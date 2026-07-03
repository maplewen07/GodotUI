using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace ManifestUiGen;

internal static class Program
{
    private const int CurrentSchemaVersion = 1;
    private const string GeneratorId = "ManifestUiGen";
    private static readonly UTF8Encoding Utf8NoBom = new(false);

    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        PropertyNameCaseInsensitive = true,
        ReadCommentHandling = JsonCommentHandling.Skip,
        AllowTrailingCommas = true,
        WriteIndented = true,
    };

    public static int Main(string[] args)
    {
        try
        {
            if (args.Length == 0)
            {
                PrintUsage();
                return 2;
            }

            return args[0] switch
            {
                "check" => Validate(args.Skip(1).ToArray()),
                "validate" => Validate(args.Skip(1).ToArray()),
                "generate" => Generate(args.Skip(1).ToArray()),
                "migrate" => Migrate(args.Skip(1).ToArray()),
                _ => UsageError($"Unknown command: {args[0]}"),
            };
        }
        catch (Exception ex)
        {
            Console.Error.WriteLine($"ERROR: {ex.Message}");
            return 1;
        }
    }

    private static int Validate(string[] args)
    {
        if (args.Length < 1)
        {
            return UsageError("validate requires <package.json>.");
        }

        var writeReport = args.Contains("--write-report", StringComparer.Ordinal);
        var result = ValidationResult.Create();
        var package = ManifestPackage.Load(ResolvePackagePath(args[0]), result);
        package?.Validate(result);

        if (!result.Ok)
        {
            result.Print();
            return 1;
        }

        if (writeReport && package is not null)
        {
            ReportWriter.Write(package);
        }

        Console.WriteLine($"OK {package!.Package.PackageId}");
        result.PrintWarnings();
        return 0;
    }

    private static int Generate(string[] args)
    {
        if (args.Length < 1)
        {
            return UsageError("generate requires <package.json>.");
        }

        var result = ValidationResult.Create();
        var package = ManifestPackage.Load(ResolvePackagePath(args[0]), result);
        package?.Validate(result);

        if (!result.Ok)
        {
            result.Print();
            return 1;
        }

        var outputDir = package!.GetOutputDir();
        Directory.CreateDirectory(outputDir);

        File.WriteAllText(Path.Combine(outputDir, $"{package.Package.Godot.WidgetClass}.tscn"), SceneGenerator.Generate(package), Utf8NoBom);
        File.WriteAllText(Path.Combine(outputDir, $"{package.Package.Godot.WidgetClass}.cs"), ScriptStubGenerator.Generate(package), Utf8NoBom);
        File.WriteAllText(Path.Combine(outputDir, $"{package.Package.Godot.WidgetClass}.g.cs"), CodeGenerator.Generate(package), Utf8NoBom);
        AssetGenerator.Generate(package);

        Console.WriteLine($"Generated {package.Package.PackageId} -> {Path.GetRelativePath(Directory.GetCurrentDirectory(), outputDir)}");
        result.PrintWarnings();
        return 0;
    }

    private static int Migrate(string[] args)
    {
        if (args.Length != 2 || args[0] != "--check")
        {
            return UsageError("migrate usage: ManifestUiGen migrate --check <package.json>");
        }

        var result = ValidationResult.Create();
        var package = ManifestPackage.Load(ResolvePackagePath(args[1]), result, loadReferences: false);
        if (package is null)
        {
            result.Print();
            return 1;
        }

        if (package.Package.SchemaVersion == CurrentSchemaVersion)
        {
            Console.WriteLine($"OK schemaVersion {CurrentSchemaVersion} no migration needed");
            return 0;
        }

        if (package.Package.SchemaVersion > CurrentSchemaVersion)
        {
            Console.Error.WriteLine($"ERROR: package.json.schemaVersion: {package.Package.SchemaVersion} is newer than tool support {CurrentSchemaVersion}");
            return 1;
        }

        Console.Error.WriteLine($"ERROR: package.json.schemaVersion: migration from {package.Package.SchemaVersion} to {CurrentSchemaVersion} is not defined");
        return 1;
    }

    private static int UsageError(string message)
    {
        Console.Error.WriteLine($"ERROR: {message}");
        PrintUsage();
        return 2;
    }

    private static void PrintUsage()
    {
        Console.Error.WriteLine("Usage:");
        Console.Error.WriteLine("  ManifestUiGen validate <package.json> [--write-report]");
        Console.Error.WriteLine("  ManifestUiGen check <package.json>");
        Console.Error.WriteLine("  ManifestUiGen generate <package.json>");
        Console.Error.WriteLine("  ManifestUiGen migrate --check <package.json>");
    }

    private static string ResolvePackagePath(string path)
    {
        var resolved = Path.GetFullPath(path);
        return Directory.Exists(resolved) ? Path.Combine(resolved, "package.json") : resolved;
    }

    private static T? ReadJson<T>(string path, ValidationResult result, string logicalName)
    {
        try
        {
            return JsonSerializer.Deserialize<T>(File.ReadAllText(path), JsonOptions);
        }
        catch (Exception ex) when (ex is IOException or JsonException or UnauthorizedAccessException)
        {
            result.Error(Path.GetFileName(path), logicalName, $"JSON read failed: {ex.Message}");
            return default;
        }
    }

    private sealed class ManifestPackage
    {
        private readonly Dictionary<string, LayoutNode> _nodeByPath = new(StringComparer.Ordinal);
        private readonly Dictionary<string, LayoutNode> _nodeById = new(StringComparer.Ordinal);
        private static readonly HashSet<string> AllowedFieldTypes = new(StringComparer.Ordinal) { "text", "bool", "number", "assetRef", "object" };
        private static readonly HashSet<string> SupportedProperties = new(StringComparer.Ordinal) { "text", "visible", "enabled", "value", "texture", "themeClass" };
        private static readonly HashSet<string> KnownConverters = new(StringComparer.Ordinal) { "string", "bool", "number", "not", "isNotEmpty", "texture" };

        public required string PackagePath { get; init; }
        public required string DirectoryPath { get; init; }
        public required PackageJson Package { get; init; }
        public required LayoutJson Layout { get; init; }
        public required BindingsJson Bindings { get; init; }
        public required AssetsJson Assets { get; init; }
        public required CodegenJson Codegen { get; init; }
        public required ValidationJson Validation { get; init; }
        public required Dictionary<string, string> SourceFiles { get; init; }
        public IReadOnlyDictionary<string, LayoutNode> NodeByPath => _nodeByPath;

        public static ManifestPackage? Load(string packagePath, ValidationResult result, bool loadReferences = true)
        {
            if (!File.Exists(packagePath))
            {
                result.Error("package.json", "package", $"file does not exist: {packagePath}");
                return null;
            }

            var packageDir = Path.GetDirectoryName(packagePath) ?? Directory.GetCurrentDirectory();
            var package = ReadJson<PackageJson>(packagePath, result, "package.json");
            if (package is null)
            {
                return null;
            }

            var sourceFiles = new Dictionary<string, string>(StringComparer.Ordinal) { ["package"] = packagePath };
            if (!loadReferences)
            {
                return new ManifestPackage
                {
                    PackagePath = packagePath,
                    DirectoryPath = packageDir,
                    Package = package,
                    Layout = new LayoutJson(),
                    Bindings = new BindingsJson(),
                    Assets = new AssetsJson(),
                    Codegen = new CodegenJson(),
                    Validation = new ValidationJson(),
                    SourceFiles = sourceFiles,
                };
            }

            var assetsPath = ResolveRequiredPackageFile(packageDir, package.Assets, "assets", result);
            var layoutPath = ResolveRequiredPackageFile(packageDir, package.Layout, "layout", result);
            var bindingsPath = ResolveRequiredPackageFile(packageDir, package.Bindings, "bindings", result);
            var codegenPath = ResolveRequiredPackageFile(packageDir, package.Codegen, "codegen", result);
            var validationPath = ResolveRequiredPackageFile(packageDir, package.Validation, "validation", result);

            var assets = assetsPath is null ? null : ReadJson<AssetsJson>(assetsPath, result, "assets.json");
            var layout = layoutPath is null ? null : ReadJson<LayoutJson>(layoutPath, result, "layout.json");
            var bindings = bindingsPath is null ? null : ReadJson<BindingsJson>(bindingsPath, result, "bindings.json");
            var codegen = codegenPath is null ? null : ReadJson<CodegenJson>(codegenPath, result, "codegen.json");
            var validation = validationPath is null ? null : ReadJson<ValidationJson>(validationPath, result, "validation.json");

            if (assetsPath is not null) sourceFiles["assets"] = assetsPath;
            if (layoutPath is not null) sourceFiles["layout"] = layoutPath;
            if (bindingsPath is not null) sourceFiles["bindings"] = bindingsPath;
            if (codegenPath is not null) sourceFiles["codegen"] = codegenPath;
            if (validationPath is not null) sourceFiles["validation"] = validationPath;

            return assets is null || layout is null || bindings is null || codegen is null || validation is null
                ? null
                : new ManifestPackage
                {
                    PackagePath = packagePath,
                    DirectoryPath = packageDir,
                    Package = package,
                    Layout = layout,
                    Bindings = bindings,
                    Assets = assets,
                    Codegen = codegen,
                    Validation = validation,
                    SourceFiles = sourceFiles,
                };
        }

        public string SystemName => string.IsNullOrWhiteSpace(Package.Godot.SystemName)
            ? Names.SystemNameFromPackageId(Package.PackageId)
            : Package.Godot.SystemName;

        public string GetOutputDir()
        {
            var configured = string.IsNullOrWhiteSpace(Package.Godot.OutputDir)
                ? Path.Combine("generated", "ui", SystemName)
                : Package.Godot.OutputDir;
            return Path.GetFullPath(configured, Directory.GetCurrentDirectory());
        }

        public string GetNamespace()
        {
            return string.IsNullOrWhiteSpace(Package.Godot.Namespace)
                ? $"GodotUi.Generated.{Names.Pascal(SystemName)}"
                : Package.Godot.Namespace;
        }

        public void Validate(ValidationResult result)
        {
            ValidatePackage(result);
            ValidateSchemaSnapshots(result);
            ValidateLayout(result);
            ValidateBindings(result);
            ValidateAssets(result);
            ValidateCodegen(result);
            ValidateValidationManifest(result);
        }

        public List<PropertyBinding> GetPropertyBindings()
        {
            var result = new List<PropertyBinding>();
            foreach (var (key, value) in Bindings.Bindings)
            {
                if (TryReadPropertyBinding(key, value, null, out var binding) && binding is not null)
                {
                    result.Add(binding);
                }
            }
            return result;
        }

        public List<RepeaterBinding> GetRepeaters()
        {
            return Bindings.Repeaters.Select(repeater => new RepeaterBinding(
                repeater.Target,
                repeater.Template,
                StripSourcePrefix(repeater.Source, "viewmodel:"),
                repeater.Bindings.Select(kvp => ReadItemBinding(kvp.Key, kvp.Value)).Where(binding => binding is not null).Cast<ItemBinding>().ToList())).ToList();
        }

        public List<InputBinding> GetInputs()
        {
            return Bindings.Inputs.Select(input => new InputBinding(input.Target, input.Property, StripSourcePrefix(input.Source, "viewmodel:"))).ToList();
        }

        public Dictionary<string, string> GetAssetResourcePaths()
        {
            return GetAssetRefs().ToDictionary(asset => asset.Id, asset => asset.Path, StringComparer.Ordinal);
        }

        public string GetAssetResourcePath(AssetEntry asset)
        {
            return ToResourcePath(Path.GetFullPath(Path.Combine(DirectoryPath, asset.RelativePath)));
        }

        public List<GeneratedAssetRef> GetAssetRefs()
        {
            return Assets.Assets
                .Select(asset => new GeneratedAssetRef(asset.Id, asset.Kind, IsThemeKind(asset.Kind) ? GetThemeOutputResourcePath(asset) : GetAssetResourcePath(asset)))
                .ToList();
        }

        public AssetEntry? GetThemeAsset()
        {
            return Assets.Assets.FirstOrDefault(asset => IsThemeKind(asset.Kind));
        }

        public string GetThemeOutputPath(AssetEntry theme)
        {
            var configured = string.IsNullOrWhiteSpace(theme.Theme.OutputPath)
                ? Path.Combine(GetOutputDir(), "assets", $"{Names.Pascal(SystemName)}Theme.tres")
                : theme.Theme.OutputPath;
            return Path.GetFullPath(configured, Directory.GetCurrentDirectory());
        }

        public string GetThemeOutputResourcePath(AssetEntry theme)
        {
            return ToResourcePath(GetThemeOutputPath(theme));
        }

        private static string NormalizeProperty(string property)
        {
            return string.Equals(property, "visibility", StringComparison.Ordinal) ? "visible" : property;
        }

        private static string StripSourcePrefix(string source, string prefix)
        {
            return source.StartsWith(prefix, StringComparison.Ordinal) ? source[prefix.Length..] : source;
        }

        private static bool IsPropertyCompatible(string property, string nodeType)
        {
            return property switch
            {
                "text" => nodeType is "Label" or "Button" or "LineEdit" or "RichTextLabel",
                "visible" => true,
                "enabled" => nodeType is "Button" or "TextureButton" or "CheckBox" or "CheckButton" or "OptionButton" or "MenuButton" or "LineEdit" or "TextEdit",
                "value" => nodeType is "ProgressBar" or "HSlider" or "VSlider" or "SpinBox" or "TextureProgressBar",
                "texture" => nodeType is "TextureRect" or "TextureButton" or "Button",
                "themeClass" => true,
                _ => false,
            };
        }

        private static bool IsInputCompatible(string property, string nodeType)
        {
            return property switch
            {
                "text" => nodeType is "LineEdit" or "TextEdit",
                "buttonPressed" => nodeType is "CheckBox" or "CheckButton",
                "value" => nodeType is "ProgressBar" or "HSlider" or "VSlider" or "SpinBox" or "TextureProgressBar",
                "selected" => nodeType is "OptionButton",
                _ => false,
            };
        }

        private static bool IsEventCompatible(string signal, string nodeType)
        {
            return signal switch
            {
                "pressed" => nodeType is "Button" or "TextureButton" or "CheckBox" or "CheckButton",
                "text_changed" => nodeType is "LineEdit" or "TextEdit",
                "toggled" => nodeType is "CheckBox" or "CheckButton",
                "value_changed" => nodeType is "ProgressBar" or "HSlider" or "VSlider" or "SpinBox" or "TextureProgressBar",
                "item_selected" => nodeType is "OptionButton",
                "tab_changed" => nodeType is "TabContainer",
                _ => false,
            };
        }

        private static bool IsFieldTypeCompatible(string property, string fieldType)
        {
            return property switch
            {
                "text" or "themeClass" => fieldType is "text" or "number" or "bool" or "object",
                "visible" or "enabled" => fieldType is "bool" or "text" or "number",
                "value" => fieldType is "number" or "text",
                "texture" => fieldType is "assetRef" or "text" or "object",
                _ => false,
            };
        }

        private static bool IsTextureKind(string kind)
        {
            return string.Equals(kind, "texture", StringComparison.OrdinalIgnoreCase);
        }

        private static bool IsFontKind(string kind)
        {
            return string.Equals(kind, "font", StringComparison.OrdinalIgnoreCase);
        }

        private static bool IsThemeKind(string kind)
        {
            return string.Equals(kind, "theme", StringComparison.OrdinalIgnoreCase);
        }

        private static bool IsKnownAssetKind(string kind)
        {
            return IsTextureKind(kind) || IsFontKind(kind) || IsThemeKind(kind);
        }

        private static bool IsExtensionCompatible(string kind, string path)
        {
            var extension = Path.GetExtension(path).ToLowerInvariant();
            if (IsTextureKind(kind))
            {
                return extension is ".png" or ".jpg" or ".jpeg" or ".webp" or ".svg" or ".tres";
            }
            if (IsFontKind(kind))
            {
                return extension is ".ttf" or ".otf" or ".tres";
            }
            if (IsThemeKind(kind))
            {
                return extension is ".json" or ".tres";
            }
            return false;
        }

        public List<EventBinding> GetEvents()
        {
            var events = new List<EventBinding>();
            foreach (var control in Bindings.Controls)
            {
                foreach (var evt in control.Events)
                {
                    events.Add(new EventBinding
                    {
                        EventId = string.IsNullOrWhiteSpace(evt.Handler) ? evt.Event : evt.Handler,
                        Target = control.Target,
                        Signal = evt.Event,
                        Channel = evt.Channel,
                    });
                }
            }

            return events;
        }

        private void ValidatePackage(ValidationResult result)
        {
            if (Package.SchemaVersion != CurrentSchemaVersion)
            {
                result.Error("package.json", "schemaVersion", $"expected {CurrentSchemaVersion}, got {Package.SchemaVersion}");
            }

            Required(Package.PackageId, "package.json", "packageId", result);
            Required(Package.DisplayName, "package.json", "displayName", result);
            Required(Package.Assets, "package.json", "assets", result);
            Required(Package.Layout, "package.json", "layout", result);
            Required(Package.Bindings, "package.json", "bindings", result);
            Required(Package.Codegen, "package.json", "codegen", result);
            Required(Package.Validation, "package.json", "validation", result);

            if (Package.DesignResolution.Length != 2 || Package.DesignResolution.Any(x => x <= 0))
            {
                result.Error("package.json", "designResolution", "must be [width, height] with positive integers");
            }

            Required(Package.Godot.WidgetClass, "package.json", "godot.widgetClass", result);
            Required(Package.Godot.ControllerClass, "package.json", "godot.controllerClass", result);
            Required(Package.Godot.ScenePath, "package.json", "godot.scenePath", result);
            ValidateProjectRelativePath(Package.Godot.OutputDir, "package.json", "godot.outputDir", result);
            ValidateGodotScenePath(result);
            if (!string.IsNullOrWhiteSpace(Package.Godot.Namespace) && !IsDotNetNamespace(Package.Godot.Namespace))
            {
                result.Error("package.json", "godot.namespace", "must be a valid C# namespace");
            }
        }

        private void ValidateSchemaSnapshots(ValidationResult result)
        {
            var sharedDir = Path.Combine(Directory.GetCurrentDirectory(), "schemas", "manifest-ui");
            var localDir = Path.Combine(DirectoryPath, "schemas");
            foreach (var schemaFile in SchemaFiles.All)
            {
                var sharedPath = Path.Combine(sharedDir, schemaFile);
                var localPath = Path.Combine(localDir, schemaFile);
                if (!File.Exists(sharedPath))
                {
                    result.Error("schemas/manifest-ui", schemaFile, "shared schema is missing");
                    continue;
                }

                if (!File.Exists(localPath))
                {
                    result.Warning($"schemas/{schemaFile}: local schema snapshot is missing");
                    continue;
                }

                if (NormalizeText(File.ReadAllText(sharedPath)) != NormalizeText(File.ReadAllText(localPath)))
                {
                    result.Error("schemas", schemaFile, "local schema snapshot differs from shared schema");
                }
            }
        }

        private void ValidateLayout(ValidationResult result)
        {
            if (Layout.Root is null)
            {
                result.Error("layout.json", "root", "is required");
                return;
            }

            _nodeByPath.Clear();
            _nodeById.Clear();
            CollectNodes(Layout.Root, "", "root", result);
        }

        private void CollectNodes(LayoutNode node, string parentPath, string logicalPath, ValidationResult result)
        {
            Required(node.Id, "layout.json", $"{logicalPath}.id", result);
            Required(node.Type, "layout.json", $"{logicalPath}.type", result);
            Required(node.Name, "layout.json", $"{logicalPath}.name", result);
            if (string.Equals(node.Type, "SceneInstance", StringComparison.Ordinal))
            {
                Required(node.ScenePath, "layout.json", $"{logicalPath}.scenePath", result);
                ValidateResourceScenePath(node.ScenePath, "layout.json", $"{logicalPath}.scenePath", result);
            }

            var path = string.IsNullOrWhiteSpace(parentPath) ? node.Name : $"{parentPath}/{node.Name}";
            var relativePath = path.StartsWith(Layout.Root.Name + "/", StringComparison.Ordinal)
                ? path[(Layout.Root.Name.Length + 1)..]
                : path;

            if (!string.Equals(relativePath, Layout.Root.Name, StringComparison.Ordinal) && !_nodeByPath.TryAdd(relativePath, node))
            {
                result.Error("layout.json", $"{logicalPath}.name", $"duplicate node path '{relativePath}'");
            }

            if (!string.IsNullOrWhiteSpace(node.Id) && !_nodeById.TryAdd(node.Id, node))
            {
                result.Error("layout.json", $"{logicalPath}.id", $"duplicate node id '{node.Id}'");
            }

            for (var i = 0; i < node.Children.Count; i++)
            {
                CollectNodes(node.Children[i], path, $"{logicalPath}.children[{i}]", result);
            }
        }

        private static void ValidateResourceScenePath(string scenePath, string file, string logicalPath, ValidationResult result)
        {
            if (string.IsNullOrWhiteSpace(scenePath))
            {
                return;
            }

            const string prefix = "res://";
            if (!scenePath.StartsWith(prefix, StringComparison.Ordinal))
            {
                result.Error(file, logicalPath, "must start with res://");
                return;
            }

            var relativePath = scenePath[prefix.Length..].Replace('/', Path.DirectorySeparatorChar);
            if (Path.IsPathRooted(relativePath))
            {
                result.Error(file, logicalPath, "must be project-relative");
                return;
            }

            var root = Directory.GetCurrentDirectory();
            var resolved = Path.GetFullPath(Path.Combine(root, relativePath));
            var relative = Path.GetRelativePath(root, resolved);
            if (relative == ".." || relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
            {
                result.Error(file, logicalPath, "must stay inside the project directory");
                return;
            }

            if (!string.Equals(Path.GetExtension(resolved), ".tscn", StringComparison.OrdinalIgnoreCase))
            {
                result.Error(file, logicalPath, "must point to a .tscn scene");
            }

            if (!File.Exists(resolved))
            {
                result.Error(file, logicalPath, $"file does not exist: {scenePath}");
            }
        }

        private void ValidateBindings(ValidationResult result)
        {
            if (Bindings.Extra.Keys.Any(key => string.Equals(key, "fields", StringComparison.OrdinalIgnoreCase)))
            {
                result.Error("bindings.json", "fields", "legacy top-level fields are not supported in schemaVersion 1; use bindings");
            }

            var mvvmTypes = new Dictionary<string, string>(StringComparer.Ordinal);
            var mvvmCollections = new Dictionary<string, string>(StringComparer.Ordinal);
            for (var i = 0; i < Bindings.Mvvm.Fields.Count; i++)
            {
                var field = Bindings.Mvvm.Fields[i];
                Required(field.Id, "bindings.json", $"mvvm.fields[{i}].id", result);
                Required(field.Path, "bindings.json", $"mvvm.fields[{i}].path", result);
                Required(field.Value, "bindings.json", $"mvvm.fields[{i}].value", result);
                if (!string.IsNullOrWhiteSpace(field.Value) && !AllowedFieldTypes.Contains(field.Value))
                {
                    result.Error("bindings.json", $"mvvm.fields[{i}].value", "must be one of text, bool, number, assetRef, object");
                }
                if (!string.IsNullOrWhiteSpace(field.Id) && !mvvmTypes.TryAdd(field.Id, field.Value))
                {
                    result.Error("bindings.json", $"mvvm.fields[{i}].id", $"duplicate field id '{field.Id}'");
                }
                if (!string.IsNullOrWhiteSpace(field.Id))
                {
                    mvvmCollections[field.Id] = field.Collection;
                }
            }

            ValidateCanonicalPropertyBindings(result, mvvmTypes);
            ValidateRepeaters(result, mvvmTypes, mvvmCollections);
            ValidateInputs(result, mvvmTypes);
            ValidateEvents(result);
        }

        private void ValidateCanonicalPropertyBindings(ValidationResult result, Dictionary<string, string> mvvmTypes)
        {
            foreach (var (key, value) in Bindings.Bindings)
            {
                if (!TryReadPropertyBinding(key, value, result, out var binding) || binding is null)
                {
                    continue;
                }

                if (!NodeByPath.TryGetValue(binding.Target, out var targetNode))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"unknown layout target '{binding.Target}'");
                    continue;
                }
                if (!SupportedProperties.Contains(NormalizeProperty(binding.Property)))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"unsupported property '{binding.Property}'");
                }
                if (!IsPropertyCompatible(NormalizeProperty(binding.Property), targetNode.Type))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"property '{binding.Property}' is not supported on {targetNode.Type}");
                }
                if (!mvvmTypes.TryGetValue(binding.FieldId, out var fieldType))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"unknown mvvm field '{binding.FieldId}'");
                }
                else if (!IsFieldTypeCompatible(NormalizeProperty(binding.Property), fieldType))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"field type '{fieldType}' is not compatible with property '{binding.Property}'");
                }
                if (!string.IsNullOrWhiteSpace(binding.Converter) && !KnownConverters.Contains(binding.Converter))
                {
                    result.Error("bindings.json", $"bindings.{key}.converter", $"unknown converter '{binding.Converter}'");
                }
                if (NormalizeProperty(binding.Property) == "texture"
                    && binding.Fallback is { ValueKind: JsonValueKind.String } fallback
                    && !IsTextureReferenceValid(fallback.GetString() ?? ""))
                {
                    result.Error("bindings.json", $"bindings.{key}.fallback", $"unknown texture asset '{fallback.GetString()}'");
                }
            }
        }

        private void ValidateRepeaters(ValidationResult result, Dictionary<string, string> mvvmTypes, Dictionary<string, string> mvvmCollections)
        {
            var ids = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < Bindings.Repeaters.Count; i++)
            {
                var repeater = Bindings.Repeaters[i];
                var label = $"repeaters[{i}]";
                Required(repeater.Id, "bindings.json", $"{label}.id", result);
                Required(repeater.Target, "bindings.json", $"{label}.target", result);
                Required(repeater.Template, "bindings.json", $"{label}.template", result);
                Required(repeater.Source, "bindings.json", $"{label}.source", result);
                if (!string.IsNullOrWhiteSpace(repeater.Id) && !ids.Add(repeater.Id))
                {
                    result.Error("bindings.json", $"{label}.id", $"duplicate repeater id '{repeater.Id}'");
                }
                if (!NodeByPath.ContainsKey(repeater.Target))
                {
                    result.Error("bindings.json", $"{label}.target", $"unknown layout target '{repeater.Target}'");
                }
                if (!NodeByPath.ContainsKey(repeater.Template))
                {
                    result.Error("bindings.json", $"{label}.template", $"unknown template path '{repeater.Template}'");
                }
                else if (!string.IsNullOrWhiteSpace(repeater.Target) && !repeater.Template.StartsWith(repeater.Target + "/", StringComparison.Ordinal))
                {
                    result.Error("bindings.json", $"{label}.template", "must be a child of target");
                }
                var fieldId = StripSourcePrefix(repeater.Source, "viewmodel:");
                if (!repeater.Source.StartsWith("viewmodel:", StringComparison.Ordinal))
                {
                    result.Error("bindings.json", $"{label}.source", "must use viewmodel:<fieldId>");
                }
                else if (!mvvmTypes.ContainsKey(fieldId))
                {
                    result.Error("bindings.json", $"{label}.source", $"unknown mvvm field '{fieldId}'");
                }
                else if (!mvvmCollections.TryGetValue(fieldId, out var collection) || string.IsNullOrWhiteSpace(collection) || collection == "none")
                {
                    result.Error("bindings.json", $"{label}.source", $"field '{fieldId}' must declare collection");
                }

                foreach (var (key, value) in repeater.Bindings)
                {
                    if (!TryReadItemBinding(key, value, result, out var binding) || binding is null)
                    {
                        continue;
                    }

                    var absoluteTarget = string.IsNullOrWhiteSpace(binding.Target) || binding.Target == "."
                        ? repeater.Template
                        : $"{repeater.Template}/{binding.Target}";
                    if (!NodeByPath.TryGetValue(absoluteTarget, out var targetNode))
                    {
                        result.Error("bindings.json", $"{label}.bindings.{key}", $"unknown template target '{binding.Target}'");
                        continue;
                    }
                    if (!SupportedProperties.Contains(NormalizeProperty(binding.Property)))
                    {
                        result.Error("bindings.json", $"{label}.bindings.{key}", $"unsupported property '{binding.Property}'");
                    }
                    if (!IsPropertyCompatible(NormalizeProperty(binding.Property), targetNode.Type))
                    {
                        result.Error("bindings.json", $"{label}.bindings.{key}", $"property '{binding.Property}' is not supported on {targetNode.Type}");
                    }
                    if (!string.IsNullOrWhiteSpace(binding.Converter) && !KnownConverters.Contains(binding.Converter))
                    {
                        result.Error("bindings.json", $"{label}.bindings.{key}.converter", $"unknown converter '{binding.Converter}'");
                    }
                }
            }
        }

        private void ValidateInputs(ValidationResult result, Dictionary<string, string> mvvmTypes)
        {
            var ids = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < Bindings.Inputs.Count; i++)
            {
                var input = Bindings.Inputs[i];
                var label = $"inputs[{i}]";
                Required(input.Id, "bindings.json", $"{label}.id", result);
                Required(input.Target, "bindings.json", $"{label}.target", result);
                Required(input.Property, "bindings.json", $"{label}.property", result);
                Required(input.Source, "bindings.json", $"{label}.source", result);
                if (!string.IsNullOrWhiteSpace(input.Id) && !ids.Add(input.Id))
                {
                    result.Error("bindings.json", $"{label}.id", $"duplicate input id '{input.Id}'");
                }
                if (!NodeByPath.TryGetValue(input.Target, out var targetNode))
                {
                    result.Error("bindings.json", $"{label}.target", $"unknown layout target '{input.Target}'");
                    continue;
                }
                if (!IsInputCompatible(input.Property, targetNode.Type))
                {
                    result.Error("bindings.json", $"{label}.property", $"property '{input.Property}' is not supported on {targetNode.Type}");
                }
                var fieldId = StripSourcePrefix(input.Source, "viewmodel:");
                if (!input.Source.StartsWith("viewmodel:", StringComparison.Ordinal))
                {
                    result.Error("bindings.json", $"{label}.source", "must use viewmodel:<fieldId>");
                }
                else if (!mvvmTypes.ContainsKey(fieldId))
                {
                    result.Error("bindings.json", $"{label}.source", $"unknown mvvm field '{fieldId}'");
                }
            }
        }

        private bool TryReadPropertyBinding(string key, JsonElement value, ValidationResult? result, out PropertyBinding? binding)
        {
            binding = null;
            var dot = key.LastIndexOf('.');
            if (dot <= 0 || dot == key.Length - 1)
            {
                result?.Error("bindings.json", $"bindings.{key}", "key must be <node-path>.<property>");
                return false;
            }

            var source = "";
            var converter = "";
            var format = "";
            JsonElement? fallback = null;
            switch (value.ValueKind)
            {
                case JsonValueKind.String:
                    source = value.GetString() ?? "";
                    break;
                case JsonValueKind.Object:
                    if (!value.TryGetProperty("source", out var sourceElement) || sourceElement.ValueKind != JsonValueKind.String)
                    {
                        result?.Error("bindings.json", $"bindings.{key}.source", "is required");
                        return false;
                    }
                    source = sourceElement.GetString() ?? "";
                    if (value.TryGetProperty("converter", out var converterElement) && converterElement.ValueKind == JsonValueKind.String)
                    {
                        converter = converterElement.GetString() ?? "";
                    }
                    if (value.TryGetProperty("format", out var formatElement) && formatElement.ValueKind == JsonValueKind.String)
                    {
                        format = formatElement.GetString() ?? "";
                    }
                    if (value.TryGetProperty("fallback", out var fallbackElement))
                    {
                        fallback = fallbackElement;
                    }
                    break;
                default:
                    result?.Error("bindings.json", $"bindings.{key}", "value must be a viewmodel string or binding object");
                    return false;
            }

            const string prefix = "viewmodel:";
            if (!source.StartsWith(prefix, StringComparison.Ordinal))
            {
                result?.Error("bindings.json", $"bindings.{key}", "source must use viewmodel:<fieldId>");
                return false;
            }

            binding = new PropertyBinding(key[..dot], key[(dot + 1)..], source[prefix.Length..], converter, format, fallback);
            return true;
        }

        private static ItemBinding? ReadItemBinding(string key, JsonElement value)
        {
            return TryReadItemBinding(key, value, null, out var binding) ? binding : null;
        }

        private static bool TryReadItemBinding(string key, JsonElement value, ValidationResult? result, out ItemBinding? binding)
        {
            binding = null;
            var dot = key.LastIndexOf('.');
            if (dot < 0 || dot == key.Length - 1)
            {
                result?.Error("bindings.json", $"repeaters.bindings.{key}", "key must be <template-node-path>.<property>");
                return false;
            }

            var source = "";
            var converter = "";
            var format = "";
            JsonElement? fallback = null;
            switch (value.ValueKind)
            {
                case JsonValueKind.String:
                    source = value.GetString() ?? "";
                    break;
                case JsonValueKind.Object:
                    if (!value.TryGetProperty("source", out var sourceElement) || sourceElement.ValueKind != JsonValueKind.String)
                    {
                        result?.Error("bindings.json", $"repeaters.bindings.{key}.source", "is required");
                        return false;
                    }
                    source = sourceElement.GetString() ?? "";
                    if (value.TryGetProperty("converter", out var converterElement) && converterElement.ValueKind == JsonValueKind.String)
                    {
                        converter = converterElement.GetString() ?? "";
                    }
                    if (value.TryGetProperty("format", out var formatElement) && formatElement.ValueKind == JsonValueKind.String)
                    {
                        format = formatElement.GetString() ?? "";
                    }
                    if (value.TryGetProperty("fallback", out var fallbackElement))
                    {
                        fallback = fallbackElement;
                    }
                    break;
                default:
                    result?.Error("bindings.json", $"repeaters.bindings.{key}", "value must be an item string or binding object");
                    return false;
            }

            const string prefix = "item:";
            if (!source.StartsWith(prefix, StringComparison.Ordinal))
            {
                result?.Error("bindings.json", $"repeaters.bindings.{key}", "source must use item:<fieldId>");
                return false;
            }

            binding = new ItemBinding(key[..dot], key[(dot + 1)..], source[prefix.Length..], converter, format, fallback);
            return true;
        }

        private bool IsTextureReferenceValid(string value)
        {
            return string.IsNullOrEmpty(value)
                || value.StartsWith("res://", StringComparison.Ordinal)
                || Assets.Assets.Any(asset => string.Equals(asset.Id, value, StringComparison.Ordinal) && IsTextureKind(asset.Kind));
        }

        private void ValidateEvents(ValidationResult result)
        {
            if (Bindings.Events.ValueKind == JsonValueKind.Array)
            {
                result.Error("bindings.json", "events", "legacy array-form events are not supported in schemaVersion 1; use controls and events.channels");
            }

            var channels = GetChannels();
            var channelIds = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < channels.Count; i++)
            {
                Required(channels[i].Id, "bindings.json", $"events.channels[{i}].id", result);
                Required(channels[i].Scope, "bindings.json", $"events.channels[{i}].scope", result);
                Required(channels[i].Dispatch, "bindings.json", $"events.channels[{i}].dispatch", result);
                if (!string.IsNullOrWhiteSpace(channels[i].Id) && !channelIds.Add(channels[i].Id))
                {
                    result.Error("bindings.json", $"events.channels[{i}].id", $"duplicate channel '{channels[i].Id}'");
                }
            }

            var controlIds = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < Bindings.Controls.Count; i++)
            {
                var control = Bindings.Controls[i];
                Required(control.Id, "bindings.json", $"controls[{i}].id", result);
                Required(control.Target, "bindings.json", $"controls[{i}].target", result);
                if (!string.IsNullOrWhiteSpace(control.Id) && !controlIds.Add(control.Id))
                {
                    result.Error("bindings.json", $"controls[{i}].id", $"duplicate control id '{control.Id}'");
                }
                LayoutNode? targetNode = null;
                if (!string.IsNullOrWhiteSpace(control.Target) && !NodeByPath.ContainsKey(control.Target))
                {
                    result.Error("bindings.json", $"controls[{i}].target", $"unknown layout target '{control.Target}'");
                }
                else if (!string.IsNullOrWhiteSpace(control.Target))
                {
                    targetNode = NodeByPath[control.Target];
                    if (!string.IsNullOrWhiteSpace(control.WidgetClass) && !string.Equals(control.WidgetClass, targetNode.Type, StringComparison.Ordinal))
                    {
                        result.Error("bindings.json", $"controls[{i}].widgetClass", $"must match layout node type '{targetNode.Type}'");
                    }
                }
                for (var j = 0; j < control.Events.Count; j++)
                {
                    var evt = control.Events[j];
                    Required(evt.Event, "bindings.json", $"controls[{i}].events[{j}].event", result);
                    Required(evt.Handler, "bindings.json", $"controls[{i}].events[{j}].handler", result);
                    Required(evt.Channel, "bindings.json", $"controls[{i}].events[{j}].channel", result);
                    if (targetNode is not null && !IsEventCompatible(evt.Event, targetNode.Type))
                    {
                        result.Error("bindings.json", $"controls[{i}].events[{j}].event", $"event '{evt.Event}' is not supported on {targetNode.Type}");
                    }
                    if (!string.IsNullOrWhiteSpace(evt.Channel) && !channelIds.Contains(evt.Channel))
                    {
                        result.Error("bindings.json", $"controls[{i}].events[{j}].channel", $"undeclared channel '{evt.Channel}'");
                    }
                }
            }
        }

        private List<EventChannel> GetChannels()
        {
            if (Bindings.Events.ValueKind != JsonValueKind.Object
                || !Bindings.Events.TryGetProperty("channels", out var channels)
                || channels.ValueKind != JsonValueKind.Array)
            {
                return new List<EventChannel>();
            }
            return JsonSerializer.Deserialize<List<EventChannel>>(channels.GetRawText(), JsonOptions) ?? new List<EventChannel>();
        }

        private void ValidateAssets(ValidationResult result)
        {
            var ids = new HashSet<string>(StringComparer.Ordinal);
            var byId = new Dictionary<string, AssetEntry>(StringComparer.Ordinal);
            for (var i = 0; i < Assets.Assets.Count; i++)
            {
                var asset = Assets.Assets[i];
                var label = $"assets[{i}]";
                Required(asset.Id, "assets.json", $"{label}.id", result);
                Required(asset.RelativePath, "assets.json", $"{label}.relativePath", result);
                Required(asset.Kind, "assets.json", $"{label}.kind", result);
                Required(asset.ContentHash, "assets.json", $"{label}.contentHash", result);
                if (!string.IsNullOrWhiteSpace(asset.Id) && !ids.Add(asset.Id))
                {
                    result.Error("assets.json", $"{label}.id", $"duplicate asset id '{asset.Id}'");
                }
                else if (!string.IsNullOrWhiteSpace(asset.Id))
                {
                    byId[asset.Id] = asset;
                }
                if (!IsKnownAssetKind(asset.Kind))
                {
                    result.Error("assets.json", $"{label}.kind", "must be texture, font, or theme");
                }
                if (!IsSha256(asset.ContentHash))
                {
                    result.Error("assets.json", $"{label}.contentHash", "must be sha256:<64 hex chars>");
                }
                if (asset.Size is not null && (asset.Size.Length != 2 || asset.Size.Any(value => value <= 0)))
                {
                    result.Error("assets.json", $"{label}.size", "must be [width, height] with positive integers");
                }

                var path = ResolvePackageFile(DirectoryPath, asset.RelativePath, "assets.json", $"{label}.relativePath", result);
                if (path is null)
                {
                    continue;
                }
                var relative = Path.GetRelativePath(DirectoryPath, path).Replace('\\', '/');
                if (!relative.StartsWith("assets/", StringComparison.Ordinal))
                {
                    result.Error("assets.json", $"{label}.relativePath", "must be under assets/");
                }
                if (!IsExtensionCompatible(asset.Kind, path))
                {
                    result.Error("assets.json", $"{label}.kind", $"kind '{asset.Kind}' is not compatible with extension '{Path.GetExtension(path)}'");
                }
                if (!File.Exists(path))
                {
                    result.Error("assets.json", $"{label}.relativePath", $"file does not exist: {asset.RelativePath}");
                    continue;
                }
                var actual = Sha256File(path);
                if (IsSha256(asset.ContentHash) && asset.ContentHash != actual)
                {
                    result.Error("assets.json", $"{label}.contentHash", $"hash mismatch, expected {asset.ContentHash}, actual {actual}");
                }
            }

            foreach (var (asset, index) in Assets.Assets.Select((asset, index) => (asset, index)).Where(pair => IsThemeKind(pair.asset.Kind)))
            {
                var label = $"assets[{index}].theme";
                var theme = asset.Theme;
                if (!string.IsNullOrWhiteSpace(theme.OutputPath))
                {
                    ValidateProjectRelativePath(theme.OutputPath, "assets.json", $"{label}.outputPath", result);
                    if (!string.Equals(Path.GetExtension(theme.OutputPath), ".tres", StringComparison.OrdinalIgnoreCase))
                    {
                        result.Error("assets.json", $"{label}.outputPath", "must point to a .tres file");
                    }
                }
                if (!string.IsNullOrWhiteSpace(theme.DefaultFontAssetId))
                {
                    if (!byId.TryGetValue(theme.DefaultFontAssetId, out var fontAsset) || !IsFontKind(fontAsset.Kind))
                    {
                        result.Error("assets.json", $"{label}.defaultFontAssetId", $"unknown font asset '{theme.DefaultFontAssetId}'");
                    }
                }
                if (theme.DefaultFontSize < 0)
                {
                    result.Error("assets.json", $"{label}.defaultFontSize", "must be >= 0");
                }
                for (var i = 0; i < theme.TypeVariations.Count; i++)
                {
                    Required(theme.TypeVariations[i].Id, "assets.json", $"{label}.typeVariations[{i}].id", result);
                    Required(theme.TypeVariations[i].BaseType, "assets.json", $"{label}.typeVariations[{i}].baseType", result);
                }
            }
        }

        private void ValidateCodegen(ValidationResult result)
        {
            if (Codegen.SchemaVersion != CurrentSchemaVersion)
            {
                result.Error("codegen.json", "schemaVersion", $"expected {CurrentSchemaVersion}, got {Codegen.SchemaVersion}");
            }
            if (!string.IsNullOrWhiteSpace(Codegen.Generator) && Codegen.Generator != GeneratorId)
            {
                result.Warning($"codegen.json.generator: expected {GeneratorId}, got {Codegen.Generator}");
            }
            ValidateProjectRelativePath(Package.Godot.OutputDir, "package.json", "godot.outputDir", result);
        }

        private void ValidateGodotScenePath(ValidationResult result)
        {
            var scenePath = Package.Godot.ScenePath;
            if (string.IsNullOrWhiteSpace(scenePath))
            {
                return;
            }
            const string prefix = "res://";
            if (!scenePath.StartsWith(prefix, StringComparison.Ordinal))
            {
                result.Error("package.json", "godot.scenePath", "must start with res://");
                return;
            }

            var relativePath = scenePath[prefix.Length..].Replace('/', Path.DirectorySeparatorChar);
            if (Path.IsPathRooted(relativePath))
            {
                result.Error("package.json", "godot.scenePath", "must be project-relative");
                return;
            }

            var root = Directory.GetCurrentDirectory();
            var resolved = Path.GetFullPath(Path.Combine(root, relativePath));
            var relative = Path.GetRelativePath(root, resolved);
            if (relative == ".." || relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
            {
                result.Error("package.json", "godot.scenePath", "must stay inside the project directory");
                return;
            }

            if (!string.Equals(Path.GetExtension(resolved), ".tscn", StringComparison.OrdinalIgnoreCase))
            {
                result.Error("package.json", "godot.scenePath", "must point to a .tscn scene");
            }

            if (!string.IsNullOrWhiteSpace(Package.Godot.WidgetClass))
            {
                var expected = Path.Combine(GetOutputDir(), $"{Package.Godot.WidgetClass}.tscn");
                if (!string.Equals(Path.GetFullPath(expected), resolved, StringComparison.OrdinalIgnoreCase))
                {
                    var expectedResourcePath = ToResourcePath(expected);
                    result.Error("package.json", "godot.scenePath", $"must match generated scene path {expectedResourcePath}");
                }
            }
        }

        private void ValidateValidationManifest(ValidationResult result)
        {
            if (Validation.CommandletInputWhitelist.Count == 0)
            {
                result.Warning("validation.json.commandletInputWhitelist: empty");
                return;
            }
            foreach (var entry in new[] { Package.Assets, Package.Layout, Package.Bindings, Package.Codegen, Package.Validation })
            {
                if (!Validation.CommandletInputWhitelist.Contains(entry, StringComparer.Ordinal))
                {
                    result.Error("validation.json", "commandletInputWhitelist", $"missing {entry}");
                }
            }
        }
    }

    private static class AssetGenerator
    {
        public static void Generate(ManifestPackage package)
        {
            var theme = package.GetThemeAsset();
            if (theme is null)
            {
                return;
            }

            var outputPath = package.GetThemeOutputPath(theme);
            Directory.CreateDirectory(Path.GetDirectoryName(outputPath) ?? package.GetOutputDir());
            File.WriteAllText(outputPath, GenerateTheme(package, theme), Utf8NoBom);
        }

        private static string GenerateTheme(ManifestPackage package, AssetEntry themeAsset)
        {
            var theme = themeAsset.Theme;
            var fontAsset = ResolveDefaultFont(package, themeAsset);
            var fontSize = ResolveDefaultFontSize(themeAsset, fontAsset);
            var sb = new StringBuilder();

            if (fontAsset is not null)
            {
                sb.AppendLine("[gd_resource type=\"Theme\" load_steps=2 format=3]");
                sb.AppendLine();
                sb.AppendLine($"[ext_resource type=\"Font\" path=\"{package.GetAssetResourcePath(fontAsset)}\" id=\"1_default_font\"]");
                sb.AppendLine();
            }
            else
            {
                sb.AppendLine("[gd_resource type=\"Theme\" format=3]");
                sb.AppendLine();
            }

            sb.AppendLine("[resource]");
            if (fontAsset is not null)
            {
                sb.AppendLine("default_font = ExtResource(\"1_default_font\")");
            }
            if (fontSize > 0)
            {
                sb.AppendLine($"default_font_size = {fontSize}");
            }
            foreach (var variation in theme.TypeVariations)
            {
                sb.AppendLine($"{variation.Id}/base_type = &\"{Escape(variation.BaseType)}\"");
            }
            return sb.ToString();
        }

        private static AssetEntry? ResolveDefaultFont(ManifestPackage package, AssetEntry themeAsset)
        {
            if (!string.IsNullOrWhiteSpace(themeAsset.Theme.DefaultFontAssetId))
            {
                return package.Assets.Assets.FirstOrDefault(asset => string.Equals(asset.Id, themeAsset.Theme.DefaultFontAssetId, StringComparison.Ordinal));
            }
            return package.Assets.Assets.FirstOrDefault(asset => asset.DefaultFont && string.Equals(asset.Kind, "font", StringComparison.OrdinalIgnoreCase));
        }

        private static int ResolveDefaultFontSize(AssetEntry themeAsset, AssetEntry? fontAsset)
        {
            if (themeAsset.Theme.DefaultFontSize > 0)
            {
                return themeAsset.Theme.DefaultFontSize;
            }
            return fontAsset?.DefaultFontSize ?? 0;
        }
    }

    private static class SceneGenerator
    {
        public static string Generate(ManifestPackage package)
        {
            var outputDir = package.GetOutputDir();
            var scriptPath = ToResourcePath(Path.Combine(outputDir, $"{package.Package.Godot.WidgetClass}.cs"));
            var sceneResources = CollectSceneResources(package.Layout.Root);
            var sb = new StringBuilder();
            sb.AppendLine($"[gd_scene load_steps={2 + sceneResources.Count} format=3]");
            sb.AppendLine();
            sb.AppendLine($"[ext_resource type=\"Script\" path=\"{scriptPath}\" id=\"1_widget\"]");
            foreach (var (path, id) in sceneResources)
            {
                sb.AppendLine($"[ext_resource type=\"PackedScene\" path=\"{path}\" id=\"{id}\"]");
            }
            sb.AppendLine();
            EmitNode(sb, package.Layout.Root, parentPath: "", nodePath: ".", sceneResources);
            return sb.ToString();
        }

        private static Dictionary<string, string> CollectSceneResources(LayoutNode root)
        {
            var result = new Dictionary<string, string>(StringComparer.Ordinal);
            var next = 2;
            foreach (var node in Walk(root).Where(node => string.Equals(node.Type, "SceneInstance", StringComparison.Ordinal)))
            {
                if (!result.ContainsKey(node.ScenePath))
                {
                    result[node.ScenePath] = $"{next++}_scene";
                }
            }
            return result;
        }

        private static IEnumerable<LayoutNode> Walk(LayoutNode node)
        {
            yield return node;
            foreach (var child in node.Children)
            {
                foreach (var nested in Walk(child))
                {
                    yield return nested;
                }
            }
        }

        private static void EmitNode(StringBuilder sb, LayoutNode node, string parentPath, string nodePath, Dictionary<string, string> sceneResources)
        {
            if (nodePath == ".")
            {
                sb.AppendLine($"[node name=\"{node.Name}\" type=\"{node.Type}\"]");
                sb.AppendLine("script = ExtResource(\"1_widget\")");
            }
            else if (string.Equals(node.Type, "SceneInstance", StringComparison.Ordinal))
            {
                sb.AppendLine($"[node name=\"{node.Name}\" parent=\"{parentPath}\" instance=ExtResource(\"{sceneResources[node.ScenePath]}\")]");
            }
            else
            {
                sb.AppendLine($"[node name=\"{node.Name}\" type=\"{node.Type}\" parent=\"{parentPath}\"]");
            }
            foreach (var (key, value) in node.Properties)
            {
                sb.AppendLine($"{key} = {FormatValue(value)}");
            }
            foreach (var child in node.Children)
            {
                sb.AppendLine();
                var childPath = nodePath == "." ? child.Name : $"{nodePath}/{child.Name}";
                EmitNode(sb, child, nodePath, childPath, sceneResources);
            }
        }

        private static string FormatValue(JsonElement value)
        {
            return value.ValueKind switch
            {
                JsonValueKind.String => $"\"{Escape(value.GetString() ?? "")}\"",
                JsonValueKind.Number => value.GetRawText(),
                JsonValueKind.True => "true",
                JsonValueKind.False => "false",
                JsonValueKind.Array when value.GetArrayLength() == 2 => $"Vector2({value[0].GetRawText()}, {value[1].GetRawText()})",
                _ => throw new InvalidOperationException($"Unsupported tscn value: {value.GetRawText()}"),
            };
        }
    }

    private static class CodeGenerator
    {
        public static string Generate(ManifestPackage package)
        {
            var propertyBindings = package.GetPropertyBindings();
            var repeaters = package.GetRepeaters();
            var inputs = package.GetInputs();
            var events = package.GetEvents();
            var targets = CollectTargets(package, propertyBindings, repeaters, inputs, events);
            var assets = package.GetAssetRefs();
            var themePath = package.GetThemeAsset() is { } themeAsset ? package.GetThemeOutputResourcePath(themeAsset) : "";
            var sb = new StringBuilder();
            sb.AppendLine("using System.Collections.Generic;");
            sb.AppendLine("using Godot;");
            sb.AppendLine("using GodotUi.Manifest;");
            sb.AppendLine();
            sb.AppendLine($"namespace {package.GetNamespace()};");
            sb.AppendLine();
            sb.AppendLine($"public partial class {package.Package.Godot.WidgetClass}");
            sb.AppendLine("{");
            foreach (var target in targets.Values)
            {
                sb.AppendLine($"    private {target.Type} {target.FieldName} = null!;");
            }
            sb.AppendLine();
            sb.AppendLine($"    public override string PackageId => \"{Escape(package.Package.PackageId)}\";");
            sb.AppendLine();
            sb.AppendLine("    protected override ManifestControllerBase CreateController()");
            sb.AppendLine("    {");
            sb.AppendLine($"        return new global::{package.Package.Godot.ControllerClass}();");
            sb.AppendLine("    }");
            sb.AppendLine();
            sb.AppendLine("    protected override void BindNodes()");
            sb.AppendLine("    {");
            foreach (var target in targets.Values)
            {
                sb.AppendLine($"        {target.FieldName} = GetNode<{target.Type}>(\"{target.Path}\");");
            }
            foreach (var evt in events)
            {
                var target = targets[evt.Target];
                sb.AppendLine($"        {target.FieldName}.{SignalEventName(evt.Signal)} += {Names.EventMethod(evt.EventId, evt.Signal)};");
            }
            foreach (var input in inputs)
            {
                var target = targets[input.Target];
                sb.AppendLine($"        {InputConnectLine(target, input)}");
            }
            sb.AppendLine("    }");
            sb.AppendLine();
            sb.AppendLine("    protected override ManifestBindingSet GetBindingSet()");
            sb.AppendLine("    {");
            sb.AppendLine("        return new ManifestBindingSet(");
            sb.AppendLine("            new ManifestPropertyBinding[]");
            sb.AppendLine("            {");
            foreach (var binding in propertyBindings)
            {
                sb.AppendLine($"                new ManifestPropertyBinding(\"{Escape(binding.Target)}\", \"{Escape(binding.Property)}\", \"{Escape(binding.FieldId)}\", \"{Escape(binding.Converter)}\", \"{Escape(binding.Format)}\", {FormatCSharpLiteral(binding.Fallback)}),");
            }
            sb.AppendLine("            },");
            sb.AppendLine("            new ManifestAssetCatalog(");
            sb.AppendLine("                new ManifestAssetRef[]");
            sb.AppendLine("                {");
            foreach (var asset in assets)
            {
                sb.AppendLine($"                    new ManifestAssetRef(\"{Escape(asset.Id)}\", \"{Escape(asset.Kind)}\", \"{Escape(asset.Path)}\"),");
            }
            sb.AppendLine("                },");
            sb.AppendLine($"                \"{Escape(themePath)}\"),");
            sb.AppendLine("            new ManifestRepeaterBinding[]");
            sb.AppendLine("            {");
            foreach (var repeater in repeaters)
            {
                sb.AppendLine($"                new ManifestRepeaterBinding(\"{Escape(repeater.Target)}\", \"{Escape(repeater.Template)}\", \"{Escape(repeater.FieldId)}\", new ManifestItemBinding[]");
                sb.AppendLine("                {");
                foreach (var binding in repeater.ItemBindings)
                {
                    sb.AppendLine($"                    new ManifestItemBinding(\"{Escape(binding.Target)}\", \"{Escape(binding.Property)}\", \"{Escape(binding.FieldId)}\", \"{Escape(binding.Converter)}\", \"{Escape(binding.Format)}\", {FormatCSharpLiteral(binding.Fallback)}),");
                }
                sb.AppendLine("                }),");
            }
            sb.AppendLine("            },");
            sb.AppendLine("            new ManifestInputBinding[]");
            sb.AppendLine("            {");
            foreach (var input in inputs)
            {
                sb.AppendLine($"                new ManifestInputBinding(\"{Escape(input.Target)}\", \"{Escape(input.Property)}\", \"{Escape(input.FieldId)}\"),");
            }
            sb.AppendLine("            });");
            sb.AppendLine("    }");
            foreach (var evt in events)
            {
                var target = targets[evt.Target];
                sb.AppendLine();
                sb.AppendLine($"    private void {Names.EventMethod(evt.EventId, evt.Signal)}({SignalArgs(evt.Signal, target.Node.Type)})");
                sb.AppendLine("    {");
                sb.AppendLine($"        DispatchUiEvent(\"{evt.EventId}\", \"{evt.Channel}\");");
                sb.AppendLine("    }");
            }
            sb.AppendLine("}");
            return sb.ToString();
        }

        private static string FormatCSharpLiteral(JsonElement? value)
        {
            if (value is null || value.Value.ValueKind == JsonValueKind.Null || value.Value.ValueKind == JsonValueKind.Undefined)
            {
                return "null";
            }

            var element = value.Value;
            return element.ValueKind switch
            {
                JsonValueKind.String => $"\"{Escape(element.GetString() ?? "")}\"",
                JsonValueKind.Number => element.GetRawText(),
                JsonValueKind.True => "true",
                JsonValueKind.False => "false",
                _ => "null",
            };
        }

        private static string SignalEventName(string signal)
        {
            return signal switch
            {
                "pressed" => "Pressed",
                "text_changed" => "TextChanged",
                "toggled" => "Toggled",
                "value_changed" => "ValueChanged",
                "item_selected" => "ItemSelected",
                "tab_changed" => "TabChanged",
                _ => Names.Pascal(signal),
            };
        }

        private static string SignalArgs(string signal, string nodeType)
        {
            if (signal == "text_changed" && nodeType == "TextEdit")
            {
                return "";
            }

            return signal switch
            {
                "text_changed" => "string value",
                "toggled" => "bool value",
                "value_changed" => "double value",
                "item_selected" => "long value",
                "tab_changed" => "long value",
                _ => "",
            };
        }

        private static string InputConnectLine(Target target, InputBinding input)
        {
            var fieldName = target.FieldName;
            return input.Property switch
            {
                "text" when target.Node.Type == "TextEdit" => $"{fieldName}.TextChanged += () => SetInputValue(\"{Escape(input.FieldId)}\", {fieldName}.Text);",
                "text" => $"{fieldName}.TextChanged += value => SetInputValue(\"{Escape(input.FieldId)}\", value);",
                "buttonPressed" => $"{fieldName}.Toggled += value => SetInputValue(\"{Escape(input.FieldId)}\", value);",
                "value" => $"{fieldName}.ValueChanged += value => SetInputValue(\"{Escape(input.FieldId)}\", value);",
                "selected" => $"{fieldName}.ItemSelected += value => SetInputValue(\"{Escape(input.FieldId)}\", value);",
                _ => "",
            };
        }

        private static Dictionary<string, Target> CollectTargets(
            ManifestPackage package,
            List<PropertyBinding> propertyBindings,
            List<RepeaterBinding> repeaters,
            List<InputBinding> inputs,
            List<EventBinding> events)
        {
            var result = new Dictionary<string, Target>(StringComparer.Ordinal);
            foreach (var targetPath in propertyBindings.Select(x => x.Target)
                         .Concat(repeaters.SelectMany(x => new[] { x.Target, x.Template }))
                         .Concat(inputs.Select(x => x.Target))
                         .Concat(events.Select(x => x.Target))
                         .Distinct())
            {
                var node = package.NodeByPath[targetPath];
                result[targetPath] = new Target(targetPath, Names.Field(targetPath), node, FieldType(node));
            }
            return result;
        }

        private static string FieldType(LayoutNode node)
        {
            return string.Equals(node.Type, "SceneInstance", StringComparison.Ordinal) ? "Control" : node.Type;
        }
    }

    private static class ScriptStubGenerator
    {
        public static string Generate(ManifestPackage package)
        {
            return $$"""
                   using GodotUi.Manifest;

                   namespace {{package.GetNamespace()}};

                   public partial class {{package.Package.Godot.WidgetClass}} : ManifestGeneratedWidget
                   {
                   }
                   """;
        }
    }

    private static class ReportWriter
    {
        public static void Write(ManifestPackage package)
        {
            var exportDir = Path.Combine(package.DirectoryPath, "export");
            Directory.CreateDirectory(exportDir);

            var sourceFiles = package.SourceFiles.ToDictionary(
                kvp => kvp.Key,
                kvp => new SourceHash(Path.GetRelativePath(package.DirectoryPath, kvp.Value).Replace('\\', '/'), Sha256File(kvp.Value)),
                StringComparer.Ordinal);

            var channelCount = package.Bindings.Events.ValueKind == JsonValueKind.Object
                && package.Bindings.Events.TryGetProperty("channels", out var channels)
                && channels.ValueKind == JsonValueKind.Array ? channels.GetArrayLength() : 0;

            var counts = new ReportCounts
            {
                Nodes = package.NodeByPath.Count + 1,
                Fields = package.GetPropertyBindings().Count,
                Events = package.GetEvents().Count,
                Channels = channelCount,
                Assets = package.Assets.Assets.Count,
            };
            var assetReport = package.Assets.Assets.Select(asset => new AssetReportEntry(
                asset.Id,
                asset.Kind,
                asset.RelativePath.Replace('\\', '/'),
                package.GetAssetRefs().First(assetRef => assetRef.Id == asset.Id).Path,
                asset.ContentHash,
                package.GetThemeAsset() == asset ? package.GetThemeOutputResourcePath(asset) : "")).ToList();

            var importManifest = new ImportManifest
            {
                SchemaVersion = CurrentSchemaVersion,
                GeneratorId = GeneratorId,
                PackageId = package.Package.PackageId,
                DisplayName = package.Package.DisplayName,
                SourceFiles = sourceFiles,
                Counts = counts,
                Assets = assetReport,
            };

            File.WriteAllText(Path.Combine(exportDir, "godot_import_manifest.json"), JsonSerializer.Serialize(importManifest, JsonOptions) + Environment.NewLine, Utf8NoBom);

            var lines = new List<string>
            {
                "# Manifest UI Validation Report",
                "",
                $"- Package: {package.Package.PackageId}",
                $"- DisplayName: {package.Package.DisplayName}",
                $"- Nodes: {counts.Nodes}",
                $"- Fields: {counts.Fields}",
                $"- Events: {counts.Events}",
                $"- Channels: {counts.Channels}",
                $"- Assets: {counts.Assets}",
                "",
                "## Source Files",
                "",
            };
            lines.AddRange(sourceFiles.Select(kvp => $"- {kvp.Value.Path}: {kvp.Value.ContentHash}"));
            lines.Add("");
            lines.Add("## Assets");
            lines.Add("");
            lines.Add("| id | kind | source | resource | hash | theme output |");
            lines.Add("|----|------|--------|----------|------|--------------|");
            lines.AddRange(assetReport.Select(asset => $"| {asset.Id} | {asset.Kind} | {asset.SourcePath} | {asset.ResourcePath} | {asset.ContentHash} | {asset.ThemeOutput} |"));
            lines.Add("");
            File.WriteAllText(Path.Combine(exportDir, "manifest_report.md"), string.Join(Environment.NewLine, lines), Utf8NoBom);
        }
    }

    private sealed class ValidationResult
    {
        private readonly List<string> _errors = new();
        private readonly List<string> _warnings = new();
        public bool Ok => _errors.Count == 0;
        public static ValidationResult Create() => new();
        public void Error(string file, string path, string message) => _errors.Add($"{file}.{path}: {message}");
        public void Warning(string message) => _warnings.Add(message);
        public void Print()
        {
            foreach (var error in _errors) Console.Error.WriteLine($"ERROR: {error}");
            PrintWarnings();
        }
        public void PrintWarnings()
        {
            foreach (var warning in _warnings) Console.Error.WriteLine($"WARN: {warning}");
        }
    }

    private static class Names
    {
        public static string Pascal(string value)
        {
            var parts = value.Split(new[] { '_', '-', '/', '.', ' ' }, StringSplitOptions.RemoveEmptyEntries);
            return string.Concat(parts.Select(part => char.ToUpperInvariant(part[0]) + part[1..]));
        }
        public static string Camel(string value)
        {
            var pascal = Pascal(value);
            return string.IsNullOrEmpty(pascal) ? pascal : char.ToLowerInvariant(pascal[0]) + pascal[1..];
        }
        public static string Field(string path) => "_" + Camel(path.Split('/').Last());
        public static string EventMethod(string eventId, string signal) => $"On{Pascal(eventId)}{Pascal(signal)}";
        public static string SystemNameFromPackageId(string packageId) => packageId.StartsWith("ui.", StringComparison.Ordinal) ? packageId[3..] : packageId;
    }

    private static class SchemaFiles
    {
        public static readonly string[] All =
        {
            "package.schema.json",
            "layout.schema.json",
            "bindings.schema.json",
            "assets.schema.json",
            "codegen.schema.json",
            "validation.schema.json",
        };
    }

    private static string? ResolveRequiredPackageFile(string packageDir, string? relativePath, string label, ValidationResult result)
    {
        if (string.IsNullOrWhiteSpace(relativePath))
        {
            result.Error("package.json", label, "is required");
            return null;
        }
        var resolved = ResolvePackageFile(packageDir, relativePath, "package.json", label, result);
        if (resolved is not null && !File.Exists(resolved))
        {
            result.Error("package.json", label, $"file does not exist: {relativePath}");
            return null;
        }
        return resolved;
    }

    private static string? ResolvePackageFile(string packageDir, string relativePath, string file, string logicalPath, ValidationResult result)
    {
        if (Path.IsPathRooted(relativePath))
        {
            result.Error(file, logicalPath, "must be package-relative");
            return null;
        }
        var resolved = Path.GetFullPath(Path.Combine(packageDir, relativePath));
        var relative = Path.GetRelativePath(packageDir, resolved);
        if (relative == ".." || relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
        {
            result.Error(file, logicalPath, "must stay inside the package directory");
            return null;
        }
        return resolved;
    }

    private static void ValidateProjectRelativePath(string? path, string file, string logicalPath, ValidationResult result)
    {
        if (string.IsNullOrWhiteSpace(path)) return;
        if (Path.IsPathRooted(path))
        {
            result.Error(file, logicalPath, "must be project-relative");
            return;
        }
        var root = Directory.GetCurrentDirectory();
        var resolved = Path.GetFullPath(Path.Combine(root, path));
        var relative = Path.GetRelativePath(root, resolved);
        if (relative == ".." || relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
        {
            result.Error(file, logicalPath, "must stay inside the project directory");
        }
    }

    private static void Required(string? value, string file, string logicalPath, ValidationResult result)
    {
        if (string.IsNullOrWhiteSpace(value)) result.Error(file, logicalPath, "is required");
    }

    private static string ToResourcePath(string path) => "res://" + Path.GetRelativePath(Directory.GetCurrentDirectory(), path).Replace('\\', '/');
    private static string Escape(string value) => value.Replace("\\", "\\\\").Replace("\"", "\\\"");
    private static bool IsSha256(string? value) => value is not null && value.Length == 71 && value.StartsWith("sha256:", StringComparison.Ordinal) && value[7..].All(Uri.IsHexDigit);
    private static string Sha256File(string path)
    {
        using var sha = SHA256.Create();
        using var stream = File.OpenRead(path);
        return "sha256:" + Convert.ToHexString(sha.ComputeHash(stream)).ToLowerInvariant();
    }
    private static bool IsDotNetNamespace(string value) => value.Split('.').All(part => part.Length > 0 && (char.IsLetter(part[0]) || part[0] == '_') && part.All(ch => char.IsLetterOrDigit(ch) || ch == '_'));
    private static string NormalizeText(string value) => value.Replace("\r\n", "\n").Trim();

    private sealed record Target(string Path, string FieldName, LayoutNode Node, string Type);
    private sealed record PropertyBinding(string Target, string Property, string FieldId, string Converter, string Format, JsonElement? Fallback);
    private sealed record ItemBinding(string Target, string Property, string FieldId, string Converter, string Format, JsonElement? Fallback);
    private sealed record RepeaterBinding(string Target, string Template, string FieldId, List<ItemBinding> ItemBindings);
    private sealed record InputBinding(string Target, string Property, string FieldId);
    private sealed record GeneratedAssetRef(string Id, string Kind, string Path);
    private sealed record SourceHash(string Path, string ContentHash);
    private sealed record AssetReportEntry(string Id, string Kind, string SourcePath, string ResourcePath, string ContentHash, string ThemeOutput);

    private sealed class ImportManifest
    {
        public int SchemaVersion { get; set; }
        public string GeneratorId { get; set; } = "";
        public string PackageId { get; set; } = "";
        public string DisplayName { get; set; } = "";
        public Dictionary<string, SourceHash> SourceFiles { get; set; } = new(StringComparer.Ordinal);
        public ReportCounts Counts { get; set; } = new();
        public List<AssetReportEntry> Assets { get; set; } = new();
    }
    private sealed class ReportCounts
    {
        public int Nodes { get; set; }
        public int Fields { get; set; }
        public int Events { get; set; }
        public int Channels { get; set; }
        public int Assets { get; set; }
    }
    private sealed class PackageJson
    {
        public int SchemaVersion { get; set; }
        public string PackageId { get; set; } = "";
        public string DisplayName { get; set; } = "";
        public int[] DesignResolution { get; set; } = Array.Empty<int>();
        public string Assets { get; set; } = "";
        public string Layout { get; set; } = "";
        public string Bindings { get; set; } = "";
        public string Codegen { get; set; } = "";
        public string Validation { get; set; } = "";
        public GodotPackageJson Godot { get; set; } = new();
    }
    private sealed class GodotPackageJson
    {
        public string SystemName { get; set; } = "";
        public string WidgetClass { get; set; } = "";
        public string ControllerClass { get; set; } = "";
        public string Namespace { get; set; } = "";
        public string OutputDir { get; set; } = "";
        public string ScenePath { get; set; } = "";
    }
    private sealed class LayoutJson { public LayoutNode Root { get; set; } = new(); }
    private sealed class LayoutNode
    {
        public string Id { get; set; } = "";
        public string Type { get; set; } = "";
        public string Name { get; set; } = "";
        public string ScenePath { get; set; } = "";
        public Dictionary<string, JsonElement> Properties { get; set; } = new(StringComparer.Ordinal);
        public List<LayoutNode> Children { get; set; } = new();
    }
    private sealed class BindingsJson
    {
        public MvvmJson Mvvm { get; set; } = new();
        public Dictionary<string, JsonElement> Bindings { get; set; } = new(StringComparer.Ordinal);
        public List<RepeaterJson> Repeaters { get; set; } = new();
        public List<InputJson> Inputs { get; set; } = new();
        public List<ControlBinding> Controls { get; set; } = new();
        public JsonElement Events { get; set; }
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class MvvmJson
    {
        public string UpdatePolicy { get; set; } = "";
        public List<MvvmField> Fields { get; set; } = new();
    }
    private sealed class MvvmField
    {
        public string Id { get; set; } = "";
        public string Path { get; set; } = "";
        public string Value { get; set; } = "";
        public string Collection { get; set; } = "none";
        public bool ControllerOnlySideEffect { get; set; }
    }
    private sealed class ControlBinding
    {
        public string Id { get; set; } = "";
        public string Target { get; set; } = "";
        public string WidgetClass { get; set; } = "";
        public List<ControlEvent> Events { get; set; } = new();
    }
    private sealed class RepeaterJson
    {
        public string Id { get; set; } = "";
        public string Target { get; set; } = "";
        public string Template { get; set; } = "";
        public string Source { get; set; } = "";
        public Dictionary<string, JsonElement> Bindings { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class InputJson
    {
        public string Id { get; set; } = "";
        public string Target { get; set; } = "";
        public string Property { get; set; } = "";
        public string Source { get; set; } = "";
    }
    private sealed class ControlEvent
    {
        public string Event { get; set; } = "";
        public string Handler { get; set; } = "";
        public string Channel { get; set; } = "";
    }
    private sealed class EventBinding
    {
        public string EventId { get; set; } = "";
        public string Target { get; set; } = "";
        public string Signal { get; set; } = "";
        public string Channel { get; set; } = "";
    }
    private sealed class EventChannel
    {
        public string Id { get; set; } = "";
        public string Scope { get; set; } = "";
        public string Dispatch { get; set; } = "";
        public List<string> Payload { get; set; } = new();
    }
    private sealed class AssetsJson { public List<AssetEntry> Assets { get; set; } = new(); }
    private sealed class AssetEntry
    {
        public string Id { get; set; } = "";
        public string RelativePath { get; set; } = "";
        public string Kind { get; set; } = "";
        public string ContentHash { get; set; } = "";
        public int[]? Size { get; set; }
        public Dictionary<string, JsonElement> Import { get; set; } = new(StringComparer.Ordinal);
        public bool DefaultFont { get; set; }
        public int DefaultFontSize { get; set; }
        public ThemeAssetConfig Theme { get; set; } = new();
    }
    private sealed class ThemeAssetConfig
    {
        public string OutputPath { get; set; } = "";
        public string DefaultFontAssetId { get; set; } = "";
        public int DefaultFontSize { get; set; }
        public List<ThemeTypeVariation> TypeVariations { get; set; } = new();
    }
    private sealed class ThemeTypeVariation
    {
        public string Id { get; set; } = "";
        public string BaseType { get; set; } = "";
    }
    private sealed class CodegenJson
    {
        public int SchemaVersion { get; set; }
        public string Generator { get; set; } = "";
    }
    private sealed class ValidationJson
    {
        public List<string> CommandletInputWhitelist { get; set; } = new();
        public Dictionary<string, JsonElement> Checks { get; set; } = new(StringComparer.Ordinal);
    }
}

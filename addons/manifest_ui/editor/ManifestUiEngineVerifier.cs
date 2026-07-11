#if TOOLS
using Godot;
using GodotUi.Manifest.Tooling;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.Json;

namespace GodotUi.Manifest.Editor;

internal static class ManifestUiEngineVerifier
{
    public static ManifestDiagnostic[] Verify(string packagePath)
    {
        var diagnostics = new List<ManifestDiagnostic>();
        PackedScene? scene = null;
        Node? instance = null;
        try
        {
            using var packageDocument = ReadDocument(packagePath);
            var package = packageDocument.RootElement;
            var packageDirectory = Path.GetDirectoryName(Path.GetFullPath(packagePath))!;
            var packageFile = Path.GetFileName(packagePath);
            var scenePath = GetString(package, "godot", "scenePath");
            scene = ResourceLoader.Load<PackedScene>(scenePath, "PackedScene", ResourceLoader.CacheMode.Replace);
            if (scene is null)
            {
                diagnostics.Add(Error("MUI4001", packageFile, "/godot/scenePath", $"Generated scene could not be loaded as PackedScene: {scenePath}"));
                return diagnostics.ToArray();
            }

            instance = scene.Instantiate();
            if (instance is not Control root)
            {
                diagnostics.Add(Error("MUI4002", packageFile, "/godot/scenePath", "Generated scene root must inherit Control."));
                return diagnostics.ToArray();
            }

            VerifyGeneratedRoot(package, packageFile, root, diagnostics);

            var layoutReference = GetReference(package, "layout", "layout.json");
            using (var layoutDocument = ReadDocument(Path.Combine(packageDirectory, layoutReference)))
            {
                VerifyLayout(layoutDocument.RootElement, layoutReference, root, package, diagnostics);
            }

            var bindingsReference = GetReference(package, "bindings", "bindings.json");
            using (var bindingsDocument = ReadDocument(Path.Combine(packageDirectory, bindingsReference)))
            {
                VerifyBindings(bindingsDocument.RootElement, bindingsReference, root, diagnostics);
            }

            VerifyGeneratedBehavior(root, packageFile, diagnostics);

            var assetsReference = GetReference(package, "assets", "assets.json");
            using (var assetsDocument = ReadDocument(Path.Combine(packageDirectory, assetsReference)))
            {
                VerifyAssets(packageDirectory, assetsDocument.RootElement, assetsReference, diagnostics);
            }

            VerifyCatalog(packagePath, package, root, diagnostics);
        }
        catch (Exception ex)
        {
            diagnostics.Add(Error("MUI4000", Path.GetFileName(packagePath), "", $"Engine verification failed: {ex.Message}"));
        }
        finally
        {
            if (instance is not null && GodotObject.IsInstanceValid(instance))
            {
                instance.Free();
            }
            scene?.Dispose();
        }

        return diagnostics.ToArray();
    }

    private static void VerifyGeneratedBehavior(
        Control root,
        string packageFile,
        List<ManifestDiagnostic> diagnostics)
    {
        if (root is not ManifestGeneratedWidget widget)
        {
            return;
        }

        var runtimeDiagnostics = new List<ManifestRuntimeDiagnostic>();
        void Capture(ManifestRuntimeDiagnostic diagnostic) => runtimeDiagnostics.Add(diagnostic);
        ManifestRuntimeDiagnostics.Emitted += Capture;
        try
        {
            using var preview = ManifestGeneratedWidget.SuppressControllersForPreview();
            widget._Ready();
        }
        catch (Exception ex)
        {
            diagnostics.Add(Error("MUI4018", packageFile, "/godot/widgetClass", $"Generated widget preview initialization failed: {ex.Message}"));
        }
        finally
        {
            ManifestRuntimeDiagnostics.Emitted -= Capture;
        }

        foreach (var diagnostic in runtimeDiagnostics.Where(item => item.Severity == ManifestRuntimeDiagnosticSeverity.Error))
        {
            diagnostics.Add(Error(
                "MUI4018",
                packageFile,
                "/godot/widgetClass",
                $"Generated widget preview emitted {diagnostic.Code}: {diagnostic.Message}"));
        }
    }

    private static void VerifyGeneratedRoot(
        JsonElement package,
        string packageFile,
        Control root,
        List<ManifestDiagnostic> diagnostics)
    {
        var godot = package.GetProperty("godot");
        var expectedType = $"{godot.GetProperty("namespace").GetString()}.{godot.GetProperty("widgetClass").GetString()}";
        var expectedScript = ToResourcePath(Path.Combine(
            ProjectSettings.GlobalizePath("res://"),
            godot.GetProperty("outputDir").GetString() ?? "",
            $"{godot.GetProperty("widgetClass").GetString()}.cs"));

        if (root is not ManifestGeneratedWidget widget)
        {
            var attachedScript = root.GetScript().AsGodotObject() as Script;
            var attachedPath = attachedScript?.ResourcePath ?? "<none>";
            var actualType = root.GetType().FullName ?? root.GetType().Name;
            if (string.Equals(attachedPath, expectedScript, StringComparison.Ordinal))
            {
                diagnostics.Add(Error(
                    "MUI4005",
                    packageFile,
                    "/godot/scenePath",
                    $"The generated script is attached, but the current editor instantiated it as '{actualType}' instead of '{expectedType}'. The loaded C# assembly is stale or belongs to a previous hot reload.",
                    "Build the Debug C# project, restart the Godot editor, and run Verify again."));
            }
            else
            {
                diagnostics.Add(Error("MUI4005", packageFile, "/godot/scenePath", $"Generated scene root must inherit ManifestGeneratedWidget. Attached script is '{attachedPath}', expected '{expectedScript}'."));
            }
            return;
        }

        var packageId = package.GetProperty("packageId").GetString() ?? "";
        if (!string.Equals(widget.PackageId, packageId, StringComparison.Ordinal))
        {
            diagnostics.Add(Error("MUI4006", packageFile, "/packageId", $"Generated widget reports package id '{widget.PackageId}', expected '{packageId}'."));
        }

        if (!string.Equals(root.GetType().FullName, expectedType, StringComparison.Ordinal))
        {
            diagnostics.Add(Error("MUI4006", packageFile, "/godot/widgetClass", $"Scene root script type is '{root.GetType().FullName}', expected '{expectedType}'."));
        }

        VerifyScriptPath(root, expectedScript, packageFile, "/godot/widgetClass", "MUI4006", diagnostics);
    }

    private static void VerifyLayout(
        JsonElement layout,
        string file,
        Control root,
        JsonElement package,
        List<ManifestDiagnostic> diagnostics)
    {
        if (!layout.TryGetProperty("root", out var layoutRoot) || layoutRoot.ValueKind != JsonValueKind.Object)
        {
            diagnostics.Add(Error("MUI4010", file, "/root", "Layout root is missing."));
            return;
        }

        VerifyLayoutNode(layoutRoot, root, root, file, "/root", isRoot: true, diagnostics);
    }

    private static void VerifyLayoutNode(
        JsonElement definition,
        Control sceneRoot,
        Node actual,
        string file,
        string pointer,
        bool isRoot,
        List<ManifestDiagnostic> diagnostics)
    {
        var expectedName = definition.TryGetProperty("name", out var nameElement) ? nameElement.GetString() ?? "" : "";
        if (!string.Equals(actual.Name.ToString(), expectedName, StringComparison.Ordinal))
        {
            diagnostics.Add(Error("MUI4010", file, pointer + "/name", $"Instantiated node is named '{actual.Name}', expected '{expectedName}'."));
        }

        var expectedType = definition.TryGetProperty("type", out var typeElement) ? typeElement.GetString() ?? "" : "";
        if (!string.Equals(expectedType, "SceneInstance", StringComparison.Ordinal) &&
            !string.IsNullOrWhiteSpace(expectedType) &&
            !actual.IsClass(expectedType))
        {
            diagnostics.Add(Error("MUI4010", file, pointer + "/type", $"Node '{actual.GetPath()}' is '{actual.GetClass()}', expected '{expectedType}'."));
        }

        if (definition.TryGetProperty("scenePath", out var scenePathElement) && scenePathElement.ValueKind == JsonValueKind.String)
        {
            VerifySceneInstance(actual, scenePathElement.GetString() ?? "", file, pointer + "/scenePath", diagnostics);
        }

        if (!isRoot && definition.TryGetProperty("scriptPath", out var scriptPathElement) && scriptPathElement.ValueKind == JsonValueKind.String)
        {
            VerifyScriptPath(actual, scriptPathElement.GetString() ?? "", file, pointer + "/scriptPath", "MUI4011", diagnostics);
        }

        if (!definition.TryGetProperty("children", out var children) || children.ValueKind != JsonValueKind.Array)
        {
            return;
        }

        var index = 0;
        foreach (var childDefinition in children.EnumerateArray())
        {
            var childName = childDefinition.TryGetProperty("name", out var childNameElement) ? childNameElement.GetString() ?? "" : "";
            var childPointer = $"{pointer}/children/{index}";
            var child = actual.GetNodeOrNull(childName);
            if (child is null)
            {
                diagnostics.Add(Error("MUI4003", file, childPointer + "/name", $"Generated scene does not contain child node '{childName}' below '{actual.GetPath()}'."));
            }
            else
            {
                VerifyLayoutNode(childDefinition, sceneRoot, child, file, childPointer, isRoot: false, diagnostics);
            }
            index++;
        }
    }

    private static void VerifySceneInstance(
        Node actual,
        string scenePath,
        string file,
        string pointer,
        List<ManifestDiagnostic> diagnostics)
    {
        PackedScene? referenced = null;
        try
        {
            referenced = ResourceLoader.Load<PackedScene>(scenePath);
            if (referenced is null)
            {
                diagnostics.Add(Error("MUI4016", file, pointer, $"Scene instance resource could not be loaded: {scenePath}"));
                return;
            }

            if (actual is not Control)
            {
                diagnostics.Add(Error("MUI4016", file, pointer, $"Instantiated scene node '{actual.GetPath()}' must inherit Control."));
            }
        }
        catch (Exception ex)
        {
            diagnostics.Add(Error("MUI4016", file, pointer, $"Scene instance verification failed for '{scenePath}': {ex.Message}"));
        }
        finally
        {
            referenced?.Dispose();
        }
    }

    private static void VerifyBindings(
        JsonElement bindings,
        string file,
        Control root,
        List<ManifestDiagnostic> diagnostics)
    {
        if (bindings.TryGetProperty("bindings", out var propertyBindings) && propertyBindings.ValueKind == JsonValueKind.Object)
        {
            foreach (var binding in propertyBindings.EnumerateObject())
            {
                var separator = binding.Name.LastIndexOf('.');
                if (separator <= 0)
                {
                    continue;
                }

                var pointer = $"/bindings/{EscapePointer(binding.Name)}";
                var node = FindNode(root, binding.Name[..separator], file, pointer, diagnostics);
                if (node is Control control)
                {
                    VerifyBindingProperty(control, binding.Name[(separator + 1)..], file, pointer, diagnostics);
                }
            }
        }

        if (bindings.TryGetProperty("inputs", out var inputs) && inputs.ValueKind == JsonValueKind.Array)
        {
            var index = 0;
            foreach (var input in inputs.EnumerateArray())
            {
                var pointer = $"/inputs/{index}";
                var target = GetOptionalString(input, "target");
                var node = FindNode(root, target, file, pointer + "/target", diagnostics);
                if (node is Control control)
                {
                    var property = GetOptionalString(input, "property");
                    VerifyInput(control, property, file, pointer + "/property", diagnostics);
                }
                index++;
            }
        }

        if (bindings.TryGetProperty("controls", out var controls) && controls.ValueKind == JsonValueKind.Array)
        {
            var index = 0;
            foreach (var controlBinding in controls.EnumerateArray())
            {
                var pointer = $"/controls/{index}";
                var node = FindNode(root, GetOptionalString(controlBinding, "target"), file, pointer + "/target", diagnostics);
                if (node is not null)
                {
                    var widgetClass = GetOptionalString(controlBinding, "widgetClass");
                    if (!string.IsNullOrWhiteSpace(widgetClass) && !node.IsClass(widgetClass))
                    {
                        diagnostics.Add(Error("MUI4010", file, pointer + "/widgetClass", $"Node '{node.GetPath()}' is not a '{widgetClass}'."));
                    }

                    if (controlBinding.TryGetProperty("events", out var events) && events.ValueKind == JsonValueKind.Array)
                    {
                        var eventIndex = 0;
                        foreach (var eventBinding in events.EnumerateArray())
                        {
                            var signal = GetOptionalString(eventBinding, "event");
                            if (!string.IsNullOrWhiteSpace(signal) && !node.HasSignal(signal))
                            {
                                diagnostics.Add(Error("MUI4014", file, $"{pointer}/events/{eventIndex}/event", $"Node '{node.GetPath()}' does not expose signal '{signal}'."));
                            }
                            eventIndex++;
                        }
                    }
                }
                index++;
            }
        }

        if (bindings.TryGetProperty("repeaters", out var repeaters) && repeaters.ValueKind == JsonValueKind.Array)
        {
            var index = 0;
            foreach (var repeater in repeaters.EnumerateArray())
            {
                var pointer = $"/repeaters/{index}";
                var target = FindNode(root, GetOptionalString(repeater, "target"), file, pointer + "/target", diagnostics) as Control;
                var template = FindNode(root, GetOptionalString(repeater, "template"), file, pointer + "/template", diagnostics) as Control;
                if (target is not null && template is not null && template.GetParent() != target && !target.IsAncestorOf(template))
                {
                    diagnostics.Add(Error("MUI4015", file, pointer + "/template", $"Repeater template '{template.GetPath()}' is not below target '{target.GetPath()}'."));
                }

                if (template is not null && repeater.TryGetProperty("bindings", out var itemBindings) && itemBindings.ValueKind == JsonValueKind.Object)
                {
                    foreach (var itemBinding in itemBindings.EnumerateObject())
                    {
                        var separator = itemBinding.Name.LastIndexOf('.');
                        if (separator <= 0)
                        {
                            continue;
                        }
                        var itemPointer = $"{pointer}/bindings/{EscapePointer(itemBinding.Name)}";
                        var itemNode = FindNode(template, itemBinding.Name[..separator], file, itemPointer, diagnostics);
                        if (itemNode is Control itemControl)
                        {
                            VerifyBindingProperty(itemControl, itemBinding.Name[(separator + 1)..], file, itemPointer, diagnostics);
                        }
                    }
                }
                index++;
            }
        }
    }

    private static void VerifyBindingProperty(
        Control target,
        string property,
        string file,
        string pointer,
        List<ManifestDiagnostic> diagnostics)
    {
        var compatible = property switch
        {
            "text" => target is Label or Button or LineEdit or RichTextLabel,
            "visible" or "visibility" or "themeClass" => true,
            "enabled" => target is BaseButton or LineEdit or TextEdit,
            "value" => target is Godot.Range,
            "texture" => target is TextureRect or TextureButton or Button,
            _ => false,
        };
        if (!compatible)
        {
            diagnostics.Add(Error("MUI4012", file, pointer, $"Binding property '{property}' cannot be applied to node '{target.GetPath()}' ({target.GetClass()})."));
        }
    }

    private static void VerifyInput(
        Control target,
        string property,
        string file,
        string pointer,
        List<ManifestDiagnostic> diagnostics)
    {
        var signal = property switch
        {
            "text" => "text_changed",
            "buttonPressed" => "toggled",
            "value" => "value_changed",
            "selected" => "item_selected",
            _ => "",
        };
        if (string.IsNullOrWhiteSpace(signal) || !target.HasSignal(signal))
        {
            diagnostics.Add(Error("MUI4013", file, pointer, $"Input property '{property}' is not supported by node '{target.GetPath()}' ({target.GetClass()})."));
        }
    }

    private static Node? FindNode(
        Node root,
        string path,
        string file,
        string pointer,
        List<ManifestDiagnostic> diagnostics)
    {
        if (string.IsNullOrWhiteSpace(path))
        {
            diagnostics.Add(Error("MUI4003", file, pointer, "Node path is empty."));
            return null;
        }

        var node = root.GetNodeOrNull(path);
        if (node is null)
        {
            diagnostics.Add(Error("MUI4003", file, pointer, $"Generated scene does not contain node path '{path}'."));
        }
        return node;
    }

    private static void VerifyAssets(
        string packageDirectory,
        JsonElement assetsDocument,
        string file,
        List<ManifestDiagnostic> diagnostics)
    {
        if (!assetsDocument.TryGetProperty("assets", out var assets) || assets.ValueKind != JsonValueKind.Array)
        {
            return;
        }

        var index = 0;
        foreach (var asset in assets.EnumerateArray())
        {
            var kind = GetOptionalString(asset, "kind");
            var pointer = $"/assets/{index}";
            var path = GetOptionalString(asset, "relativePath");
            if (string.Equals(kind, "theme", StringComparison.OrdinalIgnoreCase) &&
                asset.TryGetProperty("theme", out var theme) && theme.ValueKind == JsonValueKind.Object)
            {
                path = GetOptionalString(theme, "outputPath");
                path = ToProjectResourcePath(path);
                VerifyResource<Theme>(path, file, pointer + "/theme/outputPath", "MUI4004", diagnostics);
            }
            else
            {
                path = path.StartsWith("res://", StringComparison.Ordinal)
                    ? path
                    : ToResourcePath(Path.Combine(packageDirectory, path));
                if (string.Equals(kind, "texture", StringComparison.OrdinalIgnoreCase))
                {
                    VerifyResource<Texture2D>(path, file, pointer + "/relativePath", "MUI4017", diagnostics);
                }
                else if (string.Equals(kind, "font", StringComparison.OrdinalIgnoreCase))
                {
                    VerifyResource<Font>(path, file, pointer + "/relativePath", "MUI4017", diagnostics);
                }
                else
                {
                    VerifyResource<Resource>(path, file, pointer + "/relativePath", "MUI4017", diagnostics);
                }
            }
            index++;
        }
    }

    private static void VerifyCatalog(
        string packagePath,
        JsonElement package,
        Control root,
        List<ManifestDiagnostic> diagnostics)
    {
        var packageFile = Path.GetFileName(packagePath);
        var godot = package.GetProperty("godot");
        var widgetClass = godot.GetProperty("widgetClass").GetString() ?? "";
        var namespaceName = godot.GetProperty("namespace").GetString() ?? "";
        var catalogTypeName = $"{namespaceName}.{widgetClass}ManifestCatalog";
        var catalogPath = Path.Combine(
            ProjectSettings.GlobalizePath("res://"),
            godot.GetProperty("outputDir").GetString() ?? "",
            $"{widgetClass}.Catalog.g.cs");
        if (!File.Exists(catalogPath))
        {
            diagnostics.Add(Error("MUI4008", packageFile, "/godot/outputDir", $"Generated Catalog source is missing: {ToResourcePath(catalogPath)}"));
            return;
        }

        var catalogType = FindType(catalogTypeName);
        var createEntry = catalogType?.GetMethod("CreateEntry", BindingFlags.Public | BindingFlags.Static);
        if (createEntry is null)
        {
            diagnostics.Add(Error("MUI4008", packageFile, "/godot/widgetClass", $"Compiled Catalog type '{catalogTypeName}' was not found. Rebuild the C# project after generation."));
            return;
        }

        ManifestUiCatalogEntry? entry = null;
        try
        {
            entry = createEntry.Invoke(null, null) as ManifestUiCatalogEntry;
        }
        catch (Exception ex)
        {
            diagnostics.Add(Error("MUI4008", packageFile, "/godot/widgetClass", $"Catalog CreateEntry failed: {Unwrap(ex).Message}"));
        }
        if (entry is null)
        {
            return;
        }

        var packageId = package.GetProperty("packageId").GetString() ?? "";
        var scenePath = godot.GetProperty("scenePath").GetString() ?? "";
        if (!string.Equals(entry.PackageId.ToString(), packageId, StringComparison.Ordinal) ||
            !string.Equals(entry.ScenePath, scenePath, StringComparison.Ordinal))
        {
            diagnostics.Add(Error("MUI4008", packageFile, "/godot/scenePath", $"Catalog maps '{entry.PackageId}' to '{entry.ScenePath}', expected '{packageId}' to '{scenePath}'."));
        }

        var expectedScope = GetExpectedScope(package);
        if (entry.ControllerScope != expectedScope)
        {
            diagnostics.Add(Error("MUI4008", packageFile, "/runtime/controllerScope", $"Catalog controller scope is '{entry.ControllerScope}', expected '{expectedScope}'."));
        }

        VerifyCatalogController(godot, entry, packageFile, diagnostics);
        VerifyCatalogTranslations(packagePath, package, entry, root, diagnostics);
    }

    private static void VerifyCatalogController(
        JsonElement godot,
        ManifestUiCatalogEntry entry,
        string packageFile,
        List<ManifestDiagnostic> diagnostics)
    {
        var controllerTypeName = godot.GetProperty("controllerClass").GetString() ?? "";
        var controllerType = FindType(controllerTypeName);
        if (controllerType is null || !typeof(ManifestControllerBase).IsAssignableFrom(controllerType))
        {
            diagnostics.Add(Error("MUI4007", packageFile, "/godot/controllerClass", $"Controller type '{controllerTypeName}' is not a compiled ManifestControllerBase."));
            return;
        }
        if (entry.ControllerFactory is null)
        {
            diagnostics.Add(Error("MUI4007", packageFile, "/godot/controllerClass", "Catalog does not provide a Controller factory."));
            return;
        }

        ManifestControllerBase? controller = null;
        try
        {
            controller = entry.ControllerFactory();
            if (!controllerType.IsInstanceOfType(controller))
            {
                diagnostics.Add(Error("MUI4007", packageFile, "/godot/controllerClass", $"Catalog creates '{controller.GetType().FullName}', expected '{controllerTypeName}'."));
            }
        }
        catch (Exception ex)
        {
            diagnostics.Add(Error("MUI4007", packageFile, "/godot/controllerClass", $"Catalog Controller factory failed: {ex.Message}"));
        }
        finally
        {
            controller?.Dispose();
        }
    }

    private static void VerifyCatalogTranslations(
        string packagePath,
        JsonElement package,
        ManifestUiCatalogEntry entry,
        Control root,
        List<ManifestDiagnostic> diagnostics)
    {
        var packageFile = Path.GetFileName(packagePath);
        var hasStrings = package.TryGetProperty("strings", out var stringsReference) && stringsReference.ValueKind == JsonValueKind.String;
        var expectedDomain = hasStrings ? package.GetProperty("packageId").GetString() ?? "" : "";
        if (!string.Equals(entry.TranslationDomain, expectedDomain, StringComparison.Ordinal))
        {
            diagnostics.Add(Error("MUI4009", packageFile, "/strings", $"Catalog translation domain is '{entry.TranslationDomain}', expected '{expectedDomain}'."));
        }
        if (root is ManifestGeneratedWidget widget && !string.Equals(widget.TranslationDomain, expectedDomain, StringComparison.Ordinal))
        {
            diagnostics.Add(Error("MUI4009", packageFile, "/strings", $"Generated widget translation domain is '{widget.TranslationDomain}', expected '{expectedDomain}'."));
        }

        var expectedLocales = new HashSet<string>(StringComparer.Ordinal);
        var expectedPaths = new HashSet<string>(StringComparer.Ordinal);
        if (hasStrings)
        {
            var stringsPath = Path.Combine(Path.GetDirectoryName(packagePath)!, stringsReference.GetString() ?? "strings.json");
            using var strings = ReadDocument(stringsPath);
            var godot = package.GetProperty("godot");
            var outputDir = godot.GetProperty("outputDir").GetString() ?? "";
            var systemName = godot.GetProperty("systemName").GetString() ?? "";
            if (strings.RootElement.TryGetProperty("locales", out var locales) && locales.ValueKind == JsonValueKind.Array)
            {
                foreach (var locale in locales.EnumerateArray())
                {
                    var localeName = locale.GetString() ?? "";
                    expectedLocales.Add(localeName);
                    expectedPaths.Add(ToProjectResourcePath(Path.Combine(outputDir, "translations", $"{systemName}.{localeName}.tres")));
                }
            }
        }

        if (entry.TranslationPaths.Count != expectedPaths.Count ||
            !new HashSet<string>(entry.TranslationPaths, StringComparer.Ordinal).SetEquals(expectedPaths))
        {
            diagnostics.Add(Error(
                "MUI4009",
                packageFile,
                "/strings",
                $"Catalog translation paths are [{string.Join(", ", entry.TranslationPaths)}], expected [{string.Join(", ", expectedPaths.OrderBy(value => value, StringComparer.Ordinal))}]."));
        }

        var actualLocales = new HashSet<string>(StringComparer.Ordinal);
        for (var index = 0; index < entry.TranslationPaths.Count; index++)
        {
            Translation? translation = null;
            try
            {
                translation = ResourceLoader.Load<Translation>(entry.TranslationPaths[index]);
                if (translation is null)
                {
                    diagnostics.Add(Error("MUI4009", packageFile, "/strings", $"Catalog translation could not be loaded: {entry.TranslationPaths[index]}"));
                    continue;
                }
                actualLocales.Add(translation.Locale);
            }
            catch (Exception ex)
            {
                diagnostics.Add(Error("MUI4009", packageFile, "/strings", $"Catalog translation verification failed for '{entry.TranslationPaths[index]}': {ex.Message}"));
            }
            finally
            {
                translation?.Dispose();
            }
        }

        if (!actualLocales.SetEquals(expectedLocales))
        {
            diagnostics.Add(Error(
                "MUI4009",
                packageFile,
                "/strings",
                $"Catalog translation locales are [{string.Join(", ", actualLocales.OrderBy(value => value, StringComparer.Ordinal))}], expected [{string.Join(", ", expectedLocales.OrderBy(value => value, StringComparer.Ordinal))}]."));
        }
    }

    private static void VerifyScriptPath(
        GodotObject target,
        string expectedPath,
        string file,
        string pointer,
        string code,
        List<ManifestDiagnostic> diagnostics)
    {
        Script? scriptResource = null;
        try
        {
            scriptResource = ResourceLoader.Load<Script>(expectedPath);
            if (scriptResource is null)
            {
                diagnostics.Add(Error(code, file, pointer, $"Script resource could not be loaded: {expectedPath}"));
                return;
            }

            var attachedScript = target.GetScript().AsGodotObject() as Script;
            if (attachedScript is null || !string.Equals(attachedScript.ResourcePath, expectedPath, StringComparison.Ordinal))
            {
                diagnostics.Add(Error(code, file, pointer, $"Node script is '{attachedScript?.ResourcePath ?? "<none>"}', expected '{expectedPath}'."));
            }
        }
        catch (Exception ex)
        {
            diagnostics.Add(Error(code, file, pointer, $"Script verification failed for '{expectedPath}': {ex.Message}"));
        }
        finally
        {
            scriptResource?.Dispose();
        }
    }

    private static void VerifyResource<T>(
        string path,
        string file,
        string pointer,
        string code,
        List<ManifestDiagnostic> diagnostics)
        where T : Resource
    {
        Resource? resource = null;
        try
        {
            resource = ResourceLoader.Load(path);
            if (resource is not T)
            {
                diagnostics.Add(Error(code, file, pointer, $"Resource '{path}' could not be loaded as {typeof(T).Name}."));
            }
        }
        catch (Exception ex)
        {
            diagnostics.Add(Error(code, file, pointer, $"Resource verification failed for '{path}': {ex.Message}"));
        }
        finally
        {
            resource?.Dispose();
        }
    }

    private static ManifestControllerScope GetExpectedScope(JsonElement package)
    {
        if (!package.TryGetProperty("runtime", out var runtime) || runtime.ValueKind != JsonValueKind.Object ||
            !runtime.TryGetProperty("controllerScope", out var scope) || scope.ValueKind != JsonValueKind.String)
        {
            return ManifestControllerScope.Package;
        }
        return scope.GetString()?.ToLowerInvariant() switch
        {
            "instance" => ManifestControllerScope.Instance,
            "screen" => ManifestControllerScope.Screen,
            _ => ManifestControllerScope.Package,
        };
    }

    private static Type? FindType(string fullName)
    {
        return AppDomain.CurrentDomain.GetAssemblies()
            .Select(assembly => assembly.GetType(fullName, throwOnError: false, ignoreCase: false))
            .FirstOrDefault(type => type is not null);
    }

    private static Exception Unwrap(Exception exception)
    {
        return exception is TargetInvocationException { InnerException: not null } invocation ? invocation.InnerException! : exception;
    }

    private static JsonDocument ReadDocument(string path)
    {
        return JsonDocument.Parse(File.ReadAllText(path));
    }

    private static string GetReference(JsonElement package, string property, string fallback)
    {
        return package.TryGetProperty(property, out var value) && value.ValueKind == JsonValueKind.String
            ? value.GetString() ?? fallback
            : fallback;
    }

    private static string GetString(JsonElement root, string objectName, string propertyName)
    {
        return root.GetProperty(objectName).GetProperty(propertyName).GetString() ?? "";
    }

    private static string GetOptionalString(JsonElement element, string propertyName)
    {
        return element.TryGetProperty(propertyName, out var value) && value.ValueKind == JsonValueKind.String
            ? value.GetString() ?? ""
            : "";
    }

    private static string ToProjectResourcePath(string path)
    {
        if (path.StartsWith("res://", StringComparison.Ordinal))
        {
            return path;
        }
        return ToResourcePath(Path.Combine(ProjectSettings.GlobalizePath("res://"), path));
    }

    private static string ToResourcePath(string absolutePath)
    {
        var localized = ProjectSettings.LocalizePath(Path.GetFullPath(absolutePath));
        return localized.Replace('\\', '/');
    }

    private static ManifestDiagnostic Error(string code, string file, string pointer, string message, string? hint = null)
    {
        return new ManifestDiagnostic(code, ManifestDiagnosticSeverity.Error, file, pointer, 0, 0, message, hint ?? "Regenerate the package, rebuild the C# project, and inspect the referenced generated resource.");
    }

    private static string EscapePointer(string value)
    {
        return value.Replace("~", "~0", StringComparison.Ordinal).Replace("/", "~1", StringComparison.Ordinal);
    }
}
#endif

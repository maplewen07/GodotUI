using Godot;
using GodotUi.Manifest.Tooling;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;

namespace GodotUi.Manifest.EngineTooling;

public static class ManifestUiSceneExporter
{
    private const string NodeIdMetadata = "metadata/_manifest_ui_id";
    private static readonly UTF8Encoding Utf8NoBom = new(false);
    private static readonly JsonSerializerOptions JsonOptions = new() { WriteIndented = true };

    public static ManifestUiToolResult Export(string packagePath)
    {
        var diagnostics = new List<ManifestDiagnostic>();
        try
        {
            packagePath = Path.GetFullPath(packagePath);
            var projectRoot = Path.GetFullPath(ProjectSettings.GlobalizePath("res://"));
            if (!File.Exists(packagePath))
            {
                return Failure(Error(packagePath, "/package", "package manifest does not exist"), ManifestUiTool.UsageOrEnvironmentFailure);
            }

            var packageDirectory = Path.GetDirectoryName(packagePath)!;
            var package = ReadObject(packagePath);
            var layoutPath = ResolveReferencedFile(packageDirectory, package, "layout", "layout.json");
            var assetsPath = ResolveReferencedFile(packageDirectory, package, "assets", "assets.json");
            var stringsPath = TryResolveReferencedFile(packageDirectory, package, "strings");
            var layout = ReadObject(layoutPath);
            var assets = ReadObject(assetsPath);
            var strings = stringsPath is null ? null : ReadObject(stringsPath);
            var scenePath = package["godot"]?["scenePath"]?.GetValue<string>() ?? "";
            if (!scenePath.StartsWith("res://", StringComparison.Ordinal))
            {
                return Failure(Error(Path.GetFileName(packagePath), "/godot/scenePath", "must be a res:// scene path"));
            }

            var scene = ResourceLoader.Load<PackedScene>(scenePath, "PackedScene", ResourceLoader.CacheMode.Replace);
            if (scene is null)
            {
                return Failure(Error(scenePath, "/scene", "could not load the scene as PackedScene"));
            }

            var state = scene.GetState();
            if (state.GetBaseSceneState() is not null)
            {
                return Failure(Error(scenePath, "/scene", "inherited scenes cannot be exported", "Flatten the scene before exporting."));
            }
            if (state.GetConnectionCount() > 0)
            {
                return Failure(Error(scenePath, "/connections", "scene signal connections are not represented by layout.json", "Move behavior into bindings.json or generated code."));
            }

            var oldLayoutRoot = layout["root"] as JsonObject ?? throw new InvalidDataException("layout.json root must be an object");
            var oldIndex = OldLayoutIndex.Create(oldLayoutRoot);
            var assetIndex = new AssetIndex(projectRoot, packageDirectory, package, assets, diagnostics);
            var localization = new LocalizationUpdater(strings, diagnostics);
            var records = ReadSceneRecords(state, scenePath, diagnostics);
            if (diagnostics.Any(item => item.Severity == ManifestDiagnosticSeverity.Error))
            {
                return Failure(diagnostics);
            }

            var usedIds = new HashSet<string>(StringComparer.Ordinal);
            var rootRecord = records.SingleOrDefault(record => record.ParentPath is null);
            if (rootRecord is null)
            {
                return Failure(Error(scenePath, "/scene", "scene has no unique root node"));
            }
            var children = records.Where(record => record.ParentPath is not null)
                .GroupBy(record => record.ParentPath!, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.OrderBy(record => record.Index).ToArray(), StringComparer.Ordinal);
            var exportedRoot = ExportNode(rootRecord, children, oldIndex, usedIds, assetIndex, localization, scenePath, diagnostics, isRoot: true);
            if (diagnostics.Any(item => item.Severity == ManifestDiagnosticSeverity.Error))
            {
                return Failure(diagnostics);
            }

            layout["root"] = exportedRoot;
            var candidates = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase)
            {
                [layoutPath] = Serialize(layout),
                [assetsPath] = Serialize(assets),
            };
            if (stringsPath is not null && strings is not null)
            {
                candidates[stringsPath] = Serialize(strings);
            }

            var originals = candidates.ToDictionary(pair => pair.Key, pair => File.ReadAllText(pair.Key), StringComparer.OrdinalIgnoreCase);
            try
            {
                foreach (var (path, content) in candidates)
                {
                    AtomicWrite(path, content);
                }

                var validation = ManifestUiTool.Execute(new[] { "validate", packagePath }, projectRoot);
                if (!validation.Success)
                {
                    foreach (var (path, content) in originals)
                    {
                        AtomicWrite(path, content);
                    }
                    return new ManifestUiToolResult
                    {
                        ExitCode = validation.ExitCode,
                        Diagnostics = diagnostics.Concat(validation.Diagnostics).ToArray(),
                        Messages = new[] { "Export validation failed; source JSON was restored." },
                    };
                }
            }
            catch
            {
                foreach (var (path, content) in originals)
                {
                    AtomicWrite(path, content);
                }
                throw;
            }

            return new ManifestUiToolResult
            {
                ExitCode = ManifestUiTool.Success,
                Diagnostics = diagnostics,
                Messages = new[] { $"Exported {scenePath} -> {Path.GetRelativePath(projectRoot, layoutPath).Replace('\\', '/')}" },
            };
        }
        catch (Exception ex)
        {
            diagnostics.Add(Error(Path.GetFileName(packagePath), "/export", $"scene export failed: {ex.Message}"));
            return Failure(diagnostics, ManifestUiTool.InternalFailure);
        }
    }

    private static JsonObject ExportNode(
        SceneRecord record,
        IReadOnlyDictionary<string, SceneRecord[]> children,
        OldLayoutIndex oldIndex,
        HashSet<string> usedIds,
        AssetIndex assets,
        LocalizationUpdater localization,
        string scenePath,
        List<ManifestDiagnostic> diagnostics,
        bool isRoot)
    {
        var oldNode = oldIndex.Match(record.MetadataId, record.Path, record.Name, usedIds);
        var id = oldNode?["id"]?.GetValue<string>();
        if (string.IsNullOrWhiteSpace(id))
        {
            id = CreateNodeId(record, usedIds);
        }
        usedIds.Add(id!);

        var node = new JsonObject
        {
            ["id"] = id,
            ["type"] = record.Instance is null ? record.Type : "SceneInstance",
            ["name"] = record.Name,
        };
        if (record.Instance is not null)
        {
            if (children.ContainsKey(record.Path))
            {
                diagnostics.Add(Error(scenePath, $"/nodes/{record.Path}", "scene instance overrides or added children cannot be represented by layout.json"));
            }
            node["scenePath"] = record.Instance.ResourcePath;
        }

        var properties = new JsonObject();
        var localizedProperties = new JsonObject();
        var oldLocalization = oldNode?["localization"] as JsonObject;
        foreach (var (propertyName, value) in record.Properties.OrderBy(pair => pair.Key, StringComparer.Ordinal))
        {
            if (propertyName == NodeIdMetadata)
            {
                continue;
            }
            if (propertyName.StartsWith("metadata/", StringComparison.Ordinal))
            {
                diagnostics.Add(Error(scenePath, $"/nodes/{record.Path}/{propertyName}", "custom node metadata is not represented by layout.json"));
                continue;
            }
            if (propertyName == "script")
            {
                if (isRoot)
                {
                    continue;
                }
                var script = value.AsGodotObject() as Script;
                if (script is null || string.IsNullOrWhiteSpace(script.ResourcePath))
                {
                    diagnostics.Add(Error(scenePath, $"/nodes/{record.Path}/script", "built-in scripts cannot be exported"));
                }
                else
                {
                    node["scriptPath"] = script.ResourcePath;
                }
                continue;
            }

            var jsonValue = ConvertVariant(value, assets, scenePath, record.Path, propertyName, diagnostics);
            if (jsonValue is null)
            {
                continue;
            }
            if (oldLocalization is not null && oldLocalization[propertyName] is JsonNode localizationValue)
            {
                var key = ReadLocalizationKey(localizationValue);
                if (jsonValue is not JsonValue scalar || !scalar.TryGetValue<string>(out var text))
                {
                    diagnostics.Add(Error(scenePath, $"/nodes/{record.Path}/{propertyName}", "localized properties must serialize as strings"));
                    continue;
                }
                if (!string.Equals(text, key, StringComparison.Ordinal))
                {
                    localization.UpdateDefault(key, text, scenePath, record.Path, propertyName);
                }
                localizedProperties[propertyName] = localizationValue.DeepClone();
                continue;
            }
            properties[propertyName] = jsonValue;
        }

        if (properties.Count > 0)
        {
            node["properties"] = properties;
        }
        if (localizedProperties.Count > 0)
        {
            node["localization"] = localizedProperties;
        }
        if (children.TryGetValue(record.Path, out var childRecords))
        {
            var childNodes = new JsonArray();
            foreach (var child in childRecords)
            {
                childNodes.Add(ExportNode(child, children, oldIndex, usedIds, assets, localization, scenePath, diagnostics, isRoot: false));
            }
            if (childNodes.Count > 0)
            {
                node["children"] = childNodes;
            }
        }
        return node;
    }

    private static JsonNode? ConvertVariant(
        Variant value,
        AssetIndex assets,
        string scenePath,
        string nodePath,
        string propertyName,
        List<ManifestDiagnostic> diagnostics)
    {
        switch (value.VariantType)
        {
            case Variant.Type.Nil:
                return null;
            case Variant.Type.Bool:
                return JsonValue.Create(value.AsBool());
            case Variant.Type.Int:
                return JsonValue.Create(value.AsInt64());
            case Variant.Type.Float:
                return JsonValue.Create(value.AsDouble());
            case Variant.Type.String:
                return JsonValue.Create(value.AsString());
            case Variant.Type.StringName:
                return JsonValue.Create(value.AsStringName().ToString());
            case Variant.Type.Vector2:
            {
                var vector = value.AsVector2();
                return new JsonArray(JsonValue.Create(vector.X), JsonValue.Create(vector.Y));
            }
            case Variant.Type.Vector2I:
            {
                var vector = value.AsVector2I();
                return new JsonObject { ["vector2i"] = new JsonArray(vector.X, vector.Y) };
            }
            case Variant.Type.Color:
            {
                var color = value.AsColor();
                return new JsonObject { ["color"] = new JsonArray(color.R, color.G, color.B, color.A) };
            }
            case Variant.Type.NodePath:
                return new JsonObject { ["nodePath"] = value.AsNodePath().ToString() };
            case Variant.Type.Object:
            {
                if (value.AsGodotObject() is not Resource resource)
                {
                    break;
                }
                var assetId = assets.Resolve(resource, scenePath, nodePath, propertyName);
                return assetId is null ? null : new JsonObject { ["assetRef"] = assetId };
            }
        }

        diagnostics.Add(Error(
            scenePath,
            $"/nodes/{nodePath}/{propertyName}",
            $"Godot Variant type '{value.VariantType}' is not supported by layout.json"));
        return null;
    }

    private static List<SceneRecord> ReadSceneRecords(SceneState state, string scenePath, List<ManifestDiagnostic> diagnostics)
    {
        var records = new List<SceneRecord>();
        for (var index = 0; index < state.GetNodeCount(); index++)
        {
            if (state.GetNodeGroups(index).Any())
            {
                diagnostics.Add(Error(scenePath, $"/nodes/{index}/groups", "node groups are not represented by layout.json"));
            }
            var path = NormalizeNodePath(state.GetNodePath(index, false).ToString());
            var properties = new Dictionary<string, Variant>(StringComparer.Ordinal);
            for (var propertyIndex = 0; propertyIndex < state.GetNodePropertyCount(index); propertyIndex++)
            {
                properties[state.GetNodePropertyName(index, propertyIndex).ToString()] = state.GetNodePropertyValue(index, propertyIndex);
            }
            var metadataId = properties.TryGetValue(NodeIdMetadata, out var metadata) && metadata.VariantType == Variant.Type.String
                ? metadata.AsString()
                : "";
            records.Add(new SceneRecord(
                index,
                path,
                ParentPath(path),
                state.GetNodeName(index).ToString(),
                state.GetNodeType(index).ToString(),
                metadataId,
                state.GetNodeInstance(index),
                properties));
        }
        return records;
    }

    private static string CreateNodeId(SceneRecord record, HashSet<string> usedIds)
    {
        var segments = record.Path == "." ? new[] { record.Name } : record.Path.Split('/');
        for (var take = 1; take <= segments.Length; take++)
        {
            var candidate = string.Concat(segments.Skip(Math.Max(0, segments.Length - take)).Select(ToIdentifierPart));
            if (!string.IsNullOrWhiteSpace(candidate) && !usedIds.Contains(candidate))
            {
                return candidate;
            }
        }
        var fallback = ToIdentifierPart(record.Name);
        var suffix = 2;
        while (usedIds.Contains(fallback + suffix))
        {
            suffix++;
        }
        return fallback + suffix;
    }

    private static string ToIdentifierPart(string value)
    {
        var parts = value.Split(value.Where(character => !char.IsLetterOrDigit(character)).Distinct().ToArray(), StringSplitOptions.RemoveEmptyEntries);
        var result = string.Concat(parts.Select(part => char.ToUpperInvariant(part[0]) + part[1..]));
        return string.IsNullOrWhiteSpace(result) ? "Node" : result;
    }

    private static string ReadLocalizationKey(JsonNode value)
    {
        if (value is JsonValue scalar && scalar.TryGetValue<string>(out var key))
        {
            return key;
        }
        return value["key"]?.GetValue<string>() ?? "";
    }

    private static string NormalizeNodePath(string path)
    {
        path = path.Replace('\\', '/').Trim('/');
        return string.IsNullOrWhiteSpace(path) ? "." : path;
    }

    private static string? ParentPath(string path)
    {
        if (path == ".")
        {
            return null;
        }
        var separator = path.LastIndexOf('/');
        return separator < 0 ? "." : path[..separator];
    }

    private static JsonObject ReadObject(string path)
    {
        var options = new JsonDocumentOptions { AllowTrailingCommas = true, CommentHandling = JsonCommentHandling.Skip };
        return JsonNode.Parse(File.ReadAllText(path), documentOptions: options) as JsonObject
            ?? throw new InvalidDataException($"{Path.GetFileName(path)} must contain a JSON object");
    }

    private static string ResolveReferencedFile(string directory, JsonObject package, string property, string fallback)
    {
        var reference = package[property]?.GetValue<string>();
        return Path.GetFullPath(Path.Combine(directory, string.IsNullOrWhiteSpace(reference) ? fallback : reference));
    }

    private static string? TryResolveReferencedFile(string directory, JsonObject package, string property)
    {
        var reference = package[property]?.GetValue<string>();
        return string.IsNullOrWhiteSpace(reference) ? null : Path.GetFullPath(Path.Combine(directory, reference));
    }

    private static string Serialize(JsonObject value)
    {
        return value.ToJsonString(JsonOptions).Replace("\r\n", "\n", StringComparison.Ordinal).TrimEnd() + "\n";
    }

    private static void AtomicWrite(string path, string content)
    {
        var temporary = Path.Combine(Path.GetDirectoryName(path)!, $".{Path.GetFileName(path)}.{Guid.NewGuid():N}.tmp");
        try
        {
            File.WriteAllText(temporary, content, Utf8NoBom);
            File.Move(temporary, path, overwrite: true);
        }
        finally
        {
            if (File.Exists(temporary))
            {
                File.Delete(temporary);
            }
        }
    }

    private static ManifestDiagnostic Error(string file, string pointer, string message, string hint = "")
        => new("MUI4100", ManifestDiagnosticSeverity.Error, file.Replace('\\', '/'), pointer, 0, 0, message, hint);

    private static ManifestUiToolResult Failure(ManifestDiagnostic diagnostic, int exitCode = ManifestUiTool.ValidationFailure)
        => Failure(new[] { diagnostic }, exitCode);

    private static ManifestUiToolResult Failure(IEnumerable<ManifestDiagnostic> diagnostics, int exitCode = ManifestUiTool.ValidationFailure)
        => new() { ExitCode = exitCode, Diagnostics = diagnostics.ToArray() };

    private sealed record SceneRecord(
        int Index,
        string Path,
        string? ParentPath,
        string Name,
        string Type,
        string MetadataId,
        PackedScene? Instance,
        Dictionary<string, Variant> Properties);

    private sealed class OldLayoutIndex
    {
        private readonly Dictionary<string, JsonObject> _byId = new(StringComparer.Ordinal);
        private readonly Dictionary<string, JsonObject> _byPath = new(StringComparer.Ordinal);
        private readonly Dictionary<string, List<JsonObject>> _byName = new(StringComparer.Ordinal);

        public static OldLayoutIndex Create(JsonObject root)
        {
            var index = new OldLayoutIndex();
            index.Add(root, ".");
            return index;
        }

        public JsonObject? Match(string metadataId, string path, string name, HashSet<string> usedIds)
        {
            if (!string.IsNullOrWhiteSpace(metadataId) && _byId.TryGetValue(metadataId, out var metadataNode) && !usedIds.Contains(metadataId))
            {
                return metadataNode;
            }
            if (_byPath.TryGetValue(path, out var pathNode) && !usedIds.Contains(pathNode["id"]?.GetValue<string>() ?? ""))
            {
                return pathNode;
            }
            if (_byName.TryGetValue(name, out var named) && named.Count == 1 && !usedIds.Contains(named[0]["id"]?.GetValue<string>() ?? ""))
            {
                return named[0];
            }
            return null;
        }

        private void Add(JsonObject node, string path)
        {
            var id = node["id"]?.GetValue<string>() ?? "";
            var name = node["name"]?.GetValue<string>() ?? "";
            if (!string.IsNullOrWhiteSpace(id)) _byId[id] = node;
            _byPath[path] = node;
            if (!_byName.TryGetValue(name, out var nodes)) _byName[name] = nodes = new List<JsonObject>();
            nodes.Add(node);
            if (node["children"] is not JsonArray children) return;
            foreach (var child in children.OfType<JsonObject>())
            {
                var childName = child["name"]?.GetValue<string>() ?? "";
                Add(child, path == "." ? childName : $"{path}/{childName}");
            }
        }
    }

    private sealed class AssetIndex
    {
        private readonly string _projectRoot;
        private readonly string _packageDirectory;
        private readonly JsonArray _assets;
        private readonly List<ManifestDiagnostic> _diagnostics;
        private readonly Dictionary<string, string> _idsByResourcePath = new(StringComparer.OrdinalIgnoreCase);
        private readonly HashSet<string> _ids = new(StringComparer.Ordinal);

        public AssetIndex(string projectRoot, string packageDirectory, JsonObject package, JsonObject assets, List<ManifestDiagnostic> diagnostics)
        {
            _projectRoot = projectRoot;
            _packageDirectory = packageDirectory;
            _assets = assets["assets"] as JsonArray ?? throw new InvalidDataException("assets.json assets must be an array");
            _diagnostics = diagnostics;
            foreach (var asset in _assets.OfType<JsonObject>())
            {
                var id = asset["id"]?.GetValue<string>() ?? "";
                var relativePath = asset["relativePath"]?.GetValue<string>() ?? "";
                if (!string.IsNullOrWhiteSpace(id)) _ids.Add(id);
                if (!string.IsNullOrWhiteSpace(relativePath))
                {
                    _idsByResourcePath[ToResourcePath(Path.GetFullPath(Path.Combine(packageDirectory, relativePath)))] = id;
                }
                if (string.Equals(asset["kind"]?.GetValue<string>(), "theme", StringComparison.OrdinalIgnoreCase))
                {
                    var outputPath = asset["theme"]?["outputPath"]?.GetValue<string>();
                    if (string.IsNullOrWhiteSpace(outputPath))
                    {
                        var godot = package["godot"] as JsonObject;
                        var systemName = godot?["systemName"]?.GetValue<string>() ?? package["packageId"]?.GetValue<string>()?.Split('.').Last() ?? "ui";
                        outputPath = Path.Combine(godot?["outputDir"]?.GetValue<string>() ?? "generated/ui", "assets", $"{ToIdentifierPart(systemName)}Theme.tres");
                    }
                    _idsByResourcePath[ToResourcePath(Path.GetFullPath(Path.Combine(_projectRoot, outputPath)))] = id;
                }
            }
        }

        public string? Resolve(Resource resource, string scenePath, string nodePath, string propertyName)
        {
            var resourcePath = resource.ResourcePath.Replace('\\', '/');
            if (string.IsNullOrWhiteSpace(resourcePath) || resourcePath.Contains("::", StringComparison.Ordinal))
            {
                _diagnostics.Add(Error(scenePath, $"/nodes/{nodePath}/{propertyName}", "built-in SubResources cannot be exported"));
                return null;
            }
            if (_idsByResourcePath.TryGetValue(resourcePath, out var existingId))
            {
                return existingId;
            }
            if (resource is Theme)
            {
                _diagnostics.Add(Error(scenePath, $"/nodes/{nodePath}/{propertyName}", "new Theme resources require an explicit assets.json configuration"));
                return null;
            }

            var absolutePath = Path.GetFullPath(ProjectSettings.GlobalizePath(resourcePath));
            var relative = Path.GetRelativePath(_packageDirectory, absolutePath).Replace('\\', '/');
            if (!relative.StartsWith("assets/", StringComparison.Ordinal) || relative.StartsWith("../", StringComparison.Ordinal))
            {
                _diagnostics.Add(Error(scenePath, $"/nodes/{nodePath}/{propertyName}", "new resources must be stored under the package assets/ directory"));
                return null;
            }
            if (!File.Exists(absolutePath))
            {
                _diagnostics.Add(Error(scenePath, $"/nodes/{nodePath}/{propertyName}", $"resource file does not exist: {resourcePath}"));
                return null;
            }

            var kind = resource switch
            {
                Texture2D => "texture",
                Font => "font",
                _ => "resource",
            };
            var baseId = ToAssetId(Path.ChangeExtension(relative["assets/".Length..], null) ?? "asset");
            var id = baseId;
            for (var suffix = 2; _ids.Contains(id); suffix++) id = baseId + "_" + suffix;
            _ids.Add(id);
            _idsByResourcePath[resourcePath] = id;
            _assets.Add(new JsonObject
            {
                ["id"] = id,
                ["relativePath"] = relative,
                ["kind"] = kind,
                ["contentHash"] = Sha256File(absolutePath),
            });
            return id;
        }

        private string ToResourcePath(string path) => "res://" + Path.GetRelativePath(_projectRoot, path).Replace('\\', '/');

        private static string ToAssetId(string path)
        {
            var builder = new StringBuilder();
            foreach (var character in path.Replace('\\', '/'))
            {
                if (char.IsLetterOrDigit(character)) builder.Append(char.ToLowerInvariant(character));
                else if (builder.Length > 0 && builder[^1] != '_') builder.Append('_');
            }
            var result = builder.ToString().Trim('_');
            return string.IsNullOrWhiteSpace(result) ? "asset" : result;
        }

        private static string Sha256File(string path)
        {
            using var stream = File.OpenRead(path);
            return "sha256:" + Convert.ToHexString(SHA256.HashData(stream)).ToLowerInvariant();
        }
    }

    private sealed class LocalizationUpdater
    {
        private readonly JsonObject? _strings;
        private readonly List<ManifestDiagnostic> _diagnostics;

        public LocalizationUpdater(JsonObject? strings, List<ManifestDiagnostic> diagnostics)
        {
            _strings = strings;
            _diagnostics = diagnostics;
        }

        public void UpdateDefault(string key, string text, string scenePath, string nodePath, string propertyName)
        {
            var defaultLocale = _strings?["defaultLocale"]?.GetValue<string>();
            var entries = _strings?["strings"] as JsonObject;
            if (string.IsNullOrWhiteSpace(defaultLocale) || entries?[key] is not JsonObject translations)
            {
                _diagnostics.Add(Error(scenePath, $"/nodes/{nodePath}/{propertyName}", $"cannot update localization key '{key}' because strings.json does not define it"));
                return;
            }
            translations[defaultLocale] = text;
        }
    }
}

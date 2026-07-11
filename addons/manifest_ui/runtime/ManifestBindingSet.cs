using System;
using System.Collections.Generic;
using System.Linq;

namespace GodotUi.Manifest;

public sealed class ManifestBindingSet
{
    public ManifestBindingSet(IEnumerable<ManifestPropertyBinding> properties, IReadOnlyDictionary<string, string>? assets = null)
        : this(properties, ManifestAssetCatalog.FromPathMap(assets))
    {
    }

    public ManifestBindingSet(
        IEnumerable<ManifestPropertyBinding> properties,
        ManifestAssetCatalog? assets,
        IEnumerable<ManifestRepeaterBinding>? repeaters = null,
        IEnumerable<ManifestInputBinding>? inputs = null,
        ManifestUiUpdatePolicy updatePolicy = ManifestUiUpdatePolicy.Manual,
        IEnumerable<ManifestLocalizedPropertyBinding>? localizations = null)
    {
        Properties = new List<ManifestPropertyBinding>(properties);
        Assets = assets ?? ManifestAssetCatalog.Empty;
        Repeaters = new List<ManifestRepeaterBinding>(repeaters ?? Array.Empty<ManifestRepeaterBinding>());
        Inputs = new List<ManifestInputBinding>(inputs ?? Array.Empty<ManifestInputBinding>());
        UpdatePolicy = updatePolicy;
        Localizations = new List<ManifestLocalizedPropertyBinding>(localizations ?? Array.Empty<ManifestLocalizedPropertyBinding>());
    }

    public IReadOnlyList<ManifestPropertyBinding> Properties { get; }
    public ManifestAssetCatalog Assets { get; }
    public IReadOnlyList<ManifestRepeaterBinding> Repeaters { get; }
    public IReadOnlyList<ManifestInputBinding> Inputs { get; }
    public ManifestUiUpdatePolicy UpdatePolicy { get; }
    public IReadOnlyList<ManifestLocalizedPropertyBinding> Localizations { get; }
}

public sealed class ManifestAssetCatalog
{
    private readonly Dictionary<string, ManifestAssetRef> _assets;

    public static ManifestAssetCatalog Empty { get; } = new(Array.Empty<ManifestAssetRef>(), "");

    public ManifestAssetCatalog(IEnumerable<ManifestAssetRef> assets, string themePath = "")
    {
        _assets = assets.ToDictionary(asset => asset.Id, StringComparer.Ordinal);
        ThemePath = themePath;
    }

    public string ThemePath { get; }

    public IReadOnlyDictionary<string, ManifestAssetRef> Assets => _assets;

    public bool TryGetPath(string id, out string path)
    {
        if (_assets.TryGetValue(id, out var asset))
        {
            path = asset.Path;
            return true;
        }

        path = "";
        return false;
    }

    public static ManifestAssetCatalog FromPathMap(IReadOnlyDictionary<string, string>? assets)
    {
        return assets is null
            ? Empty
            : new ManifestAssetCatalog(assets.Select(kvp => new ManifestAssetRef(kvp.Key, "", kvp.Value)));
    }
}

public sealed class ManifestAssetRef
{
    public ManifestAssetRef(string id, string kind, string path)
    {
        Id = id;
        Kind = kind;
        Path = path;
    }

    public string Id { get; }
    public string Kind { get; }
    public string Path { get; }
}

public sealed class ManifestPropertyBinding
{
    public ManifestPropertyBinding(string targetPath, string property, string fieldId, string converter = "", string format = "", object? fallback = null)
    {
        TargetPath = targetPath;
        Property = property;
        FieldId = fieldId;
        Converter = converter;
        Format = format;
        Fallback = fallback;
    }

    public string TargetPath { get; }
    public string Property { get; }
    public string FieldId { get; }
    public string Converter { get; }
    public string Format { get; }
    public object? Fallback { get; }
}

public sealed class ManifestItemBinding
{
    public ManifestItemBinding(string targetPath, string property, string fieldId, string converter = "", string format = "", object? fallback = null)
    {
        TargetPath = targetPath;
        Property = property;
        FieldId = fieldId;
        Converter = converter;
        Format = format;
        Fallback = fallback;
    }

    public string TargetPath { get; }
    public string Property { get; }
    public string FieldId { get; }
    public string Converter { get; }
    public string Format { get; }
    public object? Fallback { get; }
}

public sealed class ManifestRepeaterBinding
{
    public ManifestRepeaterBinding(
        string targetPath,
        string templatePath,
        string fieldId,
        IEnumerable<ManifestItemBinding> itemBindings,
        string keyFieldId = "",
        int poolCapacity = 32)
    {
        TargetPath = targetPath;
        TemplatePath = templatePath;
        FieldId = fieldId;
        ItemBindings = new List<ManifestItemBinding>(itemBindings);
        KeyFieldId = keyFieldId;
        PoolCapacity = Math.Max(0, poolCapacity);
    }

    public string TargetPath { get; }
    public string TemplatePath { get; }
    public string FieldId { get; }
    public IReadOnlyList<ManifestItemBinding> ItemBindings { get; }
    public string KeyFieldId { get; }
    public int PoolCapacity { get; }
}

public sealed class ManifestLocalizedPropertyBinding
{
    public ManifestLocalizedPropertyBinding(
        string targetPath,
        string property,
        string key,
        string context = "",
        IEnumerable<string>? argumentFieldIds = null)
    {
        TargetPath = targetPath;
        Property = property;
        Key = key;
        Context = context;
        ArgumentFieldIds = new List<string>(argumentFieldIds ?? Array.Empty<string>());
    }

    public string TargetPath { get; }
    public string Property { get; }
    public string Key { get; }
    public string Context { get; }
    public IReadOnlyList<string> ArgumentFieldIds { get; }
}

public sealed class ManifestInputBinding
{
    public ManifestInputBinding(string targetPath, string property, string fieldId)
    {
        TargetPath = targetPath;
        Property = property;
        FieldId = fieldId;
    }

    public string TargetPath { get; }
    public string Property { get; }
    public string FieldId { get; }
}

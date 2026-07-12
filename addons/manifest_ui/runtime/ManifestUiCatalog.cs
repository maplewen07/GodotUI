using System;
using System.Collections.Generic;
using Godot;

namespace GodotUi.Manifest;

public sealed class ManifestUiCatalog
{
    private readonly Dictionary<string, ManifestUiCatalogEntry> _entries = new(StringComparer.Ordinal);

    public IReadOnlyCollection<ManifestUiCatalogEntry> Entries => _entries.Values;

    public void Register(ManifestUiCatalogEntry entry, bool replace = false)
    {
        ArgumentNullException.ThrowIfNull(entry);
        var packageId = entry.PackageId.ToString();
        if (!replace && _entries.ContainsKey(packageId))
        {
            throw new InvalidOperationException($"Manifest UI package '{packageId}' is already registered.");
        }

        _entries[packageId] = entry;
    }

    public bool Unregister(StringName packageId)
    {
        return _entries.Remove(packageId.ToString());
    }

    public bool TryGet(StringName packageId, out ManifestUiCatalogEntry entry)
    {
        return _entries.TryGetValue(packageId.ToString(), out entry!);
    }

    public ManifestUiCatalogEntry GetRequired(StringName packageId)
    {
        if (TryGet(packageId, out var entry))
        {
            return entry;
        }

        throw new KeyNotFoundException($"Manifest UI package '{packageId}' is not present in the catalog.");
    }
}

public sealed class ManifestUiCatalogEntry
{
    public ManifestUiCatalogEntry(
        string packageId,
        string scenePath,
        Func<ManifestControllerBase>? controllerFactory = null,
        ManifestControllerScope controllerScope = ManifestControllerScope.Package,
        string translationDomain = "",
        IReadOnlyList<string>? translationPaths = null,
        IReadOnlyList<ManifestUiRoute>? routes = null)
    {
        if (string.IsNullOrWhiteSpace(packageId))
        {
            throw new ArgumentException("Package id is required.", nameof(packageId));
        }

        if (string.IsNullOrWhiteSpace(scenePath))
        {
            throw new ArgumentException("Scene path is required.", nameof(scenePath));
        }

        PackageId = packageId;
        ScenePath = scenePath;
        ControllerFactory = controllerFactory;
        ControllerScope = controllerScope;
        TranslationDomain = translationDomain;
        TranslationPaths = translationPaths ?? Array.Empty<string>();
        Routes = routes ?? Array.Empty<ManifestUiRoute>();
    }

    public StringName PackageId { get; }
    public string ScenePath { get; }
    public Func<ManifestControllerBase>? ControllerFactory { get; }
    public ManifestControllerScope ControllerScope { get; }
    public string TranslationDomain { get; }
    public IReadOnlyList<string> TranslationPaths { get; }
    public IReadOnlyList<ManifestUiRoute> Routes { get; }
}

public sealed class ManifestUiRoute
{
    public ManifestUiRoute(string channel, string action, string packageId = "")
    {
        if (string.IsNullOrWhiteSpace(channel))
        {
            throw new ArgumentException("Route channel is required.", nameof(channel));
        }
        if (action is not ("open" or "close"))
        {
            throw new ArgumentException("Route action must be open or close.", nameof(action));
        }
        if (action == "open" && string.IsNullOrWhiteSpace(packageId))
        {
            throw new ArgumentException("Open routes require a target package id.", nameof(packageId));
        }

        Channel = channel;
        Action = action;
        PackageId = packageId;
    }

    public StringName Channel { get; }
    public string Action { get; }
    public StringName PackageId { get; }
}

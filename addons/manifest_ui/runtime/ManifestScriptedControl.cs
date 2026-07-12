using System;
using System.Collections.Generic;
using Godot;

namespace GodotUi.Manifest;

public abstract partial class ManifestScriptedControl : Control
{
    public virtual void ApplyManifestProperties(IReadOnlyDictionary<string, Variant> properties)
    {
    }
}

public static class ManifestScriptedControlRegistry
{
    private static readonly Dictionary<string, Func<ManifestScriptedControl>> Factories = new(StringComparer.Ordinal);

    public static void Register(string typeId, Func<ManifestScriptedControl> factory, bool replace = false)
    {
        if (string.IsNullOrWhiteSpace(typeId))
        {
            throw new ArgumentException("Scripted control type id is required.", nameof(typeId));
        }

        ArgumentNullException.ThrowIfNull(factory);
        if (!replace && Factories.ContainsKey(typeId))
        {
            throw new InvalidOperationException($"Scripted control '{typeId}' is already registered.");
        }

        Factories[typeId] = factory;
    }

    public static bool Unregister(string typeId)
    {
        return Factories.Remove(typeId);
    }

    public static ManifestScriptedControl Create(
        string typeId,
        IReadOnlyDictionary<string, Variant>? properties = null)
    {
        if (!Factories.TryGetValue(typeId, out var factory))
        {
            throw new KeyNotFoundException($"Scripted control '{typeId}' is not registered.");
        }

        var control = factory();
        if (properties is not null)
        {
            control.ApplyManifestProperties(properties);
        }

        return control;
    }
}

using System;
using System.Collections.Generic;
using System.Globalization;
using Godot;

namespace GodotUi.Manifest;

public static class ManifestBindingConverters
{
    private static readonly Dictionary<string, Func<object?, object?>> Converters = new(StringComparer.Ordinal)
    {
        ["string"] = value => value?.ToString() ?? string.Empty,
        ["bool"] = value => ToBool(value),
        ["number"] = value => ToDouble(value),
        ["not"] = value => !ToBool(value),
        ["isNotEmpty"] = value => !string.IsNullOrEmpty(value?.ToString()),
        ["texture"] = ToTexture,
    };

    public static void Register(string id, Func<object?, object?> converter)
    {
        if (string.IsNullOrWhiteSpace(id))
        {
            throw new ArgumentException("Converter id is required.", nameof(id));
        }

        Converters[id] = converter ?? throw new ArgumentNullException(nameof(converter));
    }

    public static void Unregister(string id)
    {
        Converters.Remove(id);
    }

    public static bool Contains(string id)
    {
        return string.IsNullOrWhiteSpace(id) || Converters.ContainsKey(id);
    }

    public static object? Convert(string id, object? value)
    {
        return string.IsNullOrWhiteSpace(id) ? value : Converters[id](value);
    }

    internal static bool ToBool(object? value)
    {
        return value switch
        {
            null => false,
            bool b => b,
            int i => i != 0,
            long l => l != 0,
            float f => Math.Abs(f) > float.Epsilon,
            double d => Math.Abs(d) > double.Epsilon,
            string s when bool.TryParse(s, out var parsed) => parsed,
            string s when double.TryParse(s, NumberStyles.Float, CultureInfo.InvariantCulture, out var parsed) => Math.Abs(parsed) > double.Epsilon,
            string s => !string.IsNullOrEmpty(s),
            _ => true,
        };
    }

    internal static double ToDouble(object? value)
    {
        return value switch
        {
            null => 0.0,
            double d => d,
            float f => f,
            int i => i,
            long l => l,
            decimal m => (double)m,
            string s when double.TryParse(s, NumberStyles.Float, CultureInfo.InvariantCulture, out var parsed) => parsed,
            _ => 0.0,
        };
    }

    private static object? ToTexture(object? value)
    {
        if (value is Texture2D texture)
        {
            return texture;
        }

        var path = value?.ToString() ?? string.Empty;
        return path.StartsWith("res://", StringComparison.Ordinal) ? ResourceLoader.Load<Texture2D>(path) : null;
    }
}

using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using Godot;

namespace GodotUi.Manifest;

public static class ManifestBindingApplier
{
    private static readonly ConditionalWeakTable<Control, Dictionary<string, RepeaterState>> RepeaterStates = new();

    public static void Apply(Control root, ViewModelStore store, ManifestBindingSet bindings)
    {
        ApplyCore(root, store, bindings, store.IsDirty);
    }

    internal static void Apply(
        Control root,
        ViewModelStore store,
        ManifestBindingSet bindings,
        ViewModelStoreCursor cursor,
        long targetRevision)
    {
        ApplyCore(root, store, bindings, fieldId => cursor.ShouldApply(store, fieldId, targetRevision));
    }

    private static void ApplyCore(
        Control root,
        ViewModelStore store,
        ManifestBindingSet bindings,
        Func<string, bool> shouldApply)
    {
        foreach (var binding in bindings.Properties)
        {
            if (!shouldApply(binding.FieldId))
            {
                continue;
            }

            var value = store.TryGet(binding.FieldId, out var stored) ? stored : binding.Fallback;
            if (value is string text && !text.StartsWith("res://", StringComparison.Ordinal) && bindings.Assets.TryGetPath(text, out var assetPath))
            {
                value = assetPath;
            }

            value = ManifestBindingConverters.Convert(ResolveConverter(binding), value);
            if (!string.IsNullOrEmpty(binding.Format))
            {
                value = string.Format(CultureInfo.InvariantCulture, binding.Format, value);
            }

            ApplyValue(root.GetNode<Control>(binding.TargetPath), NormalizeProperty(binding.Property), value);
        }

        ApplyLocalizations(root, store, bindings, shouldApply);
        ApplyRepeaters(root, store, bindings, shouldApply);
    }

    private static void ApplyLocalizations(
        Control root,
        ViewModelStore store,
        ManifestBindingSet bindings,
        Func<string, bool> shouldApply)
    {
        foreach (var binding in bindings.Localizations)
        {
            if (binding.ArgumentFieldIds.Count > 0 && !binding.ArgumentFieldIds.Any(shouldApply))
            {
                continue;
            }

            var translated = root.Tr(binding.Key, binding.Context);
            object? value = translated;
            if (binding.ArgumentFieldIds.Count > 0)
            {
                var arguments = binding.ArgumentFieldIds.Select(store.Get).ToArray();
                try
                {
                    value = string.Format(CultureInfo.CurrentCulture, translated, arguments);
                }
                catch (FormatException exception)
                {
                    ManifestRuntimeDiagnostics.Report(
                        "MUIR4001",
                        ManifestRuntimeDiagnosticSeverity.Warning,
                        $"Localized string '{binding.Key}' has an invalid format.",
                        exception);
                }
            }

            ApplyValue(root.GetNode<Control>(binding.TargetPath), NormalizeProperty(binding.Property), value);
        }
    }

    private static string ResolveConverter(ManifestPropertyBinding binding)
    {
        if (!string.IsNullOrWhiteSpace(binding.Converter))
        {
            return binding.Converter;
        }

        return ResolveDefaultConverter(binding.Property);
    }

    private static string ResolveConverter(ManifestItemBinding binding)
    {
        if (!string.IsNullOrWhiteSpace(binding.Converter))
        {
            return binding.Converter;
        }

        return ResolveDefaultConverter(binding.Property);
    }

    private static string ResolveDefaultConverter(string property)
    {
        return NormalizeProperty(property) switch
        {
            "text" => "string",
            "visible" => "bool",
            "enabled" => "bool",
            "value" => "number",
            "texture" => "texture",
            "themeClass" => "string",
            _ => "",
        };
    }

    private static void ApplyRepeaters(
        Control root,
        ViewModelStore store,
        ManifestBindingSet bindings,
        Func<string, bool> shouldApply)
    {
        foreach (var repeater in bindings.Repeaters)
        {
            if (!shouldApply(repeater.FieldId))
            {
                continue;
            }

            var container = root.GetNode<Control>(repeater.TargetPath);
            var template = root.GetNode<Control>(repeater.TemplatePath);
            template.Visible = false;

            var stateKey = $"{repeater.TargetPath}\n{repeater.TemplatePath}\n{repeater.FieldId}";
            var rootStates = RepeaterStates.GetOrCreateValue(root);
            if (!rootStates.TryGetValue(stateKey, out var state))
            {
                state = new RepeaterState();
                rootStates[stateKey] = state;
            }

            var items = store.TryGet(repeater.FieldId, out var collection)
                ? EnumerateItems(collection).ToArray()
                : Array.Empty<object?>();
            var nextActive = new Dictionary<string, Control>(StringComparer.Ordinal);
            var keyCounts = new Dictionary<string, int>(StringComparer.Ordinal);
            var insertionIndex = template.GetParent() == container ? template.GetIndex() + 1 : container.GetChildCount();

            for (var index = 0; index < items.Length; index++)
            {
                var item = items[index];
                var baseKey = ResolveItemKey(item, repeater.KeyFieldId, index);
                var key = baseKey;
                if (keyCounts.TryGetValue(baseKey, out var duplicateIndex))
                {
                    do
                    {
                        duplicateIndex++;
                        key = $"{baseKey}#{duplicateIndex}";
                    }
                    while (nextActive.ContainsKey(key));

                    keyCounts[baseKey] = duplicateIndex;
                }
                else
                {
                    keyCounts[baseKey] = 0;
                    while (nextActive.ContainsKey(key))
                    {
                        duplicateIndex++;
                        key = $"{baseKey}#{duplicateIndex}";
                    }
                }

                if (!state.Active.Remove(key, out var control) || !GodotObject.IsInstanceValid(control))
                {
                    control = TakeFromPool(state) ?? (Control)template.Duplicate();
                }

                control.Name = $"{template.Name}_{index}";
                control.Visible = true;
                control.SetMeta("manifest_repeater", repeater.TemplatePath);
                control.SetMeta("manifest_repeater_key", key);
                if (control.GetParent() != container)
                {
                    container.AddChild(control);
                }

                container.MoveChild(control, Math.Min(insertionIndex + index, container.GetChildCount() - 1));
                ApplyItem(control, item, repeater, bindings);
                nextActive[key] = control;
            }

            foreach (var removed in state.Active.Values)
            {
                if (!GodotObject.IsInstanceValid(removed))
                {
                    continue;
                }

                removed.Visible = false;
                removed.RemoveMeta("manifest_repeater");
                removed.RemoveMeta("manifest_repeater_key");
                state.Pool.Push(removed);
            }

            state.Active = nextActive;
            TrimPool(state, repeater.PoolCapacity);
        }
    }

    private static Control? TakeFromPool(RepeaterState state)
    {
        while (state.Pool.Count > 0)
        {
            var control = state.Pool.Pop();
            if (GodotObject.IsInstanceValid(control))
            {
                return control;
            }
        }

        return null;
    }

    private static void TrimPool(RepeaterState state, int capacity)
    {
        while (state.Pool.Count > capacity)
        {
            var control = state.Pool.Pop();
            if (GodotObject.IsInstanceValid(control))
            {
                control.GetParent()?.RemoveChild(control);
                control.Free();
            }
        }
    }

    private static string ResolveItemKey(object? item, string keyFieldId, int index)
    {
        var effectiveKeyField = string.IsNullOrWhiteSpace(keyFieldId) ? "id" : keyFieldId;
        if (TryGetItemValue(item, effectiveKeyField, out var value) && value is not null)
        {
            return Convert.ToString(value, CultureInfo.InvariantCulture) ?? index.ToString(CultureInfo.InvariantCulture);
        }

        return index.ToString(CultureInfo.InvariantCulture);
    }

    private static IEnumerable<object?> EnumerateItems(object? value)
    {
        if (value is null or string)
        {
            yield break;
        }

        if (value is IEnumerable enumerable)
        {
            foreach (var item in enumerable)
            {
                yield return item;
            }
        }
    }

    private static void ApplyItem(Control clone, object? item, ManifestRepeaterBinding repeater, ManifestBindingSet bindings)
    {
        foreach (var binding in repeater.ItemBindings)
        {
            var value = TryGetItemValue(item, binding.FieldId, out var found) ? found : binding.Fallback;
            if (value is string text && !text.StartsWith("res://", StringComparison.Ordinal) && bindings.Assets.TryGetPath(text, out var assetPath))
            {
                value = assetPath;
            }

            value = ManifestBindingConverters.Convert(ResolveConverter(binding), value);
            if (!string.IsNullOrEmpty(binding.Format))
            {
                value = string.Format(CultureInfo.InvariantCulture, binding.Format, value);
            }

            var target = string.IsNullOrWhiteSpace(binding.TargetPath) || binding.TargetPath == "."
                ? clone
                : clone.GetNode<Control>(binding.TargetPath);
            ApplyValue(target, NormalizeProperty(binding.Property), value);
        }
    }

    private static bool TryGetItemValue(object? item, string fieldId, out object? value)
    {
        switch (item)
        {
            case null:
                value = null;
                return false;
            case IReadOnlyDictionary<string, object?> readOnly when readOnly.TryGetValue(fieldId, out value):
                return true;
            case IDictionary<string, object?> dictionary when dictionary.TryGetValue(fieldId, out value):
                return true;
            case IDictionary dictionary when dictionary.Contains(fieldId):
                value = dictionary[fieldId];
                return true;
        }

        var property = item.GetType().GetProperty(fieldId, BindingFlags.Instance | BindingFlags.Public | BindingFlags.IgnoreCase);
        value = property?.GetValue(item);
        return property is not null;
    }

    private static void ApplyValue(Control target, string property, object? value)
    {
        switch (property)
        {
            case "text":
                if (!ApplyText(target, value?.ToString() ?? string.Empty))
                {
                    ApplyGodotProperty(target, property, new[] { "text", "Text" }, value?.ToString() ?? string.Empty);
                }
                return;
            case "visible":
                target.Visible = ManifestBindingConverters.ToBool(value);
                return;
            case "enabled":
                if (!ApplyEnabled(target, ManifestBindingConverters.ToBool(value)))
                {
                    ApplyEnabledGodotProperty(target, ManifestBindingConverters.ToBool(value));
                }
                return;
            case "value":
                if (target is Godot.Range range)
                {
                    range.Value = ManifestBindingConverters.ToDouble(value);
                }
                else
                {
                    ApplyGodotProperty(target, property, new[] { "value", "Value" }, value);
                }
                return;
            case "texture":
                if (value is not null && value is not Texture2D)
                {
                    ReportBindingFailure(target, property, $"value type '{value.GetType().FullName}' is incompatible with a texture binding");
                    return;
                }
                if (!ApplyTexture(target, value as Texture2D))
                {
                    ApplyGodotProperty(target, property, new[] { "texture", "Texture" }, value);
                }
                return;
            case "themeClass":
                target.ThemeTypeVariation = value?.ToString() ?? string.Empty;
                return;
        }
    }

    private static bool ApplyText(Control target, string text)
    {
        switch (target)
        {
            case Label label:
                label.Text = text;
                return true;
            case Button button:
                button.Text = text;
                return true;
            case LineEdit lineEdit:
                lineEdit.Text = text;
                return true;
            case RichTextLabel richTextLabel:
                richTextLabel.Text = text;
                return true;
            default:
                return false;
        }
    }

    private static bool ApplyEnabled(Control target, bool enabled)
    {
        switch (target)
        {
            case BaseButton button:
                button.Disabled = !enabled;
                return true;
            case LineEdit lineEdit:
                lineEdit.Editable = enabled;
                return true;
            case TextEdit textEdit:
                textEdit.Editable = enabled;
                return true;
            default:
                return false;
        }
    }

    private static bool ApplyTexture(Control target, Texture2D? texture)
    {
        switch (target)
        {
            case TextureRect textureRect:
                textureRect.Texture = texture;
                return true;
            case TextureButton textureButton:
                textureButton.TextureNormal = texture;
                return true;
            case Button button:
                button.Icon = texture;
                return true;
            default:
                return false;
        }
    }

    private static void ApplyEnabledGodotProperty(Control target, bool enabled)
    {
        if (TryGetGodotProperty(target, new[] { "enabled", "Enabled" }, out var enabledProperty))
        {
            ApplyGodotProperty(target, "enabled", enabledProperty, enabled);
            return;
        }

        if (TryGetGodotProperty(target, new[] { "disabled", "Disabled" }, out var disabledProperty))
        {
            ApplyGodotProperty(target, "enabled", disabledProperty, !enabled);
            return;
        }

        ReportBindingFailure(target, "enabled", "the scripted control exposes neither an 'enabled' nor a 'disabled' Godot property");
    }

    private static void ApplyGodotProperty(
        Control target,
        string manifestProperty,
        IReadOnlyList<string> godotProperties,
        object? value)
    {
        if (!TryGetGodotProperty(target, godotProperties, out var property))
        {
            var names = string.Join("' or '", godotProperties);
            ReportBindingFailure(target, manifestProperty, $"Godot property '{names}' was not found");
            return;
        }

        ApplyGodotProperty(target, manifestProperty, property, value);
    }

    private static void ApplyGodotProperty(Control target, string manifestProperty, GodotProperty property, object? value)
    {
        if ((property.Usage & PropertyUsageFlags.ReadOnly) != 0)
        {
            ReportBindingFailure(target, manifestProperty, $"Godot property '{property.Name}' is read-only");
            return;
        }

        if (!TryConvertGodotValue(value, property, out var converted, out var reason))
        {
            ReportBindingFailure(target, manifestProperty, reason);
            return;
        }

        try
        {
            target.Set(new StringName(property.Name), converted);
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR4003",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Binding property '{manifestProperty}' could not be written to node '{DescribeNode(target)}' via Godot property '{property.Name}'.",
                exception);
        }
    }

    private static bool TryGetGodotProperty(Control target, string name, out GodotProperty property)
    {
        foreach (var entry in target.GetPropertyList())
        {
            if (!entry.TryGetValue("name", out var nameValue) ||
                !string.Equals(nameValue.AsString(), name, StringComparison.Ordinal))
            {
                continue;
            }

            var type = entry.TryGetValue("type", out var typeValue)
                ? (Variant.Type)typeValue.AsInt64()
                : Variant.Type.Nil;
            var className = entry.TryGetValue("class_name", out var classValue)
                ? classValue.AsString()
                : string.Empty;
            var usage = entry.TryGetValue("usage", out var usageValue)
                ? (PropertyUsageFlags)usageValue.AsInt64()
                : PropertyUsageFlags.Default;
            property = new GodotProperty(name, type, className, usage);
            return true;
        }

        property = default;
        return false;
    }

    private static bool TryGetGodotProperty(
        Control target,
        IReadOnlyList<string> names,
        out GodotProperty property)
    {
        foreach (var name in names)
        {
            if (TryGetGodotProperty(target, name, out property))
            {
                return true;
            }
        }

        property = default;
        return false;
    }

    private static bool TryConvertGodotValue(
        object? value,
        GodotProperty property,
        out Variant converted,
        out string reason)
    {
        try
        {
            switch (property.Type)
            {
                case Variant.Type.Nil:
                    converted = ManifestVariantConversion.FromObject(value);
                    reason = string.Empty;
                    return true;
                case Variant.Type.Bool:
                    converted = ManifestBindingConverters.ToBool(value);
                    reason = string.Empty;
                    return true;
                case Variant.Type.Int:
                    if (TryConvertInt64(value, out var integer))
                    {
                        converted = integer;
                        reason = string.Empty;
                        return true;
                    }
                    break;
                case Variant.Type.Float:
                    if (TryConvertDouble(value, out var number))
                    {
                        converted = number;
                        reason = string.Empty;
                        return true;
                    }
                    break;
                case Variant.Type.String:
                    converted = value?.ToString() ?? string.Empty;
                    reason = string.Empty;
                    return true;
                case Variant.Type.StringName:
                    converted = new StringName(value?.ToString() ?? string.Empty);
                    reason = string.Empty;
                    return true;
                case Variant.Type.NodePath:
                    converted = new NodePath(value?.ToString() ?? string.Empty);
                    reason = string.Empty;
                    return true;
                case Variant.Type.Object:
                    if (value is null)
                    {
                        converted = default;
                        reason = string.Empty;
                        return true;
                    }
                    if (value is GodotObject godotObject &&
                        (string.IsNullOrWhiteSpace(property.ClassName) || godotObject.IsClass(property.ClassName)))
                    {
                        converted = godotObject;
                        reason = string.Empty;
                        return true;
                    }
                    break;
                default:
                    var variant = ManifestVariantConversion.FromObject(value);
                    if (variant.VariantType == property.Type)
                    {
                        converted = variant;
                        reason = string.Empty;
                        return true;
                    }
                    break;
            }
        }
        catch (Exception exception)
        {
            converted = default;
            reason = $"value conversion for Godot property '{property.Name}' failed: {exception.Message}";
            return false;
        }

        converted = default;
        var sourceType = value?.GetType().FullName ?? "null";
        var expectedType = string.IsNullOrWhiteSpace(property.ClassName)
            ? property.Type.ToString()
            : $"{property.Type} ({property.ClassName})";
        reason = $"value type '{sourceType}' is incompatible with Godot property '{property.Name}' of type '{expectedType}'";
        return false;
    }

    private static bool TryConvertInt64(object? value, out long converted)
    {
        switch (value)
        {
            case byte typed:
                converted = typed;
                return true;
            case sbyte typed:
                converted = typed;
                return true;
            case short typed:
                converted = typed;
                return true;
            case ushort typed:
                converted = typed;
                return true;
            case int typed:
                converted = typed;
                return true;
            case uint typed:
                converted = typed;
                return true;
            case long typed:
                converted = typed;
                return true;
            case ulong typed when typed <= long.MaxValue:
                converted = (long)typed;
                return true;
            case float typed when float.IsFinite(typed) && typed >= long.MinValue && typed <= long.MaxValue:
                converted = Convert.ToInt64(typed, CultureInfo.InvariantCulture);
                return true;
            case double typed when double.IsFinite(typed) && typed >= long.MinValue && typed <= long.MaxValue:
                converted = Convert.ToInt64(typed, CultureInfo.InvariantCulture);
                return true;
            case decimal typed when typed >= long.MinValue && typed <= long.MaxValue:
                converted = Convert.ToInt64(typed, CultureInfo.InvariantCulture);
                return true;
            case string text when long.TryParse(text, NumberStyles.Integer, CultureInfo.InvariantCulture, out var parsed):
                converted = parsed;
                return true;
            default:
                converted = default;
                return false;
        }
    }

    private static bool TryConvertDouble(object? value, out double converted)
    {
        switch (value)
        {
            case byte or sbyte or short or ushort or int or uint or long or ulong or float or double or decimal:
                converted = Convert.ToDouble(value, CultureInfo.InvariantCulture);
                return true;
            case string text when double.TryParse(text, NumberStyles.Float, CultureInfo.InvariantCulture, out var parsed):
                converted = parsed;
                return true;
            default:
                converted = default;
                return false;
        }
    }

    private static void ReportBindingFailure(Control target, string manifestProperty, string reason)
    {
        ManifestRuntimeDiagnostics.Report(
            "MUIR4003",
            ManifestRuntimeDiagnosticSeverity.Error,
            $"Binding property '{manifestProperty}' cannot be applied to node '{DescribeNode(target)}': {reason}.");
    }

    private static string DescribeNode(Control target)
    {
        var path = target.IsInsideTree() ? target.GetPath().ToString() : target.Name.ToString();
        return $"{path} ({target.GetClass()})";
    }

    private static string NormalizeProperty(string property)
    {
        return string.Equals(property, "visibility", StringComparison.Ordinal) ? "visible" : property;
    }

    private sealed class RepeaterState
    {
        public Dictionary<string, Control> Active { get; set; } = new(StringComparer.Ordinal);
        public Stack<Control> Pool { get; } = new();
    }

    private readonly record struct GodotProperty(
        string Name,
        Variant.Type Type,
        string ClassName,
        PropertyUsageFlags Usage);
}

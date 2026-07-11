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
                ApplyText(target, value?.ToString() ?? string.Empty);
                return;
            case "visible":
                target.Visible = ManifestBindingConverters.ToBool(value);
                return;
            case "enabled":
                ApplyEnabled(target, ManifestBindingConverters.ToBool(value));
                return;
            case "value":
                if (target is Godot.Range range)
                {
                    range.Value = ManifestBindingConverters.ToDouble(value);
                }
                return;
            case "texture":
                ApplyTexture(target, value as Texture2D);
                return;
            case "themeClass":
                target.ThemeTypeVariation = value?.ToString() ?? string.Empty;
                return;
        }
    }

    private static void ApplyText(Control target, string text)
    {
        switch (target)
        {
            case Label label:
                label.Text = text;
                break;
            case Button button:
                button.Text = text;
                break;
            case LineEdit lineEdit:
                lineEdit.Text = text;
                break;
            case RichTextLabel richTextLabel:
                richTextLabel.Text = text;
                break;
        }
    }

    private static void ApplyEnabled(Control target, bool enabled)
    {
        switch (target)
        {
            case BaseButton button:
                button.Disabled = !enabled;
                break;
            case LineEdit lineEdit:
                lineEdit.Editable = enabled;
                break;
            case TextEdit textEdit:
                textEdit.Editable = enabled;
                break;
        }
    }

    private static void ApplyTexture(Control target, Texture2D? texture)
    {
        switch (target)
        {
            case TextureRect textureRect:
                textureRect.Texture = texture;
                break;
            case TextureButton textureButton:
                textureButton.TextureNormal = texture;
                break;
            case Button button:
                button.Icon = texture;
                break;
        }
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
}

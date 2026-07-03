using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Reflection;
using Godot;

namespace GodotUi.Manifest;

public static class ManifestBindingApplier
{
    public static void Apply(Control root, ViewModelStore store, ManifestBindingSet bindings)
    {
        foreach (var binding in bindings.Properties)
        {
            if (!store.IsDirty(binding.FieldId))
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

        ApplyRepeaters(root, store, bindings);
    }

    private static string ResolveConverter(ManifestPropertyBinding binding)
    {
        if (!string.IsNullOrWhiteSpace(binding.Converter))
        {
            return binding.Converter;
        }

        return NormalizeProperty(binding.Property) switch
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

    private static string ResolveConverter(ManifestItemBinding binding)
    {
        if (!string.IsNullOrWhiteSpace(binding.Converter))
        {
            return binding.Converter;
        }

        return NormalizeProperty(binding.Property) switch
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

    private static void ApplyRepeaters(Control root, ViewModelStore store, ManifestBindingSet bindings)
    {
        foreach (var repeater in bindings.Repeaters)
        {
            if (!store.IsDirty(repeater.FieldId))
            {
                continue;
            }

            var container = root.GetNode<Control>(repeater.TargetPath);
            var template = root.GetNode<Control>(repeater.TemplatePath);
            template.Visible = false;

            foreach (var oldItem in container.GetChildren().OfType<Control>().Where(child => child.HasMeta("manifest_repeater")).ToArray())
            {
                container.RemoveChild(oldItem);
                oldItem.Free();
            }

            if (!store.TryGet(repeater.FieldId, out var collection))
            {
                continue;
            }

            var index = 0;
            foreach (var item in EnumerateItems(collection))
            {
                var clone = (Control)template.Duplicate();
                clone.Name = $"{template.Name}_{index++}";
                clone.Visible = true;
                clone.SetMeta("manifest_repeater", repeater.TemplatePath);
                container.AddChild(clone);
                ApplyItem(clone, item, repeater, bindings);
            }
        }
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
}

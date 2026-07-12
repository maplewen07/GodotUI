using GodotUi.Manifest.Tooling;
using Xunit;

namespace ManifestUi.Tooling.Tests;

public sealed class ResourceAssetAndScriptedControlTests
{
    [Fact]
    public void Generate_EmitsDeterministicExtResourcesForEveryAssetReferenceKind()
    {
        using var project = new ManifestTestProject();
        var assetsDirectory = Path.Combine(project.PackageDirectory, "assets");
        File.WriteAllText(Path.Combine(assetsDirectory, "background.svg"), "<svg xmlns=\"http://www.w3.org/2000/svg\"></svg>");
        File.WriteAllText(Path.Combine(assetsDirectory, "font.tres"), "[gd_resource type=\"FontFile\" format=3]\n");
        File.WriteAllText(Path.Combine(assetsDirectory, "theme.json"), "{}\n");
        File.WriteAllText(Path.Combine(assetsDirectory, "style.res"), "resource-bytes\n");
        File.WriteAllText(Path.Combine(project.PackageDirectory, "assets.json"), """
            {
              "assets": [
                { "id": "style", "relativePath": "assets/style.res", "kind": "resource" },
                { "id": "theme", "relativePath": "assets/theme.json", "kind": "theme" },
                { "id": "font", "relativePath": "assets/font.tres", "kind": "font" },
                { "id": "background", "relativePath": "assets/background.svg", "kind": "texture" }
              ]
            }
            """);
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  {
                    "id": "preview", "type": "Control", "name": "Preview",
                    "properties": {
                      "a_texture": { "assetRef": "background" },
                      "b_font": { "assetRef": "font" },
                      "c_resource": { "assetRef": "style" },
                      "d_theme": { "assetRef": "theme" }
                    },
                    "children": []
                  }
                ]
              }
            }
            """);

        var first = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);

        Assert.True(first.Success, Format(first));
        var scenePath = Path.Combine(project.OutputDirectory, "TestWidget.tscn");
        var scene = File.ReadAllText(scenePath);
        Assert.Contains("[gd_scene load_steps=6 format=3]", scene, StringComparison.Ordinal);
        Assert.Contains("[ext_resource type=\"Texture2D\" path=\"res://ui/test/assets/background.svg\" id=\"2_asset\"]", scene, StringComparison.Ordinal);
        Assert.Contains("[ext_resource type=\"Font\" path=\"res://ui/test/assets/font.tres\" id=\"3_asset\"]", scene, StringComparison.Ordinal);
        Assert.Contains("[ext_resource type=\"Resource\" path=\"res://ui/test/assets/style.res\" id=\"4_asset\"]", scene, StringComparison.Ordinal);
        Assert.Contains("[ext_resource type=\"Theme\" path=\"res://generated/ui/test/assets/TestTheme.tres\" id=\"5_asset\"]", scene, StringComparison.Ordinal);
        Assert.Contains("a_texture = ExtResource(\"2_asset\")", scene, StringComparison.Ordinal);
        Assert.Contains("b_font = ExtResource(\"3_asset\")", scene, StringComparison.Ordinal);
        Assert.Contains("c_resource = ExtResource(\"4_asset\")", scene, StringComparison.Ordinal);
        Assert.Contains("d_theme = ExtResource(\"5_asset\")", scene, StringComparison.Ordinal);

        var second = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);
        Assert.True(second.Success, Format(second));
        Assert.Equal(scene, File.ReadAllText(scenePath));
    }

    [Fact]
    public void Validate_RejectsUnknownAndMalformedLayoutAssetReferences()
    {
        using var project = new ManifestTestProject();
        File.WriteAllText(Path.Combine(project.PackageDirectory, "assets", "style.tres"), "[gd_resource format=3]\n");
        File.WriteAllText(Path.Combine(project.PackageDirectory, "assets.json"), """
            { "assets": [{ "id": "style", "relativePath": "assets/style.tres", "kind": "resource" }] }
            """);
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root",
                "properties": {
                  "missing": { "assetRef": "does_not_exist" },
                  "wrong_type": { "assetRef": 42 },
                  "extra_field": { "assetRef": "style", "unexpected": true }
                },
                "children": []
              }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/root/properties/missing" && diagnostic.Message.Contains("unknown asset reference", StringComparison.Ordinal));
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/root/properties/wrong_type" && diagnostic.Message.Contains("object property values", StringComparison.Ordinal));
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/root/properties/extra_field" && diagnostic.Message.Contains("object property values", StringComparison.Ordinal));
    }

    [Fact]
    public void Validate_RejectsInvalidResourceExtensionsAndPathsOutsideAssets()
    {
        using var project = new ManifestTestProject();
        File.WriteAllText(Path.Combine(project.PackageDirectory, "assets", "style.json"), "{}\n");
        File.WriteAllText(Path.Combine(project.PackageDirectory, "assets.json"), """
            {
              "assets": [
                { "id": "wrong_extension", "relativePath": "assets/style.json", "kind": "resource" },
                { "id": "outside", "relativePath": "../outside.tres", "kind": "resource" }
              ]
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/assets/0/kind" && diagnostic.Message.Contains("not compatible", StringComparison.Ordinal));
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/assets/1/relativePath" && diagnostic.Message.Contains("must stay inside", StringComparison.Ordinal));
    }

    [Fact]
    public void ScriptedControl_AllowsCanonicalBindingsInputsAndCustomZeroArgumentEvents()
    {
        using var project = new ManifestTestProject();
        Directory.CreateDirectory(Path.Combine(project.Root, "scripts"));
        File.WriteAllText(Path.Combine(project.Root, "scripts", "CustomControl.cs"), "// Engine Verify owns the script contract.\n");
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  {
                    "id": "custom", "type": "Control", "name": "Custom",
                    "scriptPath": "res://scripts/CustomControl.cs",
                    "properties": {}, "children": []
                  }
                ]
              }
            }
            """);
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [
                { "id": "label", "path": "UI.Label", "value": "text" },
                { "id": "active", "path": "UI.Active", "value": "bool" },
                { "id": "amount", "path": "UI.Amount", "value": "number" }
              ] },
              "bindings": {
                "Custom.text": "viewmodel:label",
                "Custom.enabled": "viewmodel:active",
                "Custom.value": "viewmodel:amount"
              },
              "repeaters": [],
              "inputs": [
                { "id": "amountInput", "target": "Custom", "property": "value", "source": "viewmodel:amount" }
              ],
              "controls": [
                {
                  "id": "custom", "target": "Custom", "widgetClass": "CustomControl",
                  "events": [
                    { "event": "pressed", "handler": "apply", "channel": "ui.apply" },
                    { "event": "custom_triggered", "handler": "custom", "channel": "ui.custom" }
                  ]
                }
              ],
              "events": { "channels": [
                { "id": "ui.apply", "scope": "ui.test", "dispatch": "immediate" },
                { "id": "ui.custom", "scope": "ui.test", "dispatch": "immediate" }
              ] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);

        Assert.True(result.Success, Format(result));
        var code = File.ReadAllText(Path.Combine(project.OutputDirectory, "TestWidget.g.cs"));
        Assert.Contains("private Control _custom", code, StringComparison.Ordinal);
        Assert.Contains("Connect(new StringName(\"ValueChanged\"), new Callable(this, nameof(OnInput0AmountChanged)))", code, StringComparison.Ordinal);
        Assert.Contains("private void OnInput0AmountChanged(double value)", code, StringComparison.Ordinal);
        Assert.Contains("Connect(new StringName(\"Pressed\"), new Callable(this, nameof(OnApplyPressed)))", code, StringComparison.Ordinal);
        Assert.Contains("Connect(new StringName(\"CustomTriggered\"), new Callable(this, nameof(OnCustomCustomTriggered)))", code, StringComparison.Ordinal);
        Assert.Contains("private void OnCustomCustomTriggered()", code, StringComparison.Ordinal);
    }

    [Fact]
    public void GdScriptedControl_KeepsGodotSignalNames()
    {
        using var project = new ManifestTestProject();
        Directory.CreateDirectory(Path.Combine(project.Root, "scripts"));
        File.WriteAllText(Path.Combine(project.Root, "scripts", "custom_control.gd"), "extends Control\nsignal pressed\nsignal value_changed(value)\n");
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  {
                    "id": "custom", "type": "Control", "name": "Custom",
                    "scriptPath": "res://scripts/custom_control.gd",
                    "properties": {}, "children": []
                  }
                ]
              }
            }
            """);
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [
                { "id": "amount", "path": "UI.Amount", "value": "number" }
              ] },
              "bindings": {}, "repeaters": [],
              "inputs": [
                { "id": "amountInput", "target": "Custom", "property": "value", "source": "viewmodel:amount" }
              ],
              "controls": [
                {
                  "id": "custom", "target": "Custom",
                  "events": [{ "event": "pressed", "handler": "apply", "channel": "ui.apply" }]
                }
              ],
              "events": { "channels": [
                { "id": "ui.apply", "scope": "ui.test", "dispatch": "immediate" }
              ] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);

        Assert.True(result.Success, Format(result));
        var code = File.ReadAllText(Path.Combine(project.OutputDirectory, "TestWidget.g.cs"));
        Assert.Contains("Connect(new StringName(\"value_changed\")", code, StringComparison.Ordinal);
        Assert.Contains("Connect(new StringName(\"pressed\")", code, StringComparison.Ordinal);
    }

    [Fact]
    public void BuiltInControl_KeepsStrictPropertyInputEventAndWidgetClassValidation()
    {
        using var project = new ManifestTestProject();
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  { "id": "plain", "type": "Control", "name": "Plain", "properties": {}, "children": [] }
                ]
              }
            }
            """);
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [
                { "id": "label", "path": "UI.Label", "value": "text" },
                { "id": "amount", "path": "UI.Amount", "value": "number" }
              ] },
              "bindings": { "Plain.text": "viewmodel:label" },
              "repeaters": [],
              "inputs": [
                { "id": "amountInput", "target": "Plain", "property": "value", "source": "viewmodel:amount" }
              ],
              "controls": [
                {
                  "id": "plain", "target": "Plain", "widgetClass": "CustomControl",
                  "events": [{ "event": "custom_triggered", "handler": "custom", "channel": "ui.custom" }]
                }
              ],
              "events": { "channels": [
                { "id": "ui.custom", "scope": "ui.test", "dispatch": "immediate" }
              ] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/bindings/Plain/text" && diagnostic.Message.Contains("not supported on Control", StringComparison.Ordinal));
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/inputs/0/property" && diagnostic.Message.Contains("not supported on Control", StringComparison.Ordinal));
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/controls/0/widgetClass" && diagnostic.Message.Contains("must match", StringComparison.Ordinal));
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/controls/0/events/0/event" && diagnostic.Message.Contains("not supported on Control", StringComparison.Ordinal));
    }

    private static string Format(ManifestUiToolResult result)
    {
        return string.Join(Environment.NewLine, result.Diagnostics.Select(diagnostic => $"{diagnostic.Code} {diagnostic.File}{diagnostic.JsonPointer}: {diagnostic.Message}"));
    }
}

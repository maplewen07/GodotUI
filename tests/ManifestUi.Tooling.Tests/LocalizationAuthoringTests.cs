using System.Text.Json.Nodes;
using GodotUi.Manifest.Tooling;
using Xunit;

namespace ManifestUi.Tooling.Tests;

public sealed class LocalizationAuthoringTests
{
    [Fact]
    public void Generate_EmitsParameterizedLocalizationContextAndArguments()
    {
        using var project = new ManifestTestProject();
        AddStringsManifest(project);
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [
                { "id": "itemCount", "path": "UI.Inventory.ItemCount", "value": "number" }
              ] },
              "bindings": {}, "repeaters": [], "inputs": [], "controls": [], "events": { "channels": [] }
            }
            """);
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  {
                    "id": "count", "type": "Label", "name": "Count", "properties": {},
                    "localization": {
                      "text": { "key": "inventory.count", "context": "inventory", "arguments": ["itemCount"] }
                    },
                    "children": []
                  }
                ]
              }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);

        Assert.True(result.Success, Format(result));
        var generated = File.ReadAllText(Path.Combine(project.OutputDirectory, "TestWidget.g.cs"));
        Assert.Contains(
            "new ManifestLocalizedPropertyBinding(\"Count\", \"text\", \"inventory.count\", \"inventory\", new string[] { \"itemCount\" })",
            generated,
            StringComparison.Ordinal);
        var scene = File.ReadAllText(Path.Combine(project.OutputDirectory, "TestWidget.tscn"));
        Assert.Contains("text = \"inventory.count\"", scene, StringComparison.Ordinal);
    }

    [Fact]
    public void Validate_RejectsUnknownLocalizationArgumentField()
    {
        using var project = new ManifestTestProject();
        AddStringsManifest(project);
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  {
                    "id": "count", "type": "Label", "name": "Count", "properties": {},
                    "localization": {
                      "text": { "key": "inventory.count", "arguments": ["missing"] }
                    },
                    "children": []
                  }
                ]
              }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic =>
            diagnostic.File == "layout.json" &&
            diagnostic.JsonPointer.EndsWith("/localization/text/arguments/0", StringComparison.Ordinal) &&
            diagnostic.Message.Contains("unknown mvvm field 'missing'", StringComparison.Ordinal));
    }

    private static void AddStringsManifest(ManifestTestProject project)
    {
        var package = JsonNode.Parse(File.ReadAllText(project.PackagePath))!.AsObject();
        package["strings"] = "strings.json";
        File.WriteAllText(project.PackagePath, package.ToJsonString());
        File.WriteAllText(Path.Combine(project.PackageDirectory, "strings.json"), """
            {
              "schemaVersion": 1,
              "defaultLocale": "en",
              "locales": ["en"],
              "strings": { "inventory.count": { "en": "{0} items" } }
            }
            """);
        var validationPath = Path.Combine(project.PackageDirectory, "validation.json");
        var validation = JsonNode.Parse(File.ReadAllText(validationPath))!.AsObject();
        validation["commandletInputWhitelist"]!.AsArray().Add("strings.json");
        File.WriteAllText(validationPath, validation.ToJsonString());
    }

    private static string Format(ManifestUiToolResult result)
    {
        return string.Join(Environment.NewLine, result.Diagnostics.Select(diagnostic =>
            $"{diagnostic.Code} {diagnostic.File}{diagnostic.JsonPointer}: {diagnostic.Message}"));
    }
}

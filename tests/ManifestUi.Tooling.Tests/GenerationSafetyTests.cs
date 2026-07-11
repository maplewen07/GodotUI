using System.Text;
using System.Text.Json.Nodes;
using GodotUi.Manifest.Tooling;
using Xunit;

namespace ManifestUi.Tooling.Tests;

public sealed class GenerationSafetyTests
{
    [Fact]
    public void Generate_CleanDeletesStaleIndexedFileButPreservesUserFiles()
    {
        using var project = new ManifestTestProject();
        project.WriteCodegen("""
            {
              "schemaVersion": 1,
              "generator": "ManifestUi",
              "requiredServices": [
                { "type": "Tests.IClock", "property": "Clock" }
              ]
            }
            """);
        var first = ManifestUiTool.Execute(new[] { "generate", project.PackagePath, "--clean" }, project.Root);
        Assert.True(first.Success, Format(first));

        var staleManaged = Path.Combine(project.OutputDirectory, "TestWidget.Services.g.cs");
        var userFile = Path.Combine(project.OutputDirectory, "author-notes.txt");
        Assert.True(File.Exists(staleManaged));
        File.WriteAllText(userFile, "keep\n");

        project.WriteCodegen();
        var second = ManifestUiTool.Execute(new[] { "generate", project.PackagePath, "--clean" }, project.Root);

        Assert.True(second.Success, Format(second));
        Assert.False(File.Exists(staleManaged));
        Assert.Equal("keep\n", File.ReadAllText(userFile));
        Assert.True(File.Exists(Path.Combine(project.OutputDirectory, "TestWidget.cs")));
        using var index = project.ReadIndex();
        var managed = index.RootElement.GetProperty("managedFiles")
            .EnumerateArray()
            .Select(item => item.GetProperty("path").GetString())
            .ToArray();
        Assert.DoesNotContain("TestWidget.Services.g.cs", managed);
        Assert.DoesNotContain("author-notes.txt", managed);
    }

    [Fact]
    public void Generate_CleanRejectsTraversalInManagedIndexWithoutDeletingTarget()
    {
        using var project = new ManifestTestProject();
        var generated = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);
        Assert.True(generated.Success, Format(generated));
        var before = project.SnapshotManagedFiles();

        var outsideTarget = Path.GetFullPath(Path.Combine(project.OutputDirectory, "..", "outside.txt"));
        File.WriteAllText(outsideTarget, "must survive\n");
        var indexPath = Path.Combine(project.OutputDirectory, ".manifest-ui.generated.json");
        var index = JsonNode.Parse(File.ReadAllText(indexPath))!.AsObject();
        index["managedFiles"]!.AsArray().Add(new JsonObject
        {
            ["path"] = "../outside.txt",
            ["kind"] = "code",
            ["contentHash"] = "sha256:0000000000000000000000000000000000000000000000000000000000000000",
        });
        File.WriteAllText(indexPath, index.ToJsonString());

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath, "--clean" }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic =>
            diagnostic.Code.StartsWith("MUI3", StringComparison.Ordinal) &&
            diagnostic.Message.Contains("outside outputDir", StringComparison.Ordinal));
        Assert.Equal("must survive\n", File.ReadAllText(outsideTarget));
        AssertManagedFilesUnchanged(before, project.SnapshotManagedFiles(), ignoreIndex: true);
    }

    [Fact]
    public void Generate_InvalidManifestDoesNotPartiallyCommit()
    {
        using var project = new ManifestTestProject();
        var generated = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);
        Assert.True(generated.Success, Format(generated));
        var before = project.SnapshotManagedFiles();

        project.WriteLayout("""
            {
              "root": {
                "id": "root",
                "type": "Control",
                "name": "Root",
                "properties": {},
                "children": [
                  { "id": "duplicate", "type": "Label", "name": "First", "properties": {}, "children": [] },
                  { "id": "duplicate", "type": "Label", "name": "Second", "properties": {}, "children": [] }
                ]
              }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.Message.Contains("duplicate node id", StringComparison.Ordinal));
        AssertManagedFilesUnchanged(before, project.SnapshotManagedFiles());
        Assert.Empty(Directory.EnumerateFiles(project.OutputDirectory, "*.tmp", SearchOption.AllDirectories));
    }

    [Fact]
    public void Generate_ManagedOutputIsUtf8WithoutBomLfOnlyAndStableSorted()
    {
        using var project = new ManifestTestProject();
        var first = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);
        Assert.True(first.Success, Format(first));
        var firstSnapshot = project.SnapshotManagedFiles();

        foreach (var (path, bytes) in firstSnapshot)
        {
            Assert.False(bytes.AsSpan().StartsWith(new byte[] { 0xef, 0xbb, 0xbf }), $"{path} contains a UTF-8 BOM.");
            Assert.DoesNotContain('\r', Encoding.UTF8.GetString(bytes));
            Assert.EndsWith("\n", Encoding.UTF8.GetString(bytes), StringComparison.Ordinal);
        }

        using (var index = project.ReadIndex())
        {
            var paths = index.RootElement.GetProperty("managedFiles")
                .EnumerateArray()
                .Select(item => item.GetProperty("path").GetString()!)
                .ToArray();
            Assert.Equal(paths.OrderBy(path => path, StringComparer.Ordinal), paths);
        }

        var second = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);
        Assert.True(second.Success, Format(second));
        AssertManagedFilesUnchanged(firstSnapshot, project.SnapshotManagedFiles());
    }

    [Fact]
    public void Validate_RejectsDuplicateGeneratedServiceProperties()
    {
        using var project = new ManifestTestProject();
        project.WriteCodegen("""
            {
              "schemaVersion": 1,
              "generator": "ManifestUi",
              "requiredServices": [
                { "type": "Tests.IClock", "property": "Clock" },
                { "type": "Tests.IMetrics", "property": "Clock" }
              ]
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic =>
            diagnostic.JsonPointer == "/requiredServices/1/property" &&
            diagnostic.Message.Contains("duplicate generated property", StringComparison.Ordinal));
    }

    [Theory]
    [InlineData("immediate", "Immediate")]
    [InlineData("deferred", "Deferred")]
    public void Generate_EmitsDeclaredUpdatePolicy(string manifestValue, string enumMember)
    {
        using var project = new ManifestTestProject();
        project.WriteBindings($$"""
            {
              "mvvm": { "updatePolicy": "{{manifestValue}}", "fields": [] },
              "bindings": {},
              "repeaters": [],
              "inputs": [],
              "controls": [],
              "events": { "channels": [] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);

        Assert.True(result.Success, Format(result));
        var generated = File.ReadAllText(Path.Combine(project.OutputDirectory, "TestWidget.g.cs"));
        Assert.Contains($"ManifestUiUpdatePolicy.{enumMember}", generated, StringComparison.Ordinal);
    }

    [Fact]
    public void Generate_EmitsRepeaterKeyAndPoolCapacity()
    {
        using var project = new ManifestTestProject();
        project.WriteLayout("""
            {
              "root": {
                "id": "root",
                "type": "Control",
                "name": "Root",
                "properties": {},
                "children": [
                  {
                    "id": "items",
                    "type": "VBoxContainer",
                    "name": "Items",
                    "properties": {},
                    "children": [
                      {
                        "id": "template",
                        "type": "HBoxContainer",
                        "name": "Template",
                        "properties": {},
                        "children": [
                          { "id": "text", "type": "Label", "name": "Text", "properties": {}, "children": [] }
                        ]
                      }
                    ]
                  }
                ]
              }
            }
            """);
        project.WriteBindings("""
            {
              "mvvm": {
                "updatePolicy": "deferred",
                "fields": [
                  { "id": "items", "path": "UI.Test.Items", "value": "object", "collection": "list" }
                ]
              },
              "bindings": {},
              "repeaters": [
                {
                  "id": "itemsRepeater",
                  "target": "Items",
                  "template": "Items/Template",
                  "source": "viewmodel:items",
                  "keyFieldId": "id",
                  "poolCapacity": 7,
                  "bindings": { "Text.text": "item:name" }
                }
              ],
              "inputs": [],
              "controls": [],
              "events": { "channels": [] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);

        Assert.True(result.Success, Format(result));
        var generated = File.ReadAllText(Path.Combine(project.OutputDirectory, "TestWidget.g.cs"));
        Assert.Contains("\"id\", 7)", generated, StringComparison.Ordinal);
        Assert.Contains("ManifestUiUpdatePolicy.Deferred", generated, StringComparison.Ordinal);
    }

    [Fact]
    public void Validate_RejectsWidgetClassThatCannotBeGeneratedAsCSharp()
    {
        using var project = new ManifestTestProject(widgetClass: "Bad-Widget");

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/godot/widgetClass");
    }

    private static void AssertManagedFilesUnchanged(
        IReadOnlyDictionary<string, byte[]> expected,
        IReadOnlyDictionary<string, byte[]> actual,
        bool ignoreIndex = false)
    {
        var paths = expected.Keys
            .Union(actual.Keys, StringComparer.Ordinal)
            .Where(path => !ignoreIndex || path != ".manifest-ui.generated.json")
            .OrderBy(path => path, StringComparer.Ordinal)
            .ToArray();
        foreach (var path in paths)
        {
            Assert.True(expected.TryGetValue(path, out var expectedBytes), $"Unexpected managed file: {path}");
            Assert.True(actual.TryGetValue(path, out var actualBytes), $"Missing managed file: {path}");
            Assert.Equal(expectedBytes, actualBytes);
        }
    }

    private static string Format(ManifestUiToolResult result)
    {
        return string.Join(Environment.NewLine, result.Diagnostics.Select(diagnostic =>
            $"{diagnostic.Code} {diagnostic.File}{diagnostic.JsonPointer}: {diagnostic.Message}"));
    }
}

using System.Text.Json;
using GodotUi.Manifest.Tooling;
using Xunit;

namespace ManifestUi.Tooling.Tests;

public sealed class ManifestUiToolTests : IDisposable
{
    private readonly string _root = Path.Combine(Path.GetTempPath(), "manifest-ui-tests", Guid.NewGuid().ToString("N"));

    [Fact]
    public void Validate_ReturnsStructuredSourceLocation()
    {
        var package = CreateProject(designResolution: "[0, 720]");

        var result = ManifestUiTool.Execute(new[] { "validate", package }, _root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        var diagnostic = Assert.Single(result.Diagnostics, item => item.JsonPointer == "/designResolution");
        Assert.StartsWith("MUI", diagnostic.Code);
        Assert.True(diagnostic.Line > 0);
        Assert.True(diagnostic.Column > 0);
    }

    [Fact]
    public void Generate_IsDeterministicAndPreservesUserStub()
    {
        var package = CreateProject();

        var first = ManifestUiTool.Execute(new[] { "generate", package, "--clean" }, _root);
        Assert.True(first.Success, Format(first));

        var output = Path.Combine(_root, "generated", "ui", "test");
        var stub = Path.Combine(output, "TestWidget.cs");
        File.AppendAllText(stub, "// user edit\n");
        var expectedStub = File.ReadAllText(stub);
        var firstManaged = ReadManaged(output);

        var second = ManifestUiTool.Execute(new[] { "generate", package, "--clean" }, _root);
        Assert.True(second.Success, Format(second));
        Assert.Equal(expectedStub, File.ReadAllText(stub));
        Assert.Equal(firstManaged, ReadManaged(output));

        using var index = JsonDocument.Parse(File.ReadAllText(Path.Combine(output, ".manifest-ui.generated.json")));
        var managedPaths = index.RootElement.GetProperty("managedFiles").EnumerateArray().Select(item => item.GetProperty("path").GetString()).ToArray();
        Assert.DoesNotContain("TestWidget.cs", managedPaths);
        Assert.Contains("TestWidget.g.cs", managedPaths);
        Assert.Contains("TestWidget.Catalog.g.cs", managedPaths);
        Assert.Contains("TestWidget.tscn", managedPaths);
        Assert.Contains("[Tool]", File.ReadAllText(Path.Combine(output, "TestWidget.g.cs")), StringComparison.Ordinal);

        var check = ManifestUiTool.Execute(new[] { "generate", package, "--check" }, _root);
        Assert.True(check.Success, Format(check));
    }

    [Fact]
    public void Generate_UsesNamedInputHandlersAndKeepsEditorSignalConnections()
    {
        var package = CreateProject();
        var packageDirectory = Path.GetDirectoryName(package)!;
        File.WriteAllText(Path.Combine(packageDirectory, "layout.json"), """
            { "root": { "id": "root", "type": "Control", "name": "Root", "properties": {}, "children": [
              { "id": "search", "type": "LineEdit", "name": "Search", "properties": {}, "children": [] }
            ] } }
            """);
        File.WriteAllText(Path.Combine(packageDirectory, "bindings.json"), """
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [
                { "id": "searchText", "path": "UI.SearchText", "value": "text", "collection": "none" }
              ] },
              "bindings": {}, "repeaters": [],
              "inputs": [{ "id": "searchInput", "target": "Search", "property": "text", "source": "viewmodel:searchText" }],
              "controls": [], "events": { "channels": [] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", package }, _root);

        Assert.True(result.Success, Format(result));
        var code = File.ReadAllText(Path.Combine(_root, "generated", "ui", "test", "TestWidget.g.cs"));
        Assert.DoesNotContain("if (IsEditorPreview)", code, StringComparison.Ordinal);
        Assert.Contains("Connect(new StringName(\"text_changed\"), new Callable(this, nameof(OnInput0SearchTextChanged)))", code, StringComparison.Ordinal);
        Assert.Contains("Disconnect(new StringName(\"text_changed\"), new Callable(this, nameof(OnInput0SearchTextChanged)))", code, StringComparison.Ordinal);
        Assert.DoesNotContain("TextChanged +=", code, StringComparison.Ordinal);
        Assert.DoesNotContain("TextChanged += value =>", code, StringComparison.Ordinal);
    }

    [Fact]
    public void Generate_RejectsOutputOutsideProject()
    {
        var package = CreateProject(outputDir: "../escape");

        var result = ManifestUiTool.Execute(new[] { "generate", package }, _root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/godot/outputDir" && diagnostic.Severity == ManifestDiagnosticSeverity.Error);
        Assert.False(Directory.Exists(Path.Combine(Path.GetDirectoryName(_root)!, "escape")));
    }

    [Fact]
    public void AssetsHashCheck_IsExplicitWhileNormalValidationAllowsMissingHash()
    {
        var package = CreateProject(includeAsset: true);

        var validation = ManifestUiTool.Execute(new[] { "validate", package }, _root);
        Assert.True(validation.Success, Format(validation));

        var hashCheck = ManifestUiTool.Execute(new[] { "assets", "hash", "--check", package }, _root);
        Assert.Equal(ManifestUiTool.ValidationFailure, hashCheck.ExitCode);
        Assert.Contains(hashCheck.Diagnostics, diagnostic => diagnostic.JsonPointer.EndsWith("/contentHash", StringComparison.Ordinal));

        var write = ManifestUiTool.Execute(new[] { "assets", "hash", "--write", package }, _root);
        Assert.True(write.Success, Format(write));
        var finalCheck = ManifestUiTool.Execute(new[] { "assets", "hash", "--check", package }, _root);
        Assert.True(finalCheck.Success, Format(finalCheck));
    }

    [Fact]
    public void Generate_EmitsControllerServiceAccessorsAndRouteMetadata()
    {
        var package = CreateProject();
        var packageDirectory = Path.GetDirectoryName(package)!;
        File.WriteAllText(Path.Combine(packageDirectory, "codegen.json"), """
            {
              "schemaVersion": 1,
              "generator": "ManifestUi",
              "requiredServices": [{ "type": "Tests.IClock", "property": "Clock", "key": "ui" }],
              "routes": [{ "channel": "ui.open", "action": "open", "packageId": "ui.details" }]
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", package }, _root);

        Assert.True(result.Success, Format(result));
        var output = Path.Combine(_root, "generated", "ui", "test");
        var services = File.ReadAllText(Path.Combine(output, "TestWidget.Services.g.cs"));
        Assert.Contains("namespace Tests;", services);
        Assert.Contains("Context.RequireService<global::Tests.IClock>(\"ui\")", services);
        var catalog = File.ReadAllText(Path.Combine(output, "TestWidget.Catalog.g.cs"));
        Assert.Contains("new global::GodotUi.Manifest.ManifestUiRoute(\"ui.open\", \"open\", \"ui.details\")", catalog);
        Assert.Contains("CreateRoutes", catalog);
        Assert.Contains("(\"ui.open\", \"open\", \"ui.details\")", catalog);
    }

    private string CreateProject(string designResolution = "[1280, 720]", string outputDir = "generated/ui/test", bool includeAsset = false)
    {
        Directory.CreateDirectory(_root);
        File.WriteAllText(Path.Combine(_root, "project.godot"), "[application]\nconfig/name=\"Tooling Test\"\n");
        var packageDirectory = Path.Combine(_root, "ui", "test");
        Directory.CreateDirectory(packageDirectory);
        Directory.CreateDirectory(Path.Combine(packageDirectory, "assets"));

        File.WriteAllText(Path.Combine(packageDirectory, "package.json"), $$"""
            {
              "schemaVersion": 1,
              "packageId": "ui.test",
              "displayName": "Test",
              "designResolution": {{designResolution}},
              "assets": "assets.json",
              "layout": "layout.json",
              "bindings": "bindings.json",
              "codegen": "codegen.json",
              "validation": "validation.json",
              "godot": {
                "systemName": "test",
                "widgetClass": "TestWidget",
                "controllerClass": "Tests.TestController",
                "namespace": "Tests.Generated",
                "outputDir": "{{outputDir.Replace("\\", "/")}}",
                "scenePath": "res://{{outputDir.Replace("\\", "/")}}/TestWidget.tscn"
              }
            }
            """);
        File.WriteAllText(Path.Combine(packageDirectory, "layout.json"), """
            { "root": { "id": "root", "type": "Control", "name": "Root", "properties": {}, "children": [] } }
            """);
        File.WriteAllText(Path.Combine(packageDirectory, "bindings.json"), """
            { "mvvm": { "updatePolicy": "immediate", "fields": [] }, "bindings": {}, "repeaters": [], "inputs": [], "controls": [], "events": { "channels": [] } }
            """);
        File.WriteAllText(Path.Combine(packageDirectory, "codegen.json"), "{ \"schemaVersion\": 1, \"generator\": \"ManifestUi\" }");
        File.WriteAllText(Path.Combine(packageDirectory, "validation.json"), """
            { "commandletInputWhitelist": ["assets.json", "layout.json", "bindings.json", "codegen.json", "validation.json"], "checks": {} }
            """);

        if (includeAsset)
        {
            File.WriteAllText(Path.Combine(packageDirectory, "assets", "icon.svg"), "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"1\" height=\"1\"></svg>");
            File.WriteAllText(Path.Combine(packageDirectory, "assets.json"), """
                { "assets": [{ "id": "icon", "relativePath": "assets/icon.svg", "kind": "texture" }] }
                """);
        }
        else
        {
            File.WriteAllText(Path.Combine(packageDirectory, "assets.json"), "{ \"assets\": [] }");
        }

        return Path.Combine(packageDirectory, "package.json");
    }

    private static string ReadManaged(string output)
    {
        return string.Join("\n---\n", new[] { "TestWidget.tscn", "TestWidget.g.cs", "TestWidget.Catalog.g.cs", ".manifest-ui.generated.json" }.Select(file => File.ReadAllText(Path.Combine(output, file))));
    }

    private static string Format(ManifestUiToolResult result)
    {
        return string.Join(Environment.NewLine, result.Diagnostics.Select(diagnostic => $"{diagnostic.Code} {diagnostic.File}{diagnostic.JsonPointer}: {diagnostic.Message}"));
    }

    public void Dispose()
    {
        if (Directory.Exists(_root))
        {
            Directory.Delete(_root, recursive: true);
        }
    }
}

using System.Text.Json;

namespace ManifestUi.Tooling.Tests;

internal sealed class ManifestTestProject : IDisposable
{
    private readonly string _temporaryRoot = Path.Combine(
        Path.GetTempPath(),
        "manifest-ui-contract-tests",
        Guid.NewGuid().ToString("N"));

    public ManifestTestProject(string widgetClass = "TestWidget", string outputDir = "generated/ui/test")
    {
        Root = _temporaryRoot;
        PackageDirectory = Path.Combine(Root, "ui", "test");
        PackagePath = Path.Combine(PackageDirectory, "package.json");
        OutputDirectory = Path.GetFullPath(outputDir.Replace('/', Path.DirectorySeparatorChar), Root);

        Directory.CreateDirectory(Path.Combine(PackageDirectory, "assets"));
        File.WriteAllText(Path.Combine(Root, "project.godot"), "[application]\nconfig/name=\"Tooling Contract Test\"\n");
        WritePackage(widgetClass, outputDir);
        WriteLayout();
        WriteBindings();
        WriteCodegen();
        File.WriteAllText(Path.Combine(PackageDirectory, "assets.json"), "{ \"assets\": [] }\n");
        File.WriteAllText(Path.Combine(PackageDirectory, "validation.json"), """
            {
              "commandletInputWhitelist": [
                "assets.json",
                "layout.json",
                "bindings.json",
                "codegen.json",
                "validation.json"
              ],
              "checks": {}
            }
            """);
    }

    public string Root { get; }
    public string PackageDirectory { get; }
    public string PackagePath { get; }
    public string OutputDirectory { get; }

    public void WritePackage(string widgetClass = "TestWidget", string outputDir = "generated/ui/test")
    {
        File.WriteAllText(PackagePath, $$"""
            {
              "schemaVersion": 1,
              "packageId": "ui.test",
              "displayName": "Test",
              "designResolution": [1280, 720],
              "assets": "assets.json",
              "layout": "layout.json",
              "bindings": "bindings.json",
              "codegen": "codegen.json",
              "validation": "validation.json",
              "godot": {
                "systemName": "test",
                "widgetClass": "{{widgetClass}}",
                "controllerClass": "Tests.TestController",
                "namespace": "Tests.Generated",
                "outputDir": "{{outputDir.Replace("\\", "/")}}",
                "scenePath": "res://{{outputDir.Replace("\\", "/")}}/{{widgetClass}}.tscn"
              }
            }
            """);
    }

    public void WriteLayout(string? json = null)
    {
        File.WriteAllText(Path.Combine(PackageDirectory, "layout.json"), json ?? """
            {
              "root": {
                "id": "root",
                "type": "Control",
                "name": "Root",
                "properties": {},
                "children": []
              }
            }
            """);
    }

    public void WriteBindings(string? json = null)
    {
        File.WriteAllText(Path.Combine(PackageDirectory, "bindings.json"), json ?? """
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [] },
              "bindings": {},
              "repeaters": [],
              "inputs": [],
              "controls": [],
              "events": { "channels": [] }
            }
            """);
    }

    public void WriteCodegen(string? json = null)
    {
        File.WriteAllText(Path.Combine(PackageDirectory, "codegen.json"), json ?? """
            { "schemaVersion": 1, "generator": "ManifestUi" }
            """);
    }

    public IReadOnlyDictionary<string, byte[]> SnapshotManagedFiles()
    {
        return Directory.EnumerateFiles(OutputDirectory, "*", SearchOption.AllDirectories)
            .Where(path => Path.GetFileName(path) == ".manifest-ui.generated.json" ||
                path.EndsWith(".g.cs", StringComparison.Ordinal) ||
                path.EndsWith(".tscn", StringComparison.Ordinal) ||
                path.EndsWith(".tres", StringComparison.Ordinal))
            .OrderBy(path => path, StringComparer.Ordinal)
            .ToDictionary(
                path => Path.GetRelativePath(OutputDirectory, path).Replace('\\', '/'),
                File.ReadAllBytes,
                StringComparer.Ordinal);
    }

    public JsonDocument ReadIndex()
    {
        return JsonDocument.Parse(File.ReadAllText(Path.Combine(OutputDirectory, ".manifest-ui.generated.json")));
    }

    public void Dispose()
    {
        if (!Directory.Exists(Root))
        {
            return;
        }

        Directory.Delete(Root, recursive: true);
    }
}

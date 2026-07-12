using System.Diagnostics;
using GodotUi.Manifest.Tooling;
using Xunit;

namespace ManifestUi.Tooling.Tests;

public sealed class ReleaseHardeningTests
{
    [Fact]
    public void Execute_RejectsUnknownMissingOrExtraArguments()
    {
        var invocations = new[]
        {
            new[] { "validate", "package.json", "--wat" },
            new[] { "generate", "package.json", "extra.json" },
            new[] { "check", "package.json" },
            new[] { "doctor", "--project" },
        };
        foreach (var args in invocations)
        {
            var result = ManifestUiTool.Execute(args, RepositoryPaths.Root);

            Assert.Equal(ManifestUiTool.UsageOrEnvironmentFailure, result.ExitCode);
            var diagnostic = Assert.Single(result.Diagnostics);
            Assert.Equal("MUI5001", diagnostic.Code);
        }
    }

    [Fact]
    public void Generate_PreCanceledTokenReturnsStableResultWithoutWritingOutput()
    {
        using var project = new ManifestTestProject();
        using var cancellation = new CancellationTokenSource();
        cancellation.Cancel();

        var result = ManifestUiTool.Execute(
            new[] { "generate", project.PackagePath },
            project.Root,
            cancellation.Token);

        Assert.Equal(ManifestUiTool.UsageOrEnvironmentFailure, result.ExitCode);
        var diagnostic = Assert.Single(result.Diagnostics);
        Assert.Equal("MUI5004", diagnostic.Code);
        Assert.False(Directory.Exists(project.OutputDirectory));
    }

    [Fact]
    public void Doctor_ExecutesGodotVersionAndRejectsNonGodotExecutable()
    {
        using var project = new ManifestTestProject();
        File.WriteAllText(Path.Combine(project.Root, "Doctor.csproj"), """
            <Project Sdk="Godot.NET.Sdk/4.7.0">
              <PropertyGroup><TargetFramework>net8.0</TargetFramework></PropertyGroup>
            </Project>
            """);
        var dotnet = FindDotnetHost();

        var result = ManifestUiTool.Execute(
            new[] { "doctor", "--project", project.Root, "--godot", dotnet },
            project.Root);

        Assert.Equal(ManifestUiTool.UsageOrEnvironmentFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic =>
            diagnostic.Code == "MUI5003" &&
            diagnostic.JsonPointer == "/godotVersion" &&
            diagnostic.Message.Contains("Godot 4.7 Mono", StringComparison.Ordinal));
    }

    [Fact]
    public void CheckRelease_ContinuesWithLaterPackagesAfterValidationFailure()
    {
        using var project = new ManifestTestProject();
        var secondPackage = Path.Combine(project.Root, "ui", "z-valid");
        CopyDirectory(project.PackageDirectory, secondPackage);
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  { "id": "duplicate", "type": "Label", "name": "One", "properties": {}, "children": [] },
                  { "id": "duplicate", "type": "Label", "name": "Two", "properties": {}, "children": [] }
                ]
              }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "check", "--project", project.Root, "--release" }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.Message.Contains("duplicate node id", StringComparison.Ordinal));
        Assert.Contains(result.Diagnostics, diagnostic =>
            diagnostic.Code.StartsWith("MUI3", StringComparison.Ordinal) &&
            diagnostic.Message.Contains("generated file is missing", StringComparison.Ordinal));
    }

    [Fact]
    public void Validate_RejectsGeneratedNodeFieldCollision()
    {
        using var project = new ManifestTestProject();
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  { "id": "left", "type": "VBoxContainer", "name": "Left", "properties": {}, "children": [
                    { "id": "leftTitle", "type": "Label", "name": "Title", "properties": {}, "children": [] }
                  ] },
                  { "id": "right", "type": "VBoxContainer", "name": "Right", "properties": {}, "children": [
                    { "id": "rightTitle", "type": "Label", "name": "Title", "properties": {}, "children": [] }
                  ] }
                ]
              }
            }
            """);
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [
                { "id": "left", "path": "UI.Left", "value": "text" },
                { "id": "right", "path": "UI.Right", "value": "text" }
              ] },
              "bindings": {
                "Left/Title.text": "viewmodel:left",
                "Right/Title.text": "viewmodel:right"
              },
              "repeaters": [], "inputs": [], "controls": [], "events": { "channels": [] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic =>
            diagnostic.Code == "MUI2201" &&
            diagnostic.Message.Contains("generated node field '_title' collides", StringComparison.Ordinal));
    }

    [Fact]
    public void Validate_RejectsGeneratedHandlerCollision()
    {
        using var project = new ManifestTestProject();
        project.WriteLayout("""
            {
              "root": {
                "id": "root", "type": "Control", "name": "Root", "properties": {},
                "children": [
                  { "id": "save", "type": "Button", "name": "Save", "properties": {}, "children": [] },
                  { "id": "saveAs", "type": "Button", "name": "SaveAs", "properties": {}, "children": [] }
                ]
              }
            }
            """);
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [] },
              "bindings": {}, "repeaters": [], "inputs": [],
              "controls": [
                { "id": "save", "target": "Save", "widgetClass": "Button", "events": [
                  { "event": "pressed", "handler": "save-item", "channel": "ui.save" }
                ] },
                { "id": "saveAs", "target": "SaveAs", "widgetClass": "Button", "events": [
                  { "event": "pressed", "handler": "save_item", "channel": "ui.save" }
                ] }
              ],
              "events": { "channels": [
                { "id": "ui.save", "scope": "ui.test", "dispatch": "immediate", "payload": [] }
              ] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic =>
            diagnostic.Code == "MUI2201" &&
            diagnostic.Message.Contains("generated event handler 'OnSaveItemPressed' collides", StringComparison.Ordinal));
    }

    [Fact]
    public void Generate_UsesChannelScopeDispatchAndEmptyPayload()
    {
        using var project = new ManifestTestProject();
        project.WriteLayout("""
            { "root": { "id": "root", "type": "Control", "name": "Root", "properties": {}, "children": [
              { "id": "refresh", "type": "Button", "name": "Refresh", "properties": {}, "children": [] }
            ] } }
            """);
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [] },
              "bindings": {}, "repeaters": [], "inputs": [],
              "controls": [
                { "id": "refresh", "target": "Refresh", "widgetClass": "Button", "events": [
                  { "event": "pressed", "handler": "refresh", "channel": "ui.refresh" }
                ] }
              ],
              "events": { "channels": [
                { "id": "ui.refresh", "scope": "inventory", "dispatch": "deferred", "payload": [] }
              ] }
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath }, project.Root);

        Assert.True(result.Success, Format(result));
        var generated = File.ReadAllText(Path.Combine(project.OutputDirectory, "TestWidget.g.cs"));
        Assert.Contains("DispatchUiEvent(\"refresh\", \"\")", generated, StringComparison.Ordinal);
        Assert.Contains("\"inventory\"", generated, StringComparison.Ordinal);
        Assert.Contains("ManifestMessageDelivery.Deferred", generated, StringComparison.Ordinal);
        Assert.Contains("            default,", generated, StringComparison.Ordinal);
    }

    [Fact]
    public void Validate_RejectsReadButUnsupportedDeclarations()
    {
        using var project = new ManifestTestProject();
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "immediate", "fields": [
                { "id": "value", "path": "UI.Value", "value": "text", "controllerOnlySideEffect": true }
              ] },
              "bindings": {}, "repeaters": [], "inputs": [], "controls": [],
              "events": { "channels": [
                { "id": "ui.event", "scope": "ui.test", "dispatch": "immediate", "payload": ["value"] }
              ] }
            }
            """);
        File.WriteAllText(Path.Combine(project.PackageDirectory, "validation.json"), """
            {
              "commandletInputWhitelist": ["assets.json", "layout.json", "bindings.json", "codegen.json", "validation.json"],
              "checks": { "layoutBudget": 100 }
            }
            """);
        File.WriteAllText(Path.Combine(project.PackageDirectory, "assets", "icon.svg"), "<svg xmlns=\"http://www.w3.org/2000/svg\"></svg>");
        File.WriteAllText(Path.Combine(project.PackageDirectory, "assets.json"), """
            {
              "assets": [
                { "id": "icon", "relativePath": "assets/icon.svg", "kind": "texture", "import": { "filter": false } }
              ]
            }
            """);

        var result = ManifestUiTool.Execute(new[] { "validate", project.PackagePath }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/mvvm/fields/0/controllerOnlySideEffect");
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/events/channels/0/payload");
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/checks/layoutBudget");
        Assert.Contains(result.Diagnostics, diagnostic => diagnostic.JsonPointer == "/assets/0/import/filter");
    }

    [Fact]
    public void Generate_RollsBackManagedWritesAndCleanDeletesWhenCommitFails()
    {
        using var project = new ManifestTestProject();
        project.WriteCodegen("""
            {
              "schemaVersion": 1,
              "generator": "ManifestUi",
              "requiredServices": [{ "type": "Tests.IClock", "property": "Clock" }]
            }
            """);
        var first = ManifestUiTool.Execute(new[] { "generate", project.PackagePath, "--clean" }, project.Root);
        Assert.True(first.Success, Format(first));

        var generatedCodePath = Path.Combine(project.OutputDirectory, "TestWidget.g.cs");
        var servicePath = Path.Combine(project.OutputDirectory, "TestWidget.Services.g.cs");
        var indexPath = Path.Combine(project.OutputDirectory, ".manifest-ui.generated.json");
        var generatedCodeBefore = File.ReadAllBytes(generatedCodePath);
        var serviceBefore = File.ReadAllBytes(servicePath);
        var indexBefore = File.ReadAllBytes(indexPath);

        project.WriteCodegen();
        project.WriteBindings("""
            {
              "mvvm": { "updatePolicy": "deferred", "fields": [] },
              "bindings": {}, "repeaters": [], "inputs": [], "controls": [], "events": { "channels": [] }
            }
            """);
        var scenePath = Path.Combine(project.OutputDirectory, "TestWidget.tscn");
        File.Delete(scenePath);
        Directory.CreateDirectory(scenePath);

        var result = ManifestUiTool.Execute(new[] { "generate", project.PackagePath, "--clean" }, project.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, result.ExitCode);
        Assert.Contains(result.Diagnostics, diagnostic =>
            diagnostic.Code.StartsWith("MUI3", StringComparison.Ordinal) &&
            diagnostic.Message.Contains("generation commit failed", StringComparison.Ordinal));
        Assert.Equal(generatedCodeBefore, File.ReadAllBytes(generatedCodePath));
        Assert.Equal(serviceBefore, File.ReadAllBytes(servicePath));
        Assert.Equal(indexBefore, File.ReadAllBytes(indexPath));
        Assert.Empty(Directory.EnumerateDirectories(
            Path.GetDirectoryName(project.OutputDirectory)!,
            ".manifest-ui-transaction-*",
            SearchOption.TopDirectoryOnly));
    }

    private static string FindDotnetHost()
    {
        var configured = Environment.GetEnvironmentVariable("DOTNET_HOST_PATH");
        if (!string.IsNullOrWhiteSpace(configured) && File.Exists(configured))
        {
            return configured;
        }

        var locator = OperatingSystem.IsWindows() ? "where.exe" : "which";
        var startInfo = new ProcessStartInfo(locator, "dotnet")
        {
            RedirectStandardOutput = true,
            UseShellExecute = false,
            CreateNoWindow = true,
        };
        using var process = Process.Start(startInfo) ?? throw new InvalidOperationException("Could not locate dotnet.");
        var firstLine = process.StandardOutput.ReadLine();
        process.WaitForExit();
        return string.IsNullOrWhiteSpace(firstLine)
            ? throw new InvalidOperationException("Could not locate dotnet.")
            : firstLine;
    }

    private static void CopyDirectory(string source, string destination)
    {
        Directory.CreateDirectory(destination);
        foreach (var file in Directory.EnumerateFiles(source))
        {
            File.Copy(file, Path.Combine(destination, Path.GetFileName(file)));
        }
        foreach (var directory in Directory.EnumerateDirectories(source))
        {
            CopyDirectory(directory, Path.Combine(destination, Path.GetFileName(directory)));
        }
    }

    private static string Format(ManifestUiToolResult result)
    {
        return string.Join(Environment.NewLine, result.Diagnostics.Select(diagnostic =>
            $"{diagnostic.Code} {diagnostic.File}{diagnostic.JsonPointer}: {diagnostic.Message}"));
    }
}

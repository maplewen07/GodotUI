using System.Text.Json;
using GodotUi.Manifest.Tooling;
using Xunit;

namespace ManifestUi.Tooling.Tests;

public sealed class CliOutputTests
{
    [Fact]
    public void Help_ListsSceneExportCommand()
    {
        var output = new StringWriter();
        var error = new StringWriter();

        var exitCode = ManifestUiTool.Run(new[] { "--help" }, output, error, RepositoryPaths.Root);

        Assert.Equal(ManifestUiTool.Success, exitCode);
        Assert.Contains("manifest-ui export-scene <package>", output.ToString(), StringComparison.Ordinal);
        Assert.Empty(error.ToString());
    }

    [Fact]
    public void Run_JsonFormatEmitsStructuredDiagnosticsToStdout()
    {
        var output = new StringWriter();
        var error = new StringWriter();
        var package = Path.Combine(RepositoryPaths.Root, "tests", "fixtures", "bad_manifest", "package.json");

        var exitCode = ManifestUiTool.Run(
            new[] { "validate", package, "--format", "json" },
            output,
            error,
            RepositoryPaths.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, exitCode);
        Assert.True(string.IsNullOrWhiteSpace(error.ToString()));
        using var document = JsonDocument.Parse(output.ToString());
        Assert.Equal(ManifestUiTool.ValidationFailure, document.RootElement.GetProperty("exitCode").GetInt32());
        Assert.False(document.RootElement.GetProperty("success").GetBoolean());
        var diagnostics = document.RootElement.GetProperty("diagnostics").EnumerateArray().ToArray();
        Assert.Equal(2, diagnostics.Length);
        Assert.All(diagnostics, diagnostic =>
        {
            Assert.Equal("error", diagnostic.GetProperty("severity").GetString());
            Assert.True(diagnostic.GetProperty("line").GetInt64() > 0);
            Assert.True(diagnostic.GetProperty("column").GetInt64() > 0);
            Assert.StartsWith("/", diagnostic.GetProperty("jsonPointer").GetString());
        });
        Assert.All(diagnostics, diagnostic => Assert.Equal("MUI2201", diagnostic.GetProperty("code").GetString()));
    }

    [Fact]
    public void Run_SarifFormatEmitsVersionedPortableLocations()
    {
        var output = new StringWriter();
        var error = new StringWriter();
        var package = Path.Combine(RepositoryPaths.Root, "tests", "fixtures", "bad_manifest", "package.json");

        var exitCode = ManifestUiTool.Run(
            new[] { "validate", package, "--format", "sarif" },
            output,
            error,
            RepositoryPaths.Root);

        Assert.Equal(ManifestUiTool.ValidationFailure, exitCode);
        Assert.True(string.IsNullOrWhiteSpace(error.ToString()));
        using var document = JsonDocument.Parse(output.ToString());
        Assert.Equal("2.1.0", document.RootElement.GetProperty("version").GetString());
        var run = document.RootElement.GetProperty("runs")[0];
        Assert.Equal("Manifest UI", run.GetProperty("tool").GetProperty("driver").GetProperty("name").GetString());
        var results = run.GetProperty("results").EnumerateArray().ToArray();
        Assert.Equal(2, results.Length);
        Assert.All(results, result =>
        {
            Assert.Equal("error", result.GetProperty("level").GetString());
            var location = result.GetProperty("locations")[0].GetProperty("physicalLocation");
            var uri = location.GetProperty("artifactLocation").GetProperty("uri").GetString()
                ?? throw new InvalidOperationException("SARIF artifact URI is missing.");
            Assert.DoesNotContain('\\', uri);
            Assert.True(location.GetProperty("region").GetProperty("startLine").GetInt64() > 0);
            var properties = result.GetProperty("properties");
            Assert.StartsWith("/", properties.GetProperty("jsonPointer").GetString());
            Assert.True(properties.TryGetProperty("hint", out _));
        });
    }

    [Fact]
    public void Run_UnknownFormatUsesUsageExitCodeAndStableIssueCode()
    {
        var output = new StringWriter();
        var error = new StringWriter();

        var exitCode = ManifestUiTool.Run(
            new[] { "validate", "missing.json", "--format", "xml" },
            output,
            error,
            RepositoryPaths.Root);

        Assert.Equal(ManifestUiTool.UsageOrEnvironmentFailure, exitCode);
        Assert.Empty(output.ToString());
        Assert.Contains("MUI5001", error.ToString(), StringComparison.Ordinal);
    }
}

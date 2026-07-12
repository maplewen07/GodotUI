using System.Text.Json;
using GodotUi.Manifest.Tooling;
using Xunit;

namespace ManifestUi.Tooling.Tests;

public sealed class FixtureValidationTests
{
    public static IEnumerable<object[]> FixtureCases()
    {
        var fixturesRoot = Path.Combine(RepositoryPaths.Root, "tests", "fixtures");
        return Directory.EnumerateDirectories(fixturesRoot)
            .OrderBy(path => path, StringComparer.Ordinal)
            .Select(path => new object[] { Path.GetFileName(path) });
    }

    [Theory]
    [MemberData(nameof(FixtureCases))]
    public void Validate_LocksExpectedIssueCodesAndLocations(string fixtureName)
    {
        var fixtureDirectory = Path.Combine(RepositoryPaths.Root, "tests", "fixtures", fixtureName);
        var packagePath = Path.Combine(fixtureDirectory, "package.json");
        var expectedPath = Path.Combine(fixtureDirectory, "expected.json");
        var expected = JsonSerializer.Deserialize<ExpectedFixture>(
            File.ReadAllText(expectedPath),
            new JsonSerializerOptions { PropertyNameCaseInsensitive = true })
            ?? throw new InvalidOperationException($"Could not deserialize {expectedPath}.");

        var result = ManifestUiTool.Execute(
            new[] { "validate", packagePath },
            RepositoryPaths.Root);

        Assert.Equal(expected.ExitCode, result.ExitCode);
        var actualDiagnostics = result.Diagnostics
            .Select(diagnostic => new ExpectedDiagnostic(diagnostic.Code, diagnostic.File, diagnostic.JsonPointer))
            .ToArray();
        Assert.Equal(expected.Diagnostics, actualDiagnostics);
        Assert.All(result.Diagnostics, diagnostic =>
        {
            Assert.Equal(ManifestDiagnosticSeverity.Error, diagnostic.Severity);
            Assert.True(diagnostic.Line > 0, $"{fixtureName}: {diagnostic.Code} is missing a source line.");
            Assert.True(diagnostic.Column > 0, $"{fixtureName}: {diagnostic.Code} is missing a source column.");
            Assert.False(Path.IsPathRooted(diagnostic.File), $"{fixtureName}: diagnostics must use portable relative paths.");
        });
    }

    private sealed record ExpectedFixture(int ExitCode, ExpectedDiagnostic[] Diagnostics);
    private sealed record ExpectedDiagnostic(string Code, string File, string JsonPointer);
}

internal static class RepositoryPaths
{
    private static readonly Lazy<string> RootPath = new(FindRoot);

    public static string Root => RootPath.Value;

    private static string FindRoot()
    {
        for (var directory = new DirectoryInfo(AppContext.BaseDirectory); directory is not null; directory = directory.Parent)
        {
            if (File.Exists(Path.Combine(directory.FullName, "project.godot")) &&
                Directory.Exists(Path.Combine(directory.FullName, "tests", "fixtures")))
            {
                return directory.FullName;
            }
        }

        throw new DirectoryNotFoundException("Could not locate the GodotUI repository root from the test output directory.");
    }
}

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;
using System.Threading;

namespace GodotUi.Manifest.Tooling;

public enum ManifestDiagnosticSeverity
{
    Info,
    Warning,
    Error,
}

public sealed record ManifestDiagnostic(
    string Code,
    ManifestDiagnosticSeverity Severity,
    string File,
    string JsonPointer,
    long Line,
    long Column,
    string Message,
    string Hint = "");

public sealed class ManifestUiToolResult
{
    public int ExitCode { get; init; }
    public IReadOnlyList<ManifestDiagnostic> Diagnostics { get; init; } = Array.Empty<ManifestDiagnostic>();
    public IReadOnlyList<string> Messages { get; init; } = Array.Empty<string>();
    public bool Success => ExitCode == ManifestUiTool.Success;
}

public static class ManifestUiTool
{
    public const int Success = 0;
    public const int ValidationFailure = 1;
    public const int UsageOrEnvironmentFailure = 2;
    public const int InternalFailure = 3;
    public const int CurrentSchemaVersion = 1;
    public const string ToolVersion = "0.1.0-alpha.2";

    private const string GeneratorId = "ManifestUi";
    private const string ManagedIndexFileName = ".manifest-ui.generated.json";
    private static readonly UTF8Encoding Utf8NoBom = new(false);
    private static readonly HashSet<string> CSharpKeywords = new(StringComparer.Ordinal)
    {
        "abstract", "as", "base", "bool", "break", "byte", "case", "catch", "char", "checked", "class", "const",
        "continue", "decimal", "default", "delegate", "do", "double", "else", "enum", "event", "explicit", "extern",
        "false", "finally", "fixed", "float", "for", "foreach", "goto", "if", "implicit", "in", "int", "interface",
        "internal", "is", "lock", "long", "namespace", "new", "null", "object", "operator", "out", "override", "params",
        "private", "protected", "public", "readonly", "ref", "return", "sbyte", "sealed", "short", "sizeof", "stackalloc",
        "static", "string", "struct", "switch", "this", "throw", "true", "try", "typeof", "uint", "ulong", "unchecked",
        "unsafe", "ushort", "using", "virtual", "void", "volatile", "while",
    };

    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        PropertyNameCaseInsensitive = true,
        ReadCommentHandling = JsonCommentHandling.Skip,
        AllowTrailingCommas = true,
        WriteIndented = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        Converters = { new JsonStringEnumConverter(JsonNamingPolicy.CamelCase) },
    };

    public static ManifestUiToolResult Execute(params string[] args)
    {
        return Execute((IReadOnlyList<string>)args, projectRoot: null, CancellationToken.None);
    }

    public static ManifestUiToolResult Execute(IReadOnlyList<string> args, string? projectRoot = null)
    {
        return Execute(args, projectRoot, CancellationToken.None);
    }

    public static ManifestUiToolResult Execute(IReadOnlyList<string> args, CancellationToken cancellationToken)
    {
        return Execute(args, projectRoot: null, cancellationToken);
    }

    public static ManifestUiToolResult Execute(IReadOnlyList<string> args, string? projectRoot, CancellationToken cancellationToken)
    {
        try
        {
            cancellationToken.ThrowIfCancellationRequested();
            if (args.Count == 0)
            {
                return UsageError("A command is required.");
            }

            var commandArgs = args.Skip(1).ToArray();
            var argumentError = ValidateCommandArguments(args[0], commandArgs);
            if (argumentError is not null)
            {
                return UsageError(argumentError);
            }
            return args[0] switch
            {
                "doctor" => Doctor(commandArgs, projectRoot, cancellationToken),
                "validate" => ValidateCommand(commandArgs, projectRoot, cancellationToken),
                "generate" => GenerateCommand(commandArgs, projectRoot, cancellationToken),
                "verify" => VerifyCommand(commandArgs, projectRoot, cancellationToken),
                "check" => CheckCommand(commandArgs, projectRoot, cancellationToken),
                "migrate" => MigrateCommand(commandArgs, projectRoot, cancellationToken),
                "schema" => SchemaCommand(commandArgs, projectRoot, cancellationToken),
                "assets" => AssetsCommand(commandArgs, projectRoot, cancellationToken),
                "--help" or "-h" or "help" => new ManifestUiToolResult { ExitCode = Success, Messages = new[] { UsageText } },
                _ => UsageError($"Unknown command: {args[0]}"),
            };
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            return Cancelled();
        }
        catch (Exception ex)
        {
            return new ManifestUiToolResult
            {
                ExitCode = InternalFailure,
                Diagnostics = new[]
                {
                    new ManifestDiagnostic("MUI3000", ManifestDiagnosticSeverity.Error, "", "", 0, 0, ex.Message, "Run with a debugger or file an issue with the command and manifest."),
                },
            };
        }
    }

    public static int Run(IReadOnlyList<string> args, TextWriter? output = null, TextWriter? error = null, string? projectRoot = null)
    {
        output ??= Console.Out;
        error ??= Console.Error;
        var format = GetOption(args.Skip(1).ToArray(), "--format") ?? "text";
        if (format is not ("text" or "json" or "sarif"))
        {
            var usage = UsageError("--format must be text, json, or sarif.");
            WriteResult(usage, "text", output, error);
            return usage.ExitCode;
        }
        var result = Execute(args, projectRoot);
        WriteResult(result, format, output, error);
        return result.ExitCode;
    }

    private static ManifestUiToolResult ValidateCommand(string[] args, string? projectRoot, CancellationToken cancellationToken)
    {
        var packageArgument = GetPositionals(args).Single();

        var root = ResolveProjectRoot(projectRoot ?? GetOption(args, "--project"), packageArgument);
        var packagePath = ResolvePackagePath(packageArgument, root);
        if (!File.Exists(packagePath))
        {
            return MissingInput(packagePath, "package", "package manifest does not exist");
        }
        var result = ValidationResult.Create();
        var package = ManifestPackage.Load(packagePath, root, result, cancellationToken: cancellationToken);
        package?.Validate(result, cancellationToken);
        cancellationToken.ThrowIfCancellationRequested();
        if (result.Ok && args.Contains("--write-report", StringComparer.Ordinal) && package is not null)
        {
            cancellationToken.ThrowIfCancellationRequested();
            ReportWriter.Write(package);
        }

        return Complete(result, result.Ok && package is not null ? $"OK {package.Package.PackageId}" : null);
    }

    private static ManifestUiToolResult GenerateCommand(string[] args, string? projectRoot, CancellationToken cancellationToken)
    {
        var packageArgument = GetPositionals(args).Single();

        var root = ResolveProjectRoot(projectRoot ?? GetOption(args, "--project"), packageArgument);
        var packagePath = ResolvePackagePath(packageArgument, root);
        if (!File.Exists(packagePath))
        {
            return MissingInput(packagePath, "package", "package manifest does not exist");
        }
        var result = ValidationResult.Create();
        var package = ManifestPackage.Load(packagePath, root, result, cancellationToken: cancellationToken);
        package?.Validate(result, cancellationToken);
        if (!result.Ok || package is null)
        {
            return Complete(result);
        }

        cancellationToken.ThrowIfCancellationRequested();
        var plan = GenerationPlan.Create(package, result, cancellationToken);
        if (!result.Ok)
        {
            return Complete(result);
        }

        if (args.Contains("--check", StringComparer.Ordinal))
        {
            plan.Check(result, cancellationToken);
            return Complete(result, result.Ok ? $"OK generated output is current for {package.Package.PackageId}" : null);
        }

        plan.Commit(clean: args.Contains("--clean", StringComparer.Ordinal), result, cancellationToken);
        return Complete(result, result.Ok ? $"Generated {package.Package.PackageId} -> {Path.GetRelativePath(root, package.GetOutputDir()).Replace('\\', '/')}" : null);
    }

    private static ManifestUiToolResult MigrateCommand(string[] args, string? projectRoot, CancellationToken cancellationToken)
    {
        var packageArgument = GetPositionals(args).Single();
        var root = ResolveProjectRoot(projectRoot, packageArgument);
        var packagePath = ResolvePackagePath(packageArgument, root);
        if (!File.Exists(packagePath))
        {
            return MissingInput(packagePath, "package", "package manifest does not exist");
        }
        var result = ValidationResult.Create();
        var package = ManifestPackage.Load(packagePath, root, result, loadReferences: false, cancellationToken);
        if (package is null)
        {
            return Complete(result);
        }

        if (package.Package.SchemaVersion == CurrentSchemaVersion)
        {
            return Complete(result, $"OK schemaVersion {CurrentSchemaVersion} no migration needed");
        }

        if (package.Package.SchemaVersion > CurrentSchemaVersion)
        {
            result.Error("package.json", "schemaVersion", $"{package.Package.SchemaVersion} is newer than tool support {CurrentSchemaVersion}");
        }
        else
        {
            result.Error("package.json", "schemaVersion", $"migration from {package.Package.SchemaVersion} to {CurrentSchemaVersion} is not defined");
        }
        return Complete(result);
    }

    private static ManifestUiToolResult UsageError(string message)
    {
        return new ManifestUiToolResult
        {
            ExitCode = UsageOrEnvironmentFailure,
            Diagnostics = new[] { new ManifestDiagnostic("MUI5001", ManifestDiagnosticSeverity.Error, "", "", 0, 0, message, "Run manifest-ui --help for command syntax.") },
        };
    }

    private static ManifestUiToolResult Cancelled()
    {
        return new ManifestUiToolResult
        {
            ExitCode = UsageOrEnvironmentFailure,
            Diagnostics = new[]
            {
                new ManifestDiagnostic("MUI5004", ManifestDiagnosticSeverity.Error, "", "", 0, 0, "operation was canceled before commit", "Retry the command when ready."),
            },
        };
    }

    private static ManifestUiToolResult MissingInput(string path, string logicalPath, string message)
    {
        return new ManifestUiToolResult
        {
            ExitCode = UsageOrEnvironmentFailure,
            Diagnostics = new[]
            {
                new ManifestDiagnostic("MUI5003", ManifestDiagnosticSeverity.Error, path.Replace('\\', '/'), $"/{logicalPath}", 0, 0, message, "Check the path and project root."),
            },
        };
    }

    private const string UsageText = """
        Usage:
          manifest-ui doctor --project <dir> [--godot <exe>]
          manifest-ui validate <package> [--project <dir>] [--format text|json|sarif] [--write-report]
          manifest-ui generate <package> [--project <dir>] [--check] [--clean]
          manifest-ui verify <package> [--project <dir>]
          manifest-ui check --project <dir> [--release]
          manifest-ui migrate --check <package>
          manifest-ui schema sync|check [--project <dir>]
          manifest-ui assets hash --check|--write <package> [--project <dir>]
        """;

    private static string ResolvePackagePath(string path, string projectRoot)
    {
        var resolved = Path.GetFullPath(path, projectRoot);
        return Directory.Exists(resolved) ? Path.Combine(resolved, "package.json") : resolved;
    }

    private static ManifestUiToolResult Doctor(string[] args, string? projectRoot, CancellationToken cancellationToken)
    {
        var configuredRoot = projectRoot ?? GetOption(args, "--project");
        if (string.IsNullOrWhiteSpace(configuredRoot))
        {
            return UsageError("doctor requires --project <dir>.");
        }

        var root = Path.GetFullPath(configuredRoot);
        var result = ValidationResult.Create();
        if (!Directory.Exists(root))
        {
            result.EnvironmentError(root, "project", "project directory does not exist");
        }
        else
        {
            if (!File.Exists(Path.Combine(root, "project.godot")))
            {
                result.EnvironmentError("project.godot", "project", "Godot project.godot was not found");
            }

            var csproj = Directory.EnumerateFiles(root, "*.csproj", SearchOption.TopDirectoryOnly).FirstOrDefault();
            if (csproj is null)
            {
                result.EnvironmentError(root, "dotnet", "Godot C# project file was not found");
            }
            else
            {
                var projectText = File.ReadAllText(csproj);
                if (!projectText.Contains("Godot.NET.Sdk/4.7", StringComparison.Ordinal))
                {
                    result.EnvironmentError(Path.GetFileName(csproj), "sdk", "project must use Godot.NET.Sdk/4.7.x");
                }
                if (!projectText.Contains("<TargetFramework>net8.0</TargetFramework>", StringComparison.Ordinal))
                {
                    result.EnvironmentError(Path.GetFileName(csproj), "targetFramework", "project must target net8.0");
                }
            }
        }

        var godot = GetOption(args, "--godot") ?? Environment.GetEnvironmentVariable("GODOT_BIN");
        if (string.IsNullOrWhiteSpace(godot))
        {
            result.EnvironmentError("GODOT_BIN", "environment", "Godot 4.7 Mono executable is not configured", "Set GODOT_BIN or pass --godot <exe>.");
        }
        else if (!File.Exists(Path.GetFullPath(godot)))
        {
            result.EnvironmentError(godot, "environment", "configured Godot executable does not exist");
        }
        else if (TryRunVersionCommand(Path.GetFullPath(godot), root, cancellationToken, out var godotVersion, out var godotFailure))
        {
            var normalizedVersion = godotVersion.ToLowerInvariant();
            if (!normalizedVersion.Contains("4.7", StringComparison.Ordinal)
                || !normalizedVersion.Contains("mono", StringComparison.Ordinal))
            {
                result.EnvironmentError(godot, "godotVersion", $"Godot executable must report Godot 4.7 Mono, got '{godotVersion}'");
            }
        }
        else
        {
            result.EnvironmentError(godot, "godotVersion", $"could not execute Godot --version: {godotFailure}");
        }

        cancellationToken.ThrowIfCancellationRequested();
        if (TryRunVersionCommand("dotnet", root, cancellationToken, out var dotnetVersion, out var dotnetFailure))
        {
            if (!Version.TryParse(dotnetVersion.Split('-', 2)[0], out var parsedDotnetVersion) || parsedDotnetVersion.Major != 8)
            {
                result.EnvironmentError("dotnet", "dotnetVersion", $".NET SDK 8 is required, got '{dotnetVersion}'", "Install .NET SDK 8 and honor the repository global.json.");
            }
        }
        else
        {
            result.EnvironmentError("dotnet", "dotnetVersion", $"could not execute dotnet --version: {dotnetFailure}", "Install .NET SDK 8 and ensure dotnet is on PATH.");
        }

        return Complete(result, result.Ok ? $"OK Manifest UI environment at {root}" : null, environmentFailure: true);
    }

    private static ManifestUiToolResult VerifyCommand(string[] args, string? projectRoot, CancellationToken cancellationToken)
    {
        var packageArgument = GetPositionals(args).Single();

        var root = ResolveProjectRoot(projectRoot ?? GetOption(args, "--project"), packageArgument);
        var packagePath = ResolvePackagePath(packageArgument, root);
        if (!File.Exists(packagePath))
        {
            return MissingInput(packagePath, "package", "package manifest does not exist");
        }
        var result = ValidationResult.Create();
        var package = ManifestPackage.Load(packagePath, root, result, cancellationToken: cancellationToken);
        package?.Validate(result, cancellationToken);
        if (package is not null && result.Ok)
        {
            var plan = GenerationPlan.Create(package, result, cancellationToken);
            plan.Check(result, cancellationToken);
            cancellationToken.ThrowIfCancellationRequested();
            VerifyGeneratedScene(package, result);
        }
        return Complete(result, result.Ok && package is not null ? $"OK verified {package.Package.PackageId}" : null);
    }

    private static ManifestUiToolResult CheckCommand(string[] args, string? projectRoot, CancellationToken cancellationToken)
    {
        var configuredRoot = projectRoot ?? GetOption(args, "--project");
        if (string.IsNullOrWhiteSpace(configuredRoot))
        {
            return UsageError("check requires --project <dir>.");
        }

        var root = Path.GetFullPath(configuredRoot);
        if (!Directory.Exists(root) || !File.Exists(Path.Combine(root, "project.godot")))
        {
            return MissingInput(root, "project", "check requires an existing Godot project directory");
        }
        var result = ValidationResult.Create();
        var packages = DiscoverPackages(root, cancellationToken).ToArray();
        if (packages.Length == 0)
        {
            result.Warning("project", "packages", "no Manifest UI packages were found", "Add packages beneath ui/ or pass validate <package>.");
        }
        foreach (var packagePath in packages)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var packageResult = ValidationResult.Create();
            var package = ManifestPackage.Load(packagePath, root, packageResult, cancellationToken: cancellationToken);
            package?.Validate(packageResult, cancellationToken);
            if (package is not null && packageResult.Ok && args.Contains("--release", StringComparer.Ordinal))
            {
                GenerationPlan.Create(package, packageResult, cancellationToken).Check(packageResult, cancellationToken);
                cancellationToken.ThrowIfCancellationRequested();
                VerifyGeneratedScene(package, packageResult);
            }
            result.MergeFrom(packageResult);
        }
        return Complete(result, result.Ok ? $"OK checked {packages.Length} package(s)" : null);
    }

    private static ManifestUiToolResult SchemaCommand(string[] args, string? projectRoot, CancellationToken cancellationToken)
    {
        var action = GetPositionals(args).Single();

        var root = ResolveProjectRoot(projectRoot ?? GetOption(args, "--project"), null);
        var sourceDir = SchemaFiles.FindBundledDirectory(root);
        var result = ValidationResult.Create();
        if (sourceDir is null)
        {
            result.EnvironmentError("schemas", "source", "bundled schema directory was not found");
            return Complete(result, environmentFailure: true);
        }

        var destinations = new List<string>();
        var shared = Path.Combine(root, "schemas", "manifest-ui");
        if (!PathsEqual(sourceDir, shared))
        {
            destinations.Add(shared);
        }
        destinations.AddRange(DiscoverPackages(root, cancellationToken)
            .Select(path => Path.Combine(Path.GetDirectoryName(path)!, "schemas"))
            .Where(Directory.Exists));

        foreach (var destination in destinations.Distinct(StringComparer.OrdinalIgnoreCase))
        {
            cancellationToken.ThrowIfCancellationRequested();
            foreach (var schemaFile in SchemaFiles.All)
            {
                cancellationToken.ThrowIfCancellationRequested();
                var source = Path.Combine(sourceDir, schemaFile);
                var target = Path.Combine(destination, schemaFile);
                if (!File.Exists(target) || NormalizeText(File.ReadAllText(source)) != NormalizeText(File.ReadAllText(target)))
                {
                    if (action == "check")
                    {
                        result.GenerationError(Path.GetRelativePath(root, target), "schema", "schema snapshot is missing or stale", "Run manifest-ui schema sync --project <dir>.");
                    }
                    else
                    {
                        AtomicWrite(target, NormalizeGeneratedText(File.ReadAllText(source)));
                    }
                }
            }
        }

        return Complete(result, result.Ok ? $"OK schema {action}" : null);
    }

    private static ManifestUiToolResult AssetsCommand(string[] args, string? projectRoot, CancellationToken cancellationToken)
    {
        var positionals = GetPositionals(args);
        var packageArgument = positionals[1];
        var action = args.Contains("--check", StringComparer.Ordinal) ? "--check" : "--write";
        var root = ResolveProjectRoot(projectRoot ?? GetOption(args, "--project"), packageArgument);
        var result = ValidationResult.Create();
        var packagePath = ResolvePackagePath(packageArgument, root);
        if (!File.Exists(packagePath))
        {
            return MissingInput(packagePath, "package", "package manifest does not exist");
        }
        var packageNode = ReadJsonNode(packagePath, result);
        if (packageNode is null)
        {
            return Complete(result);
        }

        var packageDir = Path.GetDirectoryName(packagePath)!;
        var assetsReference = packageNode["assets"]?.GetValue<string>();
        var assetsPath = string.IsNullOrWhiteSpace(assetsReference)
            ? null
            : ResolvePackageFile(packageDir, assetsReference, "package.json", "assets", result);
        var assetsNode = assetsPath is null ? null : ReadJsonNode(assetsPath, result);
        if (assetsNode?["assets"] is not JsonArray assets)
        {
            result.Error("assets.json", "assets", "must be an array");
            return Complete(result);
        }

        foreach (var (node, index) in assets.Select((node, index) => (node, index)))
        {
            cancellationToken.ThrowIfCancellationRequested();
            if (node is not JsonObject asset)
            {
                result.Error("assets.json", $"assets[{index}]", "must be an object");
                continue;
            }
            var relativePath = asset["relativePath"]?.GetValue<string>() ?? "";
            var sourcePath = ResolvePackageFile(packageDir, relativePath, "assets.json", $"assets[{index}].relativePath", result);
            if (sourcePath is null || !File.Exists(sourcePath))
            {
                result.Error("assets.json", $"assets[{index}].relativePath", $"file does not exist: {relativePath}");
                continue;
            }
            var actual = Sha256File(sourcePath);
            var declared = asset["contentHash"]?.GetValue<string>() ?? "";
            if (action == "--check")
            {
                if (!string.Equals(declared, actual, StringComparison.Ordinal))
                {
                    result.Error("assets.json", $"assets[{index}].contentHash", string.IsNullOrWhiteSpace(declared) ? "content hash is missing" : $"hash mismatch, expected {declared}, actual {actual}", 0, 0, "Run manifest-ui assets hash --write <package>.");
                }
            }
            else
            {
                asset["contentHash"] = actual;
            }
        }

        if (action == "--write" && result.Ok && assetsPath is not null)
        {
            cancellationToken.ThrowIfCancellationRequested();
            AtomicWrite(assetsPath, NormalizeGeneratedText(assetsNode.ToJsonString(JsonOptions)));
        }
        return Complete(result, result.Ok ? $"OK asset hashes {action[2..]}" : null);
    }

    private static JsonObject? ReadJsonNode(string path, ValidationResult result)
    {
        try
        {
            return JsonNode.Parse(File.ReadAllText(path), new JsonNodeOptions { PropertyNameCaseInsensitive = false }, new JsonDocumentOptions { AllowTrailingCommas = true, CommentHandling = JsonCommentHandling.Skip }) as JsonObject;
        }
        catch (Exception ex) when (ex is IOException or JsonException or UnauthorizedAccessException)
        {
            var line = ex is JsonException json ? (json.LineNumber ?? -1) + 1 : 0;
            var column = ex is JsonException jsonError ? (jsonError.BytePositionInLine ?? -1) + 1 : 0;
            result.Error(Path.GetFileName(path), "", $"JSON read failed: {ex.Message}", line, column, "Check JSON syntax at the reported location.");
            return null;
        }
    }

    private static void VerifyGeneratedScene(ManifestPackage package, ValidationResult result)
    {
        var scenePath = Path.Combine(package.GetOutputDir(), $"{package.Package.Godot.WidgetClass}.tscn");
        if (!File.Exists(scenePath))
        {
            result.EngineError(Path.GetRelativePath(package.ProjectRoot, scenePath), "scene", "generated PackedScene is missing", "Run manifest-ui generate first.");
            return;
        }

        var scene = NormalizeText(File.ReadAllText(scenePath));
        if (!scene.Contains("[gd_scene", StringComparison.Ordinal) || !scene.Contains("id=\"1_widget\"", StringComparison.Ordinal))
        {
            result.EngineError(Path.GetRelativePath(package.ProjectRoot, scenePath), "scene", "generated scene header or widget script resource is invalid");
        }
        if (!scene.Contains($"[node name=\"{package.Layout.Root.Name}\" type=\"{package.Layout.Root.Type}\"]", StringComparison.Ordinal))
        {
            result.EngineError(Path.GetRelativePath(package.ProjectRoot, scenePath), "root", "generated scene root does not match layout root");
        }
    }

    private static IEnumerable<string> DiscoverPackages(string projectRoot, CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        var uiRoot = Path.Combine(projectRoot, "ui");
        if (!Directory.Exists(uiRoot))
        {
            yield break;
        }
        var packages = Directory.EnumerateFiles(uiRoot, "package.json", SearchOption.AllDirectories)
            .Where(path => !HasExcludedSegment(Path.GetRelativePath(projectRoot, path)))
            .OrderBy(path => path, StringComparer.Ordinal);
        foreach (var package in packages)
        {
            cancellationToken.ThrowIfCancellationRequested();
            yield return package;
        }
    }

    private static bool HasExcludedSegment(string path)
    {
        var segments = path.Split(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar);
        return segments.Any(segment => segment is "generated" or "addons" or "tests" or ".godot" or ".git");
    }

    private static string ResolveProjectRoot(string? configuredRoot, string? packageArgument)
    {
        if (!string.IsNullOrWhiteSpace(configuredRoot))
        {
            return Path.GetFullPath(configuredRoot);
        }

        var start = string.IsNullOrWhiteSpace(packageArgument)
            ? Directory.GetCurrentDirectory()
            : Path.GetFullPath(packageArgument, Directory.GetCurrentDirectory());
        if (File.Exists(start))
        {
            start = Path.GetDirectoryName(start)!;
        }
        else if (!Directory.Exists(start))
        {
            start = Path.GetDirectoryName(start) ?? Directory.GetCurrentDirectory();
        }

        for (var current = new DirectoryInfo(start); current is not null; current = current.Parent)
        {
            if (File.Exists(Path.Combine(current.FullName, "project.godot")))
            {
                return current.FullName;
            }
        }
        return Path.GetFullPath(Directory.GetCurrentDirectory());
    }

    private static string? GetOption(IReadOnlyList<string> args, string option)
    {
        for (var i = 0; i < args.Count - 1; i++)
        {
            if (string.Equals(args[i], option, StringComparison.Ordinal))
            {
                return args[i + 1];
            }
        }
        return null;
    }

    private static IReadOnlyList<string> GetPositionals(IReadOnlyList<string> args)
    {
        var optionsWithValues = new HashSet<string>(StringComparer.Ordinal) { "--project", "--godot", "--format" };
        var positionals = new List<string>();
        for (var i = 0; i < args.Count; i++)
        {
            if (optionsWithValues.Contains(args[i]))
            {
                i++;
                continue;
            }
            if (!args[i].StartsWith("-", StringComparison.Ordinal))
            {
                positionals.Add(args[i]);
            }
        }
        return positionals;
    }

    private static string? ValidateCommandArguments(string command, IReadOnlyList<string> args)
    {
        if (command is "--help" or "-h" or "help")
        {
            return args.Count == 0 ? null : $"{command} does not accept arguments.";
        }

        HashSet<string> valueOptions;
        HashSet<string> flags;
        switch (command)
        {
            case "doctor":
                valueOptions = new HashSet<string>(StringComparer.Ordinal) { "--project", "--godot" };
                flags = new HashSet<string>(StringComparer.Ordinal);
                break;
            case "validate":
                valueOptions = new HashSet<string>(StringComparer.Ordinal) { "--project", "--format" };
                flags = new HashSet<string>(StringComparer.Ordinal) { "--write-report" };
                break;
            case "generate":
                valueOptions = new HashSet<string>(StringComparer.Ordinal) { "--project" };
                flags = new HashSet<string>(StringComparer.Ordinal) { "--check", "--clean" };
                break;
            case "verify":
                valueOptions = new HashSet<string>(StringComparer.Ordinal) { "--project" };
                flags = new HashSet<string>(StringComparer.Ordinal);
                break;
            case "check":
                valueOptions = new HashSet<string>(StringComparer.Ordinal) { "--project" };
                flags = new HashSet<string>(StringComparer.Ordinal) { "--release" };
                break;
            case "migrate":
                valueOptions = new HashSet<string>(StringComparer.Ordinal);
                flags = new HashSet<string>(StringComparer.Ordinal) { "--check" };
                break;
            case "schema":
                valueOptions = new HashSet<string>(StringComparer.Ordinal) { "--project" };
                flags = new HashSet<string>(StringComparer.Ordinal);
                break;
            case "assets":
                valueOptions = new HashSet<string>(StringComparer.Ordinal) { "--project" };
                flags = new HashSet<string>(StringComparer.Ordinal) { "--check", "--write" };
                break;
            default:
                return null;
        }

        var positionals = new List<string>();
        var seen = new HashSet<string>(StringComparer.Ordinal);
        for (var i = 0; i < args.Count; i++)
        {
            var argument = args[i];
            if (valueOptions.Contains(argument))
            {
                if (!seen.Add(argument))
                {
                    return $"Duplicate option: {argument}";
                }
                if (i + 1 >= args.Count || args[i + 1].StartsWith("-", StringComparison.Ordinal))
                {
                    return $"{argument} requires a value.";
                }
                i++;
                continue;
            }
            if (flags.Contains(argument))
            {
                if (!seen.Add(argument))
                {
                    return $"Duplicate option: {argument}";
                }
                continue;
            }
            if (argument.StartsWith("-", StringComparison.Ordinal))
            {
                return $"Unknown option for {command}: {argument}";
            }
            positionals.Add(argument);
        }

        if (seen.Contains("--format"))
        {
            var format = GetOption(args, "--format");
            if (format is not ("text" or "json" or "sarif"))
            {
                return "--format must be text, json, or sarif.";
            }
        }

        return command switch
        {
            "doctor" when positionals.Count != 0 => "doctor does not accept positional arguments.",
            "validate" when positionals.Count != 1 => "validate requires exactly one <package.json> argument.",
            "generate" when positionals.Count != 1 => "generate requires exactly one <package.json> argument.",
            "generate" when seen.Contains("--check") && seen.Contains("--clean") => "generate --check and --clean cannot be used together.",
            "verify" when positionals.Count != 1 => "verify requires exactly one <package.json> argument.",
            "check" when positionals.Count != 0 => "check accepts only --project <dir> and --release.",
            "migrate" when positionals.Count != 1 || !seen.Contains("--check") => "migrate usage: manifest-ui migrate --check <package.json>",
            "schema" when positionals.Count != 1 || positionals[0] is not ("sync" or "check") => "schema usage: manifest-ui schema sync|check [--project <dir>]",
            "assets" when positionals.Count != 2 || positionals[0] != "hash" => "assets usage: manifest-ui assets hash --check|--write <package.json> [--project <dir>]",
            "assets" when seen.Contains("--check") == seen.Contains("--write") => "assets hash requires exactly one of --check or --write.",
            _ => null,
        };
    }

    private static bool TryRunVersionCommand(
        string executable,
        string workingDirectory,
        CancellationToken cancellationToken,
        out string version,
        out string failure)
    {
        version = "";
        failure = "";
        try
        {
            var startInfo = new ProcessStartInfo(executable)
            {
                WorkingDirectory = Directory.Exists(workingDirectory) ? workingDirectory : Directory.GetCurrentDirectory(),
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
                CreateNoWindow = true,
            };
            startInfo.ArgumentList.Add("--version");
            using var process = Process.Start(startInfo);
            if (process is null)
            {
                failure = "process did not start";
                return false;
            }

            var standardOutput = process.StandardOutput.ReadToEndAsync();
            var standardError = process.StandardError.ReadToEndAsync();
            var stopwatch = Stopwatch.StartNew();
            while (!process.WaitForExit(100))
            {
                if (cancellationToken.IsCancellationRequested)
                {
                    try
                    {
                        process.Kill(entireProcessTree: true);
                    }
                    catch (InvalidOperationException)
                    {
                    }
                    cancellationToken.ThrowIfCancellationRequested();
                }
                if (stopwatch.Elapsed >= TimeSpan.FromSeconds(10))
                {
                    try
                    {
                        process.Kill(entireProcessTree: true);
                    }
                    catch (InvalidOperationException)
                    {
                    }
                    failure = "process timed out after 10 seconds";
                    return false;
                }
            }

            var output = standardOutput.GetAwaiter().GetResult();
            var error = standardError.GetAwaiter().GetResult();
            var lines = string.Join("\n", output, error)
                .Split(new[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries);
            version = lines.FirstOrDefault() ?? "";
            if (process.ExitCode != 0)
            {
                failure = $"process exited with code {process.ExitCode}: {string.Join(" ", lines)}".TrimEnd();
                return false;
            }
            if (string.IsNullOrWhiteSpace(version))
            {
                failure = "process returned no version output";
                return false;
            }
            return true;
        }
        catch (Exception ex) when (ex is InvalidOperationException or IOException or UnauthorizedAccessException or System.ComponentModel.Win32Exception)
        {
            failure = ex.Message;
            return false;
        }
    }

    private static ManifestUiToolResult Complete(ValidationResult result, string? message = null, bool environmentFailure = false)
    {
        return new ManifestUiToolResult
        {
            ExitCode = result.Ok ? Success : environmentFailure ? UsageOrEnvironmentFailure : ValidationFailure,
            Diagnostics = result.Diagnostics.ToArray(),
            Messages = string.IsNullOrWhiteSpace(message) ? Array.Empty<string>() : new[] { message },
        };
    }

    private static void WriteResult(ManifestUiToolResult result, string format, TextWriter output, TextWriter error)
    {
        if (format == "json")
        {
            output.WriteLine(JsonSerializer.Serialize(result, JsonOptions));
            return;
        }
        if (format == "sarif")
        {
            var sarif = new
            {
                version = "2.1.0",
                runs = new[]
                {
                    new
                    {
                        tool = new { driver = new { name = "Manifest UI", version = ToolVersion } },
                        results = result.Diagnostics.Select(diagnostic => new
                        {
                            ruleId = diagnostic.Code,
                            level = diagnostic.Severity.ToString().ToLowerInvariant(),
                            message = new { text = diagnostic.Message },
                            properties = new { jsonPointer = diagnostic.JsonPointer, hint = diagnostic.Hint },
                            locations = string.IsNullOrWhiteSpace(diagnostic.File) ? Array.Empty<object>() : new object[]
                            {
                                new { physicalLocation = new { artifactLocation = new { uri = diagnostic.File.Replace('\\', '/') }, region = new { startLine = Math.Max(1, diagnostic.Line), startColumn = Math.Max(1, diagnostic.Column) } } },
                            },
                        }),
                    },
                },
            };
            output.WriteLine(JsonSerializer.Serialize(sarif, JsonOptions));
            return;
        }
        if (format != "text")
        {
            error.WriteLine("ERROR MUI5002: --format must be text, json, or sarif");
            return;
        }

        foreach (var message in result.Messages)
        {
            output.WriteLine(message);
        }
        foreach (var diagnostic in result.Diagnostics)
        {
            var writer = diagnostic.Severity == ManifestDiagnosticSeverity.Info ? output : error;
            var location = string.IsNullOrWhiteSpace(diagnostic.File) ? "" : $" {diagnostic.File}{diagnostic.JsonPointer}";
            if (diagnostic.Line > 0)
            {
                location += $"({diagnostic.Line},{diagnostic.Column})";
            }
            writer.WriteLine($"{diagnostic.Severity.ToString().ToUpperInvariant()} {diagnostic.Code}:{location}: {diagnostic.Message}{(string.IsNullOrWhiteSpace(diagnostic.Hint) ? "" : $" Hint: {diagnostic.Hint}")}");
        }
    }

    private static bool PathsEqual(string left, string right) => string.Equals(Path.GetFullPath(left).TrimEnd(Path.DirectorySeparatorChar), Path.GetFullPath(right).TrimEnd(Path.DirectorySeparatorChar), StringComparison.OrdinalIgnoreCase);
    private static string NormalizeGeneratedText(string value) => value.Replace("\r\n", "\n").Replace('\r', '\n').TrimEnd() + "\n";
    private static void AtomicWrite(string path, string content)
    {
        Directory.CreateDirectory(Path.GetDirectoryName(path)!);
        var temporary = Path.Combine(Path.GetDirectoryName(path)!, $".{Path.GetFileName(path)}.{Guid.NewGuid():N}.tmp");
        try
        {
            File.WriteAllText(temporary, NormalizeGeneratedText(content), Utf8NoBom);
            File.Move(temporary, path, overwrite: true);
        }
        finally
        {
            if (File.Exists(temporary))
            {
                File.Delete(temporary);
            }
        }
    }

    private static T? ReadJson<T>(string path, ValidationResult result, string logicalName)
    {
        try
        {
            return JsonSerializer.Deserialize<T>(File.ReadAllText(path), JsonOptions);
        }
        catch (Exception ex) when (ex is IOException or JsonException or UnauthorizedAccessException)
        {
            var line = ex is JsonException json ? (json.LineNumber ?? -1) + 1 : 0;
            var column = ex is JsonException jsonError ? (jsonError.BytePositionInLine ?? -1) + 1 : 0;
            result.Error(Path.GetFileName(path), logicalName, $"JSON read failed: {ex.Message}", line, column, "Check JSON syntax at the reported location.");
            return default;
        }
    }

    private sealed class ManifestPackage
    {
        private readonly Dictionary<string, LayoutNode> _nodeByPath = new(StringComparer.Ordinal);
        private readonly Dictionary<string, LayoutNode> _nodeById = new(StringComparer.Ordinal);
        private CancellationToken _cancellationToken;
        private static readonly HashSet<string> AllowedFieldTypes = new(StringComparer.Ordinal) { "text", "bool", "number", "assetRef", "object" };
        private static readonly HashSet<string> SupportedProperties = new(StringComparer.Ordinal) { "text", "visible", "enabled", "value", "texture", "themeClass" };
        private static readonly HashSet<string> SupportedInputProperties = new(StringComparer.Ordinal) { "text", "buttonPressed", "value", "selected" };
        private static readonly HashSet<string> KnownConverters = new(StringComparer.Ordinal) { "string", "bool", "number", "not", "isNotEmpty", "texture" };

        public required string ProjectRoot { get; init; }
        public required string PackagePath { get; init; }
        public required string DirectoryPath { get; init; }
        public required PackageJson Package { get; init; }
        public required LayoutJson Layout { get; init; }
        public required BindingsJson Bindings { get; init; }
        public required AssetsJson Assets { get; init; }
        public required CodegenJson Codegen { get; init; }
        public required ValidationJson Validation { get; init; }
        public StringsJson? Strings { get; init; }
        public required Dictionary<string, string> SourceFiles { get; init; }
        public IReadOnlyDictionary<string, LayoutNode> NodeByPath => _nodeByPath;

        public static ManifestPackage? Load(
            string packagePath,
            string projectRoot,
            ValidationResult result,
            bool loadReferences = true,
            CancellationToken cancellationToken = default)
        {
            cancellationToken.ThrowIfCancellationRequested();
            if (!File.Exists(packagePath))
            {
                result.Error("package.json", "package", $"file does not exist: {packagePath}");
                return null;
            }

            projectRoot = Path.GetFullPath(projectRoot);
            packagePath = Path.GetFullPath(packagePath);
            result.RegisterSource("package.json", packagePath);
            var relativePackage = Path.GetRelativePath(projectRoot, packagePath);
            if (relativePackage == ".." || relativePackage.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
            {
                result.Error("package.json", "package", "package must stay inside the project directory");
                return null;
            }

            var packageDir = Path.GetDirectoryName(packagePath) ?? projectRoot;
            var package = ReadJson<PackageJson>(packagePath, result, "package.json");
            cancellationToken.ThrowIfCancellationRequested();
            if (package is null)
            {
                return null;
            }

            var sourceFiles = new Dictionary<string, string>(StringComparer.Ordinal) { ["package"] = packagePath };
            if (!loadReferences)
            {
                return new ManifestPackage
                {
                    ProjectRoot = projectRoot,
                    PackagePath = packagePath,
                    DirectoryPath = packageDir,
                    Package = package,
                    Layout = new LayoutJson(),
                    Bindings = new BindingsJson(),
                    Assets = new AssetsJson(),
                    Codegen = new CodegenJson(),
                    Validation = new ValidationJson(),
                    Strings = null,
                    SourceFiles = sourceFiles,
                };
            }

            var assetsPath = ResolveRequiredPackageFile(packageDir, package.Assets, "assets", result);
            var layoutPath = ResolveRequiredPackageFile(packageDir, package.Layout, "layout", result);
            var bindingsPath = ResolveRequiredPackageFile(packageDir, package.Bindings, "bindings", result);
            var codegenPath = ResolveRequiredPackageFile(packageDir, package.Codegen, "codegen", result);
            var validationPath = ResolveRequiredPackageFile(packageDir, package.Validation, "validation", result);
            var stringsPath = string.IsNullOrWhiteSpace(package.Strings)
                ? null
                : ResolvePackageFile(packageDir, package.Strings, "package.json", "strings", result);
            if (stringsPath is not null && !File.Exists(stringsPath))
            {
                result.Error("package.json", "strings", $"file does not exist: {package.Strings}");
                stringsPath = null;
            }

            result.RegisterSource("assets.json", assetsPath);
            result.RegisterSource("layout.json", layoutPath);
            result.RegisterSource("bindings.json", bindingsPath);
            result.RegisterSource("codegen.json", codegenPath);
            result.RegisterSource("validation.json", validationPath);
            result.RegisterSource("strings.json", stringsPath);

            cancellationToken.ThrowIfCancellationRequested();
            var assets = assetsPath is null ? null : ReadJson<AssetsJson>(assetsPath, result, "assets.json");
            cancellationToken.ThrowIfCancellationRequested();
            var layout = layoutPath is null ? null : ReadJson<LayoutJson>(layoutPath, result, "layout.json");
            cancellationToken.ThrowIfCancellationRequested();
            var bindings = bindingsPath is null ? null : ReadJson<BindingsJson>(bindingsPath, result, "bindings.json");
            cancellationToken.ThrowIfCancellationRequested();
            var codegen = codegenPath is null ? null : ReadJson<CodegenJson>(codegenPath, result, "codegen.json");
            cancellationToken.ThrowIfCancellationRequested();
            var validation = validationPath is null ? null : ReadJson<ValidationJson>(validationPath, result, "validation.json");
            cancellationToken.ThrowIfCancellationRequested();
            var strings = stringsPath is null ? null : ReadJson<StringsJson>(stringsPath, result, "strings.json");

            if (assetsPath is not null) sourceFiles["assets"] = assetsPath;
            if (layoutPath is not null) sourceFiles["layout"] = layoutPath;
            if (bindingsPath is not null) sourceFiles["bindings"] = bindingsPath;
            if (codegenPath is not null) sourceFiles["codegen"] = codegenPath;
            if (validationPath is not null) sourceFiles["validation"] = validationPath;
            if (stringsPath is not null) sourceFiles["strings"] = stringsPath;

            return assets is null || layout is null || bindings is null || codegen is null || validation is null
                ? null
                : new ManifestPackage
                {
                    ProjectRoot = projectRoot,
                    PackagePath = packagePath,
                    DirectoryPath = packageDir,
                    Package = package,
                    Layout = layout,
                    Bindings = bindings,
                    Assets = assets,
                    Codegen = codegen,
                    Validation = validation,
                    Strings = strings,
                    SourceFiles = sourceFiles,
                };
        }

        public string SystemName => string.IsNullOrWhiteSpace(Package.Godot.SystemName)
            ? Names.SystemNameFromPackageId(Package.PackageId)
            : Package.Godot.SystemName;

        public string GetOutputDir()
        {
            var configured = string.IsNullOrWhiteSpace(Package.Godot.OutputDir)
                ? Path.Combine("generated", "ui", SystemName)
                : Package.Godot.OutputDir;
            return Path.GetFullPath(configured, ProjectRoot);
        }

        public string GetNamespace()
        {
            return string.IsNullOrWhiteSpace(Package.Godot.Namespace)
                ? $"GodotUi.Generated.{Names.Pascal(SystemName)}"
                : Package.Godot.Namespace;
        }

        public void Validate(ValidationResult result, CancellationToken cancellationToken = default)
        {
            _cancellationToken = cancellationToken;
            ThrowIfCancellationRequested();
            ValidatePackage(result);
            ThrowIfCancellationRequested();
            ValidateSchemaSnapshots(result);
            ThrowIfCancellationRequested();
            ValidateStrings(result);
            ThrowIfCancellationRequested();
            ValidateLayout(result);
            ThrowIfCancellationRequested();
            ValidateBindings(result);
            ThrowIfCancellationRequested();
            ValidateAssets(result);
            ThrowIfCancellationRequested();
            ValidateCodegen(result);
            ThrowIfCancellationRequested();
            ValidateValidationManifest(result);
        }

        private void ThrowIfCancellationRequested()
        {
            _cancellationToken.ThrowIfCancellationRequested();
        }

        public List<PropertyBinding> GetPropertyBindings()
        {
            var result = new List<PropertyBinding>();
            foreach (var (key, value) in Bindings.Bindings)
            {
                if (TryReadPropertyBinding(key, value, null, out var binding) && binding is not null)
                {
                    result.Add(binding);
                }
            }
            return result;
        }

        public List<RepeaterBinding> GetRepeaters()
        {
            return Bindings.Repeaters.Select(repeater => new RepeaterBinding(
                repeater.Target,
                repeater.Template,
                StripSourcePrefix(repeater.Source, "viewmodel:"),
                repeater.Bindings.Select(kvp => ReadItemBinding(kvp.Key, kvp.Value)).Where(binding => binding is not null).Cast<ItemBinding>().ToList(),
                repeater.KeyFieldId,
                repeater.PoolCapacity)).ToList();
        }

        public List<LocalizedProperty> GetLocalizedProperties()
        {
            var result = new List<LocalizedProperty>();
            Collect(Layout.Root, ".");
            return result;

            void Collect(LayoutNode node, string nodePath)
            {
                foreach (var (property, value) in node.Localization.OrderBy(pair => pair.Key, StringComparer.Ordinal))
                {
                    if (TryReadLocalizationValue(value, "layout.json", "", null, out var localization))
                    {
                        result.Add(new LocalizedProperty(
                            nodePath,
                            property,
                            localization.Key,
                            localization.Context,
                            localization.ArgumentFieldIds));
                    }
                }
                foreach (var child in node.Children)
                {
                    Collect(child, nodePath == "." ? child.Name : $"{nodePath}/{child.Name}");
                }
            }
        }

        public List<InputBinding> GetInputs()
        {
            return Bindings.Inputs.Select(input => new InputBinding(input.Target, input.Property, StripSourcePrefix(input.Source, "viewmodel:"))).ToList();
        }

        public Dictionary<string, string> GetAssetResourcePaths()
        {
            return GetAssetRefs().ToDictionary(asset => asset.Id, asset => asset.Path, StringComparer.Ordinal);
        }

        public string GetAssetResourcePath(AssetEntry asset)
        {
            return ToResourcePath(ProjectRoot, Path.GetFullPath(Path.Combine(DirectoryPath, asset.RelativePath)));
        }

        public List<GeneratedAssetRef> GetAssetRefs()
        {
            return Assets.Assets
                .Select(asset => new GeneratedAssetRef(asset.Id, asset.Kind, IsThemeKind(asset.Kind) ? GetThemeOutputResourcePath(asset) : GetAssetResourcePath(asset)))
                .ToList();
        }

        public AssetEntry? GetThemeAsset()
        {
            return Assets.Assets.FirstOrDefault(asset => IsThemeKind(asset.Kind));
        }

        public string GetThemeOutputPath(AssetEntry theme)
        {
            var configured = string.IsNullOrWhiteSpace(theme.Theme.OutputPath)
                ? Path.Combine(GetOutputDir(), "assets", $"{Names.Pascal(SystemName)}Theme.tres")
                : theme.Theme.OutputPath;
            return Path.GetFullPath(configured, ProjectRoot);
        }

        public string GetThemeOutputResourcePath(AssetEntry theme)
        {
            return ToResourcePath(ProjectRoot, GetThemeOutputPath(theme));
        }

        private static string NormalizeProperty(string property)
        {
            return string.Equals(property, "visibility", StringComparison.Ordinal) ? "visible" : property;
        }

        private static string StripSourcePrefix(string source, string prefix)
        {
            return source.StartsWith(prefix, StringComparison.Ordinal) ? source[prefix.Length..] : source;
        }

        private static bool IsPropertyCompatible(string property, string nodeType)
        {
            return property switch
            {
                "text" => nodeType is "Label" or "Button" or "LineEdit" or "RichTextLabel",
                "visible" => true,
                "enabled" => nodeType is "Button" or "TextureButton" or "CheckBox" or "CheckButton" or "OptionButton" or "MenuButton" or "LineEdit" or "TextEdit",
                "value" => nodeType is "ProgressBar" or "HSlider" or "VSlider" or "SpinBox" or "TextureProgressBar",
                "texture" => nodeType is "TextureRect" or "TextureButton" or "Button",
                "themeClass" => true,
                _ => false,
            };
        }

        private static bool IsInputCompatible(string property, string nodeType)
        {
            return property switch
            {
                "text" => nodeType is "LineEdit" or "TextEdit",
                "buttonPressed" => nodeType is "CheckBox" or "CheckButton",
                "value" => nodeType is "ProgressBar" or "HSlider" or "VSlider" or "SpinBox" or "TextureProgressBar",
                "selected" => nodeType is "OptionButton",
                _ => false,
            };
        }

        private static bool IsEventCompatible(string signal, string nodeType)
        {
            return signal switch
            {
                "pressed" => nodeType is "Button" or "TextureButton" or "CheckBox" or "CheckButton",
                "text_changed" => nodeType is "LineEdit" or "TextEdit",
                "toggled" => nodeType is "CheckBox" or "CheckButton",
                "value_changed" => nodeType is "ProgressBar" or "HSlider" or "VSlider" or "SpinBox" or "TextureProgressBar",
                "item_selected" => nodeType is "OptionButton",
                "tab_changed" => nodeType is "TabContainer",
                _ => false,
            };
        }

        private static bool IsFieldTypeCompatible(string property, string fieldType)
        {
            return property switch
            {
                "text" or "themeClass" => fieldType is "text" or "number" or "bool" or "object",
                "visible" or "enabled" => fieldType is "bool" or "text" or "number",
                "value" => fieldType is "number" or "text",
                "texture" => fieldType is "assetRef" or "text" or "object",
                _ => false,
            };
        }

        private static bool IsTextureKind(string kind)
        {
            return string.Equals(kind, "texture", StringComparison.OrdinalIgnoreCase);
        }

        private static bool IsFontKind(string kind)
        {
            return string.Equals(kind, "font", StringComparison.OrdinalIgnoreCase);
        }

        private static bool IsThemeKind(string kind)
        {
            return string.Equals(kind, "theme", StringComparison.OrdinalIgnoreCase);
        }

        private static bool IsResourceKind(string kind)
        {
            return string.Equals(kind, "resource", StringComparison.OrdinalIgnoreCase);
        }

        private static bool IsKnownAssetKind(string kind)
        {
            return IsTextureKind(kind) || IsFontKind(kind) || IsThemeKind(kind) || IsResourceKind(kind);
        }

        private static bool IsExtensionCompatible(string kind, string path)
        {
            var extension = Path.GetExtension(path).ToLowerInvariant();
            if (IsTextureKind(kind))
            {
                return extension is ".png" or ".jpg" or ".jpeg" or ".webp" or ".svg" or ".tres";
            }
            if (IsFontKind(kind))
            {
                return extension is ".ttf" or ".otf" or ".tres";
            }
            if (IsThemeKind(kind))
            {
                return extension is ".json" or ".tres";
            }
            if (IsResourceKind(kind))
            {
                return extension is ".tres" or ".res";
            }
            return false;
        }

        private static bool IsScriptedControl(LayoutNode node)
        {
            return !string.IsNullOrWhiteSpace(node.ScriptPath);
        }

        public List<EventBinding> GetEvents()
        {
            var events = new List<EventBinding>();
            var channels = GetChannels()
                .Where(channel => !string.IsNullOrWhiteSpace(channel.Id))
                .GroupBy(channel => channel.Id, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.First(), StringComparer.Ordinal);
            foreach (var control in Bindings.Controls)
            {
                foreach (var evt in control.Events)
                {
                    channels.TryGetValue(evt.Channel, out var channel);
                    events.Add(new EventBinding
                    {
                        EventId = string.IsNullOrWhiteSpace(evt.Handler) ? evt.Event : evt.Handler,
                        Target = control.Target,
                        Signal = evt.Event,
                        Channel = evt.Channel,
                        Scope = channel?.Scope ?? "",
                        Dispatch = channel?.Dispatch ?? "immediate",
                    });
                }
            }

            return events;
        }

        private void ValidatePackage(ValidationResult result)
        {
            ValidateUnsupported(Package.Extra, "package.json", "", result);
            ValidateUnsupported(Package.Runtime.Extra, "package.json", "runtime", result);
            ValidateUnsupported(Package.Godot.Extra, "package.json", "godot", result);
            if (Package.SchemaVersion != CurrentSchemaVersion)
            {
                result.Error("package.json", "schemaVersion", $"expected {CurrentSchemaVersion}, got {Package.SchemaVersion}");
            }

            Required(Package.PackageId, "package.json", "packageId", result);
            Required(Package.DisplayName, "package.json", "displayName", result);
            Required(Package.Assets, "package.json", "assets", result);
            Required(Package.Layout, "package.json", "layout", result);
            Required(Package.Bindings, "package.json", "bindings", result);
            Required(Package.Codegen, "package.json", "codegen", result);
            Required(Package.Validation, "package.json", "validation", result);
            if (Package.Runtime.ControllerScope is not ("instance" or "screen" or "package"))
            {
                result.Error("package.json", "runtime.controllerScope", "must be instance, screen, or package");
            }

            if (Package.DesignResolution.Length != 2 || Package.DesignResolution.Any(x => x <= 0))
            {
                result.Error("package.json", "designResolution", "must be [width, height] with positive integers");
            }

            Required(Package.Godot.WidgetClass, "package.json", "godot.widgetClass", result);
            if (!string.IsNullOrWhiteSpace(Package.Godot.WidgetClass) && !IsCSharpIdentifier(Package.Godot.WidgetClass))
            {
                result.Error("package.json", "godot.widgetClass", "must be a valid C# type identifier");
            }
            Required(Package.Godot.ControllerClass, "package.json", "godot.controllerClass", result);
            if (!string.IsNullOrWhiteSpace(Package.Godot.ControllerClass) && !IsDotNetTypeName(Package.Godot.ControllerClass))
            {
                result.Error("package.json", "godot.controllerClass", "must be a valid fully-qualified C# type name");
            }
            Required(Package.Godot.ScenePath, "package.json", "godot.scenePath", result);
            ValidateProjectRelativePath(ProjectRoot, Package.Godot.OutputDir, "package.json", "godot.outputDir", result);
            if (!IsInside(ProjectRoot, GetOutputDir()))
            {
                result.Error("package.json", "godot.outputDir", "must stay inside the project directory");
            }
            ValidateGodotScenePath(result);
            if (!IsDotNetNamespace(GetNamespace()))
            {
                var path = string.IsNullOrWhiteSpace(Package.Godot.Namespace) ? "godot.systemName" : "godot.namespace";
                result.Error("package.json", path, "must produce a valid C# namespace");
            }
            if (string.IsNullOrWhiteSpace(SystemName)
                || SystemName is "." or ".."
                || SystemName.IndexOfAny(Path.GetInvalidFileNameChars()) >= 0
                || SystemName.Contains('/')
                || SystemName.Contains('\\'))
            {
                result.Error("package.json", "godot.systemName", "must be a safe file and directory name");
            }
        }

        private void ValidateSchemaSnapshots(ValidationResult result)
        {
            var sharedDir = SchemaFiles.FindBundledDirectory(ProjectRoot);
            if (sharedDir is null)
            {
                result.EnvironmentError("schemas", "source", "bundled schema directory is missing");
                return;
            }
            var localDir = Path.Combine(DirectoryPath, "schemas");
            foreach (var schemaFile in SchemaFiles.All)
            {
                ThrowIfCancellationRequested();
                var sharedPath = Path.Combine(sharedDir, schemaFile);
                var localPath = Path.Combine(localDir, schemaFile);
                if (!File.Exists(localPath))
                {
                    continue;
                }

                if (NormalizeText(File.ReadAllText(sharedPath)) != NormalizeText(File.ReadAllText(localPath)))
                {
                    result.Error("schemas", schemaFile, "local schema snapshot differs from shared schema");
                }
            }
        }

        private void ValidateLayout(ValidationResult result)
        {
            ValidateUnsupported(Layout.Extra, "layout.json", "", result);
            if (Layout.Root is null)
            {
                result.Error("layout.json", "root", "is required");
                return;
            }

            _nodeByPath.Clear();
            _nodeById.Clear();
            CollectNodes(Layout.Root, "", "root", result);
        }

        private void CollectNodes(LayoutNode node, string parentPath, string logicalPath, ValidationResult result)
        {
            ThrowIfCancellationRequested();
            ValidateUnsupported(node.Extra, "layout.json", logicalPath, result);
            Required(node.Id, "layout.json", $"{logicalPath}.id", result);
            Required(node.Type, "layout.json", $"{logicalPath}.type", result);
            Required(node.Name, "layout.json", $"{logicalPath}.name", result);
            if (!string.IsNullOrWhiteSpace(node.Name)
                && (node.Name.IndexOfAny(new[] { '.', ':', '@', '/', '\"', '%' }) >= 0 || node.Name.Any(char.IsControl)))
            {
                result.Error("layout.json", $"{logicalPath}.name", "contains characters that are not safe in a Godot node name");
            }
            foreach (var (property, value) in node.Properties)
            {
                Required(property, "layout.json", $"{logicalPath}.properties", result);
                if (value.ValueKind != JsonValueKind.Object)
                {
                    continue;
                }

                var propertyPath = $"{logicalPath}.properties.{property}";
                if (!TryReadAssetReference(value, out var assetId))
                {
                    result.Error("layout.json", propertyPath, "object property values must use { \"assetRef\": \"<asset-id>\" }");
                    continue;
                }

                var asset = Assets.Assets.FirstOrDefault(candidate => string.Equals(candidate.Id, assetId, StringComparison.Ordinal));
                if (asset is null)
                {
                    result.Error("layout.json", propertyPath, $"unknown asset reference '{assetId}'");
                }
                else if (!IsKnownAssetKind(asset.Kind))
                {
                    result.Error("layout.json", propertyPath, $"asset '{assetId}' has unsupported kind '{asset.Kind}'");
                }
            }
            foreach (var (property, value) in node.Localization)
            {
                Required(property, "layout.json", $"{logicalPath}.localization", result);
                var localizationPath = $"{logicalPath}.localization.{property}";
                if (!TryReadLocalizationValue(value, "layout.json", localizationPath, result, out var localization))
                {
                    continue;
                }
                if (Strings is not null && !Strings.Strings.ContainsKey(localization.Key))
                {
                    result.Error("layout.json", localizationPath, $"unknown localization key '{localization.Key}'");
                }
                else if (Strings is null)
                {
                    result.Error("layout.json", localizationPath, "localization requires package.strings");
                }
                var fieldIds = Bindings.Mvvm.Fields.Select(field => field.Id).ToHashSet(StringComparer.Ordinal);
                for (var i = 0; i < localization.ArgumentFieldIds.Count; i++)
                {
                    if (!fieldIds.Contains(localization.ArgumentFieldIds[i]))
                    {
                        result.Error(
                            "layout.json",
                            $"{localizationPath}.arguments[{i}]",
                            $"unknown mvvm field '{localization.ArgumentFieldIds[i]}'");
                    }
                }
            }
            if (string.Equals(node.Type, "SceneInstance", StringComparison.Ordinal))
            {
                Required(node.ScenePath, "layout.json", $"{logicalPath}.scenePath", result);
                ValidateResourceScenePath(node.ScenePath, "layout.json", $"{logicalPath}.scenePath", result);
            }
            if (!string.IsNullOrWhiteSpace(node.ScriptPath))
            {
                if (logicalPath == "root")
                {
                    result.Error("layout.json", $"{logicalPath}.scriptPath", "the generated widget root cannot also bind a scripted-control script");
                }
                if (!string.Equals(node.Type, "Control", StringComparison.Ordinal))
                {
                    result.Error("layout.json", $"{logicalPath}.type", "scripted-control nodes must use base type Control");
                }
                ValidateResourceScriptPath(node.ScriptPath, "layout.json", $"{logicalPath}.scriptPath", result);
            }

            var path = string.IsNullOrWhiteSpace(parentPath) ? node.Name : $"{parentPath}/{node.Name}";
            var relativePath = path.StartsWith(Layout.Root.Name + "/", StringComparison.Ordinal)
                ? path[(Layout.Root.Name.Length + 1)..]
                : path;

            if (!string.Equals(relativePath, Layout.Root.Name, StringComparison.Ordinal) && !_nodeByPath.TryAdd(relativePath, node))
            {
                result.Error("layout.json", $"{logicalPath}.name", $"duplicate node path '{relativePath}'");
            }

            if (!string.IsNullOrWhiteSpace(node.Id) && !_nodeById.TryAdd(node.Id, node))
            {
                result.Error("layout.json", $"{logicalPath}.id", $"duplicate node id '{node.Id}'");
            }

            for (var i = 0; i < node.Children.Count; i++)
            {
                CollectNodes(node.Children[i], path, $"{logicalPath}.children[{i}]", result);
            }
        }

        private void ValidateResourceScenePath(string scenePath, string file, string logicalPath, ValidationResult result)
        {
            if (string.IsNullOrWhiteSpace(scenePath))
            {
                return;
            }

            const string prefix = "res://";
            if (!scenePath.StartsWith(prefix, StringComparison.Ordinal))
            {
                result.Error(file, logicalPath, "must start with res://");
                return;
            }

            var relativePath = scenePath[prefix.Length..].Replace('/', Path.DirectorySeparatorChar);
            if (Path.IsPathRooted(relativePath))
            {
                result.Error(file, logicalPath, "must be project-relative");
                return;
            }

            var root = ProjectRoot;
            var resolved = Path.GetFullPath(Path.Combine(root, relativePath));
            var relative = Path.GetRelativePath(root, resolved);
            if (relative == ".." || relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
            {
                result.Error(file, logicalPath, "must stay inside the project directory");
                return;
            }

            if (!string.Equals(Path.GetExtension(resolved), ".tscn", StringComparison.OrdinalIgnoreCase))
            {
                result.Error(file, logicalPath, "must point to a .tscn scene");
            }

            if (!File.Exists(resolved))
            {
                result.Error(file, logicalPath, $"file does not exist: {scenePath}");
            }
        }

        private void ValidateResourceScriptPath(string scriptPath, string file, string logicalPath, ValidationResult result)
        {
            const string prefix = "res://";
            if (!scriptPath.StartsWith(prefix, StringComparison.Ordinal))
            {
                result.Error(file, logicalPath, "must start with res://");
                return;
            }
            var relativePath = scriptPath[prefix.Length..].Replace('/', Path.DirectorySeparatorChar);
            if (Path.IsPathRooted(relativePath))
            {
                result.Error(file, logicalPath, "must be project-relative");
                return;
            }
            var resolved = Path.GetFullPath(relativePath, ProjectRoot);
            if (!IsInside(ProjectRoot, resolved))
            {
                result.Error(file, logicalPath, "must stay inside the project directory");
                return;
            }
            if (Path.GetExtension(resolved).ToLowerInvariant() is not (".cs" or ".gd"))
            {
                result.Error(file, logicalPath, "must point to a .cs or .gd script");
            }
            if (!File.Exists(resolved))
            {
                result.Error(file, logicalPath, $"file does not exist: {scriptPath}");
            }
        }

        private void ValidateBindings(ValidationResult result)
        {
            if (Bindings.Extra.Keys.Any(key => string.Equals(key, "fields", StringComparison.OrdinalIgnoreCase)))
            {
                result.Error("bindings.json", "fields", "legacy top-level fields are not supported in schemaVersion 1; use bindings");
            }

            var mvvmTypes = new Dictionary<string, string>(StringComparer.Ordinal);
            var mvvmCollections = new Dictionary<string, string>(StringComparer.Ordinal);
            if (!string.IsNullOrWhiteSpace(Bindings.Mvvm.UpdatePolicy)
                && Bindings.Mvvm.UpdatePolicy is not ("manual" or "immediate" or "deferred"))
            {
                result.Error("bindings.json", "mvvm.updatePolicy", "must be manual, immediate, or deferred");
            }
            for (var i = 0; i < Bindings.Mvvm.Fields.Count; i++)
            {
                ThrowIfCancellationRequested();
                var field = Bindings.Mvvm.Fields[i];
                Required(field.Id, "bindings.json", $"mvvm.fields[{i}].id", result);
                Required(field.Path, "bindings.json", $"mvvm.fields[{i}].path", result);
                Required(field.Value, "bindings.json", $"mvvm.fields[{i}].value", result);
                if (!string.IsNullOrWhiteSpace(field.Value) && !AllowedFieldTypes.Contains(field.Value))
                {
                    result.Error("bindings.json", $"mvvm.fields[{i}].value", "must be one of text, bool, number, assetRef, object");
                }
                if (!string.IsNullOrWhiteSpace(field.Id) && !mvvmTypes.TryAdd(field.Id, field.Value))
                {
                    result.Error("bindings.json", $"mvvm.fields[{i}].id", $"duplicate field id '{field.Id}'");
                }
                if (!string.IsNullOrWhiteSpace(field.Id))
                {
                    mvvmCollections[field.Id] = field.Collection;
                }
                if (field.ControllerOnlySideEffect)
                {
                    result.Error(
                        "bindings.json",
                        $"mvvm.fields[{i}].controllerOnlySideEffect",
                        "controllerOnlySideEffect is not supported in schemaVersion 1",
                        0,
                        0,
                        "Remove the field or set it to false until controller-only field semantics are implemented.");
                }
            }

            ValidateCanonicalPropertyBindings(result, mvvmTypes);
            ValidateRepeaters(result, mvvmTypes, mvvmCollections);
            ValidateInputs(result, mvvmTypes);
            ValidateEvents(result);
            ValidateGeneratedMemberNames(result);
        }

        private void ValidateCanonicalPropertyBindings(ValidationResult result, Dictionary<string, string> mvvmTypes)
        {
            foreach (var (key, value) in Bindings.Bindings)
            {
                ThrowIfCancellationRequested();
                if (!TryReadPropertyBinding(key, value, result, out var binding) || binding is null)
                {
                    continue;
                }

                if (!NodeByPath.TryGetValue(binding.Target, out var targetNode))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"unknown layout target '{binding.Target}'");
                    continue;
                }
                if (!SupportedProperties.Contains(NormalizeProperty(binding.Property)))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"unsupported property '{binding.Property}'");
                }
                if (!IsScriptedControl(targetNode) && !IsPropertyCompatible(NormalizeProperty(binding.Property), targetNode.Type))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"property '{binding.Property}' is not supported on {targetNode.Type}");
                }
                if (!mvvmTypes.TryGetValue(binding.FieldId, out var fieldType))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"unknown mvvm field '{binding.FieldId}'");
                }
                else if (!IsFieldTypeCompatible(NormalizeProperty(binding.Property), fieldType))
                {
                    result.Error("bindings.json", $"bindings.{key}", $"field type '{fieldType}' is not compatible with property '{binding.Property}'");
                }
                if (!string.IsNullOrWhiteSpace(binding.Converter) && !KnownConverters.Contains(binding.Converter))
                {
                    result.Error("bindings.json", $"bindings.{key}.converter", $"unknown converter '{binding.Converter}'");
                }
                if (NormalizeProperty(binding.Property) == "texture"
                    && binding.Fallback is { ValueKind: JsonValueKind.String } fallback
                    && !IsTextureReferenceValid(fallback.GetString() ?? ""))
                {
                    result.Error("bindings.json", $"bindings.{key}.fallback", $"unknown texture asset '{fallback.GetString()}'");
                }
            }
        }

        private void ValidateRepeaters(ValidationResult result, Dictionary<string, string> mvvmTypes, Dictionary<string, string> mvvmCollections)
        {
            var ids = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < Bindings.Repeaters.Count; i++)
            {
                ThrowIfCancellationRequested();
                var repeater = Bindings.Repeaters[i];
                var label = $"repeaters[{i}]";
                ValidateUnsupported(repeater.Extra, "bindings.json", label, result);
                Required(repeater.Id, "bindings.json", $"{label}.id", result);
                Required(repeater.Target, "bindings.json", $"{label}.target", result);
                Required(repeater.Template, "bindings.json", $"{label}.template", result);
                Required(repeater.Source, "bindings.json", $"{label}.source", result);
                if (!string.IsNullOrWhiteSpace(repeater.Id) && !ids.Add(repeater.Id))
                {
                    result.Error("bindings.json", $"{label}.id", $"duplicate repeater id '{repeater.Id}'");
                }
                if (!NodeByPath.ContainsKey(repeater.Target))
                {
                    result.Error("bindings.json", $"{label}.target", $"unknown layout target '{repeater.Target}'");
                }
                if (!NodeByPath.ContainsKey(repeater.Template))
                {
                    result.Error("bindings.json", $"{label}.template", $"unknown template path '{repeater.Template}'");
                }
                else if (!string.IsNullOrWhiteSpace(repeater.Target) && !repeater.Template.StartsWith(repeater.Target + "/", StringComparison.Ordinal))
                {
                    result.Error("bindings.json", $"{label}.template", "must be a child of target");
                }
                var fieldId = StripSourcePrefix(repeater.Source, "viewmodel:");
                if (!repeater.Source.StartsWith("viewmodel:", StringComparison.Ordinal))
                {
                    result.Error("bindings.json", $"{label}.source", "must use viewmodel:<fieldId>");
                }
                else if (!mvvmTypes.ContainsKey(fieldId))
                {
                    result.Error("bindings.json", $"{label}.source", $"unknown mvvm field '{fieldId}'");
                }
                else if (!mvvmCollections.TryGetValue(fieldId, out var collection) || string.IsNullOrWhiteSpace(collection) || collection == "none")
                {
                    result.Error("bindings.json", $"{label}.source", $"field '{fieldId}' must declare collection");
                }
                if (repeater.PoolCapacity < 0)
                {
                    result.Error("bindings.json", $"{label}.poolCapacity", "must be zero or greater");
                }

                foreach (var (key, value) in repeater.Bindings)
                {
                    if (!TryReadItemBinding(key, value, result, out var binding) || binding is null)
                    {
                        continue;
                    }

                    var absoluteTarget = string.IsNullOrWhiteSpace(binding.Target) || binding.Target == "."
                        ? repeater.Template
                        : $"{repeater.Template}/{binding.Target}";
                    if (!NodeByPath.TryGetValue(absoluteTarget, out var targetNode))
                    {
                        result.Error("bindings.json", $"{label}.bindings.{key}", $"unknown template target '{binding.Target}'");
                        continue;
                    }
                    if (!SupportedProperties.Contains(NormalizeProperty(binding.Property)))
                    {
                        result.Error("bindings.json", $"{label}.bindings.{key}", $"unsupported property '{binding.Property}'");
                    }
                    if (!IsScriptedControl(targetNode) && !IsPropertyCompatible(NormalizeProperty(binding.Property), targetNode.Type))
                    {
                        result.Error("bindings.json", $"{label}.bindings.{key}", $"property '{binding.Property}' is not supported on {targetNode.Type}");
                    }
                    if (!string.IsNullOrWhiteSpace(binding.Converter) && !KnownConverters.Contains(binding.Converter))
                    {
                        result.Error("bindings.json", $"{label}.bindings.{key}.converter", $"unknown converter '{binding.Converter}'");
                    }
                }
            }
        }

        private void ValidateInputs(ValidationResult result, Dictionary<string, string> mvvmTypes)
        {
            var ids = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < Bindings.Inputs.Count; i++)
            {
                ThrowIfCancellationRequested();
                var input = Bindings.Inputs[i];
                var label = $"inputs[{i}]";
                Required(input.Id, "bindings.json", $"{label}.id", result);
                Required(input.Target, "bindings.json", $"{label}.target", result);
                Required(input.Property, "bindings.json", $"{label}.property", result);
                Required(input.Source, "bindings.json", $"{label}.source", result);
                if (!string.IsNullOrWhiteSpace(input.Id) && !ids.Add(input.Id))
                {
                    result.Error("bindings.json", $"{label}.id", $"duplicate input id '{input.Id}'");
                }
                if (!NodeByPath.TryGetValue(input.Target, out var targetNode))
                {
                    result.Error("bindings.json", $"{label}.target", $"unknown layout target '{input.Target}'");
                    continue;
                }
                if (!SupportedInputProperties.Contains(input.Property))
                {
                    result.Error("bindings.json", $"{label}.property", $"unsupported input property '{input.Property}'");
                }
                else if (!IsScriptedControl(targetNode) && !IsInputCompatible(input.Property, targetNode.Type))
                {
                    result.Error("bindings.json", $"{label}.property", $"property '{input.Property}' is not supported on {targetNode.Type}");
                }
                var fieldId = StripSourcePrefix(input.Source, "viewmodel:");
                if (!input.Source.StartsWith("viewmodel:", StringComparison.Ordinal))
                {
                    result.Error("bindings.json", $"{label}.source", "must use viewmodel:<fieldId>");
                }
                else if (!mvvmTypes.ContainsKey(fieldId))
                {
                    result.Error("bindings.json", $"{label}.source", $"unknown mvvm field '{fieldId}'");
                }
            }
        }

        private bool TryReadPropertyBinding(string key, JsonElement value, ValidationResult? result, out PropertyBinding? binding)
        {
            binding = null;
            var dot = key.LastIndexOf('.');
            if (dot <= 0 || dot == key.Length - 1)
            {
                result?.Error("bindings.json", $"bindings.{key}", "key must be <node-path>.<property>");
                return false;
            }

            var source = "";
            var converter = "";
            var format = "";
            JsonElement? fallback = null;
            switch (value.ValueKind)
            {
                case JsonValueKind.String:
                    source = value.GetString() ?? "";
                    break;
                case JsonValueKind.Object:
                    if (!value.TryGetProperty("source", out var sourceElement) || sourceElement.ValueKind != JsonValueKind.String)
                    {
                        result?.Error("bindings.json", $"bindings.{key}.source", "is required");
                        return false;
                    }
                    source = sourceElement.GetString() ?? "";
                    if (value.TryGetProperty("converter", out var converterElement) && converterElement.ValueKind == JsonValueKind.String)
                    {
                        converter = converterElement.GetString() ?? "";
                    }
                    if (value.TryGetProperty("format", out var formatElement) && formatElement.ValueKind == JsonValueKind.String)
                    {
                        format = formatElement.GetString() ?? "";
                    }
                    if (value.TryGetProperty("fallback", out var fallbackElement))
                    {
                        fallback = fallbackElement;
                    }
                    break;
                default:
                    result?.Error("bindings.json", $"bindings.{key}", "value must be a viewmodel string or binding object");
                    return false;
            }

            const string prefix = "viewmodel:";
            if (!source.StartsWith(prefix, StringComparison.Ordinal))
            {
                result?.Error("bindings.json", $"bindings.{key}", "source must use viewmodel:<fieldId>");
                return false;
            }

            binding = new PropertyBinding(key[..dot], key[(dot + 1)..], source[prefix.Length..], converter, format, fallback);
            return true;
        }

        private static ItemBinding? ReadItemBinding(string key, JsonElement value)
        {
            return TryReadItemBinding(key, value, null, out var binding) ? binding : null;
        }

        private static bool TryReadItemBinding(string key, JsonElement value, ValidationResult? result, out ItemBinding? binding)
        {
            binding = null;
            var dot = key.LastIndexOf('.');
            if (dot < 0 || dot == key.Length - 1)
            {
                result?.Error("bindings.json", $"repeaters.bindings.{key}", "key must be <template-node-path>.<property>");
                return false;
            }

            var source = "";
            var converter = "";
            var format = "";
            JsonElement? fallback = null;
            switch (value.ValueKind)
            {
                case JsonValueKind.String:
                    source = value.GetString() ?? "";
                    break;
                case JsonValueKind.Object:
                    if (!value.TryGetProperty("source", out var sourceElement) || sourceElement.ValueKind != JsonValueKind.String)
                    {
                        result?.Error("bindings.json", $"repeaters.bindings.{key}.source", "is required");
                        return false;
                    }
                    source = sourceElement.GetString() ?? "";
                    if (value.TryGetProperty("converter", out var converterElement) && converterElement.ValueKind == JsonValueKind.String)
                    {
                        converter = converterElement.GetString() ?? "";
                    }
                    if (value.TryGetProperty("format", out var formatElement) && formatElement.ValueKind == JsonValueKind.String)
                    {
                        format = formatElement.GetString() ?? "";
                    }
                    if (value.TryGetProperty("fallback", out var fallbackElement))
                    {
                        fallback = fallbackElement;
                    }
                    break;
                default:
                    result?.Error("bindings.json", $"repeaters.bindings.{key}", "value must be an item string or binding object");
                    return false;
            }

            const string prefix = "item:";
            if (!source.StartsWith(prefix, StringComparison.Ordinal))
            {
                result?.Error("bindings.json", $"repeaters.bindings.{key}", "source must use item:<fieldId>");
                return false;
            }

            binding = new ItemBinding(key[..dot], key[(dot + 1)..], source[prefix.Length..], converter, format, fallback);
            return true;
        }

        private bool IsTextureReferenceValid(string value)
        {
            return string.IsNullOrEmpty(value)
                || value.StartsWith("res://", StringComparison.Ordinal)
                || Assets.Assets.Any(asset => string.Equals(asset.Id, value, StringComparison.Ordinal) && IsTextureKind(asset.Kind));
        }

        private void ValidateEvents(ValidationResult result)
        {
            if (Bindings.Events.ValueKind == JsonValueKind.Array)
            {
                result.Error("bindings.json", "events", "legacy array-form events are not supported in schemaVersion 1; use controls and events.channels");
            }

            var channels = GetChannels();
            var channelIds = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < channels.Count; i++)
            {
                ThrowIfCancellationRequested();
                ValidateUnsupported(channels[i].Extra, "bindings.json", $"events.channels[{i}]", result);
                Required(channels[i].Id, "bindings.json", $"events.channels[{i}].id", result);
                Required(channels[i].Scope, "bindings.json", $"events.channels[{i}].scope", result);
                Required(channels[i].Dispatch, "bindings.json", $"events.channels[{i}].dispatch", result);
                if (!string.IsNullOrWhiteSpace(channels[i].Dispatch) && channels[i].Dispatch is not ("immediate" or "deferred"))
                {
                    result.Error("bindings.json", $"events.channels[{i}].dispatch", "must be immediate or deferred");
                }
                if (channels[i].Payload.Count > 0)
                {
                    result.Error(
                        "bindings.json",
                        $"events.channels[{i}].payload",
                        "declared event payload fields are not supported in schemaVersion 1",
                        0,
                        0,
                        "Use an empty payload array; generated events publish an empty Variant payload.");
                }
                if (!string.IsNullOrWhiteSpace(channels[i].Id) && !channelIds.Add(channels[i].Id))
                {
                    result.Error("bindings.json", $"events.channels[{i}].id", $"duplicate channel '{channels[i].Id}'");
                }
            }

            var controlIds = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < Bindings.Controls.Count; i++)
            {
                ThrowIfCancellationRequested();
                var control = Bindings.Controls[i];
                Required(control.Id, "bindings.json", $"controls[{i}].id", result);
                Required(control.Target, "bindings.json", $"controls[{i}].target", result);
                if (!string.IsNullOrWhiteSpace(control.Id) && !controlIds.Add(control.Id))
                {
                    result.Error("bindings.json", $"controls[{i}].id", $"duplicate control id '{control.Id}'");
                }
                LayoutNode? targetNode = null;
                if (!string.IsNullOrWhiteSpace(control.Target) && !NodeByPath.ContainsKey(control.Target))
                {
                    result.Error("bindings.json", $"controls[{i}].target", $"unknown layout target '{control.Target}'");
                }
                else if (!string.IsNullOrWhiteSpace(control.Target))
                {
                    targetNode = NodeByPath[control.Target];
                    if (!IsScriptedControl(targetNode)
                        && !string.IsNullOrWhiteSpace(control.WidgetClass)
                        && !string.Equals(control.WidgetClass, targetNode.Type, StringComparison.Ordinal))
                    {
                        result.Error("bindings.json", $"controls[{i}].widgetClass", $"must match layout node type '{targetNode.Type}'");
                    }
                }
                for (var j = 0; j < control.Events.Count; j++)
                {
                    ThrowIfCancellationRequested();
                    var evt = control.Events[j];
                    Required(evt.Event, "bindings.json", $"controls[{i}].events[{j}].event", result);
                    Required(evt.Handler, "bindings.json", $"controls[{i}].events[{j}].handler", result);
                    Required(evt.Channel, "bindings.json", $"controls[{i}].events[{j}].channel", result);
                    if (targetNode is not null && !IsScriptedControl(targetNode) && !IsEventCompatible(evt.Event, targetNode.Type))
                    {
                        result.Error("bindings.json", $"controls[{i}].events[{j}].event", $"event '{evt.Event}' is not supported on {targetNode.Type}");
                    }
                    if (!string.IsNullOrWhiteSpace(evt.Channel) && !channelIds.Contains(evt.Channel))
                    {
                        result.Error("bindings.json", $"controls[{i}].events[{j}].channel", $"undeclared channel '{evt.Channel}'");
                    }
                }
            }
        }

        private void ValidateGeneratedMemberNames(ValidationResult result)
        {
            var targets = new List<(string Target, string LogicalPath)>();
            foreach (var key in Bindings.Bindings.Keys.OrderBy(key => key, StringComparer.Ordinal))
            {
                var dot = key.LastIndexOf('.');
                if (dot > 0)
                {
                    targets.Add((key[..dot], $"bindings.{key}"));
                }
            }
            for (var i = 0; i < Bindings.Repeaters.Count; i++)
            {
                targets.Add((Bindings.Repeaters[i].Target, $"repeaters[{i}].target"));
                targets.Add((Bindings.Repeaters[i].Template, $"repeaters[{i}].template"));
            }
            for (var i = 0; i < Bindings.Inputs.Count; i++)
            {
                targets.Add((Bindings.Inputs[i].Target, $"inputs[{i}].target"));
            }
            for (var i = 0; i < Bindings.Controls.Count; i++)
            {
                targets.Add((Bindings.Controls[i].Target, $"controls[{i}].target"));
            }

            var generatedFields = new Dictionary<string, (string Target, string LogicalPath)>(StringComparer.Ordinal);
            var seenTargets = new HashSet<string>(StringComparer.Ordinal);
            foreach (var target in targets.Where(target => !string.IsNullOrWhiteSpace(target.Target)))
            {
                ThrowIfCancellationRequested();
                if (!seenTargets.Add(target.Target) || !NodeByPath.ContainsKey(target.Target))
                {
                    continue;
                }
                var generatedName = Names.Field(target.Target);
                if (generatedFields.TryGetValue(generatedName, out var existing) && existing.Target != target.Target)
                {
                    result.Error(
                        "bindings.json",
                        target.LogicalPath,
                        $"generated node field '{generatedName}' collides for targets '{existing.Target}' and '{target.Target}'",
                        0,
                        0,
                        "Rename one of the target nodes so its final path segment generates a unique C# field name.");
                }
                else
                {
                    generatedFields[generatedName] = target;
                }
            }

            var generatedHandlers = new Dictionary<string, string>(StringComparer.Ordinal);
            for (var i = 0; i < Bindings.Controls.Count; i++)
            {
                ThrowIfCancellationRequested();
                for (var j = 0; j < Bindings.Controls[i].Events.Count; j++)
                {
                    ThrowIfCancellationRequested();
                    var evt = Bindings.Controls[i].Events[j];
                    if (string.IsNullOrWhiteSpace(evt.Event) || string.IsNullOrWhiteSpace(evt.Handler))
                    {
                        continue;
                    }
                    var logicalPath = $"controls[{i}].events[{j}].handler";
                    var generatedName = Names.EventMethod(evt.Handler, evt.Event);
                    if (generatedHandlers.TryGetValue(generatedName, out var existingPath))
                    {
                        result.Error(
                            "bindings.json",
                            logicalPath,
                            $"generated event handler '{generatedName}' collides with {existingPath}",
                            0,
                            0,
                            "Use handler and event names that generate a unique C# method name.");
                    }
                    else
                    {
                        generatedHandlers[generatedName] = logicalPath;
                    }
                }
            }
        }

        private List<EventChannel> GetChannels()
        {
            if (Bindings.Events.ValueKind != JsonValueKind.Object
                || !Bindings.Events.TryGetProperty("channels", out var channels)
                || channels.ValueKind != JsonValueKind.Array)
            {
                return new List<EventChannel>();
            }
            return JsonSerializer.Deserialize<List<EventChannel>>(channels.GetRawText(), JsonOptions) ?? new List<EventChannel>();
        }

        private void ValidateAssets(ValidationResult result)
        {
            ValidateUnsupported(Assets.Extra, "assets.json", "", result);
            var ids = new HashSet<string>(StringComparer.Ordinal);
            var byId = new Dictionary<string, AssetEntry>(StringComparer.Ordinal);
            for (var i = 0; i < Assets.Assets.Count; i++)
            {
                ThrowIfCancellationRequested();
                var asset = Assets.Assets[i];
                var label = $"assets[{i}]";
                Required(asset.Id, "assets.json", $"{label}.id", result);
                Required(asset.RelativePath, "assets.json", $"{label}.relativePath", result);
                Required(asset.Kind, "assets.json", $"{label}.kind", result);
                if (!string.IsNullOrWhiteSpace(asset.Id) && !ids.Add(asset.Id))
                {
                    result.Error("assets.json", $"{label}.id", $"duplicate asset id '{asset.Id}'");
                }
                else if (!string.IsNullOrWhiteSpace(asset.Id))
                {
                    byId[asset.Id] = asset;
                }
                if (!IsKnownAssetKind(asset.Kind))
                {
                    result.Error("assets.json", $"{label}.kind", "must be texture, font, theme, or resource");
                }
                if (!string.IsNullOrWhiteSpace(asset.ContentHash) && !IsSha256(asset.ContentHash))
                {
                    result.Error("assets.json", $"{label}.contentHash", "must be sha256:<64 hex chars>");
                }
                if (asset.Size is not null && (asset.Size.Length != 2 || asset.Size.Any(value => value <= 0)))
                {
                    result.Error("assets.json", $"{label}.size", "must be [width, height] with positive integers");
                }
                foreach (var importKey in asset.Import.Keys.OrderBy(key => key, StringComparer.Ordinal))
                {
                    result.Error(
                        "assets.json",
                        $"{label}.import.{importKey}",
                        $"import metadata '{importKey}' is not supported in schemaVersion 1",
                        0,
                        0,
                        "Configure Godot import settings outside the manifest until import metadata generation is implemented.");
                }

                var path = ResolvePackageFile(DirectoryPath, asset.RelativePath, "assets.json", $"{label}.relativePath", result);
                if (path is null)
                {
                    continue;
                }
                var relative = Path.GetRelativePath(DirectoryPath, path).Replace('\\', '/');
                if (!relative.StartsWith("assets/", StringComparison.Ordinal))
                {
                    result.Error("assets.json", $"{label}.relativePath", "must be under assets/");
                }
                if (!IsExtensionCompatible(asset.Kind, path))
                {
                    result.Error("assets.json", $"{label}.kind", $"kind '{asset.Kind}' is not compatible with extension '{Path.GetExtension(path)}'");
                }
                if (!File.Exists(path))
                {
                    result.Error("assets.json", $"{label}.relativePath", $"file does not exist: {asset.RelativePath}");
                    continue;
                }
                var actual = Sha256File(path);
                if (IsSha256(asset.ContentHash) && asset.ContentHash != actual)
                {
                    result.Error("assets.json", $"{label}.contentHash", $"hash mismatch, expected {asset.ContentHash}, actual {actual}");
                }
            }

            foreach (var (asset, index) in Assets.Assets.Select((asset, index) => (asset, index)).Where(pair => IsThemeKind(pair.asset.Kind)))
            {
                ThrowIfCancellationRequested();
                var label = $"assets[{index}].theme";
                var theme = asset.Theme;
                if (!string.IsNullOrWhiteSpace(theme.OutputPath))
                {
                    ValidateProjectRelativePath(ProjectRoot, theme.OutputPath, "assets.json", $"{label}.outputPath", result);
                    if (!string.Equals(Path.GetExtension(theme.OutputPath), ".tres", StringComparison.OrdinalIgnoreCase))
                    {
                        result.Error("assets.json", $"{label}.outputPath", "must point to a .tres file");
                    }
                }
                if (!string.IsNullOrWhiteSpace(theme.DefaultFontAssetId))
                {
                    if (!byId.TryGetValue(theme.DefaultFontAssetId, out var fontAsset) || !IsFontKind(fontAsset.Kind))
                    {
                        result.Error("assets.json", $"{label}.defaultFontAssetId", $"unknown font asset '{theme.DefaultFontAssetId}'");
                    }
                }
                if (theme.DefaultFontSize < 0)
                {
                    result.Error("assets.json", $"{label}.defaultFontSize", "must be >= 0");
                }
                for (var i = 0; i < theme.TypeVariations.Count; i++)
                {
                    Required(theme.TypeVariations[i].Id, "assets.json", $"{label}.typeVariations[{i}].id", result);
                    Required(theme.TypeVariations[i].BaseType, "assets.json", $"{label}.typeVariations[{i}].baseType", result);
                }
            }
        }

        private void ValidateCodegen(ValidationResult result)
        {
            ValidateUnsupported(Codegen.Extra, "codegen.json", "", result);
            if (Codegen.SchemaVersion != CurrentSchemaVersion)
            {
                result.Error("codegen.json", "schemaVersion", $"expected {CurrentSchemaVersion}, got {Codegen.SchemaVersion}");
            }
            if (!string.IsNullOrWhiteSpace(Codegen.Generator) && Codegen.Generator is not (GeneratorId or "ManifestUiGen"))
            {
                result.Warning($"codegen.json.generator: expected {GeneratorId}, got {Codegen.Generator}");
            }
            var serviceProperties = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < Codegen.RequiredServices.Count; i++)
            {
                ThrowIfCancellationRequested();
                var service = Codegen.RequiredServices[i];
                ValidateUnsupported(service.Extra, "codegen.json", $"requiredServices[{i}]", result);
                Required(service.Type, "codegen.json", $"requiredServices[{i}].type", result);
                Required(service.Property, "codegen.json", $"requiredServices[{i}].property", result);
                if (!string.IsNullOrWhiteSpace(service.Type) && !IsDotNetTypeName(service.Type))
                {
                    result.Error("codegen.json", $"requiredServices[{i}].type", "must be a valid C# type name");
                }
                if (!string.IsNullOrWhiteSpace(service.Property) && !IsCSharpIdentifier(service.Property))
                {
                    result.Error("codegen.json", $"requiredServices[{i}].property", "must be a valid C# identifier");
                }
                else if (!string.IsNullOrWhiteSpace(service.Property) && !serviceProperties.Add(service.Property))
                {
                    result.Error("codegen.json", $"requiredServices[{i}].property", $"duplicate generated property '{service.Property}'");
                }
            }
            for (var i = 0; i < Codegen.Routes.Count; i++)
            {
                ThrowIfCancellationRequested();
                var route = Codegen.Routes[i];
                ValidateUnsupported(route.Extra, "codegen.json", $"routes[{i}]", result);
                Required(route.Channel, "codegen.json", $"routes[{i}].channel", result);
                Required(route.Action, "codegen.json", $"routes[{i}].action", result);
                if (route.Action is not ("open" or "close"))
                {
                    result.Error("codegen.json", $"routes[{i}].action", "must be open or close");
                }
                if (route.Action == "open" && string.IsNullOrWhiteSpace(route.PackageId))
                {
                    result.Error("codegen.json", $"routes[{i}].packageId", "is required for open routes");
                }
            }
            ValidateProjectRelativePath(ProjectRoot, Package.Godot.OutputDir, "package.json", "godot.outputDir", result);
        }

        private void ValidateStrings(ValidationResult result)
        {
            if (Strings is null)
            {
                return;
            }
            ValidateUnsupported(Strings.Extra, "strings.json", "", result);
            if (Strings.SchemaVersion != CurrentSchemaVersion)
            {
                result.Error("strings.json", "schemaVersion", $"expected {CurrentSchemaVersion}, got {Strings.SchemaVersion}");
            }
            Required(Strings.DefaultLocale, "strings.json", "defaultLocale", result);
            var locales = new HashSet<string>(StringComparer.Ordinal);
            for (var i = 0; i < Strings.Locales.Count; i++)
            {
                ThrowIfCancellationRequested();
                Required(Strings.Locales[i], "strings.json", $"locales[{i}]", result);
                if (!string.IsNullOrWhiteSpace(Strings.Locales[i]) && !locales.Add(Strings.Locales[i]))
                {
                    result.Error("strings.json", $"locales[{i}]", $"duplicate locale '{Strings.Locales[i]}'");
                }
            }
            if (!string.IsNullOrWhiteSpace(Strings.DefaultLocale) && !locales.Contains(Strings.DefaultLocale))
            {
                result.Error("strings.json", "defaultLocale", "must be included in locales");
            }
            foreach (var (key, translations) in Strings.Strings)
            {
                ThrowIfCancellationRequested();
                Required(key, "strings.json", "strings", result);
                if (!string.IsNullOrWhiteSpace(Strings.DefaultLocale) && !translations.ContainsKey(Strings.DefaultLocale))
                {
                    result.Error("strings.json", $"strings.{key}", $"default locale '{Strings.DefaultLocale}' is missing");
                }
                foreach (var locale in translations.Keys)
                {
                    if (!locales.Contains(locale))
                    {
                        result.Error("strings.json", $"strings.{key}.{locale}", $"locale '{locale}' is not declared in locales");
                    }
                }
            }
        }

        private void ValidateGodotScenePath(ValidationResult result)
        {
            var scenePath = Package.Godot.ScenePath;
            if (string.IsNullOrWhiteSpace(scenePath))
            {
                return;
            }
            const string prefix = "res://";
            if (!scenePath.StartsWith(prefix, StringComparison.Ordinal))
            {
                result.Error("package.json", "godot.scenePath", "must start with res://");
                return;
            }

            var relativePath = scenePath[prefix.Length..].Replace('/', Path.DirectorySeparatorChar);
            if (Path.IsPathRooted(relativePath))
            {
                result.Error("package.json", "godot.scenePath", "must be project-relative");
                return;
            }

            var root = ProjectRoot;
            var resolved = Path.GetFullPath(Path.Combine(root, relativePath));
            var relative = Path.GetRelativePath(root, resolved);
            if (relative == ".." || relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
            {
                result.Error("package.json", "godot.scenePath", "must stay inside the project directory");
                return;
            }

            if (!string.Equals(Path.GetExtension(resolved), ".tscn", StringComparison.OrdinalIgnoreCase))
            {
                result.Error("package.json", "godot.scenePath", "must point to a .tscn scene");
            }

            if (!string.IsNullOrWhiteSpace(Package.Godot.WidgetClass))
            {
                var expected = Path.Combine(GetOutputDir(), $"{Package.Godot.WidgetClass}.tscn");
                if (!string.Equals(Path.GetFullPath(expected), resolved, StringComparison.OrdinalIgnoreCase))
                {
                    var expectedResourcePath = ToResourcePath(ProjectRoot, expected);
                    result.Error("package.json", "godot.scenePath", $"must match generated scene path {expectedResourcePath}");
                }
            }
        }

        private void ValidateValidationManifest(ValidationResult result)
        {
            ValidateUnsupported(Validation.Extra, "validation.json", "", result);
            foreach (var (check, value) in Validation.Checks.OrderBy(pair => pair.Key, StringComparer.Ordinal))
            {
                ThrowIfCancellationRequested();
                if (check == "manifestValidation")
                {
                    if (value.ValueKind != JsonValueKind.True)
                    {
                        result.Error(
                            "validation.json",
                            $"checks.{check}",
                            "manifestValidation must be true and cannot disable base validation");
                    }
                    continue;
                }
                result.Error(
                    "validation.json",
                    $"checks.{check}",
                    $"validation check '{check}' is not supported in schemaVersion 1",
                    0,
                    0,
                    "Remove the check until the tooling defines and executes it.");
            }
            if (Validation.CommandletInputWhitelist.Count == 0)
            {
                result.Warning("validation.json.commandletInputWhitelist: empty");
                return;
            }
            var inputs = new[] { Package.Assets, Package.Layout, Package.Bindings, Package.Codegen, Package.Validation, Package.Strings }
                .Where(entry => !string.IsNullOrWhiteSpace(entry));
            foreach (var entry in inputs)
            {
                ThrowIfCancellationRequested();
                if (!Validation.CommandletInputWhitelist.Contains(entry, StringComparer.Ordinal))
                {
                    result.Error("validation.json", "commandletInputWhitelist", $"missing {entry}");
                }
            }
        }

        private static void ValidateUnsupported(Dictionary<string, JsonElement> extra, string file, string logicalPath, ValidationResult result)
        {
            foreach (var field in extra.Keys.OrderBy(key => key, StringComparer.Ordinal))
            {
                var path = string.IsNullOrWhiteSpace(logicalPath) ? field : $"{logicalPath}.{field}";
                result.Error(file, path, $"unsupported field '{field}'");
            }
        }
    }

    private sealed class GenerationPlan
    {
        private readonly ManifestPackage _package;
        private readonly string _outputDirectory;
        private readonly List<PlannedFile> _managedFiles;
        private readonly PlannedFile _stub;
        private readonly string _indexContent;

        private GenerationPlan(
            ManifestPackage package,
            string outputDirectory,
            List<PlannedFile> managedFiles,
            PlannedFile stub,
            CancellationToken cancellationToken)
        {
            _package = package;
            _outputDirectory = outputDirectory;
            _managedFiles = managedFiles.OrderBy(file => file.RelativePath, StringComparer.Ordinal).ToList();
            _stub = stub;
            _indexContent = CreateIndexContent(cancellationToken);
        }

        public static GenerationPlan Create(ManifestPackage package, ValidationResult result, CancellationToken cancellationToken = default)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var outputDirectory = Path.GetFullPath(package.GetOutputDir());
            if (!IsInside(package.ProjectRoot, outputDirectory))
            {
                result.GenerationError("package.json", "godot.outputDir", "generation output must stay inside the project directory");
            }

            var widgetClass = package.Package.Godot.WidgetClass;
            var files = new List<PlannedFile>();
            files.Add(PlannedFile.Managed(outputDirectory, Path.Combine(outputDirectory, $"{widgetClass}.tscn"), "scene", SceneGenerator.Generate(package)));
            cancellationToken.ThrowIfCancellationRequested();
            files.Add(PlannedFile.Managed(outputDirectory, Path.Combine(outputDirectory, $"{widgetClass}.g.cs"), "code", CodeGenerator.Generate(package)));
            cancellationToken.ThrowIfCancellationRequested();
            files.Add(PlannedFile.Managed(outputDirectory, Path.Combine(outputDirectory, $"{widgetClass}.Catalog.g.cs"), "catalog", CatalogGenerator.Generate(package)));
            cancellationToken.ThrowIfCancellationRequested();
            var stub = PlannedFile.User(outputDirectory, Path.Combine(outputDirectory, $"{widgetClass}.cs"), ScriptStubGenerator.Generate(package));
            if (package.Codegen.RequiredServices.Count > 0)
            {
                files.Add(PlannedFile.Managed(outputDirectory, Path.Combine(outputDirectory, $"{widgetClass}.Services.g.cs"), "services", ServiceAccessorGenerator.Generate(package)));
            }

            if (package.GetThemeAsset() is { } theme)
            {
                var themePath = package.GetThemeOutputPath(theme);
                if (!IsInside(outputDirectory, themePath))
                {
                    result.GenerationError("assets.json", "theme.outputPath", "generated theme output must stay inside godot.outputDir", "Move theme.outputPath beneath the package output directory.");
                }
                else
                {
                    files.Add(PlannedFile.Managed(outputDirectory, themePath, "theme", AssetGenerator.GenerateTheme(package, theme)));
                }
            }
            if (package.Strings is not null)
            {
                var translationsDirectory = Path.Combine(outputDirectory, "translations");
                foreach (var locale in package.Strings.Locales.OrderBy(locale => locale, StringComparer.Ordinal))
                {
                    cancellationToken.ThrowIfCancellationRequested();
                    var translationPath = Path.Combine(translationsDirectory, $"{package.SystemName}.{locale}.tres");
                    files.Add(PlannedFile.Managed(outputDirectory, translationPath, "translation", LocalizationGenerator.Generate(package, locale)));
                }
            }

            cancellationToken.ThrowIfCancellationRequested();
            return new GenerationPlan(package, outputDirectory, files, stub, cancellationToken);
        }

        public void Check(ValidationResult result, CancellationToken cancellationToken = default)
        {
            foreach (var file in _managedFiles)
            {
                cancellationToken.ThrowIfCancellationRequested();
                CheckFile(file.FullPath, file.Content, result, file.RelativePath);
            }

            if (!File.Exists(_stub.FullPath))
            {
                result.GenerationError(_stub.RelativePath, "stub", "user widget partial is missing", "Run manifest-ui generate to create the initial stub.");
            }

            CheckFile(Path.Combine(_outputDirectory, ManagedIndexFileName), _indexContent, result, ManagedIndexFileName);
        }

        public void Commit(bool clean, ValidationResult result, CancellationToken cancellationToken = default)
        {
            var transactionRoot = "";
            var appliedPaths = new List<string>();
            var backups = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            var mutationsStarted = false;
            try
            {
                cancellationToken.ThrowIfCancellationRequested();
                var staleManagedFiles = clean ? GetStaleManagedFiles(result, cancellationToken) : new List<string>();
                if (!result.Ok)
                {
                    return;
                }

                var writes = new List<PlannedFile>(_managedFiles)
                {
                    PlannedFile.Managed(
                        _outputDirectory,
                        Path.Combine(_outputDirectory, ManagedIndexFileName),
                        "index",
                        _indexContent),
                };
                if (!File.Exists(_stub.FullPath))
                {
                    writes.Add(_stub);
                }

                var parentDirectory = Path.GetDirectoryName(_outputDirectory)!;
                Directory.CreateDirectory(parentDirectory);
                transactionRoot = Path.Combine(parentDirectory, $".manifest-ui-transaction-{Guid.NewGuid():N}");
                var stageRoot = Path.Combine(transactionRoot, "stage");
                var backupRoot = Path.Combine(transactionRoot, "backup");

                foreach (var file in writes)
                {
                    cancellationToken.ThrowIfCancellationRequested();
                    AtomicWrite(Path.Combine(stageRoot, file.RelativePath.Replace('/', Path.DirectorySeparatorChar)), file.Content);
                }

                var affectedPaths = writes.Select(file => file.FullPath)
                    .Concat(staleManagedFiles)
                    .Distinct(StringComparer.OrdinalIgnoreCase)
                    .OrderBy(path => path, StringComparer.Ordinal)
                    .ToArray();
                foreach (var path in affectedPaths.Where(File.Exists))
                {
                    cancellationToken.ThrowIfCancellationRequested();
                    var relativePath = Path.GetRelativePath(_outputDirectory, path);
                    var backupPath = Path.Combine(backupRoot, relativePath);
                    Directory.CreateDirectory(Path.GetDirectoryName(backupPath)!);
                    File.Copy(path, backupPath, overwrite: true);
                    backups[path] = backupPath;
                }

                cancellationToken.ThrowIfCancellationRequested();
                Directory.CreateDirectory(_outputDirectory);
                mutationsStarted = true;
                foreach (var path in staleManagedFiles.OrderBy(path => path, StringComparer.Ordinal))
                {
                    if (!File.Exists(path))
                    {
                        continue;
                    }
                    File.Delete(path);
                    appliedPaths.Add(path);
                }

                foreach (var file in writes.OrderBy(file => file.RelativePath, StringComparer.Ordinal))
                {
                    if (file.Kind == "user-stub" && File.Exists(file.FullPath))
                    {
                        continue;
                    }
                    var stagePath = Path.Combine(stageRoot, file.RelativePath.Replace('/', Path.DirectorySeparatorChar));
                    Directory.CreateDirectory(Path.GetDirectoryName(file.FullPath)!);
                    File.Move(stagePath, file.FullPath, overwrite: true);
                    appliedPaths.Add(file.FullPath);
                }
            }
            catch (Exception ex) when (ex is IOException or UnauthorizedAccessException)
            {
                var rollbackFailure = mutationsStarted ? Rollback(appliedPaths, backups) : "";
                var detail = string.IsNullOrWhiteSpace(rollbackFailure)
                    ? ex.Message
                    : $"{ex.Message}; rollback also failed: {rollbackFailure}";
                result.GenerationError(Path.GetRelativePath(_package.ProjectRoot, _outputDirectory), "commit", $"generation commit failed: {detail}");
            }
            finally
            {
                if (!string.IsNullOrWhiteSpace(transactionRoot) && Directory.Exists(transactionRoot))
                {
                    try
                    {
                        Directory.Delete(transactionRoot, recursive: true);
                    }
                    catch (Exception ex) when (ex is IOException or UnauthorizedAccessException)
                    {
                        if (result.Ok)
                        {
                            result.GenerationError(
                                Path.GetRelativePath(_package.ProjectRoot, transactionRoot),
                                "commit",
                                $"generation committed but transaction cleanup failed: {ex.Message}",
                                "Remove the reported transaction directory after confirming generated output.");
                        }
                    }
                }
            }
        }

        private static string Rollback(IReadOnlyList<string> appliedPaths, IReadOnlyDictionary<string, string> backups)
        {
            var failures = new List<string>();
            foreach (var path in appliedPaths.Reverse().Distinct(StringComparer.OrdinalIgnoreCase))
            {
                try
                {
                    if (backups.TryGetValue(path, out var backupPath) && File.Exists(backupPath))
                    {
                        Directory.CreateDirectory(Path.GetDirectoryName(path)!);
                        File.Copy(backupPath, path, overwrite: true);
                    }
                    else if (File.Exists(path))
                    {
                        File.Delete(path);
                    }
                }
                catch (Exception ex) when (ex is IOException or UnauthorizedAccessException)
                {
                    failures.Add($"{path}: {ex.Message}");
                }
            }
            return string.Join("; ", failures);
        }

        private string CreateIndexContent(CancellationToken cancellationToken)
        {
            var inputs = new List<GeneratedInput>();
            foreach (var pair in _package.SourceFiles.OrderBy(pair => pair.Key, StringComparer.Ordinal))
            {
                cancellationToken.ThrowIfCancellationRequested();
                inputs.Add(new GeneratedInput(
                    Path.GetRelativePath(_package.ProjectRoot, pair.Value).Replace('\\', '/'),
                    Sha256File(pair.Value)));
            }
            var inputPayload = string.Join("\n", inputs.Select(input => $"{input.Path}\0{input.ContentHash}"));
            var index = new GeneratedIndex
            {
                SchemaVersion = 1,
                ToolVersion = ToolVersion,
                PackageId = _package.Package.PackageId,
                InputHash = Sha256Text(inputPayload),
                Inputs = inputs.ToArray(),
                ManagedFiles = _managedFiles.Select(file => new GeneratedFile(file.RelativePath, file.Kind, Sha256Text(file.Content))).ToArray(),
            };
            return NormalizeGeneratedText(JsonSerializer.Serialize(index, JsonOptions));
        }

        private List<string> GetStaleManagedFiles(ValidationResult result, CancellationToken cancellationToken)
        {
            var staleFiles = new List<string>();
            var indexPath = Path.Combine(_outputDirectory, ManagedIndexFileName);
            if (!File.Exists(indexPath))
            {
                return staleFiles;
            }

            GeneratedIndex? previous;
            try
            {
                previous = JsonSerializer.Deserialize<GeneratedIndex>(File.ReadAllText(indexPath), JsonOptions);
            }
            catch (Exception ex) when (ex is IOException or JsonException or UnauthorizedAccessException)
            {
                result.GenerationError(ManagedIndexFileName, "clean", $"cannot read managed index: {ex.Message}", "Repair or remove only the invalid index after reviewing generated files.");
                return staleFiles;
            }

            var current = _managedFiles.Select(file => file.RelativePath).ToHashSet(StringComparer.Ordinal);
            foreach (var entry in previous?.ManagedFiles ?? Array.Empty<GeneratedFile>())
            {
                cancellationToken.ThrowIfCancellationRequested();
                if (current.Contains(entry.Path))
                {
                    continue;
                }
                if (string.IsNullOrWhiteSpace(entry.Path))
                {
                    result.GenerationError(ManagedIndexFileName, "clean", "refusing an empty managed path");
                    continue;
                }
                if (Path.IsPathRooted(entry.Path))
                {
                    result.GenerationError(ManagedIndexFileName, "clean", $"refusing rooted managed path '{entry.Path}'");
                    continue;
                }
                var target = Path.GetFullPath(entry.Path.Replace('/', Path.DirectorySeparatorChar), _outputDirectory);
                if (!IsInside(_outputDirectory, target))
                {
                    result.GenerationError(ManagedIndexFileName, "clean", $"refusing managed path outside outputDir: '{entry.Path}'");
                    continue;
                }
                if (File.Exists(target))
                {
                    staleFiles.Add(target);
                }
            }
            return staleFiles;
        }

        private static void CheckFile(string path, string expected, ValidationResult result, string displayPath)
        {
            if (!File.Exists(path))
            {
                result.GenerationError(displayPath, "generated", "generated file is missing", "Run manifest-ui generate.");
                return;
            }
            if (!string.Equals(NormalizeGeneratedText(File.ReadAllText(path)), NormalizeGeneratedText(expected), StringComparison.Ordinal))
            {
                result.GenerationError(displayPath, "generated", "generated file is stale", "Run manifest-ui generate.");
            }
        }
    }

    private sealed record PlannedFile(string FullPath, string RelativePath, string Kind, string Content)
    {
        public static PlannedFile Managed(string outputDirectory, string fullPath, string kind, string content)
        {
            return new PlannedFile(Path.GetFullPath(fullPath), Path.GetRelativePath(outputDirectory, fullPath).Replace('\\', '/'), kind, NormalizeGeneratedText(content));
        }

        public static PlannedFile User(string outputDirectory, string fullPath, string content)
        {
            return new PlannedFile(Path.GetFullPath(fullPath), Path.GetRelativePath(outputDirectory, fullPath).Replace('\\', '/'), "user-stub", NormalizeGeneratedText(content));
        }
    }

    private sealed class GeneratedIndex
    {
        public int SchemaVersion { get; set; }
        public string ToolVersion { get; set; } = "";
        public string PackageId { get; set; } = "";
        public string InputHash { get; set; } = "";
        public GeneratedInput[] Inputs { get; set; } = Array.Empty<GeneratedInput>();
        public GeneratedFile[] ManagedFiles { get; set; } = Array.Empty<GeneratedFile>();
    }

    private sealed record GeneratedInput(string Path, string ContentHash);
    private sealed record GeneratedFile(string Path, string Kind, string ContentHash);

    private static class AssetGenerator
    {
        public static string GenerateTheme(ManifestPackage package, AssetEntry themeAsset)
        {
            var theme = themeAsset.Theme;
            var fontAsset = ResolveDefaultFont(package, themeAsset);
            var fontSize = ResolveDefaultFontSize(themeAsset, fontAsset);
            var sb = new StringBuilder();

            if (fontAsset is not null)
            {
                sb.AppendLine("[gd_resource type=\"Theme\" load_steps=2 format=3]");
                sb.AppendLine();
                sb.AppendLine($"[ext_resource type=\"Font\" path=\"{package.GetAssetResourcePath(fontAsset)}\" id=\"1_default_font\"]");
                sb.AppendLine();
            }
            else
            {
                sb.AppendLine("[gd_resource type=\"Theme\" format=3]");
                sb.AppendLine();
            }

            sb.AppendLine("[resource]");
            if (fontAsset is not null)
            {
                sb.AppendLine("default_font = ExtResource(\"1_default_font\")");
            }
            if (fontSize > 0)
            {
                sb.AppendLine($"default_font_size = {fontSize}");
            }
            foreach (var variation in theme.TypeVariations)
            {
                sb.AppendLine($"{variation.Id}/base_type = &\"{Escape(variation.BaseType)}\"");
            }
            return sb.ToString();
        }

        private static AssetEntry? ResolveDefaultFont(ManifestPackage package, AssetEntry themeAsset)
        {
            if (!string.IsNullOrWhiteSpace(themeAsset.Theme.DefaultFontAssetId))
            {
                return package.Assets.Assets.FirstOrDefault(asset => string.Equals(asset.Id, themeAsset.Theme.DefaultFontAssetId, StringComparison.Ordinal));
            }
            return package.Assets.Assets.FirstOrDefault(asset => asset.DefaultFont && string.Equals(asset.Kind, "font", StringComparison.OrdinalIgnoreCase));
        }

        private static int ResolveDefaultFontSize(AssetEntry themeAsset, AssetEntry? fontAsset)
        {
            if (themeAsset.Theme.DefaultFontSize > 0)
            {
                return themeAsset.Theme.DefaultFontSize;
            }
            return fontAsset?.DefaultFontSize ?? 0;
        }
    }

    private static class LocalizationGenerator
    {
        public static string Generate(ManifestPackage package, string locale)
        {
            var messages = package.Strings!.Strings
                .Where(pair => pair.Value.ContainsKey(locale))
                .OrderBy(pair => pair.Key, StringComparer.Ordinal)
                .Select(pair => $"&\"{Escape(pair.Key)}\": \"{EscapeGodotString(pair.Value[locale])}\"");
            var sb = new StringBuilder();
            sb.AppendLine("[gd_resource type=\"Translation\" format=3]");
            sb.AppendLine();
            sb.AppendLine("[resource]");
            sb.AppendLine($"resource_name = \"{Escape(package.Package.PackageId)}.{Escape(locale)}\"");
            sb.AppendLine($"locale = \"{Escape(locale)}\"");
            sb.AppendLine($"messages = {{{string.Join(", ", messages)}}}");
            return sb.ToString();
        }

        private static string EscapeGodotString(string value)
        {
            return Escape(value).Replace("\n", "\\n", StringComparison.Ordinal).Replace("\r", "\\r", StringComparison.Ordinal);
        }
    }

    private static class SceneGenerator
    {
        public static string Generate(ManifestPackage package)
        {
            var outputDir = package.GetOutputDir();
            var scriptPath = ToResourcePath(package.ProjectRoot, Path.Combine(outputDir, $"{package.Package.Godot.WidgetClass}.cs"));
            var sceneResources = CollectSceneResources(package.Layout.Root);
            var scriptResources = CollectScriptResources(package.Layout.Root, sceneResources.Count + 2);
            var assetResources = CollectAssetResources(package, sceneResources.Count + scriptResources.Count + 2);
            var sb = new StringBuilder();
            sb.AppendLine($"[gd_scene load_steps={2 + sceneResources.Count + scriptResources.Count + assetResources.Count} format=3]");
            sb.AppendLine();
            sb.AppendLine($"[ext_resource type=\"Script\" path=\"{scriptPath}\" id=\"1_widget\"]");
            foreach (var (path, id) in sceneResources.OrderBy(pair => pair.Value, StringComparer.Ordinal))
            {
                sb.AppendLine($"[ext_resource type=\"PackedScene\" path=\"{path}\" id=\"{id}\"]");
            }
            foreach (var (path, id) in scriptResources.OrderBy(pair => pair.Value, StringComparer.Ordinal))
            {
                sb.AppendLine($"[ext_resource type=\"Script\" path=\"{path}\" id=\"{id}\"]");
            }
            foreach (var (_, resource) in assetResources.OrderBy(pair => pair.Key, StringComparer.Ordinal))
            {
                sb.AppendLine($"[ext_resource type=\"{resource.Type}\" path=\"{resource.Path}\" id=\"{resource.ExtResourceId}\"]");
            }
            sb.AppendLine();
            EmitNode(sb, package.Layout.Root, parentPath: "", nodePath: ".", sceneResources, scriptResources, assetResources);
            return sb.ToString();
        }

        private static Dictionary<string, string> CollectSceneResources(LayoutNode root)
        {
            var result = new Dictionary<string, string>(StringComparer.Ordinal);
            var next = 2;
            foreach (var path in Walk(root).Where(node => string.Equals(node.Type, "SceneInstance", StringComparison.Ordinal)).Select(node => node.ScenePath).Distinct(StringComparer.Ordinal).OrderBy(path => path, StringComparer.Ordinal))
            {
                result[path] = $"{next++}_scene";
            }
            return result;
        }

        private static Dictionary<string, SceneAssetResource> CollectAssetResources(ManifestPackage package, int next)
        {
            var declaredAssets = package.Assets.Assets.ToDictionary(asset => asset.Id, StringComparer.Ordinal);
            var generatedAssets = package.GetAssetRefs().ToDictionary(asset => asset.Id, StringComparer.Ordinal);
            var referencedAssetIds = Walk(package.Layout.Root)
                .SelectMany(node => node.Properties.Values)
                .Select(value => TryReadAssetReference(value, out var assetId) ? assetId : "")
                .Where(assetId => !string.IsNullOrWhiteSpace(assetId))
                .Distinct(StringComparer.Ordinal)
                .OrderBy(assetId => assetId, StringComparer.Ordinal);

            var result = new Dictionary<string, SceneAssetResource>(StringComparer.Ordinal);
            foreach (var assetId in referencedAssetIds)
            {
                var asset = declaredAssets[assetId];
                var generated = generatedAssets[assetId];
                result[assetId] = new SceneAssetResource(AssetResourceType(asset.Kind), generated.Path, $"{next++}_asset");
            }
            return result;
        }

        private static string AssetResourceType(string kind)
        {
            return kind.ToLowerInvariant() switch
            {
                "texture" => "Texture2D",
                "font" => "Font",
                "theme" => "Theme",
                _ => "Resource",
            };
        }

        private static Dictionary<string, string> CollectScriptResources(LayoutNode root, int next)
        {
            var result = new Dictionary<string, string>(StringComparer.Ordinal);
            foreach (var path in Walk(root).Select(node => node.ScriptPath).Where(path => !string.IsNullOrWhiteSpace(path)).Distinct(StringComparer.Ordinal).OrderBy(path => path, StringComparer.Ordinal))
            {
                result[path] = $"{next++}_script";
            }
            return result;
        }

        private static IEnumerable<LayoutNode> Walk(LayoutNode node)
        {
            yield return node;
            foreach (var child in node.Children)
            {
                foreach (var nested in Walk(child))
                {
                    yield return nested;
                }
            }
        }

        private static void EmitNode(
            StringBuilder sb,
            LayoutNode node,
            string parentPath,
            string nodePath,
            Dictionary<string, string> sceneResources,
            Dictionary<string, string> scriptResources,
            Dictionary<string, SceneAssetResource> assetResources)
        {
            if (nodePath == ".")
            {
                sb.AppendLine($"[node name=\"{node.Name}\" type=\"{node.Type}\"]");
                sb.AppendLine("script = ExtResource(\"1_widget\")");
            }
            else if (string.Equals(node.Type, "SceneInstance", StringComparison.Ordinal))
            {
                sb.AppendLine($"[node name=\"{node.Name}\" parent=\"{parentPath}\" instance=ExtResource(\"{sceneResources[node.ScenePath]}\")]");
            }
            else
            {
                sb.AppendLine($"[node name=\"{node.Name}\" type=\"{node.Type}\" parent=\"{parentPath}\"]");
            }
            if (nodePath != "." && !string.IsNullOrWhiteSpace(node.ScriptPath))
            {
                sb.AppendLine($"script = ExtResource(\"{scriptResources[node.ScriptPath]}\")");
            }
            foreach (var (key, value) in node.Properties.Where(pair => !node.Localization.ContainsKey(pair.Key)).OrderBy(pair => pair.Key, StringComparer.Ordinal))
            {
                sb.AppendLine($"{key} = {FormatValue(value, assetResources)}");
            }
            foreach (var (property, value) in node.Localization.OrderBy(pair => pair.Key, StringComparer.Ordinal))
            {
                if (TryReadLocalizationValue(value, "layout.json", "", null, out var localization))
                {
                    sb.AppendLine($"{property} = \"{Escape(localization.Key)}\"");
                }
            }
            foreach (var child in node.Children)
            {
                sb.AppendLine();
                var childPath = nodePath == "." ? child.Name : $"{nodePath}/{child.Name}";
                EmitNode(sb, child, nodePath, childPath, sceneResources, scriptResources, assetResources);
            }
        }

        private static string FormatValue(JsonElement value, IReadOnlyDictionary<string, SceneAssetResource> assetResources)
        {
            if (TryReadAssetReference(value, out var assetId))
            {
                return $"ExtResource(\"{assetResources[assetId].ExtResourceId}\")";
            }

            return value.ValueKind switch
            {
                JsonValueKind.String => $"\"{Escape(value.GetString() ?? "")}\"",
                JsonValueKind.Number => value.GetRawText(),
                JsonValueKind.True => "true",
                JsonValueKind.False => "false",
                JsonValueKind.Array when value.GetArrayLength() == 2 => $"Vector2({value[0].GetRawText()}, {value[1].GetRawText()})",
                _ => throw new InvalidOperationException($"Unsupported tscn value: {value.GetRawText()}"),
            };
        }

        private sealed record SceneAssetResource(string Type, string Path, string ExtResourceId);
    }

    private static class CodeGenerator
    {
        public static string Generate(ManifestPackage package)
        {
            var propertyBindings = package.GetPropertyBindings();
            var repeaters = package.GetRepeaters();
            var inputs = package.GetInputs();
            var localizations = package.GetLocalizedProperties();
            var events = package.GetEvents();
            var targets = CollectTargets(package, propertyBindings, repeaters, inputs, events);
            var assets = package.GetAssetRefs();
            var themePath = package.GetThemeAsset() is { } themeAsset ? package.GetThemeOutputResourcePath(themeAsset) : "";
            var sb = new StringBuilder();
            sb.AppendLine("using System.Collections.Generic;");
            sb.AppendLine("using Godot;");
            sb.AppendLine("using GodotUi.Manifest;");
            sb.AppendLine();
            sb.AppendLine($"namespace {package.GetNamespace()};");
            sb.AppendLine();
            sb.AppendLine("[Tool]");
            sb.AppendLine($"public partial class {package.Package.Godot.WidgetClass}");
            sb.AppendLine("{");
            foreach (var target in targets.Values)
            {
                sb.AppendLine($"    private {target.Type} {target.FieldName} = null!;");
            }
            sb.AppendLine();
            sb.AppendLine($"    public override string PackageId => \"{Escape(package.Package.PackageId)}\";");
            var scope = package.Package.Runtime.ControllerScope switch
            {
                "instance" => "Instance",
                "screen" => "Screen",
                _ => "Package",
            };
            sb.AppendLine($"    public override ManifestControllerScope ControllerScope => ManifestControllerScope.{scope};");
            if (package.Strings is not null)
            {
                sb.AppendLine($"    public override string TranslationDomain => \"{Escape(package.Package.PackageId)}\";");
            }
            sb.AppendLine();
            sb.AppendLine("    protected override ManifestControllerBase CreateController()");
            sb.AppendLine("    {");
            sb.AppendLine($"        return new global::{package.Package.Godot.ControllerClass}();");
            sb.AppendLine("    }");
            sb.AppendLine();
            sb.AppendLine("    protected override void BindNodes()");
            sb.AppendLine("    {");
            foreach (var target in targets.Values)
            {
                sb.AppendLine($"        {target.FieldName} = GetNode<{target.Type}>(\"{target.Path}\");");
            }
            foreach (var evt in events)
            {
                var target = targets[evt.Target];
                sb.AppendLine($"        {SignalConnectLine(target.FieldName, EngineSignalName(target.Node, evt.Signal), Names.EventMethod(evt.EventId, evt.Signal))}");
            }
            for (var index = 0; index < inputs.Count; index++)
            {
                var input = inputs[index];
                var target = targets[input.Target];
                sb.AppendLine($"        {InputConnectLine(target, input, index)}");
            }
            sb.AppendLine("    }");
            if (events.Count > 0 || inputs.Count > 0)
            {
                sb.AppendLine();
                sb.AppendLine("    protected override void UnbindNodes()");
                sb.AppendLine("    {");
            foreach (var evt in events)
            {
                var target = targets[evt.Target];
                sb.AppendLine($"        {SignalDisconnectLine(target.FieldName, EngineSignalName(target.Node, evt.Signal), Names.EventMethod(evt.EventId, evt.Signal))}");
                }
                for (var index = 0; index < inputs.Count; index++)
                {
                    var input = inputs[index];
                    var target = targets[input.Target];
                    sb.AppendLine($"        {InputDisconnectLine(target, input, index)}");
                }
                sb.AppendLine("    }");
            }
            sb.AppendLine();
            sb.AppendLine("    protected override ManifestBindingSet GetBindingSet()");
            sb.AppendLine("    {");
            sb.AppendLine("        return new ManifestBindingSet(");
            sb.AppendLine("            new ManifestPropertyBinding[]");
            sb.AppendLine("            {");
            foreach (var binding in propertyBindings)
            {
                sb.AppendLine($"                new ManifestPropertyBinding(\"{Escape(binding.Target)}\", \"{Escape(binding.Property)}\", \"{Escape(binding.FieldId)}\", \"{Escape(binding.Converter)}\", \"{Escape(binding.Format)}\", {FormatCSharpLiteral(binding.Fallback)}),");
            }
            sb.AppendLine("            },");
            sb.AppendLine("            new ManifestAssetCatalog(");
            sb.AppendLine("                new ManifestAssetRef[]");
            sb.AppendLine("                {");
            foreach (var asset in assets)
            {
                sb.AppendLine($"                    new ManifestAssetRef(\"{Escape(asset.Id)}\", \"{Escape(asset.Kind)}\", \"{Escape(asset.Path)}\"),");
            }
            sb.AppendLine("                },");
            sb.AppendLine($"                \"{Escape(themePath)}\"),");
            sb.AppendLine("            new ManifestRepeaterBinding[]");
            sb.AppendLine("            {");
            foreach (var repeater in repeaters)
            {
                sb.AppendLine($"                new ManifestRepeaterBinding(\"{Escape(repeater.Target)}\", \"{Escape(repeater.Template)}\", \"{Escape(repeater.FieldId)}\", new ManifestItemBinding[]");
                sb.AppendLine("                {");
                foreach (var binding in repeater.ItemBindings)
                {
                    sb.AppendLine($"                    new ManifestItemBinding(\"{Escape(binding.Target)}\", \"{Escape(binding.Property)}\", \"{Escape(binding.FieldId)}\", \"{Escape(binding.Converter)}\", \"{Escape(binding.Format)}\", {FormatCSharpLiteral(binding.Fallback)}),");
                }
                sb.AppendLine($"                }}, \"{Escape(repeater.KeyFieldId)}\", {repeater.PoolCapacity}),");
            }
            sb.AppendLine("            },");
            sb.AppendLine("            new ManifestInputBinding[]");
            sb.AppendLine("            {");
            foreach (var input in inputs)
            {
                sb.AppendLine($"                new ManifestInputBinding(\"{Escape(input.Target)}\", \"{Escape(input.Property)}\", \"{Escape(input.FieldId)}\"),");
            }
            var updatePolicy = package.Bindings.Mvvm.UpdatePolicy switch
            {
                "immediate" => "Immediate",
                "deferred" => "Deferred",
                _ => "Manual",
            };
            sb.AppendLine("            },");
            sb.AppendLine($"            ManifestUiUpdatePolicy.{updatePolicy},");
            sb.AppendLine("            new ManifestLocalizedPropertyBinding[]");
            sb.AppendLine("            {");
            foreach (var localization in localizations)
            {
                if (string.IsNullOrWhiteSpace(localization.Context) && localization.ArgumentFieldIds.Count == 0)
                {
                    sb.AppendLine($"                new ManifestLocalizedPropertyBinding(\"{Escape(localization.Target)}\", \"{Escape(localization.Property)}\", \"{Escape(localization.Key)}\"),");
                    continue;
                }
                var arguments = localization.ArgumentFieldIds.Count == 0
                    ? "global::System.Array.Empty<string>()"
                    : $"new string[] {{ {string.Join(", ", localization.ArgumentFieldIds.Select(fieldId => $"\"{Escape(fieldId)}\""))} }}";
                sb.AppendLine($"                new ManifestLocalizedPropertyBinding(\"{Escape(localization.Target)}\", \"{Escape(localization.Property)}\", \"{Escape(localization.Key)}\", \"{Escape(localization.Context)}\", {arguments}),");
            }
            sb.AppendLine("            });");
            sb.AppendLine("    }");
            foreach (var evt in events)
            {
                var target = targets[evt.Target];
                sb.AppendLine();
                sb.AppendLine($"    private void {Names.EventMethod(evt.EventId, evt.Signal)}({SignalArgs(evt.Signal, target.Node.Type)})");
                sb.AppendLine("    {");
                sb.AppendLine($"        DispatchUiEvent(\"{Escape(evt.EventId)}\", \"\");");
                sb.AppendLine("        ManifestMessageBus.Instance?.Publish(");
                sb.AppendLine($"            \"{Escape(evt.Channel)}\",");
                sb.AppendLine($"            \"{Escape(evt.EventId)}\",");
                sb.AppendLine("            default,");
                sb.AppendLine("            ManifestMessageScope.Package,");
                sb.AppendLine($"            \"{Escape(evt.Scope)}\",");
                sb.AppendLine("            PackageId,");
                sb.AppendLine($"            ManifestMessageDelivery.{(evt.Dispatch == "deferred" ? "Deferred" : "Immediate")});");
                sb.AppendLine("    }");
            }
            for (var index = 0; index < inputs.Count; index++)
            {
                var input = inputs[index];
                var target = targets[input.Target];
                sb.AppendLine();
                sb.AppendLine($"    private void {InputHandlerMethod(input, index)}({InputHandlerArgs(target, input)})");
                sb.AppendLine("    {");
                sb.AppendLine($"        SetInputValue(\"{Escape(input.FieldId)}\", {InputHandlerValue(target, input)});");
                sb.AppendLine("    }");
            }
            sb.AppendLine("}");
            return sb.ToString();
        }

        private static string FormatCSharpLiteral(JsonElement? value)
        {
            if (value is null || value.Value.ValueKind == JsonValueKind.Null || value.Value.ValueKind == JsonValueKind.Undefined)
            {
                return "null";
            }

            var element = value.Value;
            return element.ValueKind switch
            {
                JsonValueKind.String => $"\"{Escape(element.GetString() ?? "")}\"",
                JsonValueKind.Number => element.GetRawText(),
                JsonValueKind.True => "true",
                JsonValueKind.False => "false",
                _ => "null",
            };
        }

        private static string SignalConnectLine(string fieldName, string signal, string methodName)
        {
            return $"{fieldName}.Connect(new StringName(\"{Escape(signal)}\"), new Callable(this, nameof({methodName})));";
        }

        private static string SignalDisconnectLine(string fieldName, string signal, string methodName)
        {
            return $"{fieldName}.Disconnect(new StringName(\"{Escape(signal)}\"), new Callable(this, nameof({methodName})));";
        }

        private static string SignalArgs(string signal, string nodeType)
        {
            if (signal == "text_changed" && nodeType == "TextEdit")
            {
                return "";
            }

            return signal switch
            {
                "text_changed" => "string value",
                "toggled" => "bool value",
                "value_changed" => "double value",
                "item_selected" => "long value",
                "tab_changed" => "long value",
                _ => "",
            };
        }

        private static string InputConnectLine(Target target, InputBinding input, int index)
        {
            return SignalConnectLine(target.FieldName, EngineSignalName(target.Node, InputSignalName(input)), InputHandlerMethod(input, index));
        }

        private static string InputDisconnectLine(Target target, InputBinding input, int index)
        {
            return SignalDisconnectLine(target.FieldName, EngineSignalName(target.Node, InputSignalName(input)), InputHandlerMethod(input, index));
        }

        private static string EngineSignalName(LayoutNode node, string signal)
        {
            return node.ScriptPath.EndsWith(".cs", StringComparison.OrdinalIgnoreCase)
                ? Names.Pascal(signal)
                : signal;
        }

        private static string InputSignalName(InputBinding input)
        {
            return input.Property switch
            {
                "text" => "text_changed",
                "buttonPressed" => "toggled",
                "value" => "value_changed",
                "selected" => "item_selected",
                _ => throw new InvalidOperationException($"Unsupported input property '{input.Property}'."),
            };
        }

        private static string InputHandlerMethod(InputBinding input, int index)
        {
            return $"OnInput{index}{Names.Pascal(input.FieldId)}Changed";
        }

        private static string InputHandlerArgs(Target target, InputBinding input)
        {
            return input.Property switch
            {
                "text" when target.Node.Type == "TextEdit" => "",
                "text" => "string value",
                "buttonPressed" => "bool value",
                "value" => "double value",
                "selected" => "long value",
                _ => throw new InvalidOperationException($"Unsupported input property '{input.Property}'."),
            };
        }

        private static string InputHandlerValue(Target target, InputBinding input)
        {
            return input.Property == "text" && target.Node.Type == "TextEdit" ? $"{target.FieldName}.Text" : "value";
        }

        private static Dictionary<string, Target> CollectTargets(
            ManifestPackage package,
            List<PropertyBinding> propertyBindings,
            List<RepeaterBinding> repeaters,
            List<InputBinding> inputs,
            List<EventBinding> events)
        {
            var result = new Dictionary<string, Target>(StringComparer.Ordinal);
            foreach (var targetPath in propertyBindings.Select(x => x.Target)
                         .Concat(repeaters.SelectMany(x => new[] { x.Target, x.Template }))
                         .Concat(inputs.Select(x => x.Target))
                         .Concat(events.Select(x => x.Target))
                         .Distinct())
            {
                var node = package.NodeByPath[targetPath];
                result[targetPath] = new Target(targetPath, Names.Field(targetPath), node, FieldType(node));
            }
            return result;
        }

        private static string FieldType(LayoutNode node)
        {
            return string.Equals(node.Type, "SceneInstance", StringComparison.Ordinal) ? "Control" : node.Type;
        }
    }

    private static class CatalogGenerator
    {
        public static string Generate(ManifestPackage package)
        {
            var scope = package.Package.Runtime.ControllerScope switch
            {
                "instance" => "Instance",
                "screen" => "Screen",
                _ => "Package",
            };
            var translationPaths = package.Strings is null
                ? Array.Empty<string>()
                : package.Strings.Locales
                    .OrderBy(locale => locale, StringComparer.Ordinal)
                    .Select(locale => ToResourcePath(package.ProjectRoot, Path.Combine(package.GetOutputDir(), "translations", $"{package.SystemName}.{locale}.tres")))
                    .ToArray();
            var sb = new StringBuilder();
            sb.AppendLine($"namespace {package.GetNamespace()};");
            sb.AppendLine();
            sb.AppendLine($"public static class {package.Package.Godot.WidgetClass}ManifestCatalog");
            sb.AppendLine("{");
            sb.AppendLine("    public static global::GodotUi.Manifest.ManifestUiCatalogEntry CreateEntry()");
            sb.AppendLine("    {");
            sb.AppendLine("        return new global::GodotUi.Manifest.ManifestUiCatalogEntry(");
            sb.AppendLine($"            \"{Escape(package.Package.PackageId)}\",");
            sb.AppendLine($"            \"{Escape(package.Package.Godot.ScenePath)}\",");
            sb.AppendLine($"            () => new global::{package.Package.Godot.ControllerClass}(),");
            sb.AppendLine($"            global::GodotUi.Manifest.ManifestControllerScope.{scope},");
            sb.AppendLine($"            \"{(package.Strings is null ? "" : Escape(package.Package.PackageId))}\",");
            sb.AppendLine("            new string[]");
            sb.AppendLine("            {");
            foreach (var path in translationPaths)
            {
                sb.AppendLine($"                \"{Escape(path)}\",");
            }
            sb.AppendLine("            },");
            sb.AppendLine("            new global::GodotUi.Manifest.ManifestUiRoute[]");
            sb.AppendLine("            {");
            foreach (var route in package.Codegen.Routes)
            {
                sb.AppendLine($"                new global::GodotUi.Manifest.ManifestUiRoute(\"{Escape(route.Channel)}\", \"{Escape(route.Action)}\", \"{Escape(route.PackageId)}\"),");
            }
            sb.AppendLine("            });");
            sb.AppendLine("    }");
            sb.AppendLine();
            sb.AppendLine("    public static void Register(global::GodotUi.Manifest.ManifestUiManager manager, bool replace = false)");
            sb.AppendLine("    {");
            sb.AppendLine("        manager.RegisterCatalogEntry(CreateEntry(), replace);");
            sb.AppendLine("    }");
            if (package.Codegen.Routes.Count > 0)
            {
                sb.AppendLine();
                sb.AppendLine("    public static (string Channel, string Action, string PackageId)[] CreateRoutes()");
                sb.AppendLine("    {");
                sb.AppendLine("        return new (string Channel, string Action, string PackageId)[]");
                sb.AppendLine("        {");
                foreach (var route in package.Codegen.Routes)
                {
                    sb.AppendLine($"            (\"{Escape(route.Channel)}\", \"{Escape(route.Action)}\", \"{Escape(route.PackageId)}\"),");
                }
                sb.AppendLine("        };");
                sb.AppendLine("    }");
            }
            sb.AppendLine("}");
            return sb.ToString();
        }
    }

    private static class ServiceAccessorGenerator
    {
        public static string Generate(ManifestPackage package)
        {
            var controllerType = package.Package.Godot.ControllerClass;
            var separator = controllerType.LastIndexOf('.');
            var controllerNamespace = separator < 0 ? "" : controllerType[..separator];
            var controllerClass = separator < 0 ? controllerType : controllerType[(separator + 1)..];
            var sb = new StringBuilder();
            if (!string.IsNullOrWhiteSpace(controllerNamespace))
            {
                sb.AppendLine($"namespace {controllerNamespace};");
                sb.AppendLine();
            }
            sb.AppendLine($"public partial class {controllerClass}");
            sb.AppendLine("{");
            foreach (var service in package.Codegen.RequiredServices)
            {
                var typeName = service.Type.StartsWith("global::", StringComparison.Ordinal) ? service.Type : $"global::{service.Type}";
                sb.AppendLine($"    protected {typeName} {service.Property} => Context.RequireService<{typeName}>(\"{Escape(service.Key)}\");");
            }
            sb.AppendLine("}");
            return sb.ToString();
        }
    }

    private static class ScriptStubGenerator
    {
        public static string Generate(ManifestPackage package)
        {
            return $$"""
                   using GodotUi.Manifest;

                   namespace {{package.GetNamespace()}};

                   public partial class {{package.Package.Godot.WidgetClass}} : ManifestGeneratedWidget
                   {
                   }
                   """;
        }
    }

    private static class ReportWriter
    {
        public static void Write(ManifestPackage package)
        {
            var exportDir = Path.Combine(package.DirectoryPath, "export");
            Directory.CreateDirectory(exportDir);

            var sourceFiles = package.SourceFiles.ToDictionary(
                kvp => kvp.Key,
                kvp => new SourceHash(Path.GetRelativePath(package.DirectoryPath, kvp.Value).Replace('\\', '/'), Sha256File(kvp.Value)),
                StringComparer.Ordinal);

            var channelCount = package.Bindings.Events.ValueKind == JsonValueKind.Object
                && package.Bindings.Events.TryGetProperty("channels", out var channels)
                && channels.ValueKind == JsonValueKind.Array ? channels.GetArrayLength() : 0;

            var counts = new ReportCounts
            {
                Nodes = package.NodeByPath.Count + 1,
                Fields = package.GetPropertyBindings().Count,
                Events = package.GetEvents().Count,
                Channels = channelCount,
                Assets = package.Assets.Assets.Count,
            };
            var assetReport = package.Assets.Assets.Select(asset => new AssetReportEntry(
                asset.Id,
                asset.Kind,
                asset.RelativePath.Replace('\\', '/'),
                package.GetAssetRefs().First(assetRef => assetRef.Id == asset.Id).Path,
                asset.ContentHash,
                package.GetThemeAsset() == asset ? package.GetThemeOutputResourcePath(asset) : "")).ToList();

            var importManifest = new ImportManifest
            {
                SchemaVersion = CurrentSchemaVersion,
                GeneratorId = GeneratorId,
                PackageId = package.Package.PackageId,
                DisplayName = package.Package.DisplayName,
                SourceFiles = sourceFiles,
                Counts = counts,
                Assets = assetReport,
            };

            AtomicWrite(Path.Combine(exportDir, "godot_import_manifest.json"), JsonSerializer.Serialize(importManifest, JsonOptions));

            var lines = new List<string>
            {
                "# Manifest UI Validation Report",
                "",
                $"- Package: {package.Package.PackageId}",
                $"- DisplayName: {package.Package.DisplayName}",
                $"- Nodes: {counts.Nodes}",
                $"- Fields: {counts.Fields}",
                $"- Events: {counts.Events}",
                $"- Channels: {counts.Channels}",
                $"- Assets: {counts.Assets}",
                "",
                "## Source Files",
                "",
            };
            lines.AddRange(sourceFiles.Select(kvp => $"- {kvp.Value.Path}: {kvp.Value.ContentHash}"));
            lines.Add("");
            lines.Add("## Assets");
            lines.Add("");
            lines.Add("| id | kind | source | resource | hash | theme output |");
            lines.Add("|----|------|--------|----------|------|--------------|");
            lines.AddRange(assetReport.Select(asset => $"| {asset.Id} | {asset.Kind} | {asset.SourcePath} | {asset.ResourcePath} | {asset.ContentHash} | {asset.ThemeOutput} |"));
            lines.Add("");
            AtomicWrite(Path.Combine(exportDir, "manifest_report.md"), string.Join("\n", lines));
        }
    }

    private sealed class ValidationResult
    {
        private readonly List<ManifestDiagnostic> _diagnostics = new();
        private readonly Dictionary<string, string> _sourcePaths = new(StringComparer.OrdinalIgnoreCase);
        public IReadOnlyList<ManifestDiagnostic> Diagnostics => _diagnostics;
        public bool Ok => _diagnostics.All(diagnostic => diagnostic.Severity != ManifestDiagnosticSeverity.Error);
        public static ValidationResult Create() => new();

        public void RegisterSource(string logicalFile, string? fullPath)
        {
            if (!string.IsNullOrWhiteSpace(fullPath))
            {
                _sourcePaths[logicalFile] = fullPath;
            }
        }

        public void MergeFrom(ValidationResult other)
        {
            _diagnostics.AddRange(other.Diagnostics);
        }

        public void Error(string file, string path, string message, long line = 0, long column = 0, string hint = "")
        {
            Add(InferValidationCode(file, path, message), ManifestDiagnosticSeverity.Error, file, path, line, column, message, hint);
        }

        public void Warning(string message)
        {
            Add("MUI2000", ManifestDiagnosticSeverity.Warning, "", "", 0, 0, message, "");
        }

        public void Warning(string file, string path, string message, string hint = "")
        {
            Add("MUI2000", ManifestDiagnosticSeverity.Warning, file, path, 0, 0, message, hint);
        }

        public void GenerationError(string file, string path, string message, string hint = "")
        {
            Add("MUI3001", ManifestDiagnosticSeverity.Error, file, path, 0, 0, message, hint);
        }

        public void EngineError(string file, string path, string message, string hint = "")
        {
            Add("MUI4001", ManifestDiagnosticSeverity.Error, file, path, 0, 0, message, hint);
        }

        public void EnvironmentError(string file, string path, string message, string hint = "")
        {
            Add("MUI5003", ManifestDiagnosticSeverity.Error, file, path, 0, 0, message, hint);
        }

        private void Add(string code, ManifestDiagnosticSeverity severity, string file, string path, long line, long column, string message, string hint)
        {
            if (line <= 0 && _sourcePaths.TryGetValue(file, out var sourcePath))
            {
                (line, column) = FindSourceLocation(sourcePath, path);
            }
            _diagnostics.Add(new ManifestDiagnostic(code, severity, file.Replace('\\', '/'), ToJsonPointer(path), line, column, message, hint));
        }

        private static (long Line, long Column) FindSourceLocation(string sourcePath, string path)
        {
            try
            {
                var tokens = path.Split('.', '[', ']')
                    .Where(part => !string.IsNullOrWhiteSpace(part) && !int.TryParse(part, out _))
                    .ToArray();
                if (tokens.Length == 0)
                {
                    return (1, 1);
                }
                var lines = File.ReadAllLines(sourcePath);
                var candidates = Enumerable.Range(0, tokens.Length)
                    .Select(start => string.Join('.', tokens.Skip(start)))
                    .OrderByDescending(candidate => candidate.Length)
                    .Distinct(StringComparer.Ordinal);
                foreach (var candidate in candidates)
                {
                    var needle = $"\"{candidate}\"";
                    for (var i = 0; i < lines.Length; i++)
                    {
                        var column = lines[i].IndexOf(needle, StringComparison.Ordinal);
                        if (column >= 0)
                        {
                            return (i + 1, column + 1);
                        }
                    }
                }
            }
            catch (IOException)
            {
            }
            catch (UnauthorizedAccessException)
            {
            }
            return (0, 0);
        }

        private static string InferValidationCode(string file, string path, string message)
        {
            if (message.StartsWith("JSON read failed", StringComparison.Ordinal)) return "MUI1001";
            if (path.Contains("schemaVersion", StringComparison.Ordinal) || message.Contains("is required", StringComparison.Ordinal)) return "MUI1002";
            if (path.Contains("contentHash", StringComparison.Ordinal)) return "MUI2302";
            if (file.Contains("bindings", StringComparison.Ordinal)) return "MUI2201";
            if (file.Contains("assets", StringComparison.Ordinal)) return "MUI2301";
            if (message.Contains("path", StringComparison.OrdinalIgnoreCase) || path.Contains("Path", StringComparison.OrdinalIgnoreCase) || path.Contains("outputDir", StringComparison.Ordinal)) return "MUI2002";
            return "MUI2001";
        }

        private static string ToJsonPointer(string path)
        {
            if (string.IsNullOrWhiteSpace(path)) return "";
            var normalized = path.Replace("]", "", StringComparison.Ordinal).Replace("[", "/", StringComparison.Ordinal).Replace('.', '/');
            return "/" + string.Join('/', normalized.Split('/', StringSplitOptions.RemoveEmptyEntries).Select(segment => segment.Replace("~", "~0", StringComparison.Ordinal).Replace("/", "~1", StringComparison.Ordinal)));
        }
    }

    private static class Names
    {
        public static string Pascal(string value)
        {
            var parts = value
                .Split(value.Where(ch => !char.IsLetterOrDigit(ch)).Distinct().ToArray(), StringSplitOptions.RemoveEmptyEntries);
            var identifier = string.Concat(parts.Select(part => char.ToUpperInvariant(part[0]) + part[1..]));
            if (string.IsNullOrEmpty(identifier))
            {
                return "Generated";
            }
            if (char.IsDigit(identifier[0]) || CSharpKeywords.Contains(identifier))
            {
                return "_" + identifier;
            }
            return identifier;
        }
        public static string Camel(string value)
        {
            var pascal = Pascal(value);
            return string.IsNullOrEmpty(pascal) ? pascal : char.ToLowerInvariant(pascal[0]) + pascal[1..];
        }
        public static string Field(string path) => "_" + Camel(path.Split('/').Last());
        public static string EventMethod(string eventId, string signal) => $"On{Pascal(eventId)}{Pascal(signal)}";
        public static string SystemNameFromPackageId(string packageId) => packageId.StartsWith("ui.", StringComparison.Ordinal) ? packageId[3..] : packageId;
    }

    private static class SchemaFiles
    {
        public static readonly string[] All =
        {
            "package.schema.json",
            "layout.schema.json",
            "bindings.schema.json",
            "assets.schema.json",
            "codegen.schema.json",
            "validation.schema.json",
            "strings.schema.json",
        };

        public static string? FindBundledDirectory(string projectRoot)
        {
            var candidates = new[]
            {
                Path.Combine(projectRoot, "addons", "manifest_ui", "tooling", "schemas"),
                Path.Combine(AppContext.BaseDirectory, "schemas"),
                Path.Combine(projectRoot, "schemas", "manifest-ui"),
            };
            return candidates.FirstOrDefault(candidate => All.All(file => File.Exists(Path.Combine(candidate, file))));
        }
    }

    private static string? ResolveRequiredPackageFile(string packageDir, string? relativePath, string label, ValidationResult result)
    {
        if (string.IsNullOrWhiteSpace(relativePath))
        {
            result.Error("package.json", label, "is required");
            return null;
        }
        var resolved = ResolvePackageFile(packageDir, relativePath, "package.json", label, result);
        if (resolved is not null && !File.Exists(resolved))
        {
            result.Error("package.json", label, $"file does not exist: {relativePath}");
            return null;
        }
        return resolved;
    }

    private static string? ResolvePackageFile(string packageDir, string relativePath, string file, string logicalPath, ValidationResult result)
    {
        if (Path.IsPathRooted(relativePath))
        {
            result.Error(file, logicalPath, "must be package-relative");
            return null;
        }
        var resolved = Path.GetFullPath(Path.Combine(packageDir, relativePath));
        var relative = Path.GetRelativePath(packageDir, resolved);
        if (relative == ".." || relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
        {
            result.Error(file, logicalPath, "must stay inside the package directory");
            return null;
        }
        return resolved;
    }

    private static void ValidateProjectRelativePath(string projectRoot, string? path, string file, string logicalPath, ValidationResult result)
    {
        if (string.IsNullOrWhiteSpace(path)) return;
        if (Path.IsPathRooted(path))
        {
            result.Error(file, logicalPath, "must be project-relative");
            return;
        }
        var root = projectRoot;
        var resolved = Path.GetFullPath(Path.Combine(root, path));
        var relative = Path.GetRelativePath(root, resolved);
        if (relative == ".." || relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal))
        {
            result.Error(file, logicalPath, "must stay inside the project directory");
        }
    }

    private static void Required(string? value, string file, string logicalPath, ValidationResult result)
    {
        if (string.IsNullOrWhiteSpace(value)) result.Error(file, logicalPath, "is required");
    }

    private static bool TryReadLocalizationValue(
        JsonElement value,
        string file,
        string logicalPath,
        ValidationResult? result,
        out LocalizationValue localization)
    {
        var key = "";
        var context = "";
        var arguments = new List<string>();
        var valid = true;
        var keyWasString = false;
        if (value.ValueKind == JsonValueKind.String)
        {
            key = value.GetString() ?? "";
            keyWasString = true;
        }
        else if (value.ValueKind == JsonValueKind.Object)
        {
            var allowedFields = new HashSet<string>(StringComparer.Ordinal) { "key", "context", "arguments" };
            foreach (var property in value.EnumerateObject().OrderBy(property => property.Name, StringComparer.Ordinal))
            {
                if (!allowedFields.Contains(property.Name))
                {
                    result?.Error(file, JoinLogicalPath(logicalPath, property.Name), $"unsupported localization field '{property.Name}'");
                    valid = false;
                }
            }

            if (!value.TryGetProperty("key", out var keyElement) || keyElement.ValueKind != JsonValueKind.String)
            {
                result?.Error(file, JoinLogicalPath(logicalPath, "key"), "is required and must be a string");
                valid = false;
            }
            else
            {
                key = keyElement.GetString() ?? "";
                keyWasString = true;
            }

            if (value.TryGetProperty("context", out var contextElement))
            {
                if (contextElement.ValueKind != JsonValueKind.String)
                {
                    result?.Error(file, JoinLogicalPath(logicalPath, "context"), "must be a string");
                    valid = false;
                }
                else
                {
                    context = contextElement.GetString() ?? "";
                }
            }

            if (value.TryGetProperty("arguments", out var argumentsElement))
            {
                if (argumentsElement.ValueKind != JsonValueKind.Array)
                {
                    result?.Error(file, JoinLogicalPath(logicalPath, "arguments"), "must be an array of mvvm field ids");
                    valid = false;
                }
                else
                {
                    var index = 0;
                    foreach (var argument in argumentsElement.EnumerateArray())
                    {
                        if (argument.ValueKind != JsonValueKind.String || string.IsNullOrWhiteSpace(argument.GetString()))
                        {
                            result?.Error(file, $"{JoinLogicalPath(logicalPath, "arguments")}[{index}]", "must be a non-empty mvvm field id");
                            valid = false;
                        }
                        else
                        {
                            arguments.Add(argument.GetString()!);
                        }
                        index++;
                    }
                }
            }
        }
        else
        {
            result?.Error(file, logicalPath, "must be a localization key string or an object");
            valid = false;
        }

        if (keyWasString && string.IsNullOrWhiteSpace(key))
        {
            result?.Error(file, value.ValueKind == JsonValueKind.Object ? JoinLogicalPath(logicalPath, "key") : logicalPath, "localization key must not be empty");
            valid = false;
        }

        localization = new LocalizationValue(key, context, arguments);
        return valid;
    }

    private static string JoinLogicalPath(string prefix, string suffix)
    {
        return string.IsNullOrWhiteSpace(prefix) ? suffix : $"{prefix}.{suffix}";
    }

    private static bool TryReadAssetReference(JsonElement value, out string assetId)
    {
        assetId = "";
        if (value.ValueKind != JsonValueKind.Object
            || value.EnumerateObject().Count() != 1
            || !value.TryGetProperty("assetRef", out var assetRef)
            || assetRef.ValueKind != JsonValueKind.String)
        {
            return false;
        }

        assetId = assetRef.GetString() ?? "";
        return !string.IsNullOrWhiteSpace(assetId);
    }

    private static string ToResourcePath(string projectRoot, string path) => "res://" + Path.GetRelativePath(projectRoot, path).Replace('\\', '/');
    private static string Escape(string value) => value.Replace("\\", "\\\\").Replace("\"", "\\\"");
    private static bool IsSha256(string? value) => value is not null && value.Length == 71 && value.StartsWith("sha256:", StringComparison.Ordinal) && value[7..].All(Uri.IsHexDigit);
    private static string Sha256File(string path)
    {
        using var sha = SHA256.Create();
        using var stream = File.OpenRead(path);
        return "sha256:" + Convert.ToHexString(sha.ComputeHash(stream)).ToLowerInvariant();
    }
    private static string Sha256Text(string value)
    {
        return "sha256:" + Convert.ToHexString(SHA256.HashData(Utf8NoBom.GetBytes(NormalizeGeneratedText(value)))).ToLowerInvariant();
    }
    private static bool IsInside(string root, string path)
    {
        var relative = Path.GetRelativePath(Path.GetFullPath(root), Path.GetFullPath(path));
        return relative != ".." && !relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal) && !Path.IsPathRooted(relative);
    }
    private static bool IsDotNetNamespace(string value) => value.Split('.').All(IsCSharpIdentifier);
    private static bool IsCSharpIdentifier(string value) => value.Length > 0
        && !CSharpKeywords.Contains(value)
        && (char.IsLetter(value[0]) || value[0] == '_')
        && value.All(ch => char.IsLetterOrDigit(ch) || ch == '_');
    private static bool IsDotNetTypeName(string value)
    {
        var normalized = value.StartsWith("global::", StringComparison.Ordinal) ? value[8..] : value;
        return normalized.Split('.').All(IsCSharpIdentifier);
    }
    private static string NormalizeText(string value) => value.Replace("\r\n", "\n").Trim();

    private sealed record Target(string Path, string FieldName, LayoutNode Node, string Type);
    private sealed record PropertyBinding(string Target, string Property, string FieldId, string Converter, string Format, JsonElement? Fallback);
    private sealed record ItemBinding(string Target, string Property, string FieldId, string Converter, string Format, JsonElement? Fallback);
    private sealed record RepeaterBinding(string Target, string Template, string FieldId, List<ItemBinding> ItemBindings, string KeyFieldId, int PoolCapacity);
    private sealed record LocalizedProperty(string Target, string Property, string Key, string Context, IReadOnlyList<string> ArgumentFieldIds);
    private sealed record LocalizationValue(string Key, string Context, IReadOnlyList<string> ArgumentFieldIds);
    private sealed record InputBinding(string Target, string Property, string FieldId);
    private sealed record GeneratedAssetRef(string Id, string Kind, string Path);
    private sealed record SourceHash(string Path, string ContentHash);
    private sealed record AssetReportEntry(string Id, string Kind, string SourcePath, string ResourcePath, string ContentHash, string ThemeOutput);

    private sealed class ImportManifest
    {
        public int SchemaVersion { get; set; }
        public string GeneratorId { get; set; } = "";
        public string PackageId { get; set; } = "";
        public string DisplayName { get; set; } = "";
        public Dictionary<string, SourceHash> SourceFiles { get; set; } = new(StringComparer.Ordinal);
        public ReportCounts Counts { get; set; } = new();
        public List<AssetReportEntry> Assets { get; set; } = new();
    }
    private sealed class ReportCounts
    {
        public int Nodes { get; set; }
        public int Fields { get; set; }
        public int Events { get; set; }
        public int Channels { get; set; }
        public int Assets { get; set; }
    }
    private sealed class PackageJson
    {
        public int SchemaVersion { get; set; }
        public string PackageId { get; set; } = "";
        public string DisplayName { get; set; } = "";
        public int[] DesignResolution { get; set; } = Array.Empty<int>();
        public string Assets { get; set; } = "";
        public string Layout { get; set; } = "";
        public string Bindings { get; set; } = "";
        public string Codegen { get; set; } = "";
        public string Validation { get; set; } = "";
        public string Strings { get; set; } = "";
        public RuntimeJson Runtime { get; set; } = new();
        public GodotPackageJson Godot { get; set; } = new();
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class RuntimeJson
    {
        public string ControllerScope { get; set; } = "package";
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class GodotPackageJson
    {
        public string SystemName { get; set; } = "";
        public string WidgetClass { get; set; } = "";
        public string ControllerClass { get; set; } = "";
        public string Namespace { get; set; } = "";
        public string OutputDir { get; set; } = "";
        public string ScenePath { get; set; } = "";
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class LayoutJson
    {
        public LayoutNode Root { get; set; } = new();
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class LayoutNode
    {
        public string Id { get; set; } = "";
        public string Type { get; set; } = "";
        public string Name { get; set; } = "";
        public string ScenePath { get; set; } = "";
        public string ScriptPath { get; set; } = "";
        public Dictionary<string, JsonElement> Properties { get; set; } = new(StringComparer.Ordinal);
        public Dictionary<string, JsonElement> Localization { get; set; } = new(StringComparer.Ordinal);
        public List<LayoutNode> Children { get; set; } = new();
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class BindingsJson
    {
        public MvvmJson Mvvm { get; set; } = new();
        public Dictionary<string, JsonElement> Bindings { get; set; } = new(StringComparer.Ordinal);
        public List<RepeaterJson> Repeaters { get; set; } = new();
        public List<InputJson> Inputs { get; set; } = new();
        public List<ControlBinding> Controls { get; set; } = new();
        public JsonElement Events { get; set; }
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class MvvmJson
    {
        public string UpdatePolicy { get; set; } = "manual";
        public List<MvvmField> Fields { get; set; } = new();
    }
    private sealed class MvvmField
    {
        public string Id { get; set; } = "";
        public string Path { get; set; } = "";
        public string Value { get; set; } = "";
        public string Collection { get; set; } = "none";
        public bool ControllerOnlySideEffect { get; set; }
    }
    private sealed class ControlBinding
    {
        public string Id { get; set; } = "";
        public string Target { get; set; } = "";
        public string WidgetClass { get; set; } = "";
        public List<ControlEvent> Events { get; set; } = new();
    }
    private sealed class RepeaterJson
    {
        public string Id { get; set; } = "";
        public string Target { get; set; } = "";
        public string Template { get; set; } = "";
        public string Source { get; set; } = "";
        public Dictionary<string, JsonElement> Bindings { get; set; } = new(StringComparer.Ordinal);
        public string KeyFieldId { get; set; } = "";
        public int PoolCapacity { get; set; } = 32;
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class InputJson
    {
        public string Id { get; set; } = "";
        public string Target { get; set; } = "";
        public string Property { get; set; } = "";
        public string Source { get; set; } = "";
    }
    private sealed class ControlEvent
    {
        public string Event { get; set; } = "";
        public string Handler { get; set; } = "";
        public string Channel { get; set; } = "";
    }
    private sealed class EventBinding
    {
        public string EventId { get; set; } = "";
        public string Target { get; set; } = "";
        public string Signal { get; set; } = "";
        public string Channel { get; set; } = "";
        public string Scope { get; set; } = "";
        public string Dispatch { get; set; } = "immediate";
    }
    private sealed class EventChannel
    {
        public string Id { get; set; } = "";
        public string Scope { get; set; } = "";
        public string Dispatch { get; set; } = "";
        public List<string> Payload { get; set; } = new();
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class AssetsJson
    {
        public List<AssetEntry> Assets { get; set; } = new();
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class AssetEntry
    {
        public string Id { get; set; } = "";
        public string RelativePath { get; set; } = "";
        public string Kind { get; set; } = "";
        public string ContentHash { get; set; } = "";
        public int[]? Size { get; set; }
        public Dictionary<string, JsonElement> Import { get; set; } = new(StringComparer.Ordinal);
        public bool DefaultFont { get; set; }
        public int DefaultFontSize { get; set; }
        public ThemeAssetConfig Theme { get; set; } = new();
    }
    private sealed class ThemeAssetConfig
    {
        public string OutputPath { get; set; } = "";
        public string DefaultFontAssetId { get; set; } = "";
        public int DefaultFontSize { get; set; }
        public List<ThemeTypeVariation> TypeVariations { get; set; } = new();
    }
    private sealed class ThemeTypeVariation
    {
        public string Id { get; set; } = "";
        public string BaseType { get; set; } = "";
    }
    private sealed class CodegenJson
    {
        public int SchemaVersion { get; set; }
        public string Generator { get; set; } = "";
        public List<RequiredServiceJson> RequiredServices { get; set; } = new();
        public List<RouteJson> Routes { get; set; } = new();
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class RequiredServiceJson
    {
        public string Type { get; set; } = "";
        public string Property { get; set; } = "";
        public string Key { get; set; } = "";
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class RouteJson
    {
        public string Channel { get; set; } = "";
        public string Action { get; set; } = "";
        public string PackageId { get; set; } = "";
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class ValidationJson
    {
        public List<string> CommandletInputWhitelist { get; set; } = new();
        public Dictionary<string, JsonElement> Checks { get; set; } = new(StringComparer.Ordinal);
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
    private sealed class StringsJson
    {
        public int SchemaVersion { get; set; }
        public string DefaultLocale { get; set; } = "";
        public List<string> Locales { get; set; } = new();
        public Dictionary<string, Dictionary<string, string>> Strings { get; set; } = new(StringComparer.Ordinal);
        [JsonExtensionData]
        public Dictionary<string, JsonElement> Extra { get; set; } = new(StringComparer.Ordinal);
    }
}

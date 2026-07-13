using Godot;
using GodotUi.Manifest.EngineTooling;
using GodotUi.Manifest.Tooling;
using System;
using System.IO;
using System.Text.Json;

namespace GodotUi.Manifest.EngineTooling;

public partial class ManifestUiExportRunner : Node
{
    public override void _Ready()
    {
        var result = Run();
        GetTree().Quit(result.ExitCode);
    }

    private static ManifestUiToolResult Run()
    {
        var args = OS.GetCmdlineUserArgs();
        var requestIndex = Array.IndexOf(args, "--manifest-ui-export-request");
        if (requestIndex < 0 || requestIndex + 1 >= args.Length)
        {
            return new ManifestUiToolResult { ExitCode = ManifestUiTool.UsageOrEnvironmentFailure };
        }

        var requestPath = args[requestIndex + 1];
        using var request = JsonDocument.Parse(File.ReadAllText(requestPath));
        var packagePath = request.RootElement.GetProperty("packagePath").GetString() ?? "";
        var resultPath = request.RootElement.GetProperty("resultPath").GetString() ?? "";
        var result = ManifestUiSceneExporter.Export(packagePath);
        Directory.CreateDirectory(Path.GetDirectoryName(resultPath)!);
        File.WriteAllText(resultPath, JsonSerializer.Serialize(result, new JsonSerializerOptions
        {
            WriteIndented = true,
            PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        }));
        return result;
    }
}

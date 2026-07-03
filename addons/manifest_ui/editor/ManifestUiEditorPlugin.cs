#if TOOLS
#pragma warning disable CS0618
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Godot;

namespace GodotUi.Manifest.Editor;

[Tool]
public partial class ManifestUiEditorPlugin : EditorPlugin
{
    private readonly (string Name, string Path)[] _autoloads =
    {
        ("ManifestMessageBus", "res://addons/manifest_ui/autoload/ManifestMessageBus.cs"),
        ("ManifestUiRoot", "res://addons/manifest_ui/autoload/ManifestUiRoot.cs"),
        ("ManifestUiManager", "res://addons/manifest_ui/autoload/ManifestUiManager.cs"),
    };

    private VBoxContainer? _dock;
    private OptionButton? _packages;
    private Label? _status;
    private ItemList? _diagnosticsList;
    private TextEdit? _output;
    private Button? _openReport;
    private readonly List<Button> _actionButtons = new();
    private readonly List<Button> _packageButtons = new();
    private readonly List<ManifestEditorDiagnostic> _diagnostics = new();

    public override void _EnterTree()
    {
        EnsureAutoloads();
        BuildDock();
    }

    public override void _ExitTree()
    {
        if (_dock is not null)
        {
            RemoveControlFromDocks(_dock);
            _dock.QueueFree();
            _dock = null;
        }

        RemoveOwnedAutoloads();
    }

    private void EnsureAutoloads()
    {
        foreach (var (name, path) in _autoloads)
        {
            if (!ProjectSettings.HasSetting($"autoload/{name}"))
            {
                AddAutoloadSingleton(name, path);
            }
        }
    }

    private void RemoveOwnedAutoloads()
    {
        foreach (var (name, path) in _autoloads)
        {
            var setting = $"autoload/{name}";
            if (ProjectSettings.HasSetting(setting) && (ProjectSettings.GetSetting(setting).AsString().Contains(path, StringComparison.Ordinal)))
            {
                RemoveAutoloadSingleton(name);
            }
        }
    }

    private void BuildDock()
    {
        _dock = new VBoxContainer { Name = "Manifest UI" };
        _packages = new OptionButton();
        _status = new Label { Text = "Ready." };
        _diagnosticsList = new ItemList
        {
            CustomMinimumSize = new Vector2(0, 140),
            AllowReselect = true,
        };
        _output = new TextEdit
        {
            CustomMinimumSize = new Vector2(0, 180),
            Editable = false,
        };

        var refresh = new Button { Text = "Refresh Packages" };
        var validate = new Button { Text = "Validate" };
        var report = new Button { Text = "Validate Report" };
        var generate = new Button { Text = "Generate" };
        var importAssets = new Button { Text = "Import Assets" };
        _openReport = new Button { Text = "Open Report", Disabled = true };
        _actionButtons.Clear();
        _actionButtons.AddRange(new[] { refresh, validate, report, generate, importAssets, _openReport });
        _packageButtons.Clear();
        _packageButtons.AddRange(new[] { validate, report, generate, importAssets, _openReport });

        refresh.Pressed += RefreshPackages;
        validate.Pressed += () => RunGenerator("validate", false);
        report.Pressed += () => RunGenerator("validate", true);
        generate.Pressed += () => RunGenerator("generate", false);
        importAssets.Pressed += RunAssetImport;
        _openReport.Pressed += OpenReport;
        _diagnosticsList.ItemSelected += OnDiagnosticSelected;
        _packages.ItemSelected += _ => UpdatePackageState(true);

        _dock.AddChild(_packages);
        _dock.AddChild(refresh);
        _dock.AddChild(validate);
        _dock.AddChild(report);
        _dock.AddChild(generate);
        _dock.AddChild(importAssets);
        _dock.AddChild(_openReport);
        _dock.AddChild(_status);
        _dock.AddChild(new Label { Text = "Diagnostics" });
        _dock.AddChild(_diagnosticsList);
        _dock.AddChild(new Label { Text = "Raw Output" });
        _dock.AddChild(_output);
        AddControlToDock(DockSlot.LeftUl, _dock);
        RefreshPackages();
    }

    private void RefreshPackages()
    {
        if (_packages is null)
        {
            return;
        }

        _packages.Clear();
        ClearDiagnostics();
        var root = ProjectSettings.GlobalizePath("res://");
        var uiDir = Path.Combine(root, "ui");
        if (!Directory.Exists(uiDir))
        {
            Log("ui directory not found.", "No ui directory.");
            return;
        }

        foreach (var packagePath in Directory.GetDirectories(uiDir).Select(dir => Path.Combine(dir, "package.json")).Where(File.Exists).OrderBy(path => path, StringComparer.Ordinal))
        {
            _packages.AddItem(Path.GetRelativePath(root, packagePath).Replace('\\', '/'));
        }

        SetStatus($"Found {_packages.ItemCount} package(s).");
        UpdatePackageState(true);
    }

    private void RunGenerator(string command, bool writeReport)
    {
        if (_packages is null || _output is null || _packages.ItemCount == 0)
        {
            Log("No package selected.", "No package selected.");
            return;
        }

        var root = ProjectSettings.GlobalizePath("res://");
        var package = _packages.GetItemText(_packages.Selected);
        var arguments = writeReport
            ? $"run --project tools/ManifestUiGen -- {command} {package} --write-report"
            : $"run --project tools/ManifestUiGen -- {command} {package}";

        var process = new Process
        {
            StartInfo = new ProcessStartInfo("dotnet", arguments)
            {
                WorkingDirectory = root,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
                CreateNoWindow = true,
            },
        };

        SetBusy(true);
        SetStatus($"Running {command}...");
        try
        {
            process.Start();
            var stdout = process.StandardOutput.ReadToEnd();
            var stderr = process.StandardError.ReadToEnd();
            process.WaitForExit();
            var rawOutput = $"> dotnet {arguments}\n{stdout}{stderr}\nExitCode: {process.ExitCode}";
            ParseDiagnostics(stdout + stderr);
            Log(rawOutput, $"{command} exit {process.ExitCode}. Diagnostics: {_diagnostics.Count}");
            if (process.ExitCode == 0 && command == "generate")
            {
                EditorInterface.Singleton.GetResourceFilesystem().Scan();
            }
            UpdatePackageState(false);
        }
        finally
        {
            SetBusy(false);
        }
    }

    private void RunAssetImport()
    {
        if (_packages is null || _output is null || _packages.ItemCount == 0)
        {
            Log("No package selected.", "No package selected.");
            return;
        }

        SetBusy(true);
        var root = ProjectSettings.GlobalizePath("res://");
        var package = _packages.GetItemText(_packages.Selected);
        var packageDir = Path.GetDirectoryName(package)?.Replace('\\', '/') ?? "";
        var assetsDir = $"res://{packageDir}/assets";
        var globalAssetsDir = ProjectSettings.GlobalizePath(assetsDir);
        var assetFiles = Directory.Exists(globalAssetsDir)
            ? Directory.GetFiles(globalAssetsDir, "*", SearchOption.AllDirectories)
                .Where(path => !path.EndsWith(".import", StringComparison.Ordinal))
                .Select(path => "res://" + Path.GetRelativePath(root, path).Replace('\\', '/'))
                .OrderBy(path => path, StringComparer.Ordinal)
                .ToArray()
            : Array.Empty<string>();

        try
        {
            var filesystem = EditorInterface.Singleton.GetResourceFilesystem();
            filesystem.Scan();
            if (assetFiles.Length > 0)
            {
                filesystem.ReimportFiles(assetFiles);
            }

            var message = assetFiles.Length == 0
                ? $"No asset files found in {assetsDir}."
                : $"Requested Godot asset import refresh for {assetsDir}\nFiles: {assetFiles.Length}";
            ClearDiagnostics();
            Log(message, assetFiles.Length == 0 ? "No assets to import." : $"Import refresh requested for {assetFiles.Length} asset(s).");
        }
        finally
        {
            SetBusy(false);
        }
    }

    private void OpenReport()
    {
        if (!HasSelectedPackage())
        {
            SetStatus("No package selected.");
            return;
        }

        var reportPath = GetSelectedPackageResourceDir() + "/export/manifest_report.md";
        if (!File.Exists(ProjectSettings.GlobalizePath(reportPath)))
        {
            SetStatus($"Report not found: {reportPath}");
            return;
        }

        NavigateTo(reportPath, "report");
    }

    private void OnDiagnosticSelected(long index)
    {
        if (index < 0 || index >= _diagnostics.Count)
        {
            return;
        }

        var diagnostic = _diagnostics[(int)index];
        var path = ResolveDiagnosticResourcePath(diagnostic);
        NavigateTo(path, diagnostic.LogicalPath);
    }

    private void NavigateTo(string resourcePath, string logicalPath)
    {
        EditorInterface.Singleton.GetFileSystemDock().NavigateToPath(resourcePath);
        SetStatus(string.IsNullOrWhiteSpace(logicalPath) ? $"Selected {resourcePath}" : $"Selected {resourcePath} :: {logicalPath}");
    }

    private string ResolveDiagnosticResourcePath(ManifestEditorDiagnostic diagnostic)
    {
        var normalizedFile = diagnostic.File.Replace('\\', '/');
        if (normalizedFile.StartsWith("res://", StringComparison.Ordinal) && File.Exists(ProjectSettings.GlobalizePath(normalizedFile)))
        {
            return normalizedFile;
        }

        var root = ProjectSettings.GlobalizePath("res://");
        if (Path.IsPathRooted(normalizedFile) && normalizedFile.StartsWith(root.Replace('\\', '/'), StringComparison.OrdinalIgnoreCase))
        {
            normalizedFile = Path.GetRelativePath(root, normalizedFile).Replace('\\', '/');
        }

        var packagePath = GetSelectedPackageResourceDir();
        var inPackage = $"{packagePath}/{normalizedFile}";
        if (File.Exists(ProjectSettings.GlobalizePath(inPackage)))
        {
            return inPackage;
        }

        var projectPath = $"res://{normalizedFile}";
        var looksProjectRelative = normalizedFile.StartsWith("ui/", StringComparison.Ordinal)
            || normalizedFile.StartsWith("generated/", StringComparison.Ordinal)
            || normalizedFile.StartsWith("addons/", StringComparison.Ordinal)
            || normalizedFile.StartsWith("schemas/manifest-ui/", StringComparison.Ordinal);
        return looksProjectRelative && File.Exists(ProjectSettings.GlobalizePath(projectPath)) ? projectPath : $"{packagePath}/package.json";
    }

    private string GetSelectedPackageResourceDir()
    {
        if (_packages is null || _packages.ItemCount == 0)
        {
            return "res://ui";
        }

        var package = _packages.GetItemText(_packages.Selected);
        var packageDir = Path.GetDirectoryName(package)?.Replace('\\', '/') ?? "";
        return $"res://{packageDir}";
    }

    private void ParseDiagnostics(string output)
    {
        ClearDiagnostics();
        foreach (var rawLine in output.Split(new[] { "\r\n", "\n" }, StringSplitOptions.RemoveEmptyEntries))
        {
            var severity = rawLine.StartsWith("ERROR: ", StringComparison.Ordinal)
                ? "ERROR"
                : rawLine.StartsWith("WARN: ", StringComparison.Ordinal) ? "WARN" : "";
            if (severity.Length == 0)
            {
                continue;
            }

            var body = rawLine[(severity.Length + 2)..].Trim();
            var colon = body.IndexOf(':');
            if (colon < 0)
            {
                AddDiagnostic(new ManifestEditorDiagnostic(severity, "package.json", "", body));
                continue;
            }

            var path = body[..colon].Trim();
            var message = body[(colon + 1)..].Trim();
            var (file, logicalPath) = SplitDiagnosticPath(path);
            AddDiagnostic(new ManifestEditorDiagnostic(severity, file, logicalPath, message));
        }

        if (_diagnostics.Count == 0 && _diagnosticsList is not null)
        {
            _diagnosticsList.AddItem("No diagnostics.");
            _diagnosticsList.SetItemDisabled(0, true);
        }
    }

    private static (string File, string LogicalPath) SplitDiagnosticPath(string path)
    {
        var json = path.LastIndexOf(".json", StringComparison.Ordinal);
        if (json >= 0)
        {
            var file = path[..(json + 5)];
            var logical = path.Length > json + 5 && path[json + 5] == '.' ? path[(json + 6)..] : "";
            return (file, logical);
        }

        return (path, "");
    }

    private void AddDiagnostic(ManifestEditorDiagnostic diagnostic)
    {
        _diagnostics.Add(diagnostic);
        _diagnosticsList?.AddItem($"{diagnostic.Severity}: {diagnostic.File}{(string.IsNullOrWhiteSpace(diagnostic.LogicalPath) ? "" : "." + diagnostic.LogicalPath)} - {diagnostic.Message}");
    }

    private void ClearDiagnostics()
    {
        _diagnostics.Clear();
        _diagnosticsList?.Clear();
    }

    private void UpdateReportButton()
    {
        if (_openReport is null)
        {
            return;
        }

        var reportPath = GetSelectedPackageResourceDir() + "/export/manifest_report.md";
        _openReport.Disabled = !HasSelectedPackage() || !File.Exists(ProjectSettings.GlobalizePath(reportPath));
    }

    private void UpdatePackageState(bool updateStatus)
    {
        var hasPackage = HasSelectedPackage();
        foreach (var button in _packageButtons)
        {
            button.Disabled = !hasPackage;
        }

        UpdateReportButton();
        if (!updateStatus)
        {
            return;
        }

        if (hasPackage && _packages is not null)
        {
            SetStatus($"Selected {_packages.GetItemText(_packages.Selected)}.");
        }
        else
        {
            SetStatus("No packages found.");
        }
    }

    private void SetBusy(bool busy)
    {
        foreach (var button in _actionButtons)
        {
            button.Disabled = busy;
        }
        _packages?.SetDisabled(busy);
        if (!busy)
        {
            UpdatePackageState(false);
        }
    }

    private bool HasSelectedPackage()
    {
        return _packages is not null && _packages.ItemCount > 0 && _packages.Selected >= 0;
    }

    private void SetStatus(string message)
    {
        if (_status is not null)
        {
            _status.Text = message;
        }
    }

    private void Log(string message, string status)
    {
        if (_output is not null)
        {
            _output.Text = message;
        }
        SetStatus(status);
        GD.Print(message);
    }

    private sealed record ManifestEditorDiagnostic(string Severity, string File, string LogicalPath, string Message);
}
#endif

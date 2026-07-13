#if TOOLS
using Godot;
using GodotUi.Manifest.EngineTooling;
using GodotUi.Manifest.Tooling;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace GodotUi.Manifest.Editor;

[Tool]
internal partial class ManifestUiDock : VBoxContainer, IManifestUiAssemblyUnloadParticipant
{
    internal const string SourceRootsSetting = "manifest_ui/source_roots";
    internal const string GeneratedRootSetting = "manifest_ui/generated_root";
    private const string EditorBridgeMeta = "manifest_ui_editor_bridge";
    private const string OperationButtonMeta = "manifest_ui_operation_button";
    private const string PackagesControlName = "ManifestUiPackages";
    private const string StatusControlName = "ManifestUiStatus";
    private const string DiagnosticsControlName = "ManifestUiDiagnostics";
    private const string OutputControlName = "ManifestUiOutput";
    private const string CancelControlName = "ManifestUiCancel";

    private readonly List<string> _packagePaths = new();
    private readonly List<ManifestDiagnostic> _diagnostics = new();
    private readonly List<BaseButton> _operationButtons = new();
    private readonly List<string> _logLines = new();

    private bool _initialized;
    private bool _rehydrating;
    private bool _packageDiscoveryPerformed;
    private OptionButton? _packages;
    private Label? _status;
    private ItemList? _diagnosticsList;
    private TextEdit? _output;
    private Button? _cancelButton;
    private bool _toolRunning;
    private string _currentOperation = "";
    private LineEdit? _settingsRoots;
    private LineEdit? _settingsGenerated;
    private LineEdit? _newPackageId;
    private LineEdit? _newPackageDisplayName;
    private string _pendingSkillSource = "";
    private string _pendingSkillDestination = "";
    private bool _pendingSkillBackup;
    private bool _generatedRefreshPending;
    private bool _generatedRefreshActivityLogged;
    private int _generatedRefreshFrames;
    private string _generatedSceneToReload = "";
    private GodotObject? _editorBridge;

    public void Initialize(GodotObject editorBridge)
    {
        _editorBridge = editorBridge;
        SetMeta(EditorBridgeMeta, editorBridge);
        Log("Initialize", $"Editor bridge attached: {editorBridge.GetClass()}.");
        Initialize();
    }

    public void Initialize()
    {
        if (_initialized)
        {
            return;
        }

        _initialized = true;
        Log("Initialize", "Building Manifest UI Dock.");
        ManifestUiAssemblyUnloadRegistry.Register(this);
        Name = "Manifest UI";
        SizeFlagsHorizontal = SizeFlags.ExpandFill;
        SizeFlagsVertical = SizeFlags.ExpandFill;
        SetProcess(false);
        BuildUi();
        RefreshPackages();
        Log("Initialize", $"Dock ready with {_packagePaths.Count} discovered package(s).");
    }

    public override void _Ready()
    {
        Initialize();
    }

    public override void _ExitTree()
    {
        PrepareForAssemblyUnload();
        ManifestUiAssemblyUnloadRegistry.Unregister(this);
    }

    public void PrepareForAssemblyUnload()
    {
        Log("Assembly", "Preparing editor dock for assembly unload.");
        _toolRunning = false;
    }

    private void BuildUi()
    {
        var header = new HBoxContainer();
        var title = new Label
        {
            Text = "Manifest UI",
            SizeFlagsHorizontal = SizeFlags.ExpandFill,
        };
        title.AddThemeFontSizeOverride("font_size", 16);
        header.AddChild(title);

        var settings = CreateButton("Settings", nameof(ShowSettings));
        settings.TooltipText = "Configure source roots and generated output";
        header.AddChild(settings);
        AddChild(header);

        _packages = new OptionButton
        {
            Name = PackagesControlName,
            SizeFlagsHorizontal = SizeFlags.ExpandFill,
            TooltipText = "Manifest package",
        };
        _packages.Connect(OptionButton.SignalName.ItemSelected, new Callable(this, nameof(OnPackageSelected)));
        AddChild(_packages);

        var packageActions = new GridContainer { Columns = 3 };
        packageActions.AddChild(CreateOperationButton("Refresh", nameof(RunRefreshPackages)));
        packageActions.AddChild(CreateOperationButton("New", nameof(ShowNewPackageDialog)));
        packageActions.AddChild(CreateOperationButton("Doctor", nameof(RunDoctor)));
        packageActions.AddChild(CreateOperationButton("Validate", nameof(RunValidate)));
        packageActions.AddChild(CreateOperationButton("Generate", nameof(RunGenerate)));
        packageActions.AddChild(CreateOperationButton("Export JSON", nameof(RunExportJson)));
        packageActions.AddChild(CreateOperationButton("Verify", nameof(RunVerify)));
        packageActions.AddChild(CreateOperationButton("Preview", nameof(RunPreview)));
        packageActions.AddChild(CreateOperationButton("Run Preview", nameof(RunInteractivePreview)));
        packageActions.AddChild(CreateOperationButton("Check All", nameof(RunCheckAll)));
        packageActions.AddChild(CreateOperationButton("Report", nameof(OpenReport)));
        packageActions.AddChild(CreateOperationButton("Reimport", nameof(ReimportAssets)));
        packageActions.AddChild(CreateOperationButton("Install Skill", nameof(InstallSkill)));
        AddChild(packageActions);

        _cancelButton = CreateButton("Cancel", nameof(CancelOperation));
        _cancelButton.Name = CancelControlName;
        _cancelButton.Disabled = true;
        _cancelButton.TooltipText = "Ignore the result of the active operation";
        AddChild(_cancelButton);

        _status = new Label
        {
            Name = StatusControlName,
            Text = "Ready.",
            AutowrapMode = TextServer.AutowrapMode.WordSmart,
        };
        AddChild(_status);

        AddChild(new Label { Text = "Diagnostics" });
        _diagnosticsList = new ItemList
        {
            Name = DiagnosticsControlName,
            CustomMinimumSize = new Vector2(0, 170),
            SizeFlagsVertical = SizeFlags.ExpandFill,
            AllowReselect = true,
        };
        _diagnosticsList.Connect(ItemList.SignalName.ItemSelected, new Callable(this, nameof(OnDiagnosticSelected)));
        AddChild(_diagnosticsList);

        AddChild(new Label { Text = "Output" });
        _output = new TextEdit
        {
            Name = OutputControlName,
            CustomMinimumSize = new Vector2(0, 150),
            Editable = false,
            WrapMode = TextEdit.LineWrappingMode.Boundary,
            SizeFlagsVertical = SizeFlags.ExpandFill,
        };
        AddChild(_output);
        RefreshLogOutput();
    }

    private void Log(string phase, string message)
    {
        var line = $"[{DateTime.Now:HH:mm:ss.fff}] [Manifest UI] [{phase}] {message}";
        _logLines.Add(line);
        if (_logLines.Count > 300)
        {
            _logLines.RemoveRange(0, _logLines.Count - 300);
        }
        GD.Print(line);
        RefreshLogOutput();
    }

    private void RefreshLogOutput()
    {
        if (_output is null)
        {
            return;
        }
        _output.Text = string.Join(System.Environment.NewLine, _logLines);
        _output.ScrollVertical = int.MaxValue;
    }

    private void EnsureDockState()
    {
        if (_rehydrating)
        {
            return;
        }

        var controlsValid = IsValid(_packages) && IsValid(_status) && IsValid(_diagnosticsList) && IsValid(_output) && IsValid(_cancelButton);
        var packageStateValid = controlsValid
            && _packageDiscoveryPerformed
            && _packagePaths.Count == _packages!.ItemCount
            && (_packages.ItemCount == 0 || (_packages.Selected >= 0 && _packages.Selected < _packages.ItemCount));
        if (packageStateValid && _editorBridge is not null && GodotObject.IsInstanceValid(_editorBridge))
        {
            return;
        }

        _rehydrating = true;
        var recoveredControls = false;
        try
        {
            _packages = FindChild(PackagesControlName, recursive: true, owned: false) as OptionButton;
            _status = FindChild(StatusControlName, recursive: true, owned: false) as Label;
            _diagnosticsList = FindChild(DiagnosticsControlName, recursive: true, owned: false) as ItemList;
            _output = FindChild(OutputControlName, recursive: true, owned: false) as TextEdit;
            _cancelButton = FindChild(CancelControlName, recursive: true, owned: false) as Button;
            recoveredControls = IsValid(_packages) && IsValid(_status) && IsValid(_diagnosticsList) && IsValid(_output) && IsValid(_cancelButton);

            _operationButtons.Clear();
            CollectOperationButtons(this, _operationButtons);

            if ((_editorBridge is null || !GodotObject.IsInstanceValid(_editorBridge)) && HasMeta(EditorBridgeMeta))
            {
                _editorBridge = GetMeta(EditorBridgeMeta).AsGodotObject();
            }

            if (_logLines.Count == 0 && _output is not null && !string.IsNullOrWhiteSpace(_output.Text))
            {
                _logLines.AddRange(_output.Text.Split(new[] { "\r\n", "\n" }, StringSplitOptions.RemoveEmptyEntries).TakeLast(300));
            }

            ManifestUiAssemblyUnloadRegistry.Register(this);
            _initialized = true;
        }
        finally
        {
            _rehydrating = false;
        }

        Log("HotReload", $"Rehydrated managed state: controls={recoveredControls}, operationButtons={_operationButtons.Count}, bridge={_editorBridge is not null && GodotObject.IsInstanceValid(_editorBridge)}.");
        if (!packageStateValid)
        {
            RefreshPackages();
        }
    }

    private static bool IsValid(GodotObject? value)
    {
        return value is not null && GodotObject.IsInstanceValid(value);
    }

    private static void CollectOperationButtons(Node node, List<BaseButton> result)
    {
        foreach (var child in node.GetChildren())
        {
            if (child is BaseButton button && child.HasMeta(OperationButtonMeta) && child.GetMeta(OperationButtonMeta).AsBool())
            {
                result.Add(button);
            }
            CollectOperationButtons(child, result);
        }
    }

    private Button CreateOperationButton(string text, string methodName)
    {
        var button = CreateButton(text, methodName);
        button.SetMeta(OperationButtonMeta, true);
        button.CustomMinimumSize = new Vector2(88, 32);
        _operationButtons.Add(button);
        return button;
    }

    private Button CreateButton(string text, string methodName)
    {
        var button = new Button { Text = text };
        button.Connect(BaseButton.SignalName.Pressed, new Callable(this, methodName));
        return button;
    }

    private void OnPackageSelected(long index)
    {
        EnsureDockState();
        UpdatePackageStatus();
    }

    private void RunRefreshPackages()
    {
        EnsureDockState();
        RefreshPackages();
    }

    private void RunValidate()
    {
        RunForPackage("Validate", "validate", "--write-report");
    }

    private void RunGenerate()
    {
        EnsureDockState();
        var package = SelectedPackagePath();
        Log("Generate", $"Requested for {(package is null ? "<none>" : ToResourcePath(package))}.");
        if (package is not null && TryReadPreview(package, out var scenePath, out _, out _))
        {
            var unsavedScenes = EditorInterface.Singleton.GetUnsavedScenes();
            if (unsavedScenes.Contains(scenePath, StringComparer.Ordinal))
            {
                SetStatus($"Cannot generate while {scenePath} has unsaved editor changes.", true);
                Log("Generate", $"Blocked because {scenePath} has unsaved editor changes.");
                return;
            }
        }
        if (package is null || _toolRunning || _generatedRefreshPending)
        {
            Log("Generate", "Ignored because no package is selected or another operation is active.");
            return;
        }

        RunTool("Generate", "generate", package, "--project", ProjectRoot());
    }

    private void RunExportJson()
    {
        EnsureDockState();
        var package = SelectedPackagePath();
        if (package is null || _toolRunning || _generatedRefreshPending)
        {
            SetStatus("Select a package and wait for the current operation to finish.", true);
            return;
        }
        if (!TryReadPreview(package, out var scenePath, out _, out var error))
        {
            SetStatus($"Could not resolve package scene: {error}", true);
            return;
        }
        if (EditorInterface.Singleton.GetUnsavedScenes().Contains(scenePath, StringComparer.Ordinal))
        {
            SetStatus($"Save {scenePath} before exporting JSON.", true);
            return;
        }

        _currentOperation = "Export JSON";
        _toolRunning = true;
        SetBusy(true);
        SetStatus("Export JSON running...", false);
        Log("Export JSON", $"Exporting {scenePath} into manifest source JSON.");
        ManifestUiToolResult result;
        try
        {
            result = ManifestUiSceneExporter.Export(package);
        }
        catch (Exception exception)
        {
            result = new ManifestUiToolResult
            {
                ExitCode = ManifestUiTool.InternalFailure,
                Diagnostics = new[]
                {
                    new ManifestDiagnostic("MUI4100", ManifestDiagnosticSeverity.Error, scenePath, "/export", 0, 0, exception.Message),
                },
            };
        }
        FinishOperation(result, canceled: false);
        if (result.Success)
        {
            EditorInterface.Singleton.GetResourceFilesystem().CallDeferred(EditorFileSystem.MethodName.Scan);
            SetStatus("Export JSON succeeded. Manifest sources are current; Generate was not run.", false);
        }
    }

    private void RunVerify()
    {
        VerifySelected(showResult: true);
    }

    private void RunPreview()
    {
        PreviewSelected(run: false);
    }

    private void RunInteractivePreview()
    {
        PreviewSelected(run: true);
    }

    private void RunCheckAll()
    {
        RunTool("Check All", "check", "--project", ProjectRoot());
    }

    private void ConnectDialog(ConfirmationDialog dialog, string confirmedMethod, string canceledMethod)
    {
        dialog.Connect(ConfirmationDialog.SignalName.Confirmed, new Callable(this, confirmedMethod));
        dialog.Connect(ConfirmationDialog.SignalName.Canceled, new Callable(this, canceledMethod));
        var queueFree = new Callable(dialog, Node.MethodName.QueueFree);
        dialog.Connect(ConfirmationDialog.SignalName.Confirmed, queueFree);
        dialog.Connect(ConfirmationDialog.SignalName.Canceled, queueFree);
    }

    private void RefreshPackages()
    {
        Log("Packages", "Refreshing configured source roots.");
        if (_packages is null)
        {
            return;
        }

        var previous = _packages.Selected >= 0 && _packages.Selected < _packagePaths.Count
            ? _packagePaths[_packages.Selected]
            : null;
        var previousLabel = _packages.Selected >= 0 && _packages.Selected < _packages.ItemCount
            ? _packages.GetItemText(_packages.Selected)
            : _packages.Text;
        _packagePaths.Clear();
        _packages.Clear();

        foreach (var sourceRoot in GetSourceRoots())
        {
            var globalRoot = ProjectSettings.GlobalizePath(sourceRoot);
            if (!Directory.Exists(globalRoot))
            {
                continue;
            }

            foreach (var path in Directory.EnumerateFiles(globalRoot, "package.json", SearchOption.AllDirectories))
            {
                var resourcePath = ToResourcePath(path);
                if (IsExcluded(resourcePath))
                {
                    continue;
                }
                _packagePaths.Add(path);
            }
        }

        _packagePaths.Sort(StringComparer.OrdinalIgnoreCase);
        foreach (var path in _packagePaths)
        {
            _packages.AddItem(ToResourcePath(path).TrimStart("res://".ToCharArray()));
            _packages.SetItemMetadata(_packages.ItemCount - 1, path);
        }

        var selected = previous is null ? -1 : _packagePaths.FindIndex(path => string.Equals(path, previous, StringComparison.OrdinalIgnoreCase));
        if (selected < 0 && !string.IsNullOrWhiteSpace(previousLabel))
        {
            selected = _packagePaths.FindIndex(path => string.Equals(ToResourcePath(path).TrimStart("res://".ToCharArray()), previousLabel, StringComparison.OrdinalIgnoreCase));
        }
        if (_packagePaths.Count > 0)
        {
            _packages.Select(selected >= 0 ? selected : 0);
        }

        SetStatus(_packagePaths.Count == 0 ? "No packages found." : $"Found {_packagePaths.Count} package(s).", false);
        _packageDiscoveryPerformed = true;
        UpdatePackageStatus();
        var selectedPath = SelectedPackagePath();
        Log("Packages", selectedPath is null
            ? "Package discovery completed with no selection."
            : $"Discovered {_packagePaths.Count} package(s); selected {ToResourcePath(selectedPath)}.");
    }

    private IEnumerable<string> GetSourceRoots()
    {
        if (!ProjectSettings.HasSetting(SourceRootsSetting))
        {
            return new[] { "res://ui" };
        }

        var value = ProjectSettings.GetSetting(SourceRootsSetting);
        if (value.VariantType == Variant.Type.PackedStringArray)
        {
            return value.AsStringArray().Where(path => !string.IsNullOrWhiteSpace(path)).Distinct(StringComparer.Ordinal);
        }
        if (value.VariantType == Variant.Type.Array)
        {
            return value.AsGodotArray<string>().Where(path => !string.IsNullOrWhiteSpace(path)).Distinct(StringComparer.Ordinal);
        }

        return new[] { "res://ui" };
    }

    private static bool IsExcluded(string resourcePath)
    {
        var normalized = resourcePath.Replace('\\', '/').ToLowerInvariant();
        return normalized.Contains("/generated/") || normalized.Contains("/addons/") || normalized.Contains("/tests/") || normalized.Contains("/.godot/");
    }

    private void RunForPackage(string operation, string command, params string[] extra)
    {
        var package = SelectedPackagePath();
        if (package is null)
        {
            SetStatus("Select a package first.", true);
            Log(operation, "Blocked because no package is selected.");
            return;
        }

        var args = new List<string> { command, package, "--project", ProjectRoot() };
        args.AddRange(extra);
        RunTool(operation, args.ToArray());
    }

    private void RunDoctor()
    {
        RunTool("Doctor", "doctor", "--project", ProjectRoot(), "--godot", OS.GetExecutablePath());
    }

    private void RunTool(string operation, params string[] args)
    {
        EnsureDockState();
        if (_toolRunning || _generatedRefreshPending)
        {
            Log(operation, "Ignored because another operation or resource refresh is active.");
            return;
        }

        _currentOperation = operation;
        _toolRunning = true;
        SetBusy(true);
        SetStatus($"{operation} running...", false);
        Log(operation, $"Starting isolated command: {string.Join(" ", args.Select(QuoteLogArgument))}");
        try
        {
            FinishOperation(ExecuteIsolatedTool(args), canceled: false);
        }
        catch (Exception exception)
        {
            _toolRunning = false;
            SetBusy(false);
            SetStatus($"{operation} failed: {exception.Message}", true);
            Log(operation, $"Editor host failure: {exception}");
        }
    }

    private static string QuoteLogArgument(string argument)
    {
        return argument.Any(char.IsWhiteSpace) ? $"\"{argument}\"" : argument;
    }

    private ManifestUiToolResult ExecuteIsolatedTool(IReadOnlyList<string> args)
    {
        EnsureToolHost();
        var resultDirectory = Path.Combine(ProjectRoot(), ".godot", "manifest_ui_tool_host", "results");
        Directory.CreateDirectory(resultDirectory);
        var resultFile = Path.Combine(resultDirectory, Guid.NewGuid().ToString("N") + ".json");
        var errorFile = resultFile + ".stderr";
        try
        {
            var hostDll = Path.Combine(ProjectRoot(), ".godot", "manifest_ui_tool_host", "bin", "Debug", "net8.0", "manifest-ui-editor-host.dll");
            var processArgs = new List<string> { hostDll };
            processArgs.AddRange(args);
            processArgs.Add("--result-file");
            processArgs.Add(resultFile);
            Log("ToolHost", $"Launching {Path.GetFileName(hostDll)}; result file {resultFile}.");
            var exitCode = RunDotnetProcess(processArgs);
            Log("ToolHost", $"Process exited with code {exitCode}.");
            if (!File.Exists(resultFile))
            {
                var detail = File.Exists(errorFile) ? File.ReadAllText(errorFile).Trim() : "The tooling host produced no structured result.";
                throw new InvalidOperationException($"Tooling host exited with code {exitCode}. {detail}");
            }
            var result = ReadToolResult(resultFile);
            Log("ToolHost", $"Parsed exit={result.ExitCode}, messages={result.Messages.Count}, diagnostics={result.Diagnostics.Count}.");
            return result;
        }
        finally
        {
            TryDelete(resultFile);
            TryDelete(errorFile);
        }
    }

    private void EnsureToolHost()
    {
        var hostDll = Path.Combine(ProjectRoot(), ".godot", "manifest_ui_tool_host", "bin", "Debug", "net8.0", "manifest-ui-editor-host.dll");
        var hostProject = ProjectSettings.GlobalizePath("res://addons/manifest_ui/tooling/host/ManifestUi.EditorHost.csproj");
        var hostInputs = new[]
        {
            hostProject,
            ProjectSettings.GlobalizePath("res://addons/manifest_ui/tooling/host/Directory.Build.props"),
            ProjectSettings.GlobalizePath("res://addons/manifest_ui/tooling/host/Program.cs.txt"),
            ProjectSettings.GlobalizePath("res://addons/manifest_ui/tooling/ManifestUiTool.cs"),
        };
        var hostIsCurrent = File.Exists(hostDll) && hostInputs.All(path => File.Exists(path) && File.GetLastWriteTimeUtc(path) <= File.GetLastWriteTimeUtc(hostDll));
        if (hostIsCurrent)
        {
            Log("ToolHost", $"Using cached host {hostDll}.");
            return;
        }

        Log("ToolHost", $"Building isolated host from {hostProject}.");
        var exitCode = RunDotnetProcess(new[] { "build", hostProject, "-c", "Debug", "-nologo", "-v:q" });
        if (exitCode != 0)
        {
            throw new InvalidOperationException($"Could not build the isolated tooling host (exit code {exitCode}).");
        }
        Log("ToolHost", $"Host build completed at {hostDll}.");
    }

    private static int RunDotnetProcess(IEnumerable<string> args)
    {
        var startInfo = new ProcessStartInfo
        {
            FileName = "dotnet",
            WorkingDirectory = ProjectRoot(),
            UseShellExecute = false,
            CreateNoWindow = true,
        };
        foreach (var argument in args)
        {
            startInfo.ArgumentList.Add(argument);
        }
        using var process = Process.Start(startInfo) ?? throw new InvalidOperationException("Could not start dotnet.");
        process.WaitForExit();
        return process.ExitCode;
    }

    private static ManifestUiToolResult ReadToolResult(string path)
    {
        using var document = JsonDocument.Parse(File.ReadAllText(path));
        var root = document.RootElement;
        var diagnostics = new List<ManifestDiagnostic>();
        if (root.TryGetProperty("diagnostics", out var diagnosticsElement))
        {
            foreach (var item in diagnosticsElement.EnumerateArray())
            {
                var severityText = item.GetProperty("severity").GetString() ?? "error";
                Enum.TryParse<ManifestDiagnosticSeverity>(severityText, ignoreCase: true, out var severity);
                diagnostics.Add(new ManifestDiagnostic(
                    item.GetProperty("code").GetString() ?? "MUI3000",
                    severity,
                    item.GetProperty("file").GetString() ?? "",
                    item.GetProperty("jsonPointer").GetString() ?? "",
                    item.GetProperty("line").GetInt64(),
                    item.GetProperty("column").GetInt64(),
                    item.GetProperty("message").GetString() ?? "",
                    item.TryGetProperty("hint", out var hint) ? hint.GetString() ?? "" : ""));
            }
        }

        var messages = root.TryGetProperty("messages", out var messagesElement)
            ? messagesElement.EnumerateArray().Select(item => item.GetString() ?? "").ToArray()
            : Array.Empty<string>();
        return new ManifestUiToolResult
        {
            ExitCode = root.GetProperty("exitCode").GetInt32(),
            Diagnostics = diagnostics,
            Messages = messages,
        };
    }

    private static void TryDelete(string path)
    {
        try
        {
            if (File.Exists(path))
            {
                File.Delete(path);
            }
        }
        catch
        {
        }
    }

    private void FinishOperation(ManifestUiToolResult? result, bool canceled)
    {
        _toolRunning = false;

        if (canceled)
        {
            SetBusy(false);
            SetStatus($"{_currentOperation} canceled. Any commit already in progress completed atomically.", true);
            Log(_currentOperation, "Operation canceled.");
            return;
        }

        if (result is null)
        {
            SetBusy(false);
            SetStatus($"{_currentOperation} did not return a result.", true);
            Log(_currentOperation, "No structured result was returned.");
            return;
        }

        Log(_currentOperation, $"Completed with exit={result.ExitCode}, diagnostics={result.Diagnostics.Count}.");
        ShowResult(result);
        if (result.Success && string.Equals(_currentOperation, "Generate", StringComparison.Ordinal))
        {
            BeginGeneratedResourceRefresh();
            return;
        }
        SetBusy(false);
    }

    private void BeginGeneratedResourceRefresh()
    {
        _generatedSceneToReload = "";
        var package = SelectedPackagePath();
        if (package is not null && TryReadPreview(package, out var scenePath, out _, out _))
        {
            _generatedSceneToReload = scenePath;
        }

        _generatedRefreshPending = true;
        _generatedRefreshActivityLogged = false;
        _generatedRefreshFrames = 3;
        SetBusy(true);
        SetStatus("Generate succeeded. Refreshing Godot resources...", false);
        SetProcess(true);
        Log("Generate.Refresh", $"Scheduled EditorFileSystem scan; scene reload target={(_generatedSceneToReload.Length == 0 ? "<none>" : _generatedSceneToReload)}.");
        EditorInterface.Singleton.GetResourceFilesystem().CallDeferred(EditorFileSystem.MethodName.Scan);
    }

    public override void _Process(double delta)
    {
        if (!_generatedRefreshPending)
        {
            return;
        }

        if (_generatedRefreshFrames > 0)
        {
            _generatedRefreshFrames--;
            return;
        }

        var filesystem = EditorInterface.Singleton.GetResourceFilesystem();
        if (filesystem.IsScanning() || filesystem.IsImporting())
        {
            if (!_generatedRefreshActivityLogged)
            {
                _generatedRefreshActivityLogged = true;
                Log("Generate.Refresh", $"Godot filesystem active: scanning={filesystem.IsScanning()}, importing={filesystem.IsImporting()}.");
            }
            return;
        }

        CompleteGeneratedResourceRefresh();
    }

    private void CompleteGeneratedResourceRefresh()
    {
        _generatedRefreshPending = false;
        Log("Generate.Refresh", "Godot filesystem scan/import is idle.");
        SetProcess(false);

        if (!string.IsNullOrWhiteSpace(_generatedSceneToReload))
        {
            var openScenes = EditorInterface.Singleton.GetOpenScenes();
            if (openScenes.Contains(_generatedSceneToReload, StringComparer.Ordinal))
            {
                Log("Generate.Refresh", $"Reloading open generated scene {_generatedSceneToReload} from disk.");
                EditorInterface.Singleton.ReloadSceneFromPath(_generatedSceneToReload);
            }
            else
            {
                Log("Generate.Refresh", $"Generated scene {_generatedSceneToReload} is not open; no editor scene reload required.");
            }
        }

        _generatedSceneToReload = "";
        SetBusy(false);
        SetStatus("Generate succeeded. Godot resources are current.", false);
        Log("Generate.Refresh", "Refresh completed; editor operations re-enabled.");
    }

    private void ShowResult(ManifestUiToolResult result)
    {
        _diagnostics.Clear();
        _diagnostics.AddRange(result.Diagnostics);
        _diagnosticsList?.Clear();

        foreach (var diagnostic in _diagnostics)
        {
            var pointer = string.IsNullOrWhiteSpace(diagnostic.JsonPointer) ? "" : $" {diagnostic.JsonPointer}";
            var location = diagnostic.Line > 0 ? $":{diagnostic.Line}:{diagnostic.Column}" : "";
            _diagnosticsList?.AddItem($"{diagnostic.Severity} {diagnostic.Code} {diagnostic.File}{location}{pointer} - {diagnostic.Message}");
        }

        if (_diagnostics.Count == 0)
        {
            _diagnosticsList?.AddItem("No diagnostics.");
            _diagnosticsList?.SetItemDisabled(0, true);
        }

        foreach (var message in result.Messages)
        {
            Log($"{_currentOperation}.Message", message);
        }
        foreach (var diagnostic in result.Diagnostics)
        {
            Log($"{_currentOperation}.Diagnostic", FormatDiagnostic(diagnostic));
        }

        SetStatus(result.Success ? $"{_currentOperation} succeeded." : $"{_currentOperation} failed with exit code {result.ExitCode}.", !result.Success);
    }

    private static string FormatDiagnostic(ManifestDiagnostic diagnostic)
    {
        var hint = string.IsNullOrWhiteSpace(diagnostic.Hint) ? "" : $" Hint: {diagnostic.Hint}";
        return $"{diagnostic.Severity} {diagnostic.Code}: {diagnostic.File} {diagnostic.JsonPointer} {diagnostic.Message}{hint}";
    }

    private void CancelOperation()
    {
        SetStatus("The isolated tooling host completes each atomic operation before returning.", false);
    }

    private void SetBusy(bool busy)
    {
        foreach (var button in _operationButtons)
        {
            button.Disabled = busy;
        }
        if (_packages is not null)
        {
            _packages.Disabled = busy;
        }
        if (_cancelButton is not null)
        {
            _cancelButton.Disabled = !busy;
        }
    }

    private void UpdatePackageStatus()
    {
        var package = SelectedPackagePath();
        if (package is not null && !_toolRunning && !_generatedRefreshPending)
        {
            SetStatus($"Selected {ToResourcePath(package)}.", false);
        }
    }

    private void SetStatus(string message, bool error)
    {
        if (_status is null)
        {
            return;
        }
        _status.Text = message;
        _status.Modulate = error ? new Color(1.0f, 0.55f, 0.55f) : Colors.White;
    }

    private string? SelectedPackagePath()
    {
        EnsureDockState();
        if (_packages is null)
        {
            return null;
        }

        var selected = _packages.Selected;
        if (selected >= 0 && selected < _packages.ItemCount)
        {
            var metadata = _packages.GetItemMetadata(selected);
            if (metadata.VariantType == Variant.Type.String)
            {
                var metadataPath = metadata.AsString();
                if (!string.IsNullOrWhiteSpace(metadataPath))
                {
                    return metadataPath;
                }
            }

            if (selected < _packagePaths.Count)
            {
                return _packagePaths[selected];
            }
        }

        var displayedLabel = selected >= 0 && selected < _packages.ItemCount
            ? _packages.GetItemText(selected)
            : _packages.Text;
        if (string.IsNullOrWhiteSpace(displayedLabel))
        {
            return null;
        }

        var normalizedLabel = displayedLabel.Replace('\\', '/');
        if (normalizedLabel.StartsWith("res://", StringComparison.OrdinalIgnoreCase))
        {
            normalizedLabel = normalizedLabel[6..];
        }

        var mapped = _packagePaths.FirstOrDefault(path => string.Equals(
            ToResourcePath(path).Replace('\\', '/')[6..],
            normalizedLabel,
            StringComparison.OrdinalIgnoreCase));
        if (!string.IsNullOrWhiteSpace(mapped))
        {
            return mapped;
        }

        var candidate = ProjectSettings.GlobalizePath($"res://{normalizedLabel.TrimStart('/')}");
        return File.Exists(candidate) ? candidate : null;
    }

    private void OnDiagnosticSelected(long index)
    {
        if (index < 0 || index >= _diagnostics.Count)
        {
            return;
        }

        var diagnostic = _diagnostics[(int)index];
        var candidate = ResolveDiagnosticPath(diagnostic.File, SelectedPackagePath());
        if (candidate is not null && File.Exists(candidate))
        {
            EditorInterface.Singleton.GetFileSystemDock().NavigateToPath(ToResourcePath(candidate));
        }
        else if (!string.IsNullOrWhiteSpace(diagnostic.File))
        {
            SetStatus($"Could not resolve diagnostic file '{diagnostic.File}' unambiguously.", true);
            return;
        }
        SetStatus($"{diagnostic.Code}: {diagnostic.JsonPointer} {diagnostic.Message}", diagnostic.Severity == ManifestDiagnosticSeverity.Error);
    }

    private string? ResolveDiagnosticPath(string diagnosticFile, string? selectedPackage)
    {
        if (string.IsNullOrWhiteSpace(diagnosticFile))
        {
            return selectedPackage;
        }
        if (diagnosticFile.StartsWith("res://", StringComparison.Ordinal))
        {
            return ProjectSettings.GlobalizePath(diagnosticFile);
        }
        if (Path.IsPathRooted(diagnosticFile))
        {
            return Path.GetFullPath(diagnosticFile);
        }

        var projectCandidate = Path.GetFullPath(Path.Combine(ProjectRoot(), diagnosticFile));
        if (File.Exists(projectCandidate))
        {
            return projectCandidate;
        }
        if (selectedPackage is not null)
        {
            var packageCandidate = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(selectedPackage)!, diagnosticFile));
            if (File.Exists(packageCandidate))
            {
                return packageCandidate;
            }
        }

        var matches = _packagePaths
            .Select(path => Path.Combine(Path.GetDirectoryName(path)!, diagnosticFile))
            .Where(File.Exists)
            .Distinct(StringComparer.OrdinalIgnoreCase)
            .Take(2)
            .ToArray();
        return matches.Length == 1 ? matches[0] : null;
    }

    private void PreviewSelected(bool run)
    {
        EnsureDockState();
        Log(run ? "RunPreview" : "Preview", "Requested.");
        if (_toolRunning || _generatedRefreshPending)
        {
            SetStatus("Wait for the current Generate refresh to finish.", false);
            Log(run ? "RunPreview" : "Preview", "Blocked while tooling or resource refresh is active.");
            return;
        }
        Log(run ? "RunPreview.Selection" : "Preview.Selection",
            $"selectedIndex={_packages?.Selected ?? -1}, itemCount={_packages?.ItemCount ?? 0}, mappingCount={_packagePaths.Count}, displayed='{_packages?.Text ?? "<missing>"}'.");
        var package = SelectedPackagePath();
        if (package is null)
        {
            SetStatus("Select a package first.", true);
            Log(run ? "RunPreview" : "Preview", "Blocked because no package is selected.");
            return;
        }

        Log(run ? "RunPreview" : "Preview", $"Verifying {ToResourcePath(package)} before launch.");
        var result = VerifySelected(showResult: false);
        if (result is null)
        {
            return;
        }
        if (!result.Success)
        {
            _currentOperation = "Verify";
            ShowResult(result);
            Log(run ? "RunPreview" : "Preview", "Launch stopped because Verify failed.");
            return;
        }

        if (!TryReadPreview(package, out var scenePath, out var designResolution, out var error))
        {
            SetStatus(error, true);
            Log(run ? "RunPreview" : "Preview", $"Could not resolve preview metadata: {error}");
            return;
        }
        Log(run ? "RunPreview" : "Preview", $"Resolved scene={scenePath}, design={designResolution.X}x{designResolution.Y}.");

        if (run)
        {
            if (_editorBridge is null || !GodotObject.IsInstanceValid(_editorBridge))
            {
                SetStatus("The editor bridge is unavailable. Reload the Manifest UI plugin.", true);
                Log("RunPreview", "Editor bridge is unavailable.");
                return;
            }
            Log("RunPreview", $"Submitting delayed GDScript launch request for {scenePath}.");
            _editorBridge.Call("request_run_preview", scenePath);
            SetStatus($"Starting {scenePath}.", false);
            return;
        }

        var preview = new ManifestUiPreviewWindow();
        AddChild(preview);
        preview.Open(scenePath, designResolution);
        Log("Preview", $"Preview window opened for {scenePath}.");
        SetStatus($"Previewing {scenePath} at {(int)designResolution.X} x {(int)designResolution.Y}.", false);
    }

    private ManifestUiToolResult? VerifySelected(bool showResult)
    {
        EnsureDockState();
        Log("Verify", $"Requested; showResult={showResult}.");
        if (_toolRunning || _generatedRefreshPending)
        {
            Log("Verify", "Blocked while tooling or resource refresh is active.");
            return null;
        }
        var package = SelectedPackagePath();
        if (package is null)
        {
            SetStatus("Select a package first.", true);
            Log("Verify", "Blocked because no package is selected.");
            return null;
        }

        SetBusy(true);
        SetStatus("Verify running...", false);
        _toolRunning = true;
        ManifestUiToolResult staticResult;
        try
        {
            Log("Verify.Static", $"Starting isolated verification for {ToResourcePath(package)}.");
            staticResult = ExecuteIsolatedTool(new[] { "verify", package, "--project", ProjectRoot() });
            Log("Verify.Static", $"Completed with exit={staticResult.ExitCode}, diagnostics={staticResult.Diagnostics.Count}.");
        }
        catch (Exception exception)
        {
            _toolRunning = false;
            SetBusy(false);
            SetStatus($"Verify failed: {exception.Message}", true);
            Log("Verify.Static", $"Host failure: {exception}");
            return null;
        }
        _toolRunning = false;
        Log("Verify.Engine", staticResult.Success ? "Starting Godot engine verification." : "Skipped because static verification failed.");
        var engineDiagnostics = staticResult.Success
            ? ManifestUiEngineVerifier.Verify(package)
            : Array.Empty<ManifestDiagnostic>();
        Log("Verify.Engine", $"Completed with {engineDiagnostics.Length} diagnostic(s).");
        var allDiagnostics = staticResult.Diagnostics.Concat(engineDiagnostics).ToArray();
        var result = new ManifestUiToolResult
        {
            ExitCode = allDiagnostics.Any(diagnostic => diagnostic.Severity == ManifestDiagnosticSeverity.Error)
                ? ManifestUiTool.ValidationFailure
                : staticResult.ExitCode,
            Diagnostics = allDiagnostics,
            Messages = staticResult.Messages.Concat(engineDiagnostics.Length == 0 ? Array.Empty<string>() : new[] { "Godot engine verification completed." }).ToArray(),
        };
        SetBusy(false);
        if (showResult || !result.Success)
        {
            _currentOperation = "Verify";
            ShowResult(result);
        }
        return result;
    }

    private static bool TryReadPreview(string packagePath, out string scenePath, out Vector2I designResolution, out string error)
    {
        scenePath = "";
        designResolution = new Vector2I(1280, 720);
        error = "";
        try
        {
            using var document = JsonDocument.Parse(File.ReadAllText(packagePath));
            var root = document.RootElement;
            if (!root.TryGetProperty("godot", out var godot) || !godot.TryGetProperty("scenePath", out var pathElement))
            {
                error = "package.json does not define godot.scenePath.";
                return false;
            }
            scenePath = pathElement.GetString() ?? "";
            if (root.TryGetProperty("designResolution", out var resolution) && resolution.ValueKind == JsonValueKind.Array && resolution.GetArrayLength() == 2)
            {
                designResolution = new Vector2I(resolution[0].GetInt32(), resolution[1].GetInt32());
            }
            return !string.IsNullOrWhiteSpace(scenePath);
        }
        catch (Exception ex)
        {
            error = $"Could not read preview settings: {ex.Message}";
            return false;
        }
    }

    private void OpenReport()
    {
        var package = SelectedPackagePath();
        if (package is null)
        {
            SetStatus("Select a package first.", true);
            return;
        }
        var report = Path.Combine(Path.GetDirectoryName(package)!, "export", "manifest_report.md");
        if (!File.Exists(report))
        {
            SetStatus("Report not found. Run Validate with report output first.", true);
            return;
        }
        EditorInterface.Singleton.GetFileSystemDock().NavigateToPath(ToResourcePath(report));
    }

    private void ReimportAssets()
    {
        var package = SelectedPackagePath();
        if (package is null)
        {
            SetStatus("Select a package first.", true);
            return;
        }
        var assetDirectory = Path.Combine(Path.GetDirectoryName(package)!, "assets");
        var resources = Directory.Exists(assetDirectory)
            ? Directory.EnumerateFiles(assetDirectory, "*", SearchOption.AllDirectories)
                .Where(path => !path.EndsWith(".import", StringComparison.OrdinalIgnoreCase))
                .Select(ToResourcePath)
                .OrderBy(path => path, StringComparer.Ordinal)
                .ToArray()
            : Array.Empty<string>();
        EditorInterface.Singleton.GetResourceFilesystem().Scan();
        if (resources.Length > 0)
        {
            EditorInterface.Singleton.GetResourceFilesystem().ReimportFiles(resources);
        }
        SetStatus(resources.Length == 0 ? "No package assets to reimport." : $"Requested reimport for {resources.Length} asset(s).", false);
    }

    private void ShowSettings()
    {
        var dialog = new ConfirmationDialog { Title = "Manifest UI Settings", Size = new Vector2I(620, 210) };
        var content = new VBoxContainer();
        _settingsRoots = new LineEdit { Text = string.Join(";", GetSourceRoots()), PlaceholderText = "res://ui;res://game/ui" };
        _settingsGenerated = new LineEdit { Text = ProjectSettings.GetSetting(GeneratedRootSetting).AsString() };
        content.AddChild(new Label { Text = "Source roots (semicolon separated)" });
        content.AddChild(_settingsRoots);
        content.AddChild(new Label { Text = "Generated root" });
        content.AddChild(_settingsGenerated);
        dialog.AddChild(content);
        ConnectDialog(dialog, nameof(OnSettingsConfirmed), nameof(OnSettingsCanceled));
        AddChild(dialog);
        dialog.PopupCentered();
    }

    private void OnSettingsConfirmed()
    {
        if (_settingsRoots is not null && _settingsGenerated is not null)
        {
            var values = _settingsRoots.Text.Split(';', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries)
                .Where(value => value.StartsWith("res://", StringComparison.Ordinal))
                .Distinct(StringComparer.Ordinal)
                .ToArray();
            ProjectSettings.SetSetting(SourceRootsSetting, values);
            ProjectSettings.SetSetting(GeneratedRootSetting, _settingsGenerated.Text.Trim());
            ProjectSettings.Save();
            RefreshPackages();
        }
        ClearSettingsDialogState();
    }

    private void OnSettingsCanceled()
    {
        ClearSettingsDialogState();
    }

    private void ClearSettingsDialogState()
    {
        _settingsRoots = null;
        _settingsGenerated = null;
    }

    private void ShowNewPackageDialog()
    {
        var dialog = new ConfirmationDialog { Title = "New Manifest UI Package", Size = new Vector2I(620, 250) };
        var content = new VBoxContainer();
        _newPackageId = new LineEdit { PlaceholderText = "ui.inventory" };
        _newPackageDisplayName = new LineEdit { PlaceholderText = "Inventory" };
        content.AddChild(new Label { Text = "Package id" });
        content.AddChild(_newPackageId);
        content.AddChild(new Label { Text = "Display name" });
        content.AddChild(_newPackageDisplayName);
        dialog.AddChild(content);
        ConnectDialog(dialog, nameof(OnNewPackageConfirmed), nameof(OnNewPackageCanceled));
        AddChild(dialog);
        dialog.PopupCentered();
    }

    private void OnNewPackageConfirmed()
    {
        try
        {
            CreatePackage(_newPackageId?.Text.Trim() ?? "", _newPackageDisplayName?.Text.Trim() ?? "");
        }
        catch (Exception ex)
        {
            SetStatus($"Package creation failed: {ex.Message}", true);
        }
        ClearNewPackageDialogState();
    }

    private void OnNewPackageCanceled()
    {
        ClearNewPackageDialogState();
    }

    private void ClearNewPackageDialogState()
    {
        _newPackageId = null;
        _newPackageDisplayName = null;
    }

    private void CreatePackage(string packageId, string displayName)
    {
        if (string.IsNullOrWhiteSpace(packageId) || packageId.Any(character => !(char.IsLetterOrDigit(character) || character is '.' or '_' or '-')))
        {
            throw new InvalidOperationException("Package id may contain only letters, digits, '.', '_' and '-'.");
        }
        if (string.IsNullOrWhiteSpace(displayName))
        {
            throw new InvalidOperationException("Display name is required.");
        }

        var systemName = packageId.Split('.').Last();
        var root = GetSourceRoots().FirstOrDefault() ?? "res://ui";
        var directory = Path.Combine(ProjectSettings.GlobalizePath(root), systemName);
        if (Directory.Exists(directory))
        {
            throw new IOException($"Package directory already exists: {directory}");
        }
        Directory.CreateDirectory(directory);

        var className = Pascal(systemName);
        var generatedRoot = ProjectSettings.GetSetting(GeneratedRootSetting).AsString().TrimEnd('/');
        WriteJson(Path.Combine(directory, "package.json"), new
        {
            schemaVersion = 1,
            packageId,
            displayName,
            designResolution = new[] { 1280, 720 },
            assets = "assets.json",
            layout = "layout.json",
            bindings = "bindings.json",
            codegen = "codegen.json",
            validation = "validation.json",
            strings = "strings.json",
            runtime = new { controllerScope = "instance" },
            godot = new
            {
                systemName,
                widgetClass = $"{className}Widget",
                controllerClass = $"GodotUi.Generated.{className}.{className}Controller",
                @namespace = $"GodotUi.Generated.{className}",
                outputDir = $"{generatedRoot.Replace("res://", "")}/{systemName}",
                scenePath = $"{generatedRoot}/{systemName}/{className}Widget.tscn",
            },
        });
        WriteJson(Path.Combine(directory, "layout.json"), new
        {
            root = new
            {
                id = $"{className}Widget",
                type = "Control",
                name = $"{className}Widget",
                properties = new { anchors_preset = 15, anchor_right = 1.0, anchor_bottom = 1.0, grow_horizontal = 2, grow_vertical = 2 },
                children = Array.Empty<object>(),
            },
        });
        WriteJson(Path.Combine(directory, "bindings.json"), new
        {
            mvvm = new { updatePolicy = "manual", fields = Array.Empty<object>() },
            bindings = new { },
            repeaters = Array.Empty<object>(),
            inputs = Array.Empty<object>(),
            controls = Array.Empty<object>(),
            events = new { channels = Array.Empty<object>() },
        });
        WriteJson(Path.Combine(directory, "assets.json"), new { assets = Array.Empty<object>() });
        WriteJson(Path.Combine(directory, "codegen.json"), new { schemaVersion = 1, generator = "ManifestUi", requiredServices = Array.Empty<object>(), routes = Array.Empty<object>() });
        WriteJson(Path.Combine(directory, "validation.json"), new
        {
            commandletInputWhitelist = new[] { "assets.json", "layout.json", "bindings.json", "codegen.json", "validation.json", "strings.json" },
            checks = new { manifestValidation = true },
        });
        WriteJson(Path.Combine(directory, "strings.json"), new { schemaVersion = 1, defaultLocale = "en", locales = new[] { "en" }, strings = new { } });

        EditorInterface.Singleton.GetResourceFilesystem().Scan();
        RefreshPackages();
        var packagePath = Path.Combine(directory, "package.json");
        var index = _packagePaths.FindIndex(path => string.Equals(path, packagePath, StringComparison.OrdinalIgnoreCase));
        if (index >= 0)
        {
            _packages?.Select(index);
        }
        SetStatus($"Created {ToResourcePath(packagePath)}.", false);
    }

    private static void WriteJson(string path, object value)
    {
        var text = JsonSerializer.Serialize(value, new JsonSerializerOptions { WriteIndented = true }) + "\n";
        File.WriteAllText(path, text, new System.Text.UTF8Encoding(false));
    }

    private void InstallSkill()
    {
        var source = ProjectSettings.GlobalizePath("res://addons/manifest_ui/codex_skill/godot-manifest-ui");
        if (!Directory.Exists(source))
        {
            SetStatus("Bundled Codex Skill was not found.", true);
            return;
        }
        var codexHome = System.Environment.GetEnvironmentVariable("CODEX_HOME");
        if (string.IsNullOrWhiteSpace(codexHome))
        {
            codexHome = Path.Combine(System.Environment.GetFolderPath(System.Environment.SpecialFolder.UserProfile), ".codex");
        }
        var destination = Path.Combine(codexHome, "skills", "godot-manifest-ui");
        if (Directory.Exists(destination))
        {
            var bundledVersion = ReadSkillVersion(source);
            var installedVersion = ReadSkillVersion(destination);
            var modified = !DirectoryContentsEqual(source, destination);
            if (!modified && string.Equals(bundledVersion, installedVersion, StringComparison.Ordinal))
            {
                SetStatus($"Codex Skill {bundledVersion} is already installed and unchanged.", false);
                return;
            }

            var relation = DescribeVersionChange(installedVersion, bundledVersion);
            var modificationText = modified ? " Local modifications were detected and will be preserved in the backup." : "";
            var confirm = new ConfirmationDialog
            {
                Title = "Update Codex Skill",
                DialogText = $"{relation}\nInstalled: {installedVersion}\nBundled: {bundledVersion}\n{destination}\n\nBack up and replace the installed skill?{modificationText}",
            };
            SetPendingSkillInstall(source, destination, createBackup: true);
            ConnectDialog(confirm, nameof(OnInstallSkillConfirmed), nameof(OnInstallSkillCanceled));
            AddChild(confirm);
            confirm.PopupCentered();
            return;
        }
        var installVersion = ReadSkillVersion(source);
        var installConfirm = new ConfirmationDialog
        {
            Title = "Install Codex Skill",
            DialogText = $"Install Godot Manifest UI Skill {installVersion}?\n\nDestination:\n{destination}",
        };
        SetPendingSkillInstall(source, destination, createBackup: false);
        ConnectDialog(installConfirm, nameof(OnInstallSkillConfirmed), nameof(OnInstallSkillCanceled));
        AddChild(installConfirm);
        installConfirm.PopupCentered();
    }

    private void SetPendingSkillInstall(string source, string destination, bool createBackup)
    {
        _pendingSkillSource = source;
        _pendingSkillDestination = destination;
        _pendingSkillBackup = createBackup;
    }

    private void OnInstallSkillConfirmed()
    {
        var source = _pendingSkillSource;
        var destination = _pendingSkillDestination;
        var createBackup = _pendingSkillBackup;
        ClearPendingSkillInstall();
        InstallSkillCopy(source, destination, createBackup);
    }

    private void OnInstallSkillCanceled()
    {
        ClearPendingSkillInstall();
    }

    private void ClearPendingSkillInstall()
    {
        _pendingSkillSource = "";
        _pendingSkillDestination = "";
        _pendingSkillBackup = false;
    }

    private void InstallSkillCopy(string source, string destination, bool createBackup)
    {
        string? backup = null;
        try
        {
            if (createBackup && Directory.Exists(destination))
            {
                backup = destination + ".backup-" + DateTime.UtcNow.ToString("yyyyMMddHHmmssfff");
                if (Directory.Exists(backup))
                {
                    backup += "-" + Guid.NewGuid().ToString("N");
                }
                Directory.Move(destination, backup);
            }
            CopyDirectory(source, destination);
            var backupText = backup is null ? "" : $" Backup: {backup}.";
            SetStatus($"Installed Codex Skill {ReadSkillVersion(source)} to {destination}.{backupText}", false);
        }
        catch (Exception ex)
        {
            try
            {
                if (backup is not null && Directory.Exists(backup))
                {
                    if (Directory.Exists(destination))
                    {
                        Directory.Delete(destination, recursive: true);
                    }
                    Directory.Move(backup, destination);
                }
            }
            catch (Exception rollbackException)
            {
                SetStatus($"Skill installation failed: {ex.Message}. Backup restore also failed: {rollbackException.Message}", true);
                return;
            }
            SetStatus($"Skill installation failed and the previous installation was restored: {ex.Message}", true);
        }
    }

    private static string ReadSkillVersion(string directory)
    {
        var versionPath = Path.Combine(directory, "VERSION");
        return File.Exists(versionPath) ? File.ReadAllText(versionPath).Trim() : "unknown";
    }

    private static bool DirectoryContentsEqual(string first, string second)
    {
        var firstFiles = Directory.EnumerateFiles(first, "*", SearchOption.AllDirectories)
            .Select(path => Path.GetRelativePath(first, path).Replace('\\', '/'))
            .OrderBy(path => path, StringComparer.Ordinal)
            .ToArray();
        var secondFiles = Directory.EnumerateFiles(second, "*", SearchOption.AllDirectories)
            .Select(path => Path.GetRelativePath(second, path).Replace('\\', '/'))
            .OrderBy(path => path, StringComparer.Ordinal)
            .ToArray();
        if (!firstFiles.SequenceEqual(secondFiles, StringComparer.Ordinal))
        {
            return false;
        }

        foreach (var relativePath in firstFiles)
        {
            var firstPath = Path.Combine(first, relativePath.Replace('/', Path.DirectorySeparatorChar));
            var secondPath = Path.Combine(second, relativePath.Replace('/', Path.DirectorySeparatorChar));
            if (new FileInfo(firstPath).Length != new FileInfo(secondPath).Length)
            {
                return false;
            }
            if (!SHA256.HashData(File.ReadAllBytes(firstPath)).SequenceEqual(SHA256.HashData(File.ReadAllBytes(secondPath))))
            {
                return false;
            }
        }
        return true;
    }

    private static string DescribeVersionChange(string installed, string bundled)
    {
        var comparison = CompareSemanticVersions(installed, bundled);
        return comparison switch
        {
            < 0 => "A newer bundled Codex Skill is available.",
            > 0 => "The installed Codex Skill is newer. This operation is a downgrade.",
            0 => "The installed Codex Skill has the same version but different contents.",
            _ => "The installed Codex Skill version could not be compared.",
        };
    }

    private static int? CompareSemanticVersions(string installed, string bundled)
    {
        if (!TryParseSemanticVersion(installed, out var installedCore, out var installedPrerelease)
            || !TryParseSemanticVersion(bundled, out var bundledCore, out var bundledPrerelease))
        {
            return null;
        }
        var coreComparison = installedCore.CompareTo(bundledCore);
        if (coreComparison != 0)
        {
            return coreComparison;
        }
        if (installedPrerelease.Length == 0 || bundledPrerelease.Length == 0)
        {
            return installedPrerelease.Length == bundledPrerelease.Length ? 0 : installedPrerelease.Length == 0 ? 1 : -1;
        }
        return ComparePrerelease(installedPrerelease, bundledPrerelease);
    }

    private static bool TryParseSemanticVersion(string value, out Version core, out string[] prerelease)
    {
        var withoutMetadata = value.Split('+', 2)[0];
        var parts = withoutMetadata.Split('-', 2);
        prerelease = parts.Length == 2 ? parts[1].Split('.') : Array.Empty<string>();
        return Version.TryParse(parts[0], out core!);
    }

    private static int ComparePrerelease(IReadOnlyList<string> first, IReadOnlyList<string> second)
    {
        for (var index = 0; index < Math.Max(first.Count, second.Count); index++)
        {
            if (index >= first.Count) return -1;
            if (index >= second.Count) return 1;
            var firstNumeric = int.TryParse(first[index], out var firstNumber);
            var secondNumeric = int.TryParse(second[index], out var secondNumber);
            var comparison = firstNumeric && secondNumeric
                ? firstNumber.CompareTo(secondNumber)
                : firstNumeric != secondNumeric
                    ? firstNumeric ? -1 : 1
                    : string.Compare(first[index], second[index], StringComparison.Ordinal);
            if (comparison != 0) return comparison;
        }
        return 0;
    }

    private static void CopyDirectory(string source, string destination)
    {
        Directory.CreateDirectory(destination);
        foreach (var file in Directory.EnumerateFiles(source))
        {
            File.Copy(file, Path.Combine(destination, Path.GetFileName(file)), overwrite: true);
        }
        foreach (var directory in Directory.EnumerateDirectories(source))
        {
            CopyDirectory(directory, Path.Combine(destination, Path.GetFileName(directory)));
        }
    }

    private static string ProjectRoot()
    {
        return Path.GetFullPath(ProjectSettings.GlobalizePath("res://"));
    }

    private static string ToResourcePath(string globalPath)
    {
        var relative = Path.GetRelativePath(ProjectRoot(), Path.GetFullPath(globalPath)).Replace('\\', '/');
        return "res://" + relative;
    }

    private static string Pascal(string value)
    {
        return string.Concat(value.Split(new[] { '_', '-', '.', ' ' }, StringSplitOptions.RemoveEmptyEntries)
            .Select(part => char.ToUpperInvariant(part[0]) + part[1..]));
    }
}
#endif

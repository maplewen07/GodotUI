using System.Collections.Generic;
using System.Linq;
using Godot;

namespace GodotUi.Manifest;

public partial class ManifestUiManager : Node
{
    private readonly Dictionary<string, List<OpenWidgetEntry>> _openWidgets = new();
    private readonly Dictionary<string, ManifestControllerBase> _controllers = new();

    public static ManifestUiManager? Instance { get; private set; }

    public override void _EnterTree()
    {
        Instance = this;
    }

    public override void _ExitTree()
    {
        foreach (var entry in _openWidgets.Values.SelectMany(entries => entries).ToArray())
        {
            CloseEntry(entry, ManifestUiCloseReason.ManagerShutdown, queueFree: true);
        }
        _openWidgets.Clear();

        foreach (var controller in _controllers.Values.ToArray())
        {
            controller.Dispose();
        }
        _controllers.Clear();

        if (Instance == this)
        {
            Instance = null;
        }
    }

    public Control Open(string screenId, string scenePath)
    {
        return Open(screenId, scenePath, new ManifestUiOpenOptions());
    }

    public Control Open(string screenId, string scenePath, ManifestUiOpenOptions? options)
    {
        if (_openWidgets.TryGetValue(screenId, out var existing))
        {
            if (options is null || options.Mode == ManifestUiOpenMode.Reuse)
            {
                return existing[^1].Widget;
            }

            if (options.Mode == ManifestUiOpenMode.Replace)
            {
                foreach (var existingEntry in existing.ToArray())
                {
                    CloseEntry(existingEntry, ManifestUiCloseReason.Replaced, queueFree: true);
                }
            }
        }

        options ??= new ManifestUiOpenOptions();
        var scene = ResourceLoader.Load<PackedScene>(scenePath);
        var widget = scene.Instantiate<Control>();
        var entry = new OpenWidgetEntry(screenId, widget, options);

        if (!_openWidgets.TryGetValue(screenId, out var entries))
        {
            entries = new List<OpenWidgetEntry>();
            _openWidgets[screenId] = entries;
        }
        entries.Add(entry);

        if (ManifestUiRoot.Instance is { } root)
        {
            entry.RootAttachment = root.AttachWidget(widget, options);
        }
        else
        {
            GetTree().Root.AddChild(widget);
        }

        return widget;
    }

    public void Close(string screenId)
    {
        if (!_openWidgets.TryGetValue(screenId, out var entries) || entries.Count == 0)
        {
            return;
        }

        CloseEntry(entries[^1], ManifestUiCloseReason.Programmatic, queueFree: true);
    }

    public void Close(Control widget)
    {
        if (FindEntry(widget) is { } entry)
        {
            CloseEntry(entry, ManifestUiCloseReason.Programmatic, queueFree: true);
        }
    }

    public void NotifyWidgetExited(Control widget)
    {
        if (FindEntry(widget) is { } entry)
        {
            CloseEntry(entry, ManifestUiCloseReason.OwnerFreed, queueFree: false);
        }
    }

    public ManifestControllerBase GetOrCreateController(string packageId, System.Func<ManifestControllerBase> factory)
    {
        if (_controllers.TryGetValue(packageId, out var controller))
        {
            return controller;
        }

        controller = factory();
        controller.Setup(this, packageId);
        _controllers[packageId] = controller;
        return controller;
    }

    public ManifestControllerBase? FindController(string packageId)
    {
        return _controllers.TryGetValue(packageId, out var controller) ? controller : null;
    }

    public int GetOpenCount(string screenId)
    {
        return _openWidgets.TryGetValue(screenId, out var entries) ? entries.Count : 0;
    }

    private OpenWidgetEntry? FindEntry(Control widget)
    {
        return _openWidgets.Values.SelectMany(entries => entries).LastOrDefault(entry => ReferenceEquals(entry.Widget, widget));
    }

    private void CloseEntry(OpenWidgetEntry entry, ManifestUiCloseReason reason, bool queueFree)
    {
        if (_openWidgets.TryGetValue(entry.ScreenId, out var entries))
        {
            entries.Remove(entry);
            if (entries.Count == 0)
            {
                _openWidgets.Remove(entry.ScreenId);
            }
        }

        ManifestUiRoot.Instance?.DetachWidget(entry.Widget, entry.Options, entry.RootAttachment);
        entry.Options.OnClosed?.Invoke(entry.Widget, reason);

        if (queueFree && IsInstanceValid(entry.Widget) && !entry.Widget.IsQueuedForDeletion())
        {
            entry.Widget.QueueFree();
        }
    }

    private sealed class OpenWidgetEntry
    {
        public OpenWidgetEntry(string screenId, Control widget, ManifestUiOpenOptions options)
        {
            ScreenId = screenId;
            Widget = widget;
            Options = options;
        }

        public string ScreenId { get; }
        public Control Widget { get; }
        public ManifestUiOpenOptions Options { get; }
        public ManifestUiRootAttachment? RootAttachment { get; set; }
    }
}

public enum ManifestUiOpenMode
{
    Reuse,
    Replace,
    Stack,
}

public enum ManifestUiCloseReason
{
    Programmatic,
    Replaced,
    OwnerFreed,
    ManagerShutdown,
}

public sealed class ManifestUiOpenOptions
{
    public string LayerId { get; set; } = "Main";
    public ManifestUiOpenMode Mode { get; set; } = ManifestUiOpenMode.Reuse;
    public bool IsModal { get; set; }
    public bool GrabFocus { get; set; }
    public bool RestoreFocusOnClose { get; set; }
    public bool PauseTree { get; set; }
    public System.Action<Control, ManifestUiCloseReason>? OnClosed { get; set; }
}

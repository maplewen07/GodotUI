using Godot;
using System.Collections.Generic;

namespace GodotUi.Manifest;

public partial class ManifestUiRoot : CanvasLayer
{
    private readonly Dictionary<string, Control> _layers = new();
    private readonly Dictionary<string, List<Control>> _layerStacks = new();
    private readonly List<Control> _modalStack = new();

    public static ManifestUiRoot? Instance { get; private set; }

    public override void _EnterTree()
    {
        Instance = this;
    }

    public override void _ExitTree()
    {
        if (Instance == this)
        {
            Instance = null;
        }
    }

    internal ManifestUiRootAttachment AttachWidget(Control widget, ManifestUiOpenOptions options)
    {
        var attachment = new ManifestUiRootAttachment
        {
            LayerId = string.IsNullOrWhiteSpace(options.LayerId) ? "Main" : options.LayerId,
            PreviousFocus = options.RestoreFocusOnClose ? GetViewport().GuiGetFocusOwner() : null,
            WasTreePaused = GetTree().Paused,
            PauseApplied = options.PauseTree,
        };

        var layer = GetOrCreateLayer(attachment.LayerId);
        layer.AddChild(widget);

        if (!_layerStacks.TryGetValue(attachment.LayerId, out var stack))
        {
            stack = new List<Control>();
            _layerStacks[attachment.LayerId] = stack;
        }
        stack.Add(widget);

        if (options.IsModal)
        {
            _modalStack.Add(widget);
            widget.ProcessMode = ProcessModeEnum.Always;
        }

        if (options.PauseTree)
        {
            GetTree().Paused = true;
            widget.ProcessMode = ProcessModeEnum.Always;
        }

        if (options.GrabFocus)
        {
            GrabFirstFocusable(widget);
        }

        return attachment;
    }

    internal void DetachWidget(Control widget, ManifestUiOpenOptions options, ManifestUiRootAttachment? attachment)
    {
        if (attachment is not null && _layerStacks.TryGetValue(attachment.LayerId, out var stack))
        {
            stack.Remove(widget);
        }

        _modalStack.Remove(widget);

        if (attachment?.PauseApplied == true)
        {
            GetTree().Paused = attachment.WasTreePaused;
        }

        if (options.RestoreFocusOnClose && attachment?.PreviousFocus is { } previousFocus && IsInstanceValid(previousFocus))
        {
            previousFocus.GrabFocus();
        }
    }

    public bool IsModalLayerActive()
    {
        _modalStack.RemoveAll(widget => !IsInstanceValid(widget) || !widget.IsInsideTree());
        return _modalStack.Count > 0;
    }

    private Control GetOrCreateLayer(string layerId)
    {
        if (_layers.TryGetValue(layerId, out var layer) && IsInstanceValid(layer))
        {
            return layer;
        }

        layer = new Control { Name = layerId };
        layer.SetAnchorsPreset(Control.LayoutPreset.FullRect);
        AddChild(layer);
        _layers[layerId] = layer;
        return layer;
    }

    private static void GrabFirstFocusable(Control root)
    {
        var focusable = FindFirstFocusable(root);
        focusable?.GrabFocus();
    }

    private static Control? FindFirstFocusable(Node node)
    {
        if (node is Control control && control.FocusMode != Control.FocusModeEnum.None)
        {
            return control;
        }

        foreach (var child in node.GetChildren())
        {
            var found = FindFirstFocusable(child);
            if (found is not null)
            {
                return found;
            }
        }

        return null;
    }
}

internal sealed class ManifestUiRootAttachment
{
    public string LayerId { get; set; } = "Main";
    public Control? PreviousFocus { get; set; }
    public bool WasTreePaused { get; set; }
    public bool PauseApplied { get; set; }
}

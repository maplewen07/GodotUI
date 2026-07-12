using System;
using System.Collections.Generic;
using System.Linq;
using Godot;

namespace GodotUi.Manifest;

public partial class ManifestUiRoot : CanvasLayer
{
    private readonly Dictionary<string, Control> _layers = new(StringComparer.Ordinal);
    private readonly Dictionary<string, List<Control>> _layerStacks = new(StringComparer.Ordinal);
    private readonly Dictionary<Control, ManifestUiRootAttachment> _attachments = new();
    private readonly List<ManifestUiRootAttachment> _modalStack = new();
    private readonly HashSet<ManifestUiRootAttachment> _pauseOwners = new();
    private bool _pausedBeforeRequests;

    public static ManifestUiRoot? Instance { get; private set; }

    public override void _EnterTree()
    {
        ProcessMode = ProcessModeEnum.Always;
        Instance = this;
    }

    public override void _ExitTree()
    {
        _attachments.Clear();
        _modalStack.Clear();
        _pauseOwners.Clear();
        if (Instance == this)
        {
            Instance = null;
        }
    }

    public override void _Process(double delta)
    {
        CleanupInvalidAttachments();
        var top = GetTopActiveModal();
        if (top is null || !top.Options.TrapFocus || !GodotObject.IsInstanceValid(top.Widget))
        {
            return;
        }

        var focusOwner = GetViewport().GuiGetFocusOwner();
        if (focusOwner is null ||
            !GodotObject.IsInstanceValid(focusOwner) ||
            !ReferenceEquals(focusOwner, top.Widget) && !top.Widget.IsAncestorOf(focusOwner))
        {
            GrabFirstFocusable(top.Widget);
        }
    }

    public override void _UnhandledInput(InputEvent @event)
    {
        var top = GetTopActiveModal();
        if (top is null)
        {
            return;
        }

        if (@event.IsActionPressed("ui_cancel"))
        {
            GetViewport().SetInputAsHandled();
            HandleCancel(top);
            return;
        }

        if (@event is InputEventKey or InputEventJoypadButton or InputEventJoypadMotion)
        {
            GetViewport().SetInputAsHandled();
        }
    }

    internal ManifestUiRootAttachment AttachWidget(Control widget, ManifestUiOpenOptions options)
    {
        var attachment = new ManifestUiRootAttachment(widget, options)
        {
            LayerId = string.IsNullOrWhiteSpace(options.LayerId) ? "Main" : options.LayerId,
            PreviousFocus = options.RestoreFocusOnClose ? GetViewport().GuiGetFocusOwner() : null,
            IsActive = true,
        };
        var layer = GetOrCreateLayer(attachment.LayerId);

        if (options.IsModal)
        {
            attachment.Blocker = CreateModalBlocker(widget);
            layer.AddChild(attachment.Blocker);
            _modalStack.Add(attachment);
            widget.ProcessMode = ProcessModeEnum.Always;
        }

        layer.AddChild(widget);
        if (!_layerStacks.TryGetValue(attachment.LayerId, out var stack))
        {
            stack = new List<Control>();
            _layerStacks[attachment.LayerId] = stack;
        }

        stack.Add(widget);
        _attachments[widget] = attachment;

        if (options.PauseTree)
        {
            AcquirePause(attachment);
            widget.ProcessMode = ProcessModeEnum.Always;
        }

        if (options.GrabFocus || options.IsModal)
        {
            GrabFirstFocusable(widget);
        }

        return attachment;
    }

    internal void HideWidget(Control widget, ManifestUiOpenOptions options, ManifestUiRootAttachment? attachment)
    {
        attachment ??= FindAttachment(widget);
        if (attachment is null || !attachment.IsActive)
        {
            return;
        }

        attachment.IsActive = false;
        if (attachment.Blocker is { } blocker && GodotObject.IsInstanceValid(blocker))
        {
            blocker.Visible = false;
            blocker.MouseFilter = Control.MouseFilterEnum.Ignore;
        }

        ReleasePause(attachment);
        FocusTopModalOrRestore(null);
    }

    internal void ShowWidget(Control widget, ManifestUiOpenOptions options, ManifestUiRootAttachment? attachment)
    {
        attachment ??= FindAttachment(widget);
        if (attachment is null || attachment.IsActive)
        {
            return;
        }

        attachment.IsActive = true;
        if (options.IsModal)
        {
            _modalStack.Remove(attachment);
            _modalStack.Add(attachment);
        }

        if (attachment.Blocker is { } blocker && GodotObject.IsInstanceValid(blocker))
        {
            blocker.Visible = true;
            blocker.MouseFilter = Control.MouseFilterEnum.Stop;
            blocker.MoveToFront();
            widget.MoveToFront();
        }

        if (options.PauseTree)
        {
            AcquirePause(attachment);
        }

        if (options.GrabFocus || options.IsModal)
        {
            GrabFirstFocusable(widget);
        }
    }

    internal void DetachWidget(Control widget, ManifestUiOpenOptions options, ManifestUiRootAttachment? attachment)
    {
        attachment ??= FindAttachment(widget);
        if (attachment is null)
        {
            return;
        }

        var wasTopModal = ReferenceEquals(GetTopActiveModal(), attachment);
        attachment.IsActive = false;
        _attachments.Remove(widget);
        _modalStack.Remove(attachment);
        if (_layerStacks.TryGetValue(attachment.LayerId, out var stack))
        {
            stack.Remove(widget);
        }

        ReleasePause(attachment);
        if (attachment.Blocker is { } blocker && GodotObject.IsInstanceValid(blocker))
        {
            blocker.GetParent()?.RemoveChild(blocker);
            blocker.Free();
        }

        if (wasTopModal || !options.IsModal)
        {
            FocusTopModalOrRestore(options.RestoreFocusOnClose ? attachment.PreviousFocus : null);
        }
    }

    public bool IsModalLayerActive()
    {
        CleanupInvalidAttachments();
        return GetTopActiveModal() is not null;
    }

    private ManifestUiRootAttachment? FindAttachment(Control widget)
    {
        return _attachments.TryGetValue(widget, out var attachment) ? attachment : null;
    }

    private Control GetOrCreateLayer(string layerId)
    {
        if (_layers.TryGetValue(layerId, out var layer) && GodotObject.IsInstanceValid(layer))
        {
            return layer;
        }

        layer = new Control
        {
            Name = layerId,
            MouseFilter = Control.MouseFilterEnum.Ignore,
        };
        layer.SetAnchorsAndOffsetsPreset(Control.LayoutPreset.FullRect);
        AddChild(layer);
        _layers[layerId] = layer;
        return layer;
    }

    private static Control CreateModalBlocker(Control widget)
    {
        var blocker = new Control
        {
            Name = $"{widget.Name}_ModalBlocker",
            MouseFilter = Control.MouseFilterEnum.Stop,
            FocusMode = Control.FocusModeEnum.None,
            ProcessMode = ProcessModeEnum.Always,
        };
        blocker.SetAnchorsAndOffsetsPreset(Control.LayoutPreset.FullRect);
        return blocker;
    }

    private void AcquirePause(ManifestUiRootAttachment attachment)
    {
        if (!_pauseOwners.Add(attachment))
        {
            return;
        }

        if (_pauseOwners.Count == 1)
        {
            _pausedBeforeRequests = GetTree().Paused;
        }

        GetTree().Paused = true;
    }

    private void ReleasePause(ManifestUiRootAttachment attachment)
    {
        if (!_pauseOwners.Remove(attachment) || _pauseOwners.Count > 0)
        {
            return;
        }

        GetTree().Paused = _pausedBeforeRequests;
    }

    private ManifestUiRootAttachment? GetTopActiveModal()
    {
        for (var index = _modalStack.Count - 1; index >= 0; index--)
        {
            var attachment = _modalStack[index];
            if (attachment.IsActive && GodotObject.IsInstanceValid(attachment.Widget) && attachment.Widget.IsInsideTree())
            {
                return attachment;
            }
        }

        return null;
    }

    private void FocusTopModalOrRestore(Control? fallback)
    {
        if (GetTopActiveModal() is { } top)
        {
            GrabFirstFocusable(top.Widget);
            return;
        }

        if (fallback is not null && GodotObject.IsInstanceValid(fallback) && fallback.IsInsideTree())
        {
            fallback.GrabFocus();
        }
    }

    private void HandleCancel(ManifestUiRootAttachment attachment)
    {
        switch (attachment.Options.CancelPolicy)
        {
            case ManifestUiCancelPolicy.Ignore:
                return;
            case ManifestUiCancelPolicy.InvokeCallback:
                if (ManifestUiManager.Instance?.GetHandle(attachment.Widget) is { } callbackHandle)
                {
                    try
                    {
                        attachment.Options.OnCancel?.Invoke(callbackHandle);
                    }
                    catch (Exception exception)
                    {
                        ManifestRuntimeDiagnostics.Report(
                            "MUIR6001",
                            ManifestRuntimeDiagnosticSeverity.Error,
                            "A modal cancel callback failed.",
                            exception,
                            callbackHandle.PackageId.ToString(),
                            callbackHandle.InstanceId);
                    }
                }
                return;
            case ManifestUiCancelPolicy.CloseTop:
                if (ManifestUiManager.Instance?.GetHandle(attachment.Widget) is { } handle)
                {
                    _ = ManifestUiManager.Instance.CloseAsync(handle, ManifestUiCloseReason.Cancelled);
                }
                return;
        }
    }

    private void CleanupInvalidAttachments()
    {
        foreach (var attachment in _attachments.Values.Where(attachment => !GodotObject.IsInstanceValid(attachment.Widget)).ToArray())
        {
            _attachments.Remove(attachment.Widget);
            _modalStack.Remove(attachment);
            ReleasePause(attachment);
            if (attachment.Blocker is { } blocker && GodotObject.IsInstanceValid(blocker))
            {
                blocker.QueueFree();
            }
        }
    }

    private static void GrabFirstFocusable(Control root)
    {
        FindFirstFocusable(root)?.GrabFocus();
    }

    private static Control? FindFirstFocusable(Node node)
    {
        if (node is Control control && control.Visible && control.FocusMode != Control.FocusModeEnum.None)
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
    public ManifestUiRootAttachment(Control widget, ManifestUiOpenOptions options)
    {
        Widget = widget;
        Options = options;
    }

    public Control Widget { get; }
    public ManifestUiOpenOptions Options { get; }
    public string LayerId { get; set; } = "Main";
    public Control? PreviousFocus { get; set; }
    public Control? Blocker { get; set; }
    public bool IsActive { get; set; }
}

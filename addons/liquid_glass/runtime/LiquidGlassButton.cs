using Godot;

namespace GodotUi.LiquidGlass;

[Tool]
[GlobalClass]
public partial class LiquidGlassButton : Control
{
    [Signal] public delegate void PressedEventHandler();

    private LiquidGlassPanel? _glass;
    private Label? _label;
    private bool _pressed;
    private bool _disabled;
    private string _text = "Button";
    private LiquidGlassStyle? _style;

    [Export]
    public string Text
    {
        get => _text;
        set { _text = value ?? ""; if (_label is not null) _label.Text = _text; QueueAccessibilityRefresh(); }
    }

    [Export]
    public bool Disabled
    {
        get => _disabled;
        set { _disabled = value; if (value) _pressed = false; MouseDefaultCursorShape = value ? CursorShape.Forbidden : CursorShape.PointingHand; UpdateVisualState(); QueueAccessibilityRefresh(); }
    }

    [Export]
    public LiquidGlassStyle? Style
    {
        get => _style;
        set { _style = value; if (_glass is not null) _glass.Style = value; }
    }

    public override void _EnterTree()
    {
        FocusMode = FocusModeEnum.All;
        MouseFilter = MouseFilterEnum.Stop;
        MouseDefaultCursorShape = CursorShape.PointingHand;
        CustomMinimumSize = new Vector2(120, 44);
        EnsureChildren();
        UpdateVisualState();
    }

    public override void _Notification(int what)
    {
        if (what == NotificationResized)
        {
            LayoutChildren();
        }
        else if (what == NotificationFocusEnter || what == NotificationFocusExit || what == NotificationMouseEnter || what == NotificationMouseExit)
        {
            UpdateVisualState();
            QueueAccessibilityRefresh();
        }
        else if (what == NotificationAccessibilityUpdate)
        {
            UpdateAccessibility();
        }
    }

    public override void _GuiInput(InputEvent @event)
    {
        if (_disabled)
        {
            return;
        }
        if (@event.IsActionPressed("ui_accept", false, false))
        {
            _pressed = true;
            UpdateVisualState();
            AcceptEvent();
            return;
        }
        if (@event.IsActionReleased("ui_accept"))
        {
            _pressed = false;
            UpdateVisualState();
            EmitSignal(SignalName.Pressed);
            AcceptEvent();
            return;
        }
        if (@event is InputEventMouseButton mouse && mouse.ButtonIndex == MouseButton.Left)
        {
            _pressed = mouse.Pressed;
            UpdateVisualState();
            if (!mouse.Pressed && new Rect2(Vector2.Zero, Size).HasPoint(mouse.Position))
            {
                GrabFocus();
                EmitSignal(SignalName.Pressed);
            }
            AcceptEvent();
            return;
        }
        if (@event is InputEventKey key && !key.Echo && key.Keycode is Key.Enter or Key.Space)
        {
            _pressed = key.Pressed;
            UpdateVisualState();
            if (!key.Pressed)
            {
                EmitSignal(SignalName.Pressed);
            }
            AcceptEvent();
        }
    }

    private void EnsureChildren()
    {
        _glass ??= new LiquidGlassPanel { Name = "_Glass", MouseFilter = MouseFilterEnum.Ignore, Style = _style };
        if (_glass.GetParent() is null)
        {
            AddChild(_glass, false, InternalMode.Back);
        }
        _label ??= new Label
        {
            Name = "_Label",
            Text = _text,
            HorizontalAlignment = HorizontalAlignment.Center,
            VerticalAlignment = VerticalAlignment.Center,
            MouseFilter = MouseFilterEnum.Ignore,
            ZIndex = 1,
        };
        _label.AddThemeColorOverride("font_color", Colors.White);
        _label.AddThemeFontSizeOverride("font_size", 16);
        if (_label.GetParent() is null)
        {
            AddChild(_label, false, InternalMode.Front);
        }
        LayoutChildren();
    }

    private void LayoutChildren()
    {
        if (_glass is not null)
        {
            _glass.Position = Vector2.Zero;
            _glass.Size = Size;
        }
        if (_label is not null)
        {
            _label.Position = Vector2.Zero;
            _label.Size = Size;
        }
    }

    private void UpdateVisualState()
    {
        if (_glass is null)
        {
            return;
        }
        var hovered = GetGlobalRect().HasPoint(GetGlobalMousePosition());
        _glass.VisualIntensity = _disabled ? 0.45f : _pressed ? 1.35f : hovered || HasFocus() ? 1.15f : 1.0f;
        Modulate = _disabled ? new Color(1, 1, 1, 0.62f) : Colors.White;
    }

    private void QueueAccessibilityRefresh()
    {
        if (IsInsideTree())
        {
            QueueAccessibilityUpdate();
        }
    }

    private void UpdateAccessibility()
    {
        var server = AccessibilityServer.Singleton;
        if (!server.IsSupported())
        {
            return;
        }
        var element = GetAccessibilityElement();
        if (!element.IsValid)
        {
            return;
        }
        server.UpdateSetRole(element, AccessibilityServer.AccessibilityRole.Button);
        server.UpdateSetName(element, string.IsNullOrWhiteSpace(AccessibilityName) ? _text : AccessibilityName);
        server.UpdateSetDescription(element, AccessibilityDescription);
        server.UpdateSetFlag(element, AccessibilityServer.AccessibilityFlags.Disabled, _disabled);
        server.UpdateSetStateDescription(element, _disabled ? "Disabled" : _pressed ? "Pressed" : HasFocus() ? "Focused" : "Ready");
        if (HasFocus())
        {
            server.UpdateSetFocus(element);
        }
    }
}

using Godot;
using System;

namespace GodotUi.LiquidGlass;

[Tool]
[GlobalClass]
public partial class LiquidGlassSlider : Control
{
    [Signal] public delegate void ValueChangedEventHandler(double value);

    private LiquidGlassPanel? _thumb;
    private double _minValue;
    private double _maxValue = 1.0;
    private double _value = 0.5;
    private double _step = 0.01;
    private float _visualRatio = 0.5f;
    private float _velocity;
    private bool _dragging;
    private bool _disabled;

    [Export] public double MinValue { get => _minValue; set { _minValue = value; _maxValue = Math.Max(_maxValue, _minValue + Math.Max(_step, double.Epsilon)); SetValue(_value, false); QueueAccessibilityRefresh(); } }
    [Export] public double MaxValue { get => _maxValue; set { _maxValue = Math.Max(value, _minValue + Math.Max(_step, double.Epsilon)); SetValue(_value, false); QueueAccessibilityRefresh(); } }
    [Export] public double Value { get => _value; set => SetValue(value, true); }
    [Export(PropertyHint.Range, "0.0001,100,0.0001,or_greater")] public double Step { get => _step; set { _step = Math.Max(value, 0.0001); SetValue(_value, false); QueueAccessibilityRefresh(); } }
    [Export(PropertyHint.Range, "20,400,1")] public float SpringStrength { get; set; } = 180.0f;
    [Export(PropertyHint.Range, "1,60,0.5")] public float SpringDamping { get; set; } = 22.0f;
    private LiquidGlassStyle? _thumbStyle;

    [Export]
    public LiquidGlassStyle? ThumbStyle
    {
        get => _thumbStyle;
        set { _thumbStyle = value; if (_thumb is not null) _thumb.Style = value; }
    }

    [Export]
    public bool Disabled
    {
        get => _disabled;
        set
        {
            _disabled = value;
            if (value)
            {
                _dragging = false;
            }
            MouseDefaultCursorShape = value ? CursorShape.Forbidden : CursorShape.PointingHand;
            Modulate = value ? new Color(1, 1, 1, 0.62f) : Colors.White;
            QueueAccessibilityRefresh();
        }
    }

    public override void _EnterTree()
    {
        FocusMode = FocusModeEnum.All;
        MouseFilter = MouseFilterEnum.Stop;
        MouseDefaultCursorShape = CursorShape.PointingHand;
        CustomMinimumSize = new Vector2(180, 38);
        SetProcess(true);
        EnsureThumb();
        QueueRedraw();
    }

    public override void _Notification(int what)
    {
        if (what == NotificationFocusEnter || what == NotificationFocusExit)
        {
            QueueRedraw();
            QueueAccessibilityRefresh();
        }
        else if (what == NotificationAccessibilityUpdate)
        {
            UpdateAccessibility();
        }
    }

    public override void _Process(double delta)
    {
        var target = Ratio();
        var acceleration = (target - _visualRatio) * SpringStrength - _velocity * SpringDamping;
        _velocity += acceleration * (float)delta;
        _visualRatio += _velocity * (float)delta;
        if (Mathf.Abs(target - _visualRatio) < 0.0005f && Mathf.Abs(_velocity) < 0.0005f)
        {
            _visualRatio = target;
            _velocity = 0.0f;
        }
        LayoutThumb();
        QueueRedraw();
    }

    public override void _Draw()
    {
        var centerY = Size.Y * 0.5f;
        var start = new Vector2(14, centerY);
        var end = new Vector2(Mathf.Max(Size.X - 14, 14), centerY);
        DrawLine(start, end, new Color(1, 1, 1, 0.22f), 8, true);
        DrawLine(start, start.Lerp(end, Mathf.Clamp(_visualRatio, 0, 1)), new Color("8fe6ff"), 8, true);
        if (HasFocus())
        {
            DrawStyleBox(new StyleBoxFlat { BorderColor = new Color("bdefff"), BorderWidthLeft = 2, BorderWidthTop = 2, BorderWidthRight = 2, BorderWidthBottom = 2, BgColor = Colors.Transparent, CornerRadiusTopLeft = 8, CornerRadiusTopRight = 8, CornerRadiusBottomLeft = 8, CornerRadiusBottomRight = 8 }, new Rect2(Vector2.Zero, Size));
        }
    }

    public override void _GuiInput(InputEvent @event)
    {
        if (_disabled)
        {
            return;
        }
        if (@event.IsActionPressed("ui_left", false, false) || @event.IsActionPressed("ui_down", false, false))
        {
            SetValue(_value - _step, true);
            AcceptEvent();
            return;
        }
        if (@event.IsActionPressed("ui_right", false, false) || @event.IsActionPressed("ui_up", false, false))
        {
            SetValue(_value + _step, true);
            AcceptEvent();
            return;
        }
        if (@event is InputEventMouseButton mouse && mouse.ButtonIndex == MouseButton.Left)
        {
            _dragging = mouse.Pressed;
            if (_dragging)
            {
                GrabFocus();
                UpdateFromX(mouse.Position.X);
            }
            AcceptEvent();
            return;
        }
        if (@event is InputEventMouseMotion motion && _dragging)
        {
            UpdateFromX(motion.Position.X);
            AcceptEvent();
            return;
        }
        if (@event is InputEventKey key && key.Pressed && !key.Echo)
        {
            if (key.Keycode is Key.Left or Key.Down)
            {
                SetValue(_value - _step, true);
                AcceptEvent();
            }
            else if (key.Keycode is Key.Right or Key.Up)
            {
                SetValue(_value + _step, true);
                AcceptEvent();
            }
            else if (key.Keycode == Key.Home)
            {
                SetValue(_minValue, true);
                AcceptEvent();
            }
            else if (key.Keycode == Key.End)
            {
                SetValue(_maxValue, true);
                AcceptEvent();
            }
        }
    }

    private void EnsureThumb()
    {
        _thumb ??= new LiquidGlassPanel
        {
            Name = "_Thumb",
            MouseFilter = MouseFilterEnum.Ignore,
            Style = _thumbStyle,
            Preset = LiquidGlassPreset.Vibrant,
        };
        if (_thumb.GetParent() is null)
        {
            AddChild(_thumb, false, InternalMode.Front);
        }
        LayoutThumb();
    }

    private void LayoutThumb()
    {
        if (_thumb is null)
        {
            return;
        }
        var diameter = Mathf.Min(30.0f, Mathf.Max(18.0f, Size.Y - 4.0f));
        var x = Mathf.Lerp(14.0f, Mathf.Max(Size.X - 14.0f, 14.0f), Mathf.Clamp(_visualRatio, 0, 1));
        _thumb.Position = new Vector2(x - diameter * 0.5f, (Size.Y - diameter) * 0.5f);
        _thumb.Size = new Vector2(diameter, diameter);
        _thumb.VisualIntensity = _dragging ? 1.35f : HasFocus() ? 1.15f : 1.0f;
    }

    private void UpdateFromX(float x)
    {
        var width = Mathf.Max(Size.X - 28.0f, 1.0f);
        var ratio = Mathf.Clamp((x - 14.0f) / width, 0.0f, 1.0f);
        SetValue(Mathf.Lerp((float)_minValue, (float)_maxValue, ratio), true);
    }

    private void SetValue(double value, bool emit)
    {
        var snapped = _minValue + Math.Round((Math.Clamp(value, _minValue, _maxValue) - _minValue) / _step) * _step;
        snapped = Math.Clamp(snapped, _minValue, _maxValue);
        if (Math.Abs(_value - snapped) < 0.0000001)
        {
            return;
        }
        _value = snapped;
        QueueRedraw();
        if (emit)
        {
            EmitSignal(SignalName.ValueChanged, _value);
        }
        QueueAccessibilityRefresh();
    }

    private float Ratio()
    {
        return (float)((_value - _minValue) / Math.Max(_maxValue - _minValue, double.Epsilon));
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
        server.UpdateSetRole(element, AccessibilityServer.AccessibilityRole.Slider);
        server.UpdateSetName(element, string.IsNullOrWhiteSpace(AccessibilityName) ? "Value" : AccessibilityName);
        server.UpdateSetDescription(element, AccessibilityDescription);
        server.UpdateSetValue(element, _value.ToString("G", System.Globalization.CultureInfo.InvariantCulture));
        server.UpdateSetNumValue(element, _value);
        server.UpdateSetNumRange(element, _minValue, _maxValue);
        server.UpdateSetNumStep(element, _step);
        server.UpdateSetFlag(element, AccessibilityServer.AccessibilityFlags.Disabled, _disabled);
        server.UpdateSetStateDescription(element, _disabled ? "Disabled" : HasFocus() ? "Focused" : "Ready");
        if (HasFocus())
        {
            server.UpdateSetFocus(element);
        }
    }
}

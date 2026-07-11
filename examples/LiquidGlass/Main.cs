using Godot;
using GodotUi.LiquidGlass;

public partial class Main : Control
{
    private Label? _status;

    public override void _Ready()
    {
        AddBackground(new Rect2(0, 0, 960, 540), new Color("111726"));
        AddBackground(new Rect2(0, 0, 320, 540), new Color("e34b69"));
        AddBackground(new Rect2(320, 0, 320, 540), new Color("1aa7a1"));
        AddBackground(new Rect2(640, 0, 320, 540), new Color("efbd3f"));

        var superellipse = new LiquidGlassStyle
        {
            Shape = LiquidGlassShape.Superellipse,
            SuperellipseExponent = 4.5f,
            Tint = new Color("d9f7ff"),
        };
        superellipse.ApplyPreset(LiquidGlassPreset.Frosted);
        AddGlass(new Rect2(75, 65, 440, 270), superellipse, "SUPERELLIPSE");

        var overlap = new LiquidGlassStyle
        {
            Shape = LiquidGlassShape.RoundedRectangle,
            CornerRadius = 24,
            Tint = new Color("ffc8ef"),
        };
        overlap.ApplyPreset(LiquidGlassPreset.Vibrant);
        AddGlass(new Rect2(380, 185, 390, 240), overlap, "OVERLAP");

        var button = new LiquidGlassButton
        {
            Text = "Apply glass",
            AccessibilityName = "Apply glass effect",
            Position = new Vector2(105, 400),
            Size = new Vector2(205, 58),
        };
        button.Pressed += () => SetStatus("Button activated");
        AddChild(button);

        var slider = new LiquidGlassSlider
        {
            AccessibilityName = "Glass intensity",
            Position = new Vector2(390, 410),
            Size = new Vector2(350, 44),
            MinValue = 0,
            MaxValue = 1,
            Step = 0.05,
            Value = 0.45,
        };
        slider.ValueChanged += value => SetStatus($"Intensity {value:F2}");
        AddChild(slider);

        _status = new Label
        {
            Position = new Vector2(105, 475),
            Size = new Vector2(635, 30),
            Text = "Use mouse, keyboard, or controller UI actions",
        };
        AddChild(_status);
    }

    private void AddBackground(Rect2 rect, Color color)
    {
        AddChild(new ColorRect
        {
            Position = rect.Position,
            Size = rect.Size,
            Color = color,
            MouseFilter = MouseFilterEnum.Ignore,
        });
    }

    private void AddGlass(Rect2 rect, LiquidGlassStyle style, string title)
    {
        var panel = new LiquidGlassPanel
        {
            Position = rect.Position,
            Size = rect.Size,
            Style = style,
            Preset = LiquidGlassPreset.Custom,
            AccessibilityName = title,
        };
        panel.AddChild(new Label
        {
            Position = new Vector2(28, 26),
            Size = new Vector2(rect.Size.X - 56, 32),
            Text = title,
            MouseFilter = MouseFilterEnum.Ignore,
        });
        AddChild(panel);
    }

    private void SetStatus(string text)
    {
        if (_status is not null)
        {
            _status.Text = text;
        }
    }
}

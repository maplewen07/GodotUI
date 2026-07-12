using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading.Tasks;
using Godot;
using GodotUi.LiquidGlass;

namespace GodotUi.Tests;

public partial class LiquidGlassVisualCheck : Control
{
    private static readonly Vector2 DesignSize = new(960, 540);

    private int _buttonPresses;
    private int _sliderChanges;
    private float _scale = 1.0f;
    private Vector2 _offset;

    public override async void _Ready()
    {
        try
        {
            ConfigureScale();
            BuildScene();
            await WaitFramesAsync(3);
            VerifyInteraction();
            await MeasureFrameBudgetAsync();
            RenderingServer.ForceDraw(false, 0.0);
            await ToSignal(RenderingServer.Singleton, RenderingServer.SignalName.FramePostDraw);
            CaptureAndVerify();
            GD.Print("Liquid Glass visual check passed.");
            GetTree().Quit(0);
        }
        catch (Exception exception)
        {
            GD.PushError(exception.ToString());
            GetTree().Quit(1);
        }
    }

    private void ConfigureScale()
    {
        var viewportSize = GetViewportRect().Size;
        _scale = Mathf.Min(viewportSize.X / DesignSize.X, viewportSize.Y / DesignSize.Y);
        Require(_scale > 0.0f, "viewport has no drawable area");
        _offset = (viewportSize - DesignSize * _scale) * 0.5f;

        if (TryReadInt("LIQUID_GLASS_EXPECTED_WIDTH", out var expectedWidth))
        {
            Require(Math.Abs(viewportSize.X - expectedWidth) <= 1.0f, $"viewport width {viewportSize.X} does not match {expectedWidth}");
        }
        if (TryReadInt("LIQUID_GLASS_EXPECTED_HEIGHT", out var expectedHeight))
        {
            Require(Math.Abs(viewportSize.Y - expectedHeight) <= 1.0f, $"viewport height {viewportSize.Y} does not match {expectedHeight}");
        }
    }

    private void BuildScene()
    {
        SetAnchorsAndOffsetsPreset(LayoutPreset.FullRect);

        AddColorBlock(new Rect2(Vector2.Zero, DesignSize), new Color("101625"));
        AddColorBlock(new Rect2(0, 0, 310, 540), new Color("e24a68"));
        AddColorBlock(new Rect2(310, 0, 330, 540), new Color("1aa7a1"));
        AddColorBlock(new Rect2(640, 0, 320, 540), new Color("f1bd3b"));
        AddColorBlock(new Rect2(90, 95, 260, 120), new Color("3156d3"));
        AddColorBlock(new Rect2(520, 245, 310, 150), new Color("862d91"));

        var primaryStyle = new LiquidGlassStyle
        {
            Shape = LiquidGlassShape.Superellipse,
            SuperellipseExponent = 4.6f,
            Tint = new Color("d7f6ff"),
        };
        primaryStyle.ApplyPreset(LiquidGlassPreset.Frosted);
        var primary = AddGlassPanel("PrimaryGlass", new Rect2(78, 58, 420, 270), primaryStyle);
        AddPanelLabel(primary, "FROSTED / SUPERELLIPSE", new Vector2(28, 24), 18);
        AddPanelLabel(primary, "Screen texture blur, tint, rim and inner shadow", new Vector2(28, 62), 14);

        var overlapStyle = new LiquidGlassStyle
        {
            Shape = LiquidGlassShape.RoundedRectangle,
            Tint = new Color("ffc8f0"),
            CornerRadius = 24,
        };
        overlapStyle.ApplyPreset(LiquidGlassPreset.Vibrant);
        var overlap = AddGlassPanel("OverlapGlass", new Rect2(360, 178, 390, 245), overlapStyle);
        AddPanelLabel(overlap, "VIBRANT OVERLAP", new Vector2(28, 28), 18);
        AddPanelLabel(overlap, "Drawn after the frosted panel", new Vector2(28, 66), 14);

        var capsuleStyle = new LiquidGlassStyle
        {
            Shape = LiquidGlassShape.Capsule,
            Tint = new Color("f6ffe0"),
        };
        capsuleStyle.ApplyPreset(LiquidGlassPreset.Clear);
        var capsule = AddGlassPanel("CapsuleGlass", new Rect2(595, 62, 280, 72), capsuleStyle);
        AddPanelLabel(capsule, "CAPSULE", new Vector2(88, 22), 17);

        var circleStyle = new LiquidGlassStyle
        {
            Shape = LiquidGlassShape.Circle,
            Tint = new Color("ffe6a8"),
        };
        circleStyle.ApplyPreset(LiquidGlassPreset.Soft);
        AddGlassPanel("CircleGlass", new Rect2(796, 372, 82, 82), circleStyle);

        var button = new LiquidGlassButton
        {
            Name = "ActionButton",
            Text = "Apply glass",
            AccessibilityName = "Apply glass effect",
            AccessibilityDescription = "Activates the Liquid Glass example action.",
            Position = ScalePoint(new Vector2(105, 390)),
            Size = ScaleVector(new Vector2(205, 58)),
        };
        button.Pressed += () => _buttonPresses++;
        AddChild(button);

        var slider = new LiquidGlassSlider
        {
            Name = "IntensitySlider",
            AccessibilityName = "Glass intensity",
            AccessibilityDescription = "Adjusts the visual intensity from zero to one.",
            Position = ScalePoint(new Vector2(390, 400)),
            Size = ScaleVector(new Vector2(360, 46)),
            MinValue = 0,
            MaxValue = 1,
            Step = 0.05,
            Value = 0.35,
        };
        slider.ValueChanged += _ => _sliderChanges++;
        AddChild(slider);
    }

    private void VerifyInteraction()
    {
        var button = GetNode<LiquidGlassButton>("ActionButton");
        Require(button.AccessibilityName == "Apply glass effect", "button accessibility name was not retained");
        var buttonLabel = button.GetNodeOrNull<Label>("_Label");
        Require(buttonLabel is { Visible: true, Text: "Apply glass" } && buttonLabel.ZIndex > 0, "button label is not configured above the glass surface");
        button.GrabFocus();
        using (var acceptDown = new InputEventAction { Action = "ui_accept", Pressed = true })
        using (var acceptUp = new InputEventAction { Action = "ui_accept", Pressed = false })
        {
            button._GuiInput(acceptDown);
            button._GuiInput(acceptUp);
        }
        Require(_buttonPresses == 1, "ui_accept should emit one button press");

        using (var keyDown = new InputEventKey { Keycode = Key.Space, Pressed = true })
        using (var keyUp = new InputEventKey { Keycode = Key.Space, Pressed = false })
        {
            button._GuiInput(keyDown);
            button._GuiInput(keyUp);
        }
        Require(_buttonPresses == 2, "keyboard activation should emit one additional button press");

        button.Disabled = true;
        using (var accept = new InputEventAction { Action = "ui_accept", Pressed = true })
        {
            button._GuiInput(accept);
        }
        Require(_buttonPresses == 2, "disabled button accepted an action");
        button.Disabled = false;

        var slider = GetNode<LiquidGlassSlider>("IntensitySlider");
        Require(slider.AccessibilityName == "Glass intensity", "slider accessibility name was not retained");
        var initial = slider.Value;
        slider.GrabFocus();
        using (var right = new InputEventAction { Action = "ui_right", Pressed = true })
        {
            slider._GuiInput(right);
        }
        Require(slider.Value > initial && _sliderChanges == 1, "ui_right should advance the slider once");

        using (var left = new InputEventAction { Action = "ui_left", Pressed = true })
        {
            slider._GuiInput(left);
        }
        Require(Math.Abs(slider.Value - initial) < 0.000001 && _sliderChanges == 2, "ui_left should restore the slider value");

        slider.Disabled = true;
        using (var right = new InputEventAction { Action = "ui_right", Pressed = true })
        {
            slider._GuiInput(right);
        }
        Require(Math.Abs(slider.Value - initial) < 0.000001, "disabled slider accepted an action");
        slider.Disabled = false;

        var primaryIndex = GetNode<LiquidGlassPanel>("PrimaryGlass").GetIndex();
        var overlapIndex = GetNode<LiquidGlassPanel>("OverlapGlass").GetIndex();
        Require(overlapIndex > primaryIndex, "overlap panel must draw after the primary panel");
        Require(GetNode<LiquidGlassPanel>("PrimaryGlass").Style?.Shape == LiquidGlassShape.Superellipse, "superellipse shape was not configured");
    }

    private async Task MeasureFrameBudgetAsync()
    {
        const int frameCount = 24;
        await WaitFramesAsync(3);
        var started = Time.GetTicksUsec();
        await WaitFramesAsync(frameCount);
        var averageMs = (Time.GetTicksUsec() - started) / 1000.0 / frameCount;
        var budgetMs = TryReadDouble("LIQUID_GLASS_FRAME_BUDGET_MS", out var configuredBudget) ? configuredBudget : 50.0;
        GD.Print($"LIQUID_GLASS_METRIC average_frame_ms={averageMs:F3} budget_ms={budgetMs:F3}");
        Require(averageMs <= budgetMs, $"average frame time {averageMs:F3} ms exceeded the coarse {budgetMs:F3} ms budget");
    }

    private async Task WaitFramesAsync(int count)
    {
        for (var index = 0; index < count; index++)
        {
            await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);
        }
    }

    private void CaptureAndVerify()
    {
        using var image = GetViewport().GetTexture().GetImage();
        Require(!image.IsEmpty(), "viewport capture is empty");
        Require(image.GetWidth() >= 600 && image.GetHeight() >= 330, "viewport capture is smaller than the minimum visual gate");

        long visiblePixels = 0;
        var sampledColors = new HashSet<uint>();
        var stride = Math.Max(4, image.GetWidth() / 160);
        for (var y = 0; y < image.GetHeight(); y++)
        {
            for (var x = 0; x < image.GetWidth(); x++)
            {
                var color = image.GetPixel(x, y);
                if (color.A > 0.95f)
                {
                    visiblePixels++;
                }
                if (x % stride == 0 && y % stride == 0)
                {
                    sampledColors.Add(color.ToRgba32());
                }
            }
        }

        var pixelCount = (long)image.GetWidth() * image.GetHeight();
        Require(visiblePixels > pixelCount * 9 / 10, "rendered frame contains too many transparent pixels");
        Require(sampledColors.Count >= 32, "rendered frame lacks the expected color and glass variation");

        var doubleGlass = GetLogicalPixel(image, new Vector2(430, 220));
        var singleGlass = GetLogicalPixel(image, new Vector2(620, 220));
        var unobscured = GetLogicalPixel(image, new Vector2(430, 480));
        Require(doubleGlass.A > 0.95f && singleGlass.A > 0.95f, "overlap samples are unexpectedly transparent");
        Require(ColorDistance(doubleGlass, singleGlass) > 0.008f, "double-glass and single-glass samples are indistinguishable");
        Require(ColorDistance(singleGlass, unobscured) > 0.02f, "glass sample is indistinguishable from its unobscured background");

        var configuredPath = System.Environment.GetEnvironmentVariable("LIQUID_GLASS_SCREENSHOT");
        var screenshotPath = string.IsNullOrWhiteSpace(configuredPath)
            ? ProjectSettings.GlobalizePath("res://artifacts/test-results/liquid-glass.png")
            : Path.GetFullPath(configuredPath);
        Directory.CreateDirectory(Path.GetDirectoryName(screenshotPath)!);
        var error = image.SavePng(screenshotPath);
        Require(error == Error.Ok, $"failed to save screenshot: {error}");
        GD.Print($"Liquid Glass screenshot: {screenshotPath}");
    }

    private LiquidGlassPanel AddGlassPanel(string name, Rect2 rect, LiquidGlassStyle style)
    {
        var scaled = ScaleRect(rect);
        var panel = new LiquidGlassPanel
        {
            Name = name,
            AccessibilityName = name,
            Position = scaled.Position,
            Size = scaled.Size,
            Style = style,
            Preset = LiquidGlassPreset.Custom,
        };
        AddChild(panel);
        return panel;
    }

    private void AddColorBlock(Rect2 rect, Color color)
    {
        var scaled = ScaleRect(rect);
        AddChild(new ColorRect
        {
            Position = scaled.Position,
            Size = scaled.Size,
            Color = color,
            MouseFilter = MouseFilterEnum.Ignore,
        });
    }

    private void AddPanelLabel(Control parent, string text, Vector2 position, int fontSize)
    {
        var label = new Label
        {
            Text = text,
            Position = position * _scale,
            Size = new Vector2(parent.Size.X - position.X * _scale * 2, 32 * _scale),
            MouseFilter = MouseFilterEnum.Ignore,
        };
        label.AddThemeFontSizeOverride("font_size", Math.Max(9, Mathf.RoundToInt(fontSize * _scale)));
        label.AddThemeColorOverride("font_color", new Color("f7fbff"));
        parent.AddChild(label);
    }

    private Rect2 ScaleRect(Rect2 rect)
    {
        return new Rect2(ScalePoint(rect.Position), ScaleVector(rect.Size));
    }

    private Vector2 ScalePoint(Vector2 point)
    {
        return _offset + point * _scale;
    }

    private Vector2 ScaleVector(Vector2 vector)
    {
        return vector * _scale;
    }

    private Color GetLogicalPixel(Image image, Vector2 point)
    {
        var scaled = ScalePoint(point);
        var x = Math.Clamp(Mathf.RoundToInt(scaled.X), 0, image.GetWidth() - 1);
        var y = Math.Clamp(Mathf.RoundToInt(scaled.Y), 0, image.GetHeight() - 1);
        return image.GetPixel(x, y);
    }

    private static float ColorDistance(Color left, Color right)
    {
        var red = left.R - right.R;
        var green = left.G - right.G;
        var blue = left.B - right.B;
        return Mathf.Sqrt(red * red + green * green + blue * blue);
    }

    private static bool TryReadInt(string name, out int value)
    {
        return int.TryParse(System.Environment.GetEnvironmentVariable(name), NumberStyles.Integer, CultureInfo.InvariantCulture, out value);
    }

    private static bool TryReadDouble(string name, out double value)
    {
        return double.TryParse(System.Environment.GetEnvironmentVariable(name), NumberStyles.Float, CultureInfo.InvariantCulture, out value);
    }

    private static void Require(bool condition, string message)
    {
        if (!condition)
        {
            throw new InvalidOperationException(message);
        }
    }
}

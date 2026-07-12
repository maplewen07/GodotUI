using System;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;
using Godot;
using GodotUi.Generated.LiquidGlass;
using GodotUi.LiquidGlass;
using GodotUi.Manifest;

namespace GodotUi.Tests;

public partial class ManifestLiquidGlassVisualCheck : Control
{
    public override async void _Ready()
    {
        try
        {
            SetAnchorsAndOffsetsPreset(LayoutPreset.FullRect);
            var manager = ManifestUiManager.Instance
                ?? throw new InvalidOperationException("ManifestUiManager autoload is not available.");

            LiquidGlassWidgetManifestCatalog.Register(manager, replace: true);
            var handle = await manager.OpenAsync(
                "ui.liquid_glass",
                new ManifestUiOpenOptions
                {
                    LayerId = "Visual",
                    Mode = ManifestUiOpenMode.Replace,
                    GrabFocus = true,
                });
            var widget = handle.Widget as LiquidGlassWidget
                ?? throw new InvalidOperationException("Liquid Glass generated widget did not open.");

            await WaitFramesAsync(4);
            VerifyGeneratedContract(widget);
            VerifyInteraction(widget);
            await WaitFramesAsync(2);
            VerifyBounds(widget);

            RenderingServer.ForceDraw(false, 0.0);
            await ToSignal(RenderingServer.Singleton, RenderingServer.SignalName.FramePostDraw);
            CaptureAndVerify();

            await manager.CloseAsync(handle, ManifestUiCloseReason.Programmatic);
            await manager.ReleaseAsync("ui.liquid_glass", closeInstances: true);
            GD.Print("Manifest Liquid Glass visual check passed.");
            GetTree().Quit(0);
        }
        catch (Exception exception)
        {
            GD.PushError(exception.ToString());
            GetTree().Quit(1);
        }
    }

    private static void VerifyGeneratedContract(LiquidGlassWidget widget)
    {
        var primary = widget.GetNode<LiquidGlassPanel>("PrimaryGlass");
        var overlap = widget.GetNode<LiquidGlassPanel>("OverlapGlass");
        Require(primary.Style is not null, "primary style resource was not assigned");
        Require(overlap.Style is not null, "overlap style resource was not assigned");
        Require(primary.Style!.Shape == LiquidGlassShape.Superellipse, "primary style shape mismatch");
        Require(Math.Abs(primary.Style.SuperellipseExponent - 4.6f) < 0.001f, "primary exponent mismatch");
        Require(overlap.Style!.Shape == LiquidGlassShape.RoundedRectangle, "overlap style shape mismatch");
        Require(Math.Abs(overlap.Style.CornerRadius - 24.0f) < 0.001f, "overlap corner radius mismatch");
        Require(primary.Style.ResourcePath.EndsWith("frosted_superellipse_style_resource.tres", StringComparison.Ordinal), "primary resource path mismatch");
        Require(overlap.Style.ResourcePath.EndsWith("vibrant_rounded_style_resource.tres", StringComparison.Ordinal), "overlap resource path mismatch");
        Require(widget.GetNode<LiquidGlassButton>("ActionButton").Text == "Apply glass", "button script property mismatch");
        Require(Math.Abs(widget.GetNode<LiquidGlassSlider>("IntensitySlider").Value - 0.45) < 0.001, "slider script property mismatch");
    }

    private static void VerifyInteraction(LiquidGlassWidget widget)
    {
        var status = widget.GetNode<Label>("StatusLabel");
        var button = widget.GetNode<LiquidGlassButton>("ActionButton");
        button.EmitSignal(LiquidGlassButton.SignalName.Pressed);
        Require(status.Text == "Glass applied 1 time(s)", "generated button event did not reach the controller");

        var slider = widget.GetNode<LiquidGlassSlider>("IntensitySlider");
        slider.Value = 0.65;
        Require(status.Text == "Intensity 0.65", "generated slider input did not reach the controller");
        Require(widget.GetNode<Label>("IntensityLabel").Text == "0.65", "slider Store value did not flush to the view");
        Require(Math.Abs(widget.Store.Get<double>("intensity", 0.0) - 0.65) < 0.001, "slider input did not update the Store");
    }

    private void VerifyBounds(LiquidGlassWidget widget)
    {
        var viewport = GetViewportRect();
        foreach (var path in new[]
                 {
                     "TitleLabel",
                     "PrimaryGlass",
                     "OverlapGlass",
                     "ActionButton",
                     "IntensitySlider",
                     "IntensityLabel",
                     "StatusLabel",
                 })
        {
            var rect = widget.GetNode<Control>(path).GetGlobalRect();
            Require(rect.Position.X >= viewport.Position.X - 1.0f, $"{path} overflows the left edge");
            Require(rect.Position.Y >= viewport.Position.Y - 1.0f, $"{path} overflows the top edge");
            Require(rect.End.X <= viewport.End.X + 1.0f, $"{path} overflows the right edge");
            Require(rect.End.Y <= viewport.End.Y + 1.0f, $"{path} overflows the bottom edge");
        }
    }

    private void CaptureAndVerify()
    {
        using var image = GetViewport().GetTexture().GetImage();
        Require(!image.IsEmpty(), "viewport capture is empty");
        if (TryReadInt("MANIFEST_LIQUID_GLASS_EXPECTED_WIDTH", out var expectedWidth))
        {
            Require(image.GetWidth() == expectedWidth, $"image width {image.GetWidth()} does not match {expectedWidth}");
        }
        if (TryReadInt("MANIFEST_LIQUID_GLASS_EXPECTED_HEIGHT", out var expectedHeight))
        {
            Require(image.GetHeight() == expectedHeight, $"image height {image.GetHeight()} does not match {expectedHeight}");
        }

        long opaquePixels = 0;
        var sampledColors = new HashSet<uint>();
        var stride = Math.Max(3, image.GetWidth() / 160);
        for (var y = 0; y < image.GetHeight(); y++)
        {
            for (var x = 0; x < image.GetWidth(); x++)
            {
                var color = image.GetPixel(x, y);
                if (color.A > 0.95f)
                {
                    opaquePixels++;
                }
                if (x % stride == 0 && y % stride == 0)
                {
                    sampledColors.Add(color.ToRgba32());
                }
            }
        }

        var pixelCount = (long)image.GetWidth() * image.GetHeight();
        Require(opaquePixels > pixelCount * 9 / 10, "rendered frame contains too many transparent pixels");
        Require(sampledColors.Count >= 32, "rendered frame lacks expected background and glass variation");

        var configuredPath = System.Environment.GetEnvironmentVariable("MANIFEST_LIQUID_GLASS_SCREENSHOT");
        var screenshotPath = string.IsNullOrWhiteSpace(configuredPath)
            ? ProjectSettings.GlobalizePath("res://artifacts/test-results/manifest-liquid-glass.png")
            : Path.GetFullPath(configuredPath);
        Directory.CreateDirectory(Path.GetDirectoryName(screenshotPath)!);
        var error = image.SavePng(screenshotPath);
        Require(error == Error.Ok, $"failed to save screenshot: {error}");
        GD.Print($"Manifest Liquid Glass screenshot: {screenshotPath}");
    }

    private async Task WaitFramesAsync(int count)
    {
        for (var index = 0; index < count; index++)
        {
            await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);
        }
    }

    private static bool TryReadInt(string name, out int value)
    {
        return int.TryParse(System.Environment.GetEnvironmentVariable(name), out value);
    }

    private static void Require(bool condition, string message)
    {
        if (!condition)
        {
            throw new InvalidOperationException(message);
        }
    }
}

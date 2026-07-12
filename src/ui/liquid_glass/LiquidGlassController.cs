using System;
using GodotUi.Manifest;

namespace GodotUi.Sample.LiquidGlass;

public sealed class LiquidGlassController : ManifestControllerBase
{
    private int _applyCount;

    protected override void OnSetup()
    {
        using (Store.BeginBatch())
        {
            Store.Set("status", "Use mouse, keyboard, or controller UI actions");
            Store.Set("intensity", 0.45);
        }
    }

    public override void DispatchEvent(string eventId)
    {
        if (!string.Equals(eventId, "apply_glass", StringComparison.Ordinal))
        {
            return;
        }

        _applyCount++;
        Store.Set("status", $"Glass applied {_applyCount} time(s)");
    }

    protected override void OnInputChanged(string fieldId, object? value, ManifestGeneratedWidget widget)
    {
        if (!string.Equals(fieldId, "intensity", StringComparison.Ordinal))
        {
            return;
        }

        var intensity = Convert.ToDouble(value ?? 0.0);
        using (Store.BeginBatch())
        {
            Store.Set("intensity", intensity);
            Store.Set("status", $"Intensity {intensity:0.00}");
        }
    }
}

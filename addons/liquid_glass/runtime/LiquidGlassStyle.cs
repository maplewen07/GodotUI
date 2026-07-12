using Godot;
using System;

namespace GodotUi.LiquidGlass;

[Tool]
[GlobalClass]
public partial class LiquidGlassStyle : Resource
{
    private LiquidGlassShape _shape = LiquidGlassShape.RoundedRectangle;
    private float _cornerRadius = 28.0f;
    private float _superellipseExponent = 4.0f;
    private float _edgeSoftness = 1.25f;
    private float _blurLod = 2.2f;
    private float _refraction = 4.0f;
    private float _dispersion = 0.8f;
    private Color _tint = new("b8e8ff");
    private float _tintStrength = 0.16f;
    private float _saturation = 1.08f;
    private float _rimStrength = 0.42f;
    private float _innerShadow = 0.16f;
    private float _noiseStrength = 0.008f;

    [Export] public LiquidGlassShape Shape { get => _shape; set => Set(ref _shape, value); }
    [Export(PropertyHint.Range, "0,128,0.5")] public float CornerRadius { get => _cornerRadius; set => Set(ref _cornerRadius, Math.Max(0.0f, value)); }
    [Export(PropertyHint.Range, "2,12,0.1")] public float SuperellipseExponent { get => _superellipseExponent; set => Set(ref _superellipseExponent, Math.Clamp(value, 2.0f, 12.0f)); }
    [Export(PropertyHint.Range, "0.25,4,0.05")] public float EdgeSoftness { get => _edgeSoftness; set => Set(ref _edgeSoftness, Math.Max(0.25f, value)); }
    [Export(PropertyHint.Range, "0,8,0.05")] public float BlurLod { get => _blurLod; set => Set(ref _blurLod, Math.Clamp(value, 0.0f, 8.0f)); }
    [Export(PropertyHint.Range, "0,24,0.1")] public float Refraction { get => _refraction; set => Set(ref _refraction, Math.Clamp(value, 0.0f, 24.0f)); }
    [Export(PropertyHint.Range, "0,8,0.05")] public float Dispersion { get => _dispersion; set => Set(ref _dispersion, Math.Clamp(value, 0.0f, 8.0f)); }
    [Export] public Color Tint { get => _tint; set => Set(ref _tint, value); }
    [Export(PropertyHint.Range, "0,1,0.01")] public float TintStrength { get => _tintStrength; set => Set(ref _tintStrength, Math.Clamp(value, 0.0f, 1.0f)); }
    [Export(PropertyHint.Range, "0,2,0.01")] public float Saturation { get => _saturation; set => Set(ref _saturation, Math.Clamp(value, 0.0f, 2.0f)); }
    [Export(PropertyHint.Range, "0,2,0.01")] public float RimStrength { get => _rimStrength; set => Set(ref _rimStrength, Math.Clamp(value, 0.0f, 2.0f)); }
    [Export(PropertyHint.Range, "0,1,0.01")] public float InnerShadow { get => _innerShadow; set => Set(ref _innerShadow, Math.Clamp(value, 0.0f, 1.0f)); }
    [Export(PropertyHint.Range, "0,0.08,0.001")] public float NoiseStrength { get => _noiseStrength; set => Set(ref _noiseStrength, Math.Clamp(value, 0.0f, 0.08f)); }

    public void ApplyPreset(LiquidGlassPreset preset)
    {
        switch (preset)
        {
            case LiquidGlassPreset.Clear:
                BlurLod = 0.8f; Refraction = 2.0f; Dispersion = 0.25f; TintStrength = 0.08f; Saturation = 1.02f; RimStrength = 0.28f; InnerShadow = 0.08f; NoiseStrength = 0.003f;
                break;
            case LiquidGlassPreset.Soft:
                BlurLod = 2.2f; Refraction = 3.5f; Dispersion = 0.6f; TintStrength = 0.14f; Saturation = 1.06f; RimStrength = 0.38f; InnerShadow = 0.14f; NoiseStrength = 0.006f;
                break;
            case LiquidGlassPreset.Frosted:
                BlurLod = 4.6f; Refraction = 1.8f; Dispersion = 0.3f; TintStrength = 0.28f; Saturation = 0.88f; RimStrength = 0.52f; InnerShadow = 0.22f; NoiseStrength = 0.018f;
                break;
            case LiquidGlassPreset.Vibrant:
                BlurLod = 1.8f; Refraction = 6.5f; Dispersion = 1.8f; TintStrength = 0.2f; Saturation = 1.3f; RimStrength = 0.7f; InnerShadow = 0.12f; NoiseStrength = 0.005f;
                break;
        }
        EmitChanged();
    }

    private void Set<T>(ref T field, T value)
    {
        if (Equals(field, value))
        {
            return;
        }
        field = value;
        EmitChanged();
    }
}

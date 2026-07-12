using Godot;

namespace GodotUi.LiquidGlass;

[Tool]
[GlobalClass]
public partial class LiquidGlassPanel : Control
{
    private const string ShaderPath = "res://addons/liquid_glass/shaders/liquid_glass.gdshader";

    private BackBufferCopy? _backBuffer;
    private ColorRect? _surface;
    private ShaderMaterial? _material;
    private LiquidGlassStyle? _style;
    private bool _styleConnected;
    private LiquidGlassPreset _preset = LiquidGlassPreset.Soft;
    private float _visualIntensity = 1.0f;

    [Export]
    public LiquidGlassStyle? Style
    {
        get => _style;
        set
        {
            if (_style == value)
            {
                return;
            }
            if (_styleConnected && _style is not null)
            {
                _style.Changed -= UpdateMaterial;
                _styleConnected = false;
            }
            _style = value;
            ConnectStyle();
            UpdateMaterial();
        }
    }

    [Export]
    public LiquidGlassPreset Preset
    {
        get => _preset;
        set
        {
            _preset = value;
            EnsureStyle();
            if (value != LiquidGlassPreset.Custom)
            {
                _style!.ApplyPreset(value);
            }
            UpdateMaterial();
        }
    }

    [Export(PropertyHint.Range, "0,2,0.01")]
    public float VisualIntensity
    {
        get => _visualIntensity;
        set
        {
            _visualIntensity = Mathf.Clamp(value, 0.0f, 2.0f);
            UpdateMaterial();
        }
    }

    public override void _EnterTree()
    {
        MouseFilter = MouseFilterEnum.Pass;
        EnsureStyle();
        ConnectStyle();
        EnsureSurface();
        UpdateGeometry();
        UpdateMaterial();
    }

    public override void _ExitTree()
    {
        if (_styleConnected && _style is not null)
        {
            _style.Changed -= UpdateMaterial;
            _styleConnected = false;
        }
    }

    public override void _Notification(int what)
    {
        if (what == NotificationResized || what == NotificationTransformChanged || what == NotificationThemeChanged)
        {
            UpdateGeometry();
            UpdateMaterial();
        }
        else if (what == NotificationAccessibilityUpdate)
        {
            UpdateAccessibility();
        }
    }

    private void EnsureStyle()
    {
        if (_style is not null)
        {
            return;
        }
        _style = new LiquidGlassStyle();
        _style.ApplyPreset(_preset);
    }

    private void ConnectStyle()
    {
        if (_styleConnected || _style is null || !IsInsideTree())
        {
            return;
        }
        _style.Changed += UpdateMaterial;
        _styleConnected = true;
    }

    private void EnsureSurface()
    {
        if (_backBuffer is null)
        {
            _backBuffer = new BackBufferCopy
            {
                Name = "_LiquidGlassBackBuffer",
                CopyMode = BackBufferCopy.CopyModeEnum.Rect,
            };
            AddChild(_backBuffer, false, InternalMode.Back);
        }
        if (_surface is null)
        {
            _surface = new ColorRect
            {
                Name = "_LiquidGlassSurface",
                Color = Colors.White,
                MouseFilter = MouseFilterEnum.Ignore,
                ShowBehindParent = true,
            };
            AddChild(_surface, false, InternalMode.Back);
        }
        if (_material is null)
        {
            var shader = ResourceLoader.Load<Shader>(ShaderPath);
            if (shader is null)
            {
                GD.PushError($"[Liquid Glass] Shader not found: {ShaderPath}");
                return;
            }
            _material = new ShaderMaterial { Shader = shader };
            _surface.Material = _material;
        }
    }

    private void UpdateGeometry()
    {
        if (_backBuffer is not null)
        {
            _backBuffer.Rect = new Rect2(Vector2.Zero, Size);
        }
        if (_surface is not null)
        {
            _surface.Position = Vector2.Zero;
            _surface.Size = Size;
        }
    }

    private void UpdateMaterial()
    {
        EnsureStyle();
        EnsureSurface();
        if (_material is null || _style is null)
        {
            return;
        }
        _material.SetShaderParameter("panel_size", new Vector2(Mathf.Max(Size.X, 1.0f), Mathf.Max(Size.Y, 1.0f)));
        _material.SetShaderParameter("shape_mode", (int)_style.Shape);
        _material.SetShaderParameter("corner_radius", _style.CornerRadius);
        _material.SetShaderParameter("superellipse_exponent", _style.SuperellipseExponent);
        _material.SetShaderParameter("edge_softness", _style.EdgeSoftness);
        _material.SetShaderParameter("blur_lod", _style.BlurLod);
        _material.SetShaderParameter("refraction", _style.Refraction);
        _material.SetShaderParameter("dispersion", _style.Dispersion);
        _material.SetShaderParameter("tint", _style.Tint);
        _material.SetShaderParameter("tint_strength", _style.TintStrength);
        _material.SetShaderParameter("saturation", _style.Saturation);
        _material.SetShaderParameter("rim_strength", _style.RimStrength);
        _material.SetShaderParameter("inner_shadow", _style.InnerShadow);
        _material.SetShaderParameter("noise_strength", _style.NoiseStrength);
        _material.SetShaderParameter("visual_intensity", _visualIntensity);
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
        server.UpdateSetRole(element, AccessibilityServer.AccessibilityRole.Panel);
        server.UpdateSetName(element, AccessibilityName);
    }
}

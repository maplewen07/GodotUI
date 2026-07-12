using System.Collections.Generic;
using Godot;
using GodotUi.Manifest;

namespace GodotUi.Generated.LiquidGlass;

[Tool]
public partial class LiquidGlassWidget
{
    private Label _statusLabel = null!;
    private Label _intensityLabel = null!;
    private Control _intensitySlider = null!;
    private Control _actionButton = null!;

    public override string PackageId => "ui.liquid_glass";
    public override ManifestControllerScope ControllerScope => ManifestControllerScope.Instance;

    protected override ManifestControllerBase CreateController()
    {
        return new global::GodotUi.Sample.LiquidGlass.LiquidGlassController();
    }

    protected override void BindNodes()
    {
        _statusLabel = GetNode<Label>("StatusLabel");
        _intensityLabel = GetNode<Label>("IntensityLabel");
        _intensitySlider = GetNode<Control>("IntensitySlider");
        _actionButton = GetNode<Control>("ActionButton");
        _actionButton.Connect(new StringName("Pressed"), new Callable(this, nameof(OnApplyGlassPressed)));
        _intensitySlider.Connect(new StringName("ValueChanged"), new Callable(this, nameof(OnInput0IntensityChanged)));
    }

    protected override void UnbindNodes()
    {
        _actionButton.Disconnect(new StringName("Pressed"), new Callable(this, nameof(OnApplyGlassPressed)));
        _intensitySlider.Disconnect(new StringName("ValueChanged"), new Callable(this, nameof(OnInput0IntensityChanged)));
    }

    protected override ManifestBindingSet GetBindingSet()
    {
        return new ManifestBindingSet(
            new ManifestPropertyBinding[]
            {
                new ManifestPropertyBinding("StatusLabel", "text", "status", "", "", "Use mouse, keyboard, or controller UI actions"),
                new ManifestPropertyBinding("IntensityLabel", "text", "intensity", "number", "{0:0.00}", 0.45),
            },
            new ManifestAssetCatalog(
                new ManifestAssetRef[]
                {
                    new ManifestAssetRef("liquid_glass_background", "texture", "res://ui/liquid_glass/assets/liquid_glass_background.svg"),
                    new ManifestAssetRef("frosted_superellipse_style", "resource", "res://ui/liquid_glass/assets/frosted_superellipse_style_resource.tres"),
                    new ManifestAssetRef("vibrant_rounded_style", "resource", "res://ui/liquid_glass/assets/vibrant_rounded_style_resource.tres"),
                },
                ""),
            new ManifestRepeaterBinding[]
            {
            },
            new ManifestInputBinding[]
            {
                new ManifestInputBinding("IntensitySlider", "value", "intensity"),
            },
            ManifestUiUpdatePolicy.Immediate,
            new ManifestLocalizedPropertyBinding[]
            {
            });
    }

    private void OnApplyGlassPressed()
    {
        DispatchUiEvent("apply_glass", "");
        ManifestMessageBus.Instance?.Publish(
            "liquid_glass.apply",
            "apply_glass",
            default,
            ManifestMessageScope.Package,
            "liquid_glass",
            PackageId,
            ManifestMessageDelivery.Immediate);
    }

    private void OnInput0IntensityChanged(double value)
    {
        SetInputValue("intensity", value);
    }
}

using System;
using Godot;
using GodotUi.Generated.LiquidGlass;
using GodotUi.Manifest;

namespace GodotUi.Demo;

public partial class Main : Node
{
    public override async void _Ready()
    {
        try
        {
            var manager = ManifestUiManager.Instance
                ?? throw new InvalidOperationException("ManifestUiManager autoload is not available.");

            LiquidGlassWidgetManifestCatalog.Register(manager, replace: true);
            await manager.OpenAsync(
                "ui.liquid_glass",
                new ManifestUiOpenOptions
                {
                    LayerId = "Main",
                    Mode = ManifestUiOpenMode.Reuse,
                    GrabFocus = true,
                });
        }
        catch (Exception exception)
        {
            GD.PushError(exception.ToString());
        }
    }
}

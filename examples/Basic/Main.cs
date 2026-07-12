using System;
using Godot;
using GodotUi.Examples.Basic.Generated;
using GodotUi.Manifest;

namespace GodotUi.Examples.Basic;

public partial class Main : Control
{
    public override async void _Ready()
    {
        try
        {
            var manager = GetNodeOrNull<global::ManifestUiManager>("/root/ManifestUiManager")
                ?? throw new InvalidOperationException("ManifestUiManager autoload is not available.");

            BasicWidgetManifestCatalog.Register(manager, replace: true);
            var handle = await manager.OpenAsync(
                "example.basic",
                new ManifestUiOpenOptions
                {
                    LayerId = "Main",
                    Mode = ManifestUiOpenMode.Reuse,
                    GrabFocus = true,
                });
            if (OS.GetEnvironment("MANIFEST_UI_EXAMPLE_SMOKE") == "1")
            {
                if (handle.State != ManifestUiState.Open)
                {
                    throw new InvalidOperationException("Basic example did not reach the Open state.");
                }
                await manager.CloseAsync(handle, ManifestUiCloseReason.Programmatic);
                await manager.ReleaseAsync("example.basic", closeInstances: true);
                GD.Print("Manifest UI Basic example smoke OK.");
                GetTree().Quit(0);
            }
        }
        catch (Exception exception)
        {
            GD.PushError(exception.ToString());
        }
    }
}

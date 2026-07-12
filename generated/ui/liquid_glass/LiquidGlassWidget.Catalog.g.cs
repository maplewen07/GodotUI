namespace GodotUi.Generated.LiquidGlass;

public static class LiquidGlassWidgetManifestCatalog
{
    public static global::GodotUi.Manifest.ManifestUiCatalogEntry CreateEntry()
    {
        return new global::GodotUi.Manifest.ManifestUiCatalogEntry(
            "ui.liquid_glass",
            "res://generated/ui/liquid_glass/LiquidGlassWidget.tscn",
            () => new global::GodotUi.Sample.LiquidGlass.LiquidGlassController(),
            global::GodotUi.Manifest.ManifestControllerScope.Instance,
            "",
            new string[]
            {
            },
            new global::GodotUi.Manifest.ManifestUiRoute[]
            {
            });
    }

    public static void Register(global::GodotUi.Manifest.ManifestUiManager manager, bool replace = false)
    {
        manager.RegisterCatalogEntry(CreateEntry(), replace);
    }
}

namespace GodotUi.Generated.Badge;

public static class BadgeWidgetManifestCatalog
{
    public static global::GodotUi.Manifest.ManifestUiCatalogEntry CreateEntry()
    {
        return new global::GodotUi.Manifest.ManifestUiCatalogEntry(
            "ui.badge",
            "res://generated/ui/badge/BadgeWidget.tscn",
            () => new global::GodotUi.Sample.Badge.BadgeController(),
            global::GodotUi.Manifest.ManifestControllerScope.Package,
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

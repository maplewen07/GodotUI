namespace GodotUi.Generated.Phone;

public static class PhoneWidgetManifestCatalog
{
    public static global::GodotUi.Manifest.ManifestUiCatalogEntry CreateEntry()
    {
        return new global::GodotUi.Manifest.ManifestUiCatalogEntry(
            "ui.phone",
            "res://generated/ui/phone/PhoneWidget.tscn",
            () => new global::GodotUi.Sample.Phone.PhoneController(),
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

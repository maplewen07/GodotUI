namespace GodotUi.Examples.Basic.Generated;

public static class BasicWidgetManifestCatalog
{
    public static global::GodotUi.Manifest.ManifestUiCatalogEntry CreateEntry()
    {
        return new global::GodotUi.Manifest.ManifestUiCatalogEntry(
            "example.basic",
            "res://generated/ui/basic/BasicWidget.tscn",
            () => new global::GodotUi.Examples.Basic.BasicController(),
            global::GodotUi.Manifest.ManifestControllerScope.Instance,
            "example.basic",
            new string[]
            {
                "res://generated/ui/basic/translations/basic.en.tres",
                "res://generated/ui/basic/translations/basic.zh_CN.tres",
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

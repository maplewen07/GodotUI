namespace GodotUi.Examples.Inventory.Generated;

public static class InventoryWidgetManifestCatalog
{
    public static global::GodotUi.Manifest.ManifestUiCatalogEntry CreateEntry()
    {
        return new global::GodotUi.Manifest.ManifestUiCatalogEntry(
            "example.inventory",
            "res://generated/ui/inventory/InventoryWidget.tscn",
            () => new global::GodotUi.Examples.Inventory.InventoryController(),
            global::GodotUi.Manifest.ManifestControllerScope.Instance,
            "example.inventory",
            new string[]
            {
                "res://generated/ui/inventory/translations/inventory.en.tres",
                "res://generated/ui/inventory/translations/inventory.zh_CN.tres",
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

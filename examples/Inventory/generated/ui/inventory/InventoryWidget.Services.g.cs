namespace GodotUi.Examples.Inventory;

public partial class InventoryController
{
    protected global::GodotUi.Examples.Inventory.IInventoryService InventoryService => Context.RequireService<global::GodotUi.Examples.Inventory.IInventoryService>("demo");
}

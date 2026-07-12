using System.Collections.Generic;

namespace GodotUi.Examples.Inventory;

public interface IInventoryService
{
    IReadOnlyList<InventoryItem> LoadItems();
}

public sealed record InventoryItem(string Sku, string Name, int Quantity);

public sealed class DemoInventoryService : IInventoryService
{
    private static readonly IReadOnlyList<InventoryItem> Items = new[]
    {
        new InventoryItem("CMP-001", "Copper wire", 12),
        new InventoryItem("OPT-014", "Optical lens", 4),
        new InventoryItem("PWR-120", "Power cell", 8),
        new InventoryItem("SNS-204", "Motion sensor", 3),
        new InventoryItem("TLS-031", "Repair tool", 2),
    };

    public IReadOnlyList<InventoryItem> LoadItems()
    {
        return Items;
    }
}

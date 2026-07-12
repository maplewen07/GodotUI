using System;
using System.Collections.Generic;
using System.Linq;
using GodotUi.Manifest;

namespace GodotUi.Examples.Inventory;

public partial class InventoryController : ManifestControllerBase
{
    private IReadOnlyList<InventoryItem> _allItems = Array.Empty<InventoryItem>();

    protected override void OnSetup()
    {
        Reload();
    }

    public override void DispatchEvent(string eventId)
    {
        if (string.Equals(eventId, "refresh_inventory", StringComparison.Ordinal))
        {
            Reload();
        }
    }

    protected override void OnInputChanged(string fieldId, object? value, ManifestGeneratedWidget widget)
    {
        if (string.Equals(fieldId, "filter", StringComparison.Ordinal))
        {
            ApplyFilter(value?.ToString() ?? "");
        }
    }

    private void Reload()
    {
        _allItems = InventoryService.LoadItems();
        ApplyFilter(Store.Get<string>("filter", "") ?? "");
    }

    private void ApplyFilter(string filter)
    {
        var normalized = filter.Trim();
        var visible = string.IsNullOrEmpty(normalized)
            ? _allItems.ToArray()
            : _allItems
                .Where(item => item.Name.Contains(normalized, StringComparison.OrdinalIgnoreCase)
                    || item.Sku.Contains(normalized, StringComparison.OrdinalIgnoreCase))
                .ToArray();

        using (Store.BeginBatch())
        {
            Store.Set("filter", filter);
            Store.Set("items", visible);
            Store.Set("hasItems", visible.Length > 0);
            Store.Set("usedCapacity", visible.Sum(item => item.Quantity));
            Store.Set("summary", $"{visible.Length} item type(s), {visible.Sum(item => item.Quantity)} unit(s)");
        }
    }
}

using System.Collections.Generic;
using Godot;
using GodotUi.Manifest;

namespace GodotUi.Examples.Inventory.Generated;

[Tool]
public partial class InventoryWidget
{
    private LineEdit _filterInput = null!;
    private Label _summaryLabel = null!;
    private ProgressBar _capacityBar = null!;
    private Label _emptyState = null!;
    private ScrollContainer _scroll = null!;
    private VBoxContainer _rows = null!;
    private HBoxContainer _rowTemplate = null!;
    private Button _refreshButton = null!;

    public override string PackageId => "example.inventory";
    public override ManifestControllerScope ControllerScope => ManifestControllerScope.Instance;
    public override string TranslationDomain => "example.inventory";

    protected override ManifestControllerBase CreateController()
    {
        return new global::GodotUi.Examples.Inventory.InventoryController();
    }

    protected override void BindNodes()
    {
        _filterInput = GetNode<LineEdit>("Card/Content/Toolbar/FilterInput");
        _summaryLabel = GetNode<Label>("Card/Content/SummaryLabel");
        _capacityBar = GetNode<ProgressBar>("Card/Content/CapacityBar");
        _emptyState = GetNode<Label>("Card/Content/EmptyState");
        _scroll = GetNode<ScrollContainer>("Card/Content/Scroll");
        _rows = GetNode<VBoxContainer>("Card/Content/Scroll/Rows");
        _rowTemplate = GetNode<HBoxContainer>("Card/Content/Scroll/Rows/RowTemplate");
        _refreshButton = GetNode<Button>("Card/Content/Toolbar/RefreshButton");
        _refreshButton.Connect(new StringName("pressed"), new Callable(this, nameof(OnRefreshInventoryPressed)));
        _filterInput.Connect(new StringName("text_changed"), new Callable(this, nameof(OnInput0FilterChanged)));
    }

    protected override void UnbindNodes()
    {
        _refreshButton.Disconnect(new StringName("pressed"), new Callable(this, nameof(OnRefreshInventoryPressed)));
        _filterInput.Disconnect(new StringName("text_changed"), new Callable(this, nameof(OnInput0FilterChanged)));
    }

    protected override ManifestBindingSet GetBindingSet()
    {
        return new ManifestBindingSet(
            new ManifestPropertyBinding[]
            {
                new ManifestPropertyBinding("Card/Content/Toolbar/FilterInput", "text", "filter", "", "", ""),
                new ManifestPropertyBinding("Card/Content/SummaryLabel", "text", "summary", "", "", "Loading inventory..."),
                new ManifestPropertyBinding("Card/Content/CapacityBar", "value", "usedCapacity", "number", "", 0),
                new ManifestPropertyBinding("Card/Content/EmptyState", "visible", "hasItems", "not", "", false),
                new ManifestPropertyBinding("Card/Content/Scroll", "visible", "hasItems", "", "", false),
            },
            new ManifestAssetCatalog(
                new ManifestAssetRef[]
                {
                },
                ""),
            new ManifestRepeaterBinding[]
            {
                new ManifestRepeaterBinding("Card/Content/Scroll/Rows", "Card/Content/Scroll/Rows/RowTemplate", "items", new ManifestItemBinding[]
                {
                    new ManifestItemBinding("SkuLabel", "text", "sku", "", "", null),
                    new ManifestItemBinding("NameLabel", "text", "name", "", "", null),
                    new ManifestItemBinding("QuantityLabel", "text", "quantity", "number", "x{0}", 0),
                }, "sku", 16),
            },
            new ManifestInputBinding[]
            {
                new ManifestInputBinding("Card/Content/Toolbar/FilterInput", "text", "filter"),
            },
            ManifestUiUpdatePolicy.Deferred,
            new ManifestLocalizedPropertyBinding[]
            {
                new ManifestLocalizedPropertyBinding("Card/Content/TitleLabel", "text", "inventory.title"),
                new ManifestLocalizedPropertyBinding("Card/Content/Toolbar/RefreshButton", "text", "inventory.refresh"),
                new ManifestLocalizedPropertyBinding("Card/Content/EmptyState", "text", "inventory.empty"),
            });
    }

    private void OnRefreshInventoryPressed()
    {
        DispatchUiEvent("refresh_inventory", "");
        ManifestMessageBus.Instance?.Publish(
            "inventory.refresh",
            "refresh_inventory",
            default,
            ManifestMessageScope.Package,
            "inventory",
            PackageId,
            ManifestMessageDelivery.Immediate);
    }

    private void OnInput0FilterChanged(string value)
    {
        SetInputValue("filter", value);
    }
}

using System.Collections.Generic;
using Godot;
using GodotUi.Manifest;

namespace GodotUi.Generated.Phone;

[Tool]
public partial class PhoneWidget
{
    private Panel _panel = null!;
    private TextureRect _iconTexture = null!;
    private Label _titleLabel = null!;
    private Label _statusLabel = null!;
    private LineEdit _searchInput = null!;
    private Label _countLabel = null!;
    private ProgressBar _batteryBar = null!;
    private Label _detailsLabel = null!;
    private Button _contactsButton = null!;
    private VBoxContainer _contactsList = null!;
    private HBoxContainer _contactItemTemplate = null!;
    private TabContainer _tabs = null!;

    public override string PackageId => "ui.phone";
    public override ManifestControllerScope ControllerScope => ManifestControllerScope.Package;

    protected override ManifestControllerBase CreateController()
    {
        return new global::GodotUi.Sample.Phone.PhoneController();
    }

    protected override void BindNodes()
    {
        _panel = GetNode<Panel>("Panel");
        _iconTexture = GetNode<TextureRect>("Panel/Content/IconTexture");
        _titleLabel = GetNode<Label>("Panel/Content/TitleLabel");
        _statusLabel = GetNode<Label>("Panel/Content/StatusLabel");
        _searchInput = GetNode<LineEdit>("Panel/Content/SearchInput");
        _countLabel = GetNode<Label>("Panel/Content/CountLabel");
        _batteryBar = GetNode<ProgressBar>("Panel/Content/BatteryBar");
        _detailsLabel = GetNode<Label>("Panel/Content/DetailsLabel");
        _contactsButton = GetNode<Button>("Panel/Content/ContactsButton");
        _contactsList = GetNode<VBoxContainer>("Panel/Content/Tabs/ContactsTab/ContactsList");
        _contactItemTemplate = GetNode<HBoxContainer>("Panel/Content/Tabs/ContactsTab/ContactsList/ContactItemTemplate");
        _tabs = GetNode<TabContainer>("Panel/Content/Tabs");
        _contactsButton.Connect(new StringName("pressed"), new Callable(this, nameof(OnOpenContactsPressed)));
        _tabs.Connect(new StringName("tab_changed"), new Callable(this, nameof(OnSwitchTabTabChanged)));
        _searchInput.Connect(new StringName("text_changed"), new Callable(this, nameof(OnInput0SearchTextChanged)));
    }

    protected override void UnbindNodes()
    {
        _contactsButton.Disconnect(new StringName("pressed"), new Callable(this, nameof(OnOpenContactsPressed)));
        _tabs.Disconnect(new StringName("tab_changed"), new Callable(this, nameof(OnSwitchTabTabChanged)));
        _searchInput.Disconnect(new StringName("text_changed"), new Callable(this, nameof(OnInput0SearchTextChanged)));
    }

    protected override ManifestBindingSet GetBindingSet()
    {
        return new ManifestBindingSet(
            new ManifestPropertyBinding[]
            {
                new ManifestPropertyBinding("Panel", "themeClass", "panelTheme", "", "", null),
                new ManifestPropertyBinding("Panel/Content/IconTexture", "texture", "icon", "", "", "phone_icon"),
                new ManifestPropertyBinding("Panel/Content/TitleLabel", "text", "title", "", "", null),
                new ManifestPropertyBinding("Panel/Content/StatusLabel", "text", "status", "", "", null),
                new ManifestPropertyBinding("Panel/Content/SearchInput", "text", "searchText", "", "", null),
                new ManifestPropertyBinding("Panel/Content/CountLabel", "text", "contactCount", "number", "Contacts opened {0} time(s)", null),
                new ManifestPropertyBinding("Panel/Content/BatteryBar", "value", "battery", "number", "", null),
                new ManifestPropertyBinding("Panel/Content/DetailsLabel", "visibility", "showDetails", "", "", null),
                new ManifestPropertyBinding("Panel/Content/ContactsButton", "enabled", "contactsEnabled", "", "", null),
            },
            new ManifestAssetCatalog(
                new ManifestAssetRef[]
                {
                    new ManifestAssetRef("phone_icon", "texture", "res://ui/phone/assets/phone_icon.tres"),
                    new ManifestAssetRef("phone_font", "font", "res://ui/phone/assets/phone_font.tres"),
                    new ManifestAssetRef("phone_theme", "theme", "res://generated/ui/phone/assets/PhoneTheme.tres"),
                },
                "res://generated/ui/phone/assets/PhoneTheme.tres"),
            new ManifestRepeaterBinding[]
            {
                new ManifestRepeaterBinding("Panel/Content/Tabs/ContactsTab/ContactsList", "Panel/Content/Tabs/ContactsTab/ContactsList/ContactItemTemplate", "contacts", new ManifestItemBinding[]
                {
                    new ManifestItemBinding("NameLabel", "text", "name", "", "", null),
                    new ManifestItemBinding("PhoneLabel", "text", "phone", "", "", null),
                }, "", 32),
            },
            new ManifestInputBinding[]
            {
                new ManifestInputBinding("Panel/Content/SearchInput", "text", "searchText"),
            },
            ManifestUiUpdatePolicy.Manual,
            new ManifestLocalizedPropertyBinding[]
            {
            });
    }

    private void OnOpenContactsPressed()
    {
        DispatchUiEvent("open_contacts", "");
        ManifestMessageBus.Instance?.Publish(
            "phone.open_contacts",
            "open_contacts",
            default,
            ManifestMessageScope.Package,
            "phone",
            PackageId,
            ManifestMessageDelivery.Immediate);
    }

    private void OnSwitchTabTabChanged(long value)
    {
        DispatchUiEvent("switch_tab", "");
        ManifestMessageBus.Instance?.Publish(
            "phone.tab_changed",
            "switch_tab",
            default,
            ManifestMessageScope.Package,
            "phone",
            PackageId,
            ManifestMessageDelivery.Immediate);
    }

    private void OnInput0SearchTextChanged(string value)
    {
        SetInputValue("searchText", value);
    }
}

using System.Collections.Generic;
using GodotUi.Manifest;

namespace GodotUi.Sample.Phone;

public sealed class PhoneController : ManifestControllerBase
{
    private readonly PhoneModel _model = new();

    protected override void OnWidgetOpened(ManifestGeneratedWidget widget)
    {
        Store.Set("title", "Phone");
        Store.Set("status", "Ready");
        Store.Set("searchText", "");
        Store.Set("contactCount", _model.ContactOpenCount);
        Store.Set("battery", 7.0);
        Store.Set("showDetails", false);
        Store.Set("contactsEnabled", true);
        Store.Set("contacts", new List<Dictionary<string, object?>>
        {
            new() { ["name"] = "Ada", ["phone"] = "1001" },
            new() { ["name"] = "Grace", ["phone"] = "1002" },
        });
        Store.Set("icon", "phone_icon");
        Store.Set("panelTheme", "PhonePanel");
        Flush();
    }

    public override void DispatchEvent(string eventId)
    {
        if (eventId == "switch_tab")
        {
            Store.Set("status", "Tab changed");
            Flush();
            return;
        }

        if (eventId != "open_contacts")
        {
            return;
        }

        _model.ContactOpenCount++;
        OpenModal("phone_modal", "res://generated/ui/badge/BadgeWidget.tscn");
        Store.Set("status", $"Contacts opened {_model.ContactOpenCount} time(s)");
        Store.Set("contactCount", _model.ContactOpenCount);
        Store.Set("battery", 7.0 + _model.ContactOpenCount);
        Store.Set("showDetails", true);
        Store.Set("contacts", new List<Dictionary<string, object?>>
        {
            new() { ["name"] = "Ada", ["phone"] = "1001" },
            new() { ["name"] = "Grace", ["phone"] = "1002" },
            new() { ["name"] = "Linus", ["phone"] = "1003" },
        });
        Flush();
    }

    protected override void OnInputChanged(string fieldId, object? value, ManifestGeneratedWidget widget)
    {
        if (fieldId != "searchText")
        {
            return;
        }

        Store.Set("status", $"Search: {value}");
        Flush();
    }
}

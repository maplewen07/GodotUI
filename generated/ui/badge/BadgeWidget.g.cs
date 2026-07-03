using System.Collections.Generic;
using Godot;
using GodotUi.Manifest;

namespace GodotUi.Generated.Badge;

public partial class BadgeWidget
{
    private Label _badgeLabel = null!;

    public override string PackageId => "ui.badge";

    protected override ManifestControllerBase CreateController()
    {
        return new global::GodotUi.Sample.Badge.BadgeController();
    }

    protected override void BindNodes()
    {
        _badgeLabel = GetNode<Label>("BadgeLabel");
    }

    protected override ManifestBindingSet GetBindingSet()
    {
        return new ManifestBindingSet(
            new ManifestPropertyBinding[]
            {
                new ManifestPropertyBinding("BadgeLabel", "text", "badgeText", "", "", null),
            },
            new ManifestAssetCatalog(
                new ManifestAssetRef[]
                {
                },
                ""),
            new ManifestRepeaterBinding[]
            {
            },
            new ManifestInputBinding[]
            {
            });
    }
}

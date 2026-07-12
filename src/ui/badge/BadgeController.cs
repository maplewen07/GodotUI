using GodotUi.Manifest;

namespace GodotUi.Sample.Badge;

public sealed class BadgeController : ManifestControllerBase
{
    protected override void OnWidgetOpened(ManifestGeneratedWidget widget)
    {
        Store.Set("badgeText", "Nested badge");
        Flush();
    }
}

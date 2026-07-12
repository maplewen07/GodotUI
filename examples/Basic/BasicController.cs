using System;
using GodotUi.Manifest;

namespace GodotUi.Examples.Basic;

public sealed class BasicController : ManifestControllerBase
{
    protected override void OnSetup()
    {
        using (Store.BeginBatch())
        {
            Store.Set("name", "Maple");
            Store.Set("greeting", "Ready to greet someone.");
            Store.Set("clickCount", 0);
        }
    }

    public override void DispatchEvent(string eventId)
    {
        if (!string.Equals(eventId, "say_hello", StringComparison.Ordinal))
        {
            return;
        }

        var count = Convert.ToInt32(Store.Get("clickCount") ?? 0) + 1;
        var name = Store.Get<string>("name", "")?.Trim();
        using (Store.BeginBatch())
        {
            Store.Set("clickCount", count);
            Store.Set("greeting", BuildGreeting(name));
        }
    }

    protected override void OnInputChanged(string fieldId, object? value, ManifestGeneratedWidget widget)
    {
        if (string.Equals(fieldId, "name", StringComparison.Ordinal))
        {
            Store.Set("greeting", BuildGreeting(value?.ToString()));
        }
    }

    private static string BuildGreeting(string? name)
    {
        return string.IsNullOrWhiteSpace(name)
            ? "Enter a name, then send a greeting."
            : $"Hello, {name.Trim()}!";
    }
}

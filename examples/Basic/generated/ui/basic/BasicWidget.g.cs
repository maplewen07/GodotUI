using System.Collections.Generic;
using Godot;
using GodotUi.Manifest;

namespace GodotUi.Examples.Basic.Generated;

[Tool]
public partial class BasicWidget
{
    private LineEdit _nameInput = null!;
    private Label _greetingLabel = null!;
    private Label _countLabel = null!;
    private Button _greetButton = null!;

    public override string PackageId => "example.basic";
    public override ManifestControllerScope ControllerScope => ManifestControllerScope.Instance;
    public override string TranslationDomain => "example.basic";

    protected override ManifestControllerBase CreateController()
    {
        return new global::GodotUi.Examples.Basic.BasicController();
    }

    protected override void BindNodes()
    {
        _nameInput = GetNode<LineEdit>("Card/Content/NameInput");
        _greetingLabel = GetNode<Label>("Card/Content/GreetingLabel");
        _countLabel = GetNode<Label>("Card/Content/CountLabel");
        _greetButton = GetNode<Button>("Card/Content/GreetButton");
        _greetButton.Connect(new StringName("pressed"), new Callable(this, nameof(OnSayHelloPressed)));
        _nameInput.Connect(new StringName("text_changed"), new Callable(this, nameof(OnInput0NameChanged)));
    }

    protected override void UnbindNodes()
    {
        _greetButton.Disconnect(new StringName("pressed"), new Callable(this, nameof(OnSayHelloPressed)));
        _nameInput.Disconnect(new StringName("text_changed"), new Callable(this, nameof(OnInput0NameChanged)));
    }

    protected override ManifestBindingSet GetBindingSet()
    {
        return new ManifestBindingSet(
            new ManifestPropertyBinding[]
            {
                new ManifestPropertyBinding("Card/Content/NameInput", "text", "name", "", "", "Maple"),
                new ManifestPropertyBinding("Card/Content/GreetingLabel", "text", "greeting", "", "", "Ready to greet someone."),
                new ManifestPropertyBinding("Card/Content/CountLabel", "text", "clickCount", "number", "Greetings sent: {0}", 0),
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
                new ManifestInputBinding("Card/Content/NameInput", "text", "name"),
            },
            ManifestUiUpdatePolicy.Immediate,
            new ManifestLocalizedPropertyBinding[]
            {
                new ManifestLocalizedPropertyBinding("Card/Content/TitleLabel", "text", "basic.title"),
                new ManifestLocalizedPropertyBinding("Card/Content/HintLabel", "text", "basic.hint"),
                new ManifestLocalizedPropertyBinding("Card/Content/GreetButton", "text", "basic.greet"),
            });
    }

    private void OnSayHelloPressed()
    {
        DispatchUiEvent("say_hello", "");
        ManifestMessageBus.Instance?.Publish(
            "basic.say_hello",
            "say_hello",
            default,
            ManifestMessageScope.Package,
            "basic",
            PackageId,
            ManifestMessageDelivery.Immediate);
    }

    private void OnInput0NameChanged(string value)
    {
        SetInputValue("name", value);
    }
}

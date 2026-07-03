using Godot;
using GodotUi.Manifest;

namespace GodotUi.Demo;

public partial class Main : Node
{
    public override void _Ready()
    {
        ManifestUiManager.Instance?.Open("phone", "res://generated/ui/phone/PhoneWidget.tscn");
    }
}

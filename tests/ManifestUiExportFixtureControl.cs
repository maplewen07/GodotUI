using Godot;

namespace GodotUi.Tests;

public partial class ManifestUiExportFixtureControl : Control
{
    [Export] public Color AccentColor { get; set; } = Colors.White;
    [Export] public NodePath TargetPath { get; set; } = new();
    [Export] public Vector2I GridSize { get; set; }
    [Export] public Texture2D? Icon { get; set; }
}

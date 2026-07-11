#if TOOLS
using Godot;

namespace GodotUi.Manifest.Editor;

[Tool]
internal partial class ManifestUiPreviewWindow : Window
{
    private SubViewport? _viewport;

    public void Open(string scenePath, Vector2I designResolution)
    {
        GD.Print($"[Manifest UI] [PreviewWindow] Opening {scenePath} at {designResolution.X}x{designResolution.Y}.");
        Title = $"Manifest UI Preview - {scenePath.GetFile()}";
        Size = FitWindow(designResolution);
        MinSize = new Vector2I(480, 320);
        Connect(Window.SignalName.CloseRequested, new Callable(this, nameof(OnCloseRequested)));

        var container = new SubViewportContainer
        {
            Stretch = true,
            SizeFlagsHorizontal = Control.SizeFlags.ExpandFill,
            SizeFlagsVertical = Control.SizeFlags.ExpandFill,
        };
        AddChild(container);
        container.SetAnchorsAndOffsetsPreset(Control.LayoutPreset.FullRect);

        _viewport = new SubViewport
        {
            Size = designResolution,
            TransparentBg = false,
            RenderTargetUpdateMode = SubViewport.UpdateMode.Always,
            GuiDisableInput = false,
        };
        container.AddChild(_viewport);

        var background = new ColorRect
        {
            Color = new Color("20242b"),
            MouseFilter = Control.MouseFilterEnum.Ignore,
        };
        background.SetAnchorsAndOffsetsPreset(Control.LayoutPreset.FullRect);
        _viewport.AddChild(background);

        var scene = ResourceLoader.Load<PackedScene>(scenePath);
        if (scene is null)
        {
            GD.Print($"[Manifest UI] [PreviewWindow] ResourceLoader returned null for {scenePath}.");
            AddError($"Could not load {scenePath}.");
            PopupCentered();
            return;
        }
        var instance = scene.Instantiate();
        if (instance is not Control control)
        {
            GD.Print($"[Manifest UI] [PreviewWindow] Root is {instance.GetType().FullName}, expected Control.");
            instance.QueueFree();
            AddError("Generated scene root is not a Control.");
            PopupCentered();
            return;
        }
        control.SetMeta("manifest_ui_preview", true);
        _viewport.AddChild(control);
        control.SetAnchorsAndOffsetsPreset(Control.LayoutPreset.FullRect);
        PopupCentered();
        GD.Print($"[Manifest UI] [PreviewWindow] Preview displayed for {scenePath}.");
    }

    private void OnCloseRequested()
    {
        QueueFree();
    }

    private void AddError(string message)
    {
        var label = new Label
        {
            Text = message,
            HorizontalAlignment = HorizontalAlignment.Center,
            VerticalAlignment = VerticalAlignment.Center,
            AutowrapMode = TextServer.AutowrapMode.WordSmart,
        };
        label.SetAnchorsAndOffsetsPreset(Control.LayoutPreset.FullRect);
        _viewport?.AddChild(label);
    }

    private static Vector2I FitWindow(Vector2I designResolution)
    {
        const int maxWidth = 1100;
        const int maxHeight = 760;
        var scale = Mathf.Min(1.0f, Mathf.Min((float)maxWidth / designResolution.X, (float)maxHeight / designResolution.Y));
        return new Vector2I(Mathf.Max(480, Mathf.RoundToInt(designResolution.X * scale)), Mathf.Max(320, Mathf.RoundToInt(designResolution.Y * scale)));
    }
}
#endif

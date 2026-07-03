using Godot;

namespace GodotUi.Manifest;

public abstract partial class ManifestGeneratedWidget : Control
{
    private readonly ViewModelStore _fallbackStore = new();
    private ManifestControllerBase? _controller;
    private bool _ownsController;

    public ViewModelStore Store => _controller?.Store ?? _fallbackStore;

    public override void _Ready()
    {
        BindNodes();
        ApplyGeneratedTheme();

        var manager = ManifestUiManager.Instance;
        if (manager is null)
        {
            _controller = CreateController();
            _controller.Setup(null, PackageId);
            _ownsController = true;
        }
        else
        {
            _controller = manager.GetOrCreateController(PackageId, CreateController);
        }

        _controller.AttachWidget(this);
    }

    public override void _ExitTree()
    {
        var controller = _controller;
        _controller = null;

        controller?.DetachWidget(this);
        if (_ownsController)
        {
            controller?.Dispose();
            _ownsController = false;
        }

        ManifestUiManager.Instance?.NotifyWidgetExited(this);
    }

    public void FlushViewModel()
    {
        if (GetBindingSet() is { } bindingSet)
        {
            ManifestBindingApplier.Apply(this, Store, bindingSet);
        }
        ApplyBindings(Store);
        Store.ClearDirty();
    }

    private void ApplyGeneratedTheme()
    {
        var themePath = GetBindingSet()?.Assets.ThemePath ?? "";
        if (!string.IsNullOrWhiteSpace(themePath))
        {
            Theme = ResourceLoader.Load<Theme>(themePath);
        }
    }

    protected void DispatchUiEvent(string eventId, string channel = "")
    {
        _controller?.DispatchEvent(eventId);

        if (!string.IsNullOrWhiteSpace(channel))
        {
            ManifestMessageBus.Instance?.Publish(channel, eventId);
        }
    }

    protected void SetInputValue(string fieldId, object? value)
    {
        Store.Set(fieldId, value);
        if (_controller is not null)
        {
            _controller.HandleInputChanged(fieldId, value, this);
        }
    }

    public abstract string PackageId { get; }
    protected abstract ManifestControllerBase CreateController();
    protected abstract void BindNodes();
    protected virtual ManifestBindingSet? GetBindingSet()
    {
        return null;
    }

    protected virtual void ApplyBindings(ViewModelStore store)
    {
    }
}

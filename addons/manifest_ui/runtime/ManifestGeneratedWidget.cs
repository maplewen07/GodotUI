using System;
using System.Threading;
using Godot;

namespace GodotUi.Manifest;

public abstract partial class ManifestGeneratedWidget : Control
{
    public const string EditorPreviewMeta = "manifest_ui_preview";

    private static int _previewScopeDepth;
    private readonly ViewModelStore _fallbackStore = new();
    private readonly ViewModelStoreCursor _bindingCursor = new();
    private ManifestControllerBase? _controller;
    private ManifestUiManager? _manager;
    private ManifestBindingSet? _bindingSet;
    private bool _ownsController;
    private bool _isReady;
    private bool _isPreview;
    private bool _nodesBound;
    private bool _deferredFlushPending;

    public ViewModelStore Store => _controller?.Store ?? _fallbackStore;
    public ManifestControllerBase? AttachedController => _controller;
    public bool IsEditorPreview => _isPreview;

    public virtual ManifestControllerScope ControllerScope => ManifestControllerScope.Package;
    public virtual string TranslationDomain => "";

    public static IDisposable SuppressControllersForPreview()
    {
        Interlocked.Increment(ref _previewScopeDepth);
        return new PreviewScope();
    }

    public override void _Ready()
    {
        _isPreview = Engine.IsEditorHint() || Volatile.Read(ref _previewScopeDepth) > 0 || HasPreviewMeta(this);
        BindNodes();
        _nodesBound = true;
        _bindingSet = GetBindingSet();
        ApplyGeneratedTheme();

        _manager = ManifestUiManager.Instance;
        var translationDomain = !string.IsNullOrWhiteSpace(TranslationDomain)
            ? TranslationDomain
            : _manager?.GetTranslationDomain(PackageId) ?? string.Empty;
        if (!string.IsNullOrWhiteSpace(translationDomain))
        {
            SetTranslationDomain(translationDomain);
        }

        _isReady = true;
        if (_isPreview)
        {
            FlushViewModel();
            return;
        }

        if (_manager is null)
        {
            _controller = CreateController();
            _controller.Setup(null, PackageId, ControllerScope);
            _ownsController = true;
        }
        else
        {
            _controller = _manager.AttachGeneratedWidget(this, PackageId, ControllerScope, CreateController);
        }

        Store.Changed += OnStoreChanged;
        _controller.AttachWidget(this);
        FlushViewModel();
    }

    public override void _ExitTree()
    {
        _isReady = false;
        _deferredFlushPending = false;

        if (_nodesBound)
        {
            try
            {
                UnbindNodes();
            }
            finally
            {
                _nodesBound = false;
            }
        }

        var controller = _controller;
        if (controller is not null)
        {
            controller.Store.Changed -= OnStoreChanged;
            controller.DetachWidget(this);
        }

        _controller = null;
        if (_ownsController)
        {
            controller?.Dispose();
            _ownsController = false;
        }
        else if (controller is not null)
        {
            _manager?.DetachGeneratedWidget(this, controller);
        }

        _manager?.NotifyWidgetExited(this);
        _manager = null;
    }

    public override void _Notification(int what)
    {
        if (what == NotificationTranslationChanged && _isReady)
        {
            _bindingCursor.Reset();
            FlushViewModel();
        }
    }

    public void FlushViewModel()
    {
        if (!_isReady || !GodotObject.IsInstanceValid(this))
        {
            return;
        }

        var targetRevision = Store.Revision;
        try
        {
            if (_bindingSet is not null)
            {
                ManifestBindingApplier.Apply(this, Store, _bindingSet, _bindingCursor, targetRevision);
            }

            ApplyBindings(Store);
            _bindingCursor.AdvanceTo(targetRevision);
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR4002",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Widget '{GetType().FullName}' failed to apply bindings.",
                exception,
                PackageId);
        }
    }

    internal void ResetBindingCursor()
    {
        _bindingCursor.Reset();
    }

    private void ApplyGeneratedTheme()
    {
        var themePath = _bindingSet?.Assets.ThemePath ?? "";
        if (!string.IsNullOrWhiteSpace(themePath))
        {
            Theme = ResourceLoader.Load<Theme>(themePath);
        }
    }

    protected void DispatchUiEvent(string eventId, string channel = "")
    {
        DispatchUiEvent(eventId, channel, eventId);
    }

    protected void DispatchUiEvent(
        string eventId,
        string channel,
        Variant payload,
        ManifestMessageScope scope = ManifestMessageScope.Package,
        string scopeId = "")
    {
        if (_isPreview)
        {
            return;
        }

        try
        {
            _controller?.DispatchEvent(eventId);
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR3005",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Controller '{_controller?.GetType().FullName}' failed while dispatching event '{eventId}'.",
                exception,
                PackageId);
        }
        if (!string.IsNullOrWhiteSpace(channel))
        {
            ManifestMessageBus.Instance?.Publish(
                channel,
                eventId,
                payload,
                scope,
                string.IsNullOrWhiteSpace(scopeId) ? PackageId : scopeId,
                PackageId);
        }
    }

    protected void SetInputValue(string fieldId, object? value)
    {
        if (_isPreview)
        {
            return;
        }

        Store.Set(fieldId, value);
        try
        {
            _controller?.HandleInputChanged(fieldId, value, this);
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR3006",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Controller '{_controller?.GetType().FullName}' failed while handling input '{fieldId}'.",
                exception,
                PackageId);
        }
    }

    private void OnStoreChanged(object? sender, ViewModelStoreChangedEventArgs args)
    {
        if (!_isReady || !Visible || _bindingSet is null)
        {
            return;
        }

        switch (_bindingSet.UpdatePolicy)
        {
            case ManifestUiUpdatePolicy.Immediate:
                FlushViewModel();
                break;
            case ManifestUiUpdatePolicy.Deferred when !_deferredFlushPending:
                _deferredFlushPending = true;
                Callable.From(FlushDeferred).CallDeferred();
                break;
        }
    }

    private void FlushDeferred()
    {
        _deferredFlushPending = false;
        if (_isReady && Visible)
        {
            FlushViewModel();
        }
    }

    private static bool HasPreviewMeta(Node node)
    {
        for (Node? current = node; current is not null; current = current.GetParent())
        {
            if (current.HasMeta(EditorPreviewMeta) && current.GetMeta(EditorPreviewMeta).AsBool())
            {
                return true;
            }
        }

        return false;
    }

    public abstract string PackageId { get; }
    protected abstract ManifestControllerBase CreateController();
    protected abstract void BindNodes();

    protected virtual void UnbindNodes()
    {
    }

    protected virtual ManifestBindingSet? GetBindingSet()
    {
        return null;
    }

    protected virtual void ApplyBindings(ViewModelStore store)
    {
    }

    private sealed class PreviewScope : IDisposable
    {
        private int _disposed;

        public void Dispose()
        {
            if (Interlocked.Exchange(ref _disposed, 1) == 0)
            {
                Interlocked.Decrement(ref _previewScopeDepth);
            }
        }
    }
}

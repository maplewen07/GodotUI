using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Godot;

namespace GodotUi.Manifest;

public abstract class ManifestControllerBase : IDisposable
{
    private readonly List<ManifestGeneratedWidget> _activeWidgets = new();
    private readonly List<IDisposable> _subscriptions = new();
    private bool _isSetup;
    private bool _isTornDown;

    public string PackageId { get; private set; } = "";
    public ViewModelStore Store { get; } = new();
    public int ActiveWidgetCount => _activeWidgets.Count;
    public ManifestControllerContext Context { get; private set; } = null!;

    protected ManifestGeneratedWidget? Widget => _activeWidgets.Count == 0 ? null : _activeWidgets[^1];
    protected ManifestUiManager? Manager => Context.Manager;
    protected ManifestMessageBus? MessageBus => Context.MessageBus;
    protected ManifestServiceRegistry Services => Context.Services;

    internal void Setup(
        ManifestUiManager? manager,
        string packageId,
        ManifestControllerScope scope = ManifestControllerScope.Package,
        string scopeId = "",
        ManifestServiceRegistry? services = null,
        ManifestMessageBus? messageBus = null)
    {
        if (_isSetup)
        {
            return;
        }

        PackageId = packageId;
        Context = new ManifestControllerContext(
            manager,
            packageId,
            scopeId,
            scope,
            services ?? manager?.Services ?? new ManifestServiceRegistry(),
            messageBus ?? ManifestMessageBus.Instance);
        _isSetup = true;
        OnSetup();
    }

    internal void AttachWidget(ManifestGeneratedWidget widget)
    {
        if (!_activeWidgets.Contains(widget))
        {
            _activeWidgets.Add(widget);
        }

        try
        {
            OnWidgetOpened(widget);
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR3001",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Controller '{GetType().FullName}' failed while opening a widget.",
                exception,
                PackageId);
            throw;
        }
    }

    internal void DetachWidget(ManifestGeneratedWidget widget)
    {
        if (!_activeWidgets.Remove(widget))
        {
            return;
        }

        try
        {
            OnWidgetClosed(widget);
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR3002",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Controller '{GetType().FullName}' failed while closing a widget.",
                exception,
                PackageId);
        }
    }

    public void Dispose()
    {
        Teardown();
        GC.SuppressFinalize(this);
    }

    public void Teardown()
    {
        if (_isTornDown)
        {
            return;
        }

        _isTornDown = true;
        try
        {
            OnTeardown();
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR3003",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Controller '{GetType().FullName}' failed during teardown.",
                exception,
                PackageId);
        }

        foreach (var subscription in _subscriptions.ToArray())
        {
            try
            {
                subscription.Dispose();
            }
            catch (Exception exception)
            {
                ManifestRuntimeDiagnostics.Report(
                    "MUIR3004",
                    ManifestRuntimeDiagnosticSeverity.Warning,
                    "A controller subscription failed to dispose.",
                    exception,
                    PackageId);
            }
        }

        _subscriptions.Clear();
        _activeWidgets.Clear();
    }

    public virtual void DispatchEvent(string eventId)
    {
    }

    internal void HandleInputChanged(string fieldId, object? value, ManifestGeneratedWidget widget)
    {
        OnInputChanged(fieldId, value, widget);
    }

    protected virtual void OnSetup()
    {
    }

    protected virtual void OnTeardown()
    {
    }

    protected virtual void OnWidgetOpened(ManifestGeneratedWidget widget)
    {
    }

    protected virtual void OnWidgetClosed(ManifestGeneratedWidget widget)
    {
    }

    protected virtual void OnInputChanged(string fieldId, object? value, ManifestGeneratedWidget widget)
    {
    }

    protected T RequireService<T>(string key = "")
    {
        return Services.Resolve<T>(key);
    }

    protected bool TryGetService<T>(out T? service, string key = "")
    {
        return Services.TryResolve(out service, key);
    }

    protected IDisposable? SubscribeMessage(string channel, Action<object?> handler)
    {
        return TrackSubscription(MessageBus?.Subscribe(channel, handler));
    }

    protected IDisposable? SubscribeMessage(
        StringName channel,
        Action<ManifestMessageEnvelope> handler,
        ManifestMessageScope? scope = null,
        StringName? scopeId = null)
    {
        return TrackSubscription(MessageBus?.SubscribeEnvelope(channel, handler, scope, scopeId));
    }

    protected void PublishMessage(ManifestMessageEnvelope envelope)
    {
        MessageBus?.Publish(envelope);
    }

    protected void CloseWidget(ManifestGeneratedWidget widget)
    {
        Manager?.Close(widget);
    }

    protected Task CloseWidgetAsync(ManifestUiHandle handle, CancellationToken cancellationToken = default)
    {
        return Manager?.CloseAsync(handle, ManifestUiCloseReason.Programmatic, cancellationToken) ?? Task.CompletedTask;
    }

    [Obsolete("Use OpenScreenAsync(packageId, options, cancellationToken).")]
    protected Control? OpenScreen(string screenId, string scenePath, ManifestUiOpenOptions? options = null)
    {
        return Manager?.Open(screenId, scenePath, options);
    }

    protected Task<ManifestUiHandle?> OpenScreenAsync(
        StringName packageId,
        ManifestUiOpenOptions? options = null,
        CancellationToken cancellationToken = default)
    {
        return Manager is null
            ? Task.FromResult<ManifestUiHandle?>(null)
            : AwaitHandle(Manager.OpenAsync(packageId, options, cancellationToken));
    }

    [Obsolete("Use OpenModalAsync(packageId, options, cancellationToken).")]
    protected Control? OpenModal(string screenId, string scenePath, ManifestUiOpenOptions? options = null)
    {
        options = ConfigureModal(options);
        return Manager?.Open(screenId, scenePath, options);
    }

    protected Task<ManifestUiHandle?> OpenModalAsync(
        StringName packageId,
        ManifestUiOpenOptions? options = null,
        CancellationToken cancellationToken = default)
    {
        return OpenScreenAsync(packageId, ConfigureModal(options), cancellationToken);
    }

    [Obsolete("Use CloseWidgetAsync with a handle.")]
    protected void CloseScreen(string screenId)
    {
        Manager?.Close(screenId);
    }

    public void CloseAllWidgets()
    {
        foreach (var widget in _activeWidgets.ToArray())
        {
            Manager?.Close(widget);
        }
    }

    protected void Flush()
    {
        foreach (var widget in _activeWidgets.ToArray().Where(widget => GodotObject.IsInstanceValid(widget) && widget.IsInsideTree()))
        {
            widget.FlushViewModel();
        }
    }

    private IDisposable? TrackSubscription(IDisposable? subscription)
    {
        if (subscription is not null)
        {
            _subscriptions.Add(subscription);
        }

        return subscription;
    }

    private static ManifestUiOpenOptions ConfigureModal(ManifestUiOpenOptions? options)
    {
        options ??= new ManifestUiOpenOptions();
        options.IsModal = true;
        options.LayerId = string.IsNullOrWhiteSpace(options.LayerId) || options.LayerId == "Main" ? "Modal" : options.LayerId;
        options.Mode = ManifestUiOpenMode.Stack;
        options.RestoreFocusOnClose = true;
        return options;
    }

    private static async Task<ManifestUiHandle?> AwaitHandle(Task<ManifestUiHandle> task)
    {
        return await task;
    }
}

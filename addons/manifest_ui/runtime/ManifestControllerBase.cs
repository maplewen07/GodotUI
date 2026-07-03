using System;
using System.Collections.Generic;
using System.Linq;
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

    protected ManifestGeneratedWidget? Widget => _activeWidgets.Count == 0 ? null : _activeWidgets[^1];
    protected ManifestUiManager? Manager { get; private set; }
    protected ManifestMessageBus? MessageBus => ManifestMessageBus.Instance;

    internal void Setup(ManifestUiManager? manager, string packageId)
    {
        if (_isSetup)
        {
            return;
        }

        Manager = manager;
        PackageId = packageId;
        _isSetup = true;
        OnSetup();
    }

    internal void AttachWidget(ManifestGeneratedWidget widget)
    {
        if (!_activeWidgets.Contains(widget))
        {
            _activeWidgets.Add(widget);
        }

        Store.MarkAllDirty();
        OnWidgetOpened(widget);
    }

    internal void DetachWidget(ManifestGeneratedWidget widget)
    {
        if (_activeWidgets.Remove(widget))
        {
            OnWidgetClosed(widget);
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
        OnTeardown();

        foreach (var subscription in _subscriptions.ToArray())
        {
            subscription.Dispose();
        }
        _subscriptions.Clear();
        _activeWidgets.Clear();
        Manager = null;
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

    protected IDisposable? SubscribeMessage(string channel, Action<object?> handler)
    {
        var subscription = MessageBus?.Subscribe(channel, handler);
        if (subscription is not null)
        {
            _subscriptions.Add(subscription);
        }
        return subscription;
    }

    protected void CloseWidget(ManifestGeneratedWidget widget)
    {
        Manager?.Close(widget);
    }

    protected Control? OpenScreen(string screenId, string scenePath, ManifestUiOpenOptions? options = null)
    {
        return Manager?.Open(screenId, scenePath, options);
    }

    protected Control? OpenModal(string screenId, string scenePath, ManifestUiOpenOptions? options = null)
    {
        options ??= new ManifestUiOpenOptions();
        options.IsModal = true;
        options.LayerId = string.IsNullOrWhiteSpace(options.LayerId) || options.LayerId == "Main" ? "Modal" : options.LayerId;
        options.Mode = ManifestUiOpenMode.Stack;
        options.RestoreFocusOnClose = true;
        return Manager?.Open(screenId, scenePath, options);
    }

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
        foreach (var widget in _activeWidgets.ToArray().Where(widget => widget.IsInsideTree()))
        {
            widget.FlushViewModel();
        }
    }
}

using System;
using System.Threading;
using System.Threading.Tasks;
using Godot;

namespace GodotUi.Manifest;

public enum ManifestUiOpenMode
{
    Reuse,
    Replace,
    Stack,
}

public enum ManifestUiCloseReason
{
    Programmatic,
    Replaced,
    OwnerFreed,
    ManagerShutdown,
    Cancelled,
    Released,
    Message,
}

public enum ManifestUiState
{
    Loading,
    Open,
    Hidden,
    Closing,
    Closed,
    Failed,
}

public enum ManifestControllerScope
{
    Instance,
    Screen,
    Package,
}

public enum ManifestUiUpdatePolicy
{
    Manual,
    Immediate,
    Deferred,
}

public enum ManifestUiCancelPolicy
{
    Ignore,
    CloseTop,
    InvokeCallback,
}

public sealed class ManifestUiOpenOptions
{
    public string LayerId { get; set; } = "Main";
    public string ScreenId { get; set; } = "";
    public string ReuseKey { get; set; } = "";
    public ManifestUiOpenMode Mode { get; set; } = ManifestUiOpenMode.Reuse;
    public ManifestControllerScope? ControllerScope { get; set; }
    public bool IsModal { get; set; }
    public bool GrabFocus { get; set; }
    public bool RestoreFocusOnClose { get; set; }
    public bool PauseTree { get; set; }
    public bool TrapFocus { get; set; } = true;
    public ManifestUiCancelPolicy CancelPolicy { get; set; } = ManifestUiCancelPolicy.CloseTop;
    public Action<ManifestUiHandle>? OnCancel { get; set; }
    public Action<Control, ManifestUiCloseReason>? OnClosed { get; set; }
    public Action<ManifestUiHandle, ManifestUiCloseReason>? OnHandleClosed { get; set; }

    internal ManifestUiOpenOptions Snapshot()
    {
        return (ManifestUiOpenOptions)MemberwiseClone();
    }
}

public sealed class ManifestUiHandle
{
    internal ManifestUiHandle(StringName packageId, ManifestUiOpenOptions options)
    {
        InstanceId = Guid.NewGuid();
        PackageId = packageId;
        Options = options;
        State = ManifestUiState.Loading;
    }

    public Guid InstanceId { get; }
    public StringName PackageId { get; }
    public Control? Widget { get; internal set; }
    public ManifestControllerBase? Controller { get; internal set; }
    public ManifestUiState State { get; internal set; }
    public ManifestUiOpenOptions Options { get; }

    internal long Generation { get; set; }
    internal long CatalogRevision { get; set; }
    internal ManifestUiRootAttachment? RootAttachment { get; set; }
    internal bool CloseCallbackInvoked { get; set; }
}

public sealed class ManifestControllerContext
{
    internal ManifestControllerContext(
        ManifestUiManager? manager,
        string packageId,
        string scopeId,
        ManifestControllerScope scope,
        ManifestServiceRegistry services,
        ManifestMessageBus? messageBus)
    {
        Manager = manager;
        PackageId = packageId;
        ScopeId = scopeId;
        Scope = scope;
        Services = services;
        MessageBus = messageBus;
    }

    public ManifestUiManager? Manager { get; }
    public string PackageId { get; }
    public string ScopeId { get; }
    public ManifestControllerScope Scope { get; }
    public ManifestServiceRegistry Services { get; }
    public ManifestMessageBus? MessageBus { get; }

    public T RequireService<T>(string key = "")
    {
        return Services.Resolve<T>(key);
    }
}

internal static class ManifestTaskExtensions
{
    public static Task WaitForCancellation(this Task task, CancellationToken cancellationToken)
    {
        return cancellationToken.CanBeCanceled ? task.WaitAsync(cancellationToken) : task;
    }

    public static Task<T> WaitForCancellation<T>(this Task<T> task, CancellationToken cancellationToken)
    {
        return cancellationToken.CanBeCanceled ? task.WaitAsync(cancellationToken) : task;
    }
}

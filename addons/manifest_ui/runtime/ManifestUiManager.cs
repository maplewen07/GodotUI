using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Godot;

namespace GodotUi.Manifest;

public partial class ManifestUiManager : Node
{
    private readonly List<ManifestUiHandle> _handles = new();
    private readonly Dictionary<Control, ManifestUiHandle> _handlesByWidget = new();
    private readonly Dictionary<ManifestGeneratedWidget, ControllerRecord> _controllerByWidget = new();
    private readonly Dictionary<string, ControllerRecord> _controllers = new(StringComparer.Ordinal);
    private readonly Dictionary<string, LoadedScene> _preloadedScenes = new(StringComparer.Ordinal);
    private readonly Dictionary<string, PendingSceneLoad> _loadTasks = new(StringComparer.Ordinal);
    private readonly Dictionary<string, Task<ManifestUiHandle>> _pendingReuse = new(StringComparer.Ordinal);
    private readonly Dictionary<string, long> _generations = new(StringComparer.Ordinal);
    private readonly Dictionary<string, LoadedTranslations> _loadedTranslations = new(StringComparer.Ordinal);
    private readonly Dictionary<string, PendingTranslationLoad> _translationLoadTasks = new(StringComparer.Ordinal);
    private readonly Dictionary<string, long> _catalogRevisions = new(StringComparer.Ordinal);
    private readonly Dictionary<string, List<IDisposable>> _routeSubscriptions = new(StringComparer.Ordinal);
    private readonly HashSet<string> _ownedTranslationDomains = new(StringComparer.Ordinal);
    private readonly HashSet<string> _releaseWhenClosed = new(StringComparer.Ordinal);
    private int _mainThreadId;
    private bool _shuttingDown;

    public static ManifestUiManager? Instance { get; private set; }

    public ManifestUiCatalog Catalog { get; } = new();
    public ManifestServiceRegistry Services { get; } = new();

    public IReadOnlyList<ManifestUiHandle> Handles => _handles.ToArray();

    public override void _EnterTree()
    {
        _mainThreadId = System.Environment.CurrentManagedThreadId;
        Instance = this;
    }

    public override void _ExitTree()
    {
        _shuttingDown = true;
        foreach (var handle in _handles.ToArray())
        {
            CloseHandle(handle, ManifestUiCloseReason.ManagerShutdown, queueFree: true);
        }

        foreach (var record in _controllers.Values.Distinct().ToArray())
        {
            record.Controller.Dispose();
        }

        _controllers.Clear();
        _controllerByWidget.Clear();
        foreach (var scene in _preloadedScenes.Values.Select(record => record.Scene).Distinct().ToArray())
        {
            scene.Dispose();
        }
        _preloadedScenes.Clear();
        _loadTasks.Clear();
        _pendingReuse.Clear();
        _translationLoadTasks.Clear();
        foreach (var subscriptions in _routeSubscriptions.Values)
        {
            foreach (var subscription in subscriptions)
            {
                subscription.Dispose();
            }
        }
        _routeSubscriptions.Clear();
        _releaseWhenClosed.Clear();
        RemoveAllTranslations();
        _catalogRevisions.Clear();
        Services.Clear();

        if (Instance == this)
        {
            Instance = null;
        }
    }

    public void RegisterCatalogEntry(ManifestUiCatalogEntry entry, bool replace = false)
    {
        EnsureMainThread();
        ArgumentNullException.ThrowIfNull(entry);
        var packageKey = entry.PackageId.ToString();
        var replacing = Catalog.TryGet(entry.PackageId, out _);
        Catalog.Register(entry, replace);
        IncrementCatalogRevision(packageKey);
        if (replacing)
        {
            var replacementHasTranslations = entry.TranslationPaths.Count > 0 || !string.IsNullOrWhiteSpace(entry.TranslationDomain);
            InvalidateCatalogResources(packageKey, preserveTranslations: replacementHasTranslations);
        }
        _releaseWhenClosed.Remove(packageKey);
        ReplaceRouteSubscriptions(entry);
    }

    public bool UnregisterCatalogEntry(StringName packageId)
    {
        EnsureMainThread();
        var packageKey = packageId.ToString();
        if (!Catalog.Unregister(packageId))
        {
            return false;
        }

        IncrementCatalogRevision(packageKey);
        InvalidateCatalogResources(packageKey, preserveTranslations: false);
        RemoveRouteSubscriptions(packageKey);
        return true;
    }

    public async Task PreloadAsync(StringName packageId, CancellationToken cancellationToken = default)
    {
        EnsureMainThread();
        var entry = Catalog.GetRequired(packageId);
        var revision = GetCatalogRevision(packageId.ToString());
        await LoadSceneAsync(entry, revision).WaitForCancellation(cancellationToken);
        await EnsureTranslationsAsync(entry, revision).WaitForCancellation(cancellationToken);
        EnsureCatalogCurrent(entry, revision);
    }

    public async Task<ManifestUiHandle> OpenAsync(
        StringName packageId,
        ManifestUiOpenOptions? options = null,
        CancellationToken cancellationToken = default)
    {
        EnsureMainThread();
        cancellationToken.ThrowIfCancellationRequested();
        var entry = Catalog.GetRequired(packageId);
        var catalogRevision = GetCatalogRevision(packageId.ToString());
        var snapshot = NormalizeOptions(packageId.ToString(), options);
        var reuseKey = BuildReuseKey(packageId.ToString(), snapshot);

        if (snapshot.Mode == ManifestUiOpenMode.Reuse)
        {
            var reusable = FindReusable(reuseKey);
            if (reusable is not null)
            {
                if (reusable.State == ManifestUiState.Hidden)
                {
                    await ShowAsync(reusable, cancellationToken);
                }

                return reusable;
            }

            if (_pendingReuse.TryGetValue(reuseKey, out var pending))
            {
                if (!pending.IsCompleted)
                {
                    return await pending.WaitForCancellation(cancellationToken);
                }

                _pendingReuse.Remove(reuseKey);
            }

            var generation = GetGeneration(reuseKey);
            var sharedTask = OpenCoreAsync(entry, catalogRevision, snapshot, reuseKey, generation, CancellationToken.None);
            _pendingReuse[reuseKey] = sharedTask;
            _ = RemovePendingReuseAsync(reuseKey, sharedTask);
            return await sharedTask.WaitForCancellation(cancellationToken);
        }

        var nextGeneration = GetGeneration(reuseKey);
        if (snapshot.Mode == ManifestUiOpenMode.Replace)
        {
            nextGeneration = IncrementGeneration(reuseKey);
            foreach (var existing in _handles.Where(handle => GetHandleReuseKey(handle) == reuseKey).ToArray())
            {
                CloseHandle(existing, ManifestUiCloseReason.Replaced, queueFree: true);
            }
        }

        return await OpenCoreAsync(entry, catalogRevision, snapshot, reuseKey, nextGeneration, cancellationToken);
    }

    public Task ShowAsync(ManifestUiHandle handle, CancellationToken cancellationToken = default)
    {
        EnsureMainThread();
        cancellationToken.ThrowIfCancellationRequested();
        ValidateOwnedHandle(handle);

        if (handle.State == ManifestUiState.Open)
        {
            return Task.CompletedTask;
        }

        if (handle.State != ManifestUiState.Hidden)
        {
            throw new InvalidOperationException($"Cannot show a UI in state '{handle.State}'.");
        }

        if (handle.Widget is null || !GodotObject.IsInstanceValid(handle.Widget))
        {
            CloseHandle(handle, ManifestUiCloseReason.OwnerFreed, queueFree: false);
            throw new InvalidOperationException("Cannot show a UI whose widget has been freed.");
        }

        handle.Widget.Visible = true;
        ManifestUiRoot.Instance?.ShowWidget(handle.Widget, handle.Options, handle.RootAttachment);
        if (handle.Widget is ManifestGeneratedWidget generated)
        {
            generated.ResetBindingCursor();
            generated.FlushViewModel();
        }

        handle.State = ManifestUiState.Open;
        return Task.CompletedTask;
    }

    public Task HideAsync(ManifestUiHandle handle, CancellationToken cancellationToken = default)
    {
        EnsureMainThread();
        cancellationToken.ThrowIfCancellationRequested();
        ValidateOwnedHandle(handle);

        if (handle.State == ManifestUiState.Hidden)
        {
            return Task.CompletedTask;
        }

        if (handle.State != ManifestUiState.Open)
        {
            throw new InvalidOperationException($"Cannot hide a UI in state '{handle.State}'.");
        }

        if (handle.Widget is null)
        {
            throw new InvalidOperationException("Cannot hide a UI whose widget has been released.");
        }

        ManifestUiRoot.Instance?.HideWidget(handle.Widget, handle.Options, handle.RootAttachment);
        handle.Widget.Visible = false;
        handle.State = ManifestUiState.Hidden;
        return Task.CompletedTask;
    }

    public Task CloseAsync(
        ManifestUiHandle handle,
        ManifestUiCloseReason reason,
        CancellationToken cancellationToken = default)
    {
        EnsureMainThread();
        cancellationToken.ThrowIfCancellationRequested();
        if (handle.State is ManifestUiState.Closed or ManifestUiState.Failed)
        {
            return Task.CompletedTask;
        }

        ValidateOwnedHandle(handle);
        CloseHandle(handle, reason, queueFree: true);
        return Task.CompletedTask;
    }

    public async Task ReleaseAsync(StringName packageId, bool closeInstances = false)
    {
        EnsureMainThread();
        var packageKey = packageId.ToString();
        if (closeInstances)
        {
            foreach (var handle in _handles.Where(handle => handle.PackageId.ToString() == packageKey).ToArray())
            {
                await CloseAsync(handle, ManifestUiCloseReason.Released);
            }
        }

        if (_loadTasks.TryGetValue(packageKey, out var loading))
        {
            try
            {
                await loading.Task;
            }
            catch
            {
                // A failed preload has no retained resource to release.
            }
        }

        if (_translationLoadTasks.TryGetValue(packageKey, out var translationsLoading))
        {
            try
            {
                await translationsLoading.Task;
            }
            catch
            {
                // A failed translation load has no completed package registration to release.
            }
        }

        if (_preloadedScenes.Remove(packageKey, out var preloadedScene))
        {
            preloadedScene.Scene.Dispose();
        }
        if (_handles.Any(handle => handle.PackageId.ToString() == packageKey))
        {
            _releaseWhenClosed.Add(packageKey);
        }
        else
        {
            RemoveTranslations(packageKey);
            _releaseWhenClosed.Remove(packageKey);
        }

        foreach (var pair in _controllers.Where(pair => pair.Value.PackageId == packageKey).ToArray())
        {
            var record = pair.Value;
            if (record.ReferenceCount == 0)
            {
                record.Controller.Dispose();
                RemoveControllerRecord(record);
            }
            else
            {
                record.ReleaseWhenUnused = true;
            }
        }
    }

    [Obsolete("Use OpenAsync(packageId, options, cancellationToken) with a generated catalog.")]
    public Control Open(string screenId, string scenePath)
    {
        return Open(screenId, scenePath, new ManifestUiOpenOptions());
    }

    [Obsolete("Use OpenAsync(packageId, options, cancellationToken) with a generated catalog.")]
    public Control Open(string screenId, string scenePath, ManifestUiOpenOptions? options)
    {
        EnsureMainThread();
        var snapshot = NormalizeOptions(screenId, options);
        var reuseKey = BuildReuseKey(screenId, snapshot);
        if (snapshot.Mode == ManifestUiOpenMode.Reuse && FindReusable(reuseKey) is { } reusable)
        {
            if (reusable.State == ManifestUiState.Hidden)
            {
                _ = ShowAsync(reusable);
            }

            return reusable.Widget!;
        }

        if (snapshot.Mode == ManifestUiOpenMode.Replace)
        {
            IncrementGeneration(reuseKey);
            foreach (var existing in _handles.Where(handle => GetHandleReuseKey(handle) == reuseKey).ToArray())
            {
                CloseHandle(existing, ManifestUiCloseReason.Replaced, queueFree: true);
            }
        }

        var scene = ResourceLoader.Load<PackedScene>(scenePath)
            ?? throw new InvalidOperationException($"PackedScene '{scenePath}' could not be loaded.");
        var handle = new ManifestUiHandle(screenId, snapshot)
        {
            Generation = GetGeneration(reuseKey),
        };
        _handles.Add(handle);

        try
        {
            InstantiateHandle(handle, scene, null);
            return handle.Widget!;
        }
        catch
        {
            handle.State = ManifestUiState.Failed;
            _handles.Remove(handle);
            throw;
        }
    }

    [Obsolete("Use CloseAsync(handle, reason, cancellationToken).")]
    public void Close(string screenId)
    {
        var handle = _handles.LastOrDefault(candidate =>
            candidate.Options.ScreenId == screenId || candidate.PackageId.ToString() == screenId);
        if (handle is not null)
        {
            CloseHandle(handle, ManifestUiCloseReason.Programmatic, queueFree: true);
        }
    }

    [Obsolete("Use CloseAsync(handle, reason, cancellationToken).")]
    public void Close(Control widget)
    {
        if (_handlesByWidget.TryGetValue(widget, out var handle))
        {
            CloseHandle(handle, ManifestUiCloseReason.Programmatic, queueFree: true);
        }
    }

    public ManifestUiHandle? GetHandle(Control widget)
    {
        return _handlesByWidget.TryGetValue(widget, out var handle) ? handle : null;
    }

    public void NotifyWidgetExited(Control widget)
    {
        if (_handlesByWidget.TryGetValue(widget, out var handle))
        {
            CloseHandle(handle, ManifestUiCloseReason.OwnerFreed, queueFree: false);
        }
    }

    [Obsolete("Controller creation is driven by generated scope metadata. This method always uses Package scope.")]
    public ManifestControllerBase GetOrCreateController(string packageId, Func<ManifestControllerBase> factory)
    {
        var key = BuildControllerKey(
            ManifestControllerScope.Package,
            packageId,
            packageId,
            GetCatalogRevision(packageId));
        if (_controllers.TryGetValue(key, out var existing))
        {
            return existing.Controller;
        }

        var controller = factory();
        controller.Setup(this, packageId, ManifestControllerScope.Package, packageId, Services, ManifestMessageBus.Instance);
        var record = new ControllerRecord(key, packageId, ManifestControllerScope.Package, packageId, controller);
        _controllers[key] = record;
        return controller;
    }

    public ManifestControllerBase? FindController(string packageId)
    {
        return _controllers.Values.LastOrDefault(record => record.PackageId == packageId && record.ReferenceCount > 0)?.Controller
            ?? _controllers.Values.LastOrDefault(record => record.PackageId == packageId)?.Controller;
    }

    public int GetOpenCount(string screenId)
    {
        return _handles.Count(handle =>
            handle.State is ManifestUiState.Loading or ManifestUiState.Open or ManifestUiState.Hidden
            && (handle.Options.ScreenId == screenId || handle.PackageId.ToString() == screenId));
    }

    public string GetTranslationDomain(string packageId)
    {
        return Catalog.TryGet(packageId, out var entry) ? entry.TranslationDomain : string.Empty;
    }

    internal ManifestControllerBase AttachGeneratedWidget(
        ManifestGeneratedWidget widget,
        string packageId,
        ManifestControllerScope declaredScope,
        Func<ManifestControllerBase> generatedFactory)
    {
        var handle = _handlesByWidget.TryGetValue(widget, out var ownedHandle) ? ownedHandle : null;
        Catalog.TryGet(packageId, out var catalogEntry);
        var scope = handle?.Options.ControllerScope ?? catalogEntry?.ControllerScope ?? declaredScope;
        var screenId = handle?.Options.ScreenId;
        if (string.IsNullOrWhiteSpace(screenId))
        {
            screenId = packageId;
        }

        var scopeId = scope switch
        {
            ManifestControllerScope.Instance => handle?.InstanceId.ToString("N") ?? widget.GetInstanceId().ToString(),
            ManifestControllerScope.Screen => screenId,
            _ => packageId,
        };
        var catalogRevision = handle is not null && string.Equals(handle.PackageId.ToString(), packageId, StringComparison.Ordinal)
            ? handle.CatalogRevision
            : GetCatalogRevision(packageId);
        var controllerKey = BuildControllerKey(scope, packageId, scopeId, catalogRevision);

        if (!_controllers.TryGetValue(controllerKey, out var record))
        {
            var controller = (catalogEntry?.ControllerFactory ?? generatedFactory)();
            controller.Setup(this, packageId, scope, scopeId, Services, ManifestMessageBus.Instance);
            record = new ControllerRecord(controllerKey, packageId, scope, scopeId, controller);
            _controllers[controllerKey] = record;
        }

        record.ReferenceCount++;
        _controllerByWidget[widget] = record;
        if (handle is not null)
        {
            handle.Controller = record.Controller;
        }

        return record.Controller;
    }

    internal void DetachGeneratedWidget(ManifestGeneratedWidget widget, ManifestControllerBase controller)
    {
        if (!_controllerByWidget.Remove(widget, out var record))
        {
            return;
        }

        record.ReferenceCount = Math.Max(0, record.ReferenceCount - 1);
        if (record.ReferenceCount == 0 &&
            (record.Scope == ManifestControllerScope.Instance || record.ReleaseWhenUnused || _shuttingDown))
        {
            record.Controller.Dispose();
            RemoveControllerRecord(record);
        }
    }

    private async Task<ManifestUiHandle> OpenCoreAsync(
        ManifestUiCatalogEntry entry,
        long catalogRevision,
        ManifestUiOpenOptions options,
        string reuseKey,
        long generation,
        CancellationToken cancellationToken)
    {
        var handle = new ManifestUiHandle(entry.PackageId, options)
        {
            Generation = generation,
            CatalogRevision = catalogRevision,
        };
        _handles.Add(handle);

        try
        {
            var loadTask = LoadSceneAsync(entry, catalogRevision);
            var translationTask = EnsureTranslationsAsync(entry, catalogRevision);
            var scene = await loadTask.WaitForCancellation(cancellationToken);
            await translationTask.WaitForCancellation(cancellationToken);
            cancellationToken.ThrowIfCancellationRequested();
            EnsureCatalogCurrent(entry, catalogRevision);

            if (handle.State != ManifestUiState.Loading ||
                options.Mode != ManifestUiOpenMode.Stack && GetGeneration(reuseKey) != generation)
            {
                handle.State = ManifestUiState.Closed;
                _handles.Remove(handle);
                throw new OperationCanceledException("The UI open request was superseded.");
            }

            InstantiateHandle(handle, scene, entry);
            return handle;
        }
        catch (OperationCanceledException)
        {
            if (handle.State == ManifestUiState.Loading)
            {
                handle.State = ManifestUiState.Closed;
            }

            _handles.Remove(handle);
            throw;
        }
        catch (Exception exception)
        {
            handle.State = ManifestUiState.Failed;
            _handles.Remove(handle);
            ManifestRuntimeDiagnostics.Report(
                "MUIR5001",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Failed to open Manifest UI package '{entry.PackageId}'.",
                exception,
                entry.PackageId.ToString(),
                handle.InstanceId);
            throw;
        }
    }

    private async Task RemovePendingReuseAsync(string reuseKey, Task<ManifestUiHandle> task)
    {
        try
        {
            await task;
        }
        catch
        {
            // The original caller observes the failure; this continuation only owns cleanup.
        }
        finally
        {
            if (_pendingReuse.TryGetValue(reuseKey, out var current) && ReferenceEquals(current, task))
            {
                _pendingReuse.Remove(reuseKey);
            }
        }
    }

    private void InstantiateHandle(ManifestUiHandle handle, PackedScene scene, ManifestUiCatalogEntry? entry)
    {
        var widget = scene.Instantiate<Control>();
        if (entry is not null && widget is not ManifestGeneratedWidget)
        {
            widget.Free();
            throw new InvalidOperationException(
                $"Catalog scene '{entry.ScenePath}' must have a ManifestGeneratedWidget root.");
        }

        handle.Widget = widget;
        _handlesByWidget[widget] = handle;

        try
        {
            if (ManifestUiRoot.Instance is { } root)
            {
                handle.RootAttachment = root.AttachWidget(widget, handle.Options);
            }
            else
            {
                GetTree().Root.AddChild(widget);
            }

            if (handle.Controller is null && entry?.ControllerFactory is { } factory)
            {
                var scope = handle.Options.ControllerScope ?? entry.ControllerScope;
                var scopeId = scope == ManifestControllerScope.Instance
                    ? handle.InstanceId.ToString("N")
                    : scope == ManifestControllerScope.Screen ? handle.Options.ScreenId : entry.PackageId.ToString();
                var key = BuildControllerKey(scope, entry.PackageId.ToString(), scopeId, handle.CatalogRevision);
                if (!_controllers.TryGetValue(key, out var record))
                {
                    var controller = factory();
                    controller.Setup(this, entry.PackageId.ToString(), scope, scopeId, Services, ManifestMessageBus.Instance);
                    record = new ControllerRecord(key, entry.PackageId.ToString(), scope, scopeId, controller);
                    _controllers[key] = record;
                }

                handle.Controller = record.Controller;
            }

            handle.State = ManifestUiState.Open;
            ManifestUiRoot.Instance?.ShowWidget(widget, handle.Options, handle.RootAttachment);
        }
        catch
        {
            _handlesByWidget.Remove(widget);
            if (handle.RootAttachment is not null)
            {
                ManifestUiRoot.Instance?.DetachWidget(widget, handle.Options, handle.RootAttachment);
            }

            if (GodotObject.IsInstanceValid(widget))
            {
                widget.QueueFree();
            }

            handle.Widget = null;
            handle.Controller = null;
            handle.RootAttachment = null;

            throw;
        }
    }

    private async Task<PackedScene> LoadSceneAsync(ManifestUiCatalogEntry entry, long catalogRevision)
    {
        var packageKey = entry.PackageId.ToString();
        if (_preloadedScenes.TryGetValue(packageKey, out var loaded))
        {
            if (loaded.CatalogRevision == catalogRevision && ReferenceEquals(loaded.Entry, entry))
            {
                return loaded.Scene;
            }

            _preloadedScenes.Remove(packageKey);
            loaded.Scene.Dispose();
        }

        if (_loadTasks.TryGetValue(packageKey, out var pending))
        {
            if (pending.CatalogRevision == catalogRevision && ReferenceEquals(pending.Entry, entry))
            {
                return await pending.Task;
            }

            _loadTasks.Remove(packageKey);
        }

        var task = LoadAndCacheSceneAsync(entry, packageKey, catalogRevision);
        var load = new PendingSceneLoad(entry, catalogRevision, task);
        _loadTasks[packageKey] = load;
        try
        {
            return await task;
        }
        finally
        {
            if (_loadTasks.TryGetValue(packageKey, out var current) && ReferenceEquals(current, load))
            {
                _loadTasks.Remove(packageKey);
            }
        }
    }

    private async Task<PackedScene> LoadAndCacheSceneAsync(
        ManifestUiCatalogEntry entry,
        string packageKey,
        long catalogRevision)
    {
        var scene = await LoadSceneCoreAsync(entry.ScenePath, forceReload: catalogRevision > 1);
        if (!IsCatalogCurrent(entry, catalogRevision))
        {
            scene.Dispose();
            throw new OperationCanceledException($"Catalog entry '{packageKey}' was replaced while its scene was loading.");
        }

        _preloadedScenes[packageKey] = new LoadedScene(entry, catalogRevision, scene);
        return scene;
    }

    private async Task<PackedScene> LoadSceneCoreAsync(string path, bool forceReload)
    {
        if (ResourceLoader.HasCached(path))
        {
            return ResourceLoader.Load<PackedScene>(
                path,
                typeHint: "PackedScene",
                cacheMode: forceReload ? ResourceLoader.CacheMode.Replace : ResourceLoader.CacheMode.Reuse)
                ?? throw new InvalidOperationException($"Cached PackedScene '{path}' could not be loaded.");
        }

        var cacheMode = forceReload ? ResourceLoader.CacheMode.Replace : ResourceLoader.CacheMode.Reuse;
        var error = ResourceLoader.LoadThreadedRequest(path, "PackedScene", true, cacheMode);
        if (error != Error.Ok)
        {
            throw new InvalidOperationException($"Threaded load request for '{path}' failed with {error}.");
        }

        while (true)
        {
            var status = ResourceLoader.LoadThreadedGetStatus(path);
            switch (status)
            {
                case ResourceLoader.ThreadLoadStatus.Loaded:
                    return ResourceLoader.LoadThreadedGet(path) as PackedScene
                        ?? throw new InvalidOperationException($"Threaded resource '{path}' is not a PackedScene.");
                case ResourceLoader.ThreadLoadStatus.Failed:
                case ResourceLoader.ThreadLoadStatus.InvalidResource:
                    throw new InvalidOperationException($"Threaded load for '{path}' failed with status {status}.");
            }

            await Task.Delay(1);
        }
    }

    private Task EnsureTranslationsAsync(ManifestUiCatalogEntry entry, long catalogRevision)
    {
        var packageKey = entry.PackageId.ToString();
        if (_loadedTranslations.TryGetValue(packageKey, out var loaded))
        {
            if (loaded.CatalogRevision == catalogRevision && ReferenceEquals(loaded.Entry, entry))
            {
                return Task.CompletedTask;
            }

            // Keep the last complete domain active until the replacement resources are ready.
        }

        if (entry.TranslationPaths.Count == 0 && string.IsNullOrWhiteSpace(entry.TranslationDomain))
        {
            return Task.CompletedTask;
        }

        if (_translationLoadTasks.TryGetValue(packageKey, out var pending))
        {
            if (pending.CatalogRevision == catalogRevision && ReferenceEquals(pending.Entry, entry))
            {
                return pending.Task;
            }

            _translationLoadTasks.Remove(packageKey);
        }

        var task = LoadTranslationsCoreAsync(entry, packageKey, catalogRevision);
        var load = new PendingTranslationLoad(entry, catalogRevision, task);
        _translationLoadTasks[packageKey] = load;
        _ = RemoveTranslationLoadTaskAsync(packageKey, load);
        return task;
    }

    private async Task LoadTranslationsCoreAsync(
        ManifestUiCatalogEntry entry,
        string packageKey,
        long catalogRevision)
    {
        var translations = new List<Translation>();
        var domainName = string.IsNullOrWhiteSpace(entry.TranslationDomain) ? packageKey : entry.TranslationDomain;
        TranslationDomain? domain = null;
        var domainExisted = false;
        var added = new List<Translation>();

        try
        {
            foreach (var path in entry.TranslationPaths)
            {
                translations.Add(await LoadTranslationAsync(path, forceReload: catalogRevision > 1));
            }

            EnsureCatalogCurrent(entry, catalogRevision);
            RemoveTranslations(packageKey);
            domainExisted = TranslationServer.HasDomain(domainName);
            domain = TranslationServer.GetOrAddDomain(domainName);
            if (!domainExisted)
            {
                _ownedTranslationDomains.Add(domainName);
            }

            foreach (var translation in translations)
            {
                domain.AddTranslation(translation);
                added.Add(translation);
            }

            _loadedTranslations[packageKey] = new LoadedTranslations(entry, catalogRevision, domainName, translations);
        }
        catch
        {
            if (domain is not null)
            {
                foreach (var translation in added.Where(domain.HasTranslation))
                {
                    domain.RemoveTranslation(translation);
                }
            }

            if (!domainExisted && TranslationServer.HasDomain(domainName))
            {
                TranslationServer.RemoveDomain(domainName);
                _ownedTranslationDomains.Remove(domainName);
            }

            foreach (var translation in translations)
            {
                translation.Dispose();
            }
            throw;
        }
        finally
        {
            domain?.Dispose();
        }
    }

    private async Task RemoveTranslationLoadTaskAsync(string packageKey, PendingTranslationLoad load)
    {
        try
        {
            await load.Task;
        }
        catch
        {
            // The preload/open caller observes the error; this continuation only owns cleanup.
        }
        finally
        {
            if (_translationLoadTasks.TryGetValue(packageKey, out var current) && ReferenceEquals(current, load))
            {
                _translationLoadTasks.Remove(packageKey);
            }
        }
    }

    private async Task<Translation> LoadTranslationAsync(string path, bool forceReload)
    {
        if (ResourceLoader.HasCached(path))
        {
            return ResourceLoader.Load<Translation>(
                path,
                typeHint: "Translation",
                cacheMode: forceReload ? ResourceLoader.CacheMode.Replace : ResourceLoader.CacheMode.Reuse)
                ?? throw new InvalidOperationException($"Translation '{path}' could not be loaded.");
        }

        var cacheMode = forceReload ? ResourceLoader.CacheMode.Replace : ResourceLoader.CacheMode.Reuse;
        var error = ResourceLoader.LoadThreadedRequest(path, "Translation", true, cacheMode);
        if (error != Error.Ok)
        {
            throw new InvalidOperationException($"Threaded translation request for '{path}' failed with {error}.");
        }

        while (true)
        {
            var status = ResourceLoader.LoadThreadedGetStatus(path);
            switch (status)
            {
                case ResourceLoader.ThreadLoadStatus.Loaded:
                    return ResourceLoader.LoadThreadedGet(path) as Translation
                        ?? throw new InvalidOperationException($"Resource '{path}' is not a Translation.");
                case ResourceLoader.ThreadLoadStatus.Failed:
                case ResourceLoader.ThreadLoadStatus.InvalidResource:
                    throw new InvalidOperationException($"Threaded translation load for '{path}' failed with status {status}.");
            }

            await Task.Delay(1);
        }
    }

    private void CloseHandle(ManifestUiHandle handle, ManifestUiCloseReason reason, bool queueFree)
    {
        if (handle.State is ManifestUiState.Closing or ManifestUiState.Closed)
        {
            return;
        }

        handle.State = ManifestUiState.Closing;
        _handles.Remove(handle);

        var widget = handle.Widget;
        if (widget is not null)
        {
            _handlesByWidget.Remove(widget);
            try
            {
                ManifestUiRoot.Instance?.DetachWidget(widget, handle.Options, handle.RootAttachment);
            }
            catch (Exception exception)
            {
                ManifestRuntimeDiagnostics.Report(
                    "MUIR5002",
                    ManifestRuntimeDiagnosticSeverity.Error,
                    "Failed to detach a UI widget from its root.",
                    exception,
                    handle.PackageId.ToString(),
                    handle.InstanceId);
            }
        }

        InvokeCloseCallbacks(handle, reason);
        handle.State = ManifestUiState.Closed;

        if (queueFree && widget is not null && GodotObject.IsInstanceValid(widget) && !widget.IsQueuedForDeletion())
        {
            widget.QueueFree();
        }

        handle.Widget = null;
        handle.Controller = null;
        handle.RootAttachment = null;

        var packageId = handle.PackageId.ToString();
        if (_releaseWhenClosed.Contains(packageId) && !_handles.Any(open => open.PackageId.ToString() == packageId))
        {
            RemoveTranslations(packageId);
            _releaseWhenClosed.Remove(packageId);
        }
    }

    private static void InvokeCloseCallbacks(ManifestUiHandle handle, ManifestUiCloseReason reason)
    {
        if (handle.CloseCallbackInvoked)
        {
            return;
        }

        handle.CloseCallbackInvoked = true;
        try
        {
            if (handle.Widget is not null)
            {
                handle.Options.OnClosed?.Invoke(handle.Widget, reason);
            }
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR5003",
                ManifestRuntimeDiagnosticSeverity.Error,
                "A legacy close callback failed.",
                exception,
                handle.PackageId.ToString(),
                handle.InstanceId);
        }

        try
        {
            handle.Options.OnHandleClosed?.Invoke(handle, reason);
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR5004",
                ManifestRuntimeDiagnosticSeverity.Error,
                "A handle close callback failed.",
                exception,
                handle.PackageId.ToString(),
                handle.InstanceId);
        }
    }

    private ManifestUiHandle? FindReusable(string reuseKey)
    {
        return _handles.LastOrDefault(handle =>
            GetHandleReuseKey(handle) == reuseKey &&
            handle.State is ManifestUiState.Open or ManifestUiState.Hidden);
    }

    private static ManifestUiOpenOptions NormalizeOptions(string packageId, ManifestUiOpenOptions? options)
    {
        var snapshot = (options ?? new ManifestUiOpenOptions()).Snapshot();
        snapshot.LayerId = string.IsNullOrWhiteSpace(snapshot.LayerId) ? "Main" : snapshot.LayerId;
        snapshot.VisibilityScope = string.IsNullOrWhiteSpace(snapshot.VisibilityScope)
            ? "global"
            : snapshot.VisibilityScope.Trim();
        snapshot.ScreenId = string.IsNullOrWhiteSpace(snapshot.ScreenId) ? packageId : snapshot.ScreenId;
        snapshot.ReuseKey = string.IsNullOrWhiteSpace(snapshot.ReuseKey) ? snapshot.ScreenId : snapshot.ReuseKey;
        if (snapshot.IsModal)
        {
            if (snapshot.LayerId == "Main")
            {
                snapshot.LayerId = "Modal";
            }

            snapshot.RestoreFocusOnClose = true;
        }

        return snapshot;
    }

    private static string BuildReuseKey(string packageId, ManifestUiOpenOptions options)
    {
        return $"{packageId}\n{options.ReuseKey}";
    }

    private static string GetHandleReuseKey(ManifestUiHandle handle)
    {
        return BuildReuseKey(handle.PackageId.ToString(), handle.Options);
    }

    private long GetGeneration(string reuseKey)
    {
        return _generations.TryGetValue(reuseKey, out var generation) ? generation : 0;
    }

    private long IncrementGeneration(string reuseKey)
    {
        var generation = GetGeneration(reuseKey) + 1;
        _generations[reuseKey] = generation;
        return generation;
    }

    private long GetCatalogRevision(string packageId)
    {
        return _catalogRevisions.TryGetValue(packageId, out var revision) ? revision : 0;
    }

    private long IncrementCatalogRevision(string packageId)
    {
        var revision = checked(GetCatalogRevision(packageId) + 1);
        _catalogRevisions[packageId] = revision;
        return revision;
    }

    private bool IsCatalogCurrent(ManifestUiCatalogEntry entry, long catalogRevision)
    {
        return !_shuttingDown
            && GetCatalogRevision(entry.PackageId.ToString()) == catalogRevision
            && Catalog.TryGet(entry.PackageId, out var current)
            && ReferenceEquals(current, entry);
    }

    private void EnsureCatalogCurrent(ManifestUiCatalogEntry entry, long catalogRevision)
    {
        if (!IsCatalogCurrent(entry, catalogRevision))
        {
            throw new OperationCanceledException($"Catalog entry '{entry.PackageId}' was replaced while an operation was in progress.");
        }
    }

    private void InvalidateCatalogResources(string packageId, bool preserveTranslations)
    {
        if (_preloadedScenes.Remove(packageId, out var loadedScene))
        {
            loadedScene.Scene.Dispose();
        }

        _loadTasks.Remove(packageId);
        _translationLoadTasks.Remove(packageId);
        if (!preserveTranslations)
        {
            RemoveTranslations(packageId);
        }

        foreach (var record in _controllers.Values.Where(record => record.PackageId == packageId).Distinct().ToArray())
        {
            if (record.ReferenceCount == 0)
            {
                record.Controller.Dispose();
                RemoveControllerRecord(record);
            }
            else
            {
                record.ReleaseWhenUnused = true;
            }
        }

        var reusePrefix = packageId + "\n";
        foreach (var reuseKey in _pendingReuse.Keys.Where(key => key.StartsWith(reusePrefix, StringComparison.Ordinal)).ToArray())
        {
            _pendingReuse.Remove(reuseKey);
            IncrementGeneration(reuseKey);
        }
    }

    private void ValidateOwnedHandle(ManifestUiHandle handle)
    {
        ArgumentNullException.ThrowIfNull(handle);
        if (!_handles.Contains(handle))
        {
            throw new InvalidOperationException("The handle is not owned by this ManifestUiManager.");
        }
    }

    private static string BuildControllerKey(
        ManifestControllerScope scope,
        string packageId,
        string scopeId,
        long catalogRevision)
    {
        return $"{scope}:{packageId}:{scopeId}:v{catalogRevision}";
    }

    private void RemoveControllerRecord(ControllerRecord record)
    {
        foreach (var key in _controllers.Where(pair => ReferenceEquals(pair.Value, record)).Select(pair => pair.Key).ToArray())
        {
            _controllers.Remove(key);
        }
    }

    private void ReplaceRouteSubscriptions(ManifestUiCatalogEntry entry)
    {
        var packageKey = entry.PackageId.ToString();
        RemoveRouteSubscriptions(packageKey);
        if (entry.Routes.Count == 0)
        {
            return;
        }

        var bus = ManifestMessageBus.Instance;
        if (bus is null)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR2002",
                ManifestRuntimeDiagnosticSeverity.Warning,
                $"Catalog routes for '{packageKey}' were not registered because ManifestMessageBus is unavailable.",
                packageId: packageKey);
            return;
        }

        var subscriptions = new List<IDisposable>(entry.Routes.Count);
        foreach (var route in entry.Routes)
        {
            subscriptions.Add(bus.SubscribeEnvelope(route.Channel, envelope => DispatchCatalogRoute(entry, route, envelope)));
        }
        _routeSubscriptions[packageKey] = subscriptions;
    }

    private void RemoveRouteSubscriptions(string packageId)
    {
        if (!_routeSubscriptions.Remove(packageId, out var subscriptions))
        {
            return;
        }
        foreach (var subscription in subscriptions)
        {
            subscription.Dispose();
        }
    }

    private void DispatchCatalogRoute(ManifestUiCatalogEntry owner, ManifestUiRoute route, ManifestMessageEnvelope envelope)
    {
        void Execute() => _ = ExecuteCatalogRouteAsync(owner, route, envelope);
        if (_mainThreadId == 0 || System.Environment.CurrentManagedThreadId == _mainThreadId)
        {
            Execute();
        }
        else
        {
            Callable.From((Action)Execute).CallDeferred();
        }
    }

    private async Task ExecuteCatalogRouteAsync(ManifestUiCatalogEntry owner, ManifestUiRoute route, ManifestMessageEnvelope envelope)
    {
        var targetPackage = string.IsNullOrWhiteSpace(route.PackageId.ToString())
            ? owner.PackageId
            : route.PackageId;
        try
        {
            if (route.Action == "open")
            {
                await OpenAsync(targetPackage);
                return;
            }

            foreach (var handle in _handles.Where(handle => handle.PackageId == targetPackage).ToArray())
            {
                await CloseAsync(handle, ManifestUiCloseReason.Message);
            }
        }
        catch (Exception exception)
        {
            ManifestRuntimeDiagnostics.Report(
                "MUIR2003",
                ManifestRuntimeDiagnosticSeverity.Error,
                $"Catalog route '{route.Channel}' ({route.Action}) failed for target package '{targetPackage}'.",
                exception,
                owner.PackageId.ToString());
        }
    }

    private void RemoveTranslations(string packageId)
    {
        if (!_loadedTranslations.Remove(packageId, out var loaded))
        {
            return;
        }

        TranslationDomain? domain = null;
        try
        {
            if (TranslationServer.HasDomain(loaded.Domain))
            {
                domain = TranslationServer.GetOrAddDomain(loaded.Domain);
                foreach (var translation in loaded.Translations.Where(domain.HasTranslation))
                {
                    domain.RemoveTranslation(translation);
                }
            }

            if (_ownedTranslationDomains.Contains(loaded.Domain) &&
                _loadedTranslations.Values.All(other => other.Domain != loaded.Domain) &&
                TranslationServer.HasDomain(loaded.Domain))
            {
                TranslationServer.RemoveDomain(loaded.Domain);
                _ownedTranslationDomains.Remove(loaded.Domain);
            }
        }
        finally
        {
            domain?.Dispose();
            foreach (var translation in loaded.Translations)
            {
                translation.Dispose();
            }
        }
    }

    private void RemoveAllTranslations()
    {
        foreach (var packageId in _loadedTranslations.Keys.ToArray())
        {
            RemoveTranslations(packageId);
        }

        _ownedTranslationDomains.Clear();
    }

    private void EnsureMainThread()
    {
        if (_mainThreadId != 0 && System.Environment.CurrentManagedThreadId != _mainThreadId)
        {
            throw new InvalidOperationException("ManifestUiManager lifecycle APIs must be called from the Godot main thread.");
        }

        if (_shuttingDown)
        {
            throw new InvalidOperationException("ManifestUiManager is shutting down.");
        }
    }

    private sealed class ControllerRecord
    {
        public ControllerRecord(
            string key,
            string packageId,
            ManifestControllerScope scope,
            string scopeId,
            ManifestControllerBase controller)
        {
            Key = key;
            PackageId = packageId;
            Scope = scope;
            ScopeId = scopeId;
            Controller = controller;
        }

        public string Key { get; }
        public string PackageId { get; }
        public ManifestControllerScope Scope { get; }
        public string ScopeId { get; }
        public ManifestControllerBase Controller { get; }
        public int ReferenceCount { get; set; }
        public bool ReleaseWhenUnused { get; set; }
    }

    private sealed class LoadedTranslations
    {
        public LoadedTranslations(
            ManifestUiCatalogEntry entry,
            long catalogRevision,
            string domain,
            IReadOnlyList<Translation> translations)
        {
            Entry = entry;
            CatalogRevision = catalogRevision;
            Domain = domain;
            Translations = translations;
        }

        public ManifestUiCatalogEntry Entry { get; }
        public long CatalogRevision { get; }
        public string Domain { get; }
        public IReadOnlyList<Translation> Translations { get; }
    }

    private sealed record LoadedScene(
        ManifestUiCatalogEntry Entry,
        long CatalogRevision,
        PackedScene Scene);

    private sealed record PendingSceneLoad(
        ManifestUiCatalogEntry Entry,
        long CatalogRevision,
        Task<PackedScene> Task);

    private sealed record PendingTranslationLoad(
        ManifestUiCatalogEntry Entry,
        long CatalogRevision,
        Task Task);
}

# Manifest UI Runtime API

The runtime is catalog-driven: application code registers generated package
entries, then opens packages by `packageId`. Scene paths stay in generated
catalog code rather than business logic.

## Bootstrap

Enabling the editor plugin manages three autoloads:
`ManifestMessageBus`, `ManifestUiRoot`, and `ManifestUiManager`. It reports a
conflict instead of replacing an unrelated autoload with the same name.

Register generated catalogs and services before opening a package:

```csharp
using GodotUi.Manifest;
using Game.Ui.Generated.Inventory;

var manager = ManifestUiManager.Instance
    ?? throw new InvalidOperationException("Manifest UI autoload is missing.");

manager.Services.Register<IInventoryService>(inventoryService, "player");
InventoryWidgetManifestCatalog.Register(manager);

var handle = await manager.OpenAsync("game.inventory");
```

Catalog registration fails on duplicate package ids unless `replace: true` is
explicitly supplied.

## Lifecycle

```csharp
Task PreloadAsync(StringName packageId, CancellationToken ct = default);
Task<ManifestUiHandle> OpenAsync(
    StringName packageId,
    ManifestUiOpenOptions? options = null,
    CancellationToken ct = default);
Task ShowAsync(ManifestUiHandle handle, CancellationToken ct = default);
Task HideAsync(ManifestUiHandle handle, CancellationToken ct = default);
Task CloseAsync(
    ManifestUiHandle handle,
    ManifestUiCloseReason reason,
    CancellationToken ct = default);
Task ReleaseAsync(StringName packageId, bool closeInstances = false);
```

- `PreloadAsync` retains the `PackedScene` and package translations.
- `OpenAsync` loads, instantiates, attaches a Controller, and returns a handle.
- `HideAsync` keeps the Widget, Controller, and Store alive.
- `ShowAsync` restores a hidden Widget and applies missed Store revisions.
- `CloseAsync` detaches and destroys one instance, then runs close callbacks.
- `ReleaseAsync` releases retained package resources. With
  `closeInstances: true`, it closes live instances first.

Godot scene instantiation and SceneTree changes run on the main thread.
Resource loading uses Godot's threaded loader. Call lifecycle methods from the
main thread; cancellation cancels the caller's wait and does not make SceneTree
operations thread-safe.

## Handles and states

`ManifestUiHandle` exposes stable `InstanceId`, `PackageId`, `State`, and the
snapshotted `Options`. `Widget` and `Controller` are available while the
instance is live and become `null` after close so the handle does not retain
freed Godot objects.

States are `Loading`, `Open`, `Hidden`, `Closing`, `Closed`, and `Failed`.
`Reuse` callers for the same reuse key share an in-flight load. `Replace`
invalidates older generations so an obsolete request cannot commit after its
replacement.

Do not cache only the Widget node when lifecycle decisions matter. Keep the
handle and check its state, especially when an owner may call `QueueFree()`.

## Open options

`ManifestUiOpenOptions` includes:

| Option | Meaning |
|---|---|
| `LayerId` | Target Manifest UI layer; defaults to `Main` |
| `ScreenId` | Scope identity used for screen-scoped Controllers |
| `ReuseKey` | Additional identity for `Reuse` and `Replace` |
| `Mode` | `Reuse`, `Replace`, or `Stack` |
| `ControllerScope` | Optional override of the catalog scope |
| `IsModal` | Add blocker and modal-stack behavior |
| `GrabFocus` | Focus the first eligible descendant |
| `RestoreFocusOnClose` | Restore the previous valid focus owner |
| `PauseTree` | Acquire a reference-counted pause request |
| `TrapFocus` | Keep keyboard or controller focus inside the top modal |
| `CancelPolicy` | Ignore, close the top modal, or invoke `OnCancel` |
| `OnClosed` | Legacy Widget callback |
| `OnHandleClosed` | Handle-aware close callback |

Use `Stack` for independent modal instances. Use `Reuse` for a logical screen
that should return its current handle. `Replace` closes matching instances and
opens the new generation.

User callbacks are isolated by runtime diagnostics: one failing callback does
not prevent cleanup or focus restoration.

## Controller scopes

- `Instance`: one Controller and Store per opened instance. This is the
  recommended default for new packages.
- `Screen`: share by package and `ScreenId`/reuse identity.
- `Package`: share one Controller and Store across package instances.

Schema v1 packages without `runtime.controllerScope` retain legacy `Package`
behavior. Shared Stores use revision cursors per Widget, so one Widget applying
a revision does not clear updates for another.

Controllers receive a `ManifestControllerContext` with the manager, package id,
scope information, service registry, and message bus. Keep business state and
dependencies in Controllers rather than generated Widgets.

## Store and updates

`ViewModelStore` supports typed and untyped `Set`, `Invalidate`, `BeginBatch`,
revision queries, and read cursors:

```csharp
using (Store.BeginBatch())
{
    Store.Set("playerName", player.Name);
    Store.Set("health", player.Health);
}

Store.Invalidate("health");
```

`BeginBatch` emits one revision for related changes. A field fallback is
applied on first display even if the Store has never held that field.

`manual` packages call the protected Controller `Flush()` after related Store
updates. `immediate` packages flush synchronously on Store change. `deferred`
packages coalesce changes through a deferred call. Hidden Widgets catch up on
`ShowAsync`.

Store subscribers are isolated: a subscriber exception emits `MUIR1001` and
does not prevent remaining subscribers from running.

## Services

The manager owns a generic, optionally keyed registry:

```csharp
manager.Services.Register<IAudioService>(audio);
manager.Services.Register<IInventoryService>(inventory, "player");

var audio = manager.Services.Resolve<IAudioService>();
manager.Services.TryResolve<IInventoryService>(out var inventory, "player");
```

Declare required Controller dependencies in `codegen.json`. Generation creates
typed accessors that call `Context.RequireService<T>(key)`. Missing services
fail explicitly; register them before `OpenAsync`.

## Message bus

An envelope contains a channel, event id, Godot `Variant` payload, scope,
scope id, sender, and immediate/deferred delivery:

```csharp
var subscription = ManifestMessageBus.Instance!.SubscribeEnvelope(
    "inventory.changed",
    envelope => Refresh(envelope.Payload),
    ManifestMessageScope.Package,
    "game.inventory");

ManifestMessageBus.Instance.Publish(new ManifestMessageEnvelope(
    "inventory.changed",
    eventId: "refresh",
    payload: 3,
    scope: ManifestMessageScope.Package,
    scopeId: "game.inventory",
    sender: "inventory-controller",
    delivery: ManifestMessageDelivery.Deferred));
```

Dispose subscriptions. `ManifestControllerBase.SubscribeMessage` tracks
subscriptions and disposes them during teardown. A failing subscriber emits
`MUIR2001`; other subscribers still receive the envelope.

Generated catalog routes subscribe automatically when `Register` or
`RegisterCatalogEntry` is called. Route failures emit `MUIR2003` and do not
escape the bus callback. Use `UnregisterCatalogEntry` when removing a package
catalog at runtime so its route subscriptions are released immediately.

## Localization

When a package references `strings.json`, generation creates Godot Translation
resources and a package TranslationDomain. Catalog preload/open registers those
resources. Generated Widgets set their domain and reapply localized properties
on Godot's translation-change notification.

Keep translated copy in `strings.json`. A layout localization entry may be a
plain key or `{ "key", "context", "arguments" }`; argument entries are MVVM
field ids whose current Store values are applied with `string.Format` after
translation. Store revisions reapply parameterized copy when an argument field
changes.

## Legacy immediate API

The scene-path `Open` and synchronous `Close` overloads remain for migration
and are marked obsolete. They perform immediate legacy operations and should
not be used to wait for asynchronous loading or frame processing. They are
scheduled for removal in Manifest UI 2.0.

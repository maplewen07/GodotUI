# 2026-07-03 Runtime Lifecycle Upgrade

- Task: complete Matrix-style runtime lifecycle for the Godot C# manifest UI framework.
- Controller ownership: `ManifestUiManager` now caches controllers by package id; generated widgets expose `PackageId` and obtain controllers through the manager.
- Widget lifecycle: `ManifestGeneratedWidget` attaches on `_Ready()` and detaches on `_ExitTree()`, so external `QueueFree()` does not leave stale controller widget references.
- Controller lifecycle: `ManifestControllerBase` owns a shared `ViewModelStore`, tracks active widgets, supports setup/teardown, closes active widgets through the manager, and disposes stored message-bus subscriptions.
- Message bus: `Subscribe()` now returns an `IDisposable` handle while keeping ignored-return old call sites valid.
- UI root: `ManifestUiRoot` now owns layer containers, stack bookkeeping, modal tracking, focus restore, and optional tree pause.
- Open/close policy: added `ManifestUiOpenOptions`, `ManifestUiOpenMode` (`Reuse`, `Replace`, `Stack`), and `ManifestUiCloseReason`.
- Sample/test: `PhoneController` uses `OnWidgetOpened`; `SelfCheck` covers subscription dispose, reuse, replace, shared store reopen, detach cleanup, and focus restore.
- Verified:
  - `dotnet build tools\ManifestUiGen\ManifestUiGen.csproj`
  - `dotnet run --no-build --project tools\ManifestUiGen -- validate ui\phone\package.json --write-report`
  - `dotnet run --no-build --project tools\ManifestUiGen -- generate ui\phone\package.json`
  - `dotnet build GodotUI.csproj`
  - `godot --headless --path . --scene res://tests/SelfCheck.tscn`
  - `godot --headless --path . --scene res://demo/Main.tscn --quit-after 5`
- Skipped: no EditorPlugin, animation transitions, or complex input-mode integration.

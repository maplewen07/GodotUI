# Migration and Upgrade Guide

Upgrade the addon and CLI as one versioned toolchain. Generated output embeds
the tool version and must be regenerated after an upgrade.

## Before upgrading

1. Commit or back up package JSON, Controllers, services, and Widget partials.
2. Run `manifest-ui validate` and record existing diagnostics.
3. Confirm which files are managed in each `.manifest-ui.generated.json`.
4. Read the target release notes and `CHANGELOG.md`.

Do not merge two addon versions file by file.

## Replace and check

1. Disable Manifest UI in Godot so its owned autoloads are removed cleanly.
2. Replace the complete `addons/manifest_ui/` directory with the release ZIP.
3. Replace the portable CLI with the matching release version.
4. Build the C# project and re-enable the plugin.
5. Run the migration and schema checks.

```powershell
manifest-ui migrate --check ui/inventory/package.json
manifest-ui schema check --project .
manifest-ui validate ui/inventory/package.json
```

`migrate --check` is read-only. The 1.0 alpha tooling supports schema version 1
only; it reports older or newer versions instead of guessing a rewrite.

## Schema v1 compatibility

Existing schema v1 packages remain valid when new optional fields are absent.
Important legacy behavior:

- Missing `runtime.controllerScope` maps to `package`.
- New packages should explicitly use `instance` unless shared state is needed.
- `strings`, `requiredServices`, `routes`, and layout localization are optional.
- `contentHash` is optional, but any present value is verified strictly.
- `generator: "ManifestUiGen"` remains accepted; new packages should use
  `generator: "ManifestUi"`.

Unknown fields now produce stable diagnostics. If an older tool ignored a
field, either remove it or move its behavior into supported Controller code;
do not assume it has runtime effect.

## Regenerate safely

Run normal generation before drift verification:

```powershell
manifest-ui generate ui/inventory/package.json
manifest-ui generate ui/inventory/package.json --check
manifest-ui verify ui/inventory/package.json
```

Managed `.g.cs`, `.tscn`, `.tres`, and index files may change. The user Widget
partial is created only when absent and must retain local edits. Controller and
service code outside managed output is never a generation target.

Use `--clean` only after reviewing the old managed index. It cannot delete
unindexed or out-of-directory files.

## Moving from scene-path calls

Legacy code may call synchronous `Open(screenId, scenePath, options)` and
`Close`. Migrate by registering the generated catalog and retaining handles:

```csharp
SettingsWidgetManifestCatalog.Register(manager);
var handle = await manager.OpenAsync("game.settings", options, cancellationToken);
await manager.HideAsync(handle, cancellationToken);
await manager.ShowAsync(handle, cancellationToken);
await manager.CloseAsync(handle, ManifestUiCloseReason.Programmatic, cancellationToken);
```

Do not block on async lifecycle Tasks from Godot's main thread. Propagate async
control flow instead.

## Moving shared Controller state

An undeclared v1 scope is package-wide. If instances were unintentionally
sharing state, add:

```json
"runtime": { "controllerScope": "instance" }
```

Then review every assumption about Store persistence, message scope, reuse
keys, and release. If sharing is intentional, keep `package` explicit.

## Release gate after migration

Run project-wide checks, the Godot engine verifier, runtime tests, and a clean
install test using only the final addon ZIP. CI should finish with
`git diff --exit-code` to prove verification did not rewrite tracked files.

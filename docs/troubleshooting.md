# Troubleshooting Manifest UI

Start with the environment check and the narrowest package command:

```powershell
manifest-ui doctor --project . --godot $env:GODOT_BIN
manifest-ui validate ui/inventory/package.json --format text
```

Do not generate through validation errors. The generator deliberately refuses
partial output.

## Doctor reports Godot is missing

Use the Godot 4.7 Mono console executable, not the standard editor build. Put
it on `PATH`, set `GODOT_BIN`, or pass `--godot <exe>`. The project C# file must
use `Godot.NET.Sdk/4.7.x` and target `net8.0`.

The executable path is machine-local and must not be committed to the repo.

## `MUI5003` says bundled schemas are missing

Keep the addon installation complete. The editor core expects
`addons/manifest_ui/tooling/schemas`; the portable CLI includes the same files
beside its assembly. Do not copy only the CLI executable or selected addon C#
files.

Optional package-local `schemas/` snapshots may be removed if they are not
needed. If kept, run `manifest-ui schema sync --project .` and commit the full
synchronized set.

## A path is rejected

Package references cannot escape the package directory. Generated output,
Theme output, `res://` scenes, and scripted controls must stay inside the Godot
project. Asset sources must stay below the package's `assets/` directory.

Use forward slashes in JSON and `res://` for Godot resources. Never solve a
path diagnostic by weakening validation.

## Validate succeeds but `generate --check` fails

`--check` is read-only and expects every managed file, the user Widget stub,
and `.manifest-ui.generated.json` to exist with current bytes. Run a normal
generation once:

```powershell
manifest-ui generate ui/inventory/package.json
manifest-ui generate ui/inventory/package.json --check
```

If drift returns immediately, check newline conversion, an external formatter,
or a tool/addon version mismatch. Managed output is UTF-8 with LF and should not
be formatted independently.

## `--clean` will not remove a file

This is intentional. Clean removes only stale files listed in the prior
`.manifest-ui.generated.json` and only inside `outputDir`. Handwritten partial
classes and unindexed files are user-owned. Review and delete those manually
only when the application no longer references them.

## Asset hash mismatch

First verify that the changed asset is expected. Then use:

```powershell
manifest-ui assets hash --write ui/inventory/package.json
manifest-ui assets hash --check ui/inventory/package.json
```

Do not add a fake hash or remove a lock merely to pass CI. `contentHash` may be
omitted during ordinary authoring, but it is strict once present.

## Binding reports an unknown target

Binding targets use node **names** relative to the generated root. For a tree
`Root/Content/SaveButton`, use `Content/SaveButton`, not the layout id and not
the root name. Repeater item targets are relative to the template.

Also check the property/control compatibility table in the
[schema reference](manifest-reference.md). Unsupported signals and properties
are diagnosed rather than silently ignored.

## The UI opens but values do not refresh

Check `mvvm.updatePolicy`:

- `manual` requires Controller code to call `Flush()`.
- `immediate` applies every visible Store change.
- `deferred` applies changes on a deferred callback.

Use `Store.Set` or `Invalidate`; mutating an object already stored without
invalidating its field creates no new revision. Group related changes in
`BeginBatch()`.

## A service cannot be resolved

Register the exact declared type and key on `ManifestUiManager.Services` before
opening the package. A service registered as its concrete class does not
automatically satisfy an accessor generated for an interface.

When `requiredServices` is non-empty, the handwritten Controller type must be
`partial` so the generated accessor declaration can join it.

## Localized text shows the key

Confirm that `package.json` references `strings.json`, every key has the default
locale, the locale is declared, and generation created translation `.tres`
files. Register/open through the generated catalog so package translations are
loaded and the TranslationDomain is known.

Use localization for supported Widget properties, normally `text`. A dynamic
value should be a Store binding rather than a changing entry in `strings.json`.

## Preview is disabled or blank

Generate and Verify first. Preview only accepts a current generated scene.
Normal Preview suppresses Controller setup; therefore Store-driven values may
show binding fallbacks. Use Run Preview only when executing Controller logic is
intentional.

`designResolution` determines the preview viewport. Fix a zero/invalid size in
`package.json` rather than resizing generated scenes.

## The plugin reports an autoload conflict

Manifest UI never replaces an unrelated autoload named `ManifestMessageBus`,
`ManifestUiRoot`, or `ManifestUiManager`. Rename the application autoload or
remove the stale entry after confirming ownership, then enable the plugin
again. Disabling the plugin removes only entries it recorded as owned.

## A modal leaves pause or focus in the wrong state

Close modals through their `ManifestUiHandle`. Avoid freeing modal descendants
directly. The runtime cleans up externally freed roots, but explicit lifecycle
calls preserve the clearest close reason and callback ordering.

Inspect `MUIR5xxx` and `MUIR6xxx` diagnostics. User callback exceptions are
isolated, so the first visible symptom may be a diagnostic rather than a crash.

## Godot reports one leaked RefCounted after async loading

See [Known issues](known-issues.md). The release test isolates the current Godot
4.7 threaded ResourceLoader signature from plugin-owned lifecycle leaks. Do not
silence additional leaked instances or replace threaded loading with a blocking
load on the main thread.

## Reporting a defect

Include the addon and CLI versions, Godot version, command, exit code,
structured diagnostics, the smallest source manifest that reproduces the
problem, and whether a second `generate --check` drifts. Do not include private
assets or credentials.

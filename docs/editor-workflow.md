# Manifest UI Editor Workflow

Enable Manifest UI under **Project > Project Settings > Plugins** after the C#
project builds. The plugin adds a Manifest UI dock and manages its owned
autoloads.

## Source roots

The default source root is `res://ui`. Open **Settings** in the dock to provide
multiple semicolon-separated roots, for example:

```text
res://ui;res://game/ui;res://dlc/ui
```

Discovery is recursive and excludes generated output, addons, tests, `.godot`,
and `.git`. The generated root defaults to `res://generated/ui`.

Keep one package per directory and avoid nesting generated output below a
source root where other tools might mistake it for authoring source.

## Create a package

Select **New**, enter a package id and display name, and confirm. The wizard
creates schema version 1 source files below the first configured source root.
New packages explicitly use instance-scoped Controllers.

After creation:

1. Define the layout tree and stable ids/names.
2. Add Store fields before referencing them in bindings.
3. Add inputs, events, and repeaters.
4. Add static copy to `strings.json` when localization is required.
5. Implement the fully qualified Controller class.
6. Validate before generating.

## Dock actions

| Action | Result |
|---|---|
| **Refresh** | Rediscover packages in all source roots |
| **New** | Open the schema v1 package wizard |
| **Doctor** | Check project, SDK, and configured Godot environment |
| **Validate** | Run in-process validation and write the package report |
| **Generate** | Commit the deterministic generation plan |
| **Export JSON** | Reconcile a saved generated TSCN into layout/assets/strings source JSON, then validate without regenerating |
| **Verify** | Check managed drift and instantiate/inspect the generated PackedScene |
| **Preview** | Show verified output without running its Controller |
| **Run Preview** | Show verified output with normal runtime behavior |
| **Check All** | Validate every discovered package |
| **Report** | Open the last generated validation report |
| **Reimport** | Ask Godot to rescan changed source/generated resources |
| **Install Skill** | Install the bundled `godot-manifest-ui` Codex Skill |
| **Cancel** | Ignore the result of the active dock operation when it completes |

The dock calls the shared tooling core directly and renders structured
diagnostics. Selecting a diagnostic opens its source file where possible.

The current tooling work itself is synchronous inside the background task;
Cancel prevents the result from being applied to the dock but does not attempt
an unsafe mid-write interruption.

## Verify

Verify first checks source and managed-output drift. The editor engine verifier
then loads and instantiates the generated `PackedScene` and checks its root,
node paths, binding targets, input targets, event targets, repeater template,
resources, Theme, and catalog-facing scene metadata.

CLI `verify` performs portable generated-scene checks. The editor verifier is
the stronger Godot-engine check and should be part of release review.

## Preview modes

Preview is enabled only after generation and verification succeed.

- **Preview** marks the instance as an editor preview and suppresses Controller
  setup and UI event dispatch. Binding fallbacks and static layout are safe to
  inspect.
- **Run Preview** uses the runtime path and may call services, subscribe to
  messages, mutate Store state, or open other packages.

The preview viewport uses `designResolution`. Preview is an inspection tool,
not a substitute for testing multiple real window sizes and input devices.

## Autoload ownership

On enable, the plugin adds `ManifestMessageBus`, `ManifestUiRoot`, and
`ManifestUiManager` only when their names are free. It records ownership in
project settings. On disable, it removes only matching entries it owns.

A same-name entry with a different path is an error. Resolve it explicitly;
the plugin will not overwrite or later remove user configuration.

## Recommended review loop

```text
Edit source -> Validate -> Generate -> Verify -> Preview/Run Preview
            -> generate --check -> project tests
```

For visual editing, use `Generate -> edit and save TSCN -> Export JSON ->
Validate -> Generate`. Export blocks unsupported scene-only data rather than
silently dropping it. Generated `.g.cs` files remain read-only.

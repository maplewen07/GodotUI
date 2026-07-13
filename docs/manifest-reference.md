# Manifest UI Schema Version 1

A Manifest UI package is a directory containing `package.json` and the source
files it references. Source JSON is canonical. Generated C#, scenes,
translations, themes, reports, and indexes are derived artifacts.

The examples below describe the contract implemented by the 1.0 alpha tooling.
Unknown fields are errors rather than being silently ignored.

## Package Files

| File | Required | Purpose |
|---|---:|---|
| `package.json` | yes | Package identity, source references, runtime scope, and Godot output |
| `layout.json` | yes | Godot Control tree and static properties |
| `bindings.json` | yes | Store fields, bindings, inputs, repeaters, and events |
| `assets.json` | yes | Texture, font, and Theme inputs |
| `codegen.json` | yes | Generator version, service accessors, and route descriptors |
| `validation.json` | yes | Input allowlist and project-specific check metadata |
| `strings.json` | no | Package-local translations |
| `schemas/*.schema.json` | no | Optional synchronized schema snapshots |

All paths in a package source file are resolved relative to the package unless
the field explicitly uses a Godot `res://` path. Output paths must stay within
the Godot project.

## `package.json`

```json
{
  "schemaVersion": 1,
  "packageId": "example.settings",
  "displayName": "Settings",
  "designResolution": [1280, 720],
  "assets": "assets.json",
  "layout": "layout.json",
  "bindings": "bindings.json",
  "codegen": "codegen.json",
  "validation": "validation.json",
  "strings": "strings.json",
  "runtime": {
    "controllerScope": "instance"
  },
  "godot": {
    "systemName": "settings",
    "widgetClass": "SettingsWidget",
    "controllerClass": "Game.Ui.Settings.SettingsController",
    "namespace": "Game.Ui.Generated.Settings",
    "outputDir": "generated/ui/settings",
    "scenePath": "res://generated/ui/settings/SettingsWidget.tscn"
  }
}
```

`schemaVersion` must be `1`. `packageId` is the runtime catalog key and should
be stable. `designResolution` controls the editor preview viewport.

`runtime.controllerScope` accepts `instance`, `screen`, or `package`. New
packages should normally declare `instance`. A schema v1 package that omits
`runtime` preserves the legacy `package` scope.

`godot.controllerClass` must be a fully qualified C# type. `scenePath` must
exactly match `<outputDir>/<widgetClass>.tscn` as a `res://` path.
`systemName`, `namespace`, and `outputDir` have deterministic defaults, but
declaring them makes public packages easier to review.

## `layout.json`

The root and every descendant require unique `id`, `type`, and `name` values.
Binding paths use node names relative to the generated root, not ids.

```json
{
  "root": {
    "id": "SettingsWidget",
    "type": "Control",
    "name": "SettingsWidget",
    "properties": {
      "anchors_preset": 15,
      "anchor_right": 1.0,
      "anchor_bottom": 1.0
    },
    "children": [
      {
        "id": "Title",
        "type": "Label",
        "name": "Title",
        "localization": {
          "text": {
            "key": "settings.item_count",
            "context": "settings",
            "arguments": ["itemCount"]
          }
        }
      }
    ]
  }
}
```

Property values emit strings, numbers, booleans, two-number arrays (as
`Vector2`), and declared asset references. Common typed UI values use
`{ "color": [r, g, b, a] }`, `{ "nodePath": "Panel/Button" }`, and
`{ "vector2i": [x, y] }`. Use Godot's serialized property names, such as
`custom_minimum_size`, `offset_left`, or `placeholder_text`. The object form
`{ "assetRef": "asset_id" }` emits an `ExtResource` and may reference a
declared texture, font, theme, or generic resource asset.

Special node forms:

- `type: "SceneInstance"` requires `scenePath` pointing to an existing
  `res://...tscn`. The referenced scene is instantiated in the generated scene.
- A non-root `type: "Control"` may set `scriptPath` to an existing
  `res://...cs` or `res://...gd`. This is the scripted-control extension point.
  Scripted controls may use the canonical properties, inputs, and events below;
  their exported properties and signals are confirmed by engine Verify.
- C# exported layout properties use Godot Source Generator engine names such
  as `Text`, `Value`, or `Style`. GDScript properties keep their declared
  names. Canonical binding and event names remain language-neutral; generated
  C# signal connections map `pressed` to `Pressed`, `value_changed` to
  `ValueChanged`, and so on.
- `localization` maps a serialized property either to a key string or to
  `{ "key", "context", "arguments" }`. `arguments` contains MVVM field ids;
  their Store values fill `{0}`, `{1}`, and later placeholders after
  translation. Localized properties should use supported binding targets,
  most commonly `text` on `Label`, `Button`, or `RichTextLabel`.

## `bindings.json`

### Store fields and update policy

```json
{
  "mvvm": {
    "updatePolicy": "immediate",
    "fields": [
      {
        "id": "displayName",
        "path": "UI.Settings.DisplayName",
        "value": "text",
        "collection": "none"
      }
    ]
  },
  "bindings": {},
  "controls": [],
  "events": { "channels": [] }
}
```

`value` accepts `text`, `bool`, `number`, `assetRef`, or `object`.
`collection` defaults to `none`; repeaters require a non-`none` value such as
`list`. Field `path` is authoring metadata; generated runtime bindings address
the field by `id`.

Update policies:

- `manual`: Store changes are applied when Controller code calls `Flush()` or
  the Widget is first shown.
- `immediate`: each Store revision flushes visible Widgets immediately.
- `deferred`: visible Widgets coalesce changes into a deferred flush.

Hidden Widgets retain Store revisions and catch up when shown again.

### Property bindings

A key has the form `<node-path>.<property>`. A short value binds directly; the
object form adds a converter, format string, or fallback.

```json
{
  "bindings": {
    "Content/Name.text": "viewmodel:displayName",
    "Content/Count.text": {
      "source": "viewmodel:itemCount",
      "converter": "number",
      "format": "{0} items",
      "fallback": 0
    }
  }
}
```

Supported generated properties are:

| Property | Compatible controls |
|---|---|
| `text` | `Label`, `Button`, `LineEdit`, `RichTextLabel` |
| `visible` or legacy alias `visibility` | any `Control` |
| `enabled` | buttons, options, menus, `LineEdit`, `TextEdit` |
| `value` | `ProgressBar`, sliders, `SpinBox`, `TextureProgressBar` |
| `texture` | `TextureRect`, `TextureButton`, `Button` icon |
| `themeClass` | any `Control` (`ThemeTypeVariation`) |

Converters are `string`, `bool`, `number`, `not`, `isNotEmpty`, and `texture`.
The fallback is used on first display when the Store has no value.
Scripted controls may use these same canonical properties even though their
layout base type is `Control`; arbitrary custom binding properties remain
unsupported.

### Inputs

Inputs copy a control signal value into the Store and then invoke the
Controller's input callback.

| Input property | Compatible controls |
|---|---|
| `text` | `LineEdit`, `TextEdit` |
| `buttonPressed` | `CheckBox`, `CheckButton` |
| `value` | progress controls, sliders, `SpinBox` |
| `selected` | `OptionButton` |

Scripted controls may use any of these four canonical input contracts. Engine
Verify confirms that the corresponding signal and exported property exist.

```json
{
  "inputs": [
    {
      "id": "nameInput",
      "target": "Content/NameInput",
      "property": "text",
      "source": "viewmodel:displayName"
    }
  ]
}
```

### Events and channels

Declare channels before controls reference them. Supported signals are
`pressed`, `text_changed`, `toggled`, `value_changed`, `item_selected`, and
`tab_changed` on compatible Godot controls.
Scripted controls may also name a custom zero-argument signal; CLI validation
defers signal existence to engine Verify. Event payloads remain unsupported in
schema v1.

```json
{
  "controls": [
    {
      "id": "SaveButton",
      "target": "Content/SaveButton",
      "widgetClass": "Button",
      "events": [
        {
          "event": "pressed",
          "handler": "save_settings",
          "channel": "settings.save"
        }
      ]
    }
  ],
  "events": {
    "channels": [
      {
        "id": "settings.save",
        "scope": "settings",
        "dispatch": "immediate",
        "payload": []
      }
    ]
  }
}
```

The generated handler calls `Controller.DispatchEvent(handler)` and publishes
an envelope on the channel. `scope` is the package message scope id and
`dispatch` accepts `immediate` or `deferred`. Schema v1 supports an empty
`payload` array and publishes an empty `Variant`; declared payload fields fail
validation until their mapping semantics are defined.

### Repeaters

A repeater duplicates a template below its target and binds values from each
item. The template must be a descendant of the target.

```json
{
  "repeaters": [
    {
      "id": "rows",
      "target": "Content/Rows",
      "template": "Content/Rows/RowTemplate",
      "source": "viewmodel:items",
      "keyFieldId": "id",
      "poolCapacity": 32,
      "bindings": {
        "Name.text": "item:name",
        "Quantity.text": {
          "source": "item:quantity",
          "format": "x{0}",
          "fallback": 0
        }
      }
    }
  ]
}
```

The runtime uses `keyFieldId` for keyed diffing and reuses removed controls
through an object pool. If `keyFieldId` is omitted, it looks for an item field
named `id`, then falls back to list position. `poolCapacity` defaults to `32`
and may be `0` to disable retained pooled instances. Viewport virtualization is
not provided.

## `assets.json`

```json
{
  "assets": [
    {
      "id": "settings_icon",
      "relativePath": "assets/settings.svg",
      "kind": "texture",
      "contentHash": "sha256:0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    }
  ]
}
```

Asset paths must stay below the package's `assets/` directory. Kinds and
accepted extensions are:

- `texture`: `.png`, `.jpg`, `.jpeg`, `.webp`, `.svg`, `.tres`
- `font`: `.ttf`, `.otf`, `.tres`
- `theme`: `.json`, `.tres`
- `resource`: `.tres`, `.res`

`contentHash` is optional during normal authoring. When present, it is strict.
Use `manifest-ui assets hash --check|--write <package>` rather than editing
hashes by hand. A Theme asset may declare an output `.tres`, a default font,
default font size, and type variations.

## `strings.json`

```json
{
  "schemaVersion": 1,
  "defaultLocale": "en",
  "locales": ["en", "zh_CN"],
  "strings": {
    "settings.title": {
      "en": "Settings",
      "zh_CN": "设置"
    }
  }
}
```

Every key must include the default locale. Translation locales not listed in
`locales` are errors. Generation writes one Godot `Translation` resource per
locale and registers a package TranslationDomain through the generated catalog.

## `codegen.json`

```json
{
  "schemaVersion": 1,
  "generator": "ManifestUi",
  "requiredServices": [
    {
      "type": "Game.Inventory.IInventoryService",
      "property": "InventoryService",
      "key": "player"
    }
  ],
  "routes": [
    {
      "channel": "menu.open_settings",
      "action": "open",
      "packageId": "example.settings"
    }
  ]
}
```

`requiredServices` generates a partial Controller accessor that resolves the
type and optional key from `ManifestServiceRegistry`. The handwritten
Controller declaration must be `partial` when service accessors are generated.

Routes accept `open` or `close`; `open` requires `packageId`. Registering the
generated catalog entry installs scoped lifecycle subscriptions on the runtime
MessageBus. `open` uses the normal Reuse behavior. `close` closes all handles
for its target package; when its `packageId` is omitted, it targets the catalog
entry that owns the route. Replacing or unregistering the entry disposes the
old subscriptions.

## `validation.json`

`commandletInputWhitelist` must list every source filename referenced by
`package.json`, including optional `strings.json`. Schema v1 accepts
`"manifestValidation": true`, which records the mandatory base validation
already performed by every package command. Other check names, non-boolean
values, and attempts to set it to `false` fail with a stable unsupported
diagnostic; CI-only gates must stay in CI configuration until tooling core can
execute them.

## Generated Ownership

Generation builds and validates an in-memory plan before writing. Managed files
include `.g.cs`, `.tscn`, generated `.tres`, and
`.manifest-ui.generated.json`. The initial `<Widget>.cs` partial is created only
when absent and is never overwritten.

`generate --clean` may delete only files named in the prior managed index and
only while they remain inside `outputDir`. Output uses UTF-8, LF, stable
ordering, and deterministic content. Use `generate --check` in CI to detect
missing or drifted generated files.

Editor callers may pass a `CancellationToken` to tooling core. Cancellation is
observed during discovery, validation, planning, and transaction staging. The
final commit is deliberately non-cancelable: once it starts, all managed
writes finish or roll back before the command returns.

## Exporting Scene Edits

`export-scene` is the explicit reconciliation path for a generated TSCN that
was edited in Godot. It updates `layout.json`, incrementally registers new
package-local resources in `assets.json`, and updates the default locale for
existing localized properties in `strings.json`. Bindings, codegen, validation,
and package configuration remain source-owned and are validated after export.

The exporter reads Godot `PackedScene` state and rejects data the manifest
schema cannot preserve, including signal connections, node groups, built-in
SubResources, complex Variant values, and scene-instance overrides. All source
files are restored if package validation fails. Export does not run Generate.

Generated nodes contain `metadata/_manifest_ui_id` so renames and moves retain
their manifest ids. Generate once before starting a scene-edit workflow when
working with scenes created by an older generator.

## CLI Contract

```text
manifest-ui doctor --project <dir> [--godot <exe>]
manifest-ui validate <package> [--project <dir>] [--format text|json|sarif] [--write-report]
manifest-ui generate <package> [--project <dir>] [--check] [--clean]
manifest-ui export-scene <package> [--project <dir>] [--godot <exe>]
manifest-ui verify <package> [--project <dir>]
manifest-ui check --project <dir> [--release]
manifest-ui migrate --check <package>
manifest-ui schema sync|check [--project <dir>]
manifest-ui assets hash --check|--write <package> [--project <dir>]
```

Exit codes are `0` success, `1` validation or drift failure, `2` usage or
environment failure, and `3` internal failure.

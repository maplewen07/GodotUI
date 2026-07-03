# GodotUI Manifest C# V1

Minimal Godot 4.6 Mono/C# UI framework based on a manifest-driven flow:

`Model / Service -> Controller -> ViewModelStore -> Widget / Scene`

## Generate

```powershell
dotnet run --project tools\ManifestUiGen -- validate ui\phone\package.json --write-report
dotnet run --project tools\ManifestUiGen -- migrate --check ui\phone\package.json
dotnet run --project tools\ManifestUiGen -- generate ui\phone\package.json
```

## Verify

```powershell
dotnet build GodotUI.csproj
godot --headless --build-solutions --quit
godot --headless --path . --scene res://tests/SelfCheck.tscn
godot --headless --path . --scene res://demo/Main.tscn --quit-after 5
```

Current scope skips visual designer import, localization, complex controls, atlas generation, compression policy, and platform overrides.

`package.json` is the canonical entrypoint. It references split manifest files and Godot output settings:

- `assets.json`
- `layout.json`
- `bindings.json`
- `codegen.json`
- `validation.json`
- `godot.outputDir`, `godot.widgetClass`, `godot.controllerClass`

Schema snapshots live in `schemas/manifest-ui/` and `ui/<system>/schemas/`; validation is implemented in C#.

For `schemaVersion: 1`, `bindings.json` is canonical-only: generated widget code reads `mvvm.fields`, `bindings`, `controls`, and `events.channels`. Legacy top-level `fields` and array-form `events` fail validation.

## Runtime Lifecycle

```csharp
ManifestUiManager.Instance?.Open("phone", "res://generated/ui/phone/PhoneWidget.tscn");

ManifestUiManager.Instance?.Open("phone", "res://generated/ui/phone/PhoneWidget.tscn", new ManifestUiOpenOptions
{
    Mode = ManifestUiOpenMode.Replace,
    LayerId = "Modal",
    IsModal = true,
    GrabFocus = true,
    RestoreFocusOnClose = true,
});

ManifestUiManager.Instance?.Close("phone");
```

`ManifestUiManager` owns controllers by package id. Widgets attach/detach on tree enter/exit, controllers own the shared `ViewModelStore`, and message bus subscriptions can be disposed or stored by controllers for teardown.

## Plugin And Bindings

Enable `addons/manifest_ui/plugin.cfg` in Godot to install the Manifest UI autoloads and open the Manifest UI dock. The dock scans `ui/*/package.json`, lets you pick a package, and runs the existing C# generator for `Validate`, `Validate Report`, and `Generate`.

The dock shows a status line, parsed diagnostics, and raw generator output. Diagnostics are parsed from `ERROR:` and `WARN:` CLI lines; selecting one navigates the FileSystem dock to the manifest file and shows the logical manifest path in the status line. `Validate Report` writes `ui/<system>/export/manifest_report.md`, and `Open Report` selects it when present. `Generate` refreshes Godot's editor filesystem after a successful run.

`Import Assets` refreshes Godot's editor filesystem and reimports the selected package's `ui/<system>/assets/` files. If the package has no assets directory or no importable files, the dock reports that explicitly.

Bindings are applied by the runtime plugin, not by per-widget generated setters:

```json
{
  "Panel/Content/TitleLabel.text": "viewmodel:title",
  "Panel/Content/CountLabel.text": {
    "source": "viewmodel:contactCount",
    "converter": "number",
    "format": "Contacts opened {0} time(s)"
  }
}
```

Supported properties are `text`, `visible`/`visibility`, `enabled`, `value`, `texture`, and `themeClass`.

```csharp
ManifestBindingConverters.Register("upper", value => value?.ToString()?.ToUpperInvariant() ?? "");
```

## Complex UI

V1 supports the small set needed for real screens without adding a full UI router:

- `repeaters[]` rebuilds a list from a collection field using a hidden template child.
- `inputs[]` writes common input signals back into `ViewModelStore` and calls `ManifestControllerBase.OnInputChanged`.
- `SceneInstance` layout nodes instance an existing `.tscn`; generated child widgets attach to their own manager-owned controller.
- `controls[].events[]` supports `pressed`, `text_changed`, `toggled`, `value_changed`, `item_selected`, and `tab_changed`.

```json
{
  "repeaters": [
    {
      "id": "contactsRepeater",
      "target": "Panel/Content/Tabs/ContactsTab/ContactsList",
      "template": "Panel/Content/Tabs/ContactsTab/ContactsList/ContactItemTemplate",
      "source": "viewmodel:contacts",
      "bindings": {
        "NameLabel.text": "item:name",
        "PhoneLabel.text": "item:phone"
      }
    }
  ],
  "inputs": [
    {
      "id": "searchInput",
      "target": "Panel/Content/SearchInput",
      "property": "text",
      "source": "viewmodel:searchText"
    }
  ]
}
```

Repeaters intentionally use full rebuild, not keyed diff or virtualization. Add that only when list size makes it measurable.

## Assets

`assets.json` declares package-local resources. Source assets must stay under `ui/<system>/assets/`; generated metadata maps each id to a stable `res://ui/<system>/assets/...` path. The generator validates path containment, `sha256:` hashes, file existence, and kind/extension compatibility.

Supported asset kinds are `texture`, `font`, and `theme`:

```json
{
  "assets": [
    {
      "id": "phone_icon",
      "relativePath": "assets/phone_icon.tres",
      "kind": "texture",
      "contentHash": "sha256:..."
    },
    {
      "id": "phone_font",
      "relativePath": "assets/phone_font.tres",
      "kind": "font",
      "contentHash": "sha256:...",
      "defaultFont": true,
      "defaultFontSize": 14
    },
    {
      "id": "phone_theme",
      "relativePath": "assets/phone_theme.json",
      "kind": "theme",
      "contentHash": "sha256:...",
      "theme": {
        "outputPath": "generated/ui/phone/assets/PhoneTheme.tres",
        "defaultFontAssetId": "phone_font",
        "defaultFontSize": 14,
        "typeVariations": [
          { "id": "PhonePanel", "baseType": "Panel" }
        ]
      }
    }
  ]
}
```

Generation does not copy source assets. It only writes derived theme resources such as `generated/ui/phone/assets/PhoneTheme.tres`. Generated widgets include a `ManifestAssetCatalog`; texture bindings can use an asset id fallback, and widgets apply the generated theme automatically.

`validate --write-report` emits `ui/<system>/export/manifest_report.md` and `godot_import_manifest.json`, including asset ids, kinds, source paths, `res://` paths, hashes, and theme outputs.

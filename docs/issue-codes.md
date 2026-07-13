# Manifest UI Issue Codes

Tooling diagnostics have the stable shape:

```text
code / severity / file / jsonPointer / line / column / message / hint
```

Line and column are best-effort source locations. `jsonPointer` is the stable
machine-readable location to use in editor integrations and CI. Text, JSON, and
SARIF output describe the same diagnostics.

## Tooling families

| Range | Area |
|---|---|
| `MUI1xxx` | JSON and schema shape |
| `MUI2xxx` | Semantic validation and authoring safety |
| `MUI3xxx` | Generation, managed output, or internal generation failure |
| `MUI4xxx` | Generated scene/engine verification |
| `MUI5xxx` | CLI usage and environment |

Current codes:

| Code | Meaning | Typical action |
|---|---|---|
| `MUI1001` | A JSON file could not be read | Fix syntax at the reported line and column |
| `MUI1002` | Required/schema-version shape error | Add the field or use schema version 1 |
| `MUI2000` | Semantic warning | Review the message; warnings do not set exit code 1 |
| `MUI2001` | General semantic error | Follow the JSON pointer and correct the manifest contract |
| `MUI2002` | Unsafe or invalid path/output boundary | Use package- or project-relative paths inside allowed roots |
| `MUI2201` | Binding, input, repeater, event, or channel error | Fix the target, field, property, converter, or signal |
| `MUI2301` | Asset declaration or asset-path error | Fix kind, extension, id, location, or Theme reference |
| `MUI2302` | Asset hash error | Run the explicit asset hash command after reviewing the asset |
| `MUI3000` | Unexpected internal tool exception | Reproduce with the same command and file an issue |
| `MUI3001` | Generation plan, drift, atomic commit, or managed-clean error | Validate, inspect generated ownership, then regenerate |
| `MUI4001` | Generated PackedScene verification error | Regenerate, import in Godot, and run Verify again |
| `MUI4005` | Generated root type or stale C# editor assembly | Confirm the generated script path; rebuild Debug and restart Godot when the attached script belongs to an earlier hot reload |
| `MUI4100` | TSCN export cannot preserve scene data or complete its atomic write | Remove unsupported scene-only data, register external resources, save the scene, and retry Export JSON |
| `MUI5001` | Missing/unknown command or invalid CLI usage | Run `manifest-ui --help` |
| `MUI5002` | Invalid output format | Use `text`, `json`, or `sarif` |
| `MUI5003` | Project, SDK, Godot, or schema environment error | Run Doctor and correct the reported prerequisite |
| `MUI5004` | Tooling operation canceled before commit | Retry when ready; no managed output was committed |

Several validation rules intentionally share a code. Automation should match
the code and JSON pointer, not parse the English message.

## Runtime codes

Runtime codes begin with `MUIR`. They are delivered through
`ManifestRuntimeDiagnostics.Emitted` and are also pushed to Godot's error or
warning output.

| Code | Meaning |
|---|---|
| `MUIR1001` | A `ViewModelStore` change subscriber threw |
| `MUIR2001` | A message-bus subscriber threw |
| `MUIR3001` | Controller failed while opening a Widget |
| `MUIR3002` | Controller failed while closing a Widget |
| `MUIR3003` | Controller teardown failed |
| `MUIR3004` | A tracked Controller subscription failed to dispose |
| `MUIR3005` | Controller event dispatch threw |
| `MUIR3006` | Controller input handling threw |
| `MUIR4001` | A localized format string was invalid |
| `MUIR4002` | A Widget failed to apply generated bindings |
| `MUIR5001` | Package open/load/instantiation failed |
| `MUIR5002` | Widget detach from the Manifest UI root failed |
| `MUIR5003` | A legacy close callback threw |
| `MUIR5004` | A handle close callback threw |
| `MUIR6001` | A modal cancel callback threw |

Subscriber and callback errors are isolated so cleanup and unrelated callbacks
can continue. Treat the diagnostic as a real defect even when the application
appears to recover.

## CI use

Use JSON for custom automation and SARIF for code-scanning ingestion:

```powershell
manifest-ui validate ui/inventory/package.json --format json
manifest-ui validate ui/inventory/package.json --format sarif > manifest-ui.sarif
```

Exit code `0` means success, `1` means validation or drift failure, `2` means
usage/environment failure, and `3` means an internal error.

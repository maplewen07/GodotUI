# Manifest UI Examples

This archive contains two original Godot 4.7 Mono projects:

- [Basic](Basic/README.md): localized static copy, Store fallbacks, immediate
  updates, text input, and a button event.
- [Inventory](Inventory/README.md): deferred updates, a pooled repeater, input
  filtering, and a keyed service resolved by a partial Controller.

The addon is intentionally not duplicated in the examples archive. For either
project, extract the matching `manifest-ui-<version>.zip` at that example's
root, then use the matching CLI release to validate and generate its package.
The archive uses .NET SDK 8.0.400 or a later .NET 8 patch accepted by
`global.json` and is distributed under the included MIT license.

From an example directory:

```powershell
manifest-ui doctor --project . --godot $env:GODOT_BIN
manifest-ui validate ui/<package>/package.json
manifest-ui generate ui/<package>/package.json
manifest-ui generate ui/<package>/package.json --check
manifest-ui verify ui/<package>/package.json
dotnet build
```

Open the example with Godot 4.7 Mono, confirm that Manifest UI is enabled under
**Project > Project Settings > Plugins**, and run `Main.tscn`.

The archive includes generated output from the matching release so the drift
and Verify commands work immediately. Do not hand-edit it. Package JSON and
handwritten C# files remain the canonical example source.

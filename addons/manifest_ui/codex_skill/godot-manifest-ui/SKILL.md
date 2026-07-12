---
name: godot-manifest-ui
description: Create, modify, validate, generate, and diagnose Godot Manifest UI packages for the GodotUI Manifest UI addon. Use when Codex works with package.json, layout.json, bindings.json, assets.json, codegen.json, validation.json, strings.json, generated Manifest UI scenes, controller partials, service adapters, bindings, events, repeaters, localization, or Manifest UI CLI diagnostics in a Godot 4.7 Mono project.
---

# Godot Manifest UI

Treat Source JSON as canonical. Treat generated scenes and generated C# as replaceable output. Keep business behavior in handwritten Controller partials and service adapters.

## Workflow

1. Locate `project.godot`, configured Manifest UI source roots, and the target `package.json`.
2. Read the package and every referenced manifest before editing. Read [references/schema-v1.md](references/schema-v1.md) when changing manifest shape.
3. Inspect existing Controllers and services before adding fields or events. Read [references/runtime.md](references/runtime.md) for lifecycle and service boundaries.
4. Edit Source JSON and handwritten code only. Never hand-edit `.g.cs`, generated `.tscn`, derived `.tres`, reports, or `.manifest-ui.generated.json`.
5. Run `scripts/quick_validate.py` for the package. Resolve errors by diagnostic code and JSON pointer.
6. Run generation only after validation succeeds. Run Verify after generation and ensure a second generate-check reports no drift.
7. Summarize Source changes, generated outputs, diagnostics, and verification results.

## Authoring Rules

- Preserve `schemaVersion: 1` and existing package conventions unless the user explicitly requests migration.
- Use stable ids. Do not rename fields, controls, channels, or package ids without checking generated and handwritten consumers.
- Keep static localized copy in `strings.json` and layout localization entries. Keep runtime-changing values in bindings and the Store.
- Send UI input through generated View handlers to Controller code. Let Controllers update the Store; do not access business singletons from Views or binders.
- Declare required business dependencies as services and resolve them through the Controller service context.
- Use `SceneInstance` or a scripted Control for reusable composition. Avoid copying generated node trees between packages.
- Use repeater keys when item identity is stable. Do not assume repeaters provide viewport virtualization.
- Keep asset paths inside allowed roots. Treat `contentHash` as an optional lock: update it only with the explicit asset hash command.
- Preserve handwritten partial files. If generation would overwrite one, stop and report a generator defect.

## Validation

Use the bundled validator first:

```powershell
py addons/manifest_ui/codex_skill/godot-manifest-ui/scripts/quick_validate.py --project . --package ui/phone/package.json
```

For direct CLI use:

```powershell
manifest-ui validate ui/phone/package.json --format text
manifest-ui generate ui/phone/package.json --check
manifest-ui verify ui/phone/package.json
```

Read [references/authoring.md](references/authoring.md) for package creation and modification checklists. Load only the reference needed for the current task.

## Failure Handling

- Stop generation when validation reports an error.
- Do not weaken path, type, hash, or output-boundary validation to make a package pass.
- Do not delete files unless they are listed in `.manifest-ui.generated.json` and the user requested managed cleanup.
- Report unsupported properties or signals instead of inventing runtime behavior.
- If the installed addon and skill versions differ, update the skill before authoring.

# Authoring Workflow

## Define The Layout Tree

1. Record the intended tree in surface/state, semantic section, visual group, and atomic-control levels before writing `layout.json`.
2. Give nodes that share visibility, movement, scaling, clipping, input bounds, or layout a common parent. Keep unrelated sections out of the same sibling list.
3. Use plain `Control` parents for fixed or circular composition. Use `VBoxContainer`, `HBoxContainer`, or `GridContainer` only when children should participate in flow layout.
4. Give every structural parent a stable `id` and `name`. Set non-interactive grouping Controls to `mouse_filter = 2` (`Ignore`).
5. Express child geometry in immediate-parent coordinates. Recalculate offsets when reparenting; do not retain root-relative offsets.
6. Finalize the recursive `children` tree, enumerate its generated node paths, then author `bindings.json` and control targets with complete paths.
7. Do not wrap every atomic node. Add a parent when it owns shared behavior or geometry; a module that requires moving or hiding three or more siblings is a warning that a semantic parent is missing.

## Create A Package

1. Choose a stable package id and output directory.
2. Create `package.json` and its referenced manifests under a configured source root.
3. Define the semantic recursive layout tree, stable ids, local geometry, and final paths before bindings.
4. Separate static localized copy from dynamic Store fields.
5. Declare events, channels, inputs, repeaters, assets, generated types, and required services.
6. Validate, generate, verify, and run the package in a sample scene.

## Modify A Package

1. Read Source JSON, generated report, Controller partial, and service adapters.
2. Preserve ids unless the task is an explicit migration.
3. Update the recursive layout tree and enumerate final node paths before adding or changing bindings.
4. Update fields before referencing them from bindings or repeaters.
5. Update strings before adding localization keys.
6. Run validation after each structural group of changes.
7. Generate once, review managed output, then run generate-check and Verify.

## Controller Boundary

- Initialize display state from services in the Controller.
- Subscribe through tracked subscriptions and release them with the Controller.
- Update the Store in batches for related fields.
- Use message channels for UI-to-UI coordination, not direct View references.
- Keep generated event methods thin and delegate business decisions to handwritten partial methods.

## Review Checklist

- Package paths stay inside the project and configured roots.
- Composite modules use semantic parents and recursive `children`; unrelated sections are not emitted as one flat sibling list.
- Structural parents have stable ids, local child geometry, and explicit input ownership.
- Control ids, node paths, fields, handlers, channels, and asset ids are unique.
- Bindings target compatible properties and field types.
- Events target supported signals and preserve signal payloads.
- Repeaters have stable templates and keys where applicable.
- Static text uses localization; dynamic text uses the Store.
- Generated files contain generator headers and no handwritten edits.
- A second generation is byte-stable.

# Authoring Workflow

## Create A Package

1. Choose a stable package id and output directory.
2. Create `package.json` and its referenced manifests under a configured source root.
3. Define layout ids and paths before bindings.
4. Separate static localized copy from dynamic Store fields.
5. Declare events, channels, inputs, repeaters, assets, generated types, and required services.
6. Validate, generate, verify, and run the package in a sample scene.

## Modify A Package

1. Read Source JSON, generated report, Controller partial, and service adapters.
2. Preserve ids unless the task is an explicit migration.
3. Update layout before adding bindings to new controls.
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
- Control ids, node paths, fields, handlers, channels, and asset ids are unique.
- Bindings target compatible properties and field types.
- Events target supported signals and preserve signal payloads.
- Repeaters have stable templates and keys where applicable.
- Static text uses localization; dynamic text uses the Store.
- Generated files contain generator headers and no handwritten edits.
- A second generation is byte-stable.

# Manifest Schema V1

`package.json` is the canonical entrypoint. It references:

- `layout.json`: Control tree, properties, scene instances, scripted controls, and localization keys.
- `bindings.json`: Store fields, property bindings, inputs, repeaters, controls, events, channels, and update policy.
- `assets.json`: Package assets, kinds, optional content hashes, and generated theme metadata.
- `codegen.json`: Generated type names, required services, routes, and generator options.
- `validation.json`: Supported validation policy. Unknown checks must fail validation.
- `strings.json`: Optional locale tables for static and parameterized localized copy.

Compatibility rules:

- Keep `schemaVersion` equal to `1`.
- Missing new optional fields use legacy behavior.
- A package without `runtime.controllerScope` uses package-scoped Controllers; new packages should declare instance scope.
- Accepted fields must have implemented behavior. A validator must reject unsupported declarations.
- Package-local schema snapshots are optional; when present, they must match the addon schemas.

Generated ownership rules:

- Managed: `.g.cs`, generated `.tscn`, derived `.tres`, catalogs, reports, and `.manifest-ui.generated.json`.
- Scaffolded once: Widget partial `.cs` and Controller partial `.cs`.
- Handwritten: business services, adapters, models, and Controller partial implementations.

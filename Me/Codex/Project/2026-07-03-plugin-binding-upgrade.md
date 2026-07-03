# 2026-07-03 Plugin Binding Upgrade

- Task: move Godot manifest UI bindings from generated setters into plugin-level runtime binding applier.
- Runtime: added binding metadata, applier, converter registry, and `ManifestGeneratedWidget.GetBindingSet()`.
- Generator: validates canonical string/object bindings and emits `ManifestBindingSet` metadata instead of property setter code.
- Plugin: added `plugin.cfg` and C# `EditorPlugin` dock for package scan, validate, report, and generate through the existing `dotnet` generator.
- Sample: expanded `ui/phone` to cover text format, visible/visibility, enabled, value, texture asset id, and theme class.
- Tests: extended `SelfCheck` for converter registry and applied binding properties; added negative fixtures for unsupported property, incompatible target, unknown converter, and missing texture asset.

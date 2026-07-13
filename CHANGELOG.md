# Changelog

All notable changes to Manifest UI are documented in this file. The project
follows [Semantic Versioning](https://semver.org/spec/v2.0.0.html), with tags
named `manifest-ui-vX.Y.Z`.

## [Unreleased]

## [0.1.0-alpha.2] - 2026-07-13

### Added

- Release-grade tooling, runtime, editor, documentation, and test work for the
  Manifest UI 1.0 roadmap.
- Generic `resource` assets and static layout `{ "assetRef": "..." }`
  properties that generate deterministic Godot `ExtResource` assignments.
- Engine-verified scripted-control properties, inputs, and events, demonstrated
  by the repository's Manifest-driven Liquid Glass UI package.
- Manager-owned UI visibility scopes, priorities, and opt-in lower-priority
  suppression with `Hud`, `Overlay`, and `Modal` priority constants.

### Changed

- Suppressed handles remain Open while generated Store state continues to
  update, then fully refresh when visibility returns.
- Suppressed modals release blockers, pause ownership, and focus until restored.

### Fixed

- C# scripted controls now use Godot's PascalCase exported property and signal
  names during generation, runtime fallback binding, and engine verification.
- Engine verification no longer disposes ResourceLoader cache objects while
  instantiated scenes still reference them.

## [0.1.0-alpha.1] - 2026-07-11

### Added

- Initial public release foundation for Godot 4.7 Mono and .NET 8.
- Manifest-driven generation, runtime binding, lifecycle, asset validation,
  editor dock, demonstration project, and headless self-check baseline.

### Changed

- Project ownership and package metadata now use `maplewen` and the MIT License.
- Removed third-party Unreal Engine source material from the distributable tree.

### Known Issues

- Godot 4.7 stable leaves an internal `RefCounted` LoadToken after each threaded
  ResourceLoader request. Alpha verification recognizes only that exact
  upstream signature; beta, RC, and stable release gates remain strict.

[Unreleased]: https://github.com/maplewen07/GodotUI/compare/manifest-ui-v0.1.0-alpha.2...HEAD
[0.1.0-alpha.2]: https://github.com/maplewen07/GodotUI/releases/tag/manifest-ui-v0.1.0-alpha.2
[0.1.0-alpha.1]: https://github.com/maplewen07/GodotUI/releases/tag/manifest-ui-v0.1.0-alpha.1

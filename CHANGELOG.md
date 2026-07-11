# Changelog

All notable changes to Manifest UI are documented in this file. The project
follows [Semantic Versioning](https://semver.org/spec/v2.0.0.html), with tags
named `manifest-ui-vX.Y.Z`.

## [Unreleased]

### Added

- Release-grade tooling, runtime, editor, documentation, and test work for the
  Manifest UI 1.0 roadmap.

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

[Unreleased]: https://github.com/maplewen07/GodotUI/compare/manifest-ui-v0.1.0-alpha.1...HEAD
[0.1.0-alpha.1]: https://github.com/maplewen07/GodotUI/releases/tag/manifest-ui-v0.1.0-alpha.1

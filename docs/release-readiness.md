# Release Readiness

GodotUI uses independent release trains. Passing an alpha gate means the
archive is installable and testable; it does not imply the 1.0 compatibility
promise.

## Manifest UI

The current version is `0.1.0-alpha.2`.

| Gate | Required result |
| --- | --- |
| Alpha | Tooling, runtime, Editor import, final ZIP install/uninstall, published CLI, and examples pass on supported CI systems. The precisely matched Godot 4.7 threaded loader leak may be acknowledged. |
| Beta | Feature and schema-v1 contracts are complete, all supported fields are implemented or diagnosed, and ObjectDB leak checks are strict. |
| RC | Windows, Linux, and macOS release gates pass from a clean tag; generated output and archives are byte-stable; documentation and migration notes are frozen. |
| 1.0 | No open critical issue, every RC gate remains green, and version/tag/plugin/CLI/Skill/CHANGELOG metadata agree. |

The official Godot 4.7 Mono binary currently leaks internal threaded
`ResourceLoader` tokens. This repository proves the leak with strict baseline
tests and allows only the exact `RefCounted`/reference-count-zero signature in
alpha. Beta, RC, and stable gates do not allow it. See
[Known issues](known-issues.md).

The public release must also come from the new history created by
`scripts/release/New-PublicRepository.ps1`. Metadata gates reject the removed
third-party and internal archive paths in either the index or Git history.

## Liquid Glass

Liquid Glass has its own `liquid-glass-vX.Y.Z` tags, metadata, changelog,
archives, clean-install test, and visual gate. Its current alpha does not change
the sequencing rule: Manifest UI reaches 1.0 before Liquid Glass is promoted to
a stable 1.0 release.

Liquid Glass visual evidence is rendered at three 16:9 resolutions. The gate
checks nonblank output, color diversity, overlap order, controls, accessibility
state, and a coarse frame-time budget. Device-specific GPU qualification is
still required before a stable release.

# GodotUI

GodotUI is a Godot 4.7 Mono project for building manifest-driven user
interfaces in C#. The first distributable addon, **Manifest UI**, combines a
runtime, deterministic code generation, validation, and editor workflows around
one versioned UI manifest.

Manifest UI is currently a pre-1.0 alpha. Its package and API contracts are
being hardened for public release; prerelease versions may still change with a
documented migration path.

[中文说明](docs/README.zh-CN.md) | [Installation](docs/installation.md) |
[Contributing](CONTRIBUTING.md) | [Changelog](CHANGELOG.md)

## Requirements

- Godot 4.7 Mono. The standard non-Mono editor cannot compile the addon.
- .NET SDK 8.0.400 or a later .NET 8 patch accepted by `global.json`.
- PowerShell 7 for repository verification and release packaging.

The repository never stores a machine-specific Godot path. Set `GODOT_BIN` if
the console executable is not available as `godot` on `PATH`:

```powershell
$env:GODOT_BIN = '<Godot 4.7 Mono console executable>'
```

## Install the Addon

Download `manifest-ui-<version>.zip` from a GitHub Release and extract it at the
root of a Godot project. The resulting path must be:

```text
addons/manifest_ui/plugin.cfg
```

Build the C# project, open **Project > Project Settings > Plugins**, and enable
**Manifest UI**. See [the installation guide](docs/installation.md) for source
install, upgrade, and uninstall instructions.

## Develop from Source

```powershell
dotnet build GodotUI.csproj --configuration Release
dotnet run --project tools/ManifestUi.Cli -- --help
pwsh ./scripts/ci/Invoke-CI.ps1
```

When Godot is not on `PATH`, pass it explicitly:

```powershell
pwsh ./scripts/ci/Invoke-CI.ps1 -GodotBin $env:GODOT_BIN
```

The CLI and editor plugin consume the same tooling core. Generated `.g.cs`,
`.tscn`, and `.tres` files are managed output; handwritten partial widget files
remain user-owned.

The root project opens `ui/liquid_glass/package.json` as an integration demo.
It exercises generic scripted controls and resource-backed layout properties
without creating a dependency between the Manifest UI and Liquid Glass addons.

## Repository Layout

```text
addons/manifest_ui/       distributable Manifest UI addon
tools/ManifestUi.Cli/     .NET 8 command-line frontend
tests/                    tooling and Godot headless tests
examples/                 examples excluded from the addon archive
docs/                     user and maintainer documentation
scripts/                  CI and release verification
```

Only `addons/manifest_ui/` is included in the addon archive. It must not depend
on source files elsewhere in the repository.

## Release Model

Manifest UI uses semantic versions and `manifest-ui-vX.Y.Z` tags. Releases move
through alpha, beta, and release-candidate gates before 1.0. The release
workflow produces the addon, portable .NET CLI, examples, and SHA-256 checksums.

Liquid Glass now has an independent clean-room alpha implementation under
`addons/liquid_glass/`, with its own version metadata, `liquid-glass-vX.Y.Z`
tags, release workflow, archive, examples, and checksums. The roadmap still
keeps its stable 1.0 release after Manifest UI 1.0; the current alpha is for
behavior, renderer, accessibility, and performance validation. No third-party
Unreal Engine source, binaries, assets, or history are included in the public
repository or release archives.

## License

GodotUI is available under the [MIT License](LICENSE). See
[Third-Party Notices](THIRD_PARTY_NOTICES.md) for external runtime and tooling
dependencies.

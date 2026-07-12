# Installing Manifest UI

## Prerequisites

Use Godot 4.7 Mono and .NET 8. Confirm both tools before installing:

```powershell
dotnet --version
& $env:GODOT_BIN --version
```

The Godot output must identify version 4.7 and a Mono/.NET build. The addon does
not support the standard non-Mono editor.

## Release Archive

1. Download `manifest-ui-<version>.zip` and its checksum file from the matching
   GitHub Release.
2. Verify the archive SHA-256 value.
3. Extract the archive at the project root without adding another directory
   level.
4. Confirm that `addons/manifest_ui/plugin.cfg` exists.
5. Build the project's C# solution.
6. Enable **Manifest UI** under **Project > Project Settings > Plugins**.

The addon manages its own autoloads when enabled. A name collision with an
existing project autoload must be resolved explicitly; the plugin must not
overwrite an unrelated autoload.

## Source Checkout

For development, clone the repository and run:

```powershell
dotnet restore
dotnet build GodotUI.csproj --configuration Release
pwsh ./scripts/ci/Invoke-CI.ps1 -GodotBin $env:GODOT_BIN
```

Do not copy the repository's `tests`, `examples`, `tools`, or root project into
an application that only needs the addon. The release ZIP is the authoritative
installation boundary.

## Upgrade

1. Disable Manifest UI in the Godot plugin settings.
2. Back up handwritten manifests and partial widget files.
3. Replace the complete `addons/manifest_ui/` directory with the new release.
4. Read the version's changelog and run the documented migration check.
5. Build the C# solution, re-enable the plugin, and validate all packages.

Do not merge two addon versions file by file. Generated output should be
regenerated with the newly installed tooling after validation succeeds.

## Uninstall

1. Disable Manifest UI in the plugin settings so owned autoload entries are
   removed.
2. Close Godot and delete `addons/manifest_ui/`.
3. Remove generated UI files only after confirming they are not referenced by
   application scenes or code.
4. Rebuild the C# solution.

Manifest packages and user-authored partial classes are application source and
are not removed automatically.

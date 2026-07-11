# Releasing Manifest UI

Releases are created only from `manifest-ui-vX.Y.Z` tags. The repository stays
on prerelease versions until every 1.0 gate is implemented and passing.

## Prepare a Version

Update the same semantic version in:

- `manifest-ui-version.json`
- `Directory.Build.props`
- `project.godot`
- `addons/manifest_ui/plugin.cfg`
- `addons/manifest_ui/tooling/ManifestUiTool.cs` (`ToolVersion`)
- `addons/manifest_ui/codex_skill/godot-manifest-ui/VERSION`
- `CHANGELOG.md`

Then run:

```powershell
pwsh ./scripts/release/Test-ReleaseMetadata.ps1
pwsh ./scripts/ci/Invoke-CI.ps1 -GodotBin $env:GODOT_BIN
pwsh ./scripts/release/Build-Release.ps1 -RequireExamples
```

`Test-ReleaseMetadata.ps1` intentionally checks duplicated user-facing version
fields so a Godot install, generated index, bundled Skill, .NET binary, and GitHub
tag cannot disagree. It also rejects `CBLiquidGlass` or `Me` anywhere in the Git
index or history. Create the publishable repository without the source history:

```powershell
pwsh ./scripts/release/New-PublicRepository.ps1 `
  -DestinationPath (Join-Path (Split-Path -Parent $PWD) 'GodotUI-public')
```

Review and commit that new repository before creating any release tag.

## Artifact Contract

For version `X.Y.Z`, the release directory contains:

```text
manifest-ui-X.Y.Z.zip
manifest-ui-cli-X.Y.Z.zip
manifest-ui-example-X.Y.Z.zip
SHA256SUMS.txt
```

The addon archive contains only `addons/manifest_ui/` at its top level and must
remain below 2 MiB. The CLI archive is framework-dependent and portable across
platforms with .NET 8 installed. The example archive is separate from both.

Verify the addon from its ZIP rather than the source tree:

```powershell
pwsh ./scripts/release/Test-AddonPackage.ps1 `
  -PackagePath ./artifacts/release/manifest-ui-X.Y.Z.zip `
  -GodotBin $env:GODOT_BIN
```

Also execute the published CLI and both examples from their final archives:

```powershell
pwsh ./scripts/release/Test-CliPackage.ps1 `
  -PackagePath ./artifacts/release/manifest-ui-cli-X.Y.Z.zip
pwsh ./scripts/release/Test-ExamplePackage.ps1 `
  -PackagePath ./artifacts/release/manifest-ui-example-X.Y.Z.zip `
  -AddonPackagePath ./artifacts/release/manifest-ui-X.Y.Z.zip `
  -GodotBin $env:GODOT_BIN
```

Alpha CI alone may opt into the narrowly matched Godot 4.7 threaded loader leak
exception. Beta, RC, and stable release gates remain strict.

## Publish

Push an annotated tag only after the version commit passes CI:

```powershell
git tag -a manifest-ui-vX.Y.Z -m "Manifest UI X.Y.Z"
git push origin manifest-ui-vX.Y.Z
```

The release workflow repeats metadata validation on Windows, Linux, and macOS,
builds artifacts from the tagged commit, verifies checksums and archive layout,
then creates the GitHub Release. Never upload locally modified artifacts over a
tagged release.

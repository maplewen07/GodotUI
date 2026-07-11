# Contributing

Thank you for helping improve GodotUI. Contributions should stay focused on the
Manifest UI roadmap until its 1.0 release gates are complete.

## Prerequisites

- Godot 4.7 Mono. The standard build of Godot does not include C# support.
- .NET SDK 8.0.400 or a newer 8.0 patch selected by `global.json`.
- PowerShell 7 for the repository verification and release scripts.

Set `GODOT_BIN` to the Godot console executable when it is not available as
`godot` on `PATH`. Do not commit a machine-specific engine path.

## Development Workflow

1. Create a focused branch from the current default branch.
2. Keep handwritten code separate from generated `.g.cs`, `.tscn`, and `.tres`
   output.
3. Add or update tests for every behavioral change.
4. Run `pwsh ./scripts/ci/Invoke-CI.ps1` before opening a pull request.
5. Update `CHANGELOG.md` for user-visible behavior.

CI must finish with a clean Git diff. Generators and tests may write ignored
caches or artifacts, but must not rewrite tracked files.

## Code and Compatibility

- Use UTF-8, LF line endings, nullable C#, and deterministic output ordering.
- Preserve Manifest schema version 1 unless a separately approved migration is
  included.
- Treat public runtime API changes as compatibility work and document their
  migration path.
- Do not add code, assets, or documentation copied from `CBLiquidGlass` or other
  sources without compatible licensing and an explicit notice.

## Reporting Changes

Pull requests should describe the behavior changed, tests run, compatibility
impact, and any generated artifacts. Security reports must follow
`SECURITY.md`, not a public issue.

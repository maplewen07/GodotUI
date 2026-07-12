# Codex Skill for Manifest UI

The addon ships an optional `godot-manifest-ui` Codex Skill for source-first UI
authoring. It guides Codex to inspect the full package, edit only canonical JSON
and handwritten code, validate before generation, and preserve user partials.

The bundled source is:

```text
addons/manifest_ui/codex_skill/godot-manifest-ui/
```

It contains `SKILL.md`, agent metadata, a quick validation script, and focused
schema/runtime references. It does not use generated files as handwritten
templates.

## Install from the editor

Select **Install Skill** in the Manifest UI dock. Installation is explicit; the
addon does not modify Codex configuration when enabled.

The bundle contains a `VERSION` file. Compare it with an installed copy before
updating. If a destination already exists, the editor asks before replacing it
and creates a timestamped backup. Review any local Skill modifications before
confirming replacement.

Restart or reload Codex after installation so its available-Skill catalog is
refreshed.

## Authoring workflow

Ask Codex to use `godot-manifest-ui` and name the package or task. For example:

```text
Use the godot-manifest-ui Skill to add a localized empty state to ui/inventory.
Validate, generate, verify, and report the diagnostics.
```

The Skill instructs the agent to:

1. Locate `project.godot`, configured source roots, and the target package.
2. Read `package.json` plus every referenced source file.
3. Inspect Controllers and registered services before changing behavior.
4. Edit source JSON and handwritten code only.
5. Validate and resolve diagnostics by code and JSON pointer.
6. Generate only after validation succeeds.
7. Verify and run a second generation check for deterministic output.

AI-generated changes require the same review and tests as hand-authored code.
Do not grant a prompt permission to weaken path, type, hash, or ownership checks.

## Quick validation script

From the repository root:

```powershell
py addons/manifest_ui/codex_skill/godot-manifest-ui/scripts/quick_validate.py `
  --project . `
  --package ui/inventory/package.json
```

The script performs a JSON-reference preflight and locates an installed CLI,
the repository CLI project, or a compatible legacy entry point. Use the direct
CLI for JSON/SARIF formatting and release checks.

## Version alignment

Keep the Skill, addon, and CLI from the same release. After an addon upgrade,
check the installed Skill version before asking Codex to author manifests.

If Skill guidance and a current tooling diagnostic disagree, the tooling
diagnostic and bundled schema are authoritative. Capture the mismatch as a
documentation defect rather than changing generated output by hand.

## Review boundaries

Before accepting an AI-authored package, confirm:

- ids, node names, fields, channels, and package ids remain stable;
- services use Controller context instead of business singletons;
- localized static copy and dynamic Store values are separated;
- generated output changed only through the generator;
- `generate --check` and Verify succeed;
- no private prompts, reports, credentials, or external assets entered the
  publishable tree.

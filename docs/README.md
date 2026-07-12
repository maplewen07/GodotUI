# Manifest UI Documentation

Manifest UI targets Godot 4.7 Mono and .NET 8. Start with the installation
guide, then use the references below while authoring and integrating packages.

- [Installation](installation.md): prerequisites, release archive layout,
  upgrades, and uninstall.
- [Editor workflow](editor-workflow.md): source roots, package creation,
  validation, generation, verification, and previews.
- [Manifest schema v1](manifest-reference.md): every source file, supported
  bindings, assets, localization, and generated-file ownership.
- [Runtime API](runtime-api.md): catalog registration, lifecycle handles,
  Controller scopes, Store updates, services, messages, and modals.
- [Issue codes](issue-codes.md): tooling and runtime diagnostics.
- [Troubleshooting](troubleshooting.md): common environment, authoring,
  generation, editor, and runtime failures.
- [Known issues](known-issues.md): upstream engine blockers and exact CI policy.
- [Migration and upgrade](migration.md): moving between addon versions while
  preserving user-owned code.
- [Codex Skill](codex-skill.md): safe AI-assisted authoring with the bundled
  `godot-manifest-ui` Skill.
- [Release process](releasing.md): maintainer release gates and artifacts.
- [Release readiness](release-readiness.md): alpha, beta, RC, and 1.0 promotion
  criteria for both addons.
- [Liquid Glass](liquid-glass/README.md): independent clean-room alpha,
  installation, scripted-control integration, and renderer testing.

Runnable authoring projects are under [`examples/`](../examples/README.md):
**Basic** demonstrates input, events, bindings, and localization; **Inventory**
adds a repeater and a keyed service dependency.

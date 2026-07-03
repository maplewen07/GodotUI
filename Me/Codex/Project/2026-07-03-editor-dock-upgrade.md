# 2026-07-03 Editor Dock Upgrade

- Task: upgrade the Godot Manifest UI editor dock from a basic output panel into a practical package operation panel.
- Dock UI: added package selection, action buttons, status line, diagnostics list, raw output, and an `Open Report` entry.
- Diagnostics: parses existing generator `ERROR:` and `WARN:` text into severity, file, logical path, and message without changing the CLI contract.
- Navigation: selecting a diagnostic asks the Godot FileSystem dock to select the manifest file and shows the logical manifest path in the status line.
- Operations: generator subprocess execution disables dock buttons while running; successful generate refreshes the Godot editor filesystem.
- Assets/report: `Import Assets` reports empty asset directories and refreshes/reimports selected package assets; `Validate Report` enables opening `ui/<system>/export/manifest_report.md` when present.
- Skipped: no package creation wizard, settings page, batch operations, line-number jump, or duplicate manifest validation logic in the plugin.

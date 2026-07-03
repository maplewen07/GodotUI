# 2026-07-03 Complex UI V1

- Task: add the practical complex UI loop for Godot manifest UI without turning it into a full router/framework.
- Runtime: added repeater/input metadata, full-rebuild repeater rendering, item binding apply, input writeback through `SetInputValue`, `ManifestControllerBase.OnInputChanged`, and small controller helpers for screen/modal open/close.
- Generator: added optional `repeaters[]`, `inputs[]`, `SceneInstance` layout nodes, PackedScene scene includes, and UI signal wiring for pressed/text/toggled/value/item/tab events.
- Sample: expanded `ui/phone` with search input, contact repeater, tab event, modal helper use, and a nested generated `ui/badge` package included through SceneInstance.
- Validation: added negative fixtures for unknown repeater source, bad template path, bad scene path, incompatible input target, and unsupported event signal.
- Verified:
  - `dotnet build tools\ManifestUiGen\ManifestUiGen.csproj`
  - `dotnet run --no-build --project tools\ManifestUiGen -- validate ui\badge\package.json`
  - `dotnet run --no-build --project tools\ManifestUiGen -- validate ui\phone\package.json --write-report`
  - `dotnet run --no-build --project tools\ManifestUiGen -- generate ui\badge\package.json`
  - `dotnet run --no-build --project tools\ManifestUiGen -- generate ui\phone\package.json`
  - old and new negative fixture loop
  - `dotnet build GodotUI.csproj`
  - `godot --headless --path . --scene res://tests/SelfCheck.tscn`
  - `godot --headless --path . --scene res://demo/Main.tscn --quit-after 5`
  - `godot --headless --build-solutions --quit` exited 0, with the existing GodotTools hot-reload timer log.
- Skipped: keyed diff, virtual list, parent-child controller protocol, full route table, expression language, and automatic navigation decisions in generated widgets.

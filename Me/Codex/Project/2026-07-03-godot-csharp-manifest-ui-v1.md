# 2026-07-03 Godot C# Manifest UI V1

- Task: implement a Godot C# version of the Matrix manifest-driven UI framework.
- Runtime: added `GodotUi.Manifest` classes for UI manager, root, message bus, controller/model base, generated widget, and dirty-field store.
- Codegen: added `tools/ManifestUiGen`, using `System.Text.Json` only, with `check` and `generate` commands.
- Example: added `ui/phone` source manifests, generated `generated/ui/phone`, and hand-authored `PhoneController` / `PhoneModel`.
- Godot detail: scene scripts need a class-name-matching `.cs` file, so codegen emits `PhoneWidget.cs` as a thin script wrapper and `PhoneWidget.g.cs` for generated bindings.
- Validation passed: generator check, generator output, `dotnet build GodotUI.csproj`, `godot --headless --build-solutions --quit`, self-check scene, and demo scene startup.
- Deliberate skips: editor plugin UI, visual designer import, localization, theme conversion, and complex controls.

# GodotUI Liquid Glass

Liquid Glass is a clean-room set of Godot 4.7 Mono controls implemented with
`BackBufferCopy`, a CanvasItem screen-texture shader, and original presets.
It is licensed under MIT and has no runtime dependency on Manifest UI.

## Requirements

- Godot 4.7 Mono
- .NET 8
- Compatibility or Forward+ rendering with screen-texture support

## Install

Extract the release archive into a Godot project so this file is located at
`res://addons/liquid_glass/README.md`. Build the C# project, then enable
**GodotUI Liquid Glass** under **Project > Project Settings > Plugins**.

The release ZIP contains only `addons/liquid_glass/` and adds no autoloads.

## Controls

- `LiquidGlassPanel`: rounded rectangle, superellipse, capsule, or circle
  surface with blur, refraction, tint, rim, and inner shadow.
- `LiquidGlassButton`: focusable pointer/keyboard/gamepad action button.
- `LiquidGlassSlider`: focusable value control with action input and
  spring-smoothed glass thumb.
- `LiquidGlassStyle`: shared style resource with Clear, Soft, Frosted, and
  Vibrant presets.

Godot's inherited `AccessibilityName` and `AccessibilityDescription`
properties are supported. Button and slider roles, disabled state, and slider
numeric range are reported through Godot 4.7's accessibility server.

Screen-reading results depend on CanvasItem draw order. Keep each glass
surface after the background it samples, and test overlapping surfaces on
every target renderer and resolution.

See `BEHAVIOR_SPEC.md`, `PROVENANCE.md`, and the repository documentation for
the complete contract, release process, and optional Manifest UI integration.

# Liquid Glass Behavior Specification

This document defines externally observable behavior. It is the reference for
clean-room development and release testing.

## Platform contract

- Supported engine: Godot 4.7 Mono only.
- Supported scripting target: .NET 8.
- The addon must compile and import when the final addon ZIP is the only
  installed project dependency.
- Installing the addon must not add autoloads or require Manifest UI.

## Panel

- A panel samples pixels already drawn behind it through a rectangular
  `BackBufferCopy` region.
- The visible surface can be a rounded rectangle, superellipse, capsule, or
  circle. Pixels outside the selected contour are transparent.
- Blur, refraction, dispersion, tint, saturation, rim, inner shadow, and
  low-amplitude noise are independently controllable through a style resource.
- Clear, Soft, Frosted, and Vibrant are original convenience presets. Custom
  preserves user-authored values.
- Overlapping panels follow CanvasItem draw order. A later panel samples the
  composited result beneath it.

## Button

- Pointer release inside the control emits `Pressed` once.
- `ui_accept`, Enter, and Space emit `Pressed` once on release.
- Disabled buttons ignore pointer and action input and expose a disabled
  visual and accessibility state.
- Focus and hover increase visual emphasis without changing layout.

## Slider

- Pointer dragging maps the usable track to `[MinValue, MaxValue]`.
- Values are clamped and snapped to `Step` relative to `MinValue`.
- `ui_left` and `ui_down` decrement; `ui_right` and `ui_up` increment.
- Home selects the minimum and End selects the maximum.
- Disabled sliders ignore input and expose a disabled visual and accessibility
  state.
- The visible thumb follows the logical value with damped spring motion; the
  emitted value changes immediately.

## Accessibility

- Panels expose a panel role and optional inherited `AccessibilityName`.
- Buttons expose button role, inherited accessibility name/description,
  focus, and disabled/pressed state.
- Sliders expose slider role, inherited accessibility name/description,
  numeric value, range, step, focus, and disabled state.
- Accessibility information is reported only when the Godot platform backend
  supports it; control behavior remains available otherwise.

## Release gates

- Visual checks render at 640x360, 960x540, and 1440x810.
- Screenshots must be non-empty and show distinct unobscured, single-glass,
  and overlapping-glass pixels.
- A coarse average frame-time budget detects large regressions but is not a
  device performance guarantee.
- The clean-install test compiles, imports, enables, runs, and removes a
  project created from the addon ZIP alone.

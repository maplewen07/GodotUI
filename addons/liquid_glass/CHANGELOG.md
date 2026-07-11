# Changelog

All notable changes to Liquid Glass are documented here. Versions follow
Semantic Versioning and use independent `liquid-glass-vX.Y.Z` tags.

## [0.1.0-alpha.1] - 2026-07-11

### Added

- Clean-room CanvasItem glass shader using Godot screen textures and
  `BackBufferCopy`.
- Rounded rectangle, superellipse, capsule, and circle panel shapes.
- Clear, Soft, Frosted, and Vibrant original presets.
- Focusable button and slider controls with mouse, keyboard, and Godot UI
  action support.
- Godot 4.7 accessibility roles, names, descriptions, disabled state, and
  slider value/range reporting.
- Spring-smoothed slider thumb motion.
- Deterministic release archives, clean-install smoke tests, and a
  three-resolution visual gate.

### Known limitations

- This is an alpha release and its material parameters may still change.
- Screen-texture results depend on draw order and the selected renderer.
- GPU performance must be evaluated on each target device.

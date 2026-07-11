# Manifest UI Scripted-Control Integration

Manifest UI and Liquid Glass remain independent addons. Integration is opt-in
at authoring time through Manifest UI's existing `scriptPath` extension point;
neither addon references the other's assemblies.

After installing both addons, a non-root layout node can attach a Liquid Glass
control script:

```json
{
  "id": "glass_panel",
  "type": "Control",
  "name": "GlassPanel",
  "scriptPath": "res://addons/liquid_glass/runtime/LiquidGlassPanel.cs",
  "properties": {
    "offset_left": 48,
    "offset_top": 48,
    "offset_right": 432,
    "offset_bottom": 264,
    "preset": 2,
    "visual_intensity": 1.0,
    "accessibility_name": "Inventory summary"
  },
  "children": []
}
```

`type` remains `Control` because Manifest UI validates scripted controls
against their Godot base type. `scriptPath` is the only connection. Removing
Liquid Glass makes this specific package fail validation or scene loading, but
does not change Manifest UI itself.

Prefer numeric exported enum values only in generated/validated manifests.
For hand-authored scenes, assign a shared `LiquidGlassStyle` resource in the
Godot inspector.

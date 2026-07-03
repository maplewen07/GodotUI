# 2026-07-03 CBLiquidGlass Godot Conversion

- Task: study the bundled UE `CBLiquidGlass` plugin and decide how to translate it into this Godot project.
- Entry: followed the repo rule by checking `Me/Codex/Project` first; the standard `Me/Codex/memory_*.md` files are not present in this checkout.
- UE plugin identity: `CBLiquidGlass` is a Runtime UMG/Slate liquid-glass widget plugin, not a Matrix manifest/codegen plugin.
- Core UE path: `SCBLiquidGlass::OnPaint` collects the widget rect and visual parameters, `FCBLiquidGlassSlateElement` copies the backbuffer region, then `CBLiquidGlass.usf` runs downsample, blur, and composite passes.
- Core effect: shape SDF, optional alpha mask, screen refraction, chromatic aberration, frost blur mix, tint, saturation, adaptive tint, rim light, inner glow/shadow, and motion deformation.
- Public surface: base glass container plus Button, Slider, Text, Toggle, Segmented Control, Tab Bar, Toolbar, Menu, Search Bar, Progress, Stepper, Badge, Page Control, Navigation Bar, Dialog, and Fusion Container.
- Current Godot fit: this repo already has a Godot 4.6 C# manifest UI runtime and generator; the cheapest integration is a runtime `Control` plus optional manifest node support, not an EditorPlugin first.
- Recommended MVP: create a Godot `LiquidGlass` Control/Container with exported preset uniforms and a canvas_item shader using Godot screen texture/backbuffer copy. Use mipmapped screen sampling for blur first; skip exact UE multi-pass RDG parity.
- Recommended second slice: wire `LiquidGlass` into `ManifestUiGen` so `layout.json` can emit the custom node/script, then build one sample panel in `ui/phone`.
- Recommended third slice: port only Button and Slider after the base glass works. Button is a transparent native input layer over glass. Slider needs a small custom Control for the spring thumb.
- Defer: full component gallery, visual designer import, theme conversion, localization, text-as-alpha-mask, fusion blob mask rasterization, and exact multi-pass blur.
- Full parity path: only if the shader approximation is not good enough, move to a GDExtension/RenderingDevice multi-pass renderer or a SubViewport blur chain.
- Key risk: UE can copy the exact Slate output region during paint; Godot must rely on `SCREEN_TEXTURE`/`BackBufferCopy` ordering, so overlapping glass and child draw order need targeted visual checks.

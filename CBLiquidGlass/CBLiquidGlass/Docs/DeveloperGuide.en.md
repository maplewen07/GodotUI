# CBLiquidGlass Plugin Developer Guide

This document covers only the `CBLiquidGlass` plugin: how to use it, how its rendering pipeline works, how to call the demos, and how to tune performance. The plugin provides Liquid Glass-style UMG/Slate widgets by sampling the backbuffer behind the widget, then compositing blur, refraction, chromatic dispersion, tint, rim lighting, and inner shadow before drawing child content crisply on top.

## Feature Overview

| Feature | Description |
| --- | --- |
| UMG widget | `UCBLiquidGlass`, shown as `Liquid Glass` in the UMG designer. |
| UMG interaction widgets | `UCBLiquidGlassButton`, `UCBLiquidGlassText`, and `UCBLiquidGlassSlider` for reusable glass controls. |
| Slate widget | `SCBLiquidGlass`, usable directly in Slate code. |
| Shapes | `SuperellipseRect`, `Capsule`, `Circle`. |
| Presets | `Clear`, `Regular`, `FrostedMenu`, `PillLens`, `MatteLayer`, `SelfLayer`. |
| Background sampling | A Slate custom element copies the backbuffer region behind the widget on the render thread. |
| Shader effects | Downsample, separable blur, sharp/blurred background blend, shape SDF, refraction, dispersion, tint, rim light, inner shadow. |
| Demos | `CBLiquidGlass.Demo` for showcase, `CBLiquidGlass.ControlDemo` for transparent-background tuning, and focused feature demos such as `CBLiquidGlass.SliderDemo`. |

## Plugin Layout

| Path | Purpose |
| --- | --- |
| `CBLiquidGlass.uplugin` | Plugin descriptor. The module loads at `PostConfigInit` so shader directory mapping is available early. |
| `Source/CBLiquidGlass/Public/CBLiquidGlassTypes.h` | Blueprint-visible preset and shape enums. |
| `Source/CBLiquidGlass/Public/CBLiquidGlassWidget.h` | UMG widget API, Blueprint properties, and setters. |
| `Source/CBLiquidGlass/Public/CBLiquidGlassSlider.h` | UMG jelly slider API, Blueprint properties, and value-changed event. |
| `Source/CBLiquidGlass/Public/SCBLiquidGlass.h` | Slate widget API. |
| `Source/CBLiquidGlass/Public/SCBLiquidGlassSlider.h` | Slate liquid-glass slider with spring/jelly thumb motion. |
| `Source/CBLiquidGlass/Private/CBLiquidGlassRenderer.cpp` | RDG rendering: backbuffer copy, downsample, blur, final composite. |
| `Shaders/Private/CBLiquidGlass.usf` | Plugin global shaders. |
| `Source/CBLiquidGlass/Private/CBLiquidGlassDemo.cpp` | Runtime demos and console commands. |
| `Resources/1.jpg`–`4.jpg` | Background images the demos pick from at random. |
| `Resources/Icons/*.svg` | SVG icons used by the demo UI. |
| `Source/CBLiquidGlass/Private/CBLiquidGlassRecipes.h/.cpp` | Centralized glass recipe table: `FCBLiquidGlassRecipe` + preset recipes shared by presets and controls. |
| `Source/CBLiquidGlass/Private/CBLiquidGlassMotion.h` | Shared `StepSpring` solver reused by every animated control. |

## Basic Usage

### UMG

1. Add a `Liquid Glass` widget in a UMG Widget Blueprint.
2. Put text, buttons, icons, menus, or any other UI as the child content.
3. Choose a `Preset` in the Details panel. Start with `Regular` or `FrostedMenu`.
4. If corners are too round, increase `SquirclePower`. If the glass looks gray, reduce `TintOpacity` and `FrostRadius`.

`Liquid Glass` is a single-child container. The glass is rendered behind the child; the child itself is not blurred.

### Slate

```cpp
SNew(SCBLiquidGlass)
    .Shape(ECBLiquidGlassShape::SuperellipseRect)
    .SquirclePower(7.0f)
    .BlurStrength(0.95f)
    .FrostRadius(0.28f)
    .RefractionStrength(0.9f)
    .RefractionThickness(34.0f)
    .IndexOfRefraction(1.85f)
    .TintOpacity(0.015f)
[
    SNew(STextBlock)
    .Text(FText::FromString(TEXT("Glass Content")))
];
```

## Demo Commands

Both demos are runtime viewport overlays. Call them during PIE or while a game viewport is active.

| Command | Background | Purpose | Interaction | Calling again |
| --- | --- | --- | --- | --- |
| `CBLiquidGlass.Demo` | Random image from `Resources` | Shows cards, menu, pill buttons, circle lens, and Matte/Self samples | Most glass controls can be dragged after a short hold | Closes the demo |
| `CBLiquidGlass.ControlDemo` | Transparent, no full-screen background | Adds a tuning panel and a live preview over the current viewport | Sliders update the preview in real time | Closes the demo |
| `CBLiquidGlass.SliderDemo` | Random image from `Resources` | Shows a single Apple-style blue progress slider with a glass thumb | Drag the slider thumb or track; the glass thumb lags slightly, stretches subtly, then rebounds in a controlled way | Replaces the current feature demo |

### Call from PIE Console

1. Start PIE.
2. Open the console or the command input in Output Log.
3. Enter:

```text
CBLiquidGlass.Demo
```

or:

```text
CBLiquidGlass.ControlDemo
```

### Call from Blueprint

Use the `Execute Console Command` node with one of these command strings:

```text
CBLiquidGlass.Demo
```

```text
CBLiquidGlass.ControlDemo
```

### Call from C++

```cpp
if (GEngine && World)
{
    GEngine->Exec(World, TEXT("CBLiquidGlass.ControlDemo"));
}
```

## Demo Details

### `CBLiquidGlass.Demo`

| Control | Parameter direction | Purpose |
| --- | --- | --- |
| Regular Glass card | Medium refraction, low tint, low frost, tighter corners | Shows a standard card glass style. |
| Clear / Pill Lens / Prism buttons | `Capsule` shape, clear center, refracting edge | Shows fluid button styles. |
| Frosted Menu | Lower saturation, light inner shadow, mild tint | Shows a context menu or popup style. |
| Circle Lens | `Circle` shape, low frost, stronger refraction | Shows a round lens style. |
| Matte Layer | Higher frost, weaker refraction | Shows a frosted layer style. |
| Self Layer | Low frost, emphasis on edge refraction | Shows a clearer glass layer style. |

### `CBLiquidGlass.ControlDemo`

This demo is a transparent overlay. It does not draw its own full-screen background, so it is useful for tuning against the actual scene or UI currently in the viewport.

| Slider | Parameter | Effect |
| --- | --- | --- |
| Corner Power | `SquirclePower` | Controls rectangular corner curvature. Higher values produce tighter corners. |
| Blur | `BlurStrength` | Controls background blur strength. |
| Frost | `FrostRadius` | Blends between sharp capture and blurred background. |
| Refraction | `RefractionStrength` | Controls overall UV bending strength. |
| Thickness | `RefractionThickness` | Controls the width of the refracting edge band. |
| IOR | `IndexOfRefraction` | Controls the refraction amplification. |
| Prism | `PrismIntensity` | Controls chromatic/prism separation. |
| Tint | `TintOpacity` | Controls glass tint strength. |
| Rim | `RimIntensity` | Controls edge highlight strength. |
| Inner Shadow | `InnerShadowIntensity` | Controls inner edge shadow. |
| Opacity | `GlassOpacity` | Controls overall composite opacity. |

### `CBLiquidGlass.SliderDemo`

`SliderDemo` shows the main `SCBLiquidGlassSlider` style. The slider is composed of a translucent glass track, a blue progress layer, and a liquid-glass thumb. The logical value updates immediately, while the visual thumb follows through a lightly under-damped spring, so fast drags create an Apple-like subtle stretch and controlled rebound rather than an exaggerated rubber-band bounce.

| Parameter | Purpose |
| --- | --- |
| `ThumbBounce` | Controls the thumb stretch/squash amount. `0` disables the extra liquid sizing. (was `JellyStrength`) |
| `ThumbResponse` | Controls how quickly the visual thumb catches the logical value. Higher is tighter. (was `JellyResponse`) |
| `ThumbDamping` | Controls the damping ratio. `8` to `10` is closer to Apple's restrained rebound; lower values feel softer, higher values feel harder. (was `JellyDamping`) |
| `ThumbMotionStrength` | Controls the underlying glass shader's motion deformation on the thumb. Keep it low for an Apple-like feel. (was `ThumbMotionDeformationStrength`) |

## Presets

| Preset | Recommended use | Visual profile | Notes |
| --- | --- | --- | --- |
| `Custom` | Manual tuning | No automatic value writes | Editing any visual parameter switches back to `Custom`. |
| `Clear` | Small buttons and floating tools | Clear, low tint, low frost | Increase `FrostRadius` slightly on busy backgrounds. |
| `Regular` | General cards | Balanced clarity, refraction, and rim light | Recommended default starting point. |
| `FrostedMenu` | Context menus and popup menus | Mild frost, light tint, better text separation | Avoid high tint values or the menu will look gray. |
| `PillLens` | Pill buttons, tabs, floating shortcuts | Stronger edge refraction | Best with `Capsule`. |
| `MatteLayer` | Background shields or soft panels | Weak refraction and more frost | Similar cost to regular glass. |
| `SelfLayer` | Clear overlays | Low frost and light refraction | Depends strongly on the background content. |

## Shapes

| Shape | Use case | Recommended values |
| --- | --- | --- |
| `SuperellipseRect` | Cards, menus, panels | `SquirclePower` around `6.0` to `9.0`; increase if corners look too round. |
| `Capsule` | Pill buttons, tabs, short bars | Radius is derived from widget size; `SquirclePower` is not the main control. |
| `Circle` | Round lens, close button, floating spot | Keep widget width and height similar. |

## Parameters

| Parameter | Suggested range | Performance impact | Visual impact |
| --- | --- | --- | --- |
| `SquirclePower` | `2.0` to `12.0` | Very low | Superellipse corner curvature. |
| `BlurStrength` | `0.0` to `3.5` | Medium | Blur sample span. High values can look smeared. |
| `DownsampleAmount` | `1` to `8` | High | Higher values reduce blur texture size but soften the result. |
| `FrostRadius` | `0.0` to `1.0` | Very low | Blend between sharp and blurred background. |
| `RefractionStrength` | `0.0` to `1.0` | Very low | Overall UV bending. |
| `RefractionPower` | `0.5` to `6.0` | Very low | How tightly bending concentrates near the edge. |
| `RefractionThickness` | `4` to `80` | Very low | Width of the refracting edge. Too high looks inflated. |
| `IndexOfRefraction` | `1.0` to `2.4` | Very low | Refraction amplification. |
| `ChromaticAberration` | `0.0` to `0.3` | Low | Base RGB split. |
| `PrismIntensity` | `0.0` to `2.0` | Low | Extra color separation. High values can look dirty. |
| `NoiseAmount` | `0.0` to `0.05` | Very low | Breaks banding. High values look grainy. |
| `TintOpacity` | `0.0` to `0.12` | Very low | Tint strength. High values wash out the background. |
| `Saturation` | `0.8` to `1.5` | Very low | Background color intensity. |
| `AdaptiveTintStrength` | `0.0` to `0.15` | Very low | Luminance-adaptive tint. |
| `RimIntensity` | `0.0` to `0.6` | Very low | Edge highlight strength. |
| `InnerGlowIntensity` | `0.0` to `0.3` | Very low | Inner edge glow. |
| `InnerShadowIntensity` | `0.0` to `0.5` | Very low | Inner edge shadow and depth. |
| `GlassOpacity` | `0.1` to `1.0` | Very low | Overall composite opacity. |

## New Components

These appear under the `Liquid Glass` palette category and mirror common  26 controls. They live in `CBLiquidGlassExtras.h/.cpp` (UMG) and `SCBLiquidGlassExtras.h/.cpp` (Slate). Run the console command `CBLiquidGlass.ComponentGallery` during Play to preview them all at once.

| Component | Apple analogue | Key parameters / events |
| --- | --- | --- |
| `Liquid Glass Container` | `GlassEffectContainer(spacing:)` | `Blobs` (each `FCBLiquidGlassFusionBlob`: normalized `Position`, pixel `Size`, `Roundness`), `Smoothing` (merge radius — larger melts neighbours together), `CanvasSize`, `Preset`. Smooth-unions several rounded blobs into one glass panel that fuses when shapes are near. |
| `Liquid Glass Page Control` | `UIPageControl` | `NumPages`, `CurrentPage`, `DotSize`, `DotSpacing`, `ActiveColor`, `SpringSettings`; event `OnPageChanged`. The active page is a spring-driven pill. |
| `Liquid Glass Dialog` | Alert / action sheet / sheet | `Title`, `Message`, `Buttons`, `DialogStyle`, `bDimBackground`, `bStartPresented`; methods `Present()`/`Dismiss()`; events `OnButtonClicked`/`OnDismissed`. Spring-faded modal glass card. |
| `Liquid Glass Navigation Bar` | `UINavigationBar` | `Title`, `bShowBackButton`, `bLargeTitle`, `TrailingItems`; events `OnBackClicked`/`OnTrailingItemClicked`. |
| `Liquid Glass Badge` | UIKit badge | `Count`, `MaxCount` (overflow shows `N+`), `bDotMode`, `Color`. Auto-hides in count mode when `Count <= 0`. |

> The fusion container rasterizes its merged mask to a transient texture on the CPU (reusing the `AlphaMaskTexture` path) and only rebuilds it when parameters change; canvas sizes above 1024px are clamped to keep the cost bounded. Page Control dots are painted directly (Apple's page dots are not glass), so they are very cheap.

## Rendering Pipeline

| Stage | Location | Description |
| --- | --- | --- |
| Parameter collection | `SCBLiquidGlass::OnPaint` | Computes the widget rectangle and sends render parameters to the custom Slate element. |
| Background copy | `CBLiquidGlassRenderer.cpp` | Copies the backbuffer region behind the widget from `Inputs.OutputTexture`. |
| Downsample | `DownsamplePS` | 4-tap box downsample. |
| Blur | `BlurPS` | Horizontal and vertical separable Gaussian blur. |
| Composite | `CompositePS` | Shape SDF, sharp/blurred blend, refraction, dispersion, tint, rim, inner shadow. |
| Child drawing | Normal Slate drawing | Child content is painted on the next layer and remains sharp. |

## Performance Analysis

### GPU work per visible glass widget

| Work item | Count | Cost source |
| --- | --- | --- |
| Backbuffer region copy | 1 | Proportional to widget pixel area. |
| Downsample pass | 1 | Proportional to downsampled area. |
| Blur pass | 2 | Horizontal and vertical passes; proportional to downsampled area and blur taps. |
| Composite pass | 1 | Proportional to original widget pixel area. |

### Main performance factors

| Factor | Impact | Why | Optimization |
| --- | --- | --- | --- |
| Widget screen area | High | Copy and composite run at original widget size | Avoid full-screen glass panels; keep glass local. |
| Widget count | High | Each widget owns a full RDG pass chain | Merge nearby glass surfaces into one larger widget when possible. |
| `DownsampleAmount` | High | Directly changes blur texture size | Use `2` to `4` for large panels; `1` to `2` for small buttons. |
| `BlurStrength` | Medium | Increases blur sample span | Use the lowest value that looks good. |
| Overlapping glass | Medium | Later widgets sample already-composited previous widgets | Acceptable visually, but costs stack. |
| SVG icons | Low | Demo uses Slate vector brushes | Small icon counts are usually negligible. |

### Parameter cost categories

| Category | Parameters | Significant performance impact |
| --- | --- | --- |
| Shape/refraction/tint/rim | `Shape`, `RefractionStrength`, `TintOpacity`, `RimIntensity` | Usually no; mostly composite ALU. |
| Blur size | `DownsampleAmount`, widget area | Yes. |
| Blur strength | `BlurStrength` | Medium; same pass count, larger sample offsets. |
| Opacity | `GlassOpacity` | Almost none. |

### Recommended performance presets

| Scenario | Recommended settings |
| --- | --- |
| Small buttons | `DownsampleAmount=1` or `2`, `FrostRadius<0.25`, small widget area. |
| Menus/cards | `DownsampleAmount=2`, `BlurStrength=0.8~1.5`, `FrostRadius=0.25~0.5`. |
| Large panels | `DownsampleAmount=3` or `4`, lower `BlurStrength`, avoid multiple overlapping large panels. |
| Low-end devices | Reduce visible glass count, increase `DownsampleAmount`, reduce glass area. |

## Troubleshooting

| Problem | Fix |
| --- | --- |
| The glass looks gray or foggy | Reduce `TintOpacity`, `FrostRadius`, and `AdaptiveTintStrength`. |
| Corners are too round | Increase `SquirclePower` for `SuperellipseRect`; do not use `Capsule` for cards. |
| The edge is too white | Reduce `RimIntensity` and `InnerGlowIntensity`. |
| Refraction is too strong | Reduce `RefractionStrength`, `IndexOfRefraction`, or `RefractionThickness`. |
| Background does not appear | Verify `FPlatformMisc::SupportsBackbufferSampling()` is supported. Unsupported platforms skip glass rendering. |
| Demo background is missing | Ensure `Resources` contains the background images (`1.jpg`–`4.jpg`) and the plugin directory is accessible. |
| Shader path errors | Verify `PostConfigInit` loading and the `/Plugin/CBLiquidGlass` shader mapping in `StartupModule()`. |

## Extension Points

| Goal | Where to change |
| --- | --- |
| Add a preset | Add an `FCBLiquidGlassRecipe` case to `ForPreset()` in `CBLiquidGlassRecipes.cpp` and a value to `ECBLiquidGlassPreset`. `ApplyPresetProperties()` reuses it automatically. |
| Add a shape | Update `ECBLiquidGlassShape`, pass the new mode through renderer parameters, and implement its SDF in `SdShapePx()` in `CBLiquidGlass.usf`. |
| Add a shader parameter | Extend `UCBLiquidGlass`, `SCBLiquidGlass`, `FCBLiquidGlassRenderParams`, `FCBLGCompositePS::FParameters`, and the `.usf` file. |
| Add demo controls | Edit `CBLiquidGlassDemo.cpp`; prefer reusing `SCBLGDemoDraggable` and the existing SVG brushes. |
| Add an animated control | Reuse `CBLiquidGlassMotion::StepSpring` and `FCBLiquidGlassSpringSettings` so the feel matches existing controls. |


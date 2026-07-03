// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"

class SCBLiquidGlass;

/**
 * A complete, named set of liquid-glass visual parameters.
 *
 * Every control used to inline its own block of `Glass->SetBlurStrength(...)` calls, which meant
 * the same handful of "looks" were duplicated (and drifted) across the widget, button, slider and
 * controls translation units. A recipe captures one full look in a plain struct so it can be
 * declared once, reused everywhere, and applied to a live glass widget in a single call.
 *
 * The field set mirrors SCBLiquidGlass / UCBLiquidGlass exactly, so ForPreset() can drive both the
 * Slate widgets (via ApplyTo) and the UMG preset properties (via member copy).
 */
struct FCBLiquidGlassRecipe
{
	/** Analytic shape mask used by the composite shader. */
	ECBLiquidGlassShape Shape = ECBLiquidGlassShape::SuperellipseRect;

	/** Superellipse corner power for SuperellipseRect (ignored by Capsule/Circle). */
	float SquirclePower = 7.0f;

	/** Background blur span. Higher is frostier. */
	float BlurStrength = 0.95f;

	/** Blur buffer downsample factor (1-8). Higher is cheaper and softer. */
	int32 DownsampleAmount = 2;

	/** Clear/frost mix (0 = clear capture, 1 = fully frosted). */
	float FrostRadius = 0.28f;

	/** Edge lensing amount (0-1). */
	float RefractionStrength = 0.95f;

	/** Edge-bend falloff sharpness toward the rim. */
	float RefractionPower = 3.0f;

	/** Width in pixels of the refracting edge band. */
	float RefractionThickness = 34.0f;

	/** Stylized index of refraction (1 = no amplification). */
	float IndexOfRefraction = 1.85f;

	/** RGB split amount at the refracting edges. */
	float ChromaticAberration = 0.12f;

	/** Prism-like colour separation multiplier. */
	float PrismIntensity = 1.0f;

	/** Dither grain used to break gradient banding. */
	float NoiseAmount = 0.018f;

	/** Directional edge sheen strength. */
	float GlowAmount = 0.32f;

	/** Bright white rim brightness. */
	float RimIntensity = 0.24f;

	/** Rim/sheen light direction in degrees. */
	float GlowAngle = -135.0f;

	/** Soft glow just inside the edge band. */
	float InnerGlowIntensity = 0.07f;

	/** Inner edge shadow that separates glass from bright backgrounds. */
	float InnerShadowIntensity = 0.12f;

	/** Glass tint colour. */
	FLinearColor TintColor = FLinearColor::White;

	/** Tint strength (0-1). */
	float TintOpacity = 0.015f;

	/** Background saturation multiplier (1 = unchanged). */
	float Saturation = 1.35f;

	/** Luminance-adaptive tint amount (0-1). */
	float AdaptiveTintStrength = 0.0f;

	/** Final composite opacity (child content stays crisp). */
	float GlassOpacity = 1.0f;

	/** Anti-aliasing width multiplier of the shape edge. */
	float EdgeSoftness = 1.0f;

	/** Runtime cost/detail profile. */
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;

	/** Liquid motion deformation amount (0 disables motion warp). */
	float MotionStrength = 0.0f;

	/** Max movement offset, in pixels, fed to the motion solver. */
	float MotionMaxOffset = 32.0f;

	/** How quickly the glass catches up while moving. */
	float MotionResponse = 16.0f;

	/** How quickly the glass settles after movement stops (damping). */
	float MotionDamping = 10.0f;

	/** Writes every field into a live Slate glass widget through its setters. */
	void ApplyTo(SCBLiquidGlass& Glass) const;
};

namespace CBLiquidGlassRecipes
{
	/**
	 * Returns the full visual recipe for one of the built-in presets. This is the single source of
	 * truth shared by UCBLiquidGlass::ApplyPresetProperties and any control that wants a preset look.
	 * Passing Custom returns a default-constructed recipe (callers should skip applying it).
	 */
	FCBLiquidGlassRecipe ForPreset(ECBLiquidGlassPreset Preset);
}

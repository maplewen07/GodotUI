// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassRecipes.h"
#include "SCBLiquidGlass.h"

void FCBLiquidGlassRecipe::ApplyTo(SCBLiquidGlass& Glass) const
{
	Glass.SetShape(Shape);
	Glass.SetSquirclePower(SquirclePower);
	Glass.SetBlurStrength(BlurStrength);
	Glass.SetDownsampleAmount(DownsampleAmount);
	Glass.SetFrostRadius(FrostRadius);
	Glass.SetRefractionStrength(RefractionStrength);
	Glass.SetRefractionPower(RefractionPower);
	Glass.SetRefractionThickness(RefractionThickness);
	Glass.SetIndexOfRefraction(IndexOfRefraction);
	Glass.SetChromaticAberration(ChromaticAberration);
	Glass.SetPrismIntensity(PrismIntensity);
	Glass.SetNoiseAmount(NoiseAmount);
	Glass.SetGlowAmount(GlowAmount);
	Glass.SetRimIntensity(RimIntensity);
	Glass.SetGlowAngle(GlowAngle);
	Glass.SetInnerGlowIntensity(InnerGlowIntensity);
	Glass.SetInnerShadowIntensity(InnerShadowIntensity);
	Glass.SetTintColor(TintColor);
	Glass.SetTintOpacity(TintOpacity);
	Glass.SetSaturation(Saturation);
	Glass.SetAdaptiveTintStrength(AdaptiveTintStrength);
	Glass.SetGlassOpacity(GlassOpacity);
	Glass.SetEdgeSoftness(EdgeSoftness);
	Glass.SetQuality(Quality);
	Glass.SetMotionStrength(MotionStrength);
	Glass.SetMotionMaxOffset(MotionMaxOffset);
	Glass.SetMotionResponse(MotionResponse);
	Glass.SetMotionDamping(MotionDamping);
}

namespace CBLiquidGlassRecipes
{
	FCBLiquidGlassRecipe ForPreset(ECBLiquidGlassPreset Preset)
	{
		// Values are tuned as practical starting points rather than physically exact material
		// constants; they favour visible refraction and edge separation on high-contrast UI.
		FCBLiquidGlassRecipe R;
		switch (Preset)
		{
		case ECBLiquidGlassPreset::Clear:
			R.Shape = ECBLiquidGlassShape::SuperellipseRect;
			R.BlurStrength = 0.45f;
			R.DownsampleAmount = 2;
			R.FrostRadius = 0.08f;
			R.SquirclePower = 7.5f;
			R.EdgeSoftness = 1.0f;
			R.RefractionStrength = 1.0f;
			R.RefractionPower = 3.2f;
			R.RefractionThickness = 42.0f;
			R.IndexOfRefraction = 2.0f;
			R.ChromaticAberration = 0.08f;
			R.PrismIntensity = 1.15f;
			R.NoiseAmount = 0.015f;
			R.GlowAmount = 0.32f;
			R.RimIntensity = 0.24f;
			R.GlowAngle = -135.0f;
			R.InnerGlowIntensity = 0.06f;
			R.InnerShadowIntensity = 0.08f;
			R.TintColor = FLinearColor::White;
			R.TintOpacity = 0.01f;
			R.Saturation = 1.25f;
			R.AdaptiveTintStrength = 0.0f;
			R.GlassOpacity = 1.0f;
			R.Quality = ECBLiquidGlassQuality::Balanced;
			R.MotionStrength = 0.0f;
			R.MotionMaxOffset = 32.0f;
			R.MotionResponse = 16.0f;
			R.MotionDamping = 10.0f;
			break;

		case ECBLiquidGlassPreset::Regular:
			R.Shape = ECBLiquidGlassShape::SuperellipseRect;
			R.BlurStrength = 0.95f;
			R.DownsampleAmount = 2;
			R.FrostRadius = 0.28f;
			R.SquirclePower = 7.0f;
			R.EdgeSoftness = 1.0f;
			R.RefractionStrength = 0.95f;
			R.RefractionPower = 3.0f;
			R.RefractionThickness = 34.0f;
			R.IndexOfRefraction = 1.85f;
			R.ChromaticAberration = 0.15f;
			R.PrismIntensity = 1.0f;
			R.NoiseAmount = 0.018f;
			R.GlowAmount = 0.32f;
			R.RimIntensity = 0.24f;
			R.GlowAngle = -135.0f;
			R.InnerGlowIntensity = 0.07f;
			R.InnerShadowIntensity = 0.12f;
			R.TintColor = FLinearColor::White;
			R.TintOpacity = 0.015f;
			R.Saturation = 1.35f;
			R.AdaptiveTintStrength = 0.0f;
			R.GlassOpacity = 1.0f;
			R.Quality = ECBLiquidGlassQuality::Balanced;
			R.MotionStrength = 0.35f;
			R.MotionMaxOffset = 34.0f;
			R.MotionResponse = 18.0f;
			R.MotionDamping = 11.0f;
			break;

		case ECBLiquidGlassPreset::FrostedMenu:
			R.Shape = ECBLiquidGlassShape::SuperellipseRect;
			R.BlurStrength = 1.35f;
			R.DownsampleAmount = 2;
			R.FrostRadius = 0.48f;
			R.SquirclePower = 7.5f;
			R.EdgeSoftness = 1.0f;
			R.RefractionStrength = 0.62f;
			R.RefractionPower = 2.6f;
			R.RefractionThickness = 30.0f;
			R.IndexOfRefraction = 1.55f;
			R.ChromaticAberration = 0.055f;
			R.PrismIntensity = 0.5f;
			R.NoiseAmount = 0.018f;
			R.GlowAmount = 0.28f;
			R.RimIntensity = 0.22f;
			R.GlowAngle = -125.0f;
			R.InnerGlowIntensity = 0.08f;
			R.InnerShadowIntensity = 0.22f;
			R.TintColor = FLinearColor(0.72f, 0.78f, 0.82f, 1.0f);
			R.TintOpacity = 0.08f;
			R.Saturation = 1.05f;
			R.AdaptiveTintStrength = 0.08f;
			R.GlassOpacity = 0.9f;
			R.Quality = ECBLiquidGlassQuality::Balanced;
			R.MotionStrength = 0.18f;
			R.MotionMaxOffset = 24.0f;
			R.MotionResponse = 12.0f;
			R.MotionDamping = 9.0f;
			break;

		case ECBLiquidGlassPreset::PillLens:
			R.Shape = ECBLiquidGlassShape::Capsule;
			R.BlurStrength = 0.85f;
			R.DownsampleAmount = 2;
			R.FrostRadius = 0.22f;
			R.SquirclePower = 3.0f;
			R.EdgeSoftness = 1.0f;
			R.RefractionStrength = 1.0f;
			R.RefractionPower = 3.35f;
			R.RefractionThickness = 48.0f;
			R.IndexOfRefraction = 2.0f;
			R.ChromaticAberration = 0.16f;
			R.PrismIntensity = 1.25f;
			R.NoiseAmount = 0.02f;
			R.GlowAmount = 0.62f;
			R.RimIntensity = 0.55f;
			R.GlowAngle = -135.0f;
			R.InnerGlowIntensity = 0.18f;
			R.InnerShadowIntensity = 0.1f;
			R.TintColor = FLinearColor::White;
			R.TintOpacity = 0.025f;
			R.Saturation = 1.25f;
			R.AdaptiveTintStrength = 0.0f;
			R.GlassOpacity = 1.0f;
			R.Quality = ECBLiquidGlassQuality::Quality;
			R.MotionStrength = 0.55f;
			R.MotionMaxOffset = 42.0f;
			R.MotionResponse = 20.0f;
			R.MotionDamping = 12.0f;
			break;

		case ECBLiquidGlassPreset::MatteLayer:
			R.Shape = ECBLiquidGlassShape::SuperellipseRect;
			R.BlurStrength = 2.3f;
			R.DownsampleAmount = 3;
			R.FrostRadius = 0.65f;
			R.SquirclePower = 7.0f;
			R.EdgeSoftness = 1.05f;
			R.RefractionStrength = 0.22f;
			R.RefractionPower = 1.8f;
			R.RefractionThickness = 18.0f;
			R.IndexOfRefraction = 1.2f;
			R.ChromaticAberration = 0.03f;
			R.PrismIntensity = 0.18f;
			R.NoiseAmount = 0.035f;
			R.GlowAmount = 0.15f;
			R.RimIntensity = 0.16f;
			R.GlowAngle = -135.0f;
			R.InnerGlowIntensity = 0.08f;
			R.InnerShadowIntensity = 0.18f;
			R.TintColor = FLinearColor(0.9f, 0.92f, 0.95f, 1.0f);
			R.TintOpacity = 0.12f;
			R.Saturation = 1.0f;
			R.AdaptiveTintStrength = 0.06f;
			R.GlassOpacity = 0.88f;
			R.Quality = ECBLiquidGlassQuality::Performance;
			R.MotionStrength = 0.12f;
			R.MotionMaxOffset = 18.0f;
			R.MotionResponse = 10.0f;
			R.MotionDamping = 8.0f;
			break;

		case ECBLiquidGlassPreset::SelfLayer:
			R.Shape = ECBLiquidGlassShape::SuperellipseRect;
			R.BlurStrength = 0.35f;
			R.DownsampleAmount = 1;
			R.FrostRadius = 0.06f;
			R.SquirclePower = 7.0f;
			R.EdgeSoftness = 1.0f;
			R.RefractionStrength = 0.85f;
			R.RefractionPower = 2.8f;
			R.RefractionThickness = 36.0f;
			R.IndexOfRefraction = 2.1f;
			R.ChromaticAberration = 0.09f;
			R.PrismIntensity = 0.7f;
			R.NoiseAmount = 0.01f;
			R.GlowAmount = 0.35f;
			R.RimIntensity = 0.3f;
			R.GlowAngle = -135.0f;
			R.InnerGlowIntensity = 0.08f;
			R.InnerShadowIntensity = 0.05f;
			R.TintColor = FLinearColor::White;
			R.TintOpacity = 0.0f;
			R.Saturation = 1.1f;
			R.AdaptiveTintStrength = 0.0f;
			R.GlassOpacity = 1.0f;
			R.Quality = ECBLiquidGlassQuality::Balanced;
			R.MotionStrength = 0.4f;
			R.MotionMaxOffset = 36.0f;
			R.MotionResponse = 18.0f;
			R.MotionDamping = 12.0f;
			break;

		case ECBLiquidGlassPreset::Custom:
		default:
			break;
		}
		return R;
	}
}

// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Vector2D.h"
#include "RHI.h"
#include "Rendering/RenderingCommon.h"

/**
 * Parameters describing one frame of the liquid glass effect, marshalled from the
 * game thread (Slate paint) to the render thread.
 */
struct FCBLiquidGlassRenderParams
{
	/** Glass rectangle in output-texture (backbuffer) pixels. */
	FIntRect Rect = FIntRect(0, 0, 0, 0);

	/** Shape and blur controls, already clamped by the Slate widget where appropriate. */
	float SquirclePower = 7.0f;
	float BlurStrength = 0.95f;
	int32 DownsampleAmount = 2;

	/** Refraction and prism controls. Thickness is expressed in output pixels. */
	float RefractionStrength = 1.0f;
	float RefractionPower = 3.0f;
	float ChromaticAberration = 0.12f;
	float NoiseAmount = 0.018f;

	/** Highlight controls. GlowDir is a normalized 2D direction in local widget space. */
	float GlowAmount = 0.32f;
	float RimIntensity = 0.24f;
	FVector2f GlowDir = FVector2f(-0.7071f, -0.7071f);

	/** Colour treatment applied after background sampling but before edge lighting. */
	FLinearColor TintColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);
	float TintOpacity = 0.015f;
	float Saturation = 1.35f;
	float AdaptiveTintStrength = 0.0f;
	float GlassOpacity = 1.0f;
	float EdgeSoftness = 1.0f;

	/** Extended shape and material parameters consumed by the composite shader. */
	float ShapeMode = 0.0f;
	float RefractionThickness = 40.0f;
	float IndexOfRefraction = 2.0f;
	float FrostRadius = 0.28f;
	float PrismIntensity = 1.0f;
	float InnerGlowIntensity = 0.07f;
	float InnerShadowIntensity = 0.12f;

	/** Quality mode and movement vector used for dynamic liquid deformation. */
	float QualityMode = 1.0f;
	FVector2f MotionVector = FVector2f::ZeroVector;
	float MotionDeformationStrength = 0.0f;

	/** Optional external alpha mask. When valid, the mask replaces the analytic SDF shape alpha. */
	FTextureRHIRef AlphaMaskTextureRHI;
	float UseAlphaMask = 0.0f;
	float AlphaMaskThreshold = 0.5f;
	float AlphaMaskSoftness = 0.08f;
	float AlphaMaskInvert = 0.0f;
};

/**
 * Custom Slate render element that, on the render thread, captures the backbuffer region
 * behind the widget and re-composites it as frosted, refracting "liquid glass".
 *
 * Lifetime: held by a strong TSharedPtr in the owning SWidget and released on the render
 * thread to support render-thread pipelining.
 */
class FCBLiquidGlassSlateElement : public ICustomSlateElement
{
public:
	/** Push this frame's parameters to the render thread. Call from the game thread during paint. */
	void SetRenderParams_GameThread(const FCBLiquidGlassRenderParams& InParams);

	//~ Begin ICustomSlateElement interface
	virtual void Draw_RenderThread(FRDGBuilder& GraphBuilder, const FDrawPassInputs& Inputs) override;
	//~ End ICustomSlateElement interface

private:
	/** Only touched on the render thread. */
	FCBLiquidGlassRenderParams RenderThreadParams;
};

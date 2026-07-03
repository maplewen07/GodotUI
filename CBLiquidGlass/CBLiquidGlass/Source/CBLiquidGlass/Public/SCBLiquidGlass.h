// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class FCBLiquidGlassSlateElement;
class UTexture2D;

/**
 * Slate widget that renders an Apple-style "liquid glass" panel behind its single child:
 * the backbuffer behind it is captured, frosted (blurred), refracted at the rounded edges,
 * adaptively tinted and given a specular rim. Content placed inside is drawn crisply on top.
 */
class CBLIQUIDGLASS_API SCBLiquidGlass : public SCompoundWidget
{
public:
	/** Slate construction arguments mirror the UMG properties so the widget is usable directly in C++. */
	SLATE_BEGIN_ARGS(SCBLiquidGlass)
		: _HAlign(HAlign_Fill)
		, _VAlign(VAlign_Fill)
		, _Padding(FMargin(0.0f))
		, _SquirclePower(7.0f)
		, _BlurStrength(0.95f)
		, _DownsampleAmount(2)
		, _RefractionStrength(1.0f)
		, _RefractionPower(3.0f)
		, _ChromaticAberration(0.12f)
		, _NoiseAmount(0.018f)
		, _GlowAmount(0.32f)
		, _RimIntensity(0.24f)
		, _GlowAngle(-135.0f)
		, _TintColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
		, _TintOpacity(0.015f)
		, _Saturation(1.35f)
		, _AdaptiveTintStrength(0.0f)
		, _GlassOpacity(1.0f)
		, _EdgeSoftness(1.0f)
		, _Shape(ECBLiquidGlassShape::SuperellipseRect)
		, _RefractionThickness(40.0f)
		, _IndexOfRefraction(2.0f)
		, _FrostRadius(0.28f)
		, _PrismIntensity(1.0f)
		, _InnerGlowIntensity(0.07f)
		, _InnerShadowIntensity(0.12f)
		, _Quality(ECBLiquidGlassQuality::Balanced)
		, _MotionStrength(0.0f)
		, _MotionMaxOffset(32.0f)
		, _MotionResponse(16.0f)
		, _MotionDamping(10.0f)
		, _AlphaMaskTexture(nullptr)
		, _AlphaMaskThreshold(0.5f)
		, _AlphaMaskSoftness(0.08f)
		, _bInvertAlphaMask(false)
	{}
		/** Crisp content drawn above the glass composite (not blurred). */
		SLATE_DEFAULT_SLOT(FArguments, Content)
		/** Horizontal alignment of the content within the glass bounds. */
		SLATE_ARGUMENT(EHorizontalAlignment, HAlign)
		/** Vertical alignment of the content within the glass bounds. */
		SLATE_ARGUMENT(EVerticalAlignment, VAlign)
		/** Inner spacing between the glass bounds and the content. */
		SLATE_ATTRIBUTE(FMargin, Padding)
		/** Superellipse corner power for SuperellipseRect; ~4-5 = Apple's continuous corners, higher = boxier. */
		SLATE_ARGUMENT(float, SquirclePower)
		/** Background blur span (texel multiplier); higher is frostier. */
		SLATE_ARGUMENT(float, BlurStrength)
		/** Blur buffer is processed at 1/N resolution; higher is cheaper and softer (1-8). */
		SLATE_ARGUMENT(int32, DownsampleAmount)
		/** Edge lensing amount (0 = none, 1 = full Apple-style edge bending). */
		SLATE_ARGUMENT(float, RefractionStrength)
		/** Edge-bend falloff: higher concentrates refraction tighter against the rim. */
		SLATE_ARGUMENT(float, RefractionPower)
		/** RGB split amount at the refracting edges. */
		SLATE_ARGUMENT(float, ChromaticAberration)
		/** Dither grain added to break gradient banding. */
		SLATE_ARGUMENT(float, NoiseAmount)
		/** Directional edge sheen strength. */
		SLATE_ARGUMENT(float, GlowAmount)
		/** Bright white rim brightness. */
		SLATE_ARGUMENT(float, RimIntensity)
		/** Direction of the rim light/sheen, in degrees. */
		SLATE_ARGUMENT(float, GlowAngle)
		/** Glass tint colour. */
		SLATE_ARGUMENT(FLinearColor, TintColor)
		/** How strongly TintColor is applied (0-1). */
		SLATE_ARGUMENT(float, TintOpacity)
		/** Background saturation multiplier (1 = unchanged); Apple's glass boosts vibrancy. */
		SLATE_ARGUMENT(float, Saturation)
		/** Luminance-adaptive tint: brighten over dark backgrounds, darken over light ones (0-1). */
		SLATE_ARGUMENT(float, AdaptiveTintStrength)
		/** Overall opacity of the glass composite (content stays crisp). */
		SLATE_ARGUMENT(float, GlassOpacity)
		/** Anti-aliasing width multiplier of the shape edge. */
		SLATE_ARGUMENT(float, EdgeSoftness)
		/** Analytic shape mask used by the composite shader. */
		SLATE_ARGUMENT(ECBLiquidGlassShape, Shape)
		/** Width in pixels of the refracting edge band; higher = thicker lensing. */
		SLATE_ARGUMENT(float, RefractionThickness)
		/** Simplified index of refraction (1 = no lens amplification, ~2 = strong glass bend). */
		SLATE_ARGUMENT(float, IndexOfRefraction)
		/** Clear/frost mix (0 = clear capture, 1 = fully frosted). */
		SLATE_ARGUMENT(float, FrostRadius)
		/** Prism-like colour separation multiplier at refracting edges. */
		SLATE_ARGUMENT(float, PrismIntensity)
		/** Soft glow just inside the glass edge band. */
		SLATE_ARGUMENT(float, InnerGlowIntensity)
		/** Inner edge shadow that separates frosted glass from bright backgrounds. */
		SLATE_ARGUMENT(float, InnerShadowIntensity)
		/** Runtime quality profile trading blur/prism detail for cost. */
		SLATE_ARGUMENT(ECBLiquidGlassQuality, Quality)
		/** Liquid motion deformation amount applied while the widget moves (0 disables it). */
		SLATE_ARGUMENT(float, MotionStrength)
		/** Maximum movement offset, in pixels, used by the motion solver. */
		SLATE_ARGUMENT(float, MotionMaxOffset)
		/** How quickly the glass catches up while it is moving (spring response). */
		SLATE_ARGUMENT(float, MotionResponse)
		/** How quickly the glass settles after movement stops (spring damping). */
		SLATE_ARGUMENT(float, MotionDamping)
		/** Optional texture mask that replaces the analytic shape, allowing arbitrary silhouettes. */
		SLATE_ARGUMENT(UTexture2D*, AlphaMaskTexture)
		/** Mask value at which pixels become glass; lower includes more of the texture (0-1). */
		SLATE_ARGUMENT(float, AlphaMaskThreshold)
		/** Soft feather around AlphaMaskThreshold, in normalized alpha space. */
		SLATE_ARGUMENT(float, AlphaMaskSoftness)
		/** Inverts the alpha/RGB mask before thresholding. */
		SLATE_ARGUMENT(bool, bInvertAlphaMask)
	SLATE_END_ARGS()

	SCBLiquidGlass();
	virtual ~SCBLiquidGlass();

	void Construct(const FArguments& InArgs);

	/** Replaces the crisp foreground content drawn above the glass composite. */
	void SetContent(const TSharedRef<SWidget>& InContent);

	/** Forwarded layout controls for UCBLiquidGlassSlot. */
	void SetHAlign(EHorizontalAlignment InHAlign);
	void SetVAlign(EVerticalAlignment InVAlign);
	void SetPadding(TAttribute<FMargin> InPadding);

	/** Visual setters invalidate only paint because these values do not change layout geometry. */
	void SetSquirclePower(float InValue);
	void SetBlurStrength(float InValue);
	void SetDownsampleAmount(int32 InValue);
	void SetRefractionStrength(float InValue);
	void SetRefractionPower(float InValue);
	void SetChromaticAberration(float InValue);
	void SetNoiseAmount(float InValue);
	void SetGlowAmount(float InValue);
	void SetRimIntensity(float InValue);
	void SetGlowAngle(float InDegrees);
	void SetTintColor(FLinearColor InValue);
	void SetTintOpacity(float InValue);
	void SetSaturation(float InValue);
	void SetAdaptiveTintStrength(float InValue);
	void SetGlassOpacity(float InValue);
	void SetEdgeSoftness(float InValue);
	void SetShape(ECBLiquidGlassShape InValue);
	void SetRefractionThickness(float InValue);
	void SetIndexOfRefraction(float InValue);
	void SetFrostRadius(float InValue);
	void SetPrismIntensity(float InValue);
	void SetInnerGlowIntensity(float InValue);
	void SetInnerShadowIntensity(float InValue);
	void SetQuality(ECBLiquidGlassQuality InValue);
	void SetMotionStrength(float InValue);
	void SetMotionMaxOffset(float InValue);
	void SetMotionResponse(float InValue);
	void SetMotionDamping(float InValue);
	void SetAlphaMaskTexture(UTexture2D* InTexture);
	void SetAlphaMaskThreshold(float InValue);
	void SetAlphaMaskSoftness(float InValue);
	void SetInvertAlphaMask(bool bInValue);

	//~ Begin SWidget interface
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	//~ End SWidget interface

private:
	/** Custom render element that owns the render-thread draw call for the frosted background. */
	TSharedPtr<FCBLiquidGlassSlateElement> GlassElement;

	/** Shape and blur controls. */
	float SquirclePower;
	float BlurStrength;
	int32 DownsampleAmount;

	/** Lens controls: bend amount, falloff and prism split. */
	float RefractionStrength;
	float RefractionPower;
	float ChromaticAberration;
	float NoiseAmount;

	/** Rim light controls. */
	float GlowAmount;
	float RimIntensity;
	float GlowAngle;

	/** Colour treatment applied after background sampling. */
	FLinearColor TintColor;
	float TintOpacity;
	float Saturation;
	float AdaptiveTintStrength;
	float GlassOpacity;
	float EdgeSoftness;

	/** Extended Liquid Glass controls introduced for presets and shape variants. */
	ECBLiquidGlassShape Shape;
	float RefractionThickness;
	float IndexOfRefraction;
	float FrostRadius;
	float PrismIntensity;
	float InnerGlowIntensity;
	float InnerShadowIntensity;
	ECBLiquidGlassQuality Quality;
	float MotionStrength;
	float MotionMaxOffset;
	float MotionResponse;
	float MotionDamping;
	TWeakObjectPtr<UTexture2D> AlphaMaskTexture;
	float AlphaMaskThreshold;
	float AlphaMaskSoftness;
	bool bInvertAlphaMask;
	bool bHasLastCenter = false;
	FVector2D LastCenter = FVector2D::ZeroVector;
	FVector2f MotionVector = FVector2f::ZeroVector;
};

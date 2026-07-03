// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Components/ContentWidget.h"
#include "CBLiquidGlassWidget.generated.h"

class SCBLiquidGlass;
class UTexture2D;

/**
 * Liquid Glass is a single-child container that renders an Apple-style frosted, refracting
 * glass panel behind its content. The backbuffer behind the widget is captured, blurred,
 * lensed at the rounded edges (with chromatic aberration), adaptively tinted and given a
 * specular rim highlight. Place any UMG content inside; it is drawn crisply on top.
 */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass"))
class UCBLiquidGlass : public UContentWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlass();

	/** Writes a complete set of visual parameters. Editing any visual parameter switches this back to Custom. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass")
	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::Custom;

	// ---- Blur ----

	/** How far the background is blurred (texel multiplier). Higher = frostier. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Blur", meta = (ClampMin = "0.0", ClampMax = "8.0"))
	float BlurStrength = 0.95f;

	/** Background is processed at 1/N resolution. Higher = cheaper and softer. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Blur", meta = (ClampMin = "1", ClampMax = "8"))
	int32 DownsampleAmount = 2;

	/** Mix between the clear captured background and the blurred/frosted background. 0 = clear, 1 = frosted. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Blur", meta = (ClampMin = "0.0", ClampMax = "1.5"))
	float FrostRadius = 0.28f;

	// ---- Shape ----

	/** Shape mask used by the glass composite shader. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Shape")
	ECBLiquidGlassShape Shape = ECBLiquidGlassShape::SuperellipseRect;

	/** Squircle (superellipse) corner power. ~4-5 gives Apple's continuous-curvature corners; higher = boxier. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Shape", meta = (ClampMin = "2.0", ClampMax = "12.0"))
	float SquirclePower = 7.0f;

	/** Anti-aliasing width multiplier of the shape edge. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, AdvancedDisplay, Category = "Liquid Glass|Shape", meta = (ClampMin = "0.1"))
	float EdgeSoftness = 1.0f;

	// ---- Alpha Mask ----

	/** Optional texture alpha/RGB mask. When set, this replaces the analytic shape and allows arbitrary glass silhouettes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Mask")
	TObjectPtr<UTexture2D> AlphaMaskTexture = nullptr;

	/** Mask value where pixels become glass; lower values include more of the texture. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Mask", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float AlphaMaskThreshold = 0.5f;

	/** Soft feather around the threshold, in normalized alpha space. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Mask", meta = (ClampMin = "0.001", ClampMax = "0.5"))
	float AlphaMaskSoftness = 0.08f;

	/** Inverts the alpha/RGB mask before thresholding. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Mask")
	bool InvertAlphaMask = false;

	// ---- Refraction ----

	/** Lens intensity (0 = none, 1 = full Apple-style edge bending). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Refraction", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float RefractionStrength = 1.0f;

	/** Edge-bend sharpness: higher concentrates the refraction tighter against the rim. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Refraction", meta = (ClampMin = "0.5", ClampMax = "6.0"))
	float RefractionPower = 3.0f;

	/** Width in pixels of the refracting edge band. Higher = thicker lensing at the edge. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Refraction", meta = (ClampMin = "0.0", ClampMax = "160.0"))
	float RefractionThickness = 40.0f;

	/** Simplified index of refraction. 1 = no lens amplification; 2 gives a strong glass bend. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Refraction", meta = (ClampMin = "1.0", ClampMax = "3.0"))
	float IndexOfRefraction = 2.0f;

	/** RGB split amount at the refracting edges. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Refraction", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ChromaticAberration = 0.12f;

	/** Extra multiplier for prism-like colour separation at refracting edges. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Refraction", meta = (ClampMin = "0.0", ClampMax = "3.0"))
	float PrismIntensity = 1.0f;

	/** Grain/dither added to the glass to break up gradient banding. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Refraction", meta = (ClampMin = "0.0", ClampMax = "0.3"))
	float NoiseAmount = 0.018f;

	// ---- Highlight ----

	/** Directional edge sheen strength (brighter on the lit side, darker opposite). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Highlight", meta = (ClampMin = "0.0", ClampMax = "2.0"))
	float GlowAmount = 0.32f;

	/** Bright white edge rim brightness. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Highlight", meta = (ClampMin = "0.0"))
	float RimIntensity = 0.24f;

	/** Direction of the rim light/sheen, in degrees. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Highlight", meta = (ClampMin = "-180.0", ClampMax = "180.0"))
	float GlowAngle = -135.0f;

	/** Soft glow inside the glass edge band. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Highlight", meta = (ClampMin = "0.0", ClampMax = "2.0"))
	float InnerGlowIntensity = 0.07f;

	/** Subtle inner edge shadow that helps menu glass separate from bright backgrounds. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Highlight", meta = (ClampMin = "0.0", ClampMax = "2.0"))
	float InnerShadowIntensity = 0.12f;

	// ---- Tint ----

	/** Glass tint colour. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Tint")
	FLinearColor TintColor = FLinearColor::White;

	/** How strongly the tint colour is applied. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Tint", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float TintOpacity = 0.015f;

	/** Background saturation multiplier (1 = unchanged). Apple's glass boosts colour vibrancy. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Tint", meta = (ClampMin = "0.0", ClampMax = "3.0"))
	float Saturation = 1.35f;

	/** Luminance-adaptive tint: brighten over dark backgrounds, darken over light ones. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, AdvancedDisplay, Category = "Liquid Glass|Tint", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float AdaptiveTintStrength = 0.0f;

	/** Overall opacity of the glass effect. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float GlassOpacity = 1.0f;

	// ---- Motion / Performance ----

	/** Runtime quality profile that trades blur/prism detail for cost. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Performance")
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;

	/** Amount of stretch applied when the widget moves; 0 disables liquid motion deformation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Motion", meta = (ClampMin = "0.0", ClampMax = "3.0"))
	float MotionStrength = 0.0f;

	/** Maximum movement offset, in pixels, used by the deformation solver. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Motion", meta = (ClampMin = "0.0", ClampMax = "160.0"))
	float MotionMaxOffset = 32.0f;

	/** How quickly the glass catches up while it is moving. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Motion", meta = (ClampMin = "0.0", ClampMax = "40.0"))
	float MotionResponse = 16.0f;

	/** How quickly the glass returns to rest after movement stops. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass|Motion", meta = (ClampMin = "0.0", ClampMax = "40.0"))
	float MotionDamping = 10.0f;

	// ---- Setters (Blueprint callable) ----

	/** Applies one of the built-in looks by copying its values into the editable properties. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass")
	CBLIQUIDGLASS_API void SetPreset(ECBLiquidGlassPreset InValue);

	/** Sets how far the captured background is blurred before it is composited back into the widget. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Blur")
	CBLIQUIDGLASS_API void SetBlurStrength(float InValue);

	/** Sets the blur buffer downsample factor; higher values are cheaper and softer. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Blur")
	CBLIQUIDGLASS_API void SetDownsampleAmount(int32 InValue);

	/** Sets the mix between the sharp captured image and the blurred frost image. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Blur")
	CBLIQUIDGLASS_API void SetFrostRadius(float InValue);

	/** Sets the analytic shape used by the composite shader. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Shape")
	CBLIQUIDGLASS_API void SetShape(ECBLiquidGlassShape InValue);

	/** Sets the superellipse corner power used by SuperellipseRect; higher values are boxier. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Shape")
	CBLIQUIDGLASS_API void SetSquirclePower(float InValue);

	/** Sets the antialiasing width multiplier for the analytic shape edge. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Shape")
	CBLIQUIDGLASS_API void SetEdgeSoftness(float InValue);

	/** Sets an optional arbitrary texture alpha/RGB mask for the glass silhouette. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Mask")
	CBLIQUIDGLASS_API void SetAlphaMaskTexture(UTexture2D* InTexture);

	/** Sets the mask threshold used when AlphaMaskTexture is assigned. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Mask")
	CBLIQUIDGLASS_API void SetAlphaMaskThreshold(float InValue);

	/** Sets the feather around AlphaMaskThreshold. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Mask")
	CBLIQUIDGLASS_API void SetAlphaMaskSoftness(float InValue);

	/** Sets whether the alpha mask is inverted before thresholding. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Mask")
	CBLIQUIDGLASS_API void SetInvertAlphaMask(bool bInValue);

	/** Sets the overall lensing strength applied near the glass edge. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Refraction")
	CBLIQUIDGLASS_API void SetRefractionStrength(float InValue);

	/** Sets how sharply refraction falls off from the edge toward the center. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Refraction")
	CBLIQUIDGLASS_API void SetRefractionPower(float InValue);

	/** Sets the width, in pixels, of the edge band that bends background UVs. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Refraction")
	CBLIQUIDGLASS_API void SetRefractionThickness(float InValue);

	/** Sets the stylized index of refraction; 1.0 disables lens amplification. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Refraction")
	CBLIQUIDGLASS_API void SetIndexOfRefraction(float InValue);

	/** Sets the base red/green/blue split amount at refractive edges. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Refraction")
	CBLIQUIDGLASS_API void SetChromaticAberration(float InValue);

	/** Sets the extra multiplier for prism-like colour separation. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Refraction")
	CBLIQUIDGLASS_API void SetPrismIntensity(float InValue);

	/** Sets the subtle grain amount used to reduce smooth blur and tint banding. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Refraction")
	CBLIQUIDGLASS_API void SetNoiseAmount(float InValue);

	/** Sets the directional edge sheen strength. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Highlight")
	CBLIQUIDGLASS_API void SetGlowAmount(float InValue);

	/** Sets the bright rim highlight intensity around the glass edge. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Highlight")
	CBLIQUIDGLASS_API void SetRimIntensity(float InValue);

	/** Sets the rim light direction in degrees. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Highlight")
	CBLIQUIDGLASS_API void SetGlowAngle(float InValue);

	/** Sets the soft light added just inside the glass edge. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Highlight")
	CBLIQUIDGLASS_API void SetInnerGlowIntensity(float InValue);

	/** Sets the inner edge shadow that separates frosted glass from bright backgrounds. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Highlight")
	CBLIQUIDGLASS_API void SetInnerShadowIntensity(float InValue);

	/** Sets the colour blended over the sampled background. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Tint")
	CBLIQUIDGLASS_API void SetTintColor(FLinearColor InValue);

	/** Sets how strongly TintColor is blended over the sampled background. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Tint")
	CBLIQUIDGLASS_API void SetTintOpacity(float InValue);

	/** Sets the saturation multiplier applied before tint and edge lighting. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Tint")
	CBLIQUIDGLASS_API void SetSaturation(float InValue);

	/** Sets adaptive tinting that brightens over dark backgrounds and darkens over light ones. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Tint")
	CBLIQUIDGLASS_API void SetAdaptiveTintStrength(float InValue);

	/** Sets the final alpha of the glass composite while keeping child content fully crisp. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass")
	CBLIQUIDGLASS_API void SetGlassOpacity(float InValue);

	/** Sets the renderer quality profile. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Performance")
	CBLIQUIDGLASS_API void SetQuality(ECBLiquidGlassQuality InValue);

	/** Sets how strongly widget movement stretches the glass shape and refraction. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Motion")
	CBLIQUIDGLASS_API void SetMotionStrength(float InValue);

	/** Sets the maximum movement offset used by motion deformation. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Motion")
	CBLIQUIDGLASS_API void SetMotionMaxOffset(float InValue);

	/** Sets how quickly motion deformation follows active movement. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Motion")
	CBLIQUIDGLASS_API void SetMotionResponse(float InValue);

	/** Sets how quickly motion deformation settles after movement stops. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass|Motion")
	CBLIQUIDGLASS_API void SetMotionDamping(float InValue);

	// ---- Getters (used by the property Getter metadata) ----

	ECBLiquidGlassPreset GetPreset() const { return Preset; }
	float GetBlurStrength() const { return BlurStrength; }
	int32 GetDownsampleAmount() const { return DownsampleAmount; }
	float GetFrostRadius() const { return FrostRadius; }
	ECBLiquidGlassShape GetShape() const { return Shape; }
	float GetSquirclePower() const { return SquirclePower; }
	float GetEdgeSoftness() const { return EdgeSoftness; }
	UTexture2D* GetAlphaMaskTexture() const { return AlphaMaskTexture; }
	float GetAlphaMaskThreshold() const { return AlphaMaskThreshold; }
	float GetAlphaMaskSoftness() const { return AlphaMaskSoftness; }
	bool GetInvertAlphaMask() const { return InvertAlphaMask; }
	float GetRefractionStrength() const { return RefractionStrength; }
	float GetRefractionPower() const { return RefractionPower; }
	float GetRefractionThickness() const { return RefractionThickness; }
	float GetIndexOfRefraction() const { return IndexOfRefraction; }
	float GetChromaticAberration() const { return ChromaticAberration; }
	float GetPrismIntensity() const { return PrismIntensity; }
	float GetNoiseAmount() const { return NoiseAmount; }
	float GetGlowAmount() const { return GlowAmount; }
	float GetRimIntensity() const { return RimIntensity; }
	float GetGlowAngle() const { return GlowAngle; }
	float GetInnerGlowIntensity() const { return InnerGlowIntensity; }
	float GetInnerShadowIntensity() const { return InnerShadowIntensity; }
	FLinearColor GetTintColor() const { return TintColor; }
	float GetTintOpacity() const { return TintOpacity; }
	float GetSaturation() const { return Saturation; }
	float GetAdaptiveTintStrength() const { return AdaptiveTintStrength; }
	float GetGlassOpacity() const { return GlassOpacity; }
	ECBLiquidGlassQuality GetQuality() const { return Quality; }
	float GetMotionStrength() const { return MotionStrength; }
	float GetMotionMaxOffset() const { return MotionMaxOffset; }
	float GetMotionResponse() const { return MotionResponse; }
	float GetMotionDamping() const { return MotionDamping; }

	//~ Begin UWidget interface
	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UWidget interface

#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
	CBLIQUIDGLASS_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	//~ Begin UPanelWidget / UWidget interface
	CBLIQUIDGLASS_API virtual UClass* GetSlotClass() const override;
	CBLIQUIDGLASS_API virtual void OnSlotAdded(UPanelSlot* InSlot) override;
	CBLIQUIDGLASS_API virtual void OnSlotRemoved(UPanelSlot* InSlot) override;
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;
	//~ End UPanelWidget / UWidget interface

private:
	/** Copies preset defaults into editable UPROPERTY values; does not keep the preset live-linked. */
	void ApplyPresetProperties(ECBLiquidGlassPreset InPreset);

	/** Pushes the current UPROPERTY state into the live Slate widget, if it has been rebuilt. */
	void PushPropertiesToSlate();

	/** Used by manual edits so presets remain a write-once shortcut rather than an overriding style. */
	void MarkPresetCustom();

	/** Live Slate implementation owned by this UMG wrapper. Null before RebuildWidget and after release. */
	TSharedPtr<SCBLiquidGlass> MyGlass;
};

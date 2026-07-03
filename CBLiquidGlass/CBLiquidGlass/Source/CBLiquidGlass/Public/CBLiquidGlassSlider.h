// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Components/Widget.h"
#include "CBLiquidGlassSlider.generated.h"

class SCBLiquidGlassSlider;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCBLiquidGlassSliderValueChangedEvent, float, Value);

/** UMG slider with a liquid-glass thumb and spring-driven jelly motion while dragging. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Slider"))
class UCBLiquidGlassSlider : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassSlider();

	/** Current slider value. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider", meta = (UIMin = "0.0", UIMax = "1.0"))
	float Value = 0.5f;

	/** Minimum logical value. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider")
	float MinValue = 0.0f;

	/** Maximum logical value. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider")
	float MaxValue = 1.0f;

	/** Desired Slate width of the slider. UMG layout can still scale the widget. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Layout", meta = (ClampMin = "32.0"))
	float SliderLength = 560.0f;

	/** Desired Slate height used by the animated thumb and track. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Layout", meta = (ClampMin = "12.0"))
	float SliderHeight = 88.0f;

	/** Height of the line track behind the glass thumb. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Layout", meta = (ClampMin = "2.0"))
	float TrackHeight = 10.0f;

	/** Resting thumb size before jelly stretch is applied. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Layout")
	FVector2D ThumbSize = FVector2D(142.0f, 58.0f);

	/** Colour of the filled progress bar. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Style")
	FLinearColor FillColor = FLinearColor(0.0f, 0.45f, 1.0f, 1.0f);

	/** Tint applied to the translucent track glass. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Style")
	FLinearColor TrackTint = FLinearColor::White;

	/** Overall opacity of the translucent track glass. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Style", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float TrackOpacity = 0.54f;

	/** Preset used by the movable glass thumb. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Style")
	ECBLiquidGlassPreset ThumbPreset = ECBLiquidGlassPreset::PillLens;

	/** Renderer quality for the track and thumb. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Performance")
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;

	/** Multiplier for the subtle liquid stretch. 0 disables the extra width/height deformation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Jelly", meta = (ClampMin = "0.0", ClampMax = "4.0"))
	float ThumbBounce = 0.7f;

	/** How quickly the visual thumb catches the real value. Higher = snappier and less laggy. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Jelly", meta = (ClampMin = "1.0", ClampMax = "60.0"))
	float ThumbResponse = 25.0f;

	/** Spring damping ratio control. Around 8-10 gives a restrained Apple-like bounce. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Jelly", meta = (ClampMin = "0.0", ClampMax = "40.0"))
	float ThumbDamping = 8.8f;

	/** Extra shader deformation applied to the glass thumb as it moves. Keep this low for an Apple-like feel. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Slider|Jelly", meta = (ClampMin = "0.0", ClampMax = "3.0"))
	float ThumbMotionStrength = 0.86f;

	/** Broadcast whenever user input changes the value. */
	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Slider|Event")
	FCBLiquidGlassSliderValueChangedEvent OnValueChanged;

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider")
	CBLIQUIDGLASS_API void SetValue(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider")
	CBLIQUIDGLASS_API void SetMinValue(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider")
	CBLIQUIDGLASS_API void SetMaxValue(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Layout")
	CBLIQUIDGLASS_API void SetSliderLength(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Layout")
	CBLIQUIDGLASS_API void SetSliderHeight(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Layout")
	CBLIQUIDGLASS_API void SetTrackHeight(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Layout")
	CBLIQUIDGLASS_API void SetThumbSize(FVector2D InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Style")
	CBLIQUIDGLASS_API void SetFillColor(FLinearColor InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Style")
	CBLIQUIDGLASS_API void SetTrackTint(FLinearColor InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Style")
	CBLIQUIDGLASS_API void SetTrackOpacity(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Style")
	CBLIQUIDGLASS_API void SetThumbPreset(ECBLiquidGlassPreset InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Performance")
	CBLIQUIDGLASS_API void SetQuality(ECBLiquidGlassQuality InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Jelly")
	CBLIQUIDGLASS_API void SetThumbBounce(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Jelly")
	CBLIQUIDGLASS_API void SetThumbResponse(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Jelly")
	CBLIQUIDGLASS_API void SetThumbDamping(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Slider|Jelly")
	CBLIQUIDGLASS_API void SetThumbMotionStrength(float InValue);

	float GetValue() const { return Value; }
	float GetMinValue() const { return MinValue; }
	float GetMaxValue() const { return MaxValue; }
	float GetSliderLength() const { return SliderLength; }
	float GetSliderHeight() const { return SliderHeight; }
	float GetTrackHeight() const { return TrackHeight; }
	FVector2D GetThumbSize() const { return ThumbSize; }
	FLinearColor GetFillColor() const { return FillColor; }
	FLinearColor GetTrackTint() const { return TrackTint; }
	float GetTrackOpacity() const { return TrackOpacity; }
	ECBLiquidGlassPreset GetThumbPreset() const { return ThumbPreset; }
	ECBLiquidGlassQuality GetQuality() const { return Quality; }
	float GetThumbBounce() const { return ThumbBounce; }
	float GetThumbResponse() const { return ThumbResponse; }
	float GetThumbDamping() const { return ThumbDamping; }
	float GetThumbMotionStrength() const { return ThumbMotionStrength; }

	//~ Begin UWidget interface
	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UWidget interface

#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	//~ Begin UWidget interface
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;
	//~ End UWidget interface

private:
	void HandleSlateValueChanged(float InValue);
	void PushPropertiesToSlate();

	TSharedPtr<SCBLiquidGlassSlider> MySlider;
};

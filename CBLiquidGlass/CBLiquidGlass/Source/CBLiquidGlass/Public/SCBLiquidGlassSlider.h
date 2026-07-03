// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class SCBLiquidGlass;
class SCanvas;

DECLARE_DELEGATE_OneParam(FCBLiquidGlassSliderValueChanged, float);

/**
 * Slate slider with a liquid-glass thumb and spring-driven jelly motion.
 *
 * The logical value updates immediately from pointer input, while the visual thumb follows
 * through a damped spring. That separation gives the control a soft, Q-elastic feel without
 * making Blueprint value reads lag behind the user's drag.
 */
class CBLIQUIDGLASS_API SCBLiquidGlassSlider : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassSlider)
		: _Value(0.5f)
		, _MinValue(0.0f)
		, _MaxValue(1.0f)
		, _SliderLength(560.0f)
		, _SliderHeight(88.0f)
		, _TrackHeight(10.0f)
		, _ThumbSize(FVector2D(142.0f, 58.0f))
		, _FillColor(FLinearColor(0.0f, 0.45f, 1.0f, 1.0f))
		, _TrackTint(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
		, _TrackOpacity(0.54f)
		, _ThumbPreset(ECBLiquidGlassPreset::PillLens)
		, _Quality(ECBLiquidGlassQuality::Balanced)
		, _ThumbBounce(0.7f)
		, _ThumbResponse(25.0f)
		, _ThumbDamping(8.8f)
		, _ThumbMotionStrength(0.86f)
	{}
		/** Logical value; updates immediately on input while the visual thumb springs to follow. */
		SLATE_ARGUMENT(float, Value)
		/** Lower bound of the value range. */
		SLATE_ARGUMENT(float, MinValue)
		/** Upper bound of the value range. */
		SLATE_ARGUMENT(float, MaxValue)
		/** Overall track length, in pixels. */
		SLATE_ARGUMENT(float, SliderLength)
		/** Overall control height, in pixels (the interactive band, not the thin track). */
		SLATE_ARGUMENT(float, SliderHeight)
		/** Thickness of the glass track/fill capsule, in pixels. */
		SLATE_ARGUMENT(float, TrackHeight)
		/** Rest size of the glass thumb before jelly stretch is applied. */
		SLATE_ARGUMENT(FVector2D, ThumbSize)
		/** Tint of the filled (progress) portion of the track. */
		SLATE_ARGUMENT(FLinearColor, FillColor)
		/** Tint of the unfilled track behind the fill. */
		SLATE_ARGUMENT(FLinearColor, TrackTint)
		/** Composite opacity of the unfilled track (0-1). */
		SLATE_ARGUMENT(float, TrackOpacity)
		/** Base glass material used for the thumb. */
		SLATE_ARGUMENT(ECBLiquidGlassPreset, ThumbPreset)
		/** Runtime quality profile applied to all three glass layers. */
		SLATE_ARGUMENT(ECBLiquidGlassQuality, Quality)
		/** Jelly stretch amount when the thumb moves; 0 disables the elastic deform (0-4). */
		SLATE_ARGUMENT(float, ThumbBounce)
		/** Spring response of the visual thumb following the value; higher is tighter (1-60). */
		SLATE_ARGUMENT(float, ThumbResponse)
		/** Spring damping of the visual thumb; ~8-10 gives Apple's light settle (0-40). */
		SLATE_ARGUMENT(float, ThumbDamping)
		/** Shader-level motion deformation strength on the thumb glass itself (0-3). */
		SLATE_ARGUMENT(float, ThumbMotionStrength)
		/** Fired with the new logical value whenever the user drags the slider. */
		SLATE_EVENT(FCBLiquidGlassSliderValueChanged, OnValueChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Sets the logical value (clamped to [Min, Max]); does not broadcast OnValueChanged. */
	void SetValue(float InValue);
	/** Sets the lower bound; raises Max to match if it would invert, then re-clamps Value. */
	void SetMinValue(float InValue);
	/** Sets the upper bound; lowers Min to match if it would invert, then re-clamps Value. */
	void SetMaxValue(float InValue);
	/** Sets the track length in pixels (min 32). */
	void SetSliderLength(float InValue);
	/** Sets the control height in pixels (min 12). */
	void SetSliderHeight(float InValue);
	/** Sets the track/fill capsule thickness; clamped to [2, SliderHeight]. */
	void SetTrackHeight(float InValue);
	/** Sets the thumb rest size (min 20x16). */
	void SetThumbSize(FVector2D InValue);
	/** Sets the fill (progress) tint. */
	void SetFillColor(FLinearColor InValue);
	/** Sets the unfilled track tint. */
	void SetTrackTint(FLinearColor InValue);
	/** Sets the unfilled track opacity; clamped to [0, 1]. */
	void SetTrackOpacity(float InValue);
	/** Sets the thumb's base glass material and re-applies the thumb style. */
	void SetThumbPreset(ECBLiquidGlassPreset InValue);
	/** Sets the quality profile on all three glass layers. */
	void SetQuality(ECBLiquidGlassQuality InValue);
	/** Sets the jelly stretch amount; clamped to [0, 4]. */
	void SetThumbBounce(float InValue);
	/** Sets the visual-thumb spring response; clamped to [1, 60]. */
	void SetThumbResponse(float InValue);
	/** Sets the visual-thumb spring damping; clamped to [0, 40]. */
	void SetThumbDamping(float InValue);
	/** Sets the thumb glass shader motion deformation; clamped to [0, 3]. */
	void SetThumbMotionStrength(float InValue);
	/** Replaces the value-changed handler. */
	void SetOnValueChanged(FCBLiquidGlassSliderValueChanged InDelegate);

	float GetValue() const { return Value; }

	//~ Begin SWidget interface
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseCaptureLost(const FCaptureLostEvent& CaptureLostEvent) override;
	virtual bool IsInteractable() const override { return IsEnabled(); }
	//~ End SWidget interface

private:
	void RebuildLayout();
	void ApplyThumbStyle();
	void CommitValue(float InValue, bool bBroadcast);
	void UpdateValueFromPointer(const FGeometry& MyGeometry, const FVector2D& ScreenPosition);
	void ResetVisualIfNeeded();

	float GetNormalizedValue() const;
	float GetDisplayNormalizedValue() const;
	float GetUsableWidth() const;
	float GetThumbStretch() const;
	float GetThumbMotionOffset() const;
	float GetThumbVisualWidth() const;
	float GetThumbVisualHeight() const;
	float GetThumbCenterX() const;
	FLinearColor GetFillColor() const { return FillColor; }

	FVector2D GetTrackPosition() const;
	FVector2D GetTrackSize() const;
	FVector2D GetFillPosition() const;
	FVector2D GetFillSize() const;
	FVector2D GetThumbPosition() const;
	FVector2D GetThumbVisualSize() const;

	TSharedPtr<SCanvas> Canvas;
	TSharedPtr<SCBLiquidGlass> TrackGlass;
	TSharedPtr<SCBLiquidGlass> FillGlass;
	TSharedPtr<SCBLiquidGlass> ThumbGlass;
	FCBLiquidGlassSliderValueChanged OnValueChanged;

	float Value = 0.5f;
	float MinValue = 0.0f;
	float MaxValue = 1.0f;
	float SliderLength = 560.0f;
	float SliderHeight = 88.0f;
	float TrackHeight = 10.0f;
	FVector2D ThumbSize = FVector2D(142.0f, 58.0f);
	FLinearColor FillColor = FLinearColor(0.0f, 0.45f, 1.0f, 1.0f);
	FLinearColor TrackTint = FLinearColor::White;
	float TrackOpacity = 0.54f;
	ECBLiquidGlassPreset ThumbPreset = ECBLiquidGlassPreset::PillLens;
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;
	float ThumbBounce = 0.7f;
	float ThumbResponse = 25.0f;
	float ThumbDamping = 8.8f;
	float ThumbMotionStrength = 0.86f;

	bool bDragging = false;
	bool bVisualInitialized = false;
	float VisualNormalizedValue = 0.5f;
	float VisualVelocity = 0.0f;
};

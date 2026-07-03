// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class SCBLiquidGlass;

/** Slate interaction wrapper that turns SCBLiquidGlass into a hover/press-aware button. */
class CBLIQUIDGLASS_API SCBLiquidGlassButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassButton)
		: _HAlign(HAlign_Center)
		, _VAlign(VAlign_Center)
		, _Padding(FMargin(16.0f, 8.0f))
		, _Preset(ECBLiquidGlassPreset::PillLens)
		, _Shape(ECBLiquidGlassShape::Capsule)
		, _HoverGlowBoost(0.18f)
		, _PressedRefractionBoost(0.14f)
		, _PressedTintBoost(0.035f)
		, _DisabledOpacity(0.38f)
	{}
		/** Crisp content (label/icon) drawn above the interactive glass background. */
		SLATE_DEFAULT_SLOT(FArguments, Content)
		/** Horizontal alignment of the content inside the button. */
		SLATE_ARGUMENT(EHorizontalAlignment, HAlign)
		/** Vertical alignment of the content inside the button. */
		SLATE_ARGUMENT(EVerticalAlignment, VAlign)
		/** Inner spacing between the glass bounds and the content. */
		SLATE_ATTRIBUTE(FMargin, Padding)
		/** Base glass look applied at rest (the Apple-style ".glass" material the button starts from). */
		SLATE_ARGUMENT(ECBLiquidGlassPreset, Preset)
		/** Glass silhouette; Capsule matches Apple's pill buttons. */
		SLATE_ARGUMENT(ECBLiquidGlassShape, Shape)
		/** Extra rim/glow added while hovered, layered on top of the preset (0-2). */
		SLATE_ARGUMENT(float, HoverGlowBoost)
		/** Extra edge refraction added while pressed, like Apple's "interactive" press response (0-1). */
		SLATE_ARGUMENT(float, PressedRefractionBoost)
		/** Extra tint added while pressed to darken/deepen the glass (0-1). */
		SLATE_ARGUMENT(float, PressedTintBoost)
		/** Composite opacity multiplier applied while the button is disabled (0-1). */
		SLATE_ARGUMENT(float, DisabledOpacity)
		/** Fired on a completed click (press and release inside the button). */
		SLATE_EVENT(FSimpleDelegate, OnClicked)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Replaces the content drawn crisply above the interactive glass background. */
	void SetContent(const TSharedRef<SWidget>& InContent);

	/** Forwarded layout controls used by the UMG slot. */
	void SetHAlign(EHorizontalAlignment InHAlign);
	void SetVAlign(EVerticalAlignment InVAlign);
	void SetPadding(TAttribute<FMargin> InPadding);

	/** Switches the base glass material and re-applies the current hover/press state. */
	void SetPreset(ECBLiquidGlassPreset InValue);
	/** Sets the glass silhouette (Capsule, SuperellipseRect, ...). */
	void SetShape(ECBLiquidGlassShape InValue);
	/** Sets the extra rim/glow added on hover; clamped to [0, 2]. */
	void SetHoverGlowBoost(float InValue);
	/** Sets the extra edge refraction added on press; clamped to [0, 1]. */
	void SetPressedRefractionBoost(float InValue);
	/** Sets the extra tint added on press; clamped to [0, 1]. */
	void SetPressedTintBoost(float InValue);
	/** Sets the composite opacity used while disabled; clamped to [0, 1]. */
	void SetDisabledOpacity(float InValue);
	/** Replaces the click handler. */
	void SetOnClicked(FSimpleDelegate InDelegate);

	//~ Begin SWidget interface
	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual bool IsInteractable() const override { return IsEnabled(); }
	//~ End SWidget interface

private:
	void ApplyPresetBase();
	void ApplyInteractionState();

	TSharedPtr<SCBLiquidGlass> Glass;
	FSimpleDelegate OnClicked;

	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::PillLens;
	ECBLiquidGlassShape Shape = ECBLiquidGlassShape::Capsule;
	float HoverGlowBoost = 0.18f;
	float PressedRefractionBoost = 0.14f;
	float PressedTintBoost = 0.035f;
	float DisabledOpacity = 0.38f;

	float BaseGlowAmount = 0.42f;
	float BaseRimIntensity = 0.34f;
	float BaseRefractionStrength = 1.0f;
	float BaseTintOpacity = 0.01f;
	float BaseGlassOpacity = 1.0f;
	bool bHovered = false;
	bool bPressed = false;
};

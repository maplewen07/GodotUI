// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "SCBLiquidGlassButton.h"
#include "SCBLiquidGlass.h"
#include "Input/Events.h"
#include "InputCoreTypes.h"

void SCBLiquidGlassButton::Construct(const FArguments& InArgs)
{
	Preset = InArgs._Preset;
	Shape = InArgs._Shape;
	HoverGlowBoost = InArgs._HoverGlowBoost;
	PressedRefractionBoost = InArgs._PressedRefractionBoost;
	PressedTintBoost = InArgs._PressedTintBoost;
	DisabledOpacity = InArgs._DisabledOpacity;
	OnClicked = InArgs._OnClicked;

	ChildSlot
	[
		SAssignNew(Glass, SCBLiquidGlass)
		.HAlign(InArgs._HAlign)
		.VAlign(InArgs._VAlign)
		.Padding(InArgs._Padding)
		[
			InArgs._Content.Widget
		]
	];

	ApplyPresetBase();
	ApplyInteractionState();
}

void SCBLiquidGlassButton::SetContent(const TSharedRef<SWidget>& InContent)
{
	if (Glass.IsValid())
	{
		Glass->SetContent(InContent);
	}
}

void SCBLiquidGlassButton::SetHAlign(EHorizontalAlignment InHAlign)
{
	if (Glass.IsValid())
	{
		Glass->SetHAlign(InHAlign);
	}
}

void SCBLiquidGlassButton::SetVAlign(EVerticalAlignment InVAlign)
{
	if (Glass.IsValid())
	{
		Glass->SetVAlign(InVAlign);
	}
}

void SCBLiquidGlassButton::SetPadding(TAttribute<FMargin> InPadding)
{
	if (Glass.IsValid())
	{
		Glass->SetPadding(MoveTemp(InPadding));
	}
}

void SCBLiquidGlassButton::SetPreset(ECBLiquidGlassPreset InValue)
{
	if (Preset != InValue)
	{
		Preset = InValue;
		ApplyPresetBase();
		ApplyInteractionState();
	}
}

void SCBLiquidGlassButton::SetShape(ECBLiquidGlassShape InValue)
{
	Shape = InValue;
	if (Glass.IsValid())
	{
		Glass->SetShape(Shape);
	}
}

void SCBLiquidGlassButton::SetHoverGlowBoost(float InValue)
{
	// Additive rim/glow boost; negative values would dim on hover, so keep it non-negative.
	HoverGlowBoost = FMath::Clamp(InValue, 0.0f, 2.0f);
	ApplyInteractionState();
}

void SCBLiquidGlassButton::SetPressedRefractionBoost(float InValue)
{
	PressedRefractionBoost = FMath::Clamp(InValue, 0.0f, 1.0f);
	ApplyInteractionState();
}

void SCBLiquidGlassButton::SetPressedTintBoost(float InValue)
{
	PressedTintBoost = FMath::Clamp(InValue, 0.0f, 1.0f);
	ApplyInteractionState();
}

void SCBLiquidGlassButton::SetDisabledOpacity(float InValue)
{
	DisabledOpacity = FMath::Clamp(InValue, 0.0f, 1.0f);
	ApplyInteractionState();
}

void SCBLiquidGlassButton::SetOnClicked(FSimpleDelegate InDelegate)
{
	OnClicked = MoveTemp(InDelegate);
}

void SCBLiquidGlassButton::OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCompoundWidget::OnMouseEnter(MyGeometry, MouseEvent);
	bHovered = true;
	ApplyInteractionState();
}

void SCBLiquidGlassButton::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	SCompoundWidget::OnMouseLeave(MouseEvent);
	bHovered = false;
	bPressed = false;
	ApplyInteractionState();
}

FReply SCBLiquidGlassButton::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (IsEnabled() && MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		bPressed = true;
		ApplyInteractionState();
		return FReply::Handled().CaptureMouse(SharedThis(this));
	}

	return FReply::Unhandled();
}

FReply SCBLiquidGlassButton::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && HasMouseCapture())
	{
		const bool bWasPressed = bPressed;
		bPressed = false;
		ApplyInteractionState();

		FReply Reply = FReply::Handled().ReleaseMouseCapture();
		if (bWasPressed && MyGeometry.IsUnderLocation(MouseEvent.GetScreenSpacePosition()) && OnClicked.IsBound())
		{
			OnClicked.Execute();
		}
		return Reply;
	}

	return FReply::Unhandled();
}

void SCBLiquidGlassButton::ApplyPresetBase()
{
	if (!Glass.IsValid())
	{
		return;
	}

	Glass->SetShape(Shape);
	Glass->SetQuality(ECBLiquidGlassQuality::Balanced);
	Glass->SetMotionStrength(0.22f);
	Glass->SetMotionMaxOffset(24.0f);

	switch (Preset)
	{
	case ECBLiquidGlassPreset::Clear:
		BaseGlowAmount = 0.32f;
		BaseRimIntensity = 0.24f;
		BaseRefractionStrength = 1.0f;
		BaseTintOpacity = 0.01f;
		BaseGlassOpacity = 1.0f;
		Glass->SetBlurStrength(0.45f);
		Glass->SetFrostRadius(0.08f);
		Glass->SetRefractionThickness(42.0f);
		Glass->SetIndexOfRefraction(2.0f);
		break;

	case ECBLiquidGlassPreset::FrostedMenu:
		BaseGlowAmount = 0.24f;
		BaseRimIntensity = 0.2f;
		BaseRefractionStrength = 0.55f;
		BaseTintOpacity = 0.075f;
		BaseGlassOpacity = 0.9f;
		Glass->SetBlurStrength(1.25f);
		Glass->SetFrostRadius(0.46f);
		Glass->SetRefractionThickness(28.0f);
		Glass->SetIndexOfRefraction(1.5f);
		break;

	case ECBLiquidGlassPreset::MatteLayer:
		BaseGlowAmount = 0.16f;
		BaseRimIntensity = 0.14f;
		BaseRefractionStrength = 0.22f;
		BaseTintOpacity = 0.12f;
		BaseGlassOpacity = 0.88f;
		Glass->SetBlurStrength(2.2f);
		Glass->SetFrostRadius(0.65f);
		Glass->SetRefractionThickness(18.0f);
		Glass->SetIndexOfRefraction(1.2f);
		break;

	case ECBLiquidGlassPreset::PillLens:
	default:
		BaseGlowAmount = 0.42f;
		BaseRimIntensity = 0.34f;
		BaseRefractionStrength = 1.0f;
		BaseTintOpacity = 0.012f;
		BaseGlassOpacity = 1.0f;
		Glass->SetBlurStrength(0.55f);
		Glass->SetFrostRadius(0.18f);
		Glass->SetRefractionThickness(46.0f);
		Glass->SetIndexOfRefraction(2.0f);
		break;
	}

	Glass->SetRefractionPower(3.2f);
	Glass->SetChromaticAberration(0.1f);
	Glass->SetPrismIntensity(0.85f);
	Glass->SetInnerGlowIntensity(0.08f);
	Glass->SetInnerShadowIntensity(0.08f);
	Glass->SetSaturation(1.25f);
}

void SCBLiquidGlassButton::ApplyInteractionState()
{
	if (!Glass.IsValid())
	{
		return;
	}

	const float HoverAlpha = bHovered ? 1.0f : 0.0f;
	const float PressAlpha = bPressed ? 1.0f : 0.0f;
	const float EnabledAlpha = IsEnabled() ? 1.0f : FMath::Clamp(DisabledOpacity, 0.0f, 1.0f);

	Glass->SetGlowAmount(BaseGlowAmount + HoverGlowBoost * HoverAlpha);
	Glass->SetRimIntensity(BaseRimIntensity + HoverGlowBoost * 0.55f * HoverAlpha);
	Glass->SetRefractionStrength(FMath::Clamp(BaseRefractionStrength + PressedRefractionBoost * PressAlpha, 0.0f, 1.0f));
	Glass->SetTintOpacity(FMath::Clamp(BaseTintOpacity + PressedTintBoost * PressAlpha, 0.0f, 1.0f));
	Glass->SetGlassOpacity(BaseGlassOpacity * EnabledAlpha);
}

// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassButton.h"
#include "CBLiquidGlassButtonSlot.h"
#include "SCBLiquidGlassButton.h"
#include "Widgets/SNullWidget.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlassButton"

UCBLiquidGlassButton::UCBLiquidGlassButton()
{
	bIsVariable = false;
}

UClass* UCBLiquidGlassButton::GetSlotClass() const
{
	return UCBLiquidGlassButtonSlot::StaticClass();
}

void UCBLiquidGlassButton::OnSlotAdded(UPanelSlot* InSlot)
{
	if (MyButton.IsValid())
	{
		if (UCBLiquidGlassButtonSlot* ButtonSlot = Cast<UCBLiquidGlassButtonSlot>(InSlot))
		{
			ButtonSlot->BuildSlot(MyButton.ToSharedRef());
		}
	}
}

void UCBLiquidGlassButton::OnSlotRemoved(UPanelSlot* InSlot)
{
	if (MyButton.IsValid())
	{
		MyButton->SetContent(SNullWidget::NullWidget);
	}
}

TSharedRef<SWidget> UCBLiquidGlassButton::RebuildWidget()
{
	MyButton = SNew(SCBLiquidGlassButton)
		.Preset(Preset)
		.Shape(Shape)
		.HoverGlowBoost(HoverGlowBoost)
		.PressedRefractionBoost(PressedRefractionBoost)
		.PressedTintBoost(PressedTintBoost)
		.DisabledOpacity(DisabledOpacity)
		.OnClicked(FSimpleDelegate::CreateUObject(this, &UCBLiquidGlassButton::HandleSlateClicked));

	if (UCBLiquidGlassButtonSlot* ButtonSlot = Cast<UCBLiquidGlassButtonSlot>(GetContentSlot()))
	{
		ButtonSlot->BuildSlot(MyButton.ToSharedRef());
	}

	return MyButton.ToSharedRef();
}

void UCBLiquidGlassButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassButton::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyButton.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassButton::GetPaletteCategory()
{
	return LOCTEXT("LiquidGlassPaletteCategory", "Liquid Glass");
}
#endif

void UCBLiquidGlassButton::SetPreset(ECBLiquidGlassPreset InValue)
{
	Preset = InValue;
	if (MyButton.IsValid())
	{
		MyButton->SetPreset(InValue);
	}
}

void UCBLiquidGlassButton::SetShape(ECBLiquidGlassShape InValue)
{
	Shape = InValue;
	if (MyButton.IsValid())
	{
		MyButton->SetShape(InValue);
	}
}

void UCBLiquidGlassButton::SetHoverGlowBoost(float InValue)
{
	HoverGlowBoost = InValue;
	if (MyButton.IsValid())
	{
		MyButton->SetHoverGlowBoost(InValue);
	}
}

void UCBLiquidGlassButton::SetPressedRefractionBoost(float InValue)
{
	PressedRefractionBoost = InValue;
	if (MyButton.IsValid())
	{
		MyButton->SetPressedRefractionBoost(InValue);
	}
}

void UCBLiquidGlassButton::SetPressedTintBoost(float InValue)
{
	PressedTintBoost = InValue;
	if (MyButton.IsValid())
	{
		MyButton->SetPressedTintBoost(InValue);
	}
}

void UCBLiquidGlassButton::SetDisabledOpacity(float InValue)
{
	DisabledOpacity = InValue;
	if (MyButton.IsValid())
	{
		MyButton->SetDisabledOpacity(InValue);
	}
}

void UCBLiquidGlassButton::HandleSlateClicked()
{
	OnClicked.Broadcast();
}

void UCBLiquidGlassButton::PushPropertiesToSlate()
{
	if (!MyButton.IsValid())
	{
		return;
	}

	MyButton->SetPreset(Preset);
	MyButton->SetShape(Shape);
	MyButton->SetHoverGlowBoost(HoverGlowBoost);
	MyButton->SetPressedRefractionBoost(PressedRefractionBoost);
	MyButton->SetPressedTintBoost(PressedTintBoost);
	MyButton->SetDisabledOpacity(DisabledOpacity);
	MyButton->SetOnClicked(FSimpleDelegate::CreateUObject(this, &UCBLiquidGlassButton::HandleSlateClicked));
}

#undef LOCTEXT_NAMESPACE

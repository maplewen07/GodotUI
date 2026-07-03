// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassButtonSlot.h"
#include "SCBLiquidGlassButton.h"
#include "Components/Widget.h"

void UCBLiquidGlassButtonSlot::SetPadding(FMargin InPadding)
{
	Padding = InPadding;
	if (TSharedPtr<SCBLiquidGlassButton> Pinned = Button.Pin())
	{
		Pinned->SetPadding(InPadding);
	}
}

void UCBLiquidGlassButtonSlot::SetHorizontalAlignment(EHorizontalAlignment InHorizontalAlignment)
{
	HorizontalAlignment = InHorizontalAlignment;
	if (TSharedPtr<SCBLiquidGlassButton> Pinned = Button.Pin())
	{
		Pinned->SetHAlign(InHorizontalAlignment);
	}
}

void UCBLiquidGlassButtonSlot::SetVerticalAlignment(EVerticalAlignment InVerticalAlignment)
{
	VerticalAlignment = InVerticalAlignment;
	if (TSharedPtr<SCBLiquidGlassButton> Pinned = Button.Pin())
	{
		Pinned->SetVAlign(InVerticalAlignment);
	}
}

void UCBLiquidGlassButtonSlot::SynchronizeProperties()
{
	SetPadding(Padding);
	SetHorizontalAlignment(HorizontalAlignment);
	SetVerticalAlignment(VerticalAlignment);
}

void UCBLiquidGlassButtonSlot::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	Button.Reset();
}

void UCBLiquidGlassButtonSlot::BuildSlot(TSharedRef<SCBLiquidGlassButton> InButton)
{
	Button = InButton;

	InButton->SetPadding(Padding);
	InButton->SetHAlign(HorizontalAlignment);
	InButton->SetVAlign(VerticalAlignment);
	InButton->SetContent(Content ? Content->TakeWidget() : SNullWidget::NullWidget);
}

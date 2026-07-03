// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassSlot.h"
#include "SCBLiquidGlass.h"
#include "Components/Widget.h"

void UCBLiquidGlassSlot::SetPadding(FMargin InPadding)
{
	Padding = InPadding;

	// Slot properties can change after the Slate widget has been built, so forward live updates.
	if (TSharedPtr<SCBLiquidGlass> Pinned = Glass.Pin())
	{
		Pinned->SetPadding(InPadding);
	}
}

void UCBLiquidGlassSlot::SetHorizontalAlignment(EHorizontalAlignment InHorizontalAlignment)
{
	HorizontalAlignment = InHorizontalAlignment;
	if (TSharedPtr<SCBLiquidGlass> Pinned = Glass.Pin())
	{
		Pinned->SetHAlign(InHorizontalAlignment);
	}
}

void UCBLiquidGlassSlot::SetVerticalAlignment(EVerticalAlignment InVerticalAlignment)
{
	VerticalAlignment = InVerticalAlignment;
	if (TSharedPtr<SCBLiquidGlass> Pinned = Glass.Pin())
	{
		Pinned->SetVAlign(InVerticalAlignment);
	}
}

void UCBLiquidGlassSlot::SynchronizeProperties()
{
	// Route through setters to keep design-time synchronization and runtime mutation identical.
	SetPadding(Padding);
	SetHorizontalAlignment(HorizontalAlignment);
	SetVerticalAlignment(VerticalAlignment);
}

void UCBLiquidGlassSlot::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	Glass.Reset();
}

void UCBLiquidGlassSlot::BuildSlot(TSharedRef<SCBLiquidGlass> InGlass)
{
	Glass = InGlass;

	// UContentWidget owns exactly one slot; attach that content as the crisp layer above the glass.
	InGlass->SetPadding(Padding);
	InGlass->SetHAlign(HorizontalAlignment);
	InGlass->SetVAlign(VerticalAlignment);
	InGlass->SetContent(Content ? Content->TakeWidget() : SNullWidget::NullWidget);
}

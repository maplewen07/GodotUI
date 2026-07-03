// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "SCBLiquidGlassExtras.h"

#include "SCBLiquidGlass.h"
#include "SCBLiquidGlassButton.h"
#include "CBLiquidGlassRecipes.h"
#include "CBLiquidGlassMotion.h"

#include "Engine/Texture2D.h"
#include "Input/Events.h"
#include "InputCoreTypes.h"
#include "Rendering/DrawElements.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlassExtras"

namespace
{
	FSlateFontInfo BoldFont(int32 Size)
	{
		return FCoreStyle::GetDefaultFontStyle("Bold", Size);
	}
}

//////////////////////////////////////////////////////////////////////////
// SCBLiquidGlassBadge

void SCBLiquidGlassBadge::Construct(const FArguments& InArgs)
{
	Count = InArgs._Count;
	MaxCount = FMath::Max(InArgs._MaxCount, 1);
	bDotMode = InArgs._bDotMode;
	Color = InArgs._Color;
	Style = InArgs._Style;
	Rebuild();
}

void SCBLiquidGlassBadge::SetCount(int32 InCount) { Count = InCount; Rebuild(); }
void SCBLiquidGlassBadge::SetMaxCount(int32 InMaxCount) { MaxCount = FMath::Max(InMaxCount, 1); Rebuild(); }
void SCBLiquidGlassBadge::SetDotMode(bool bInDotMode) { bDotMode = bInDotMode; Rebuild(); }
void SCBLiquidGlassBadge::SetColor(FLinearColor InColor) { Color = InColor; Rebuild(); }
void SCBLiquidGlassBadge::SetStyle(const FCBLiquidGlassControlStyle& InStyle) { Style = InStyle; Rebuild(); }

FText SCBLiquidGlassBadge::GetCountText() const
{
	if (Count > MaxCount)
	{
		return FText::FromString(FString::Printf(TEXT("%d+"), MaxCount));
	}
	return FText::AsNumber(Count);
}

void SCBLiquidGlassBadge::Rebuild()
{
	// In count mode a non-positive count means "nothing to show".
	if (!bDotMode && Count <= 0)
	{
		SetVisibility(EVisibility::Collapsed);
		ChildSlot[SNullWidget::NullWidget];
		return;
	}
	SetVisibility(EVisibility::SelfHitTestInvisible);

	if (bDotMode)
	{
		ChildSlot
		[
			SNew(SBox).WidthOverride(14.0f).HeightOverride(14.0f)
			[
				SAssignNew(Glass, SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::Circle)
				.BlurStrength(0.2f).FrostRadius(0.05f)
				.RefractionStrength(0.5f).RefractionThickness(8.0f).IndexOfRefraction(1.4f)
				.TintColor(Color).TintOpacity(0.92f)
				.RimIntensity(0.4f).GlowAmount(0.4f).GlassOpacity(1.0f)
				.Quality(Style.Quality)
				[SNew(SBox)]
			]
		];
		return;
	}

	ChildSlot
	[
		SNew(SBox)
		.MinDesiredWidth(22.0f)
		.HeightOverride(22.0f)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SAssignNew(Glass, SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::Capsule)
				.BlurStrength(0.2f).FrostRadius(0.04f)
				.RefractionStrength(0.6f).RefractionThickness(12.0f).IndexOfRefraction(1.5f)
				.PrismIntensity(0.1f)
				.TintColor(Color).TintOpacity(0.9f)
				.RimIntensity(0.45f).GlowAmount(0.45f)
				.InnerGlowIntensity(0.14f).GlassOpacity(1.0f)
				.Quality(Style.Quality)
				[SNew(SBox)]
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Center).VAlign(VAlign_Center)
			.Padding(FMargin(7.0f, 0.0f))
			[
				SNew(STextBlock)
				.Text(GetCountText())
				.Font(BoldFont(12))
				.ColorAndOpacity(FLinearColor::White)
				.ShadowOffset(FVector2D(0.0f, 1.0f))
				.ShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.3f))
			]
		]
	];
}

//////////////////////////////////////////////////////////////////////////
// SCBLiquidGlassPageControl

void SCBLiquidGlassPageControl::Construct(const FArguments& InArgs)
{
	NumPages = FMath::Max(InArgs._NumPages, 1);
	CurrentPage = FMath::Clamp(InArgs._CurrentPage, 0, NumPages - 1);
	DotSize = FMath::Max(InArgs._DotSize, 2.0f);
	DotSpacing = FMath::Max(InArgs._DotSpacing, 0.0f);
	ActiveColor = InArgs._ActiveColor;
	InactiveColor = InArgs._InactiveColor;
	Spring = InArgs._Spring;
	OnPageChanged = InArgs._OnPageChanged;
	VisualPage = static_cast<float>(CurrentPage);
	SetCanTick(true);
}

void SCBLiquidGlassPageControl::SetNumPages(int32 InNumPages)
{
	NumPages = FMath::Max(InNumPages, 1);
	CurrentPage = FMath::Clamp(CurrentPage, 0, NumPages - 1);
	VisualPage = FMath::Clamp(VisualPage, 0.0f, static_cast<float>(NumPages - 1));
	Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
}

void SCBLiquidGlassPageControl::SetCurrentPage(int32 InCurrentPage)
{
	CurrentPage = FMath::Clamp(InCurrentPage, 0, NumPages - 1);
	Invalidate(EInvalidateWidgetReason::Paint);
}

void SCBLiquidGlassPageControl::SetDotSize(float InDotSize) { DotSize = FMath::Max(InDotSize, 2.0f); Invalidate(EInvalidateWidgetReason::LayoutAndVolatility); }
void SCBLiquidGlassPageControl::SetDotSpacing(float InDotSpacing) { DotSpacing = FMath::Max(InDotSpacing, 0.0f); Invalidate(EInvalidateWidgetReason::LayoutAndVolatility); }
void SCBLiquidGlassPageControl::SetActiveColor(FLinearColor InColor) { ActiveColor = InColor; Invalidate(EInvalidateWidgetReason::Paint); }
void SCBLiquidGlassPageControl::SetInactiveColor(FLinearColor InColor) { InactiveColor = InColor; Invalidate(EInvalidateWidgetReason::Paint); }
void SCBLiquidGlassPageControl::SetSpring(const FCBLiquidGlassSpringSettings& InSpring) { Spring = InSpring; }
void SCBLiquidGlassPageControl::SetOnPageChanged(FCBLiquidGlassPageChanged InDelegate) { OnPageChanged = MoveTemp(InDelegate); }

float SCBLiquidGlassPageControl::GetStride() const
{
	return DotSize + DotSpacing;
}

FVector2D SCBLiquidGlassPageControl::ComputeDesiredSize(float) const
{
	// Active pill is wider than a dot, so add one extra dot-width of headroom.
	const float Width = (NumPages - 1) * GetStride() + DotSize + DotSize;
	return FVector2D(FMath::Max(Width, DotSize), DotSize + 8.0f);
}

void SCBLiquidGlassPageControl::Tick(const FGeometry&, const double, const float InDeltaTime)
{
	const float Old = VisualPage;
	CBLiquidGlassMotion::StepSpring(static_cast<float>(CurrentPage), VisualPage, VisualVelocity, Spring, InDeltaTime);
	if (!FMath::IsNearlyEqual(Old, VisualPage, 0.001f))
	{
		Invalidate(EInvalidateWidgetReason::Paint);
	}
}

int32 SCBLiquidGlassPageControl::OnPaint(const FPaintArgs&, const FGeometry& AllottedGeometry, const FSlateRect&, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle&, bool) const
{
	const FVector2D Size = AllottedGeometry.GetLocalSize();
	const float CenterY = Size.Y * 0.5f;
	const float Stride = GetStride();
	const FPaintGeometry PaintGeom = AllottedGeometry.ToPaintGeometry();

	// Inactive dots: a near-zero-length antialiased line of thickness DotSize renders a filled circle.
	for (int32 Index = 0; Index < NumPages; ++Index)
	{
		const float CenterX = DotSize * 0.5f + Index * Stride;
		TArray<FVector2D> Points;
		Points.Add(FVector2D(CenterX - 0.05f, CenterY));
		Points.Add(FVector2D(CenterX + 0.05f, CenterY));
		FSlateDrawElement::MakeLines(OutDrawElements, LayerId, PaintGeom, Points, ESlateDrawEffect::None, InactiveColor, true, DotSize);
	}

	// Active pill: a short horizontal segment with round caps, springing between dot centers.
	const float ActiveCenterX = DotSize * 0.5f + VisualPage * Stride;
	const float PillHalf = DotSize * 0.6f;
	TArray<FVector2D> PillPoints;
	PillPoints.Add(FVector2D(ActiveCenterX - PillHalf, CenterY));
	PillPoints.Add(FVector2D(ActiveCenterX + PillHalf, CenterY));
	FSlateDrawElement::MakeLines(OutDrawElements, LayerId + 1, PaintGeom, PillPoints, ESlateDrawEffect::None, ActiveColor, true, DotSize);

	return LayerId + 1;
}

FReply SCBLiquidGlassPageControl::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		const FVector2D Local = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
		const int32 Index = FMath::Clamp(FMath::RoundToInt((Local.X - DotSize * 0.5f) / FMath::Max(GetStride(), 1.0f)), 0, NumPages - 1);
		if (Index != CurrentPage)
		{
			CurrentPage = Index;
			if (OnPageChanged.IsBound())
			{
				OnPageChanged.Execute(CurrentPage);
			}
		}
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

//////////////////////////////////////////////////////////////////////////
// SCBLiquidGlassNavigationBar

void SCBLiquidGlassNavigationBar::Construct(const FArguments& InArgs)
{
	Title = InArgs._Title;
	bShowBackButton = InArgs._bShowBackButton;
	bLargeTitle = InArgs._bLargeTitle;
	TrailingItems = InArgs._TrailingItems;
	Style = InArgs._Style;
	OnBackClicked = InArgs._OnBackClicked;
	OnTrailingItemClicked = InArgs._OnTrailingItemClicked;
	Rebuild();
}

void SCBLiquidGlassNavigationBar::SetTitle(const FText& InTitle) { Title = InTitle; Rebuild(); }
void SCBLiquidGlassNavigationBar::SetShowBackButton(bool bInValue) { bShowBackButton = bInValue; Rebuild(); }
void SCBLiquidGlassNavigationBar::SetLargeTitle(bool bInValue) { bLargeTitle = bInValue; Rebuild(); }
void SCBLiquidGlassNavigationBar::SetTrailingItems(const TArray<FCBLiquidGlassItem>& InItems) { TrailingItems = InItems; Rebuild(); }
void SCBLiquidGlassNavigationBar::SetStyle(const FCBLiquidGlassControlStyle& InStyle) { Style = InStyle; Rebuild(); }
void SCBLiquidGlassNavigationBar::SetOnBackClicked(FSimpleDelegate InDelegate) { OnBackClicked = MoveTemp(InDelegate); }
void SCBLiquidGlassNavigationBar::SetOnTrailingItemClicked(FCBLiquidGlassNavItemClicked InDelegate) { OnTrailingItemClicked = MoveTemp(InDelegate); }

void SCBLiquidGlassNavigationBar::Rebuild()
{
	TSharedRef<SOverlay> BarOverlay = SNew(SOverlay);

	if (bShowBackButton)
	{
		BarOverlay->AddSlot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(6.0f, 0.0f)
		[
			SNew(SButton)
			.ButtonStyle(FCoreStyle::Get(), "NoBorder")
			.ContentPadding(0.0f)
			.OnClicked_Lambda([this]()
			{
				if (OnBackClicked.IsBound()) { OnBackClicked.Execute(); }
				return FReply::Handled();
			})
			[
				SNew(SBox).WidthOverride(40.0f).HeightOverride(40.0f).HAlign(HAlign_Center).VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("‹")))
					.Font(BoldFont(30))
					.ColorAndOpacity(Style.AccentColor)
				]
			]
		];
	}

	// The title is layered independently from the side buttons so inline titles remain
	// visually centered even when the leading and trailing action widths differ.
	BarOverlay->AddSlot()
	.HAlign(bLargeTitle ? HAlign_Left : HAlign_Center)
	.VAlign(VAlign_Center)
	.Padding(bLargeTitle ? FMargin(bShowBackButton ? 58.0f : 18.0f, 0.0f, 92.0f, 0.0f) : FMargin(82.0f, 0.0f))
	[
		SNew(SBox)
		.MaxDesiredWidth(bLargeTitle ? 520.0f : 360.0f)
		[
			SNew(STextBlock)
			.Text(Title)
			.Font(BoldFont(bLargeTitle ? 30 : 19))
			.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.96f))
			.Justification(bLargeTitle ? ETextJustify::Left : ETextJustify::Center)
			.Clipping(EWidgetClipping::ClipToBounds)
			.ShadowOffset(FVector2D(0.0f, 1.0f))
			.ShadowColorAndOpacity(FLinearColor(0.0f, 0.04f, 0.06f, 0.35f))
		]
	];

	TSharedRef<SHorizontalBox> Trailing = SNew(SHorizontalBox);
	for (int32 Index = 0; Index < TrailingItems.Num(); ++Index)
	{
		const FCBLiquidGlassItem& Item = TrailingItems[Index];
		if (Item.State == ECBLiquidGlassItemState::Separator)
		{
			continue;
		}
		TSharedRef<SWidget> ItemContent = Item.Label.IsEmpty()
			? StaticCastSharedRef<SWidget>(
				SNew(SBox).WidthOverride(22.0f).HeightOverride(22.0f)
				[
					SNew(SImage).Image(&Item.Icon).ColorAndOpacity(Style.AccentColor)
				])
			: StaticCastSharedRef<SWidget>(
				SNew(STextBlock).Text(Item.Label).Font(BoldFont(16)).ColorAndOpacity(Style.AccentColor));

		Trailing->AddSlot().AutoWidth().VAlign(VAlign_Center).Padding(4.0f, 0.0f)
		[
			SNew(SButton)
			.ButtonStyle(FCoreStyle::Get(), "NoBorder")
			.ContentPadding(0.0f)
			.IsEnabled(Item.bEnabled && Item.State != ECBLiquidGlassItemState::Disabled)
			.OnClicked_Lambda([this, Index]()
			{
				if (OnTrailingItemClicked.IsBound())
				{
					OnTrailingItemClicked.Execute(Index, TrailingItems[Index].Value);
				}
				return FReply::Handled();
			})
			[
				SNew(SBox).MinDesiredWidth(36.0f).HeightOverride(36.0f).HAlign(HAlign_Center).VAlign(VAlign_Center).Padding(FMargin(8.0f, 0.0f))
				[
					ItemContent
				]
			]
		];
	}
	BarOverlay->AddSlot()
	.HAlign(HAlign_Right)
	.VAlign(VAlign_Center)
	.Padding(6.0f, 0.0f)
	[
		Trailing
	];

	TSharedRef<SCBLiquidGlass> Bar = SNew(SCBLiquidGlass)
		[
			SNew(SBox)
			.HeightOverride(bLargeTitle ? 72.0f : 56.0f)
			.Padding(FMargin(8.0f, 0.0f))
			.VAlign(VAlign_Center)
			[
				BarOverlay
			]
		];
	FCBLiquidGlassRecipe Recipe = CBLiquidGlassRecipes::ForPreset(ECBLiquidGlassPreset::FrostedMenu);
	Recipe.SquirclePower = 6.0f;
	Recipe.ApplyTo(*Bar);

	ChildSlot[Bar];
}

//////////////////////////////////////////////////////////////////////////
// SCBLiquidGlassDialog

void SCBLiquidGlassDialog::Construct(const FArguments& InArgs)
{
	Title = InArgs._Title;
	Message = InArgs._Message;
	Buttons = InArgs._Buttons;
	DialogStyle = InArgs._DialogStyle;
	bDimBackground = InArgs._bDimBackground;
	DimOpacity = FMath::Clamp(InArgs._DimOpacity, 0.0f, 1.0f);
	CardBlurStrength = FMath::Max(InArgs._CardBlurStrength, 0.0f);
	CardFrostRadius = FMath::Max(InArgs._CardFrostRadius, 0.0f);
	CardRefractionStrength = FMath::Max(InArgs._CardRefractionStrength, 0.0f);
	CardRefractionThickness = FMath::Max(InArgs._CardRefractionThickness, 0.0f);
	CardPrismIntensity = FMath::Max(InArgs._CardPrismIntensity, 0.0f);
	CardRimIntensity = FMath::Max(InArgs._CardRimIntensity, 0.0f);
	CardGlassOpacity = FMath::Clamp(InArgs._CardGlassOpacity, 0.0f, 1.0f);
	Style = InArgs._Style;
	Spring = InArgs._Spring;
	OnButtonClicked = InArgs._OnButtonClicked;
	OnDismissed = InArgs._OnDismissed;

	bPresented = InArgs._bStartPresented;
	VisualAlpha = bPresented ? 1.0f : 0.0f;

	Rebuild();
	SetCanTick(true);
	SetVisibility(bPresented ? EVisibility::Visible : EVisibility::Collapsed);
}

void SCBLiquidGlassDialog::SetTitle(const FText& InTitle) { Title = InTitle; Rebuild(); }
void SCBLiquidGlassDialog::SetMessage(const FText& InMessage) { Message = InMessage; Rebuild(); }
void SCBLiquidGlassDialog::SetButtons(const TArray<FCBLiquidGlassItem>& InButtons) { Buttons = InButtons; Rebuild(); }
void SCBLiquidGlassDialog::SetDialogStyle(ECBLiquidGlassDialogStyle InStyle) { DialogStyle = InStyle; Rebuild(); }
void SCBLiquidGlassDialog::SetDimBackground(bool bInValue) { bDimBackground = bInValue; Rebuild(); }
void SCBLiquidGlassDialog::SetDimOpacity(float InValue) { DimOpacity = FMath::Clamp(InValue, 0.0f, 1.0f); Rebuild(); }
void SCBLiquidGlassDialog::SetCardBlurStrength(float InValue) { CardBlurStrength = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassDialog::SetCardFrostRadius(float InValue) { CardFrostRadius = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassDialog::SetCardRefractionStrength(float InValue) { CardRefractionStrength = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassDialog::SetCardRefractionThickness(float InValue) { CardRefractionThickness = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassDialog::SetCardPrismIntensity(float InValue) { CardPrismIntensity = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassDialog::SetCardRimIntensity(float InValue) { CardRimIntensity = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassDialog::SetCardGlassOpacity(float InValue) { CardGlassOpacity = FMath::Clamp(InValue, 0.0f, 1.0f); Rebuild(); }
void SCBLiquidGlassDialog::SetSpring(const FCBLiquidGlassSpringSettings& InSpring) { Spring = InSpring; }
void SCBLiquidGlassDialog::SetStyle(const FCBLiquidGlassControlStyle& InStyle) { Style = InStyle; Rebuild(); }
void SCBLiquidGlassDialog::SetOnButtonClicked(FCBLiquidGlassDialogButtonClicked InDelegate) { OnButtonClicked = MoveTemp(InDelegate); }
void SCBLiquidGlassDialog::SetOnDismissed(FSimpleDelegate InDelegate) { OnDismissed = MoveTemp(InDelegate); }

void SCBLiquidGlassDialog::Present()
{
	bPresented = true;
	SetVisibility(EVisibility::Visible);
}

void SCBLiquidGlassDialog::Dismiss()
{
	bPresented = false;
}

void SCBLiquidGlassDialog::HandleButton(int32 Index, int32 Value)
{
	if (OnButtonClicked.IsBound())
	{
		OnButtonClicked.Execute(Index, Value);
	}
	Dismiss();
}

FReply SCBLiquidGlassDialog::OnKeyDown(const FGeometry&, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Escape)
	{
		Dismiss();
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

FReply SCBLiquidGlassDialog::OnMouseButtonDown(const FGeometry&, const FPointerEvent& MouseEvent)
{
	// Modal overlays should absorb pointer input so clicks do not leak to the game/UI behind.
	return MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton ? FReply::Handled() : FReply::Unhandled();
}

void SCBLiquidGlassDialog::Rebuild()
{
	const bool bVerticalButtons = DialogStyle != ECBLiquidGlassDialogStyle::Alert;

	TSharedRef<SVerticalBox> Card = SNew(SVerticalBox);
	Card->AddSlot().AutoHeight().HAlign(HAlign_Center).Padding(0.0f, 0.0f, 0.0f, 8.0f)
	[
		SNew(STextBlock).Text(Title).Font(BoldFont(20)).ColorAndOpacity(FLinearColor::White)
		.Justification(ETextJustify::Center).AutoWrapText(true)
	];
	if (!Message.IsEmpty())
	{
		Card->AddSlot().AutoHeight().HAlign(HAlign_Center).Padding(0.0f, 0.0f, 0.0f, 14.0f)
		[
			SNew(STextBlock).Text(Message).Font(FCoreStyle::GetDefaultFontStyle("Regular", 14))
			.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.78f)).Justification(ETextJustify::Center).AutoWrapText(true)
		];
	}

	auto MakeButton = [this](int32 Index) -> TSharedRef<SWidget>
	{
		const FCBLiquidGlassItem& Item = Buttons[Index];
		const bool bDanger = Item.State == ECBLiquidGlassItemState::Danger;
		const ECBLiquidGlassPreset ButtonPreset = (Item.State == ECBLiquidGlassItemState::Selected)
			? ECBLiquidGlassPreset::PillLens : ECBLiquidGlassPreset::FrostedMenu;
		return SNew(SCBLiquidGlassButton)
			.Preset(ButtonPreset)
			.Shape(ECBLiquidGlassShape::Capsule)
			.OnClicked(FSimpleDelegate::CreateLambda([this, Index]() { HandleButton(Index, Buttons[Index].Value); }))
			[
				SNew(SBox).MinDesiredWidth(96.0f).HeightOverride(44.0f).Padding(FMargin(18.0f, 0.0f)).HAlign(HAlign_Center).VAlign(VAlign_Center)
				[
					SNew(STextBlock).Text(Item.Label).Font(BoldFont(16))
					.ColorAndOpacity(bDanger ? FLinearColor(1.0f, 0.42f, 0.42f, 1.0f) : FLinearColor::White)
				]
			];
	};

	if (bVerticalButtons)
	{
		TSharedRef<SVerticalBox> Col = SNew(SVerticalBox);
		for (int32 Index = 0; Index < Buttons.Num(); ++Index)
		{
			Col->AddSlot().AutoHeight().Padding(0.0f, 5.0f)[MakeButton(Index)];
		}
		Card->AddSlot().AutoHeight()[Col];
	}
	else
	{
		TSharedRef<SHorizontalBox> RowBox = SNew(SHorizontalBox);
		for (int32 Index = 0; Index < Buttons.Num(); ++Index)
		{
			RowBox->AddSlot().FillWidth(1.0f).Padding(5.0f, 0.0f).HAlign(HAlign_Center)[MakeButton(Index)];
		}
		Card->AddSlot().AutoHeight().Padding(0.0f, 4.0f, 0.0f, 0.0f)[RowBox];
	}

	const float CardWidth = (DialogStyle == ECBLiquidGlassDialogStyle::Alert) ? 320.0f : 460.0f;
	TSharedRef<SCBLiquidGlass> CardGlass = SNew(SCBLiquidGlass)
		[
			SNew(SBox).MinDesiredWidth(CardWidth).Padding(FMargin(22.0f, 20.0f))[Card]
		];
	FCBLiquidGlassRecipe Recipe = CBLiquidGlassRecipes::ForPreset(ECBLiquidGlassPreset::FrostedMenu);
	Recipe.SquirclePower = 6.0f;
	Recipe.BlurStrength = CardBlurStrength;
	Recipe.FrostRadius = CardFrostRadius;
	Recipe.RefractionStrength = CardRefractionStrength;
	Recipe.RefractionThickness = CardRefractionThickness;
	Recipe.PrismIntensity = CardPrismIntensity;
	Recipe.RimIntensity = CardRimIntensity;
	Recipe.GlowAmount = FMath::Max(Recipe.GlowAmount, CardRimIntensity * 0.8f);
	Recipe.GlassOpacity = CardGlassOpacity;
	Recipe.TintOpacity = FMath::Max(Recipe.TintOpacity, 0.035f);
	Recipe.InnerShadowIntensity = FMath::Max(Recipe.InnerShadowIntensity, 0.18f);
	Recipe.ApplyTo(*CardGlass);

	const EVerticalAlignment CardVAlign = (DialogStyle == ECBLiquidGlassDialogStyle::Alert) ? VAlign_Center : VAlign_Bottom;
	const FMargin CardMargin = (DialogStyle == ECBLiquidGlassDialogStyle::Alert) ? FMargin(0.0f) : FMargin(0.0f, 0.0f, 0.0f, 24.0f);

	TSharedRef<SOverlay> Overlay = SNew(SOverlay);
	Overlay->AddSlot()
	[
		SNew(SColorBlock)
		.Color(bDimBackground ? FLinearColor(0.0f, 0.0f, 0.0f, DimOpacity) : FLinearColor::Transparent)
	];
	Overlay->AddSlot().HAlign(HAlign_Center).VAlign(CardVAlign).Padding(CardMargin)
	[
		SAssignNew(CardScaleBox, SBox)[CardGlass]
	];
	CardScaleBox->SetRenderTransformPivot(FVector2D(0.5f, 0.5f));

	Root = Overlay;
	ChildSlot[Overlay];
}

void SCBLiquidGlassDialog::Tick(const FGeometry&, const double, const float InDeltaTime)
{
	const float Target = bPresented ? 1.0f : 0.0f;
	CBLiquidGlassMotion::StepSpring(Target, VisualAlpha, VisualVelocity, Spring, InDeltaTime);
	VisualAlpha = FMath::Clamp(VisualAlpha, 0.0f, 1.05f);

	const float ClampedAlpha = FMath::Clamp(VisualAlpha, 0.0f, 1.0f);
	// Fade the whole overlay (dim + card) together via the compound widget's render opacity.
	SetRenderOpacity(ClampedAlpha);
	if (CardScaleBox.IsValid())
	{
		const float Scale = FMath::Lerp(0.94f, 1.0f, FMath::InterpEaseOut(0.0f, 1.0f, ClampedAlpha, 2.0f));
		CardScaleBox->SetRenderTransform(FSlateRenderTransform(FScale2D(Scale, Scale)));
	}

	// When fully dismissed, collapse once and notify exactly one time.
	if (!bPresented && VisualAlpha <= 0.01f && GetVisibility() != EVisibility::Collapsed)
	{
		SetVisibility(EVisibility::Collapsed);
		if (OnDismissed.IsBound())
		{
			OnDismissed.Execute();
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// SCBLiquidGlassContainer (fusion)

namespace
{
	UTexture2D* CreateMaskTexture(const TArray<uint8>& Pixels, int32 Width, int32 Height)
	{
		if (Width <= 0 || Height <= 0 || Pixels.Num() != Width * Height * 4)
		{
			return nullptr;
		}
		const FName TextureName = MakeUniqueObjectName(GetTransientPackage(), UTexture2D::StaticClass(), TEXT("CBLG_Fusion_Mask"));
		UTexture2D* Texture = UTexture2D::CreateTransient(Width, Height, PF_B8G8R8A8, TextureName, TConstArrayView64<uint8>(Pixels));
		if (!Texture)
		{
			return nullptr;
		}
		Texture->SRGB = false;
		Texture->Filter = TF_Bilinear;
		Texture->AddressX = TA_Clamp;
		Texture->AddressY = TA_Clamp;
		Texture->UpdateResource();
		return Texture;
	}

	bool AreBlobsEqual(const TArray<FCBLiquidGlassFusionBlob>& A, const TArray<FCBLiquidGlassFusionBlob>& B)
	{
		if (A.Num() != B.Num())
		{
			return false;
		}
		for (int32 Index = 0; Index < A.Num(); ++Index)
		{
			if (!A[Index].Position.Equals(B[Index].Position, 0.001f)
				|| !A[Index].Size.Equals(B[Index].Size, 0.001f)
				|| !FMath::IsNearlyEqual(A[Index].Roundness, B[Index].Roundness, 0.001f))
			{
				return false;
			}
		}
		return true;
	}

	bool BuildFusionMaskTexture(const TArray<FCBLiquidGlassFusionBlob>& Blobs, FVector2D CanvasSize, FVector2D MaskResolution, float Smoothing, TStrongObjectPtr<UTexture2D>& OutTexture)
	{
		OutTexture.Reset();
		const FVector2D SafeCanvasSize(FMath::Max(CanvasSize.X, 1.0f), FMath::Max(CanvasSize.Y, 1.0f));
		const FVector2D RequestedResolution = (MaskResolution.X > 0.0f && MaskResolution.Y > 0.0f) ? MaskResolution : SafeCanvasSize;
		const int32 Width = FMath::Clamp(FMath::RoundToInt(RequestedResolution.X), 8, 1024);
		const int32 Height = FMath::Clamp(FMath::RoundToInt(RequestedResolution.Y), 8, 1024);
		if (Blobs.Num() == 0)
		{
			return false;
		}

		auto SdRoundBox = [](const FVector2f& P, const FVector2f& B, float R) -> float
		{
			const FVector2f Q(FMath::Abs(P.X) - B.X + R, FMath::Abs(P.Y) - B.Y + R);
			const float Outside = FVector2f(FMath::Max(Q.X, 0.0f), FMath::Max(Q.Y, 0.0f)).Size();
			const float Inside = FMath::Min(FMath::Max(Q.X, Q.Y), 0.0f);
			return Outside + Inside - R;
		};
		auto Smin = [](float A, float B, float K) -> float
		{
			const float H = FMath::Clamp(0.5f + 0.5f * (B - A) / K, 0.0f, 1.0f);
			return FMath::Lerp(B, A, H) - K * H * (1.0f - H);
		};

		const float ScaleX = static_cast<float>(Width) / static_cast<float>(SafeCanvasSize.X);
		const float ScaleY = static_cast<float>(Height) / static_cast<float>(SafeCanvasSize.Y);
		const float UniformScale = (ScaleX + ScaleY) * 0.5f;
		const float K = FMath::Max(Smoothing * UniformScale, 0.001f);
		const float AA = 1.6f;

		TArray<uint8> Pixels;
		Pixels.SetNumZeroed(Width * Height * 4);

		for (int32 Y = 0; Y < Height; ++Y)
		{
			for (int32 X = 0; X < Width; ++X)
			{
				const FVector2f P(X + 0.5f, Y + 0.5f);
				float D = TNumericLimits<float>::Max();
				bool bFirst = true;
				for (const FCBLiquidGlassFusionBlob& Blob : Blobs)
				{
					const FVector2f Center(static_cast<float>(Blob.Position.X) * Width, static_cast<float>(Blob.Position.Y) * Height);
					const FVector2f Half(FMath::Max(static_cast<float>(Blob.Size.X) * ScaleX * 0.5f, 1.0f), FMath::Max(static_cast<float>(Blob.Size.Y) * ScaleY * 0.5f, 1.0f));
					const float Radius = FMath::Clamp(Blob.Roundness, 0.0f, 1.0f) * FMath::Min(Half.X, Half.Y);
					const float Sd = SdRoundBox(P - Center, Half, Radius);
					D = bFirst ? Sd : Smin(D, Sd, K);
					bFirst = false;
				}

				const float T = FMath::Clamp((D + AA) / (2.0f * AA), 0.0f, 1.0f);
				const float Smooth = T * T * (3.0f - 2.0f * T);
				const uint8 Alpha = static_cast<uint8>(FMath::Clamp(FMath::RoundToInt((1.0f - Smooth) * 255.0f), 0, 255));

				const int32 Offset = (Y * Width + X) * 4;
				Pixels[Offset + 0] = Alpha;
				Pixels[Offset + 1] = Alpha;
				Pixels[Offset + 2] = Alpha;
				Pixels[Offset + 3] = Alpha;
			}
		}

		UTexture2D* Texture = CreateMaskTexture(Pixels, Width, Height);
		if (!Texture)
		{
			return false;
		}
		OutTexture = TStrongObjectPtr<UTexture2D>(Texture);
		return true;
	}
}

void SCBLiquidGlassContainer::Construct(const FArguments& InArgs)
{
	Blobs = InArgs._Blobs;
	if (Blobs.Num() == 0)
	{
		// A sensible default that clearly shows fusion: two overlapping capsules.
		FCBLiquidGlassFusionBlob A; A.Position = FVector2D(0.34, 0.5); A.Size = FVector2D(180.0, 120.0);
		FCBLiquidGlassFusionBlob B; B.Position = FVector2D(0.66, 0.5); B.Size = FVector2D(180.0, 120.0);
		Blobs = { A, B };
	}
	Smoothing = FMath::Max(InArgs._Smoothing, 0.0f);
	CanvasSize = FVector2D(FMath::Max(InArgs._CanvasSize.X, 8.0f), FMath::Max(InArgs._CanvasSize.Y, 8.0f));
	MaskResolution = InArgs._MaskResolution;
	BlurStrength = FMath::Max(InArgs._BlurStrength, 0.0f);
	FrostRadius = FMath::Max(InArgs._FrostRadius, 0.0f);
	RefractionStrength = FMath::Max(InArgs._RefractionStrength, 0.0f);
	RefractionThickness = FMath::Max(InArgs._RefractionThickness, 0.0f);
	PrismIntensity = FMath::Max(InArgs._PrismIntensity, 0.0f);
	RimIntensity = FMath::Max(InArgs._RimIntensity, 0.0f);
	GlassOpacity = FMath::Clamp(InArgs._GlassOpacity, 0.0f, 1.0f);
	Preset = InArgs._Preset;
	Quality = InArgs._Quality;
	PendingContent = InArgs._Content.Widget;
	Rebuild();
}

void SCBLiquidGlassContainer::SetContent(const TSharedRef<SWidget>& InContent) { PendingContent = InContent; Rebuild(); }
void SCBLiquidGlassContainer::SetBlobs(const TArray<FCBLiquidGlassFusionBlob>& InBlobs) { Blobs = InBlobs; Rebuild(); }
void SCBLiquidGlassContainer::SetSmoothing(float InSmoothing) { Smoothing = FMath::Max(InSmoothing, 0.0f); Rebuild(); }
void SCBLiquidGlassContainer::SetCanvasSize(FVector2D InCanvasSize) { CanvasSize = FVector2D(FMath::Max(InCanvasSize.X, 8.0f), FMath::Max(InCanvasSize.Y, 8.0f)); Rebuild(); }
void SCBLiquidGlassContainer::SetMaskResolution(FVector2D InMaskResolution) { MaskResolution = InMaskResolution; Rebuild(); }
void SCBLiquidGlassContainer::SetBlurStrength(float InValue) { BlurStrength = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassContainer::SetFrostRadius(float InValue) { FrostRadius = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassContainer::SetRefractionStrength(float InValue) { RefractionStrength = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassContainer::SetRefractionThickness(float InValue) { RefractionThickness = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassContainer::SetPrismIntensity(float InValue) { PrismIntensity = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassContainer::SetRimIntensity(float InValue) { RimIntensity = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassContainer::SetGlassOpacity(float InValue) { GlassOpacity = FMath::Clamp(InValue, 0.0f, 1.0f); Rebuild(); }
void SCBLiquidGlassContainer::SetPreset(ECBLiquidGlassPreset InPreset) { Preset = InPreset; Rebuild(); }
void SCBLiquidGlassContainer::SetQuality(ECBLiquidGlassQuality InQuality) { Quality = InQuality; Rebuild(); }

void SCBLiquidGlassContainer::RegenerateMask()
{
	if (MaskTexture.Get()
		&& AreBlobsEqual(CachedBlobs, Blobs)
		&& FMath::IsNearlyEqual(CachedSmoothing, Smoothing, 0.001f)
		&& CachedCanvasSize.Equals(CanvasSize, 0.001f)
		&& CachedMaskResolution.Equals(MaskResolution, 0.001f))
	{
		return;
	}

	if (BuildFusionMaskTexture(Blobs, CanvasSize, MaskResolution, Smoothing, MaskTexture))
	{
		CachedBlobs = Blobs;
		CachedSmoothing = Smoothing;
		CachedCanvasSize = CanvasSize;
		CachedMaskResolution = MaskResolution;
	}
	else
	{
		CachedBlobs.Reset();
		CachedSmoothing = -1.0f;
		CachedCanvasSize = FVector2D(-1.0f, -1.0f);
		CachedMaskResolution = FVector2D(-1.0f, -1.0f);
	}
}

void SCBLiquidGlassContainer::Rebuild()
{
	RegenerateMask();

	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(CanvasSize.X)
		.HeightOverride(CanvasSize.Y)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SAssignNew(Glass, SCBLiquidGlass)
				.AlphaMaskTexture(MaskTexture.Get())
				.AlphaMaskThreshold(0.5f)
				.AlphaMaskSoftness(0.02f)
				[
					SNew(SBox)
				]
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				PendingContent.IsValid() ? PendingContent.ToSharedRef() : SNullWidget::NullWidget
			]
		]
	];

	if (Glass.IsValid())
	{
		FCBLiquidGlassRecipe Recipe = CBLiquidGlassRecipes::ForPreset(Preset);
		Recipe.Quality = Quality;
		Recipe.BlurStrength = BlurStrength;
		Recipe.FrostRadius = FrostRadius;
		Recipe.RefractionStrength = RefractionStrength;
		Recipe.RefractionThickness = RefractionThickness;
		Recipe.IndexOfRefraction = FMath::Max(Recipe.IndexOfRefraction, 1.78f);
		Recipe.ChromaticAberration = FMath::Max(Recipe.ChromaticAberration, 0.045f);
		Recipe.PrismIntensity = PrismIntensity;
		Recipe.RimIntensity = RimIntensity;
		Recipe.GlowAmount = FMath::Max(Recipe.GlowAmount, RimIntensity * 0.85f);
		Recipe.InnerGlowIntensity = FMath::Max(Recipe.InnerGlowIntensity, 0.18f);
		Recipe.InnerShadowIntensity = FMath::Max(Recipe.InnerShadowIntensity, 0.18f);
		Recipe.GlassOpacity = GlassOpacity;
		Recipe.TintOpacity = FMath::Max(Recipe.TintOpacity, 0.02f);
		Recipe.EdgeSoftness = 0.45f;
		Recipe.ApplyTo(*Glass);
		// The alpha mask drives the silhouette, so re-assert it after the recipe pass.
		Glass->SetAlphaMaskTexture(MaskTexture.Get());
	}
}

#undef LOCTEXT_NAMESPACE

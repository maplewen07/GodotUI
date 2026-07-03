// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "SCBLiquidGlassControls.h"

#include "SCBLiquidGlass.h"
#include "SCBLiquidGlassButton.h"
#include "CBLiquidGlassMotion.h"

#include "Input/Events.h"
#include "InputCoreTypes.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableText.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SCanvas.h"
#include "Widgets/SOverlay.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlassControls"

namespace
{
	FVector2D SizeForToggle(ECBLiquidGlassControlSize Size)
	{
		switch (Size)
		{
		case ECBLiquidGlassControlSize::Small: return FVector2D(54.0f, 32.0f);
		case ECBLiquidGlassControlSize::Large: return FVector2D(82.0f, 48.0f);
		case ECBLiquidGlassControlSize::Medium:
		default: return FVector2D(68.0f, 40.0f);
		}
	}

	float FontSizeFor(ECBLiquidGlassControlSize Size)
	{
		switch (Size)
		{
		case ECBLiquidGlassControlSize::Small: return 11.0f;
		case ECBLiquidGlassControlSize::Large: return 16.0f;
		case ECBLiquidGlassControlSize::Medium:
		default: return 13.0f;
		}
	}

	float IconSizeFor(ECBLiquidGlassControlSize Size)
	{
		switch (Size)
		{
		case ECBLiquidGlassControlSize::Small: return 15.0f;
		case ECBLiquidGlassControlSize::Large: return 24.0f;
		case ECBLiquidGlassControlSize::Medium:
		default: return 19.0f;
		}
	}

	void ApplyGlassRecipe(const TSharedPtr<SCBLiquidGlass>& Glass, const FCBLiquidGlassControlStyle& Style, bool bSelected = false)
	{
		if (!Glass.IsValid())
		{
			return;
		}

		Glass->SetShape(ECBLiquidGlassShape::Capsule);
		Glass->SetQuality(Style.Quality);
		Glass->SetTintColor(bSelected ? Style.AccentColor : Style.TintColor);
		Glass->SetGlassOpacity(bSelected ? 1.0f : 0.86f);
		Glass->SetMotionStrength(bSelected ? 0.72f : 0.24f);
		Glass->SetMotionMaxOffset(bSelected ? 48.0f : 24.0f);
		Glass->SetEdgeSoftness(0.42f);

		switch (Style.Preset)
		{
		case ECBLiquidGlassPreset::FrostedMenu:
			Glass->SetBlurStrength(1.05f);
			Glass->SetFrostRadius(0.38f);
			Glass->SetRefractionStrength(0.52f);
			Glass->SetRefractionThickness(26.0f);
			Glass->SetIndexOfRefraction(1.45f);
			Glass->SetTintOpacity(bSelected ? 0.08f : 0.045f);
			Glass->SetPrismIntensity(0.16f);
			Glass->SetRimIntensity(bSelected ? 0.44f : 0.22f);
			Glass->SetGlowAmount(bSelected ? 0.48f : 0.2f);
			break;
		case ECBLiquidGlassPreset::Clear:
			Glass->SetBlurStrength(0.2f);
			Glass->SetFrostRadius(0.026f);
			Glass->SetRefractionStrength(0.72f);
			Glass->SetRefractionThickness(38.0f);
			Glass->SetIndexOfRefraction(1.72f);
			Glass->SetTintOpacity(bSelected ? 0.02f : 0.008f);
			Glass->SetPrismIntensity(0.14f);
			Glass->SetRimIntensity(bSelected ? 0.6f : 0.34f);
			Glass->SetGlowAmount(bSelected ? 0.66f : 0.34f);
			break;
		case ECBLiquidGlassPreset::PillLens:
		default:
			Glass->SetBlurStrength(0.28f);
			Glass->SetFrostRadius(0.04f);
			Glass->SetRefractionStrength(0.78f);
			Glass->SetRefractionThickness(42.0f);
			Glass->SetIndexOfRefraction(1.78f);
			Glass->SetTintOpacity(bSelected ? 0.035f : 0.012f);
			Glass->SetPrismIntensity(0.16f);
			Glass->SetRimIntensity(bSelected ? 0.62f : 0.38f);
			Glass->SetGlowAmount(bSelected ? 0.68f : 0.42f);
			break;
		}

		Glass->SetInnerGlowIntensity(bSelected ? 0.18f : 0.08f);
		Glass->SetInnerShadowIntensity(bSelected ? 0.1f : 0.06f);
		Glass->SetSaturation(1.08f);
		Glass->SetNoiseAmount(0.001f);
	}

	TSharedRef<SWidget> BuildIconLabel(const FCBLiquidGlassItem& Item, const FCBLiquidGlassControlStyle& Style, ECBLiquidGlassIconPosition IconPosition, bool bSelected, bool bAllowIcon, bool bAllowLabel)
	{
		const FLinearColor EnabledColor = bSelected ? Style.AccentColor.CopyWithNewOpacity(1.0f) : FLinearColor(1.0f, 1.0f, 1.0f, 0.88f);
		const FLinearColor Color = Item.bEnabled ? EnabledColor : FLinearColor(1.0f, 1.0f, 1.0f, 0.34f);
		const bool bShowIcon = bAllowIcon && IconPosition != ECBLiquidGlassIconPosition::Only;
		const bool bIconOnly = bAllowIcon && IconPosition == ECBLiquidGlassIconPosition::Only;
		const bool bShowLabel = bAllowLabel && IconPosition != ECBLiquidGlassIconPosition::Only;
		const float IconSize = IconSizeFor(Style.Size);
		const float FontSize = FontSizeFor(Style.Size);

		auto MakeIcon = [&]()
		{
			return SNew(SBox)
				.WidthOverride(IconSize)
				.HeightOverride(IconSize)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SImage)
					.Image(&Item.Icon)
					.ColorAndOpacity(Color)
				];
		};

		auto MakeLabel = [&]()
		{
			return SNew(STextBlock)
				.Text(Item.Label)
				.Justification(ETextJustify::Center)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", FMath::RoundToInt(FontSize)))
				.ShadowOffset(bSelected ? FVector2D(0.0f, 0.8f) : FVector2D::ZeroVector)
				.ShadowColorAndOpacity(bSelected ? FLinearColor(0.0f, 0.0f, 0.0f, 0.22f) : FLinearColor::Transparent)
				.ColorAndOpacity(Color);
		};

		if (bIconOnly)
		{
			return MakeIcon();
		}

		if (IconPosition == ECBLiquidGlassIconPosition::Left || IconPosition == ECBLiquidGlassIconPosition::Right)
		{
			TSharedRef<SHorizontalBox> Row = SNew(SHorizontalBox);
			if (bShowIcon && IconPosition == ECBLiquidGlassIconPosition::Left)
			{
				Row->AddSlot().AutoWidth().VAlign(VAlign_Center).Padding(0.0f, 0.0f, 7.0f, 0.0f)[MakeIcon()];
			}
			if (bShowLabel)
			{
				Row->AddSlot().AutoWidth().VAlign(VAlign_Center)[MakeLabel()];
			}
			if (bShowIcon && IconPosition == ECBLiquidGlassIconPosition::Right)
			{
				Row->AddSlot().AutoWidth().VAlign(VAlign_Center).Padding(7.0f, 0.0f, 0.0f, 0.0f)[MakeIcon()];
			}
			return Row;
		}

		TSharedRef<SVerticalBox> Column = SNew(SVerticalBox);
		if (bShowIcon)
		{
			Column->AddSlot().AutoHeight().HAlign(HAlign_Center)[MakeIcon()];
		}
		if (bShowLabel)
		{
			Column->AddSlot().AutoHeight().HAlign(HAlign_Center).Padding(0.0f, bShowIcon ? 4.0f : 0.0f, 0.0f, 0.0f)[MakeLabel()];
		}
		return Column;
	}

	FText FormatProgressPercent(float Value)
	{
		return FText::FromString(FString::Printf(TEXT("%d%%"), FMath::RoundToInt(FMath::Clamp(Value, 0.0f, 1.0f) * 100.0f)));
	}
}

void SCBLiquidGlassToggle::Construct(const FArguments& InArgs)
{
	bChecked = InArgs._Checked;
	VisualAlpha = bChecked ? 1.0f : 0.0f;
	OnColor = InArgs._OnColor;
	OffColor = InArgs._OffColor;
	Style = InArgs._Style;
	Spring = InArgs._Spring;
	OnCheckStateChanged = InArgs._OnCheckStateChanged;
	Rebuild();
}

void SCBLiquidGlassToggle::SetChecked(bool bInChecked)
{
	if (bChecked != bInChecked)
	{
		bChecked = bInChecked;
		ApplyVisuals();
		Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
	}
}

void SCBLiquidGlassToggle::SetOnColor(FLinearColor InValue)
{
	OnColor = InValue;
	ApplyVisuals();
}

void SCBLiquidGlassToggle::SetOffColor(FLinearColor InValue)
{
	OffColor = InValue;
	ApplyVisuals();
}

void SCBLiquidGlassToggle::SetStyle(const FCBLiquidGlassControlStyle& InValue)
{
	Style = InValue;
	ApplyVisuals();
}

void SCBLiquidGlassToggle::SetSpringSettings(const FCBLiquidGlassSpringSettings& InValue)
{
	Spring = InValue;
}

void SCBLiquidGlassToggle::SetOnCheckStateChanged(FCBLiquidGlassCheckChanged InDelegate)
{
	OnCheckStateChanged = MoveTemp(InDelegate);
}

FVector2D SCBLiquidGlassToggle::ComputeDesiredSize(float) const
{
	return SizeForToggle(Style.Size);
}

void SCBLiquidGlassToggle::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	const float Target = bChecked ? 1.0f : 0.0f;
	const float OldAlpha = VisualAlpha;
	CBLiquidGlassMotion::StepSpring(Target, VisualAlpha, VisualVelocity, Spring, InDeltaTime);
	VisualAlpha = FMath::Clamp(VisualAlpha, -0.05f, 1.05f);
	if (!FMath::IsNearlyEqual(OldAlpha, VisualAlpha, 0.0005f))
	{
		if (Canvas.IsValid())
		{
			Canvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
		}
	}
}

FReply SCBLiquidGlassToggle::OnMouseButtonDown(const FGeometry&, const FPointerEvent& MouseEvent)
{
	if (IsEnabled() && MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		bChecked = !bChecked;
		ApplyVisuals();
		if (OnCheckStateChanged.IsBound())
		{
			OnCheckStateChanged.Execute(bChecked);
		}
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

void SCBLiquidGlassToggle::Rebuild()
{
	const FVector2D Size = SizeForToggle(Style.Size);
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(Size.X)
		.HeightOverride(Size.Y)
		[
			SAssignNew(Canvas, SCanvas)
			+ SCanvas::Slot()
			.Position(FVector2D::ZeroVector)
			.Size(Size)
			[
				SAssignNew(TrackGlass, SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::Capsule)
				[ SNew(SBox) ]
			]
			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassToggle::GetThumbPosition))
			.Size(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassToggle::GetThumbSize))
			[
				SAssignNew(ThumbGlass, SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::Circle)
				[ SNew(SBox) ]
			]
		]
	];
	ApplyVisuals();
}

void SCBLiquidGlassToggle::ApplyVisuals()
{
	if (TrackGlass.IsValid())
	{
		TrackGlass->SetTintColor(bChecked ? OnColor : OffColor);
		TrackGlass->SetTintOpacity(bChecked ? 0.3f : 0.08f);
		TrackGlass->SetGlassOpacity(bChecked ? 0.95f : 0.68f);
		TrackGlass->SetQuality(Style.Quality);
		TrackGlass->SetBlurStrength(0.3f);
		TrackGlass->SetFrostRadius(0.06f);
		TrackGlass->SetRefractionStrength(0.42f);
		TrackGlass->SetRefractionThickness(22.0f);
		TrackGlass->SetIndexOfRefraction(1.36f);
		TrackGlass->SetRimIntensity(0.24f);
		TrackGlass->SetGlowAmount(0.28f);
	}
	ApplyGlassRecipe(ThumbGlass, Style, true);
}

FVector2D SCBLiquidGlassToggle::GetThumbPosition() const
{
	const FVector2D Size = SizeForToggle(Style.Size);
	const float Margin = Size.Y * 0.11f;
	const float Diameter = Size.Y - Margin * 2.0f;
	const float X = Margin + FMath::Clamp(VisualAlpha, 0.0f, 1.0f) * (Size.X - Diameter - Margin * 2.0f);
	const float VelocityOffset = FMath::Clamp(VisualVelocity * Size.X * 0.015f * Spring.Stretch, -Size.Y * 0.1f, Size.Y * 0.1f);
	return FVector2D(X + VelocityOffset, Margin);
}

FVector2D SCBLiquidGlassToggle::GetThumbSize() const
{
	const FVector2D Size = SizeForToggle(Style.Size);
	const float Margin = Size.Y * 0.11f;
	const float Diameter = Size.Y - Margin * 2.0f;
	const float Stretch = FMath::Clamp(FMath::Abs(VisualVelocity) * Size.X * 0.016f * Spring.Stretch, 0.0f, Diameter * 0.22f);
	return FVector2D(Diameter + Stretch, Diameter);
}

void SCBLiquidGlassItemSelector::Construct(const FArguments& InArgs)
{
	Items = InArgs._Items;
	SelectedIndex = InArgs._SelectedIndex;
	Orientation = InArgs._Orientation;
	IconPosition = InArgs._IconPosition;
	Style = InArgs._Style;
	Spring = InArgs._Spring;
	ItemSize = InArgs._ItemSize;
	Padding = InArgs._Padding;
	bShowIcons = InArgs._bShowIcons;
	bShowLabels = InArgs._bShowLabels;
	bUseGlassBackground = InArgs._bUseGlassBackground;
	OnSelectionChanged = InArgs._OnSelectionChanged;
	VisualOffset = GetTargetOffset();
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetItems(const TArray<FCBLiquidGlassItem>& InItems)
{
	Items = InItems;
	SelectedIndex = FMath::Clamp(SelectedIndex, 0, FMath::Max(Items.Num() - 1, 0));
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetSelectedIndex(int32 InValue)
{
	SelectedIndex = FMath::Clamp(InValue, 0, FMath::Max(Items.Num() - 1, 0));
	Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
}

void SCBLiquidGlassItemSelector::SetOrientation(ECBLiquidGlassOrientation InValue)
{
	Orientation = InValue;
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetIconPosition(ECBLiquidGlassIconPosition InValue)
{
	IconPosition = InValue;
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetStyle(const FCBLiquidGlassControlStyle& InValue)
{
	Style = InValue;
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetSpringSettings(const FCBLiquidGlassSpringSettings& InValue)
{
	Spring = InValue;
}

void SCBLiquidGlassItemSelector::SetItemSize(FVector2D InValue)
{
	ItemSize = FVector2D(FMath::Max(24.0f, InValue.X), FMath::Max(24.0f, InValue.Y));
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetPadding(FMargin InValue)
{
	Padding = InValue;
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetShowIcons(bool bInValue)
{
	bShowIcons = bInValue;
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetShowLabels(bool bInValue)
{
	bShowLabels = bInValue;
	Rebuild();
}

void SCBLiquidGlassItemSelector::SetOnSelectionChanged(FCBLiquidGlassIndexChanged InDelegate)
{
	OnSelectionChanged = MoveTemp(InDelegate);
}

FVector2D SCBLiquidGlassItemSelector::ComputeDesiredSize(float) const
{
	if (Orientation == ECBLiquidGlassOrientation::Horizontal)
	{
		return FVector2D(Padding.GetTotalSpaceAlong<Orient_Horizontal>() + ItemSize.X * Items.Num(), Padding.GetTotalSpaceAlong<Orient_Vertical>() + ItemSize.Y);
	}
	return FVector2D(Padding.GetTotalSpaceAlong<Orient_Horizontal>() + ItemSize.X, Padding.GetTotalSpaceAlong<Orient_Vertical>() + ItemSize.Y * Items.Num());
}

void SCBLiquidGlassItemSelector::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	const float OldOffset = VisualOffset;
	CBLiquidGlassMotion::StepSpring(GetTargetOffset(), VisualOffset, VisualVelocity, Spring, InDeltaTime);
	if (!FMath::IsNearlyEqual(OldOffset, VisualOffset, 0.01f) && HighlightCanvas.IsValid())
	{
		HighlightCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
	}
}

void SCBLiquidGlassItemSelector::Rebuild()
{
	TSharedRef<SWidget> ItemsWidget = SNullWidget::NullWidget;
	if (Orientation == ECBLiquidGlassOrientation::Horizontal)
	{
		TSharedRef<SHorizontalBox> Row = SNew(SHorizontalBox);
		for (int32 Index = 0; Index < Items.Num(); ++Index)
		{
			Row->AddSlot().AutoWidth()[BuildItem(Index)];
		}
		ItemsWidget = Row;
	}
	else
	{
		TSharedRef<SVerticalBox> Column = SNew(SVerticalBox);
		for (int32 Index = 0; Index < Items.Num(); ++Index)
		{
			Column->AddSlot().AutoHeight()[BuildItem(Index)];
		}
		ItemsWidget = Column;
	}

	TSharedRef<SOverlay> Overlay = SNew(SOverlay);
	if (bUseGlassBackground)
	{
		Overlay->AddSlot()
		[
			SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::Capsule)
			.BlurStrength(0.7f)
			.FrostRadius(0.18f)
			.RefractionStrength(0.42f)
			.RefractionThickness(24.0f)
			.IndexOfRefraction(1.46f)
			.PrismIntensity(0.12f)
			.RimIntensity(0.22f)
			.GlowAmount(0.26f)
			.TintOpacity(0.055f)
			.GlassOpacity(0.88f)
			.Quality(Style.Quality)
			[ SNew(SBox) ]
		];
	}

	Overlay->AddSlot()
	[
		SAssignNew(HighlightCanvas, SCanvas)
		+ SCanvas::Slot()
		.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassItemSelector::GetHighlightPosition))
		.Size(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassItemSelector::GetHighlightSize))
		[
			SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::Capsule)
			.BlurStrength(0.18f)
			.FrostRadius(0.028f)
			.RefractionStrength(0.66f)
			.RefractionThickness(34.0f)
			.IndexOfRefraction(1.62f)
			.PrismIntensity(0.1f)
			.RimIntensity(0.44f)
			.GlowAmount(0.5f)
			.TintColor(Style.AccentColor)
			.TintOpacity(0.018f)
			.GlassOpacity(0.92f)
			.EdgeSoftness(0.34f)
			.MotionStrength(0.46f)
			.Quality(Style.Quality)
			[ SNew(SBox) ]
		]
	];

	Overlay->AddSlot()
	.Padding(Padding)
	[
		ItemsWidget
	];

	ChildSlot[Overlay];
}

void SCBLiquidGlassItemSelector::SelectIndex(int32 InIndex)
{
	if (!Items.IsValidIndex(InIndex) || !Items[InIndex].bEnabled || Items[InIndex].State == ECBLiquidGlassItemState::Disabled || Items[InIndex].State == ECBLiquidGlassItemState::Separator)
	{
		return;
	}

	const int32 OldIndex = SelectedIndex;
	SelectedIndex = InIndex;
	if (OnSelectionChanged.IsBound() && OldIndex != SelectedIndex)
	{
		OnSelectionChanged.Execute(SelectedIndex, Items[SelectedIndex].Value);
	}
	Rebuild();
}

TSharedRef<SWidget> SCBLiquidGlassItemSelector::BuildItem(int32 Index)
{
	const bool bSelected = Index == SelectedIndex || Items[Index].State == ECBLiquidGlassItemState::Selected;
	return SNew(SButton)
		.ButtonStyle(FCoreStyle::Get(), "NoBorder")
		.ContentPadding(0.0f)
		.OnClicked_Lambda([this, Index]()
		{
			SelectIndex(Index);
			return FReply::Handled();
		})
		[
			SNew(SBox)
			.WidthOverride(ItemSize.X)
			.HeightOverride(ItemSize.Y)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				BuildIconLabel(Items[Index], Style, IconPosition, bSelected, bShowIcons, bShowLabels)
			]
		];
}

FVector2D SCBLiquidGlassItemSelector::GetHighlightPosition() const
{
	const float Stretch = FMath::Clamp(FMath::Abs(VisualVelocity) * 0.014f * Spring.Stretch, 0.0f, 28.0f);
	const float Direction = VisualVelocity >= 0.0f ? 1.0f : -1.0f;
	const bool bCompactHorizontal = Orientation == ECBLiquidGlassOrientation::Horizontal && IconPosition == ECBLiquidGlassIconPosition::Left;
	const float InsetX = FMath::Clamp(ItemSize.X * 0.045f, 4.0f, 7.0f);
	const float InsetY = bCompactHorizontal ? FMath::Clamp(ItemSize.Y * 0.045f, 2.0f, 4.0f) : FMath::Clamp(ItemSize.Y * 0.075f, 4.0f, 7.0f);
	const float VerticalNudge = bCompactHorizontal ? 2.0f : 0.0f;
	if (Orientation == ECBLiquidGlassOrientation::Horizontal)
	{
		return FVector2D(Padding.Left + VisualOffset + InsetX - Direction * Stretch * 0.34f, Padding.Top + InsetY + VerticalNudge);
	}
	return FVector2D(Padding.Left + InsetX, Padding.Top + VisualOffset + InsetY - Direction * Stretch * 0.34f);
}

FVector2D SCBLiquidGlassItemSelector::GetHighlightSize() const
{
	const float Stretch = FMath::Clamp(FMath::Abs(VisualVelocity) * 0.014f * Spring.Stretch, 0.0f, 28.0f);
	const bool bCompactHorizontal = Orientation == ECBLiquidGlassOrientation::Horizontal && IconPosition == ECBLiquidGlassIconPosition::Left;
	const float InsetX = FMath::Clamp(ItemSize.X * 0.045f, 4.0f, 7.0f);
	const float InsetY = bCompactHorizontal ? FMath::Clamp(ItemSize.Y * 0.045f, 2.0f, 4.0f) : FMath::Clamp(ItemSize.Y * 0.075f, 4.0f, 7.0f);
	return Orientation == ECBLiquidGlassOrientation::Horizontal
		? FVector2D(FMath::Max(8.0f, ItemSize.X - InsetX * 2.0f + Stretch), FMath::Max(8.0f, ItemSize.Y - InsetY * 2.0f))
		: FVector2D(FMath::Max(8.0f, ItemSize.X - InsetX * 2.0f), FMath::Max(8.0f, ItemSize.Y - InsetY * 2.0f + Stretch));
}

float SCBLiquidGlassItemSelector::GetTargetOffset() const
{
	return FMath::Clamp(SelectedIndex, 0, FMath::Max(Items.Num() - 1, 0)) * GetItemStride();
}

float SCBLiquidGlassItemSelector::GetItemStride() const
{
	return Orientation == ECBLiquidGlassOrientation::Horizontal ? ItemSize.X : ItemSize.Y;
}

void SCBLiquidGlassSegmentedControl::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SAssignNew(Selector, SCBLiquidGlassItemSelector)
		.Items(InArgs._Items)
		.SelectedIndex(InArgs._SelectedIndex)
		.Orientation(InArgs._Orientation)
		.IconPosition(ECBLiquidGlassIconPosition::Left)
		.Style(InArgs._Style)
		.Spring(InArgs._Spring)
		.bShowIcons(InArgs._bShowIcons)
		.bShowLabels(InArgs._bShowLabels)
		.ItemSize(InArgs._ItemSize)
		.Padding(InArgs._Padding)
		.OnSelectionChanged(InArgs._OnSelectionChanged)
	];
}

void SCBLiquidGlassSegmentedControl::SetItems(const TArray<FCBLiquidGlassItem>& InItems) { if (Selector.IsValid()) Selector->SetItems(InItems); }
void SCBLiquidGlassSegmentedControl::SetSelectedIndex(int32 InValue) { if (Selector.IsValid()) Selector->SetSelectedIndex(InValue); }
void SCBLiquidGlassSegmentedControl::SetOrientation(ECBLiquidGlassOrientation InValue) { if (Selector.IsValid()) Selector->SetOrientation(InValue); }
void SCBLiquidGlassSegmentedControl::SetStyle(const FCBLiquidGlassControlStyle& InValue) { if (Selector.IsValid()) Selector->SetStyle(InValue); }
void SCBLiquidGlassSegmentedControl::SetSpringSettings(const FCBLiquidGlassSpringSettings& InValue) { if (Selector.IsValid()) Selector->SetSpringSettings(InValue); }
void SCBLiquidGlassSegmentedControl::SetShowIcons(bool bInValue) { if (Selector.IsValid()) Selector->SetShowIcons(bInValue); }
void SCBLiquidGlassSegmentedControl::SetShowLabels(bool bInValue) { if (Selector.IsValid()) Selector->SetShowLabels(bInValue); }
void SCBLiquidGlassSegmentedControl::SetItemSize(FVector2D InValue) { if (Selector.IsValid()) Selector->SetItemSize(InValue); }
void SCBLiquidGlassSegmentedControl::SetPadding(FMargin InValue) { if (Selector.IsValid()) Selector->SetPadding(InValue); }
void SCBLiquidGlassSegmentedControl::SetOnSelectionChanged(FCBLiquidGlassIndexChanged InDelegate) { if (Selector.IsValid()) Selector->SetOnSelectionChanged(MoveTemp(InDelegate)); }

void SCBLiquidGlassTabBar::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SAssignNew(Selector, SCBLiquidGlassItemSelector)
		.Items(InArgs._Items)
		.SelectedIndex(InArgs._SelectedIndex)
		.Orientation(ECBLiquidGlassOrientation::Horizontal)
		.IconPosition(ECBLiquidGlassIconPosition::Top)
		.Style(InArgs._Style)
		.Spring(InArgs._Spring)
		.bShowIcons(InArgs._bShowIcons)
		.bShowLabels(InArgs._bShowLabels)
		.ItemSize(InArgs._ItemSize)
		.Padding(InArgs._Padding)
		.OnSelectionChanged(InArgs._OnTabChanged)
	];
}

void SCBLiquidGlassTabBar::SetItems(const TArray<FCBLiquidGlassItem>& InItems) { if (Selector.IsValid()) Selector->SetItems(InItems); }
void SCBLiquidGlassTabBar::SetSelectedIndex(int32 InValue) { if (Selector.IsValid()) Selector->SetSelectedIndex(InValue); }
void SCBLiquidGlassTabBar::SetShowLabels(bool bInValue) { if (Selector.IsValid()) Selector->SetShowLabels(bInValue); }
void SCBLiquidGlassTabBar::SetShowIcons(bool bInValue) { if (Selector.IsValid()) Selector->SetShowIcons(bInValue); }
void SCBLiquidGlassTabBar::SetItemSize(FVector2D InValue) { if (Selector.IsValid()) Selector->SetItemSize(InValue); }
void SCBLiquidGlassTabBar::SetPadding(FMargin InValue) { if (Selector.IsValid()) Selector->SetPadding(InValue); }
void SCBLiquidGlassTabBar::SetStyle(const FCBLiquidGlassControlStyle& InValue) { if (Selector.IsValid()) Selector->SetStyle(InValue); }
void SCBLiquidGlassTabBar::SetSpringSettings(const FCBLiquidGlassSpringSettings& InValue) { if (Selector.IsValid()) Selector->SetSpringSettings(InValue); }
void SCBLiquidGlassTabBar::SetOnTabChanged(FCBLiquidGlassIndexChanged InDelegate) { if (Selector.IsValid()) Selector->SetOnSelectionChanged(MoveTemp(InDelegate)); }

void SCBLiquidGlassToolbar::Construct(const FArguments& InArgs)
{
	Items = InArgs._Items;
	Orientation = InArgs._Orientation;
	Style = InArgs._Style;
	bToggleMode = InArgs._bToggleMode;
	SelectedIndex = InArgs._SelectedIndex;
	bShowIcons = InArgs._bShowIcons;
	bShowLabels = InArgs._bShowLabels;
	ItemSize = InArgs._ItemSize;
	Padding = InArgs._Padding;
	OnToolClicked = InArgs._OnToolClicked;
	Rebuild();
}

void SCBLiquidGlassToolbar::SetItems(const TArray<FCBLiquidGlassItem>& InItems) { Items = InItems; Rebuild(); }
void SCBLiquidGlassToolbar::SetOrientation(ECBLiquidGlassOrientation InValue) { Orientation = InValue; Rebuild(); }
void SCBLiquidGlassToolbar::SetStyle(const FCBLiquidGlassControlStyle& InValue) { Style = InValue; Rebuild(); }
void SCBLiquidGlassToolbar::SetToggleMode(bool bInValue) { bToggleMode = bInValue; Rebuild(); }
void SCBLiquidGlassToolbar::SetSelectedIndex(int32 InValue) { SelectedIndex = InValue; Rebuild(); }
void SCBLiquidGlassToolbar::SetShowIcons(bool bInValue) { bShowIcons = bInValue; Rebuild(); }
void SCBLiquidGlassToolbar::SetShowLabels(bool bInValue) { bShowLabels = bInValue; Rebuild(); }
void SCBLiquidGlassToolbar::SetItemSize(FVector2D InValue) { ItemSize = FVector2D(FMath::Max(24.0f, InValue.X), FMath::Max(24.0f, InValue.Y)); Rebuild(); }
void SCBLiquidGlassToolbar::SetPadding(FMargin InValue) { Padding = InValue; Rebuild(); }
void SCBLiquidGlassToolbar::SetOnToolClicked(FCBLiquidGlassItemClicked InDelegate) { OnToolClicked = MoveTemp(InDelegate); }

void SCBLiquidGlassToolbar::Rebuild()
{
	if (bToggleMode && Orientation == ECBLiquidGlassOrientation::Horizontal)
	{
		FCBLiquidGlassSpringSettings ToolbarSpring;
		ToolbarSpring.Response = 26.0f;
		ToolbarSpring.Damping = 0.92f;
		ToolbarSpring.Stretch = 0.5f;

		FCBLiquidGlassControlStyle ToolbarStyle = Style;
		ToolbarStyle.Size = ECBLiquidGlassControlSize::Small;

		ChildSlot
		[
			SNew(SCBLiquidGlassItemSelector)
			.Items(Items)
			.SelectedIndex(SelectedIndex)
			.Orientation(ECBLiquidGlassOrientation::Horizontal)
			.IconPosition(ECBLiquidGlassIconPosition::Top)
			.Style(ToolbarStyle)
			.Spring(ToolbarSpring)
			.bShowIcons(bShowIcons)
			.bShowLabels(bShowLabels)
			.ItemSize(ItemSize)
			.Padding(Padding)
			.OnSelectionChanged(FCBLiquidGlassIndexChanged::CreateLambda([this](int32 Index, int32)
			{
				ClickTool(Index);
			}))
		];
		return;
	}

	TSharedRef<SWidget> Container = SNullWidget::NullWidget;
	if (Orientation == ECBLiquidGlassOrientation::Horizontal)
	{
		TSharedRef<SHorizontalBox> Row = SNew(SHorizontalBox);
		for (int32 Index = 0; Index < Items.Num(); ++Index)
		{
			Row->AddSlot().AutoWidth().Padding(3.0f)[BuildTool(Index)];
		}
		Container = Row;
	}
	else
	{
		TSharedRef<SVerticalBox> Column = SNew(SVerticalBox);
		for (int32 Index = 0; Index < Items.Num(); ++Index)
		{
			Column->AddSlot().AutoHeight().Padding(3.0f)[BuildTool(Index)];
		}
		Container = Column;
	}

	ChildSlot
	[
		SNew(SCBLiquidGlass)
		.Shape(ECBLiquidGlassShape::Capsule)
		.BlurStrength(0.78f)
		.FrostRadius(0.22f)
		.RefractionStrength(0.42f)
		.RefractionThickness(22.0f)
		.IndexOfRefraction(1.42f)
		.TintOpacity(0.055f)
		.RimIntensity(0.24f)
		.GlassOpacity(0.88f)
		.Quality(Style.Quality)
		[
			SNew(SBox).Padding(Padding)[Container]
		]
	];
}

TSharedRef<SWidget> SCBLiquidGlassToolbar::BuildTool(int32 Index)
{
	const bool bSelected = bToggleMode && Index == SelectedIndex;
	return SNew(SButton)
		.ButtonStyle(FCoreStyle::Get(), "NoBorder")
		.ContentPadding(0.0f)
		.OnClicked_Lambda([this, Index]()
		{
			ClickTool(Index);
			return FReply::Handled();
		})
		[
			SNew(SCBLiquidGlass)
			.Shape(ECBLiquidGlassShape::Capsule)
			.BlurStrength(bSelected ? 0.26f : 0.1f)
			.FrostRadius(bSelected ? 0.04f : 0.015f)
			.RefractionStrength(bSelected ? 0.68f : 0.12f)
			.RefractionThickness(bSelected ? 34.0f : 8.0f)
			.IndexOfRefraction(bSelected ? 1.66f : 1.1f)
			.RimIntensity(bSelected ? 0.52f : 0.12f)
			.GlowAmount(bSelected ? 0.58f : 0.12f)
			.TintColor(bSelected ? Style.AccentColor : FLinearColor::White)
			.TintOpacity(bSelected ? 0.035f : 0.012f)
			.GlassOpacity(bSelected ? 0.96f : 0.36f)
			.Quality(Style.Quality)
			[
				SNew(SBox)
				.WidthOverride(ItemSize.X)
				.HeightOverride(ItemSize.Y)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					BuildIconLabel(Items[Index], Style, ECBLiquidGlassIconPosition::Top, bSelected, bShowIcons, bShowLabels)
				]
			]
		];
}

void SCBLiquidGlassToolbar::ClickTool(int32 Index)
{
	if (!Items.IsValidIndex(Index) || !Items[Index].bEnabled || Items[Index].State == ECBLiquidGlassItemState::Disabled)
	{
		return;
	}
	if (bToggleMode)
	{
		SelectedIndex = Index;
		Rebuild();
	}
	if (OnToolClicked.IsBound())
	{
		OnToolClicked.Execute(Index, Items[Index].Value);
	}
}

void SCBLiquidGlassMenu::Construct(const FArguments& InArgs)
{
	Items = InArgs._Items;
	ItemHeight = InArgs._ItemHeight;
	bCloseOnClick = InArgs._bCloseOnClick;
	bShowIcons = InArgs._bShowIcons;
	bShowLabels = InArgs._bShowLabels;
	Style = InArgs._Style;
	OnMenuItemClicked = InArgs._OnMenuItemClicked;
	Rebuild();
}

void SCBLiquidGlassMenu::SetItems(const TArray<FCBLiquidGlassItem>& InItems) { Items = InItems; Rebuild(); }
void SCBLiquidGlassMenu::SetItemHeight(float InValue) { ItemHeight = FMath::Max(InValue, 24.0f); Rebuild(); }
void SCBLiquidGlassMenu::SetCloseOnClick(bool bInValue) { bCloseOnClick = bInValue; }
void SCBLiquidGlassMenu::SetStyle(const FCBLiquidGlassControlStyle& InValue) { Style = InValue; Rebuild(); }
void SCBLiquidGlassMenu::SetShowIcons(bool bInValue) { bShowIcons = bInValue; Rebuild(); }
void SCBLiquidGlassMenu::SetShowLabels(bool bInValue) { bShowLabels = bInValue; Rebuild(); }
void SCBLiquidGlassMenu::SetOnMenuItemClicked(FCBLiquidGlassItemClicked InDelegate) { OnMenuItemClicked = MoveTemp(InDelegate); }

void SCBLiquidGlassMenu::Rebuild()
{
	TSharedRef<SVerticalBox> Rows = SNew(SVerticalBox);
	for (int32 Index = 0; Index < Items.Num(); ++Index)
	{
		Rows->AddSlot().AutoHeight()[BuildMenuRow(Index)];
	}

	ChildSlot
	[
		SNew(SCBLiquidGlass)
		.Shape(ECBLiquidGlassShape::SuperellipseRect)
		.SquirclePower(8.0f)
		.BlurStrength(1.1f)
		.FrostRadius(0.36f)
		.RefractionStrength(0.48f)
		.RefractionThickness(28.0f)
		.IndexOfRefraction(1.48f)
		.TintOpacity(0.055f)
		.RimIntensity(0.28f)
		.GlassOpacity(0.9f)
		.Quality(Style.Quality)
		[
			SNew(SBox).Padding(10.0f)[Rows]
		]
	];
}

TSharedRef<SWidget> SCBLiquidGlassMenu::BuildMenuRow(int32 Index)
{
	const FCBLiquidGlassItem& Item = Items[Index];
	if (Item.State == ECBLiquidGlassItemState::Separator)
	{
		return SNew(SBox)
			.HeightOverride(12.0f)
			.VAlign(VAlign_Center)
			[
				SNew(SColorBlock).Color(FLinearColor(1.0f, 1.0f, 1.0f, 0.14f))
			];
	}

	const bool bDanger = Item.State == ECBLiquidGlassItemState::Danger;
	return SNew(SButton)
		.ButtonStyle(FCoreStyle::Get(), "NoBorder")
		.ContentPadding(0.0f)
		.IsEnabled(Item.bEnabled && Item.State != ECBLiquidGlassItemState::Disabled)
		.OnClicked_Lambda([this, Index]()
		{
			if (OnMenuItemClicked.IsBound())
			{
				OnMenuItemClicked.Execute(Index, Items[Index].Value);
			}
			if (bCloseOnClick)
			{
				ChildSlot[SNullWidget::NullWidget];
			}
			return FReply::Handled();
		})
		[
			SNew(SBox)
			.HeightOverride(ItemHeight)
			.Padding(FMargin(12.0f, 0.0f))
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0.0f, 0.0f, 12.0f, 0.0f)
				[
					SNew(SBox)
					.Visibility(bShowIcons ? EVisibility::Visible : EVisibility::Collapsed)
					[
						SNew(SImage).Image(&Item.Icon).ColorAndOpacity(bDanger ? FLinearColor(1.0f, 0.28f, 0.32f, 1.0f) : FLinearColor::White)
					]
				]
				+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
				[
					SNew(SBox)
					.Visibility(bShowLabels ? EVisibility::Visible : EVisibility::Collapsed)
					[
						SNew(STextBlock)
						.Text(Item.Label)
						.Font(FCoreStyle::GetDefaultFontStyle("Regular", 16))
						.ColorAndOpacity(bDanger ? FLinearColor(1.0f, 0.35f, 0.38f, 1.0f) : FLinearColor(1.0f, 1.0f, 1.0f, 0.9f))
					]
				]
			]
		];
}

class SCBLiquidGlassSearchGlyph : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassSearchGlyph)
		: _Color(FLinearColor(1.0f, 1.0f, 1.0f, 0.72f))
		, _Size(34.0f)
	{}
		SLATE_ARGUMENT(FLinearColor, Color)
		SLATE_ARGUMENT(float, Size)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		Color = InArgs._Color;
		GlyphSize = FMath::Max(8.0f, InArgs._Size);
	}

	virtual FVector2D ComputeDesiredSize(float) const override
	{
		return FVector2D(GlyphSize, GlyphSize);
	}

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override
	{
		const FVector2D Size = AllottedGeometry.GetLocalSize();
		const FVector2D Center(Size.X * 0.42f, Size.Y * 0.42f);
		const float Radius = FMath::Min(Size.X, Size.Y) * 0.255f;
		TArray<FVector2D> CirclePoints;
		for (int32 Index = 0; Index <= 24; ++Index)
		{
			const float Alpha = static_cast<float>(Index) / 24.0f;
			const float Angle = Alpha * UE_TWO_PI;
			CirclePoints.Add(Center + FVector2D(FMath::Cos(Angle), FMath::Sin(Angle)) * Radius);
		}
		FSlateDrawElement::MakeLines(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(), CirclePoints, ESlateDrawEffect::None, Color, true, 3.0f);

		TArray<FVector2D> HandlePoints;
		HandlePoints.Add(Center + FVector2D(Radius * 0.58f, Radius * 0.58f));
		HandlePoints.Add(FVector2D(Size.X * 0.8f, Size.Y * 0.8f));
		FSlateDrawElement::MakeLines(OutDrawElements, LayerId + 1, AllottedGeometry.ToPaintGeometry(), HandlePoints, ESlateDrawEffect::None, Color, true, 3.2f);
		return LayerId + 2;
	}

	FLinearColor Color;
	float GlyphSize = 34.0f;
};

void SCBLiquidGlassSearchBar::Construct(const FArguments& InArgs)
{
	Text = InArgs._Text;
	HintText = InArgs._HintText;
	bShowClearButton = InArgs._bShowClearButton;
	bShowSearchIcon = InArgs._bShowSearchIcon;
	bShowText = InArgs._bShowText;
	Style = InArgs._Style;
	SearchBoxStyle = InArgs._SearchBoxStyle;
	OnTextChanged = InArgs._OnTextChanged;
	OnTextCommitted = InArgs._OnTextCommitted;
	Rebuild();
}

void SCBLiquidGlassSearchBar::SetText(const FText& InText) { Text = InText; if (TextBox.IsValid()) TextBox->SetText(Text); }
void SCBLiquidGlassSearchBar::SetHintText(const FText& InText) { HintText = InText; Rebuild(); }
void SCBLiquidGlassSearchBar::SetShowClearButton(bool bInValue) { bShowClearButton = bInValue; Rebuild(); }
void SCBLiquidGlassSearchBar::SetShowSearchIcon(bool bInValue) { bShowSearchIcon = bInValue; Rebuild(); }
void SCBLiquidGlassSearchBar::SetShowText(bool bInValue) { bShowText = bInValue; Rebuild(); }
void SCBLiquidGlassSearchBar::SetStyle(const FCBLiquidGlassControlStyle& InValue) { Style = InValue; Rebuild(); }
void SCBLiquidGlassSearchBar::SetSearchBoxStyle(const FCBLiquidGlassSearchBoxStyle& InValue) { SearchBoxStyle = InValue; Rebuild(); }
void SCBLiquidGlassSearchBar::SetOnTextChanged(FCBLiquidGlassTextChanged InDelegate) { OnTextChanged = MoveTemp(InDelegate); }
void SCBLiquidGlassSearchBar::SetOnTextCommitted(FCBLiquidGlassTextCommitted InDelegate) { OnTextCommitted = MoveTemp(InDelegate); }

void SCBLiquidGlassSearchBar::Rebuild()
{
	const FVector2D BoxSize(
		FMath::Max(80.0f, SearchBoxStyle.BoxSize.X),
		FMath::Max(28.0f, SearchBoxStyle.BoxSize.Y));
	const float TextLayerHeight = FMath::Clamp(SearchBoxStyle.TextLayerHeight, 12.0f, BoxSize.Y);
	const float ClearButtonSize = FMath::Clamp(SearchBoxStyle.ClearButtonSize, 12.0f, BoxSize.Y);
	const float TextFontSize = FMath::Max(6.0f, SearchBoxStyle.TextFontSize);

	ChildSlot
	[
		SNew(SCBLiquidGlass)
		.Shape(ECBLiquidGlassShape::Capsule)
		.BlurStrength(SearchBoxStyle.OuterBlurStrength)
		.FrostRadius(SearchBoxStyle.OuterFrostRadius)
		.RefractionStrength(SearchBoxStyle.OuterRefractionStrength)
		.RefractionThickness(SearchBoxStyle.OuterRefractionThickness)
		.IndexOfRefraction(1.32f)
		.PrismIntensity(0.055f)
		.TintColor(SearchBoxStyle.OuterTintColor)
		.TintOpacity(SearchBoxStyle.OuterTintOpacity)
		.RimIntensity(0.38f)
		.GlowAmount(0.26f)
		.InnerGlowIntensity(0.1f)
		.InnerShadowIntensity(0.22f)
		.GlassOpacity(SearchBoxStyle.OuterGlassOpacity)
		.EdgeSoftness(0.28f)
		.Quality(Style.Quality)
		[
			SNew(SBox)
			.WidthOverride(BoxSize.X)
			.HeightOverride(BoxSize.Y)
			.Padding(SearchBoxStyle.OuterPadding)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Capsule)
					.BlurStrength(SearchBoxStyle.InnerBlurStrength)
					.FrostRadius(SearchBoxStyle.InnerFrostRadius)
					.RefractionStrength(0.12f)
					.RefractionThickness(8.0f)
					.IndexOfRefraction(1.12f)
					.PrismIntensity(0.02f)
					.TintColor(SearchBoxStyle.InnerTintColor)
					.TintOpacity(SearchBoxStyle.InnerTintOpacity)
					.RimIntensity(0.16f)
					.GlowAmount(0.08f)
					.InnerGlowIntensity(0.05f)
					.InnerShadowIntensity(0.2f)
					.GlassOpacity(SearchBoxStyle.InnerGlassOpacity)
					.EdgeSoftness(0.24f)
					.Quality(Style.Quality)
					[
						SNew(SBox)
						.HeightOverride(TextLayerHeight)
						.Padding(SearchBoxStyle.TextLayerPadding)
						.VAlign(VAlign_Center)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							.Padding(0.0f, 0.0f, SearchBoxStyle.IconTextSpacing, 0.0f)
							[
								SNew(SBox)
								.Visibility(bShowSearchIcon ? EVisibility::Visible : EVisibility::Collapsed)
								[
									SNew(SCBLiquidGlassSearchGlyph)
									.Color(SearchBoxStyle.IconColor)
									.Size(SearchBoxStyle.IconSize)
								]
							]
							+ SHorizontalBox::Slot()
							.FillWidth(1.0f)
							.VAlign(VAlign_Center)
							[
								SNew(SBox)
								.Visibility(bShowText ? EVisibility::Visible : EVisibility::Collapsed)
								[
									SAssignNew(TextBox, SEditableText)
									.Text(Text)
									.HintText(HintText)
									.Font(FCoreStyle::GetDefaultFontStyle("Regular", FMath::RoundToInt(TextFontSize)))
									.ColorAndOpacity(FSlateColor(SearchBoxStyle.TextColor))
									.OnTextChanged(this, &SCBLiquidGlassSearchBar::HandleTextChanged)
									.OnTextCommitted(this, &SCBLiquidGlassSearchBar::HandleTextCommitted)
								]
							]
						]
					]
				]
				+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(SearchBoxStyle.ClearButtonSpacing, 0.0f, 0.0f, 0.0f)
				[
					SNew(SButton)
					.ButtonStyle(FCoreStyle::Get(), "NoBorder")
					.Visibility(bShowClearButton ? EVisibility::Visible : EVisibility::Collapsed)
					.OnClicked_Lambda([this]()
					{
						SetText(FText::GetEmpty());
						if (OnTextChanged.IsBound())
						{
							OnTextChanged.Execute(Text);
						}
						return FReply::Handled();
					})
					[
						SNew(SCBLiquidGlass)
						.Shape(ECBLiquidGlassShape::Circle)
						.BlurStrength(0.62f)
						.FrostRadius(0.16f)
						.RefractionStrength(0.28f)
						.RefractionThickness(14.0f)
						.IndexOfRefraction(1.22f)
						.PrismIntensity(0.04f)
						.TintColor(SearchBoxStyle.ClearButtonTintColor)
						.TintOpacity(0.18f)
						.RimIntensity(0.3f)
						.GlowAmount(0.18f)
						.InnerGlowIntensity(0.08f)
						.InnerShadowIntensity(0.14f)
						.GlassOpacity(0.84f)
						.Quality(Style.Quality)
						[
							SNew(SBox).WidthOverride(ClearButtonSize).HeightOverride(ClearButtonSize).HAlign(HAlign_Center).VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("ClearSearch", "X"))
								.Font(FCoreStyle::GetDefaultFontStyle("Bold", FMath::RoundToInt(ClearButtonSize * 0.5f)))
								.ColorAndOpacity(SearchBoxStyle.ClearButtonTextColor)
								.ShadowOffset(FVector2D(0.0f, 1.0f))
								.ShadowColorAndOpacity(FLinearColor(0.0f, 0.04f, 0.06f, 0.35f))
							]
						]
					]
				]
			]
		]
	];
}

void SCBLiquidGlassSearchBar::HandleTextChanged(const FText& InText)
{
	Text = InText;
	if (OnTextChanged.IsBound())
	{
		OnTextChanged.Execute(Text);
	}
}

void SCBLiquidGlassSearchBar::HandleTextCommitted(const FText& InText, ETextCommit::Type)
{
	Text = InText;
	if (OnTextCommitted.IsBound())
	{
		OnTextCommitted.Execute(Text);
	}
}

class SCBLiquidGlassCircularProgressArc : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassCircularProgressArc)
		: _Value(0.5f)
		, _Color(FLinearColor(0.0f, 0.52f, 1.0f, 1.0f))
		, _BackgroundColor(FLinearColor(1.0f, 1.0f, 1.0f, 0.22f))
		, _Thickness(10.0f)
	{}
		SLATE_ARGUMENT(float, Value)
		SLATE_ARGUMENT(FLinearColor, Color)
		SLATE_ARGUMENT(FLinearColor, BackgroundColor)
		SLATE_ARGUMENT(float, Thickness)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		Value = InArgs._Value;
		Color = InArgs._Color;
		BackgroundColor = InArgs._BackgroundColor;
		Thickness = InArgs._Thickness;
	}

	virtual FVector2D ComputeDesiredSize(float) const override
	{
		return FVector2D(132.0f, 132.0f);
	}

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override
	{
		const FVector2D Size = AllottedGeometry.GetLocalSize();
		const FVector2D Center = Size * 0.5f;
		const float Radius = FMath::Max(FMath::Min(Size.X, Size.Y) * 0.5f - Thickness, 2.0f);
		const int32 Segments = 64;
		TArray<FVector2D> TrackPoints;
		for (int32 Index = 0; Index <= Segments; ++Index)
		{
			const float Alpha = static_cast<float>(Index) / static_cast<float>(Segments);
			const float Angle = -UE_HALF_PI + UE_TWO_PI * Alpha;
			TrackPoints.Add(Center + FVector2D(FMath::Cos(Angle), FMath::Sin(Angle)) * Radius);
		}
		FSlateDrawElement::MakeLines(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(), TrackPoints, ESlateDrawEffect::None, BackgroundColor, true, Thickness);

		TArray<FVector2D> Points;
		const float End = FMath::Clamp(Value, 0.0f, 1.0f) * UE_TWO_PI;
		for (int32 Index = 0; Index <= Segments; ++Index)
		{
			const float Alpha = static_cast<float>(Index) / static_cast<float>(Segments);
			const float Angle = -UE_HALF_PI + End * Alpha;
			Points.Add(Center + FVector2D(FMath::Cos(Angle), FMath::Sin(Angle)) * Radius);
		}
		FSlateDrawElement::MakeLines(OutDrawElements, LayerId + 1, AllottedGeometry.ToPaintGeometry(), Points, ESlateDrawEffect::None, Color, true, Thickness);
		return LayerId + 2;
	}

	float Value = 0.5f;
	FLinearColor Color;
	FLinearColor BackgroundColor;
	float Thickness = 10.0f;
};

void SCBLiquidGlassProgress::Construct(const FArguments& InArgs)
{
	Value = FMath::Clamp(InArgs._Value, 0.0f, 1.0f);
	ProgressStyle = InArgs._ProgressStyle;
	FillColor = InArgs._FillColor;
	Thickness = InArgs._Thickness;
	LinearSize = InArgs._LinearSize;
	CircularSize = InArgs._CircularSize;
	EndCapSize = InArgs._EndCapSize;
	TrackColor = InArgs._TrackColor;
	TrackOpacity = InArgs._TrackOpacity;
	bShowPercentText = InArgs._bShowPercentText;
	TextColor = InArgs._TextColor;
	BlurStrength = InArgs._BlurStrength;
	FrostRadius = InArgs._FrostRadius;
	RefractionStrength = InArgs._RefractionStrength;
	PrismIntensity = InArgs._PrismIntensity;
	GlassOpacity = InArgs._GlassOpacity;
	Quality = InArgs._Quality;
	Rebuild();
}

void SCBLiquidGlassProgress::SetValue(float InValue) { Value = FMath::Clamp(InValue, 0.0f, 1.0f); Rebuild(); }
void SCBLiquidGlassProgress::SetProgressStyle(ECBLiquidGlassProgressStyle InValue) { ProgressStyle = InValue; Rebuild(); }
void SCBLiquidGlassProgress::SetFillColor(FLinearColor InValue) { FillColor = InValue; Rebuild(); }
void SCBLiquidGlassProgress::SetThickness(float InValue) { Thickness = FMath::Max(InValue, 1.0f); Rebuild(); }
void SCBLiquidGlassProgress::SetLinearSize(FVector2D InValue) { LinearSize = FVector2D(FMath::Max(96.0f, InValue.X), FMath::Max(24.0f, InValue.Y)); Rebuild(); }
void SCBLiquidGlassProgress::SetCircularSize(FVector2D InValue) { CircularSize = FVector2D(FMath::Max(64.0f, InValue.X), FMath::Max(64.0f, InValue.Y)); Rebuild(); }
void SCBLiquidGlassProgress::SetEndCapSize(float InValue) { EndCapSize = FMath::Max(0.0f, InValue); Rebuild(); }
void SCBLiquidGlassProgress::SetTrackColor(FLinearColor InValue) { TrackColor = InValue; Rebuild(); }
void SCBLiquidGlassProgress::SetTrackOpacity(float InValue) { TrackOpacity = FMath::Clamp(InValue, 0.0f, 1.0f); Rebuild(); }
void SCBLiquidGlassProgress::SetShowPercentText(bool bInValue) { bShowPercentText = bInValue; Rebuild(); }
void SCBLiquidGlassProgress::SetTextColor(FLinearColor InValue) { TextColor = InValue; Rebuild(); }
void SCBLiquidGlassProgress::SetBlurStrength(float InValue) { BlurStrength = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassProgress::SetFrostRadius(float InValue) { FrostRadius = FMath::Clamp(InValue, 0.0f, 1.0f); Rebuild(); }
void SCBLiquidGlassProgress::SetRefractionStrength(float InValue) { RefractionStrength = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassProgress::SetPrismIntensity(float InValue) { PrismIntensity = FMath::Max(InValue, 0.0f); Rebuild(); }
void SCBLiquidGlassProgress::SetGlassOpacity(float InValue) { GlassOpacity = FMath::Clamp(InValue, 0.0f, 1.0f); Rebuild(); }
void SCBLiquidGlassProgress::SetQuality(ECBLiquidGlassQuality InValue) { Quality = InValue; Rebuild(); }

void SCBLiquidGlassProgress::Rebuild()
{
	if (ProgressStyle == ECBLiquidGlassProgressStyle::Circular)
	{
		const FVector2D SafeSize(FMath::Max(64.0f, CircularSize.X), FMath::Max(64.0f, CircularSize.Y));
		const float ArcPadding = FMath::Clamp(Thickness * 1.15f, 8.0f, FMath::Min(SafeSize.X, SafeSize.Y) * 0.25f);
		ChildSlot
		[
			SNew(SBox)
			.WidthOverride(SafeSize.X)
			.HeightOverride(SafeSize.Y)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Circle)
					.BlurStrength(BlurStrength)
					.FrostRadius(FrostRadius)
					.RefractionStrength(RefractionStrength)
					.RefractionThickness(24.0f)
					.IndexOfRefraction(1.52f)
					.PrismIntensity(PrismIntensity)
					.TintColor(FLinearColor(0.72f, 0.96f, 1.0f, 1.0f))
					.TintOpacity(0.045f)
					.RimIntensity(0.46f)
					.GlowAmount(0.38f)
					.InnerGlowIntensity(0.14f)
					.InnerShadowIntensity(0.1f)
					.GlassOpacity(GlassOpacity)
					.Quality(Quality)
					[ SNew(SBox) ]
				]
				+ SOverlay::Slot()
				.Padding(ArcPadding)
				[
					SNew(SCBLiquidGlassCircularProgressArc)
					.Value(Value)
					.Color(FillColor)
					.BackgroundColor(TrackColor.CopyWithNewOpacity(TrackColor.A * TrackOpacity))
					.Thickness(FMath::Max(9.0f, Thickness))
				]
				+ SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SBox)
					.Visibility(bShowPercentText ? EVisibility::Visible : EVisibility::Collapsed)
					[
						SNew(STextBlock)
						.Text(FormatProgressPercent(Value))
						.Font(FCoreStyle::GetDefaultFontStyle("Bold", FMath::RoundToInt(FMath::Min(SafeSize.X, SafeSize.Y) * 0.16f)))
						.ColorAndOpacity(TextColor)
						.ShadowOffset(FVector2D(0.0f, 1.0f))
						.ShadowColorAndOpacity(FLinearColor(0.0f, 0.04f, 0.06f, 0.4f))
					]
				]
			]
		];
		return;
	}

	const float LinearWidth = FMath::Max(96.0f, LinearSize.X);
	const float LinearHeight = FMath::Max(24.0f, LinearSize.Y);
	const float TrackX = FMath::Clamp(LinearHeight * 0.42f, 12.0f, 32.0f);
	const float TextReserve = bShowPercentText ? FMath::Max(78.0f, LinearHeight * 1.35f) : TrackX;
	const float TrackWidth = FMath::Max(4.0f, LinearWidth - TrackX - TextReserve);
	const float TrackHeight = FMath::Max(8.0f, Thickness);
	const float TrackY = (LinearHeight - TrackHeight) * 0.5f;
	const float FillWidth = FMath::Clamp(Value, 0.0f, 1.0f) * TrackWidth;
	const float ThumbWidth = FMath::Max(0.0f, EndCapSize);
	const float ThumbHeight = FMath::Clamp(EndCapSize * 0.58f, TrackHeight, LinearHeight);
	const float ThumbX = TrackX + FillWidth - ThumbWidth * 0.52f;
	const float ThumbY = (LinearHeight - ThumbHeight) * 0.5f;

	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(LinearWidth)
		.HeightOverride(LinearHeight)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SNew(SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::Capsule)
				.BlurStrength(BlurStrength)
				.FrostRadius(FrostRadius)
				.RefractionStrength(RefractionStrength)
				.RefractionThickness(22.0f)
				.IndexOfRefraction(1.46f)
				.PrismIntensity(PrismIntensity)
				.TintColor(FLinearColor(0.72f, 0.96f, 1.0f, 1.0f))
				.TintOpacity(0.045f)
				.RimIntensity(0.46f)
				.GlowAmount(0.34f)
				.InnerGlowIntensity(0.12f)
				.InnerShadowIntensity(0.12f)
				.GlassOpacity(GlassOpacity)
				.Quality(Quality)
				[ SNew(SBox) ]
			]
			+ SOverlay::Slot()
			[
				SNew(SCanvas)
				+ SCanvas::Slot()
				.Position(FVector2D(TrackX, TrackY))
				.Size(FVector2D(TrackWidth, TrackHeight))
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Capsule)
					.BlurStrength(0.24f)
					.FrostRadius(0.04f)
					.RefractionStrength(0.08f)
					.RefractionThickness(8.0f)
					.IndexOfRefraction(1.12f)
					.TintColor(TrackColor)
					.TintOpacity(TrackOpacity)
					.RimIntensity(0.12f)
					.GlassOpacity(0.48f)
					.Quality(Quality)
					[ SNew(SBox) ]
				]
				+ SCanvas::Slot()
				.Position(FVector2D(TrackX, TrackY))
				.Size(FVector2D(FMath::Max(1.0f, FillWidth), TrackHeight))
				[
					SAssignNew(LinearFill, SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Capsule)
					.BlurStrength(0.03f)
					.FrostRadius(0.0f)
					.RefractionStrength(0.05f)
					.RefractionThickness(4.0f)
					.IndexOfRefraction(1.04f)
					.TintColor(FillColor)
					.TintOpacity(0.98f)
					.RimIntensity(0.08f)
					.GlowAmount(0.3f)
					.GlassOpacity(1.0f)
					.Quality(Quality)
					[ SNew(SBox) ]
				]
				+ SCanvas::Slot()
				.Position(FVector2D(FMath::Clamp(ThumbX, TrackX - 4.0f, TrackX + TrackWidth - ThumbWidth + 6.0f), ThumbY))
				.Size(FVector2D(ThumbWidth, ThumbHeight))
				[
					SNew(SCBLiquidGlass)
					.Shape(ECBLiquidGlassShape::Capsule)
					.BlurStrength(0.2f)
					.FrostRadius(0.025f)
					.RefractionStrength(FMath::Max(RefractionStrength, 0.72f))
					.RefractionThickness(32.0f)
					.IndexOfRefraction(1.78f)
					.PrismIntensity(FMath::Max(PrismIntensity, 0.2f))
					.TintColor(FillColor)
					.TintOpacity(0.035f)
					.RimIntensity(0.58f)
					.GlowAmount(0.52f)
					.InnerGlowIntensity(0.12f)
					.GlassOpacity(FMath::Max(GlassOpacity, 0.72f))
					.EdgeSoftness(0.35f)
					.Quality(Quality)
					[ SNew(SBox) ]
				]
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			.Padding(0.0f, 0.0f, 24.0f, 0.0f)
			[
				SNew(SBox)
				.Visibility(bShowPercentText ? EVisibility::Visible : EVisibility::Collapsed)
				[
					SNew(STextBlock)
					.Text(FormatProgressPercent(Value))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", FMath::RoundToInt(FMath::Clamp(LinearHeight * 0.31f, 12.0f, 24.0f))))
					.ColorAndOpacity(TextColor)
					.ShadowOffset(FVector2D(0.0f, 1.0f))
					.ShadowColorAndOpacity(FLinearColor(0.0f, 0.04f, 0.06f, 0.4f))
				]
			]
		]
	];
}

FVector2D SCBLiquidGlassProgress::GetLinearFillSize() const
{
	const float LinearWidth = FMath::Max(96.0f, LinearSize.X);
	const float LinearHeight = FMath::Max(24.0f, LinearSize.Y);
	const float TrackX = FMath::Clamp(LinearHeight * 0.42f, 12.0f, 32.0f);
	const float TextReserve = bShowPercentText ? FMath::Max(78.0f, LinearHeight * 1.35f) : TrackX;
	const float TrackWidth = FMath::Max(4.0f, LinearWidth - TrackX - TextReserve);
	return FVector2D(TrackWidth * Value, FMath::Max(8.0f, Thickness));
}

void SCBLiquidGlassStepper::Construct(const FArguments& InArgs)
{
	Value = InArgs._Value;
	MinValue = InArgs._MinValue;
	MaxValue = InArgs._MaxValue;
	Step = InArgs._Step;
	bIntegerOnly = InArgs._bIntegerOnly;
	Style = InArgs._Style;
	OnValueChanged = InArgs._OnValueChanged;
	CommitValue(Value);
	Rebuild();
}

void SCBLiquidGlassStepper::SetValue(float InValue) { CommitValue(InValue); Rebuild(); }
void SCBLiquidGlassStepper::SetMinValue(float InValue) { MinValue = InValue; CommitValue(Value); Rebuild(); }
void SCBLiquidGlassStepper::SetMaxValue(float InValue) { MaxValue = InValue; CommitValue(Value); Rebuild(); }
void SCBLiquidGlassStepper::SetStep(float InValue) { Step = FMath::Max(InValue, KINDA_SMALL_NUMBER); }
void SCBLiquidGlassStepper::SetIntegerOnly(bool bInValue) { bIntegerOnly = bInValue; CommitValue(Value); Rebuild(); }
void SCBLiquidGlassStepper::SetStyle(const FCBLiquidGlassControlStyle& InValue) { Style = InValue; Rebuild(); }
void SCBLiquidGlassStepper::SetOnValueChanged(FCBLiquidGlassFloatChanged InDelegate) { OnValueChanged = MoveTemp(InDelegate); }

void SCBLiquidGlassStepper::Rebuild()
{
	auto MakeButton = [this](const FText& Label, float Delta)
	{
		return SNew(SCBLiquidGlassButton)
			.Preset(ECBLiquidGlassPreset::PillLens)
			.Shape(ECBLiquidGlassShape::Circle)
			.OnClicked(FSimpleDelegate::CreateLambda([this, Delta]()
			{
				CommitValue(Value + Delta);
				Rebuild();
			}))
			[
				SNew(SBox)
				.WidthOverride(42.0f)
				.HeightOverride(42.0f)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock).Text(Label).Font(FCoreStyle::GetDefaultFontStyle("Bold", 22)).ColorAndOpacity(FLinearColor::White)
				]
			];
	};

	ChildSlot
	[
		SNew(SCBLiquidGlass)
		.Shape(ECBLiquidGlassShape::Capsule)
		.BlurStrength(0.62f)
		.FrostRadius(0.14f)
		.RefractionStrength(0.42f)
		.RefractionThickness(24.0f)
		.IndexOfRefraction(1.44f)
		.TintOpacity(0.045f)
		.RimIntensity(0.28f)
		.GlassOpacity(0.9f)
		.Quality(Style.Quality)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().Padding(6.0f)[MakeButton(LOCTEXT("StepperMinus", "-"), -Step)]
			+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(18.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text(this, &SCBLiquidGlassStepper::GetValueText)
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 18))
				.ColorAndOpacity(FLinearColor::White)
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(6.0f)[MakeButton(LOCTEXT("StepperPlus", "+"), Step)]
		]
	];
}

void SCBLiquidGlassStepper::CommitValue(float InValue)
{
	if (MaxValue < MinValue)
	{
		Swap(MaxValue, MinValue);
	}
	const float NewValue = bIntegerOnly ? FMath::RoundToFloat(InValue) : InValue;
	const float Clamped = FMath::Clamp(NewValue, MinValue, MaxValue);
	const bool bChanged = !FMath::IsNearlyEqual(Value, Clamped);
	Value = Clamped;
	if (bChanged && OnValueChanged.IsBound())
	{
		OnValueChanged.Execute(Value);
	}
}

FText SCBLiquidGlassStepper::GetValueText() const
{
	return bIntegerOnly ? FText::AsNumber(FMath::RoundToInt(Value)) : FText::AsNumber(Value);
}

#undef LOCTEXT_NAMESPACE

// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassExtras.h"
#include "SCBLiquidGlassExtras.h"

#include "Components/PanelSlot.h"
#include "Components/Widget.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlassExtras"

namespace
{
	const FText LiquidGlassPalette()
	{
		return LOCTEXT("LiquidGlassPaletteCategory", "Liquid Glass");
	}

	FCBLiquidGlassItem MakeButtonItem(const TCHAR* Label, int32 Value, ECBLiquidGlassItemState State = ECBLiquidGlassItemState::Normal)
	{
		FCBLiquidGlassItem Item;
		Item.Label = FText::FromString(Label);
		Item.Value = Value;
		Item.State = State;
		return Item;
	}
}

//////////////////////////////////////////////////////////////////////////
// UCBLiquidGlassBadge

UCBLiquidGlassBadge::UCBLiquidGlassBadge()
{
	bIsVariable = true;
}

TSharedRef<SWidget> UCBLiquidGlassBadge::RebuildWidget()
{
	MyBadge = SNew(SCBLiquidGlassBadge)
		.Count(Count)
		.MaxCount(MaxCount)
		.bDotMode(bDotMode)
		.Color(Color)
		.Style(Style);
	return MyBadge.ToSharedRef();
}

void UCBLiquidGlassBadge::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassBadge::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyBadge.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassBadge::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassBadge::SetCount(int32 InValue) { Count = InValue; if (MyBadge.IsValid()) MyBadge->SetCount(Count); }
void UCBLiquidGlassBadge::SetMaxCount(int32 InValue) { MaxCount = FMath::Max(InValue, 1); if (MyBadge.IsValid()) MyBadge->SetMaxCount(MaxCount); }
void UCBLiquidGlassBadge::SetDotMode(bool bInValue) { bDotMode = bInValue; if (MyBadge.IsValid()) MyBadge->SetDotMode(bDotMode); }
void UCBLiquidGlassBadge::SetColor(FLinearColor InValue) { Color = InValue; if (MyBadge.IsValid()) MyBadge->SetColor(Color); }

void UCBLiquidGlassBadge::PushPropertiesToSlate()
{
	if (!MyBadge.IsValid()) return;
	MyBadge->SetMaxCount(MaxCount);
	MyBadge->SetDotMode(bDotMode);
	MyBadge->SetColor(Color);
	MyBadge->SetStyle(Style);
	MyBadge->SetCount(Count);
}

//////////////////////////////////////////////////////////////////////////
// UCBLiquidGlassPageControl

UCBLiquidGlassPageControl::UCBLiquidGlassPageControl()
{
	bIsVariable = true;
}

TSharedRef<SWidget> UCBLiquidGlassPageControl::RebuildWidget()
{
	MyPageControl = SNew(SCBLiquidGlassPageControl)
		.NumPages(NumPages)
		.CurrentPage(CurrentPage)
		.DotSize(DotSize)
		.DotSpacing(DotSpacing)
		.ActiveColor(ActiveColor)
		.InactiveColor(InactiveColor)
		.Spring(SpringSettings)
		.OnPageChanged(FCBLiquidGlassPageChanged::CreateUObject(this, &UCBLiquidGlassPageControl::HandlePageChanged));
	return MyPageControl.ToSharedRef();
}

void UCBLiquidGlassPageControl::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassPageControl::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyPageControl.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassPageControl::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassPageControl::SetNumPages(int32 InValue) { NumPages = FMath::Max(InValue, 1); if (MyPageControl.IsValid()) MyPageControl->SetNumPages(NumPages); }
void UCBLiquidGlassPageControl::SetCurrentPage(int32 InValue) { CurrentPage = InValue; if (MyPageControl.IsValid()) MyPageControl->SetCurrentPage(CurrentPage); }

void UCBLiquidGlassPageControl::PushPropertiesToSlate()
{
	if (!MyPageControl.IsValid()) return;
	MyPageControl->SetNumPages(NumPages);
	MyPageControl->SetDotSize(DotSize);
	MyPageControl->SetDotSpacing(DotSpacing);
	MyPageControl->SetActiveColor(ActiveColor);
	MyPageControl->SetInactiveColor(InactiveColor);
	MyPageControl->SetSpring(SpringSettings);
	MyPageControl->SetCurrentPage(CurrentPage);
	MyPageControl->SetOnPageChanged(FCBLiquidGlassPageChanged::CreateUObject(this, &UCBLiquidGlassPageControl::HandlePageChanged));
}

void UCBLiquidGlassPageControl::HandlePageChanged(int32 InPage)
{
	CurrentPage = InPage;
	OnPageChanged.Broadcast(InPage);
}

//////////////////////////////////////////////////////////////////////////
// UCBLiquidGlassNavigationBar

UCBLiquidGlassNavigationBar::UCBLiquidGlassNavigationBar()
{
	bIsVariable = true;
	Title = LOCTEXT("NavBarDefaultTitle", "Title");
}

TSharedRef<SWidget> UCBLiquidGlassNavigationBar::RebuildWidget()
{
	MyNavBar = SNew(SCBLiquidGlassNavigationBar)
		.Title(Title)
		.bShowBackButton(bShowBackButton)
		.bLargeTitle(bLargeTitle)
		.TrailingItems(TrailingItems)
		.Style(Style)
		.OnBackClicked(FSimpleDelegate::CreateUObject(this, &UCBLiquidGlassNavigationBar::HandleBack))
		.OnTrailingItemClicked(FCBLiquidGlassNavItemClicked::CreateUObject(this, &UCBLiquidGlassNavigationBar::HandleTrailing));
	return MyNavBar.ToSharedRef();
}

void UCBLiquidGlassNavigationBar::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassNavigationBar::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyNavBar.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassNavigationBar::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassNavigationBar::SetTitle(FText InValue) { Title = InValue; if (MyNavBar.IsValid()) MyNavBar->SetTitle(Title); }
void UCBLiquidGlassNavigationBar::SetShowBackButton(bool bInValue) { bShowBackButton = bInValue; if (MyNavBar.IsValid()) MyNavBar->SetShowBackButton(bShowBackButton); }
void UCBLiquidGlassNavigationBar::SetLargeTitle(bool bInValue) { bLargeTitle = bInValue; if (MyNavBar.IsValid()) MyNavBar->SetLargeTitle(bLargeTitle); }
void UCBLiquidGlassNavigationBar::SetTrailingItems(const TArray<FCBLiquidGlassItem>& InItems) { TrailingItems = InItems; if (MyNavBar.IsValid()) MyNavBar->SetTrailingItems(TrailingItems); }

void UCBLiquidGlassNavigationBar::PushPropertiesToSlate()
{
	if (!MyNavBar.IsValid()) return;
	MyNavBar->SetStyle(Style);
	MyNavBar->SetShowBackButton(bShowBackButton);
	MyNavBar->SetLargeTitle(bLargeTitle);
	MyNavBar->SetTrailingItems(TrailingItems);
	MyNavBar->SetTitle(Title);
	MyNavBar->SetOnBackClicked(FSimpleDelegate::CreateUObject(this, &UCBLiquidGlassNavigationBar::HandleBack));
	MyNavBar->SetOnTrailingItemClicked(FCBLiquidGlassNavItemClicked::CreateUObject(this, &UCBLiquidGlassNavigationBar::HandleTrailing));
}

void UCBLiquidGlassNavigationBar::HandleBack() { OnBackClicked.Broadcast(); }
void UCBLiquidGlassNavigationBar::HandleTrailing(int32 Index, int32 Value) { OnTrailingItemClicked.Broadcast(Index, Value); }

//////////////////////////////////////////////////////////////////////////
// UCBLiquidGlassDialog

UCBLiquidGlassDialog::UCBLiquidGlassDialog()
{
	bIsVariable = true;
	Title = LOCTEXT("DialogDefaultTitle", "Title");
	Buttons = { MakeButtonItem(TEXT("OK"), 0, ECBLiquidGlassItemState::Selected) };
}

TSharedRef<SWidget> UCBLiquidGlassDialog::RebuildWidget()
{
	MyDialog = SNew(SCBLiquidGlassDialog)
		.Title(Title)
		.Message(Message)
		.Buttons(Buttons)
		.DialogStyle(DialogStyle)
		.bDimBackground(bDimBackground)
		.bStartPresented(bStartPresented)
		.DimOpacity(DimOpacity)
		.CardBlurStrength(CardBlurStrength)
		.CardFrostRadius(CardFrostRadius)
		.CardRefractionStrength(CardRefractionStrength)
		.CardRefractionThickness(CardRefractionThickness)
		.CardPrismIntensity(CardPrismIntensity)
		.CardRimIntensity(CardRimIntensity)
		.CardGlassOpacity(CardGlassOpacity)
		.Style(Style)
		.Spring(SpringSettings)
		.OnButtonClicked(FCBLiquidGlassDialogButtonClicked::CreateUObject(this, &UCBLiquidGlassDialog::HandleButton))
		.OnDismissed(FSimpleDelegate::CreateUObject(this, &UCBLiquidGlassDialog::HandleDismissed));
	return MyDialog.ToSharedRef();
}

void UCBLiquidGlassDialog::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassDialog::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyDialog.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassDialog::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassDialog::Present() { if (MyDialog.IsValid()) MyDialog->Present(); }
void UCBLiquidGlassDialog::Dismiss() { if (MyDialog.IsValid()) MyDialog->Dismiss(); }
void UCBLiquidGlassDialog::SetTitle(FText InValue) { Title = InValue; if (MyDialog.IsValid()) MyDialog->SetTitle(Title); }
void UCBLiquidGlassDialog::SetMessage(FText InValue) { Message = InValue; if (MyDialog.IsValid()) MyDialog->SetMessage(Message); }
void UCBLiquidGlassDialog::SetButtons(const TArray<FCBLiquidGlassItem>& InButtons) { Buttons = InButtons; if (MyDialog.IsValid()) MyDialog->SetButtons(Buttons); }
void UCBLiquidGlassDialog::SetDimBackground(bool bInValue) { bDimBackground = bInValue; if (MyDialog.IsValid()) MyDialog->SetDimBackground(bDimBackground); }
void UCBLiquidGlassDialog::SetDimOpacity(float InValue) { DimOpacity = FMath::Clamp(InValue, 0.0f, 1.0f); if (MyDialog.IsValid()) MyDialog->SetDimOpacity(DimOpacity); }
void UCBLiquidGlassDialog::SetCardBlurStrength(float InValue) { CardBlurStrength = FMath::Max(InValue, 0.0f); if (MyDialog.IsValid()) MyDialog->SetCardBlurStrength(CardBlurStrength); }
void UCBLiquidGlassDialog::SetCardFrostRadius(float InValue) { CardFrostRadius = FMath::Max(InValue, 0.0f); if (MyDialog.IsValid()) MyDialog->SetCardFrostRadius(CardFrostRadius); }
void UCBLiquidGlassDialog::SetCardRefractionStrength(float InValue) { CardRefractionStrength = FMath::Max(InValue, 0.0f); if (MyDialog.IsValid()) MyDialog->SetCardRefractionStrength(CardRefractionStrength); }
void UCBLiquidGlassDialog::SetCardRefractionThickness(float InValue) { CardRefractionThickness = FMath::Max(InValue, 0.0f); if (MyDialog.IsValid()) MyDialog->SetCardRefractionThickness(CardRefractionThickness); }
void UCBLiquidGlassDialog::SetCardPrismIntensity(float InValue) { CardPrismIntensity = FMath::Max(InValue, 0.0f); if (MyDialog.IsValid()) MyDialog->SetCardPrismIntensity(CardPrismIntensity); }
void UCBLiquidGlassDialog::SetCardRimIntensity(float InValue) { CardRimIntensity = FMath::Max(InValue, 0.0f); if (MyDialog.IsValid()) MyDialog->SetCardRimIntensity(CardRimIntensity); }
void UCBLiquidGlassDialog::SetCardGlassOpacity(float InValue) { CardGlassOpacity = FMath::Clamp(InValue, 0.0f, 1.0f); if (MyDialog.IsValid()) MyDialog->SetCardGlassOpacity(CardGlassOpacity); }

void UCBLiquidGlassDialog::PushPropertiesToSlate()
{
	if (!MyDialog.IsValid()) return;
	MyDialog->SetStyle(Style);
	MyDialog->SetSpring(SpringSettings);
	MyDialog->SetDimBackground(bDimBackground);
	MyDialog->SetDimOpacity(DimOpacity);
	MyDialog->SetCardBlurStrength(CardBlurStrength);
	MyDialog->SetCardFrostRadius(CardFrostRadius);
	MyDialog->SetCardRefractionStrength(CardRefractionStrength);
	MyDialog->SetCardRefractionThickness(CardRefractionThickness);
	MyDialog->SetCardPrismIntensity(CardPrismIntensity);
	MyDialog->SetCardRimIntensity(CardRimIntensity);
	MyDialog->SetCardGlassOpacity(CardGlassOpacity);
	MyDialog->SetDialogStyle(DialogStyle);
	MyDialog->SetMessage(Message);
	MyDialog->SetButtons(Buttons);
	MyDialog->SetTitle(Title);
	MyDialog->SetOnButtonClicked(FCBLiquidGlassDialogButtonClicked::CreateUObject(this, &UCBLiquidGlassDialog::HandleButton));
	MyDialog->SetOnDismissed(FSimpleDelegate::CreateUObject(this, &UCBLiquidGlassDialog::HandleDismissed));
	if (bStartPresented && !MyDialog->IsPresented())
	{
		MyDialog->Present();
	}
}

void UCBLiquidGlassDialog::HandleButton(int32 Index, int32 Value) { OnButtonClicked.Broadcast(Index, Value); }
void UCBLiquidGlassDialog::HandleDismissed() { OnDismissed.Broadcast(); }

//////////////////////////////////////////////////////////////////////////
// UCBLiquidGlassContainer

UCBLiquidGlassContainer::UCBLiquidGlassContainer()
{
	bIsVariable = true;
}

TSharedRef<SWidget> UCBLiquidGlassContainer::RebuildWidget()
{
	TSharedRef<SWidget> ContentWidget = GetContent() ? GetContent()->TakeWidget() : SNullWidget::NullWidget;

	MyContainer = SNew(SCBLiquidGlassContainer)
		.Blobs(Blobs)
		.Smoothing(Smoothing)
		.CanvasSize(CanvasSize)
		.MaskResolution(MaskResolution)
		.BlurStrength(BlurStrength)
		.FrostRadius(FrostRadius)
		.RefractionStrength(RefractionStrength)
		.RefractionThickness(RefractionThickness)
		.PrismIntensity(PrismIntensity)
		.RimIntensity(RimIntensity)
		.GlassOpacity(GlassOpacity)
		.Preset(Preset)
		.Quality(Quality)
		[
			ContentWidget
		];
	return MyContainer.ToSharedRef();
}

void UCBLiquidGlassContainer::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassContainer::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyContainer.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassContainer::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassContainer::SetBlobs(const TArray<FCBLiquidGlassFusionBlob>& InBlobs) { Blobs = InBlobs; if (MyContainer.IsValid()) MyContainer->SetBlobs(Blobs); }
void UCBLiquidGlassContainer::SetSmoothing(float InValue) { Smoothing = FMath::Max(InValue, 0.0f); if (MyContainer.IsValid()) MyContainer->SetSmoothing(Smoothing); }
void UCBLiquidGlassContainer::SetCanvasSize(FVector2D InValue) { CanvasSize = InValue; if (MyContainer.IsValid()) MyContainer->SetCanvasSize(CanvasSize); }
void UCBLiquidGlassContainer::SetMaskResolution(FVector2D InValue) { MaskResolution = InValue; if (MyContainer.IsValid()) MyContainer->SetMaskResolution(MaskResolution); }
void UCBLiquidGlassContainer::SetBlurStrength(float InValue) { BlurStrength = FMath::Max(InValue, 0.0f); if (MyContainer.IsValid()) MyContainer->SetBlurStrength(BlurStrength); }
void UCBLiquidGlassContainer::SetFrostRadius(float InValue) { FrostRadius = FMath::Max(InValue, 0.0f); if (MyContainer.IsValid()) MyContainer->SetFrostRadius(FrostRadius); }
void UCBLiquidGlassContainer::SetRefractionStrength(float InValue) { RefractionStrength = FMath::Max(InValue, 0.0f); if (MyContainer.IsValid()) MyContainer->SetRefractionStrength(RefractionStrength); }
void UCBLiquidGlassContainer::SetRefractionThickness(float InValue) { RefractionThickness = FMath::Max(InValue, 0.0f); if (MyContainer.IsValid()) MyContainer->SetRefractionThickness(RefractionThickness); }
void UCBLiquidGlassContainer::SetPrismIntensity(float InValue) { PrismIntensity = FMath::Max(InValue, 0.0f); if (MyContainer.IsValid()) MyContainer->SetPrismIntensity(PrismIntensity); }
void UCBLiquidGlassContainer::SetRimIntensity(float InValue) { RimIntensity = FMath::Max(InValue, 0.0f); if (MyContainer.IsValid()) MyContainer->SetRimIntensity(RimIntensity); }
void UCBLiquidGlassContainer::SetGlassOpacity(float InValue) { GlassOpacity = FMath::Clamp(InValue, 0.0f, 1.0f); if (MyContainer.IsValid()) MyContainer->SetGlassOpacity(GlassOpacity); }
void UCBLiquidGlassContainer::SetPreset(ECBLiquidGlassPreset InValue) { Preset = InValue; if (MyContainer.IsValid()) MyContainer->SetPreset(Preset); }
void UCBLiquidGlassContainer::SetQuality(ECBLiquidGlassQuality InValue) { Quality = InValue; if (MyContainer.IsValid()) MyContainer->SetQuality(Quality); }

void UCBLiquidGlassContainer::PushPropertiesToSlate()
{
	if (!MyContainer.IsValid()) return;
	MyContainer->SetCanvasSize(CanvasSize);
	MyContainer->SetMaskResolution(MaskResolution);
	MyContainer->SetBlurStrength(BlurStrength);
	MyContainer->SetFrostRadius(FrostRadius);
	MyContainer->SetRefractionStrength(RefractionStrength);
	MyContainer->SetRefractionThickness(RefractionThickness);
	MyContainer->SetPrismIntensity(PrismIntensity);
	MyContainer->SetRimIntensity(RimIntensity);
	MyContainer->SetGlassOpacity(GlassOpacity);
	MyContainer->SetQuality(Quality);
	MyContainer->SetPreset(Preset);
	MyContainer->SetSmoothing(Smoothing);
	MyContainer->SetBlobs(Blobs);
}

void UCBLiquidGlassContainer::OnSlotAdded(UPanelSlot* AddedSlot)
{
	if (MyContainer.IsValid() && AddedSlot && AddedSlot->Content)
	{
		MyContainer->SetContent(AddedSlot->Content->TakeWidget());
	}
}

void UCBLiquidGlassContainer::OnSlotRemoved(UPanelSlot*)
{
	if (MyContainer.IsValid())
	{
		MyContainer->SetContent(SNullWidget::NullWidget);
	}
}

#undef LOCTEXT_NAMESPACE

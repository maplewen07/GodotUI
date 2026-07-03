// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassControls.h"
#include "SCBLiquidGlassControls.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlassControls"

namespace
{
	const FText LiquidGlassPalette()
	{
		return LOCTEXT("LiquidGlassPaletteCategory", "Liquid Glass");
	}

	FCBLiquidGlassItem MakeDefaultItem(const TCHAR* Label, int32 Value, ECBLiquidGlassItemState State = ECBLiquidGlassItemState::Normal)
	{
		FCBLiquidGlassItem Item;
		Item.Label = FText::FromString(Label);
		Item.Value = Value;
		Item.State = State;
		Item.bEnabled = State != ECBLiquidGlassItemState::Disabled && State != ECBLiquidGlassItemState::Separator;
		return Item;
	}
}

UCBLiquidGlassToggle::UCBLiquidGlassToggle()
{
	bIsVariable = true;
}

TSharedRef<SWidget> UCBLiquidGlassToggle::RebuildWidget()
{
	MyToggle = SNew(SCBLiquidGlassToggle)
		.Checked(bChecked)
		.OnColor(OnColor)
		.OffColor(OffColor)
		.Style(Style)
		.Spring(SpringSettings)
		.OnCheckStateChanged(FCBLiquidGlassCheckChanged::CreateUObject(this, &UCBLiquidGlassToggle::HandleChanged));
	return MyToggle.ToSharedRef();
}

void UCBLiquidGlassToggle::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassToggle::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyToggle.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassToggle::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassToggle::SetChecked(bool bInValue) { bChecked = bInValue; if (MyToggle.IsValid()) MyToggle->SetChecked(bChecked); }
void UCBLiquidGlassToggle::SetOnColor(FLinearColor InValue) { OnColor = InValue; if (MyToggle.IsValid()) MyToggle->SetOnColor(OnColor); }
void UCBLiquidGlassToggle::SetOffColor(FLinearColor InValue) { OffColor = InValue; if (MyToggle.IsValid()) MyToggle->SetOffColor(OffColor); }
void UCBLiquidGlassToggle::SetStyle(FCBLiquidGlassControlStyle InValue) { Style = InValue; if (MyToggle.IsValid()) MyToggle->SetStyle(Style); }
void UCBLiquidGlassToggle::SetSpringSettings(FCBLiquidGlassSpringSettings InValue) { SpringSettings = InValue; if (MyToggle.IsValid()) MyToggle->SetSpringSettings(SpringSettings); }

void UCBLiquidGlassToggle::PushPropertiesToSlate()
{
	if (!MyToggle.IsValid()) return;
	MyToggle->SetChecked(bChecked);
	MyToggle->SetOnColor(OnColor);
	MyToggle->SetOffColor(OffColor);
	MyToggle->SetStyle(Style);
	MyToggle->SetSpringSettings(SpringSettings);
	MyToggle->SetOnCheckStateChanged(FCBLiquidGlassCheckChanged::CreateUObject(this, &UCBLiquidGlassToggle::HandleChanged));
}

void UCBLiquidGlassToggle::HandleChanged(bool bInValue)
{
	bChecked = bInValue;
	OnCheckStateChanged.Broadcast(bChecked);
}

UCBLiquidGlassSegmentedControl::UCBLiquidGlassSegmentedControl()
{
	bIsVariable = true;
	Items = {
		MakeDefaultItem(TEXT("One"), 0),
		MakeDefaultItem(TEXT("Two"), 1),
		MakeDefaultItem(TEXT("Three"), 2),
	};
	SelectedIndex = 1;
}

TSharedRef<SWidget> UCBLiquidGlassSegmentedControl::RebuildWidget()
{
	MyControl = SNew(SCBLiquidGlassSegmentedControl)
		.Items(Items)
		.SelectedIndex(SelectedIndex)
		.Orientation(Orientation)
		.bShowIcons(bShowIcons)
		.bShowLabels(bShowLabels)
		.ItemSize(ItemSize)
		.Padding(Padding)
		.Style(Style)
		.Spring(SpringSettings)
		.OnSelectionChanged(FCBLiquidGlassIndexChanged::CreateUObject(this, &UCBLiquidGlassSegmentedControl::HandleSelectionChanged));
	return MyControl.ToSharedRef();
}

void UCBLiquidGlassSegmentedControl::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassSegmentedControl::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyControl.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassSegmentedControl::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassSegmentedControl::SetItems(const TArray<FCBLiquidGlassItem>& InItems) { Items = InItems; if (MyControl.IsValid()) MyControl->SetItems(Items); }
void UCBLiquidGlassSegmentedControl::SetSelectedIndex(int32 InValue) { SelectedIndex = InValue; if (MyControl.IsValid()) MyControl->SetSelectedIndex(SelectedIndex); }
void UCBLiquidGlassSegmentedControl::SetOrientation(ECBLiquidGlassOrientation InValue) { Orientation = InValue; if (MyControl.IsValid()) MyControl->SetOrientation(Orientation); }
void UCBLiquidGlassSegmentedControl::SetShowIcons(bool bInValue) { bShowIcons = bInValue; if (MyControl.IsValid()) MyControl->SetShowIcons(bShowIcons); }
void UCBLiquidGlassSegmentedControl::SetShowLabels(bool bInValue) { bShowLabels = bInValue; if (MyControl.IsValid()) MyControl->SetShowLabels(bShowLabels); }
void UCBLiquidGlassSegmentedControl::SetItemSize(FVector2D InValue) { ItemSize = InValue; if (MyControl.IsValid()) MyControl->SetItemSize(ItemSize); }
void UCBLiquidGlassSegmentedControl::SetPadding(FMargin InValue) { Padding = InValue; if (MyControl.IsValid()) MyControl->SetPadding(Padding); }
void UCBLiquidGlassSegmentedControl::SetStyle(FCBLiquidGlassControlStyle InValue) { Style = InValue; if (MyControl.IsValid()) MyControl->SetStyle(Style); }
void UCBLiquidGlassSegmentedControl::SetSpringSettings(FCBLiquidGlassSpringSettings InValue) { SpringSettings = InValue; if (MyControl.IsValid()) MyControl->SetSpringSettings(SpringSettings); }

void UCBLiquidGlassSegmentedControl::PushPropertiesToSlate()
{
	if (!MyControl.IsValid()) return;
	MyControl->SetItems(Items);
	MyControl->SetSelectedIndex(SelectedIndex);
	MyControl->SetOrientation(Orientation);
	MyControl->SetShowIcons(bShowIcons);
	MyControl->SetShowLabels(bShowLabels);
	MyControl->SetItemSize(ItemSize);
	MyControl->SetPadding(Padding);
	MyControl->SetStyle(Style);
	MyControl->SetSpringSettings(SpringSettings);
	MyControl->SetOnSelectionChanged(FCBLiquidGlassIndexChanged::CreateUObject(this, &UCBLiquidGlassSegmentedControl::HandleSelectionChanged));
}

void UCBLiquidGlassSegmentedControl::HandleSelectionChanged(int32 Index, int32 Value)
{
	SelectedIndex = Index;
	OnSelectionChanged.Broadcast(Index, Value);
}

UCBLiquidGlassTabBar::UCBLiquidGlassTabBar()
{
	bIsVariable = true;
	Items = {
		MakeDefaultItem(TEXT("Home"), 0),
		MakeDefaultItem(TEXT("Search"), 1),
		MakeDefaultItem(TEXT("Tools"), 2),
		MakeDefaultItem(TEXT("More"), 3),
	};
}

TSharedRef<SWidget> UCBLiquidGlassTabBar::RebuildWidget()
{
	MyTabBar = SNew(SCBLiquidGlassTabBar)
		.Items(Items)
		.SelectedIndex(SelectedIndex)
		.bShowLabels(bShowLabels)
		.bShowIcons(bShowIcons)
		.ItemSize(ItemSize)
		.Padding(Padding)
		.Style(Style)
		.Spring(SpringSettings)
		.OnTabChanged(FCBLiquidGlassIndexChanged::CreateUObject(this, &UCBLiquidGlassTabBar::HandleTabChanged));
	return MyTabBar.ToSharedRef();
}

void UCBLiquidGlassTabBar::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassTabBar::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyTabBar.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassTabBar::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassTabBar::SetItems(const TArray<FCBLiquidGlassItem>& InItems) { Items = InItems; if (MyTabBar.IsValid()) MyTabBar->SetItems(Items); }
void UCBLiquidGlassTabBar::SetSelectedIndex(int32 InValue) { SelectedIndex = InValue; if (MyTabBar.IsValid()) MyTabBar->SetSelectedIndex(SelectedIndex); }
void UCBLiquidGlassTabBar::SetShowLabels(bool bInValue) { bShowLabels = bInValue; if (MyTabBar.IsValid()) MyTabBar->SetShowLabels(bShowLabels); }
void UCBLiquidGlassTabBar::SetShowIcons(bool bInValue) { bShowIcons = bInValue; if (MyTabBar.IsValid()) MyTabBar->SetShowIcons(bShowIcons); }
void UCBLiquidGlassTabBar::SetItemSize(FVector2D InValue) { ItemSize = InValue; if (MyTabBar.IsValid()) MyTabBar->SetItemSize(ItemSize); }
void UCBLiquidGlassTabBar::SetPadding(FMargin InValue) { Padding = InValue; if (MyTabBar.IsValid()) MyTabBar->SetPadding(Padding); }
void UCBLiquidGlassTabBar::SetStyle(FCBLiquidGlassControlStyle InValue) { Style = InValue; if (MyTabBar.IsValid()) MyTabBar->SetStyle(Style); }
void UCBLiquidGlassTabBar::SetSpringSettings(FCBLiquidGlassSpringSettings InValue) { SpringSettings = InValue; if (MyTabBar.IsValid()) MyTabBar->SetSpringSettings(SpringSettings); }

void UCBLiquidGlassTabBar::PushPropertiesToSlate()
{
	if (!MyTabBar.IsValid()) return;
	MyTabBar->SetItems(Items);
	MyTabBar->SetSelectedIndex(SelectedIndex);
	MyTabBar->SetShowLabels(bShowLabels);
	MyTabBar->SetShowIcons(bShowIcons);
	MyTabBar->SetItemSize(ItemSize);
	MyTabBar->SetPadding(Padding);
	MyTabBar->SetStyle(Style);
	MyTabBar->SetSpringSettings(SpringSettings);
	MyTabBar->SetOnTabChanged(FCBLiquidGlassIndexChanged::CreateUObject(this, &UCBLiquidGlassTabBar::HandleTabChanged));
}

void UCBLiquidGlassTabBar::HandleTabChanged(int32 Index, int32 Value)
{
	SelectedIndex = Index;
	OnTabChanged.Broadcast(Index, Value);
}

UCBLiquidGlassToolbar::UCBLiquidGlassToolbar()
{
	bIsVariable = true;
	Items = {
		MakeDefaultItem(TEXT("Move"), 0),
		MakeDefaultItem(TEXT("Tune"), 1),
		MakeDefaultItem(TEXT("Mask"), 2),
		MakeDefaultItem(TEXT("More"), 3),
	};
	bToggleMode = true;
	SelectedIndex = 1;
}

TSharedRef<SWidget> UCBLiquidGlassToolbar::RebuildWidget()
{
	MyToolbar = SNew(SCBLiquidGlassToolbar)
		.Items(Items)
		.Orientation(Orientation)
		.bToggleMode(bToggleMode)
		.SelectedIndex(SelectedIndex)
		.bShowIcons(bShowIcons)
		.bShowLabels(bShowLabels)
		.ItemSize(ItemSize)
		.Padding(Padding)
		.Style(Style)
		.OnToolClicked(FCBLiquidGlassItemClicked::CreateUObject(this, &UCBLiquidGlassToolbar::HandleToolClicked));
	return MyToolbar.ToSharedRef();
}

void UCBLiquidGlassToolbar::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassToolbar::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyToolbar.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassToolbar::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassToolbar::SetItems(const TArray<FCBLiquidGlassItem>& InItems) { Items = InItems; if (MyToolbar.IsValid()) MyToolbar->SetItems(Items); }
void UCBLiquidGlassToolbar::SetOrientation(ECBLiquidGlassOrientation InValue) { Orientation = InValue; if (MyToolbar.IsValid()) MyToolbar->SetOrientation(Orientation); }
void UCBLiquidGlassToolbar::SetToggleMode(bool bInValue) { bToggleMode = bInValue; if (MyToolbar.IsValid()) MyToolbar->SetToggleMode(bToggleMode); }
void UCBLiquidGlassToolbar::SetSelectedIndex(int32 InValue) { SelectedIndex = InValue; if (MyToolbar.IsValid()) MyToolbar->SetSelectedIndex(SelectedIndex); }
void UCBLiquidGlassToolbar::SetShowIcons(bool bInValue) { bShowIcons = bInValue; if (MyToolbar.IsValid()) MyToolbar->SetShowIcons(bShowIcons); }
void UCBLiquidGlassToolbar::SetShowLabels(bool bInValue) { bShowLabels = bInValue; if (MyToolbar.IsValid()) MyToolbar->SetShowLabels(bShowLabels); }
void UCBLiquidGlassToolbar::SetItemSize(FVector2D InValue) { ItemSize = InValue; if (MyToolbar.IsValid()) MyToolbar->SetItemSize(ItemSize); }
void UCBLiquidGlassToolbar::SetPadding(FMargin InValue) { Padding = InValue; if (MyToolbar.IsValid()) MyToolbar->SetPadding(Padding); }
void UCBLiquidGlassToolbar::SetStyle(FCBLiquidGlassControlStyle InValue) { Style = InValue; if (MyToolbar.IsValid()) MyToolbar->SetStyle(Style); }

void UCBLiquidGlassToolbar::PushPropertiesToSlate()
{
	if (!MyToolbar.IsValid()) return;
	MyToolbar->SetItems(Items);
	MyToolbar->SetOrientation(Orientation);
	MyToolbar->SetToggleMode(bToggleMode);
	MyToolbar->SetSelectedIndex(SelectedIndex);
	MyToolbar->SetShowIcons(bShowIcons);
	MyToolbar->SetShowLabels(bShowLabels);
	MyToolbar->SetItemSize(ItemSize);
	MyToolbar->SetPadding(Padding);
	MyToolbar->SetStyle(Style);
	MyToolbar->SetOnToolClicked(FCBLiquidGlassItemClicked::CreateUObject(this, &UCBLiquidGlassToolbar::HandleToolClicked));
}

void UCBLiquidGlassToolbar::HandleToolClicked(int32 Index, int32 Value)
{
	SelectedIndex = Index;
	OnToolClicked.Broadcast(Index, Value);
}

UCBLiquidGlassMenu::UCBLiquidGlassMenu()
{
	bIsVariable = true;
	Style.Preset = ECBLiquidGlassPreset::FrostedMenu;
	Items = {
		MakeDefaultItem(TEXT("Find in Note"), 0),
		MakeDefaultItem(TEXT("Move Note"), 1, ECBLiquidGlassItemState::Disabled),
		MakeDefaultItem(TEXT(""), 0, ECBLiquidGlassItemState::Separator),
		MakeDefaultItem(TEXT("Format"), 2),
		MakeDefaultItem(TEXT("Delete"), 3, ECBLiquidGlassItemState::Danger),
	};
}

TSharedRef<SWidget> UCBLiquidGlassMenu::RebuildWidget()
{
	MyMenu = SNew(SCBLiquidGlassMenu)
		.Items(Items)
		.ItemHeight(ItemHeight)
		.bCloseOnClick(bCloseOnClick)
		.bShowIcons(bShowIcons)
		.bShowLabels(bShowLabels)
		.Style(Style)
		.OnMenuItemClicked(FCBLiquidGlassItemClicked::CreateUObject(this, &UCBLiquidGlassMenu::HandleMenuItemClicked));
	return MyMenu.ToSharedRef();
}

void UCBLiquidGlassMenu::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassMenu::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyMenu.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassMenu::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassMenu::SetItems(const TArray<FCBLiquidGlassItem>& InItems) { Items = InItems; if (MyMenu.IsValid()) MyMenu->SetItems(Items); }
void UCBLiquidGlassMenu::SetItemHeight(float InValue) { ItemHeight = InValue; if (MyMenu.IsValid()) MyMenu->SetItemHeight(ItemHeight); }
void UCBLiquidGlassMenu::SetCloseOnClick(bool bInValue) { bCloseOnClick = bInValue; if (MyMenu.IsValid()) MyMenu->SetCloseOnClick(bCloseOnClick); }
void UCBLiquidGlassMenu::SetShowIcons(bool bInValue) { bShowIcons = bInValue; if (MyMenu.IsValid()) MyMenu->SetShowIcons(bShowIcons); }
void UCBLiquidGlassMenu::SetShowLabels(bool bInValue) { bShowLabels = bInValue; if (MyMenu.IsValid()) MyMenu->SetShowLabels(bShowLabels); }
void UCBLiquidGlassMenu::SetStyle(FCBLiquidGlassControlStyle InValue) { Style = InValue; if (MyMenu.IsValid()) MyMenu->SetStyle(Style); }

void UCBLiquidGlassMenu::PushPropertiesToSlate()
{
	if (!MyMenu.IsValid()) return;
	MyMenu->SetItems(Items);
	MyMenu->SetItemHeight(ItemHeight);
	MyMenu->SetCloseOnClick(bCloseOnClick);
	MyMenu->SetShowIcons(bShowIcons);
	MyMenu->SetShowLabels(bShowLabels);
	MyMenu->SetStyle(Style);
	MyMenu->SetOnMenuItemClicked(FCBLiquidGlassItemClicked::CreateUObject(this, &UCBLiquidGlassMenu::HandleMenuItemClicked));
}

void UCBLiquidGlassMenu::HandleMenuItemClicked(int32 Index, int32 Value)
{
	OnMenuItemClicked.Broadcast(Index, Value);
}

UCBLiquidGlassSearchBar::UCBLiquidGlassSearchBar()
{
	bIsVariable = true;
	HintText = LOCTEXT("DefaultSearchHint", "Search anything...");
	Style.Preset = ECBLiquidGlassPreset::FrostedMenu;
}

TSharedRef<SWidget> UCBLiquidGlassSearchBar::RebuildWidget()
{
	MySearchBar = SNew(SCBLiquidGlassSearchBar)
		.Text(Text)
		.HintText(HintText)
		.bShowClearButton(bShowClearButton)
		.bShowSearchIcon(bShowSearchIcon)
		.bShowText(bShowText)
		.Style(Style)
		.SearchBoxStyle(SearchBoxStyle)
		.OnTextChanged(FCBLiquidGlassTextChanged::CreateUObject(this, &UCBLiquidGlassSearchBar::HandleTextChanged))
		.OnTextCommitted(FCBLiquidGlassTextCommitted::CreateUObject(this, &UCBLiquidGlassSearchBar::HandleTextCommitted));
	return MySearchBar.ToSharedRef();
}

void UCBLiquidGlassSearchBar::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassSearchBar::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MySearchBar.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassSearchBar::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassSearchBar::SetText(FText InText) { Text = InText; if (MySearchBar.IsValid()) MySearchBar->SetText(Text); }
void UCBLiquidGlassSearchBar::SetHintText(FText InText) { HintText = InText; if (MySearchBar.IsValid()) MySearchBar->SetHintText(HintText); }
void UCBLiquidGlassSearchBar::SetShowClearButton(bool bInValue) { bShowClearButton = bInValue; if (MySearchBar.IsValid()) MySearchBar->SetShowClearButton(bShowClearButton); }
void UCBLiquidGlassSearchBar::SetShowSearchIcon(bool bInValue) { bShowSearchIcon = bInValue; if (MySearchBar.IsValid()) MySearchBar->SetShowSearchIcon(bShowSearchIcon); }
void UCBLiquidGlassSearchBar::SetShowText(bool bInValue) { bShowText = bInValue; if (MySearchBar.IsValid()) MySearchBar->SetShowText(bShowText); }
void UCBLiquidGlassSearchBar::SetStyle(FCBLiquidGlassControlStyle InValue) { Style = InValue; if (MySearchBar.IsValid()) MySearchBar->SetStyle(Style); }
void UCBLiquidGlassSearchBar::SetSearchBoxStyle(FCBLiquidGlassSearchBoxStyle InValue) { SearchBoxStyle = InValue; if (MySearchBar.IsValid()) MySearchBar->SetSearchBoxStyle(SearchBoxStyle); }

void UCBLiquidGlassSearchBar::PushPropertiesToSlate()
{
	if (!MySearchBar.IsValid()) return;
	MySearchBar->SetText(Text);
	MySearchBar->SetHintText(HintText);
	MySearchBar->SetShowClearButton(bShowClearButton);
	MySearchBar->SetShowSearchIcon(bShowSearchIcon);
	MySearchBar->SetShowText(bShowText);
	MySearchBar->SetStyle(Style);
	MySearchBar->SetSearchBoxStyle(SearchBoxStyle);
	MySearchBar->SetOnTextChanged(FCBLiquidGlassTextChanged::CreateUObject(this, &UCBLiquidGlassSearchBar::HandleTextChanged));
	MySearchBar->SetOnTextCommitted(FCBLiquidGlassTextCommitted::CreateUObject(this, &UCBLiquidGlassSearchBar::HandleTextCommitted));
}

void UCBLiquidGlassSearchBar::HandleTextChanged(const FText& InText)
{
	Text = InText;
	OnTextChanged.Broadcast(Text);
}

void UCBLiquidGlassSearchBar::HandleTextCommitted(const FText& InText)
{
	Text = InText;
	OnTextCommitted.Broadcast(Text);
}

UCBLiquidGlassProgress::UCBLiquidGlassProgress()
{
	bIsVariable = true;
}

TSharedRef<SWidget> UCBLiquidGlassProgress::RebuildWidget()
{
	MyProgress = SNew(SCBLiquidGlassProgress)
		.Value(Value)
		.ProgressStyle(ProgressStyle)
		.FillColor(FillColor)
		.Thickness(Thickness)
		.LinearSize(LinearSize)
		.CircularSize(CircularSize)
		.EndCapSize(EndCapSize)
		.TrackColor(TrackColor)
		.TrackOpacity(TrackOpacity)
		.bShowPercentText(bShowPercentText)
		.TextColor(TextColor)
		.BlurStrength(BlurStrength)
		.FrostRadius(FrostRadius)
		.RefractionStrength(RefractionStrength)
		.PrismIntensity(PrismIntensity)
		.GlassOpacity(GlassOpacity)
		.Quality(Quality);
	return MyProgress.ToSharedRef();
}

void UCBLiquidGlassProgress::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassProgress::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyProgress.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassProgress::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassProgress::SetValue(float InValue) { Value = FMath::Clamp(InValue, 0.0f, 1.0f); if (MyProgress.IsValid()) MyProgress->SetValue(Value); }
void UCBLiquidGlassProgress::SetProgressStyle(ECBLiquidGlassProgressStyle InValue) { ProgressStyle = InValue; if (MyProgress.IsValid()) MyProgress->SetProgressStyle(ProgressStyle); }
void UCBLiquidGlassProgress::SetFillColor(FLinearColor InValue) { FillColor = InValue; if (MyProgress.IsValid()) MyProgress->SetFillColor(FillColor); }
void UCBLiquidGlassProgress::SetThickness(float InValue) { Thickness = InValue; if (MyProgress.IsValid()) MyProgress->SetThickness(Thickness); }
void UCBLiquidGlassProgress::SetLinearSize(FVector2D InValue) { LinearSize = InValue; if (MyProgress.IsValid()) MyProgress->SetLinearSize(LinearSize); }
void UCBLiquidGlassProgress::SetCircularSize(FVector2D InValue) { CircularSize = InValue; if (MyProgress.IsValid()) MyProgress->SetCircularSize(CircularSize); }
void UCBLiquidGlassProgress::SetEndCapSize(float InValue) { EndCapSize = InValue; if (MyProgress.IsValid()) MyProgress->SetEndCapSize(EndCapSize); }
void UCBLiquidGlassProgress::SetTrackColor(FLinearColor InValue) { TrackColor = InValue; if (MyProgress.IsValid()) MyProgress->SetTrackColor(TrackColor); }
void UCBLiquidGlassProgress::SetTrackOpacity(float InValue) { TrackOpacity = InValue; if (MyProgress.IsValid()) MyProgress->SetTrackOpacity(TrackOpacity); }
void UCBLiquidGlassProgress::SetShowPercentText(bool bInValue) { bShowPercentText = bInValue; if (MyProgress.IsValid()) MyProgress->SetShowPercentText(bShowPercentText); }
void UCBLiquidGlassProgress::SetTextColor(FLinearColor InValue) { TextColor = InValue; if (MyProgress.IsValid()) MyProgress->SetTextColor(TextColor); }
void UCBLiquidGlassProgress::SetBlurStrength(float InValue) { BlurStrength = InValue; if (MyProgress.IsValid()) MyProgress->SetBlurStrength(BlurStrength); }
void UCBLiquidGlassProgress::SetFrostRadius(float InValue) { FrostRadius = InValue; if (MyProgress.IsValid()) MyProgress->SetFrostRadius(FrostRadius); }
void UCBLiquidGlassProgress::SetRefractionStrength(float InValue) { RefractionStrength = InValue; if (MyProgress.IsValid()) MyProgress->SetRefractionStrength(RefractionStrength); }
void UCBLiquidGlassProgress::SetPrismIntensity(float InValue) { PrismIntensity = InValue; if (MyProgress.IsValid()) MyProgress->SetPrismIntensity(PrismIntensity); }
void UCBLiquidGlassProgress::SetGlassOpacity(float InValue) { GlassOpacity = InValue; if (MyProgress.IsValid()) MyProgress->SetGlassOpacity(GlassOpacity); }
void UCBLiquidGlassProgress::SetQuality(ECBLiquidGlassQuality InValue) { Quality = InValue; if (MyProgress.IsValid()) MyProgress->SetQuality(Quality); }

void UCBLiquidGlassProgress::PushPropertiesToSlate()
{
	if (!MyProgress.IsValid()) return;
	MyProgress->SetValue(Value);
	MyProgress->SetProgressStyle(ProgressStyle);
	MyProgress->SetFillColor(FillColor);
	MyProgress->SetThickness(Thickness);
	MyProgress->SetLinearSize(LinearSize);
	MyProgress->SetCircularSize(CircularSize);
	MyProgress->SetEndCapSize(EndCapSize);
	MyProgress->SetTrackColor(TrackColor);
	MyProgress->SetTrackOpacity(TrackOpacity);
	MyProgress->SetShowPercentText(bShowPercentText);
	MyProgress->SetTextColor(TextColor);
	MyProgress->SetBlurStrength(BlurStrength);
	MyProgress->SetFrostRadius(FrostRadius);
	MyProgress->SetRefractionStrength(RefractionStrength);
	MyProgress->SetPrismIntensity(PrismIntensity);
	MyProgress->SetGlassOpacity(GlassOpacity);
	MyProgress->SetQuality(Quality);
}

UCBLiquidGlassStepper::UCBLiquidGlassStepper()
{
	bIsVariable = true;
	Value = 3.0f;
}

TSharedRef<SWidget> UCBLiquidGlassStepper::RebuildWidget()
{
	MyStepper = SNew(SCBLiquidGlassStepper)
		.Value(Value)
		.MinValue(MinValue)
		.MaxValue(MaxValue)
		.Step(Step)
		.bIntegerOnly(bIntegerOnly)
		.Style(Style)
		.OnValueChanged(FCBLiquidGlassFloatChanged::CreateUObject(this, &UCBLiquidGlassStepper::HandleValueChanged));
	return MyStepper.ToSharedRef();
}

void UCBLiquidGlassStepper::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassStepper::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyStepper.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassStepper::GetPaletteCategory() { return LiquidGlassPalette(); }
#endif

void UCBLiquidGlassStepper::SetValue(float InValue) { Value = InValue; if (MyStepper.IsValid()) { MyStepper->SetValue(Value); Value = MyStepper->GetValue(); } }
void UCBLiquidGlassStepper::SetMinValue(float InValue) { MinValue = InValue; if (MyStepper.IsValid()) { MyStepper->SetMinValue(MinValue); Value = MyStepper->GetValue(); } }
void UCBLiquidGlassStepper::SetMaxValue(float InValue) { MaxValue = InValue; if (MyStepper.IsValid()) { MyStepper->SetMaxValue(MaxValue); Value = MyStepper->GetValue(); } }
void UCBLiquidGlassStepper::SetStep(float InValue) { Step = InValue; if (MyStepper.IsValid()) MyStepper->SetStep(Step); }
void UCBLiquidGlassStepper::SetIntegerOnly(bool bInValue) { bIntegerOnly = bInValue; if (MyStepper.IsValid()) { MyStepper->SetIntegerOnly(bIntegerOnly); Value = MyStepper->GetValue(); } }
void UCBLiquidGlassStepper::SetStyle(FCBLiquidGlassControlStyle InValue) { Style = InValue; if (MyStepper.IsValid()) MyStepper->SetStyle(Style); }

void UCBLiquidGlassStepper::PushPropertiesToSlate()
{
	if (!MyStepper.IsValid()) return;
	MyStepper->SetMinValue(MinValue);
	MyStepper->SetMaxValue(MaxValue);
	MyStepper->SetStep(Step);
	MyStepper->SetIntegerOnly(bIntegerOnly);
	MyStepper->SetStyle(Style);
	MyStepper->SetValue(Value);
	MyStepper->SetOnValueChanged(FCBLiquidGlassFloatChanged::CreateUObject(this, &UCBLiquidGlassStepper::HandleValueChanged));
	Value = MyStepper->GetValue();
}

void UCBLiquidGlassStepper::HandleValueChanged(float InValue)
{
	Value = InValue;
	OnValueChanged.Broadcast(Value);
}

#undef LOCTEXT_NAMESPACE

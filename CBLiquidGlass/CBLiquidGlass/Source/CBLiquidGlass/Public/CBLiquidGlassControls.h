// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Components/Widget.h"
#include "CBLiquidGlassControls.generated.h"

class SCBLiquidGlassToggle;
class SCBLiquidGlassSegmentedControl;
class SCBLiquidGlassTabBar;
class SCBLiquidGlassToolbar;
class SCBLiquidGlassMenu;
class SCBLiquidGlassSearchBar;
class SCBLiquidGlassProgress;
class SCBLiquidGlassStepper;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCBLiquidGlassToggleChangedEvent, bool, bChecked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCBLiquidGlassIndexChangedEvent, int32, Index, int32, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCBLiquidGlassItemClickedEvent, int32, Index, int32, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCBLiquidGlassTextChangedEvent, const FText&, Text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCBLiquidGlassFloatChangedEvent, float, Value);

/** UMG  liquid glass switch. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Toggle"))
class UCBLiquidGlassToggle : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassToggle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetChecked, Setter = SetChecked, Category = "Liquid Glass Toggle")
	bool bChecked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toggle")
	FLinearColor OnColor = FLinearColor(0.0f, 0.52f, 1.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toggle")
	FLinearColor OffColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.18f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toggle")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toggle")
	FCBLiquidGlassSpringSettings SpringSettings;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Toggle|Event")
	FCBLiquidGlassToggleChangedEvent OnCheckStateChanged;

	/** Sets the checked state and moves the glass thumb to the matching side. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toggle") CBLIQUIDGLASS_API void SetChecked(bool bInValue);
	/** Sets the track tint used when the toggle is checked. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toggle") CBLIQUIDGLASS_API void SetOnColor(FLinearColor InValue);
	/** Sets the track tint used when the toggle is unchecked. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toggle") CBLIQUIDGLASS_API void SetOffColor(FLinearColor InValue);
	/** Sets the shared glass preset, quality, size and accent colour used by the toggle. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toggle") CBLIQUIDGLASS_API void SetStyle(FCBLiquidGlassControlStyle InValue);
	/** Sets the spring used by the thumb animation. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toggle") CBLIQUIDGLASS_API void SetSpringSettings(FCBLiquidGlassSpringSettings InValue);

	bool GetChecked() const { return bChecked; }
	FLinearColor GetOnColor() const { return OnColor; }
	FLinearColor GetOffColor() const { return OffColor; }
	FCBLiquidGlassControlStyle GetStyle() const { return Style; }
	FCBLiquidGlassSpringSettings GetSpringSettings() const { return SpringSettings; }

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleChanged(bool bInValue);
	TSharedPtr<SCBLiquidGlassToggle> MyToggle;
};

/** UMG multi-option selector with a sliding liquid highlight. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Segmented Control"))
class UCBLiquidGlassSegmentedControl : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassSegmentedControl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Segmented Control")
	TArray<FCBLiquidGlassItem> Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Segmented Control")
	int32 SelectedIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Segmented Control")
	ECBLiquidGlassOrientation Orientation = ECBLiquidGlassOrientation::Horizontal;

	/** Whether item icons are visible. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowIcons, Setter = SetShowIcons, Category = "Liquid Glass Segmented Control")
	bool bShowIcons = true;

	/** Whether item labels are visible. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowLabels, Setter = SetShowLabels, Category = "Liquid Glass Segmented Control")
	bool bShowLabels = true;

	/** Size of each segment cell before outer padding is applied. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Segmented Control|Layout")
	FVector2D ItemSize = FVector2D(118.0f, 42.0f);

	/** Padding between the outer glass capsule and the segment cells. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Segmented Control|Layout")
	FMargin Padding = FMargin(9.0f, 7.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Segmented Control")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Segmented Control")
	FCBLiquidGlassSpringSettings SpringSettings;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Segmented Control|Event")
	FCBLiquidGlassIndexChangedEvent OnSelectionChanged;

	/** Replaces all selectable segment items and clamps the current selection to the new range. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control") CBLIQUIDGLASS_API void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	/** Selects an item by index and animates the liquid highlight to it. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control") CBLIQUIDGLASS_API void SetSelectedIndex(int32 InValue);
	/** Sets horizontal or vertical layout for the segment list. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control") CBLIQUIDGLASS_API void SetOrientation(ECBLiquidGlassOrientation InValue);
	/** Shows or hides item icons without affecting labels. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control") CBLIQUIDGLASS_API void SetShowIcons(bool bInValue);
	/** Shows or hides item labels without affecting icons. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control") CBLIQUIDGLASS_API void SetShowLabels(bool bInValue);
	/** Sets the fixed cell size used by each segment item. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control|Layout") CBLIQUIDGLASS_API void SetItemSize(FVector2D InValue);
	/** Sets padding between the outer glass capsule and item cells. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control|Layout") CBLIQUIDGLASS_API void SetPadding(FMargin InValue);
	/** Sets the glass preset, quality, size and colour recipe. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control") CBLIQUIDGLASS_API void SetStyle(FCBLiquidGlassControlStyle InValue);
	/** Sets the spring used by the sliding selection highlight. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Segmented Control") CBLIQUIDGLASS_API void SetSpringSettings(FCBLiquidGlassSpringSettings InValue);

	const TArray<FCBLiquidGlassItem>& GetItems() const { return Items; }
	int32 GetSelectedIndex() const { return SelectedIndex; }
	ECBLiquidGlassOrientation GetOrientation() const { return Orientation; }
	bool GetShowIcons() const { return bShowIcons; }
	bool GetShowLabels() const { return bShowLabels; }
	FVector2D GetItemSize() const { return ItemSize; }
	FMargin GetPadding() const { return Padding; }
	FCBLiquidGlassControlStyle GetStyle() const { return Style; }
	FCBLiquidGlassSpringSettings GetSpringSettings() const { return SpringSettings; }

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleSelectionChanged(int32 Index, int32 Value);
	TSharedPtr<SCBLiquidGlassSegmentedControl> MyControl;
};

/** UMG icon+label tab bar with liquid selected capsule. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Tab Bar"))
class UCBLiquidGlassTabBar : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassTabBar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Tab Bar")
	TArray<FCBLiquidGlassItem> Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Tab Bar")
	int32 SelectedIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowLabels, Setter = SetShowLabels, Category = "Liquid Glass Tab Bar")
	bool bShowLabels = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowIcons, Setter = SetShowIcons, Category = "Liquid Glass Tab Bar")
	bool bShowIcons = true;

	/** Size of each tab cell. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Tab Bar|Layout")
	FVector2D ItemSize = FVector2D(96.0f, 62.0f);

	/** Padding inside the tab bar glass capsule. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Tab Bar|Layout")
	FMargin Padding = FMargin(10.0f, 8.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Tab Bar")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Tab Bar")
	FCBLiquidGlassSpringSettings SpringSettings;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Tab Bar|Event")
	FCBLiquidGlassIndexChangedEvent OnTabChanged;

	/** Replaces all tabs and clamps the current selected tab to the new range. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Tab Bar") CBLIQUIDGLASS_API void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	/** Selects a tab by index and moves the liquid capsule to it. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Tab Bar") CBLIQUIDGLASS_API void SetSelectedIndex(int32 InValue);
	/** Shows or hides tab labels. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Tab Bar") CBLIQUIDGLASS_API void SetShowLabels(bool bInValue);
	/** Shows or hides tab icons. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Tab Bar") CBLIQUIDGLASS_API void SetShowIcons(bool bInValue);
	/** Sets the fixed cell size used by each tab. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Tab Bar|Layout") CBLIQUIDGLASS_API void SetItemSize(FVector2D InValue);
	/** Sets padding between the tab cells and the outer glass capsule. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Tab Bar|Layout") CBLIQUIDGLASS_API void SetPadding(FMargin InValue);
	/** Sets the glass preset, quality, size and colour recipe. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Tab Bar") CBLIQUIDGLASS_API void SetStyle(FCBLiquidGlassControlStyle InValue);
	/** Sets the spring used by the selected-tab capsule. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Tab Bar") CBLIQUIDGLASS_API void SetSpringSettings(FCBLiquidGlassSpringSettings InValue);

	const TArray<FCBLiquidGlassItem>& GetItems() const { return Items; }
	int32 GetSelectedIndex() const { return SelectedIndex; }
	bool GetShowLabels() const { return bShowLabels; }
	bool GetShowIcons() const { return bShowIcons; }
	FVector2D GetItemSize() const { return ItemSize; }
	FMargin GetPadding() const { return Padding; }
	FCBLiquidGlassControlStyle GetStyle() const { return Style; }
	FCBLiquidGlassSpringSettings GetSpringSettings() const { return SpringSettings; }

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleTabChanged(int32 Index, int32 Value);
	TSharedPtr<SCBLiquidGlassTabBar> MyTabBar;
};

/** UMG liquid glass toolbar. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Toolbar"))
class UCBLiquidGlassToolbar : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassToolbar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toolbar")
	TArray<FCBLiquidGlassItem> Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toolbar")
	ECBLiquidGlassOrientation Orientation = ECBLiquidGlassOrientation::Horizontal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetToggleMode, Setter = SetToggleMode, Category = "Liquid Glass Toolbar")
	bool bToggleMode = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toolbar")
	int32 SelectedIndex = INDEX_NONE;

	/** Whether toolbar item icons are visible. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowIcons, Setter = SetShowIcons, Category = "Liquid Glass Toolbar")
	bool bShowIcons = true;

	/** Whether toolbar item labels are visible. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowLabels, Setter = SetShowLabels, Category = "Liquid Glass Toolbar")
	bool bShowLabels = true;

	/** Size of each toolbar item. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toolbar|Layout")
	FVector2D ItemSize = FVector2D(82.0f, 58.0f);

	/** Padding inside the toolbar glass capsule. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toolbar|Layout")
	FMargin Padding = FMargin(10.0f, 8.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Toolbar")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Toolbar|Event")
	FCBLiquidGlassItemClickedEvent OnToolClicked;

	/** Replaces toolbar actions. Disabled and separator item states are respected. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar") CBLIQUIDGLASS_API void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	/** Sets horizontal or vertical toolbar layout. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar") CBLIQUIDGLASS_API void SetOrientation(ECBLiquidGlassOrientation InValue);
	/** Enables a persistent selected item with a moving glass highlight. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar") CBLIQUIDGLASS_API void SetToggleMode(bool bInValue);
	/** Selects the active toolbar item when toggle mode is enabled. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar") CBLIQUIDGLASS_API void SetSelectedIndex(int32 InValue);
	/** Shows or hides toolbar icons. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar") CBLIQUIDGLASS_API void SetShowIcons(bool bInValue);
	/** Shows or hides toolbar labels. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar") CBLIQUIDGLASS_API void SetShowLabels(bool bInValue);
	/** Sets the fixed visual cell size for toolbar items. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar|Layout") CBLIQUIDGLASS_API void SetItemSize(FVector2D InValue);
	/** Sets padding inside the toolbar glass capsule. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar|Layout") CBLIQUIDGLASS_API void SetPadding(FMargin InValue);
	/** Sets the glass preset, quality, size and colour recipe. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Toolbar") CBLIQUIDGLASS_API void SetStyle(FCBLiquidGlassControlStyle InValue);

	const TArray<FCBLiquidGlassItem>& GetItems() const { return Items; }
	ECBLiquidGlassOrientation GetOrientation() const { return Orientation; }
	bool GetToggleMode() const { return bToggleMode; }
	int32 GetSelectedIndex() const { return SelectedIndex; }
	bool GetShowIcons() const { return bShowIcons; }
	bool GetShowLabels() const { return bShowLabels; }
	FVector2D GetItemSize() const { return ItemSize; }
	FMargin GetPadding() const { return Padding; }
	FCBLiquidGlassControlStyle GetStyle() const { return Style; }

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleToolClicked(int32 Index, int32 Value);
	TSharedPtr<SCBLiquidGlassToolbar> MyToolbar;
};

/** UMG frosted liquid glass menu. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Menu"))
class UCBLiquidGlassMenu : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassMenu();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Menu")
	TArray<FCBLiquidGlassItem> Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Menu", meta = (ClampMin = "24.0"))
	float ItemHeight = 48.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetCloseOnClick, Setter = SetCloseOnClick, Category = "Liquid Glass Menu")
	bool bCloseOnClick = true;

	/** Whether row icons are visible. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowIcons, Setter = SetShowIcons, Category = "Liquid Glass Menu")
	bool bShowIcons = true;

	/** Whether row labels are visible. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowLabels, Setter = SetShowLabels, Category = "Liquid Glass Menu")
	bool bShowLabels = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Menu")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Menu|Event")
	FCBLiquidGlassItemClickedEvent OnMenuItemClicked;

	/** Replaces menu rows, including disabled, danger and separator states. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Menu") CBLIQUIDGLASS_API void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	/** Sets the height of each non-separator row. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Menu") CBLIQUIDGLASS_API void SetItemHeight(float InValue);
	/** Collapses the menu after a row click when enabled. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Menu") CBLIQUIDGLASS_API void SetCloseOnClick(bool bInValue);
	/** Shows or hides row icons. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Menu") CBLIQUIDGLASS_API void SetShowIcons(bool bInValue);
	/** Shows or hides row labels. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Menu") CBLIQUIDGLASS_API void SetShowLabels(bool bInValue);
	/** Sets the glass preset, quality, size and colour recipe. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Menu") CBLIQUIDGLASS_API void SetStyle(FCBLiquidGlassControlStyle InValue);

	const TArray<FCBLiquidGlassItem>& GetItems() const { return Items; }
	float GetItemHeight() const { return ItemHeight; }
	bool GetCloseOnClick() const { return bCloseOnClick; }
	bool GetShowIcons() const { return bShowIcons; }
	bool GetShowLabels() const { return bShowLabels; }
	FCBLiquidGlassControlStyle GetStyle() const { return Style; }

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleMenuItemClicked(int32 Index, int32 Value);
	TSharedPtr<SCBLiquidGlassMenu> MyMenu;
};

/** UMG liquid glass search bar. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Search Bar"))
class UCBLiquidGlassSearchBar : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassSearchBar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Search Bar")
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Search Bar")
	FText HintText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowClearButton, Setter = SetShowClearButton, Category = "Liquid Glass Search Bar")
	bool bShowClearButton = true;

	/** Whether the magnifier glyph is visible. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowSearchIcon, Setter = SetShowSearchIcon, Category = "Liquid Glass Search Bar")
	bool bShowSearchIcon = true;

	/** Whether the editable text layer is visible. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowText, Setter = SetShowText, Category = "Liquid Glass Search Bar")
	bool bShowText = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Search Bar")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Search Bar")
	FCBLiquidGlassSearchBoxStyle SearchBoxStyle;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Search Bar|Event")
	FCBLiquidGlassTextChangedEvent OnTextChanged;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Search Bar|Event")
	FCBLiquidGlassTextChangedEvent OnTextCommitted;

	/** Sets the editable text without changing the hint. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Search Bar") CBLIQUIDGLASS_API void SetText(FText InText);
	/** Sets the placeholder text shown when Text is empty. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Search Bar") CBLIQUIDGLASS_API void SetHintText(FText InText);
	/** Shows or hides the circular clear button. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Search Bar") CBLIQUIDGLASS_API void SetShowClearButton(bool bInValue);
	/** Shows or hides the magnifier glyph in the inner text layer. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Search Bar") CBLIQUIDGLASS_API void SetShowSearchIcon(bool bInValue);
	/** Shows or hides the editable text box while preserving its value. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Search Bar") CBLIQUIDGLASS_API void SetShowText(bool bInValue);
	/** Sets the shared quality/preset data used by the search box glass layers. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Search Bar") CBLIQUIDGLASS_API void SetStyle(FCBLiquidGlassControlStyle InValue);
	/** Sets the two-layer search-box layout, colours and glass recipe. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Search Bar") CBLIQUIDGLASS_API void SetSearchBoxStyle(FCBLiquidGlassSearchBoxStyle InValue);

	FText GetText() const { return Text; }
	FText GetHintText() const { return HintText; }
	bool GetShowClearButton() const { return bShowClearButton; }
	bool GetShowSearchIcon() const { return bShowSearchIcon; }
	bool GetShowText() const { return bShowText; }
	FCBLiquidGlassControlStyle GetStyle() const { return Style; }
	FCBLiquidGlassSearchBoxStyle GetSearchBoxStyle() const { return SearchBoxStyle; }

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleTextChanged(const FText& InText);
	void HandleTextCommitted(const FText& InText);
	TSharedPtr<SCBLiquidGlassSearchBar> MySearchBar;
};

/** UMG linear or circular liquid glass progress. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Progress"))
class UCBLiquidGlassProgress : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassProgress();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Value = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress")
	ECBLiquidGlassProgressStyle ProgressStyle = ECBLiquidGlassProgressStyle::Linear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress")
	FLinearColor FillColor = FLinearColor(0.0f, 0.52f, 1.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress", meta = (ClampMin = "1.0"))
	float Thickness = 10.0f;

	/** Desired size for the linear capsule progress bar. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Layout")
	FVector2D LinearSize = FVector2D(560.0f, 58.0f);

	/** Desired size for the circular progress ring. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Layout")
	FVector2D CircularSize = FVector2D(154.0f, 154.0f);

	/** Diameter of the droplet cap at the end of the linear fill. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Layout", meta = (ClampMin = "0.0"))
	float EndCapSize = 52.0f;

	/** Colour of the unfilled track layer. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Style")
	FLinearColor TrackColor = FLinearColor(0.78f, 1.0f, 1.0f, 0.2f);

	/** Opacity of the unfilled track layer. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Style", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float TrackOpacity = 0.48f;

	/** Whether the numeric percentage is drawn. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetShowPercentText, Setter = SetShowPercentText, Category = "Liquid Glass Progress|Style")
	bool bShowPercentText = true;

	/** Colour used for the percentage text. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Style")
	FLinearColor TextColor = FLinearColor(0.92f, 1.0f, 1.0f, 0.96f);

	/** Glass blur used by the outer shell. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Glass", meta = (ClampMin = "0.0"))
	float BlurStrength = 0.74f;

	/** Frost amount used by the outer shell. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Glass", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float FrostRadius = 0.18f;

	/** Refraction strength used by the outer shell and end cap. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Glass", meta = (ClampMin = "0.0"))
	float RefractionStrength = 0.48f;

	/** Chromatic edge strength used by the outer shell and end cap. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Glass", meta = (ClampMin = "0.0"))
	float PrismIntensity = 0.12f;

	/** Overall opacity of the outer glass shell. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Glass", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float GlassOpacity = 0.88f;

	/** Renderer quality profile for all glass layers inside the progress widget. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Progress|Performance")
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;

	/** Sets normalized progress in the [0, 1] range. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress") CBLIQUIDGLASS_API void SetValue(float InValue);
	/** Switches between the linear capsule bar and circular ring styles. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress") CBLIQUIDGLASS_API void SetProgressStyle(ECBLiquidGlassProgressStyle InValue);
	/** Sets the filled progress colour. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress") CBLIQUIDGLASS_API void SetFillColor(FLinearColor InValue);
	/** Sets the line/ring thickness in pixels. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress") CBLIQUIDGLASS_API void SetThickness(float InValue);
	/** Sets the desired size of the linear capsule progress widget. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Layout") CBLIQUIDGLASS_API void SetLinearSize(FVector2D InValue);
	/** Sets the desired size of the circular progress widget. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Layout") CBLIQUIDGLASS_API void SetCircularSize(FVector2D InValue);
	/** Sets the droplet cap diameter at the current linear fill endpoint. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Layout") CBLIQUIDGLASS_API void SetEndCapSize(float InValue);
	/** Sets the colour of the unfilled track/ring. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Style") CBLIQUIDGLASS_API void SetTrackColor(FLinearColor InValue);
	/** Sets the opacity multiplier for the unfilled track/ring. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Style") CBLIQUIDGLASS_API void SetTrackOpacity(float InValue);
	/** Shows or hides the percentage text. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Style") CBLIQUIDGLASS_API void SetShowPercentText(bool bInValue);
	/** Sets the percentage text colour. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Style") CBLIQUIDGLASS_API void SetTextColor(FLinearColor InValue);
	/** Sets the outer glass blur amount. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Glass") CBLIQUIDGLASS_API void SetBlurStrength(float InValue);
	/** Sets the outer glass frost amount. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Glass") CBLIQUIDGLASS_API void SetFrostRadius(float InValue);
	/** Sets the outer glass refraction strength. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Glass") CBLIQUIDGLASS_API void SetRefractionStrength(float InValue);
	/** Sets the chromatic edge strength. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Glass") CBLIQUIDGLASS_API void SetPrismIntensity(float InValue);
	/** Sets the opacity of the outer glass shell. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Glass") CBLIQUIDGLASS_API void SetGlassOpacity(float InValue);
	/** Sets the renderer quality used by all glass layers inside the progress widget. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Progress|Performance") CBLIQUIDGLASS_API void SetQuality(ECBLiquidGlassQuality InValue);

	float GetValue() const { return Value; }
	ECBLiquidGlassProgressStyle GetProgressStyle() const { return ProgressStyle; }
	FLinearColor GetFillColor() const { return FillColor; }
	float GetThickness() const { return Thickness; }
	FVector2D GetLinearSize() const { return LinearSize; }
	FVector2D GetCircularSize() const { return CircularSize; }
	float GetEndCapSize() const { return EndCapSize; }
	FLinearColor GetTrackColor() const { return TrackColor; }
	float GetTrackOpacity() const { return TrackOpacity; }
	bool GetShowPercentText() const { return bShowPercentText; }
	FLinearColor GetTextColor() const { return TextColor; }
	float GetBlurStrength() const { return BlurStrength; }
	float GetFrostRadius() const { return FrostRadius; }
	float GetRefractionStrength() const { return RefractionStrength; }
	float GetPrismIntensity() const { return PrismIntensity; }
	float GetGlassOpacity() const { return GlassOpacity; }
	ECBLiquidGlassQuality GetQuality() const { return Quality; }

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	TSharedPtr<SCBLiquidGlassProgress> MyProgress;
};

/** UMG liquid glass numeric stepper. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Stepper"))
class UCBLiquidGlassStepper : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassStepper();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Stepper")
	float Value = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Stepper")
	float MinValue = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Stepper")
	float MaxValue = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Stepper", meta = (ClampMin = "0.0001"))
	float Step = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter = GetIntegerOnly, Setter = SetIntegerOnly, Category = "Liquid Glass Stepper")
	bool bIntegerOnly = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Stepper")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Stepper|Event")
	FCBLiquidGlassFloatChangedEvent OnValueChanged;

	/** Sets the current numeric value and clamps it to MinValue/MaxValue. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Stepper") CBLIQUIDGLASS_API void SetValue(float InValue);
	/** Sets the lower bound and re-clamps the current value. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Stepper") CBLIQUIDGLASS_API void SetMinValue(float InValue);
	/** Sets the upper bound and re-clamps the current value. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Stepper") CBLIQUIDGLASS_API void SetMaxValue(float InValue);
	/** Sets how much the minus/plus buttons change the value per click. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Stepper") CBLIQUIDGLASS_API void SetStep(float InValue);
	/** Rounds displayed and committed values to whole numbers when enabled. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Stepper") CBLIQUIDGLASS_API void SetIntegerOnly(bool bInValue);
	/** Sets the glass preset, quality, size and colour recipe. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Stepper") CBLIQUIDGLASS_API void SetStyle(FCBLiquidGlassControlStyle InValue);

	float GetValue() const { return Value; }
	float GetMinValue() const { return MinValue; }
	float GetMaxValue() const { return MaxValue; }
	float GetStep() const { return Step; }
	bool GetIntegerOnly() const { return bIntegerOnly; }
	FCBLiquidGlassControlStyle GetStyle() const { return Style; }

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleValueChanged(float InValue);
	TSharedPtr<SCBLiquidGlassStepper> MyStepper;
};

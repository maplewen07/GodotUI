// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class SCBLiquidGlass;
class SCBLiquidGlassSlider;
class SCanvas;
class SEditableText;

DECLARE_DELEGATE_OneParam(FCBLiquidGlassCheckChanged, bool);
DECLARE_DELEGATE_TwoParams(FCBLiquidGlassIndexChanged, int32, int32);
DECLARE_DELEGATE_TwoParams(FCBLiquidGlassItemClicked, int32, int32);
DECLARE_DELEGATE_OneParam(FCBLiquidGlassTextChanged, const FText&);
DECLARE_DELEGATE_OneParam(FCBLiquidGlassTextCommitted, const FText&);
DECLARE_DELEGATE_OneParam(FCBLiquidGlassFloatChanged, float);

/**  liquid glass switch with a spring-driven droplet thumb. */
class CBLIQUIDGLASS_API SCBLiquidGlassToggle : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassToggle)
		: _Checked(false)
		, _OnColor(FLinearColor(0.0f, 0.52f, 1.0f, 1.0f))
		, _OffColor(FLinearColor(1.0f, 1.0f, 1.0f, 0.18f))
		, _Style()
		, _Spring()
	{}
		SLATE_ARGUMENT(bool, Checked)
		SLATE_ARGUMENT(FLinearColor, OnColor)
		SLATE_ARGUMENT(FLinearColor, OffColor)
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		SLATE_ARGUMENT(FCBLiquidGlassSpringSettings, Spring)
		SLATE_EVENT(FCBLiquidGlassCheckChanged, OnCheckStateChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetChecked(bool bInChecked);
	void SetOnColor(FLinearColor InValue);
	void SetOffColor(FLinearColor InValue);
	void SetStyle(const FCBLiquidGlassControlStyle& InValue);
	void SetSpringSettings(const FCBLiquidGlassSpringSettings& InValue);
	void SetOnCheckStateChanged(FCBLiquidGlassCheckChanged InDelegate);
	bool IsChecked() const { return bChecked; }

	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual bool IsInteractable() const override { return IsEnabled(); }

private:
	void Rebuild();
	void ApplyVisuals();
	FVector2D GetThumbPosition() const;
	FVector2D GetThumbSize() const;

	TSharedPtr<SCBLiquidGlass> TrackGlass;
	TSharedPtr<SCBLiquidGlass> ThumbGlass;
	TSharedPtr<SCanvas> Canvas;
	FCBLiquidGlassCheckChanged OnCheckStateChanged;
	FCBLiquidGlassControlStyle Style;
	FCBLiquidGlassSpringSettings Spring;
	FLinearColor OnColor;
	FLinearColor OffColor;
	bool bChecked = false;
	float VisualAlpha = 0.0f;
	float VisualVelocity = 0.0f;
};

/** Multi-option selector with a moving glass highlight. Used by segmented controls and tab bars. */
class CBLIQUIDGLASS_API SCBLiquidGlassItemSelector : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassItemSelector)
		: _SelectedIndex(0)
		, _Orientation(ECBLiquidGlassOrientation::Horizontal)
		, _IconPosition(ECBLiquidGlassIconPosition::Top)
		, _Style()
		, _Spring()
		, _ItemSize(FVector2D(108.0f, 68.0f))
		, _Padding(FMargin(12.0f, 8.0f))
		, _bShowIcons(true)
		, _bShowLabels(true)
		, _bUseGlassBackground(true)
	{}
		SLATE_ARGUMENT(TArray<FCBLiquidGlassItem>, Items)
		SLATE_ARGUMENT(int32, SelectedIndex)
		SLATE_ARGUMENT(ECBLiquidGlassOrientation, Orientation)
		SLATE_ARGUMENT(ECBLiquidGlassIconPosition, IconPosition)
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		SLATE_ARGUMENT(FCBLiquidGlassSpringSettings, Spring)
		SLATE_ARGUMENT(FVector2D, ItemSize)
		SLATE_ARGUMENT(FMargin, Padding)
		SLATE_ARGUMENT(bool, bShowIcons)
		SLATE_ARGUMENT(bool, bShowLabels)
		SLATE_ARGUMENT(bool, bUseGlassBackground)
		SLATE_EVENT(FCBLiquidGlassIndexChanged, OnSelectionChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	void SetSelectedIndex(int32 InValue);
	void SetOrientation(ECBLiquidGlassOrientation InValue);
	void SetIconPosition(ECBLiquidGlassIconPosition InValue);
	void SetStyle(const FCBLiquidGlassControlStyle& InValue);
	void SetSpringSettings(const FCBLiquidGlassSpringSettings& InValue);
	void SetItemSize(FVector2D InValue);
	void SetPadding(FMargin InValue);
	void SetShowIcons(bool bInValue);
	void SetShowLabels(bool bInValue);
	void SetOnSelectionChanged(FCBLiquidGlassIndexChanged InDelegate);
	int32 GetSelectedIndex() const { return SelectedIndex; }

	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

private:
	void Rebuild();
	void SelectIndex(int32 InIndex);
	TSharedRef<SWidget> BuildItem(int32 Index);
	FVector2D GetHighlightPosition() const;
	FVector2D GetHighlightSize() const;
	float GetTargetOffset() const;
	float GetItemStride() const;

	TSharedPtr<SCanvas> HighlightCanvas;
	TArray<FCBLiquidGlassItem> Items;
	FCBLiquidGlassIndexChanged OnSelectionChanged;
	ECBLiquidGlassOrientation Orientation = ECBLiquidGlassOrientation::Horizontal;
	ECBLiquidGlassIconPosition IconPosition = ECBLiquidGlassIconPosition::Top;
	FCBLiquidGlassControlStyle Style;
	FCBLiquidGlassSpringSettings Spring;
	FVector2D ItemSize = FVector2D(108.0f, 68.0f);
	FMargin Padding = FMargin(12.0f, 8.0f);
	bool bShowIcons = true;
	bool bShowLabels = true;
	int32 SelectedIndex = 0;
	float VisualOffset = 0.0f;
	float VisualVelocity = 0.0f;
	bool bUseGlassBackground = true;
};

/** Convenience segmented control wrapper around SCBLiquidGlassItemSelector. */
class CBLIQUIDGLASS_API SCBLiquidGlassSegmentedControl : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassSegmentedControl)
		: _SelectedIndex(0), _Orientation(ECBLiquidGlassOrientation::Horizontal), _Style(), _Spring(), _bShowIcons(true), _bShowLabels(true), _ItemSize(FVector2D(118.0f, 42.0f)), _Padding(FMargin(9.0f, 7.0f))
	{}
		SLATE_ARGUMENT(TArray<FCBLiquidGlassItem>, Items)
		SLATE_ARGUMENT(int32, SelectedIndex)
		SLATE_ARGUMENT(ECBLiquidGlassOrientation, Orientation)
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		SLATE_ARGUMENT(FCBLiquidGlassSpringSettings, Spring)
		SLATE_ARGUMENT(bool, bShowIcons)
		SLATE_ARGUMENT(bool, bShowLabels)
		SLATE_ARGUMENT(FVector2D, ItemSize)
		SLATE_ARGUMENT(FMargin, Padding)
		SLATE_EVENT(FCBLiquidGlassIndexChanged, OnSelectionChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	void SetSelectedIndex(int32 InValue);
	void SetOrientation(ECBLiquidGlassOrientation InValue);
	void SetStyle(const FCBLiquidGlassControlStyle& InValue);
	void SetSpringSettings(const FCBLiquidGlassSpringSettings& InValue);
	void SetShowIcons(bool bInValue);
	void SetShowLabels(bool bInValue);
	void SetItemSize(FVector2D InValue);
	void SetPadding(FMargin InValue);
	void SetOnSelectionChanged(FCBLiquidGlassIndexChanged InDelegate);

private:
	TSharedPtr<SCBLiquidGlassItemSelector> Selector;
};

/** Icon + label navigation bar with a moving liquid glass highlight. */
class CBLIQUIDGLASS_API SCBLiquidGlassTabBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassTabBar)
		: _SelectedIndex(0), _Style(), _Spring(), _bShowLabels(true), _bShowIcons(true), _ItemSize(FVector2D(96.0f, 62.0f)), _Padding(FMargin(10.0f, 8.0f))
	{}
		SLATE_ARGUMENT(TArray<FCBLiquidGlassItem>, Items)
		SLATE_ARGUMENT(int32, SelectedIndex)
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		SLATE_ARGUMENT(FCBLiquidGlassSpringSettings, Spring)
		SLATE_ARGUMENT(bool, bShowLabels)
		SLATE_ARGUMENT(bool, bShowIcons)
		SLATE_ARGUMENT(FVector2D, ItemSize)
		SLATE_ARGUMENT(FMargin, Padding)
		SLATE_EVENT(FCBLiquidGlassIndexChanged, OnTabChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	void SetSelectedIndex(int32 InValue);
	void SetShowLabels(bool bInValue);
	void SetShowIcons(bool bInValue);
	void SetItemSize(FVector2D InValue);
	void SetPadding(FMargin InValue);
	void SetStyle(const FCBLiquidGlassControlStyle& InValue);
	void SetSpringSettings(const FCBLiquidGlassSpringSettings& InValue);
	void SetOnTabChanged(FCBLiquidGlassIndexChanged InDelegate);

private:
	TSharedPtr<SCBLiquidGlassItemSelector> Selector;
};

/** Glass toolbar made of clickable icon/text items. */
class CBLIQUIDGLASS_API SCBLiquidGlassToolbar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassToolbar)
		: _Orientation(ECBLiquidGlassOrientation::Horizontal), _Style(), _bToggleMode(false), _SelectedIndex(INDEX_NONE), _bShowIcons(true), _bShowLabels(true), _ItemSize(FVector2D(82.0f, 58.0f)), _Padding(FMargin(10.0f, 8.0f))
	{}
		SLATE_ARGUMENT(TArray<FCBLiquidGlassItem>, Items)
		SLATE_ARGUMENT(ECBLiquidGlassOrientation, Orientation)
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		SLATE_ARGUMENT(bool, bToggleMode)
		SLATE_ARGUMENT(int32, SelectedIndex)
		SLATE_ARGUMENT(bool, bShowIcons)
		SLATE_ARGUMENT(bool, bShowLabels)
		SLATE_ARGUMENT(FVector2D, ItemSize)
		SLATE_ARGUMENT(FMargin, Padding)
		SLATE_EVENT(FCBLiquidGlassItemClicked, OnToolClicked)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	void SetOrientation(ECBLiquidGlassOrientation InValue);
	void SetStyle(const FCBLiquidGlassControlStyle& InValue);
	void SetToggleMode(bool bInValue);
	void SetSelectedIndex(int32 InValue);
	void SetShowIcons(bool bInValue);
	void SetShowLabels(bool bInValue);
	void SetItemSize(FVector2D InValue);
	void SetPadding(FMargin InValue);
	void SetOnToolClicked(FCBLiquidGlassItemClicked InDelegate);

private:
	void Rebuild();
	TSharedRef<SWidget> BuildTool(int32 Index);
	void ClickTool(int32 Index);

	TArray<FCBLiquidGlassItem> Items;
	ECBLiquidGlassOrientation Orientation = ECBLiquidGlassOrientation::Horizontal;
	FCBLiquidGlassControlStyle Style;
	FCBLiquidGlassItemClicked OnToolClicked;
	FVector2D ItemSize = FVector2D(82.0f, 58.0f);
	FMargin Padding = FMargin(10.0f, 8.0f);
	bool bShowIcons = true;
	bool bShowLabels = true;
	bool bToggleMode = false;
	int32 SelectedIndex = INDEX_NONE;
};

/** Frosted menu surface with item rows, separators, disabled and danger states. */
class CBLIQUIDGLASS_API SCBLiquidGlassMenu : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassMenu)
		: _ItemHeight(48.0f), _bCloseOnClick(true), _bShowIcons(true), _bShowLabels(true), _Style()
	{}
		SLATE_ARGUMENT(TArray<FCBLiquidGlassItem>, Items)
		SLATE_ARGUMENT(float, ItemHeight)
		SLATE_ARGUMENT(bool, bCloseOnClick)
		SLATE_ARGUMENT(bool, bShowIcons)
		SLATE_ARGUMENT(bool, bShowLabels)
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		SLATE_EVENT(FCBLiquidGlassItemClicked, OnMenuItemClicked)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetItems(const TArray<FCBLiquidGlassItem>& InItems);
	void SetItemHeight(float InValue);
	void SetCloseOnClick(bool bInValue);
	void SetStyle(const FCBLiquidGlassControlStyle& InValue);
	void SetShowIcons(bool bInValue);
	void SetShowLabels(bool bInValue);
	void SetOnMenuItemClicked(FCBLiquidGlassItemClicked InDelegate);

private:
	void Rebuild();
	TSharedRef<SWidget> BuildMenuRow(int32 Index);

	TArray<FCBLiquidGlassItem> Items;
	FCBLiquidGlassControlStyle Style;
	FCBLiquidGlassItemClicked OnMenuItemClicked;
	float ItemHeight = 48.0f;
	bool bCloseOnClick = true;
	bool bShowIcons = true;
	bool bShowLabels = true;
};

/** Liquid glass search field with a compact magnifier glyph, editable text and a clear button. */
class CBLIQUIDGLASS_API SCBLiquidGlassSearchBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassSearchBar)
		: _Text(FText::GetEmpty()), _HintText(NSLOCTEXT("CBLiquidGlass", "SearchHint", "Search")), _bShowClearButton(true), _bShowSearchIcon(true), _bShowText(true), _Style(), _SearchBoxStyle()
	{}
		SLATE_ARGUMENT(FText, Text)
		SLATE_ARGUMENT(FText, HintText)
		SLATE_ARGUMENT(bool, bShowClearButton)
		SLATE_ARGUMENT(bool, bShowSearchIcon)
		SLATE_ARGUMENT(bool, bShowText)
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		SLATE_ARGUMENT(FCBLiquidGlassSearchBoxStyle, SearchBoxStyle)
		SLATE_EVENT(FCBLiquidGlassTextChanged, OnTextChanged)
		SLATE_EVENT(FCBLiquidGlassTextCommitted, OnTextCommitted)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetText(const FText& InText);
	void SetHintText(const FText& InText);
	void SetShowClearButton(bool bInValue);
	void SetShowSearchIcon(bool bInValue);
	void SetShowText(bool bInValue);
	void SetStyle(const FCBLiquidGlassControlStyle& InValue);
	void SetSearchBoxStyle(const FCBLiquidGlassSearchBoxStyle& InValue);
	void SetOnTextChanged(FCBLiquidGlassTextChanged InDelegate);
	void SetOnTextCommitted(FCBLiquidGlassTextCommitted InDelegate);

private:
	void Rebuild();
	void HandleTextChanged(const FText& InText);
	void HandleTextCommitted(const FText& InText, ETextCommit::Type CommitType);

	TSharedPtr<SEditableText> TextBox;
	FText Text;
	FText HintText;
	FCBLiquidGlassControlStyle Style;
	FCBLiquidGlassSearchBoxStyle SearchBoxStyle;
	FCBLiquidGlassTextChanged OnTextChanged;
	FCBLiquidGlassTextCommitted OnTextCommitted;
	bool bShowClearButton = true;
	bool bShowSearchIcon = true;
	bool bShowText = true;
};

/** Liquid glass progress control. Supports linear bar and circular ring styles. */
class CBLIQUIDGLASS_API SCBLiquidGlassProgress : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassProgress)
		: _Value(0.5f)
		, _ProgressStyle(ECBLiquidGlassProgressStyle::Linear)
		, _FillColor(FLinearColor(0.0f, 0.52f, 1.0f, 1.0f))
		, _Thickness(10.0f)
		, _LinearSize(FVector2D(560.0f, 58.0f))
		, _CircularSize(FVector2D(154.0f, 154.0f))
		, _EndCapSize(52.0f)
		, _TrackColor(FLinearColor(0.78f, 1.0f, 1.0f, 0.2f))
		, _TrackOpacity(0.48f)
		, _bShowPercentText(true)
		, _TextColor(FLinearColor(0.92f, 1.0f, 1.0f, 0.96f))
		, _BlurStrength(0.74f)
		, _FrostRadius(0.18f)
		, _RefractionStrength(0.48f)
		, _PrismIntensity(0.12f)
		, _GlassOpacity(0.88f)
		, _Quality(ECBLiquidGlassQuality::Balanced)
	{}
		SLATE_ARGUMENT(float, Value)
		SLATE_ARGUMENT(ECBLiquidGlassProgressStyle, ProgressStyle)
		SLATE_ARGUMENT(FLinearColor, FillColor)
		SLATE_ARGUMENT(float, Thickness)
		SLATE_ARGUMENT(FVector2D, LinearSize)
		SLATE_ARGUMENT(FVector2D, CircularSize)
		SLATE_ARGUMENT(float, EndCapSize)
		SLATE_ARGUMENT(FLinearColor, TrackColor)
		SLATE_ARGUMENT(float, TrackOpacity)
		SLATE_ARGUMENT(bool, bShowPercentText)
		SLATE_ARGUMENT(FLinearColor, TextColor)
		SLATE_ARGUMENT(float, BlurStrength)
		SLATE_ARGUMENT(float, FrostRadius)
		SLATE_ARGUMENT(float, RefractionStrength)
		SLATE_ARGUMENT(float, PrismIntensity)
		SLATE_ARGUMENT(float, GlassOpacity)
		SLATE_ARGUMENT(ECBLiquidGlassQuality, Quality)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetValue(float InValue);
	void SetProgressStyle(ECBLiquidGlassProgressStyle InValue);
	void SetFillColor(FLinearColor InValue);
	void SetThickness(float InValue);
	void SetLinearSize(FVector2D InValue);
	void SetCircularSize(FVector2D InValue);
	void SetEndCapSize(float InValue);
	void SetTrackColor(FLinearColor InValue);
	void SetTrackOpacity(float InValue);
	void SetShowPercentText(bool bInValue);
	void SetTextColor(FLinearColor InValue);
	void SetBlurStrength(float InValue);
	void SetFrostRadius(float InValue);
	void SetRefractionStrength(float InValue);
	void SetPrismIntensity(float InValue);
	void SetGlassOpacity(float InValue);
	void SetQuality(ECBLiquidGlassQuality InValue);

private:
	void Rebuild();
	FVector2D GetLinearFillSize() const;

	TSharedPtr<SCBLiquidGlass> LinearFill;
	float Value = 0.5f;
	ECBLiquidGlassProgressStyle ProgressStyle = ECBLiquidGlassProgressStyle::Linear;
	FLinearColor FillColor = FLinearColor(0.0f, 0.52f, 1.0f, 1.0f);
	float Thickness = 10.0f;
	FVector2D LinearSize = FVector2D(560.0f, 58.0f);
	FVector2D CircularSize = FVector2D(154.0f, 154.0f);
	float EndCapSize = 52.0f;
	FLinearColor TrackColor = FLinearColor(0.78f, 1.0f, 1.0f, 0.2f);
	float TrackOpacity = 0.48f;
	bool bShowPercentText = true;
	FLinearColor TextColor = FLinearColor(0.92f, 1.0f, 1.0f, 0.96f);
	float BlurStrength = 0.74f;
	float FrostRadius = 0.18f;
	float RefractionStrength = 0.48f;
	float PrismIntensity = 0.12f;
	float GlassOpacity = 0.88f;
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;
};

/** Minus/value/plus liquid glass numeric stepper. */
class CBLIQUIDGLASS_API SCBLiquidGlassStepper : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassStepper)
		: _Value(0.0f), _MinValue(0.0f), _MaxValue(10.0f), _Step(1.0f), _bIntegerOnly(true), _Style()
	{}
		SLATE_ARGUMENT(float, Value)
		SLATE_ARGUMENT(float, MinValue)
		SLATE_ARGUMENT(float, MaxValue)
		SLATE_ARGUMENT(float, Step)
		SLATE_ARGUMENT(bool, bIntegerOnly)
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		SLATE_EVENT(FCBLiquidGlassFloatChanged, OnValueChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetValue(float InValue);
	void SetMinValue(float InValue);
	void SetMaxValue(float InValue);
	void SetStep(float InValue);
	void SetIntegerOnly(bool bInValue);
	void SetStyle(const FCBLiquidGlassControlStyle& InValue);
	void SetOnValueChanged(FCBLiquidGlassFloatChanged InDelegate);
	float GetValue() const { return Value; }

private:
	void Rebuild();
	void CommitValue(float InValue);
	FText GetValueText() const;

	float Value = 0.0f;
	float MinValue = 0.0f;
	float MaxValue = 10.0f;
	float Step = 1.0f;
	bool bIntegerOnly = true;
	FCBLiquidGlassControlStyle Style;
	FCBLiquidGlassFloatChanged OnValueChanged;
};

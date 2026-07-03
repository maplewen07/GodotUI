// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "UObject/StrongObjectPtr.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SLeafWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class SCBLiquidGlass;
class STextBlock;
class UTexture2D;

DECLARE_DELEGATE_OneParam(FCBLiquidGlassPageChanged, int32 /*PageIndex*/);
DECLARE_DELEGATE_TwoParams(FCBLiquidGlassDialogButtonClicked, int32 /*Index*/, int32 /*Value*/);
DECLARE_DELEGATE_TwoParams(FCBLiquidGlassNavItemClicked, int32 /*Index*/, int32 /*Value*/);

/**
 * Small count/notification badge, like the red bubble UIKit puts on tab and app icons.
 * Renders a glass capsule (or a plain dot in dot mode) with an optional clamped count.
 */
class CBLIQUIDGLASS_API SCBLiquidGlassBadge : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassBadge)
		: _Count(1)
		, _MaxCount(99)
		, _bDotMode(false)
		, _Color(FLinearColor(1.0f, 0.23f, 0.19f, 1.0f))
	{}
		/** Number shown in the badge; values <= 0 hide the badge unless in dot mode. */
		SLATE_ARGUMENT(int32, Count)
		/** Counts above this render as "MaxCount+". */
		SLATE_ARGUMENT(int32, MaxCount)
		/** When true, draws a small dot with no number. */
		SLATE_ARGUMENT(bool, bDotMode)
		/** Badge fill colour ( uses system red). */
		SLATE_ARGUMENT(FLinearColor, Color)
		/** Quality profile for the badge glass. */
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Sets the displayed count and rebuilds (negative or zero collapses the badge in count mode). */
	void SetCount(int32 InCount);
	/** Sets the "+"-overflow threshold. */
	void SetMaxCount(int32 InMaxCount);
	/** Toggles between numbered capsule and plain dot. */
	void SetDotMode(bool bInDotMode);
	/** Sets the badge fill colour. */
	void SetColor(FLinearColor InColor);
	/** Sets the shared control style (quality). */
	void SetStyle(const FCBLiquidGlassControlStyle& InStyle);

private:
	void Rebuild();
	FText GetCountText() const;

	int32 Count = 1;
	int32 MaxCount = 99;
	bool bDotMode = false;
	FLinearColor Color = FLinearColor(1.0f, 0.23f, 0.19f, 1.0f);
	FCBLiquidGlassControlStyle Style;
	TSharedPtr<SCBLiquidGlass> Glass;
};

/**
 *  page indicator: a row of dots with a spring-driven elongated pill on the current page.
 * Dots are painted directly (UIPageControl dots are solid, not glass) for a cheap, crisp indicator.
 */
class CBLIQUIDGLASS_API SCBLiquidGlassPageControl : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassPageControl)
		: _NumPages(3)
		, _CurrentPage(0)
		, _DotSize(10.0f)
		, _DotSpacing(10.0f)
		, _ActiveColor(FLinearColor(1.0f, 1.0f, 1.0f, 0.95f))
		, _InactiveColor(FLinearColor(1.0f, 1.0f, 1.0f, 0.35f))
	{}
		/** Total number of pages (dots). */
		SLATE_ARGUMENT(int32, NumPages)
		/** Active page index. */
		SLATE_ARGUMENT(int32, CurrentPage)
		/** Diameter of each dot in pixels. */
		SLATE_ARGUMENT(float, DotSize)
		/** Gap between dots in pixels. */
		SLATE_ARGUMENT(float, DotSpacing)
		/** Colour of the active page pill. */
		SLATE_ARGUMENT(FLinearColor, ActiveColor)
		/** Colour of the inactive dots. */
		SLATE_ARGUMENT(FLinearColor, InactiveColor)
		/** Spring tuning for the active pill sliding between pages. */
		SLATE_ARGUMENT(FCBLiquidGlassSpringSettings, Spring)
		/** Fired with the new page index when a dot is clicked. */
		SLATE_EVENT(FCBLiquidGlassPageChanged, OnPageChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Sets the page count and re-clamps the current page. */
	void SetNumPages(int32 InNumPages);
	/** Sets the active page; the pill springs toward it. */
	void SetCurrentPage(int32 InCurrentPage);
	/** Sets dot diameter (px). */
	void SetDotSize(float InDotSize);
	/** Sets dot spacing (px). */
	void SetDotSpacing(float InDotSpacing);
	/** Sets the active pill colour. */
	void SetActiveColor(FLinearColor InColor);
	/** Sets the inactive dot colour. */
	void SetInactiveColor(FLinearColor InColor);
	/** Sets the pill spring tuning. */
	void SetSpring(const FCBLiquidGlassSpringSettings& InSpring);
	/** Replaces the page-changed handler. */
	void SetOnPageChanged(FCBLiquidGlassPageChanged InDelegate);

	//~ Begin SWidget interface
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//~ End SWidget interface

private:
	float GetStride() const;

	int32 NumPages = 3;
	int32 CurrentPage = 0;
	float DotSize = 10.0f;
	float DotSpacing = 10.0f;
	FLinearColor ActiveColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.95f);
	FLinearColor InactiveColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.35f);
	FCBLiquidGlassSpringSettings Spring;
	FCBLiquidGlassPageChanged OnPageChanged;

	float VisualPage = 0.0f;
	float VisualVelocity = 0.0f;
};

/** Glass top bar with an optional back button, centered title and trailing icon/text actions. */
class CBLIQUIDGLASS_API SCBLiquidGlassNavigationBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassNavigationBar)
		: _Title(FText::FromString(TEXT("Title")))
		, _bShowBackButton(true)
		, _bLargeTitle(false)
	{}
		/** Bar title. */
		SLATE_ARGUMENT(FText, Title)
		/** Whether the leading back chevron is shown. */
		SLATE_ARGUMENT(bool, bShowBackButton)
		/** Large-title mode (bigger, left-aligned title) vs. inline centered title. */
		SLATE_ARGUMENT(bool, bLargeTitle)
		/** Trailing action items drawn on the right. */
		SLATE_ARGUMENT(TArray<FCBLiquidGlassItem>, TrailingItems)
		/** Shared control style (preset/quality/accent). */
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		/** Fired when the back chevron is clicked. */
		SLATE_EVENT(FSimpleDelegate, OnBackClicked)
		/** Fired with (index, value) when a trailing item is clicked. */
		SLATE_EVENT(FCBLiquidGlassNavItemClicked, OnTrailingItemClicked)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Sets the title text. */
	void SetTitle(const FText& InTitle);
	/** Shows or hides the back chevron. */
	void SetShowBackButton(bool bInValue);
	/** Toggles large-title layout. */
	void SetLargeTitle(bool bInValue);
	/** Replaces the trailing action items. */
	void SetTrailingItems(const TArray<FCBLiquidGlassItem>& InItems);
	/** Sets the shared control style. */
	void SetStyle(const FCBLiquidGlassControlStyle& InStyle);
	/** Replaces the back handler. */
	void SetOnBackClicked(FSimpleDelegate InDelegate);
	/** Replaces the trailing-item handler. */
	void SetOnTrailingItemClicked(FCBLiquidGlassNavItemClicked InDelegate);

private:
	void Rebuild();

	FText Title;
	bool bShowBackButton = true;
	bool bLargeTitle = false;
	TArray<FCBLiquidGlassItem> TrailingItems;
	FCBLiquidGlassControlStyle Style;
	FSimpleDelegate OnBackClicked;
	FCBLiquidGlassNavItemClicked OnTrailingItemClicked;
};

/**
 * Modal glass dialog overlay: a dimmed backdrop plus a frosted glass card with a title, message
 * and button row. Present()/Dismiss() animate a spring-driven fade + scale entrance.
 */
class CBLIQUIDGLASS_API SCBLiquidGlassDialog : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassDialog)
		: _Title(FText::FromString(TEXT("Title")))
		, _Message(FText::GetEmpty())
		, _DialogStyle(ECBLiquidGlassDialogStyle::Alert)
		, _bDimBackground(true)
		, _bStartPresented(false)
		, _DimOpacity(0.28f)
		, _CardBlurStrength(1.1f)
		, _CardFrostRadius(0.42f)
		, _CardRefractionStrength(0.72f)
		, _CardRefractionThickness(34.0f)
		, _CardPrismIntensity(0.2f)
		, _CardRimIntensity(0.36f)
		, _CardGlassOpacity(0.94f)
	{}
		/** Dialog heading. */
		SLATE_ARGUMENT(FText, Title)
		/** Body message. */
		SLATE_ARGUMENT(FText, Message)
		/** Action buttons (separator items render as cancel-style). */
		SLATE_ARGUMENT(TArray<FCBLiquidGlassItem>, Buttons)
		/** Alert / action sheet / sheet placement. */
		SLATE_ARGUMENT(ECBLiquidGlassDialogStyle, DialogStyle)
		/** Whether to dim the area behind the card. */
		SLATE_ARGUMENT(bool, bDimBackground)
		/** Whether the dialog starts already presented. */
		SLATE_ARGUMENT(bool, bStartPresented)
		/** Strength of the modal dim layer when bDimBackground is true. */
		SLATE_ARGUMENT(float, DimOpacity)
		/** Card background blur amount. */
		SLATE_ARGUMENT(float, CardBlurStrength)
		/** Card frost/blur blend amount. */
		SLATE_ARGUMENT(float, CardFrostRadius)
		/** Card lensing amount. */
		SLATE_ARGUMENT(float, CardRefractionStrength)
		/** Card refractive rim thickness. */
		SLATE_ARGUMENT(float, CardRefractionThickness)
		/** Card edge colour separation. */
		SLATE_ARGUMENT(float, CardPrismIntensity)
		/** Card rim highlight intensity. */
		SLATE_ARGUMENT(float, CardRimIntensity)
		/** Card composite opacity. */
		SLATE_ARGUMENT(float, CardGlassOpacity)
		/** Shared control style (quality). */
		SLATE_ARGUMENT(FCBLiquidGlassControlStyle, Style)
		/** Spring tuning for the entrance/exit animation. */
		SLATE_ARGUMENT(FCBLiquidGlassSpringSettings, Spring)
		/** Fired with (index, value) when a button is clicked. */
		SLATE_EVENT(FCBLiquidGlassDialogButtonClicked, OnButtonClicked)
		/** Fired once the dialog finishes dismissing. */
		SLATE_EVENT(FSimpleDelegate, OnDismissed)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Animates the dialog in. */
	void Present();
	/** Animates the dialog out, then collapses and fires OnDismissed. */
	void Dismiss();
	/** True while presented or animating in. */
	bool IsPresented() const { return bPresented; }

	void SetTitle(const FText& InTitle);
	void SetMessage(const FText& InMessage);
	void SetButtons(const TArray<FCBLiquidGlassItem>& InButtons);
	void SetDialogStyle(ECBLiquidGlassDialogStyle InStyle);
	void SetDimBackground(bool bInValue);
	void SetDimOpacity(float InValue);
	void SetCardBlurStrength(float InValue);
	void SetCardFrostRadius(float InValue);
	void SetCardRefractionStrength(float InValue);
	void SetCardRefractionThickness(float InValue);
	void SetCardPrismIntensity(float InValue);
	void SetCardRimIntensity(float InValue);
	void SetCardGlassOpacity(float InValue);
	void SetSpring(const FCBLiquidGlassSpringSettings& InSpring);
	void SetStyle(const FCBLiquidGlassControlStyle& InStyle);
	void SetOnButtonClicked(FCBLiquidGlassDialogButtonClicked InDelegate);
	void SetOnDismissed(FSimpleDelegate InDelegate);

	//~ Begin SWidget interface
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual bool SupportsKeyboardFocus() const override { return true; }
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//~ End SWidget interface

private:
	void Rebuild();
	void HandleButton(int32 Index, int32 Value);

	FText Title;
	FText Message;
	TArray<FCBLiquidGlassItem> Buttons;
	ECBLiquidGlassDialogStyle DialogStyle = ECBLiquidGlassDialogStyle::Alert;
	bool bDimBackground = true;
	float DimOpacity = 0.28f;
	float CardBlurStrength = 1.1f;
	float CardFrostRadius = 0.42f;
	float CardRefractionStrength = 0.72f;
	float CardRefractionThickness = 34.0f;
	float CardPrismIntensity = 0.2f;
	float CardRimIntensity = 0.36f;
	float CardGlassOpacity = 0.94f;
	FCBLiquidGlassControlStyle Style;
	FCBLiquidGlassSpringSettings Spring;
	FCBLiquidGlassDialogButtonClicked OnButtonClicked;
	FSimpleDelegate OnDismissed;

	bool bPresented = false;
	float VisualAlpha = 0.0f;
	float VisualVelocity = 0.0f;
	TSharedPtr<class SWidget> Root;
	TSharedPtr<class SBox> CardScaleBox;
};

/**
 * Liquid Glass fusion container (Apple's GlassEffectContainer): renders a single glass panel whose
 * silhouette is the smooth-union of several rounded blobs, so nearby shapes melt together. The
 * merged mask is rasterized to a transient texture and fed through SCBLiquidGlass' alpha-mask path.
 */
class CBLIQUIDGLASS_API SCBLiquidGlassContainer : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassContainer)
		: _Smoothing(40.0f)
		, _CanvasSize(FVector2D(360.0f, 160.0f))
		, _MaskResolution(FVector2D::ZeroVector)
		, _BlurStrength(1.05f)
		, _FrostRadius(0.24f)
		, _RefractionStrength(0.92f)
		, _RefractionThickness(48.0f)
		, _PrismIntensity(0.34f)
		, _RimIntensity(0.56f)
		, _GlassOpacity(1.0f)
		, _Preset(ECBLiquidGlassPreset::Regular)
		, _Quality(ECBLiquidGlassQuality::Balanced)
	{}
		/** Crisp content drawn above the fused glass. */
		SLATE_DEFAULT_SLOT(FArguments, Content)
		/** Rounded blobs that are smooth-unioned into one silhouette. */
		SLATE_ARGUMENT(TArray<FCBLiquidGlassFusionBlob>, Blobs)
		/** Merge radius in pixels; larger values melt neighbouring blobs together more. */
		SLATE_ARGUMENT(float, Smoothing)
		/** Display size of the fused glass canvas. */
		SLATE_ARGUMENT(FVector2D, CanvasSize)
		/** Generated alpha-mask resolution; zero derives it from CanvasSize and clamps safely. */
		SLATE_ARGUMENT(FVector2D, MaskResolution)
		SLATE_ARGUMENT(float, BlurStrength)
		SLATE_ARGUMENT(float, FrostRadius)
		SLATE_ARGUMENT(float, RefractionStrength)
		SLATE_ARGUMENT(float, RefractionThickness)
		SLATE_ARGUMENT(float, PrismIntensity)
		SLATE_ARGUMENT(float, RimIntensity)
		SLATE_ARGUMENT(float, GlassOpacity)
		/** Base glass material for the fused panel. */
		SLATE_ARGUMENT(ECBLiquidGlassPreset, Preset)
		/** Runtime quality profile. */
		SLATE_ARGUMENT(ECBLiquidGlassQuality, Quality)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Replaces the crisp content drawn above the glass. */
	void SetContent(const TSharedRef<SWidget>& InContent);
	/** Replaces the blob set and regenerates the merged mask. */
	void SetBlobs(const TArray<FCBLiquidGlassFusionBlob>& InBlobs);
	/** Sets the merge radius (px) and regenerates the mask. */
	void SetSmoothing(float InSmoothing);
	/** Sets the display size and regenerates the mask. */
	void SetCanvasSize(FVector2D InCanvasSize);
	/** Sets the generated alpha-mask resolution and regenerates the mask. */
	void SetMaskResolution(FVector2D InMaskResolution);
	void SetBlurStrength(float InValue);
	void SetFrostRadius(float InValue);
	void SetRefractionStrength(float InValue);
	void SetRefractionThickness(float InValue);
	void SetPrismIntensity(float InValue);
	void SetRimIntensity(float InValue);
	void SetGlassOpacity(float InValue);
	/** Sets the base glass material. */
	void SetPreset(ECBLiquidGlassPreset InPreset);
	/** Sets the quality profile. */
	void SetQuality(ECBLiquidGlassQuality InQuality);

private:
	void Rebuild();
	void RegenerateMask();

	TArray<FCBLiquidGlassFusionBlob> Blobs;
	float Smoothing = 40.0f;
	FVector2D CanvasSize = FVector2D(360.0f, 160.0f);
	FVector2D MaskResolution = FVector2D::ZeroVector;
	float BlurStrength = 1.05f;
	float FrostRadius = 0.24f;
	float RefractionStrength = 0.92f;
	float RefractionThickness = 48.0f;
	float PrismIntensity = 0.34f;
	float RimIntensity = 0.56f;
	float GlassOpacity = 1.0f;
	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::Regular;
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;

	TSharedPtr<SCBLiquidGlass> Glass;
	TSharedPtr<SWidget> PendingContent;
	TStrongObjectPtr<UTexture2D> MaskTexture;
	TArray<FCBLiquidGlassFusionBlob> CachedBlobs;
	float CachedSmoothing = -1.0f;
	FVector2D CachedCanvasSize = FVector2D(-1.0f, -1.0f);
	FVector2D CachedMaskResolution = FVector2D(-1.0f, -1.0f);
};

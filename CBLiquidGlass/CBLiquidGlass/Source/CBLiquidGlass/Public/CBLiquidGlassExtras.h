// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Components/ContentWidget.h"
#include "Components/Widget.h"
#include "CBLiquidGlassExtras.generated.h"

class SCBLiquidGlassBadge;
class SCBLiquidGlassPageControl;
class SCBLiquidGlassNavigationBar;
class SCBLiquidGlassDialog;
class SCBLiquidGlassContainer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCBLiquidGlassPageChangedEvent, int32, PageIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCBLiquidGlassSimpleEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCBLiquidGlassActionEvent, int32, Index, int32, Value);

/** UMG count/notification badge (the red bubble UIKit puts on tab and app icons). */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Badge"))
class UCBLiquidGlassBadge : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassBadge();

	/** Number shown in the badge; values <= 0 hide it unless DotMode is on. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Badge")
	int32 Count = 1;

	/** Counts above this render as "MaxCount+". */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Badge", meta = (ClampMin = "1"))
	int32 MaxCount = 99;

	/** Draws a small dot with no number instead of a counted capsule. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Badge")
	bool bDotMode = false;

	/** Badge fill colour ( uses system red). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Badge")
	FLinearColor Color = FLinearColor(1.0f, 0.23f, 0.19f, 1.0f);

	/** Shared control style (quality). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Badge")
	FCBLiquidGlassControlStyle Style;

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Badge") CBLIQUIDGLASS_API void SetCount(int32 InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Badge") CBLIQUIDGLASS_API void SetMaxCount(int32 InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Badge") CBLIQUIDGLASS_API void SetDotMode(bool bInValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Badge") CBLIQUIDGLASS_API void SetColor(FLinearColor InValue);

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	TSharedPtr<SCBLiquidGlassBadge> MyBadge;
};

/** UMG  page indicator with a spring-driven active pill. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Page Control"))
class UCBLiquidGlassPageControl : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassPageControl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Page Control", meta = (ClampMin = "1"))
	int32 NumPages = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Page Control", meta = (ClampMin = "0"))
	int32 CurrentPage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Page Control", meta = (ClampMin = "2.0"))
	float DotSize = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Page Control", meta = (ClampMin = "0.0"))
	float DotSpacing = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Page Control")
	FLinearColor ActiveColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.95f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Page Control")
	FLinearColor InactiveColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.35f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Page Control")
	FCBLiquidGlassSpringSettings SpringSettings;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Page Control|Event")
	FCBLiquidGlassPageChangedEvent OnPageChanged;

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Page Control") CBLIQUIDGLASS_API void SetNumPages(int32 InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Page Control") CBLIQUIDGLASS_API void SetCurrentPage(int32 InValue);

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandlePageChanged(int32 InPage);
	TSharedPtr<SCBLiquidGlassPageControl> MyPageControl;
};

/** UMG glass navigation bar (leading back button, centered/large title, trailing actions). */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Navigation Bar"))
class UCBLiquidGlassNavigationBar : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassNavigationBar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Navigation Bar")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Navigation Bar")
	bool bShowBackButton = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Navigation Bar")
	bool bLargeTitle = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Navigation Bar")
	TArray<FCBLiquidGlassItem> TrailingItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Navigation Bar")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Navigation Bar|Event")
	FCBLiquidGlassSimpleEvent OnBackClicked;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Navigation Bar|Event")
	FCBLiquidGlassActionEvent OnTrailingItemClicked;

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Navigation Bar") CBLIQUIDGLASS_API void SetTitle(FText InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Navigation Bar") CBLIQUIDGLASS_API void SetShowBackButton(bool bInValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Navigation Bar") CBLIQUIDGLASS_API void SetLargeTitle(bool bInValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Navigation Bar") CBLIQUIDGLASS_API void SetTrailingItems(const TArray<FCBLiquidGlassItem>& InItems);

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleBack();
	void HandleTrailing(int32 Index, int32 Value);
	TSharedPtr<SCBLiquidGlassNavigationBar> MyNavBar;
};

/** UMG modal glass dialog (alert / action sheet / sheet) with a spring entrance. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Dialog"))
class UCBLiquidGlassDialog : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassDialog();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog", meta = (MultiLine = true))
	FText Message;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog")
	TArray<FCBLiquidGlassItem> Buttons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog")
	ECBLiquidGlassDialogStyle DialogStyle = ECBLiquidGlassDialogStyle::Alert;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog")
	bool bDimBackground = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float DimOpacity = 0.28f;

	/** Whether the dialog is shown as soon as it is constructed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog")
	bool bStartPresented = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog|Card", meta = (ClampMin = "0.0"))
	float CardBlurStrength = 1.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog|Card", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float CardFrostRadius = 0.42f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog|Card", meta = (ClampMin = "0.0"))
	float CardRefractionStrength = 0.72f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog|Card", meta = (ClampMin = "0.0"))
	float CardRefractionThickness = 34.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog|Card", meta = (ClampMin = "0.0"))
	float CardPrismIntensity = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog|Card", meta = (ClampMin = "0.0"))
	float CardRimIntensity = 0.36f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog|Card", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float CardGlassOpacity = 0.94f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog")
	FCBLiquidGlassControlStyle Style;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Dialog")
	FCBLiquidGlassSpringSettings SpringSettings;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Dialog|Event")
	FCBLiquidGlassActionEvent OnButtonClicked;

	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Dialog|Event")
	FCBLiquidGlassSimpleEvent OnDismissed;

	/** Animates the dialog in. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void Present();
	/** Animates the dialog out and fires OnDismissed when finished. */
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void Dismiss();
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetTitle(FText InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetMessage(FText InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetButtons(const TArray<FCBLiquidGlassItem>& InButtons);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetDimBackground(bool bInValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetDimOpacity(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetCardBlurStrength(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetCardFrostRadius(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetCardRefractionStrength(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetCardRefractionThickness(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetCardPrismIntensity(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetCardRimIntensity(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Dialog") CBLIQUIDGLASS_API void SetCardGlassOpacity(float InValue);

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;

private:
	void PushPropertiesToSlate();
	void HandleButton(int32 Index, int32 Value);
	void HandleDismissed();
	TSharedPtr<SCBLiquidGlassDialog> MyDialog;
};

/** UMG Liquid Glass fusion container (Apple GlassEffectContainer): blobs melt into one silhouette. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Container"))
class UCBLiquidGlassContainer : public UContentWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassContainer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container")
	TArray<FCBLiquidGlassFusionBlob> Blobs;

	/** Merge radius in pixels; larger melts neighbouring blobs together more. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container", meta = (ClampMin = "0.0"))
	float Smoothing = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container")
	FVector2D CanvasSize = FVector2D(360.0f, 160.0f);

	/**
	 * Resolution of the generated alpha mask. Leave at zero to derive it from CanvasSize
	 * and clamp to a safe 1024 px maximum per axis.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container")
	FVector2D MaskResolution = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container|Visual", meta = (ClampMin = "0.0"))
	float BlurStrength = 1.05f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container|Visual", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float FrostRadius = 0.24f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container|Visual", meta = (ClampMin = "0.0"))
	float RefractionStrength = 0.92f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container|Visual", meta = (ClampMin = "0.0"))
	float RefractionThickness = 48.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container|Visual", meta = (ClampMin = "0.0"))
	float PrismIntensity = 0.34f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container|Visual", meta = (ClampMin = "0.0"))
	float RimIntensity = 0.56f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container|Visual", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float GlassOpacity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container")
	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::Regular;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Container")
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetBlobs(const TArray<FCBLiquidGlassFusionBlob>& InBlobs);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetSmoothing(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetCanvasSize(FVector2D InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetMaskResolution(FVector2D InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetBlurStrength(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetFrostRadius(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetRefractionStrength(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetRefractionThickness(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetPrismIntensity(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetRimIntensity(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetGlassOpacity(float InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetPreset(ECBLiquidGlassPreset InValue);
	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Container") CBLIQUIDGLASS_API void SetQuality(ECBLiquidGlassQuality InValue);

	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;
	CBLIQUIDGLASS_API virtual void OnSlotAdded(UPanelSlot* AddedSlot) override;
	CBLIQUIDGLASS_API virtual void OnSlotRemoved(UPanelSlot* RemovedSlot) override;

private:
	void PushPropertiesToSlate();
	TSharedPtr<SCBLiquidGlassContainer> MyContainer;
};

// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelSlot.h"
#include "Layout/Margin.h"
#include "Widgets/SNullWidget.h"
#include "CBLiquidGlassSlot.generated.h"

class SCBLiquidGlass;

/** The single content slot for a UCBLiquidGlass panel. */
UCLASS(MinimalAPI)
class UCBLiquidGlassSlot : public UPanelSlot
{
	GENERATED_BODY()

public:
	/** Sets inner spacing between the glass bounds and the child content. */
	UFUNCTION(BlueprintCallable, Category = "Layout|Liquid Glass Slot")
	CBLIQUIDGLASS_API void SetPadding(FMargin InPadding);

	/** Sets horizontal alignment of the child inside the glass container. */
	UFUNCTION(BlueprintCallable, Category = "Layout|Liquid Glass Slot")
	CBLIQUIDGLASS_API void SetHorizontalAlignment(EHorizontalAlignment InHorizontalAlignment);

	/** Sets vertical alignment of the child inside the glass container. */
	UFUNCTION(BlueprintCallable, Category = "Layout|Liquid Glass Slot")
	CBLIQUIDGLASS_API void SetVerticalAlignment(EVerticalAlignment InVerticalAlignment);

	//~ Begin UPanelSlot interface
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;
	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UPanelSlot interface

	/** Attaches this slot's content to the underlying Slate liquid glass widget. */
	CBLIQUIDGLASS_API void BuildSlot(TSharedRef<SCBLiquidGlass> InGlass);

protected:
	/** UMG slot padding forwarded to SCBLiquidGlass::ChildSlot. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, Category = "Layout|Liquid Glass Slot")
	FMargin Padding = FMargin(0.0f);

	/** Horizontal alignment forwarded to the underlying Slate child slot. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, Category = "Layout|Liquid Glass Slot")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment = HAlign_Fill;

	/** Vertical alignment forwarded to the underlying Slate child slot. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, Category = "Layout|Liquid Glass Slot")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment = VAlign_Fill;

private:
	/** Weak because the UMG slot does not own the Slate widget lifetime. */
	TWeakPtr<SCBLiquidGlass> Glass;
};

// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelSlot.h"
#include "Layout/Margin.h"
#include "Widgets/SNullWidget.h"
#include "CBLiquidGlassButtonSlot.generated.h"

class SCBLiquidGlassButton;

/** The single content slot for a UCBLiquidGlassButton. */
UCLASS(MinimalAPI)
class UCBLiquidGlassButtonSlot : public UPanelSlot
{
	GENERATED_BODY()

public:
	/** Sets inner spacing between the button glass bounds and child content. */
	UFUNCTION(BlueprintCallable, Category = "Layout|Liquid Glass Button Slot")
	CBLIQUIDGLASS_API void SetPadding(FMargin InPadding);

	/** Sets horizontal alignment of the child inside the glass button. */
	UFUNCTION(BlueprintCallable, Category = "Layout|Liquid Glass Button Slot")
	CBLIQUIDGLASS_API void SetHorizontalAlignment(EHorizontalAlignment InHorizontalAlignment);

	/** Sets vertical alignment of the child inside the glass button. */
	UFUNCTION(BlueprintCallable, Category = "Layout|Liquid Glass Button Slot")
	CBLIQUIDGLASS_API void SetVerticalAlignment(EVerticalAlignment InVerticalAlignment);

	//~ Begin UPanelSlot interface
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;
	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UPanelSlot interface

	/** Attaches this slot's content to the underlying Slate glass button. */
	CBLIQUIDGLASS_API void BuildSlot(TSharedRef<SCBLiquidGlassButton> InButton);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, Category = "Layout|Liquid Glass Button Slot")
	FMargin Padding = FMargin(16.0f, 8.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, Category = "Layout|Liquid Glass Button Slot")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment = HAlign_Center;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, Category = "Layout|Liquid Glass Button Slot")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment = VAlign_Center;

private:
	TWeakPtr<SCBLiquidGlassButton> Button;
};

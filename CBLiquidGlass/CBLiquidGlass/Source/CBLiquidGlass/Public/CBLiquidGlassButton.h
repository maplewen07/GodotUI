// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Components/ContentWidget.h"
#include "CBLiquidGlassButton.generated.h"

class SCBLiquidGlassButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCBLiquidGlassButtonClickedEvent);

/** UMG button that uses liquid glass as its interactive background. */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Button"))
class UCBLiquidGlassButton : public UContentWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassButton();

	/** Visual preset used as the button's base glass recipe. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Button")
	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::PillLens;

	/** Shape used by the glass button background. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Button")
	ECBLiquidGlassShape Shape = ECBLiquidGlassShape::Capsule;

	/** Extra rim and glow added while the pointer hovers the button. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Button|Interaction", meta = (ClampMin = "0.0", ClampMax = "2.0"))
	float HoverGlowBoost = 0.18f;

	/** Extra refraction added while the button is pressed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Button|Interaction", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float PressedRefractionBoost = 0.14f;

	/** Extra tint added while the button is pressed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Button|Interaction", meta = (ClampMin = "0.0", ClampMax = "0.5"))
	float PressedTintBoost = 0.035f;

	/** Glass opacity multiplier when the button is disabled. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Button|Interaction", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float DisabledOpacity = 0.38f;

	/** Broadcast when the button is clicked. */
	UPROPERTY(BlueprintAssignable, Category = "Liquid Glass Button|Event")
	FCBLiquidGlassButtonClickedEvent OnClicked;

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Button")
	CBLIQUIDGLASS_API void SetPreset(ECBLiquidGlassPreset InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Button")
	CBLIQUIDGLASS_API void SetShape(ECBLiquidGlassShape InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Button|Interaction")
	CBLIQUIDGLASS_API void SetHoverGlowBoost(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Button|Interaction")
	CBLIQUIDGLASS_API void SetPressedRefractionBoost(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Button|Interaction")
	CBLIQUIDGLASS_API void SetPressedTintBoost(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Button|Interaction")
	CBLIQUIDGLASS_API void SetDisabledOpacity(float InValue);

	ECBLiquidGlassPreset GetPreset() const { return Preset; }
	ECBLiquidGlassShape GetShape() const { return Shape; }
	float GetHoverGlowBoost() const { return HoverGlowBoost; }
	float GetPressedRefractionBoost() const { return PressedRefractionBoost; }
	float GetPressedTintBoost() const { return PressedTintBoost; }
	float GetDisabledOpacity() const { return DisabledOpacity; }

	//~ Begin UWidget interface
	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UWidget interface

#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

protected:
	//~ Begin UPanelWidget / UWidget interface
	CBLIQUIDGLASS_API virtual UClass* GetSlotClass() const override;
	CBLIQUIDGLASS_API virtual void OnSlotAdded(UPanelSlot* InSlot) override;
	CBLIQUIDGLASS_API virtual void OnSlotRemoved(UPanelSlot* InSlot) override;
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;
	//~ End UPanelWidget / UWidget interface

private:
	void HandleSlateClicked();
	void PushPropertiesToSlate();

	TSharedPtr<SCBLiquidGlassButton> MyButton;
};

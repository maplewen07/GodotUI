// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Components/Widget.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"
#include "CBLiquidGlassText.generated.h"

class SCBLiquidGlassText;

/**
 * UMG wrapper for liquid-glass text.
 *
 * Unlike a normal TextBlock, the visible glyphs are copied into an alpha mask and used
 * as the glass shape. The selected Slate font and fallback chain decide which scripts
 * are available, so Chinese, digits, pinyin and punctuation work when the font supports them.
 */
UCLASS(MinimalAPI, meta = (DisplayName = "Liquid Glass Text"))
class UCBLiquidGlassText : public UWidget
{
	GENERATED_BODY()

public:
	UCBLiquidGlassText();

	/** Text to draw as glyph-shaped liquid glass. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text")
	FText Text;

	/** Font used by Slate to shape and rasterize the glass text mask. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text")
	FSlateFontInfo Font;

	/** Compatibility colour property kept for Blueprint API stability. The glass shader controls colour. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text")
	FSlateColor ColorAndOpacity;

	/** Base glass material applied to the generated text mask. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text|Glass")
	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::Regular;

	/** Runtime quality profile for the text glass pass. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text|Glass")
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;

	/** Frost mix used by the generated text glass. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text|Glass", meta = (ClampMin = "0.0", ClampMax = "1.5"))
	float FrostRadius = 0.22f;

	/** Extra glass padding/thickness control used around the font mask. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text|Typography", meta = (ClampMin = "4.0", ClampMax = "30.0"))
	float GlyphThickness = 12.0f;

	/** Horizontal distance between generated glyphs before font-size scaling. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text|Typography", meta = (ClampMin = "-8.0", ClampMax = "40.0"))
	float LetterSpacing = 8.0f;

	/** Vertical distance between generated text lines before font-size scaling. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text|Typography", meta = (ClampMin = "0.0", ClampMax = "80.0"))
	float LineSpacing = 16.0f;

	/** Motion deformation amount applied to all generated text strokes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Getter, Setter, Category = "Liquid Glass Text|Motion", meta = (ClampMin = "0.0", ClampMax = "3.0"))
	float MotionStrength = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text")
	CBLIQUIDGLASS_API void SetText(FText InText);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text")
	CBLIQUIDGLASS_API void SetFont(FSlateFontInfo InFont);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text")
	CBLIQUIDGLASS_API void SetColorAndOpacity(FSlateColor InColorAndOpacity);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text|Glass")
	CBLIQUIDGLASS_API void SetPreset(ECBLiquidGlassPreset InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text|Glass")
	CBLIQUIDGLASS_API void SetQuality(ECBLiquidGlassQuality InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text|Glass")
	CBLIQUIDGLASS_API void SetFrostRadius(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text|Typography")
	CBLIQUIDGLASS_API void SetGlyphThickness(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text|Typography")
	CBLIQUIDGLASS_API void SetLetterSpacing(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text|Typography")
	CBLIQUIDGLASS_API void SetLineSpacing(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Liquid Glass Text|Motion")
	CBLIQUIDGLASS_API void SetMotionStrength(float InValue);

	FText GetText() const { return Text; }
	FSlateFontInfo GetFont() const { return Font; }
	FSlateColor GetColorAndOpacity() const { return ColorAndOpacity; }
	ECBLiquidGlassPreset GetPreset() const { return Preset; }
	ECBLiquidGlassQuality GetQuality() const { return Quality; }
	float GetFrostRadius() const { return FrostRadius; }
	float GetGlyphThickness() const { return GlyphThickness; }
	float GetLetterSpacing() const { return LetterSpacing; }
	float GetLineSpacing() const { return LineSpacing; }
	float GetMotionStrength() const { return MotionStrength; }

	//~ Begin UWidget interface
	CBLIQUIDGLASS_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	CBLIQUIDGLASS_API virtual TSharedRef<SWidget> RebuildWidget() override;
	CBLIQUIDGLASS_API virtual void SynchronizeProperties() override;
	//~ End UWidget interface

#if WITH_EDITOR
	CBLIQUIDGLASS_API virtual const FText GetPaletteCategory() override;
#endif

private:
	void PushPropertiesToSlate();

	TSharedPtr<SCBLiquidGlassText> MyGlassText;
};

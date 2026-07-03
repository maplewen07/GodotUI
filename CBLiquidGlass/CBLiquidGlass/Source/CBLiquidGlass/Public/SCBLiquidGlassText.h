// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"
#include "UObject/StrongObjectPtr.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class UTexture2D;
struct FSlateImageBrush;

/**
 * Slate text rendered as a real liquid-glass alpha mask.
 *
 * The widget asks Slate's font cache to shape/rasterize the string, copies the resulting
 * glyph atlas alpha into a transient texture, and uses that texture as SCBLiquidGlass'
 * alpha mask. This keeps the glass effect on the glyphs themselves while supporting any
 * script covered by the selected Slate font and its fallback chain.
 */
class CBLIQUIDGLASS_API SCBLiquidGlassText : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCBLiquidGlassText)
		: _Text(FText::FromString(TEXT("Liquid Glass")))
		, _Font(FSlateFontInfo())
		, _ColorAndOpacity(FLinearColor::White)
		, _FontSize(64)
		, _GlyphThickness(12.0f)
		, _LetterSpacing(8.0f)
		, _LineSpacing(16.0f)
		, _Preset(ECBLiquidGlassPreset::Clear)
		, _Quality(ECBLiquidGlassQuality::Balanced)
		, _FrostRadius(0.12f)
		, _MotionStrength(0.35f)
	{}
		SLATE_ARGUMENT(FText, Text)
		SLATE_ARGUMENT(FSlateFontInfo, Font)
		SLATE_ARGUMENT(FSlateColor, ColorAndOpacity)
		SLATE_ARGUMENT(int32, FontSize)
		SLATE_ARGUMENT(float, GlyphThickness)
		SLATE_ARGUMENT(float, LetterSpacing)
		SLATE_ARGUMENT(float, LineSpacing)
		SLATE_ARGUMENT(ECBLiquidGlassPreset, Preset)
		SLATE_ARGUMENT(ECBLiquidGlassQuality, Quality)
		SLATE_ARGUMENT(float, FrostRadius)
		SLATE_ARGUMENT(float, MotionStrength)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Rebuilds the procedural glyph strokes for a new string. */
	void SetText(FText InText);

	/** Sets the real Slate font used to rasterize the glyph mask. */
	void SetFont(FSlateFontInfo InFont);

	/** Sets the matte/source colour drawn under the transparent glass text. */
	void SetColorAndOpacity(FSlateColor InColorAndOpacity);

	/** Controls the procedural glyph scale. This is independent from Slate font families. */
	void SetFontSize(int32 InFontSize);

	/** Controls the thickness of each glass stroke before scaling. */
	void SetGlyphThickness(float InGlyphThickness);

	/** Controls horizontal spacing between glyphs before scaling. */
	void SetLetterSpacing(float InLetterSpacing);

	/** Controls vertical spacing between lines after scaling. */
	void SetLineSpacing(float InLineSpacing);

	/** Applies a material preset to all generated glass strokes. */
	void SetPreset(ECBLiquidGlassPreset InPreset);

	/** Applies a render quality profile to all generated glass strokes. */
	void SetQuality(ECBLiquidGlassQuality InQuality);

	/** Controls the clear/frosted mix for all generated glass strokes. */
	void SetFrostRadius(float InFrostRadius);

	/** Controls drag-responsive deformation on all generated glass strokes. */
	void SetMotionStrength(float InMotionStrength);

private:
	/** Recreates the SCanvas children whenever text, spacing or material values change. */
	void RefreshTextLayout();

	FText Text;
	FSlateFontInfo Font;
	FSlateColor ColorAndOpacity = FSlateColor(FLinearColor::White);
	int32 FontSize = 64;
	float GlyphThickness = 12.0f;
	float LetterSpacing = 8.0f;
	float LineSpacing = 16.0f;
	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::Clear;
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;
	float FrostRadius = 0.12f;
	float MotionStrength = 0.35f;
	TStrongObjectPtr<UTexture2D> TextMaskTexture;
	TSharedPtr<FSlateImageBrush> TextSourceBrush;
};

// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassText.h"
#include "SCBLiquidGlassText.h"
#include "Styling/CoreStyle.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlassText"

UCBLiquidGlassText::UCBLiquidGlassText()
{
	Text = LOCTEXT("DefaultLiquidGlassText", "Liquid Glass");
	Font = FCoreStyle::GetDefaultFontStyle("Bold", 24);
	ColorAndOpacity = FSlateColor(FLinearColor::White);
	bIsVariable = false;
}

TSharedRef<SWidget> UCBLiquidGlassText::RebuildWidget()
{
	MyGlassText = SNew(SCBLiquidGlassText)
		.Text(Text)
		.Font(Font)
		.ColorAndOpacity(ColorAndOpacity)
		.FontSize(Font.Size)
		.GlyphThickness(GlyphThickness)
		.LetterSpacing(LetterSpacing)
		.LineSpacing(LineSpacing)
		.Preset(Preset)
		.Quality(Quality)
		.FrostRadius(FrostRadius)
		.MotionStrength(MotionStrength);

	PushPropertiesToSlate();

	return MyGlassText.ToSharedRef();
}

void UCBLiquidGlassText::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyGlassText.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassText::GetPaletteCategory()
{
	return LOCTEXT("LiquidGlassPaletteCategory", "Liquid Glass");
}
#endif

void UCBLiquidGlassText::SetText(FText InText)
{
	Text = MoveTemp(InText);
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetFont(FSlateFontInfo InFont)
{
	Font = MoveTemp(InFont);
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetColorAndOpacity(FSlateColor InColorAndOpacity)
{
	ColorAndOpacity = MoveTemp(InColorAndOpacity);
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetPreset(ECBLiquidGlassPreset InValue)
{
	Preset = InValue;
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetQuality(ECBLiquidGlassQuality InValue)
{
	Quality = InValue;
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetFrostRadius(float InValue)
{
	FrostRadius = InValue;
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetGlyphThickness(float InValue)
{
	GlyphThickness = InValue;
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetLetterSpacing(float InValue)
{
	LetterSpacing = InValue;
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetLineSpacing(float InValue)
{
	LineSpacing = InValue;
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::SetMotionStrength(float InValue)
{
	MotionStrength = InValue;
	PushPropertiesToSlate();
}

void UCBLiquidGlassText::PushPropertiesToSlate()
{
	if (MyGlassText.IsValid())
	{
		MyGlassText->SetText(Text);
		MyGlassText->SetFont(Font);
		MyGlassText->SetColorAndOpacity(ColorAndOpacity);
		MyGlassText->SetGlyphThickness(GlyphThickness);
		MyGlassText->SetLetterSpacing(LetterSpacing);
		MyGlassText->SetLineSpacing(LineSpacing);
		MyGlassText->SetPreset(Preset);
		MyGlassText->SetQuality(Quality);
		MyGlassText->SetFrostRadius(FrostRadius);
		MyGlassText->SetMotionStrength(MotionStrength);
	}
}

#undef LOCTEXT_NAMESPACE

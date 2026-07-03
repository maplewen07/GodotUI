// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "SCBLiquidGlassText.h"

#include "SCBLiquidGlass.h"
#include "Brushes/SlateImageBrush.h"
#include "Engine/Texture2D.h"
#include "Fonts/FontCache.h"
#include "Framework/Application/SlateApplication.h"
#include "Rendering/SlateRenderer.h"
#include "Styling/CoreStyle.h"
#include "Textures/TextureAtlas.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

namespace
{
	struct FCBLGTextAtlasCopy
	{
		TArray<uint8> Pixels;
		int32 Width = 0;
		int32 Height = 0;
		int32 BytesPerPixel = 1;
		ESlateFontAtlasContentType ContentType = ESlateFontAtlasContentType::Alpha;
	};

	struct FCBLGTextLine
	{
		FString Text;
		FShapedGlyphSequencePtr GlyphSequence;
		int32 Width = 0;
		int32 Height = 0;
		int32 Baseline = 0;
	};

	static uint8 ReadAtlasAlpha(const FCBLGTextAtlasCopy& Atlas, int32 X, int32 Y)
	{
		if (!Atlas.Pixels.IsValidIndex((Y * Atlas.Width + X) * Atlas.BytesPerPixel))
		{
			return 0;
		}

		const int32 PixelOffset = (Y * Atlas.Width + X) * Atlas.BytesPerPixel;
		switch (Atlas.ContentType)
		{
		case ESlateFontAtlasContentType::Color:
			return Atlas.Pixels.IsValidIndex(PixelOffset + 3) ? Atlas.Pixels[PixelOffset + 3] : 0;
		case ESlateFontAtlasContentType::Msdf:
			// MSDF font atlases encode distance in RGB. A luminance approximation is enough for
			// the mask fallback, though regular Slate fonts normally use Alpha here.
			if (Atlas.Pixels.IsValidIndex(PixelOffset + 2))
			{
				return static_cast<uint8>((int32(Atlas.Pixels[PixelOffset])
					+ int32(Atlas.Pixels[PixelOffset + 1])
					+ int32(Atlas.Pixels[PixelOffset + 2])) / 3);
			}
			return 0;
		case ESlateFontAtlasContentType::Alpha:
		default:
			return Atlas.Pixels[PixelOffset];
		}
	}

	static void WriteMaskAlpha(TArray<uint8>& MaskPixels, int32 MaskWidth, int32 MaskHeight, int32 X, int32 Y, uint8 Alpha)
	{
		if (X < 0 || Y < 0 || X >= MaskWidth || Y >= MaskHeight || Alpha == 0)
		{
			return;
		}

		const int32 PixelOffset = (Y * MaskWidth + X) * 4;
		const uint8 CombinedAlpha = FMath::Max(MaskPixels[PixelOffset + 3], Alpha);
		MaskPixels[PixelOffset + 0] = CombinedAlpha;
		MaskPixels[PixelOffset + 1] = CombinedAlpha;
		MaskPixels[PixelOffset + 2] = CombinedAlpha;
		MaskPixels[PixelOffset + 3] = CombinedAlpha;
	}

	static UTexture2D* CreateTextureFromMaskPixels(const TArray<uint8>& MaskPixels, int32 Width, int32 Height)
	{
		if (Width <= 0 || Height <= 0 || MaskPixels.Num() != Width * Height * 4)
		{
			return nullptr;
		}

		const FName TextureName = MakeUniqueObjectName(GetTransientPackage(), UTexture2D::StaticClass(), TEXT("CBLG_Text_Mask"));
		UTexture2D* Texture = UTexture2D::CreateTransient(
			Width,
			Height,
			PF_B8G8R8A8,
			TextureName,
			TConstArrayView64<uint8>(MaskPixels));

		if (!Texture)
		{
			return nullptr;
		}

		Texture->SRGB = false;
		Texture->Filter = TF_Bilinear;
		Texture->AddressX = TA_Clamp;
		Texture->AddressY = TA_Clamp;
		Texture->UpdateResource();
		return Texture;
	}

	static FSlateFontInfo ResolveFontInfo(const FSlateFontInfo& InFont, int32 FontSize, float LetterSpacing)
	{
		FSlateFontInfo ResolvedFont = InFont;
		if (ResolvedFont.Size <= 0.0f)
		{
			ResolvedFont = FCoreStyle::GetDefaultFontStyle("Bold", FontSize);
		}

		ResolvedFont.Size = FMath::Max<float>(FontSize, 1.0f);
		ResolvedFont.LetterSpacing += FMath::RoundToInt(LetterSpacing);
		ResolvedFont.FontFallback = EFontFallback::FF_Max;
		ResolvedFont.OutlineSettings = FFontOutlineSettings::NoOutline;
		return ResolvedFont;
	}

	static bool BuildTextMaskTexture(
		const FText& Text,
		const FSlateFontInfo& Font,
		int32 FontSize,
		float GlyphThickness,
		float LetterSpacing,
		float LineSpacing,
		TStrongObjectPtr<UTexture2D>& OutTexture,
		FVector2D& OutSize)
	{
		OutTexture.Reset();
		OutSize = FVector2D(1.0f, 1.0f);

		if (!FSlateApplication::IsInitialized() || !FSlateApplication::Get().GetRenderer())
		{
			return false;
		}

		TSharedRef<FSlateFontCache> FontCache = FSlateApplication::Get().GetRenderer()->GetFontCache();
		const int32 SafeFontSize = FMath::Max(FontSize, 8);
		const float SafeGlyphThickness = FMath::Clamp(GlyphThickness, 4.0f, 48.0f);
		const float SafeLineSpacing = FMath::Max(LineSpacing, 0.0f);
		const float SafeLetterSpacing = FMath::Clamp(LetterSpacing, -64.0f, 256.0f);
		const FSlateFontInfo ResolvedFont = ResolveFontInfo(Font, SafeFontSize, SafeLetterSpacing);

		TArray<FString> SourceLines;
		Text.ToString().ParseIntoArrayLines(SourceLines, false);
		if (SourceLines.IsEmpty())
		{
			SourceLines.Add(FString());
		}

		TArray<FCBLGTextLine> Lines;
		Lines.Reserve(SourceLines.Num());

		int32 MaxLineWidth = 1;
		int32 TotalHeight = 0;
		const int32 FallbackLineHeight = FMath::Max<int32>(FontCache->GetMaxCharacterHeight(ResolvedFont, 1.0f), SafeFontSize);

		for (const FString& SourceLine : SourceLines)
		{
			FCBLGTextLine Line;
			Line.Text = SourceLine;
			Line.GlyphSequence = FontCache->ShapeBidirectionalText(
				SourceLine,
				ResolvedFont,
				1.0f,
				TextBiDi::ETextDirection::LeftToRight,
				ETextShapingMethod::FullShaping);

			if (Line.GlyphSequence.IsValid())
			{
				Line.Width = FMath::Max(Line.GlyphSequence->GetMeasuredWidth(), 1);
				Line.Height = FMath::Max<int32>(Line.GlyphSequence->GetMaxTextHeight(), FallbackLineHeight);
				Line.Baseline = Line.GlyphSequence->GetTextBaseline();

				for (const FShapedGlyphEntry& Glyph : Line.GlyphSequence->GetGlyphsToRender())
				{
					if (Glyph.bIsVisible)
					{
						FontCache->GetShapedGlyphFontAtlasData(Glyph, FFontOutlineSettings::NoOutline);
					}
				}
			}
			else
			{
				Line.Width = 1;
				Line.Height = FallbackLineHeight;
				Line.Baseline = FontCache->GetBaseline(ResolvedFont, 1.0f);
			}

			MaxLineWidth = FMath::Max(MaxLineWidth, Line.Width);
			TotalHeight += Line.Height;
			Lines.Add(MoveTemp(Line));
		}

		TotalHeight += FMath::RoundToInt(SafeLineSpacing) * FMath::Max(0, Lines.Num() - 1);

		const int32 Padding = FMath::CeilToInt(FMath::Max(SafeGlyphThickness * (SafeFontSize / 100.0f) * 2.8f, SafeFontSize * 0.22f));
		const int32 MaskWidth = FMath::Clamp(MaxLineWidth + Padding * 2, 1, 4096);
		const int32 MaskHeight = FMath::Clamp(TotalHeight + Padding * 2, 1, 4096);

		TArray<uint8> MaskPixels;
		MaskPixels.SetNumZeroed(MaskWidth * MaskHeight * 4);

		TMap<uint32, FCBLGTextAtlasCopy> AtlasCopies;
		auto GetAtlasCopy = [&AtlasCopies, &FontCache](uint32 TextureIndex) -> FCBLGTextAtlasCopy*
		{
			if (FCBLGTextAtlasCopy* Existing = AtlasCopies.Find(TextureIndex))
			{
				return Existing;
			}

			ISlateFontTexture* FontTexture = FontCache->GetFontTexture(TextureIndex);
			if (!FontTexture || !FontTexture->GetEngineTexture())
			{
				return nullptr;
			}

			FCBLGTextAtlasCopy Atlas;
			Atlas.Width = FontTexture->GetEngineTexture()->GetSizeX();
			Atlas.Height = FontTexture->GetEngineTexture()->GetSizeY();
			Atlas.ContentType = FontTexture->GetContentType();
			Atlas.BytesPerPixel = static_cast<int32>(GetSlateFontAtlasContentBytesPerPixel(Atlas.ContentType));
			FontTexture->GetAtlasDataCopy(Atlas.Pixels);

			if (Atlas.Width <= 0 || Atlas.Height <= 0 || Atlas.BytesPerPixel <= 0 || Atlas.Pixels.IsEmpty())
			{
				return nullptr;
			}

			return &AtlasCopies.Add(TextureIndex, MoveTemp(Atlas));
		};

		float CursorY = static_cast<float>(Padding);
		for (const FCBLGTextLine& Line : Lines)
		{
			if (!Line.GlyphSequence.IsValid())
			{
				CursorY += Line.Height + SafeLineSpacing;
				continue;
			}

			const float LineStartX = Padding + (MaxLineWidth - Line.Width) * 0.5f;
			float LineX = 0.0f;
			const float MaxHeight = static_cast<float>(Line.GlyphSequence->GetMaxTextHeight());
			const float Baseline = static_cast<float>(Line.GlyphSequence->GetTextBaseline());

			for (const FShapedGlyphEntry& Glyph : Line.GlyphSequence->GetGlyphsToRender())
			{
				if (Glyph.bIsVisible)
				{
					const FShapedGlyphFontAtlasData AtlasData = FontCache->GetShapedGlyphFontAtlasData(Glyph, FFontOutlineSettings::NoOutline);
					if (AtlasData.Valid)
					{
						if (const FCBLGTextAtlasCopy* Atlas = GetAtlasCopy(AtlasData.TextureIndex))
						{
							const float BitmapRenderScale = FMath::Max(Glyph.GetBitmapRenderScale(), 0.001f);
							const float InvBitmapRenderScale = 1.0f / BitmapRenderScale;
							const float GlyphX = LineStartX
								+ LineX
								+ AtlasData.HorizontalOffset
								+ Glyph.XOffset;
							const float GlyphY = CursorY
								- AtlasData.VerticalOffset
								+ Glyph.YOffset
								+ ((Baseline + MaxHeight) * InvBitmapRenderScale);

							const int32 DestW = FMath::Max(1, FMath::RoundToInt(AtlasData.USize * BitmapRenderScale));
							const int32 DestH = FMath::Max(1, FMath::RoundToInt(AtlasData.VSize * BitmapRenderScale));
							for (int32 DestY = 0; DestY < DestH; ++DestY)
							{
								const int32 SrcY = FMath::Clamp(AtlasData.StartV + FMath::FloorToInt(DestY / BitmapRenderScale), 0, Atlas->Height - 1);
								for (int32 DestX = 0; DestX < DestW; ++DestX)
								{
									const int32 SrcX = FMath::Clamp(AtlasData.StartU + FMath::FloorToInt(DestX / BitmapRenderScale), 0, Atlas->Width - 1);
									const uint8 Alpha = ReadAtlasAlpha(*Atlas, SrcX, SrcY);
									WriteMaskAlpha(
										MaskPixels,
										MaskWidth,
										MaskHeight,
										FMath::RoundToInt(GlyphX) + DestX,
										FMath::RoundToInt(GlyphY) + DestY,
										Alpha);
								}
							}
						}
					}
				}

				LineX += Glyph.XAdvance;
			}

			CursorY += Line.Height + SafeLineSpacing;
		}

		UTexture2D* Texture = CreateTextureFromMaskPixels(MaskPixels, MaskWidth, MaskHeight);
		if (!Texture)
		{
			return false;
		}

		OutTexture = TStrongObjectPtr<UTexture2D>(Texture);
		OutSize = FVector2D(MaskWidth, MaskHeight);
		return true;
	}
}

void SCBLiquidGlassText::Construct(const FArguments& InArgs)
{
	Text = InArgs._Text;
	Font = InArgs._Font;
	ColorAndOpacity = InArgs._ColorAndOpacity;
	FontSize = InArgs._FontSize;
	GlyphThickness = InArgs._GlyphThickness;
	LetterSpacing = InArgs._LetterSpacing;
	LineSpacing = InArgs._LineSpacing;
	Preset = InArgs._Preset;
	Quality = InArgs._Quality;
	FrostRadius = InArgs._FrostRadius;
	MotionStrength = InArgs._MotionStrength;

	RefreshTextLayout();
}

void SCBLiquidGlassText::SetText(FText InText)
{
	Text = MoveTemp(InText);
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetFont(FSlateFontInfo InFont)
{
	Font = MoveTemp(InFont);
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetColorAndOpacity(FSlateColor InColorAndOpacity)
{
	ColorAndOpacity = MoveTemp(InColorAndOpacity);
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetFontSize(int32 InFontSize)
{
	FontSize = InFontSize;
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetGlyphThickness(float InGlyphThickness)
{
	GlyphThickness = InGlyphThickness;
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetLetterSpacing(float InLetterSpacing)
{
	LetterSpacing = InLetterSpacing;
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetLineSpacing(float InLineSpacing)
{
	LineSpacing = InLineSpacing;
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetPreset(ECBLiquidGlassPreset InPreset)
{
	Preset = InPreset;
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetQuality(ECBLiquidGlassQuality InQuality)
{
	Quality = InQuality;
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetFrostRadius(float InFrostRadius)
{
	FrostRadius = InFrostRadius;
	RefreshTextLayout();
}

void SCBLiquidGlassText::SetMotionStrength(float InMotionStrength)
{
	MotionStrength = InMotionStrength;
	RefreshTextLayout();
}

void SCBLiquidGlassText::RefreshTextLayout()
{
	FVector2D TextMaskSize(1.0f, 1.0f);
	const bool bBuiltMask = BuildTextMaskTexture(
		Text,
		Font,
		FontSize,
		GlyphThickness,
		LetterSpacing,
		LineSpacing,
		TextMaskTexture,
		TextMaskSize);

	if (!bBuiltMask)
	{
		ChildSlot
		[
			SNew(STextBlock)
			.Text(Text)
			.Font(ResolveFontInfo(Font, FMath::Max(FontSize, 8), LetterSpacing))
			.ColorAndOpacity(ColorAndOpacity)
		];
		return;
	}

	float BlurStrength = 0.5f;
	float RefractionStrength = 0.96f;
	float TintOpacity = 0.004f;
	float TextFrostRadius = FMath::Max(FrostRadius, 0.04f);
	float GlassOpacity = 0.98f;
	float RimIntensity = 0.46f;
	float PrismIntensity = 0.34f;

	switch (Preset)
	{
	case ECBLiquidGlassPreset::FrostedMenu:
		BlurStrength = 1.15f;
		RefractionStrength = 0.62f;
		TintOpacity = 0.05f;
		TextFrostRadius = FMath::Max(FrostRadius, 0.36f);
		RimIntensity = 0.2f;
		PrismIntensity = 0.36f;
		break;
	case ECBLiquidGlassPreset::MatteLayer:
		BlurStrength = 1.65f;
		RefractionStrength = 0.28f;
		TintOpacity = 0.08f;
		TextFrostRadius = FMath::Max(FrostRadius, 0.56f);
		GlassOpacity = 0.88f;
		RimIntensity = 0.14f;
		PrismIntensity = 0.2f;
		break;
	case ECBLiquidGlassPreset::PillLens:
		BlurStrength = 0.34f;
		RefractionStrength = 1.0f;
		TextFrostRadius = FMath::Max(FrostRadius, 0.018f);
		RimIntensity = 0.62f;
		PrismIntensity = 0.38f;
		break;
	case ECBLiquidGlassPreset::Clear:
	case ECBLiquidGlassPreset::Regular:
	case ECBLiquidGlassPreset::SelfLayer:
	case ECBLiquidGlassPreset::Custom:
	default:
		break;
	}

	const float SafeFontSize = FMath::Max(FontSize, 8);
	const float SafeGlyphThickness = FMath::Clamp(GlyphThickness, 4.0f, 48.0f);
	const float Thickness = FMath::Max(SafeFontSize * 0.42f + SafeGlyphThickness * 0.9f, 12.0f);
	const FLinearColor SourceColor = ColorAndOpacity.GetSpecifiedColor();
	const FLinearColor GlassTint = SourceColor.A > 0.0f
		? FLinearColor(
			FMath::Lerp(0.94f, SourceColor.R, 0.35f),
			FMath::Lerp(1.0f, SourceColor.G, 0.35f),
			FMath::Lerp(1.0f, SourceColor.B, 0.35f),
			1.0f)
		: FLinearColor(0.94f, 1.0f, 1.0f, 1.0f);
	// The source matte is only a faint underlay. Drawing it at full opacity makes the glyphs
	// look like plain white text and hides the refraction/rim work done by the glass layer.
	const float SourceOpacity = FMath::Clamp(SourceColor.A * 0.14f, 0.0f, 0.22f);
	const float SourceTintBoost = SourceOpacity > 0.0f ? 0.006f : 0.0f;
	TextSourceBrush = MakeShared<FSlateImageBrush>(
		TextMaskTexture.Get(),
		TextMaskSize,
		FSlateColor(FLinearColor::White),
		ESlateBrushTileType::NoTile,
		ESlateBrushImageType::FullColor);

	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(TextMaskSize.X)
		.HeightOverride(TextMaskSize.Y)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SNew(SImage)
				.Image(TextSourceBrush.Get())
				.ColorAndOpacity(FLinearColor(SourceColor.R, SourceColor.G, SourceColor.B, SourceOpacity))
			]
			+ SOverlay::Slot()
			[
				SNew(SCBLiquidGlass)
				.AlphaMaskTexture(TextMaskTexture.Get())
				.AlphaMaskThreshold(0.045f)
				.AlphaMaskSoftness(0.018f)
				.BlurStrength(BlurStrength)
				.DownsampleAmount(3)
				.RefractionStrength(RefractionStrength)
				.RefractionPower(2.15f)
				.RefractionThickness(Thickness)
				.IndexOfRefraction(1.94f)
				.ChromaticAberration(0.045f)
				.PrismIntensity(PrismIntensity)
				.NoiseAmount(0.006f)
				.GlowAmount(0.58f)
				.RimIntensity(RimIntensity)
				.GlowAngle(-135.0f)
				.TintColor(GlassTint)
				.TintOpacity(FMath::Clamp(TintOpacity + SourceTintBoost, 0.0f, 1.0f))
				.Saturation(1.16f)
				.GlassOpacity(GlassOpacity)
				.EdgeSoftness(0.58f)
				.FrostRadius(TextFrostRadius)
				.InnerGlowIntensity(0.18f)
				.InnerShadowIntensity(0.16f)
				.Quality(Quality)
				.MotionStrength(MotionStrength)
				.MotionMaxOffset(22.0f)
				.MotionResponse(24.0f)
				.MotionDamping(8.0f)
				[
					SNew(SBox)
				]
			]
		]
	];
}

// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "SCBLiquidGlass.h"
#include "CBLiquidGlassRenderer.h"
#include "Engine/Texture2D.h"
#include "Rendering/DrawElements.h"
#include "RenderingThread.h"
#include "TextureResource.h"
#include "HAL/PlatformMisc.h"

SCBLiquidGlass::SCBLiquidGlass()
	: SquirclePower(7.0f)
	, BlurStrength(0.95f)
	, DownsampleAmount(2)
	, RefractionStrength(1.0f)
	, RefractionPower(3.0f)
	, ChromaticAberration(0.12f)
	, NoiseAmount(0.018f)
	, GlowAmount(0.32f)
	, RimIntensity(0.24f)
	, GlowAngle(-135.0f)
	, TintColor(FLinearColor::White)
	, TintOpacity(0.015f)
	, Saturation(1.35f)
	, AdaptiveTintStrength(0.0f)
	, GlassOpacity(1.0f)
	, EdgeSoftness(1.0f)
	, Shape(ECBLiquidGlassShape::SuperellipseRect)
	, RefractionThickness(40.0f)
	, IndexOfRefraction(2.0f)
	, FrostRadius(0.28f)
	, PrismIntensity(1.0f)
	, InnerGlowIntensity(0.07f)
	, InnerShadowIntensity(0.12f)
	, Quality(ECBLiquidGlassQuality::Balanced)
	, MotionStrength(0.0f)
	, MotionMaxOffset(32.0f)
	, MotionResponse(16.0f)
	, MotionDamping(10.0f)
	, AlphaMaskThreshold(0.5f)
	, AlphaMaskSoftness(0.08f)
	, bInvertAlphaMask(false)
{
}

SCBLiquidGlass::~SCBLiquidGlass()
{
	// Release the render element on the render thread to respect render-thread pipelining.
	if (GlassElement.IsValid())
	{
		ENQUEUE_RENDER_COMMAND(CBLG_ReleaseElement)(
			[Element = MoveTemp(GlassElement)](FRHICommandListImmediate&) mutable
			{
				Element.Reset();
			});
	}
}

void SCBLiquidGlass::Construct(const FArguments& InArgs)
{
	// Store construction values locally; OnPaint packages them into a render-thread-safe struct.
	SquirclePower = InArgs._SquirclePower;
	BlurStrength = InArgs._BlurStrength;
	DownsampleAmount = InArgs._DownsampleAmount;
	RefractionStrength = InArgs._RefractionStrength;
	RefractionPower = InArgs._RefractionPower;
	ChromaticAberration = InArgs._ChromaticAberration;
	NoiseAmount = InArgs._NoiseAmount;
	GlowAmount = InArgs._GlowAmount;
	RimIntensity = InArgs._RimIntensity;
	GlowAngle = InArgs._GlowAngle;
	TintColor = InArgs._TintColor;
	TintOpacity = InArgs._TintOpacity;
	Saturation = InArgs._Saturation;
	AdaptiveTintStrength = InArgs._AdaptiveTintStrength;
	GlassOpacity = InArgs._GlassOpacity;
	EdgeSoftness = InArgs._EdgeSoftness;
	Shape = InArgs._Shape;
	RefractionThickness = InArgs._RefractionThickness;
	IndexOfRefraction = InArgs._IndexOfRefraction;
	FrostRadius = InArgs._FrostRadius;
	PrismIntensity = InArgs._PrismIntensity;
	InnerGlowIntensity = InArgs._InnerGlowIntensity;
	InnerShadowIntensity = InArgs._InnerShadowIntensity;
	Quality = InArgs._Quality;
	MotionStrength = InArgs._MotionStrength;
	MotionMaxOffset = InArgs._MotionMaxOffset;
	MotionResponse = InArgs._MotionResponse;
	MotionDamping = InArgs._MotionDamping;
	AlphaMaskTexture = InArgs._AlphaMaskTexture;
	AlphaMaskThreshold = InArgs._AlphaMaskThreshold;
	AlphaMaskSoftness = InArgs._AlphaMaskSoftness;
	bInvertAlphaMask = InArgs._bInvertAlphaMask;

	GlassElement = MakeShared<FCBLiquidGlassSlateElement>();

	// Child content is not rendered into the glass capture. It is painted later on the next layer.
	ChildSlot
		.HAlign(InArgs._HAlign)
		.VAlign(InArgs._VAlign)
		.Padding(InArgs._Padding)
	[
		InArgs._Content.Widget
	];

	// Motion deformation needs Tick so the liquid can recover after movement stops.
	SetCanTick(MotionStrength > 0.0f);
}

void SCBLiquidGlass::SetContent(const TSharedRef<SWidget>& InContent)
{
	ChildSlot.AttachWidget(InContent);
}

void SCBLiquidGlass::SetHAlign(EHorizontalAlignment InHAlign)
{
	ChildSlot.SetHorizontalAlignment(InHAlign);
}

void SCBLiquidGlass::SetVAlign(EVerticalAlignment InVAlign)
{
	ChildSlot.SetVerticalAlignment(InVAlign);
}

void SCBLiquidGlass::SetPadding(TAttribute<FMargin> InPadding)
{
	ChildSlot.SetPadding(MoveTemp(InPadding));
}

#define CBLG_DEFINE_SETTER(MemberName, ParamType) \
	void SCBLiquidGlass::Set##MemberName(ParamType InValue) \
	{ \
		if (MemberName != InValue) \
		{ \
			MemberName = InValue; \
			/* These setters affect only shader parameters, so a paint invalidation is enough. */ \
			Invalidate(EInvalidateWidgetReason::Paint); \
		} \
	}

CBLG_DEFINE_SETTER(SquirclePower, float)
CBLG_DEFINE_SETTER(BlurStrength, float)
CBLG_DEFINE_SETTER(DownsampleAmount, int32)
CBLG_DEFINE_SETTER(RefractionStrength, float)
CBLG_DEFINE_SETTER(RefractionPower, float)
CBLG_DEFINE_SETTER(ChromaticAberration, float)
CBLG_DEFINE_SETTER(NoiseAmount, float)
CBLG_DEFINE_SETTER(GlowAmount, float)
CBLG_DEFINE_SETTER(RimIntensity, float)
CBLG_DEFINE_SETTER(GlowAngle, float)
CBLG_DEFINE_SETTER(TintColor, FLinearColor)
CBLG_DEFINE_SETTER(TintOpacity, float)
CBLG_DEFINE_SETTER(Saturation, float)
CBLG_DEFINE_SETTER(AdaptiveTintStrength, float)
CBLG_DEFINE_SETTER(GlassOpacity, float)
CBLG_DEFINE_SETTER(EdgeSoftness, float)
CBLG_DEFINE_SETTER(Shape, ECBLiquidGlassShape)
CBLG_DEFINE_SETTER(RefractionThickness, float)
CBLG_DEFINE_SETTER(IndexOfRefraction, float)
CBLG_DEFINE_SETTER(FrostRadius, float)
CBLG_DEFINE_SETTER(PrismIntensity, float)
CBLG_DEFINE_SETTER(InnerGlowIntensity, float)
CBLG_DEFINE_SETTER(InnerShadowIntensity, float)
CBLG_DEFINE_SETTER(Quality, ECBLiquidGlassQuality)

void SCBLiquidGlass::SetMotionStrength(float InValue)
{
	if (MotionStrength != InValue)
	{
		MotionStrength = InValue;
		SetCanTick(MotionStrength > 0.0f);
		Invalidate(EInvalidateWidgetReason::Paint);
	}
}

CBLG_DEFINE_SETTER(MotionMaxOffset, float)
CBLG_DEFINE_SETTER(MotionResponse, float)
CBLG_DEFINE_SETTER(MotionDamping, float)
CBLG_DEFINE_SETTER(AlphaMaskThreshold, float)
CBLG_DEFINE_SETTER(AlphaMaskSoftness, float)

#undef CBLG_DEFINE_SETTER

void SCBLiquidGlass::SetAlphaMaskTexture(UTexture2D* InTexture)
{
	if (AlphaMaskTexture.Get() != InTexture)
	{
		AlphaMaskTexture = InTexture;
		Invalidate(EInvalidateWidgetReason::Paint);
	}
}

void SCBLiquidGlass::SetInvertAlphaMask(bool bInValue)
{
	if (bInvertAlphaMask != bInValue)
	{
		bInvertAlphaMask = bInValue;
		Invalidate(EInvalidateWidgetReason::Paint);
	}
}

void SCBLiquidGlass::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	const FVector2D CurrentCenter = AllottedGeometry.GetAbsolutePosition() + AllottedGeometry.GetAbsoluteSize() * 0.5f;
	const float DeltaTime = FMath::Max(InDeltaTime, 1.0f / 240.0f);

	if (!bHasLastCenter)
	{
		LastCenter = CurrentCenter;
		bHasLastCenter = true;
		return;
	}

	const FVector2D FrameDelta = CurrentCenter - LastCenter;
	LastCenter = CurrentCenter;

	const float MaxOffset = FMath::Max(0.0f, MotionMaxOffset);
	FVector2f Target = FVector2f(
		FMath::Clamp((float)FrameDelta.X, -MaxOffset, MaxOffset),
		FMath::Clamp((float)FrameDelta.Y, -MaxOffset, MaxOffset));

	if (MotionStrength <= 0.0f)
	{
		Target = FVector2f::ZeroVector;
	}

	const float BlendSpeed = Target.SizeSquared() > KINDA_SMALL_NUMBER
		? FMath::Max(MotionResponse, 0.0f)
		: FMath::Max(MotionDamping, 0.0f);
	const float Alpha = 1.0f - FMath::Exp(-BlendSpeed * DeltaTime);
	MotionVector = FMath::Lerp(MotionVector, Target, Alpha);

	if (!MotionVector.IsNearlyZero(0.05f) || !Target.IsNearlyZero(0.05f))
	{
		Invalidate(EInvalidateWidgetReason::Paint);
	}
}

int32 SCBLiquidGlass::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	int32 ContentLayerId = LayerId;

	const bool bCanSampleBackbuffer = FPlatformMisc::SupportsBackbufferSampling();
	const float WidgetAlpha = InWidgetStyle.GetColorAndOpacityTint().A;

	// Some platforms/RHIs cannot read the backbuffer from Slate. In that case the widget remains
	// a transparent content container instead of producing black or undefined pixels.
	if (bCanSampleBackbuffer && GlassElement.IsValid() && WidgetAlpha > 0.0f && AllottedGeometry.GetLocalSize().GetMin() > 0.0f)
	{
		// Convert the Slate render bounds into output-texture pixels; the render element clamps again
		// on the render thread because DPI scale and viewport size may differ across platforms.
		const FSlateRect RenderBoundingRect = AllottedGeometry.GetRenderBoundingRect();

		FCBLiquidGlassRenderParams Params;
		Params.Rect = FIntRect(
			FMath::RoundToInt(RenderBoundingRect.Left),
			FMath::RoundToInt(RenderBoundingRect.Top),
			FMath::RoundToInt(RenderBoundingRect.Right),
			FMath::RoundToInt(RenderBoundingRect.Bottom));

		// All visual parameters are normalised / resolution-independent (squircle works in UV space).
		Params.SquirclePower = SquirclePower;
		Params.BlurStrength = FMath::Max(0.0f, BlurStrength);
		Params.DownsampleAmount = FMath::Clamp(DownsampleAmount, 1, 8);
		Params.RefractionStrength = FMath::Clamp(RefractionStrength, 0.0f, 1.0f);
		Params.RefractionPower = FMath::Max(0.0f, RefractionPower);
		Params.ChromaticAberration = FMath::Max(0.0f, ChromaticAberration);
		Params.NoiseAmount = FMath::Max(0.0f, NoiseAmount);
		Params.GlowAmount = FMath::Max(0.0f, GlowAmount);
		Params.RimIntensity = FMath::Max(0.0f, RimIntensity);

		const float AngleRad = FMath::DegreesToRadians(GlowAngle);
		Params.GlowDir = FVector2f(FMath::Cos(AngleRad), FMath::Sin(AngleRad));

		Params.TintColor = TintColor;
		Params.TintOpacity = FMath::Clamp(TintOpacity, 0.0f, 1.0f);
		Params.Saturation = FMath::Max(0.0f, Saturation);
		Params.AdaptiveTintStrength = FMath::Clamp(AdaptiveTintStrength, 0.0f, 1.0f);
		Params.GlassOpacity = FMath::Clamp(GlassOpacity, 0.0f, 1.0f) * WidgetAlpha;
		Params.EdgeSoftness = FMath::Max(0.1f, EdgeSoftness);
		Params.ShapeMode = static_cast<float>(Shape);
		Params.RefractionThickness = FMath::Max(0.0f, RefractionThickness);
		Params.IndexOfRefraction = FMath::Clamp(IndexOfRefraction, 1.0f, 3.0f);
		Params.FrostRadius = FMath::Max(0.0f, FrostRadius);
		Params.PrismIntensity = FMath::Max(0.0f, PrismIntensity);
		Params.InnerGlowIntensity = FMath::Max(0.0f, InnerGlowIntensity);
		Params.InnerShadowIntensity = FMath::Max(0.0f, InnerShadowIntensity);
		Params.QualityMode = static_cast<float>(Quality);
		Params.MotionVector = MotionVector;
		Params.MotionDeformationStrength = FMath::Max(0.0f, MotionStrength);
		Params.AlphaMaskThreshold = FMath::Clamp(AlphaMaskThreshold, 0.0f, 1.0f);
		Params.AlphaMaskSoftness = FMath::Clamp(AlphaMaskSoftness, 0.001f, 0.5f);
		Params.AlphaMaskInvert = bInvertAlphaMask ? 1.0f : 0.0f;

		if (UTexture2D* MaskTexture = AlphaMaskTexture.Get())
		{
			if (FTextureResource* MaskResource = MaskTexture->GetResource())
			{
				if (MaskResource->TextureRHI.IsValid())
				{
					Params.AlphaMaskTextureRHI = MaskResource->TextureRHI;
					Params.UseAlphaMask = 1.0f;
				}
			}
		}

		if (Params.Rect.Width() > 1 && Params.Rect.Height() > 1)
		{
			GlassElement->SetRenderParams_GameThread(Params);

			// Clip the custom element to the widget geometry. The shader still computes alpha from
			// the shape SDF, but the Slate clip prevents overdraw outside layout bounds.
			OutDrawElements.PushClip(FSlateClippingZone(AllottedGeometry));
			FSlateDrawElement::MakeCustom(OutDrawElements, LayerId, GlassElement);
			OutDrawElements.PopClip();

			// The child must draw after the custom background so labels/icons stay sharp and readable.
			ContentLayerId = LayerId + 1;
		}
	}

	// Paint child content on top of the glass.
	return SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, ContentLayerId, InWidgetStyle, bParentEnabled);
}

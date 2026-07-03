// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassRenderer.h"

#include "GlobalShader.h"
#include "PixelShaderUtils.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "RHIStaticStates.h"
#include "ShaderParameterStruct.h"
#include "RenderGraphResources.h"
#include "RenderingThread.h"

//////////////////////////////////////////////////////////////////////////
// Global shaders

/** 4-tap box downsample. */
class FCBLGDownsamplePS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FCBLGDownsamplePS);
	SHADER_USE_PARAMETER_STRUCT(FCBLGDownsamplePS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, InputTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, InputSampler)
		SHADER_PARAMETER(FVector2f, InvInputSize)
		SHADER_PARAMETER(FVector4f, SvPositionToUV)
		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }
};

/** Separable Gaussian blur (one axis per dispatch). */
class FCBLGBlurPS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FCBLGBlurPS);
	SHADER_USE_PARAMETER_STRUCT(FCBLGBlurPS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, InputTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, InputSampler)
		SHADER_PARAMETER(FVector2f, BlurDirection)
		SHADER_PARAMETER(FVector4f, SvPositionToUV)
		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }
};

/** Final composite: shape alpha, refraction, chromatic aberration, adaptive tint and edge lighting. */
class FCBLGCompositePS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FCBLGCompositePS);
	SHADER_USE_PARAMETER_STRUCT(FCBLGCompositePS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, CapturedTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, CapturedSampler)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, BlurredTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, BlurredSampler)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, AlphaMaskTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, AlphaMaskSampler)
		SHADER_PARAMETER(FVector2f, RectSize)
		SHADER_PARAMETER(float, SquirclePower)
		SHADER_PARAMETER(float, ShapeMode)
		SHADER_PARAMETER(float, RefractionStrength)
		SHADER_PARAMETER(float, RefractionPower)
		SHADER_PARAMETER(float, RefractionThickness)
		SHADER_PARAMETER(float, IndexOfRefraction)
		SHADER_PARAMETER(float, ChromaticAberration)
		SHADER_PARAMETER(float, PrismIntensity)
		SHADER_PARAMETER(float, NoiseAmount)
		SHADER_PARAMETER(float, FrostRadius)
		SHADER_PARAMETER(float, BlurStrength)
		SHADER_PARAMETER(float, GlowAmount)
		SHADER_PARAMETER(float, RimIntensity)
		SHADER_PARAMETER(float, InnerGlowIntensity)
		SHADER_PARAMETER(float, InnerShadowIntensity)
		SHADER_PARAMETER(FVector2f, GlowDir)
		SHADER_PARAMETER(FLinearColor, TintColor)
		SHADER_PARAMETER(float, TintOpacity)
		SHADER_PARAMETER(float, Saturation)
		SHADER_PARAMETER(float, AdaptiveTintStrength)
		SHADER_PARAMETER(float, GlassOpacity)
		SHADER_PARAMETER(float, EdgeSoftness)
		SHADER_PARAMETER(FVector2f, MotionVector)
		SHADER_PARAMETER(float, MotionDeformationStrength)
		SHADER_PARAMETER(float, UseAlphaMask)
		SHADER_PARAMETER(float, AlphaMaskThreshold)
		SHADER_PARAMETER(float, AlphaMaskSoftness)
		SHADER_PARAMETER(float, AlphaMaskInvert)
		SHADER_PARAMETER(FVector4f, SvPositionToUV)
		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }
};

IMPLEMENT_GLOBAL_SHADER(FCBLGDownsamplePS, "/Plugin/CBLiquidGlass/Private/CBLiquidGlass.usf", "DownsamplePS", SF_Pixel);
IMPLEMENT_GLOBAL_SHADER(FCBLGBlurPS, "/Plugin/CBLiquidGlass/Private/CBLiquidGlass.usf", "BlurPS", SF_Pixel);
IMPLEMENT_GLOBAL_SHADER(FCBLGCompositePS, "/Plugin/CBLiquidGlass/Private/CBLiquidGlass.usf", "CompositePS", SF_Pixel);

//////////////////////////////////////////////////////////////////////////
// FCBLiquidGlassSlateElement

void FCBLiquidGlassSlateElement::SetRenderParams_GameThread(const FCBLiquidGlassRenderParams& InParams)
{
	// ICustomSlateElement::Draw_RenderThread reads RenderThreadParams on the render thread only.
	// Copy the small POD-like struct through the render command queue to avoid data races.
	FCBLiquidGlassSlateElement* Self = this;
	FCBLiquidGlassRenderParams Params = InParams;
	ENQUEUE_RENDER_COMMAND(CBLG_SetParams)(
		[Self, Params](FRHICommandListImmediate&)
		{
			Self->RenderThreadParams = Params;
		});
}

void FCBLiquidGlassSlateElement::Draw_RenderThread(FRDGBuilder& GraphBuilder, const FDrawPassInputs& Inputs)
{
	FRDGTextureRef Output = Inputs.OutputTexture;
	if (!Output)
	{
		return;
	}

	const FCBLiquidGlassRenderParams& P = RenderThreadParams;

	// Clamp the glass rect to the output texture bounds.
	const FIntPoint OutExtent = Output->Desc.Extent;
	FIntRect Rect = P.Rect;
	Rect.Min.X = FMath::Clamp(Rect.Min.X, 0, OutExtent.X);
	Rect.Min.Y = FMath::Clamp(Rect.Min.Y, 0, OutExtent.Y);
	Rect.Max.X = FMath::Clamp(Rect.Max.X, 0, OutExtent.X);
	Rect.Max.Y = FMath::Clamp(Rect.Max.Y, 0, OutExtent.Y);

	const FIntPoint RectSize = Rect.Size();
	if (RectSize.X <= 1 || RectSize.Y <= 1)
	{
		return;
	}

	RDG_EVENT_SCOPE(GraphBuilder, "CBLiquidGlass");

	const FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	FRHISamplerState* BilinearClamp = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
	const EPixelFormat Format = Output->Desc.Format;

	// 1) Capture the output region behind the widget. This is the sharp source used by clear glass
	//    and also the input for the cheaper downsampled blur chain.
	FRDGTextureDesc CapturedDesc = FRDGTextureDesc::Create2D(
		RectSize, Format, FClearValueBinding::None,
		TexCreate_ShaderResource | TexCreate_RenderTargetable);
	FRDGTextureRef Captured = GraphBuilder.CreateTexture(CapturedDesc, TEXT("CBLG.Captured"));

	{
		FRHICopyTextureInfo CopyInfo;
		CopyInfo.Size = FIntVector(RectSize.X, RectSize.Y, 1);
		CopyInfo.SourcePosition = FIntVector(Rect.Min.X, Rect.Min.Y, 0);
		CopyInfo.DestPosition = FIntVector(0, 0, 0);
		AddCopyTexturePass(GraphBuilder, Output, Captured, CopyInfo);
	}

	// 2) Downsample for cheap blur. The downsample amount trades detail for cost and softness.
	const int32 RequestedDS = FMath::Clamp(P.DownsampleAmount, 1, 8);
	const int32 QualityMode = FMath::RoundToInt(FMath::Clamp(P.QualityMode, 0.0f, 2.0f));
	const int32 DS = QualityMode == 0
		? FMath::Max(RequestedDS, 4)
		: (QualityMode == 2 ? FMath::Max(1, FMath::Min(RequestedDS, 2)) : RequestedDS);
	const FIntPoint SmallSize(FMath::Max(1, RectSize.X / DS), FMath::Max(1, RectSize.Y / DS));

	// SV_Position -> [0,1] UV for the small render targets (their viewport min is 0,0).
	const FVector4f SmallSvToUV(1.0f / SmallSize.X, 1.0f / SmallSize.Y, 0.0f, 0.0f);

	FRDGTextureDesc SmallDesc = FRDGTextureDesc::Create2D(
		SmallSize, Format, FClearValueBinding::None,
		TexCreate_ShaderResource | TexCreate_RenderTargetable);

	FRDGTextureRef Downsampled = GraphBuilder.CreateTexture(SmallDesc, TEXT("CBLG.Downsampled"));
	{
		FCBLGDownsamplePS::FParameters* Params = GraphBuilder.AllocParameters<FCBLGDownsamplePS::FParameters>();
		Params->InputTexture = Captured;
		Params->InputSampler = BilinearClamp;
		Params->InvInputSize = FVector2f(1.0f / RectSize.X, 1.0f / RectSize.Y);
		Params->SvPositionToUV = SmallSvToUV;
		Params->RenderTargets[0] = FRenderTargetBinding(Downsampled, ERenderTargetLoadAction::ENoAction);

		TShaderMapRef<FCBLGDownsamplePS> PixelShader(GlobalShaderMap);
		FPixelShaderUtils::AddFullscreenPass(
			GraphBuilder, GlobalShaderMap, RDG_EVENT_NAME("CBLG.Downsample"),
			PixelShader, Params, FIntRect(0, 0, SmallSize.X, SmallSize.Y));
	}

	// 3) Separable Gaussian blur (horizontal then vertical). A two-pass blur keeps the sample count
	//    linear instead of quadratic while still producing a frosted background.
	FRDGTextureRef BlurH = GraphBuilder.CreateTexture(SmallDesc, TEXT("CBLG.BlurH"));
	{
		FCBLGBlurPS::FParameters* Params = GraphBuilder.AllocParameters<FCBLGBlurPS::FParameters>();
		Params->InputTexture = Downsampled;
		Params->InputSampler = BilinearClamp;
		Params->BlurDirection = FVector2f(P.BlurStrength / SmallSize.X, 0.0f);
		Params->SvPositionToUV = SmallSvToUV;
		Params->RenderTargets[0] = FRenderTargetBinding(BlurH, ERenderTargetLoadAction::ENoAction);

		TShaderMapRef<FCBLGBlurPS> PixelShader(GlobalShaderMap);
		FPixelShaderUtils::AddFullscreenPass(
			GraphBuilder, GlobalShaderMap, RDG_EVENT_NAME("CBLG.BlurH"),
			PixelShader, Params, FIntRect(0, 0, SmallSize.X, SmallSize.Y));
	}

	FRDGTextureRef BlurV = GraphBuilder.CreateTexture(SmallDesc, TEXT("CBLG.BlurV"));
	{
		FCBLGBlurPS::FParameters* Params = GraphBuilder.AllocParameters<FCBLGBlurPS::FParameters>();
		Params->InputTexture = BlurH;
		Params->InputSampler = BilinearClamp;
		Params->BlurDirection = FVector2f(0.0f, P.BlurStrength / SmallSize.Y);
		Params->SvPositionToUV = SmallSvToUV;
		Params->RenderTargets[0] = FRenderTargetBinding(BlurV, ERenderTargetLoadAction::ENoAction);

		TShaderMapRef<FCBLGBlurPS> PixelShader(GlobalShaderMap);
		FPixelShaderUtils::AddFullscreenPass(
			GraphBuilder, GlobalShaderMap, RDG_EVENT_NAME("CBLG.BlurV"),
			PixelShader, Params, FIntRect(0, 0, SmallSize.X, SmallSize.Y));
	}

	// 4) Composite the liquid glass back into the output texture, only within the glass rect.
	//    The shader samples both Captured and BlurV so presets can keep clear centers while using
	//    frost and prism highlights near the edge.
	{
		FRDGTextureRef AlphaMaskTexture = Captured;
		if (P.UseAlphaMask > 0.5f && P.AlphaMaskTextureRHI.IsValid())
		{
			AlphaMaskTexture = RegisterExternalTexture(GraphBuilder, P.AlphaMaskTextureRHI.GetReference(), TEXT("CBLG.AlphaMask"));
		}

		FCBLGCompositePS::FParameters* Params = GraphBuilder.AllocParameters<FCBLGCompositePS::FParameters>();
		Params->CapturedTexture = Captured;
		Params->CapturedSampler = BilinearClamp;
		Params->BlurredTexture = BlurV;
		Params->BlurredSampler = BilinearClamp;
		Params->AlphaMaskTexture = AlphaMaskTexture;
		Params->AlphaMaskSampler = BilinearClamp;
		Params->RectSize = FVector2f((float)RectSize.X, (float)RectSize.Y);
		Params->SquirclePower = FMath::Max(2.0f, P.SquirclePower);
		Params->ShapeMode = FMath::Clamp(P.ShapeMode, 0.0f, 6.0f);
		Params->RefractionStrength = FMath::Clamp(P.RefractionStrength, 0.0f, 1.0f);
		Params->RefractionPower = FMath::Max(0.0f, P.RefractionPower);
		Params->RefractionThickness = FMath::Max(0.0f, P.RefractionThickness);
		Params->IndexOfRefraction = FMath::Clamp(P.IndexOfRefraction, 1.0f, 3.0f);
		Params->ChromaticAberration = FMath::Max(0.0f, P.ChromaticAberration);
		Params->PrismIntensity = FMath::Max(0.0f, P.PrismIntensity) * (QualityMode == 0 ? 0.45f : 1.0f);
		Params->NoiseAmount = FMath::Max(0.0f, P.NoiseAmount);
		Params->FrostRadius = FMath::Max(0.0f, P.FrostRadius);
		Params->BlurStrength = FMath::Max(0.0f, P.BlurStrength);
		Params->GlowAmount = FMath::Max(0.0f, P.GlowAmount);
		Params->RimIntensity = FMath::Max(0.0f, P.RimIntensity);
		Params->InnerGlowIntensity = FMath::Max(0.0f, P.InnerGlowIntensity);
		Params->InnerShadowIntensity = FMath::Max(0.0f, P.InnerShadowIntensity);
		Params->GlowDir = P.GlowDir.GetSafeNormal();
		Params->TintColor = P.TintColor;
		Params->TintOpacity = P.TintOpacity;
		Params->Saturation = FMath::Max(0.0f, P.Saturation);
		Params->AdaptiveTintStrength = P.AdaptiveTintStrength;
		Params->GlassOpacity = P.GlassOpacity;
		Params->EdgeSoftness = FMath::Max(0.1f, P.EdgeSoftness);
		Params->MotionVector = P.MotionVector;
		Params->MotionDeformationStrength = FMath::Max(0.0f, P.MotionDeformationStrength);
		Params->UseAlphaMask = P.UseAlphaMask;
		Params->AlphaMaskThreshold = FMath::Clamp(P.AlphaMaskThreshold, 0.0f, 1.0f);
		Params->AlphaMaskSoftness = FMath::Clamp(P.AlphaMaskSoftness, 0.001f, 0.5f);
		Params->AlphaMaskInvert = P.AlphaMaskInvert;
		// SV_Position is in output-texture pixels; remap to [0,1] across the glass rect (viewport min = Rect.Min).
		Params->SvPositionToUV = FVector4f(
			1.0f / RectSize.X, 1.0f / RectSize.Y,
			-(float)Rect.Min.X / RectSize.X, -(float)Rect.Min.Y / RectSize.Y);
		Params->RenderTargets[0] = FRenderTargetBinding(Output, ERenderTargetLoadAction::ELoad);

		TShaderMapRef<FCBLGCompositePS> PixelShader(GlobalShaderMap);
		// Source alpha is produced by the shape mask and GlassOpacity; destination alpha is preserved.
		FRHIBlendState* AlphaBlend = TStaticBlendState<CW_RGB, BO_Add, BF_SourceAlpha, BF_InverseSourceAlpha, BO_Add, BF_Zero, BF_One>::GetRHI();

		FPixelShaderUtils::AddFullscreenPass(
			GraphBuilder, GlobalShaderMap, RDG_EVENT_NAME("CBLG.Composite"),
			PixelShader, Params, Rect, AlphaBlend);
	}
}

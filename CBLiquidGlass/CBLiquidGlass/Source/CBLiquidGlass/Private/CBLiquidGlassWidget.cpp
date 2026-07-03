// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassWidget.h"
#include "CBLiquidGlassSlot.h"
#include "CBLiquidGlassRecipes.h"
#include "SCBLiquidGlass.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlass"

namespace
{
	/** Returns true for properties that visually define the glass and should detach from presets when edited. */
	bool IsLiquidGlassVisualProperty(FName PropertyName)
	{
		return PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, BlurStrength)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, DownsampleAmount)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, FrostRadius)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, Shape)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, SquirclePower)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, EdgeSoftness)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, AlphaMaskTexture)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, AlphaMaskThreshold)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, AlphaMaskSoftness)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, InvertAlphaMask)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, RefractionStrength)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, RefractionPower)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, RefractionThickness)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, IndexOfRefraction)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, ChromaticAberration)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, PrismIntensity)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, NoiseAmount)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, GlowAmount)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, RimIntensity)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, GlowAngle)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, InnerGlowIntensity)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, InnerShadowIntensity)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, TintColor)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, TintOpacity)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, Saturation)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, AdaptiveTintStrength)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, GlassOpacity)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, Quality)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, MotionStrength)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, MotionMaxOffset)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, MotionResponse)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, MotionDamping);
	}
}

UCBLiquidGlass::UCBLiquidGlass()
{
	// The widget behaves like a visual container; Blueprint users usually interact with its child.
	bIsVariable = false;

	// Let child widgets receive input while this container still paints its custom background.
	SetVisibilityInternal(ESlateVisibility::SelfHitTestInvisible);
}

UClass* UCBLiquidGlass::GetSlotClass() const
{
	return UCBLiquidGlassSlot::StaticClass();
}

void UCBLiquidGlass::OnSlotAdded(UPanelSlot* InSlot)
{
	if (MyGlass.IsValid())
	{
		if (UCBLiquidGlassSlot* GlassSlot = Cast<UCBLiquidGlassSlot>(InSlot))
		{
			GlassSlot->BuildSlot(MyGlass.ToSharedRef());
		}
	}
}

void UCBLiquidGlass::OnSlotRemoved(UPanelSlot* InSlot)
{
	if (MyGlass.IsValid())
	{
		MyGlass->SetContent(SNullWidget::NullWidget);
	}
}

TSharedRef<SWidget> UCBLiquidGlass::RebuildWidget()
{
	// Recreate the Slate widget with the current UPROPERTY values. SynchronizeProperties handles
	// subsequent editor/runtime changes after the Slate object exists.
	MyGlass = SNew(SCBLiquidGlass)
		.Shape(Shape)
		.SquirclePower(SquirclePower)
		.BlurStrength(BlurStrength)
		.DownsampleAmount(DownsampleAmount)
		.FrostRadius(FrostRadius)
		.RefractionStrength(RefractionStrength)
		.RefractionPower(RefractionPower)
		.RefractionThickness(RefractionThickness)
		.IndexOfRefraction(IndexOfRefraction)
		.ChromaticAberration(ChromaticAberration)
		.PrismIntensity(PrismIntensity)
		.NoiseAmount(NoiseAmount)
		.GlowAmount(GlowAmount)
		.RimIntensity(RimIntensity)
		.GlowAngle(GlowAngle)
		.InnerGlowIntensity(InnerGlowIntensity)
		.InnerShadowIntensity(InnerShadowIntensity)
		.TintColor(TintColor)
		.TintOpacity(TintOpacity)
		.Saturation(Saturation)
		.AdaptiveTintStrength(AdaptiveTintStrength)
		.GlassOpacity(GlassOpacity)
		.EdgeSoftness(EdgeSoftness)
		.AlphaMaskTexture(AlphaMaskTexture)
		.AlphaMaskThreshold(AlphaMaskThreshold)
		.AlphaMaskSoftness(AlphaMaskSoftness)
		.bInvertAlphaMask(InvertAlphaMask)
		.Quality(Quality)
		.MotionStrength(MotionStrength)
		.MotionMaxOffset(MotionMaxOffset)
		.MotionResponse(MotionResponse)
		.MotionDamping(MotionDamping);

	if (UCBLiquidGlassSlot* GlassSlot = Cast<UCBLiquidGlassSlot>(GetContentSlot()))
	{
		GlassSlot->BuildSlot(MyGlass.ToSharedRef());
	}

	return MyGlass.ToSharedRef();
}

void UCBLiquidGlass::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	// During design-time rebuilds the UWidget may synchronize before its Slate counterpart exists.
	if (!MyGlass.IsValid())
	{
		return;
	}

	PushPropertiesToSlate();
}

void UCBLiquidGlass::PushPropertiesToSlate()
{
	if (!MyGlass.IsValid())
	{
		return;
	}

	// Keep this list in lockstep with RebuildWidget so editor edits and runtime setters behave the same.
	MyGlass->SetShape(Shape);
	MyGlass->SetSquirclePower(SquirclePower);
	MyGlass->SetBlurStrength(BlurStrength);
	MyGlass->SetDownsampleAmount(DownsampleAmount);
	MyGlass->SetFrostRadius(FrostRadius);
	MyGlass->SetRefractionStrength(RefractionStrength);
	MyGlass->SetRefractionPower(RefractionPower);
	MyGlass->SetRefractionThickness(RefractionThickness);
	MyGlass->SetIndexOfRefraction(IndexOfRefraction);
	MyGlass->SetChromaticAberration(ChromaticAberration);
	MyGlass->SetPrismIntensity(PrismIntensity);
	MyGlass->SetNoiseAmount(NoiseAmount);
	MyGlass->SetGlowAmount(GlowAmount);
	MyGlass->SetRimIntensity(RimIntensity);
	MyGlass->SetGlowAngle(GlowAngle);
	MyGlass->SetInnerGlowIntensity(InnerGlowIntensity);
	MyGlass->SetInnerShadowIntensity(InnerShadowIntensity);
	MyGlass->SetTintColor(TintColor);
	MyGlass->SetTintOpacity(TintOpacity);
	MyGlass->SetSaturation(Saturation);
	MyGlass->SetAdaptiveTintStrength(AdaptiveTintStrength);
	MyGlass->SetGlassOpacity(GlassOpacity);
	MyGlass->SetEdgeSoftness(EdgeSoftness);
	MyGlass->SetAlphaMaskTexture(AlphaMaskTexture);
	MyGlass->SetAlphaMaskThreshold(AlphaMaskThreshold);
	MyGlass->SetAlphaMaskSoftness(AlphaMaskSoftness);
	MyGlass->SetInvertAlphaMask(InvertAlphaMask);
	MyGlass->SetQuality(Quality);
	MyGlass->SetMotionStrength(MotionStrength);
	MyGlass->SetMotionMaxOffset(MotionMaxOffset);
	MyGlass->SetMotionResponse(MotionResponse);
	MyGlass->SetMotionDamping(MotionDamping);
}

void UCBLiquidGlass::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MyGlass.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlass::GetPaletteCategory()
{
	return LOCTEXT("LiquidGlassPaletteCategory", "Liquid Glass");
}

void UCBLiquidGlass::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const FName PropertyName = PropertyChangedEvent.GetPropertyName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UCBLiquidGlass, Preset))
	{
		// Choosing a preset writes a snapshot of values into the visible properties.
		ApplyPresetProperties(Preset);
	}
	else if (IsLiquidGlassVisualProperty(PropertyName))
	{
		// Any direct parameter edit means the user is now tuning manually.
		MarkPresetCustom();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

//////////////////////////////////////////////////////////////////////////
// Setters

void UCBLiquidGlass::MarkPresetCustom()
{
	if (Preset != ECBLiquidGlassPreset::Custom)
	{
		Preset = ECBLiquidGlassPreset::Custom;
	}
}

void UCBLiquidGlass::ApplyPresetProperties(ECBLiquidGlassPreset InPreset)
{
	if (InPreset == ECBLiquidGlassPreset::Custom)
	{
		// Custom leaves every visual property under manual control.
		return;
	}

	// Presets share a single source of truth with the Slate controls; see CBLiquidGlassRecipes.
	// Selecting a preset copies a full snapshot into the editable properties (it is not live-linked).
	const FCBLiquidGlassRecipe Recipe = CBLiquidGlassRecipes::ForPreset(InPreset);
	Shape = Recipe.Shape;
	BlurStrength = Recipe.BlurStrength;
	DownsampleAmount = Recipe.DownsampleAmount;
	FrostRadius = Recipe.FrostRadius;
	SquirclePower = Recipe.SquirclePower;
	EdgeSoftness = Recipe.EdgeSoftness;
	RefractionStrength = Recipe.RefractionStrength;
	RefractionPower = Recipe.RefractionPower;
	RefractionThickness = Recipe.RefractionThickness;
	IndexOfRefraction = Recipe.IndexOfRefraction;
	ChromaticAberration = Recipe.ChromaticAberration;
	PrismIntensity = Recipe.PrismIntensity;
	NoiseAmount = Recipe.NoiseAmount;
	GlowAmount = Recipe.GlowAmount;
	RimIntensity = Recipe.RimIntensity;
	GlowAngle = Recipe.GlowAngle;
	InnerGlowIntensity = Recipe.InnerGlowIntensity;
	InnerShadowIntensity = Recipe.InnerShadowIntensity;
	TintColor = Recipe.TintColor;
	TintOpacity = Recipe.TintOpacity;
	Saturation = Recipe.Saturation;
	AdaptiveTintStrength = Recipe.AdaptiveTintStrength;
	GlassOpacity = Recipe.GlassOpacity;
	Quality = Recipe.Quality;
	MotionStrength = Recipe.MotionStrength;
	MotionMaxOffset = Recipe.MotionMaxOffset;
	MotionResponse = Recipe.MotionResponse;
	MotionDamping = Recipe.MotionDamping;
}

void UCBLiquidGlass::SetPreset(ECBLiquidGlassPreset InValue)
{
	// Runtime preset changes behave like editor preset changes: copy values, then push once.
	Preset = InValue;
	ApplyPresetProperties(InValue);
	PushPropertiesToSlate();
}

#define CBLG_WIDGET_SETTER(MemberName, ParamType) \
	void UCBLiquidGlass::Set##MemberName(ParamType InValue) \
	{ \
		/* Setters represent manual tuning, so keep Preset honest for Blueprints and details panels. */ \
		MarkPresetCustom(); \
		MemberName = InValue; \
		if (MyGlass.IsValid()) \
		{ \
			MyGlass->Set##MemberName(InValue); \
		} \
	}

CBLG_WIDGET_SETTER(BlurStrength, float)
CBLG_WIDGET_SETTER(DownsampleAmount, int32)
CBLG_WIDGET_SETTER(FrostRadius, float)
CBLG_WIDGET_SETTER(Shape, ECBLiquidGlassShape)
CBLG_WIDGET_SETTER(SquirclePower, float)
CBLG_WIDGET_SETTER(EdgeSoftness, float)
CBLG_WIDGET_SETTER(AlphaMaskThreshold, float)
CBLG_WIDGET_SETTER(AlphaMaskSoftness, float)
CBLG_WIDGET_SETTER(RefractionStrength, float)
CBLG_WIDGET_SETTER(RefractionPower, float)
CBLG_WIDGET_SETTER(RefractionThickness, float)
CBLG_WIDGET_SETTER(IndexOfRefraction, float)
CBLG_WIDGET_SETTER(ChromaticAberration, float)
CBLG_WIDGET_SETTER(PrismIntensity, float)
CBLG_WIDGET_SETTER(NoiseAmount, float)
CBLG_WIDGET_SETTER(GlowAmount, float)
CBLG_WIDGET_SETTER(RimIntensity, float)
CBLG_WIDGET_SETTER(GlowAngle, float)
CBLG_WIDGET_SETTER(InnerGlowIntensity, float)
CBLG_WIDGET_SETTER(InnerShadowIntensity, float)
CBLG_WIDGET_SETTER(TintColor, FLinearColor)
CBLG_WIDGET_SETTER(TintOpacity, float)
CBLG_WIDGET_SETTER(Saturation, float)
CBLG_WIDGET_SETTER(AdaptiveTintStrength, float)
CBLG_WIDGET_SETTER(GlassOpacity, float)
CBLG_WIDGET_SETTER(Quality, ECBLiquidGlassQuality)
CBLG_WIDGET_SETTER(MotionStrength, float)
CBLG_WIDGET_SETTER(MotionMaxOffset, float)
CBLG_WIDGET_SETTER(MotionResponse, float)
CBLG_WIDGET_SETTER(MotionDamping, float)

#undef CBLG_WIDGET_SETTER

void UCBLiquidGlass::SetAlphaMaskTexture(UTexture2D* InTexture)
{
	MarkPresetCustom();
	AlphaMaskTexture = InTexture;
	if (MyGlass.IsValid())
	{
		MyGlass->SetAlphaMaskTexture(InTexture);
	}
}

void UCBLiquidGlass::SetInvertAlphaMask(bool bInValue)
{
	MarkPresetCustom();
	InvertAlphaMask = bInValue;
	if (MyGlass.IsValid())
	{
		MyGlass->SetInvertAlphaMask(bInValue);
	}
}

#undef LOCTEXT_NAMESPACE

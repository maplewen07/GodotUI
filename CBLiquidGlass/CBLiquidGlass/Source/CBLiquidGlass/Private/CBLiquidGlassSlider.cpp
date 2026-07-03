// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlassSlider.h"
#include "SCBLiquidGlassSlider.h"

#define LOCTEXT_NAMESPACE "CBLiquidGlassSlider"

UCBLiquidGlassSlider::UCBLiquidGlassSlider()
{
	bIsVariable = true;
}

TSharedRef<SWidget> UCBLiquidGlassSlider::RebuildWidget()
{
	MySlider = SNew(SCBLiquidGlassSlider)
		.Value(Value)
		.MinValue(MinValue)
		.MaxValue(MaxValue)
		.SliderLength(SliderLength)
		.SliderHeight(SliderHeight)
		.TrackHeight(TrackHeight)
		.ThumbSize(ThumbSize)
		.FillColor(FillColor)
		.TrackTint(TrackTint)
		.TrackOpacity(TrackOpacity)
		.ThumbPreset(ThumbPreset)
		.Quality(Quality)
		.ThumbBounce(ThumbBounce)
		.ThumbResponse(ThumbResponse)
		.ThumbDamping(ThumbDamping)
		.ThumbMotionStrength(ThumbMotionStrength)
		.OnValueChanged(FCBLiquidGlassSliderValueChanged::CreateUObject(this, &UCBLiquidGlassSlider::HandleSlateValueChanged));

	return MySlider.ToSharedRef();
}

void UCBLiquidGlassSlider::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	PushPropertiesToSlate();
}

void UCBLiquidGlassSlider::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MySlider.Reset();
}

#if WITH_EDITOR
const FText UCBLiquidGlassSlider::GetPaletteCategory()
{
	return LOCTEXT("LiquidGlassPaletteCategory", "Liquid Glass");
}
#endif

void UCBLiquidGlassSlider::SetValue(float InValue)
{
	Value = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetValue(InValue);
		Value = MySlider->GetValue();
	}
}

void UCBLiquidGlassSlider::SetMinValue(float InValue)
{
	MinValue = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetMinValue(InValue);
		Value = MySlider->GetValue();
	}
}

void UCBLiquidGlassSlider::SetMaxValue(float InValue)
{
	MaxValue = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetMaxValue(InValue);
		Value = MySlider->GetValue();
	}
}

void UCBLiquidGlassSlider::SetSliderLength(float InValue)
{
	SliderLength = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetSliderLength(InValue);
	}
}

void UCBLiquidGlassSlider::SetSliderHeight(float InValue)
{
	SliderHeight = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetSliderHeight(InValue);
	}
}

void UCBLiquidGlassSlider::SetTrackHeight(float InValue)
{
	TrackHeight = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetTrackHeight(InValue);
	}
}

void UCBLiquidGlassSlider::SetThumbSize(FVector2D InValue)
{
	ThumbSize = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetThumbSize(InValue);
	}
}

void UCBLiquidGlassSlider::SetFillColor(FLinearColor InValue)
{
	FillColor = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetFillColor(InValue);
	}
}

void UCBLiquidGlassSlider::SetTrackTint(FLinearColor InValue)
{
	TrackTint = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetTrackTint(InValue);
	}
}

void UCBLiquidGlassSlider::SetTrackOpacity(float InValue)
{
	TrackOpacity = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetTrackOpacity(InValue);
	}
}

void UCBLiquidGlassSlider::SetThumbPreset(ECBLiquidGlassPreset InValue)
{
	ThumbPreset = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetThumbPreset(InValue);
	}
}

void UCBLiquidGlassSlider::SetQuality(ECBLiquidGlassQuality InValue)
{
	Quality = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetQuality(InValue);
	}
}

void UCBLiquidGlassSlider::SetThumbBounce(float InValue)
{
	ThumbBounce = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetThumbBounce(InValue);
	}
}

void UCBLiquidGlassSlider::SetThumbResponse(float InValue)
{
	ThumbResponse = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetThumbResponse(InValue);
	}
}

void UCBLiquidGlassSlider::SetThumbDamping(float InValue)
{
	ThumbDamping = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetThumbDamping(InValue);
	}
}

void UCBLiquidGlassSlider::SetThumbMotionStrength(float InValue)
{
	ThumbMotionStrength = InValue;
	if (MySlider.IsValid())
	{
		MySlider->SetThumbMotionStrength(InValue);
	}
}

void UCBLiquidGlassSlider::HandleSlateValueChanged(float InValue)
{
	Value = InValue;
	OnValueChanged.Broadcast(Value);
}

void UCBLiquidGlassSlider::PushPropertiesToSlate()
{
	if (!MySlider.IsValid())
	{
		return;
	}

	MySlider->SetMinValue(MinValue);
	MySlider->SetMaxValue(MaxValue);
	MySlider->SetValue(Value);
	MySlider->SetSliderLength(SliderLength);
	MySlider->SetSliderHeight(SliderHeight);
	MySlider->SetTrackHeight(TrackHeight);
	MySlider->SetThumbSize(ThumbSize);
	MySlider->SetFillColor(FillColor);
	MySlider->SetTrackTint(TrackTint);
	MySlider->SetTrackOpacity(TrackOpacity);
	MySlider->SetThumbPreset(ThumbPreset);
	MySlider->SetQuality(Quality);
	MySlider->SetThumbBounce(ThumbBounce);
	MySlider->SetThumbResponse(ThumbResponse);
	MySlider->SetThumbDamping(ThumbDamping);
	MySlider->SetThumbMotionStrength(ThumbMotionStrength);
	MySlider->SetOnValueChanged(FCBLiquidGlassSliderValueChanged::CreateUObject(this, &UCBLiquidGlassSlider::HandleSlateValueChanged));
	Value = MySlider->GetValue();
}

#undef LOCTEXT_NAMESPACE

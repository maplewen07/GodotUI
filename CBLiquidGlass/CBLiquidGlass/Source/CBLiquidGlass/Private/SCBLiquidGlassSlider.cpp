// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "SCBLiquidGlassSlider.h"
#include "SCBLiquidGlass.h"

#include "Input/Events.h"
#include "InputCoreTypes.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Colors/SColorBlock.h"

void SCBLiquidGlassSlider::Construct(const FArguments& InArgs)
{
	Value = InArgs._Value;
	MinValue = InArgs._MinValue;
	MaxValue = InArgs._MaxValue;
	SliderLength = InArgs._SliderLength;
	SliderHeight = InArgs._SliderHeight;
	TrackHeight = InArgs._TrackHeight;
	ThumbSize = InArgs._ThumbSize;
	FillColor = InArgs._FillColor;
	TrackTint = InArgs._TrackTint;
	TrackOpacity = InArgs._TrackOpacity;
	ThumbPreset = InArgs._ThumbPreset;
	Quality = InArgs._Quality;
	ThumbBounce = InArgs._ThumbBounce;
	ThumbResponse = InArgs._ThumbResponse;
	ThumbDamping = InArgs._ThumbDamping;
	ThumbMotionStrength = InArgs._ThumbMotionStrength;
	OnValueChanged = InArgs._OnValueChanged;

	if (MaxValue < MinValue)
	{
		Swap(MinValue, MaxValue);
	}
	Value = FMath::Clamp(Value, MinValue, MaxValue);
	ResetVisualIfNeeded();
	RebuildLayout();
}

void SCBLiquidGlassSlider::SetValue(float InValue)
{
	CommitValue(InValue, false);
}

void SCBLiquidGlassSlider::SetMinValue(float InValue)
{
	MinValue = InValue;
	if (MaxValue < MinValue)
	{
		MaxValue = MinValue;
	}
	CommitValue(Value, false);
}

void SCBLiquidGlassSlider::SetMaxValue(float InValue)
{
	MaxValue = InValue;
	if (MinValue > MaxValue)
	{
		MinValue = MaxValue;
	}
	CommitValue(Value, false);
}

void SCBLiquidGlassSlider::SetSliderLength(float InValue)
{
	SliderLength = FMath::Max(InValue, 32.0f);
	RebuildLayout();
}

void SCBLiquidGlassSlider::SetSliderHeight(float InValue)
{
	SliderHeight = FMath::Max(InValue, 12.0f);
	RebuildLayout();
}

void SCBLiquidGlassSlider::SetTrackHeight(float InValue)
{
	TrackHeight = FMath::Clamp(InValue, 2.0f, SliderHeight);
	RebuildLayout();
}

void SCBLiquidGlassSlider::SetThumbSize(FVector2D InValue)
{
	ThumbSize = FVector2D(FMath::Max(InValue.X, 20.0f), FMath::Max(InValue.Y, 16.0f));
	RebuildLayout();
}

void SCBLiquidGlassSlider::SetFillColor(FLinearColor InValue)
{
	FillColor = InValue;
	if (FillGlass.IsValid())
	{
		FillGlass->SetTintColor(FillColor);
	}
	Invalidate(EInvalidateWidgetReason::Paint);
}

void SCBLiquidGlassSlider::SetTrackTint(FLinearColor InValue)
{
	TrackTint = InValue;
	if (TrackGlass.IsValid())
	{
		TrackGlass->SetTintColor(TrackTint);
	}
}

void SCBLiquidGlassSlider::SetTrackOpacity(float InValue)
{
	TrackOpacity = FMath::Clamp(InValue, 0.0f, 1.0f);
	if (TrackGlass.IsValid())
	{
		TrackGlass->SetGlassOpacity(TrackOpacity);
	}
}

void SCBLiquidGlassSlider::SetThumbPreset(ECBLiquidGlassPreset InValue)
{
	ThumbPreset = InValue;
	ApplyThumbStyle();
}

void SCBLiquidGlassSlider::SetQuality(ECBLiquidGlassQuality InValue)
{
	Quality = InValue;
	if (TrackGlass.IsValid())
	{
		TrackGlass->SetQuality(Quality);
	}
	if (FillGlass.IsValid())
	{
		FillGlass->SetQuality(Quality);
	}
	if (ThumbGlass.IsValid())
	{
		ThumbGlass->SetQuality(Quality);
	}
}

void SCBLiquidGlassSlider::SetThumbBounce(float InValue)
{
	ThumbBounce = FMath::Clamp(InValue, 0.0f, 4.0f);
}

void SCBLiquidGlassSlider::SetThumbResponse(float InValue)
{
	ThumbResponse = FMath::Clamp(InValue, 1.0f, 60.0f);
}

void SCBLiquidGlassSlider::SetThumbDamping(float InValue)
{
	ThumbDamping = FMath::Clamp(InValue, 0.0f, 40.0f);
}

void SCBLiquidGlassSlider::SetThumbMotionStrength(float InValue)
{
	ThumbMotionStrength = FMath::Clamp(InValue, 0.0f, 3.0f);
	if (ThumbGlass.IsValid())
	{
		ThumbGlass->SetMotionStrength(ThumbMotionStrength);
	}
}

void SCBLiquidGlassSlider::SetOnValueChanged(FCBLiquidGlassSliderValueChanged InDelegate)
{
	OnValueChanged = MoveTemp(InDelegate);
}

FVector2D SCBLiquidGlassSlider::ComputeDesiredSize(float) const
{
	return FVector2D(FMath::Max(SliderLength, 32.0f), FMath::Max(SliderHeight, TrackHeight));
}

void SCBLiquidGlassSlider::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	ResetVisualIfNeeded();

	const float DeltaTime = FMath::Clamp(InDeltaTime, 0.0f, 1.0f / 30.0f);
	if (DeltaTime <= 0.0f)
	{
		return;
	}

	const float Target = GetNormalizedValue();
	const float PreviousVisualValue = VisualNormalizedValue;
	const float PreviousVisualVelocity = VisualVelocity;
	const float Response = FMath::Max(ThumbResponse, 1.0f);
	const float DampingRatio = FMath::Clamp(ThumbDamping / 10.0f, 0.35f, 2.25f);
	float RemainingTime = DeltaTime;
	while (RemainingTime > 0.0f)
	{
		const float StepTime = FMath::Min(RemainingTime, 1.0f / 120.0f);
		const float SpringForce = (Target - VisualNormalizedValue) * Response * Response;
		const float DampingForce = 2.0f * Response * DampingRatio * VisualVelocity;
		VisualVelocity += (SpringForce - DampingForce) * StepTime;
		VisualNormalizedValue += VisualVelocity * StepTime;
		RemainingTime -= StepTime;
	}

	if (!bDragging && FMath::Abs(Target - VisualNormalizedValue) < 0.0005f && FMath::Abs(VisualVelocity) < 0.0005f)
	{
		VisualNormalizedValue = Target;
		VisualVelocity = 0.0f;
	}

	VisualNormalizedValue = FMath::Clamp(VisualNormalizedValue, -0.08f, 1.08f);

	const bool bNeedsVisualUpdate =
		bDragging
		|| !FMath::IsNearlyEqual(PreviousVisualValue, VisualNormalizedValue, 0.0005f)
		|| !FMath::IsNearlyEqual(PreviousVisualVelocity, VisualVelocity, 0.0005f)
		|| !FMath::IsNearlyEqual(Target, VisualNormalizedValue, 0.0005f);

	if (bNeedsVisualUpdate)
	{
		Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
	}
}

FReply SCBLiquidGlassSlider::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (IsEnabled() && MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		bDragging = true;
		UpdateValueFromPointer(MyGeometry, MouseEvent.GetScreenSpacePosition());
		return FReply::Handled().CaptureMouse(SharedThis(this));
	}

	return FReply::Unhandled();
}

FReply SCBLiquidGlassSlider::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (bDragging && HasMouseCapture())
	{
		UpdateValueFromPointer(MyGeometry, MouseEvent.GetScreenSpacePosition());
		return FReply::Handled();
	}

	return FReply::Unhandled();
}

FReply SCBLiquidGlassSlider::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && HasMouseCapture())
	{
		UpdateValueFromPointer(MyGeometry, MouseEvent.GetScreenSpacePosition());
		bDragging = false;
		return FReply::Handled().ReleaseMouseCapture();
	}

	return FReply::Unhandled();
}

void SCBLiquidGlassSlider::OnMouseCaptureLost(const FCaptureLostEvent&)
{
	bDragging = false;
}

void SCBLiquidGlassSlider::RebuildLayout()
{
	SliderLength = FMath::Max(SliderLength, 32.0f);
	SliderHeight = FMath::Max(SliderHeight, 12.0f);
	TrackHeight = FMath::Clamp(TrackHeight, 2.0f, SliderHeight);
	ThumbSize = FVector2D(FMath::Max(ThumbSize.X, 20.0f), FMath::Max(ThumbSize.Y, 16.0f));

	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(SliderLength)
		.HeightOverride(SliderHeight)
		[
			SAssignNew(Canvas, SCanvas)

			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassSlider::GetTrackPosition))
			.Size(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassSlider::GetTrackSize))
			[
				SAssignNew(TrackGlass, SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::Capsule)
				.BlurStrength(0.1f)
				.FrostRadius(0.018f)
				.RefractionStrength(0.08f)
				.RefractionThickness(8.0f)
				.IndexOfRefraction(1.1f)
				.ChromaticAberration(0.004f)
				.PrismIntensity(0.025f)
				.RimIntensity(0.18f)
				.GlowAmount(0.2f)
				.TintColor(TrackTint)
				.TintOpacity(0.08f)
				.GlassOpacity(TrackOpacity)
				.EdgeSoftness(0.42f)
				.Quality(Quality)
				[
					SNew(SBox)
				]
			]

			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassSlider::GetFillPosition))
			.Size(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassSlider::GetFillSize))
			[
				SAssignNew(FillGlass, SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::Capsule)
				.BlurStrength(0.06f)
				.FrostRadius(0.01f)
				.RefractionStrength(0.04f)
				.RefractionThickness(8.0f)
				.IndexOfRefraction(1.08f)
				.ChromaticAberration(0.0f)
				.PrismIntensity(0.0f)
				.RimIntensity(0.08f)
				.GlowAmount(0.24f)
				.TintColor(FillColor)
				.TintOpacity(0.86f)
				.GlassOpacity(0.98f)
				.EdgeSoftness(0.5f)
				.Quality(Quality)
				[
					SNew(SBox)
				]
			]

			+ SCanvas::Slot()
			.Position(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassSlider::GetThumbPosition))
			.Size(TAttribute<FVector2D>::CreateSP(this, &SCBLiquidGlassSlider::GetThumbVisualSize))
			[
				SAssignNew(ThumbGlass, SCBLiquidGlass)
				.Shape(ECBLiquidGlassShape::Capsule)
				.Quality(Quality)
				.MotionStrength(ThumbMotionStrength)
				.MotionMaxOffset(56.0f)
				.MotionResponse(28.0f)
				.MotionDamping(7.0f)
				[
					SNew(SBox)
				]
			]
		]
	];

	ApplyThumbStyle();
}

void SCBLiquidGlassSlider::ApplyThumbStyle()
{
	if (!ThumbGlass.IsValid())
	{
		return;
	}

	ThumbGlass->SetShape(ECBLiquidGlassShape::Capsule);
	ThumbGlass->SetQuality(Quality);
	ThumbGlass->SetMotionStrength(ThumbMotionStrength);

	switch (ThumbPreset)
	{
	case ECBLiquidGlassPreset::Clear:
		ThumbGlass->SetBlurStrength(0.18f);
		ThumbGlass->SetFrostRadius(0.024f);
		ThumbGlass->SetRefractionStrength(0.72f);
		ThumbGlass->SetRefractionThickness(36.0f);
		ThumbGlass->SetIndexOfRefraction(1.72f);
		ThumbGlass->SetPrismIntensity(0.16f);
		ThumbGlass->SetRimIntensity(0.58f);
		ThumbGlass->SetGlowAmount(0.62f);
		ThumbGlass->SetTintOpacity(0.008f);
		break;

	case ECBLiquidGlassPreset::FrostedMenu:
		ThumbGlass->SetBlurStrength(1.0f);
		ThumbGlass->SetFrostRadius(0.34f);
		ThumbGlass->SetRefractionStrength(0.55f);
		ThumbGlass->SetRefractionThickness(30.0f);
		ThumbGlass->SetIndexOfRefraction(1.55f);
		ThumbGlass->SetPrismIntensity(0.32f);
		ThumbGlass->SetRimIntensity(0.2f);
		ThumbGlass->SetGlowAmount(0.24f);
		ThumbGlass->SetTintOpacity(0.05f);
		break;

	case ECBLiquidGlassPreset::PillLens:
	default:
		ThumbGlass->SetBlurStrength(0.2f);
		ThumbGlass->SetFrostRadius(0.026f);
		ThumbGlass->SetRefractionStrength(0.74f);
		ThumbGlass->SetRefractionThickness(38.0f);
		ThumbGlass->SetIndexOfRefraction(1.74f);
		ThumbGlass->SetChromaticAberration(0.01f);
		ThumbGlass->SetPrismIntensity(0.14f);
		ThumbGlass->SetRimIntensity(0.6f);
		ThumbGlass->SetGlowAmount(0.66f);
		ThumbGlass->SetTintOpacity(0.01f);
		break;
	}

	ThumbGlass->SetRefractionPower(2.7f);
	ThumbGlass->SetChromaticAberration(0.01f);
	ThumbGlass->SetNoiseAmount(0.001f);
	ThumbGlass->SetInnerGlowIntensity(0.16f);
	ThumbGlass->SetInnerShadowIntensity(0.1f);
	ThumbGlass->SetSaturation(1.06f);
	ThumbGlass->SetEdgeSoftness(0.42f);
	ThumbGlass->SetGlassOpacity(1.0f);
}

void SCBLiquidGlassSlider::CommitValue(float InValue, bool bBroadcast)
{
	const float OldValue = Value;
	Value = FMath::Clamp(InValue, MinValue, MaxValue);

	if (!FMath::IsNearlyEqual(OldValue, Value))
	{
		Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
		if (bBroadcast && OnValueChanged.IsBound())
		{
			OnValueChanged.Execute(Value);
		}
	}
}

void SCBLiquidGlassSlider::UpdateValueFromPointer(const FGeometry& MyGeometry, const FVector2D& ScreenPosition)
{
	const FVector2D LocalPosition = MyGeometry.AbsoluteToLocal(ScreenPosition);
	const float Width = FMath::Max(MyGeometry.GetLocalSize().X, SliderLength);
	const float ThumbWidth = FMath::Max(ThumbSize.X, 1.0f);
	const float UsableWidth = FMath::Max(Width - ThumbWidth, 1.0f);
	const float Normalized = FMath::Clamp((LocalPosition.X - ThumbWidth * 0.5f) / UsableWidth, 0.0f, 1.0f);
	CommitValue(FMath::Lerp(MinValue, MaxValue, Normalized), true);
}

void SCBLiquidGlassSlider::ResetVisualIfNeeded()
{
	if (!bVisualInitialized)
	{
		VisualNormalizedValue = GetNormalizedValue();
		VisualVelocity = 0.0f;
		bVisualInitialized = true;
	}
}

float SCBLiquidGlassSlider::GetNormalizedValue() const
{
	if (FMath::IsNearlyEqual(MinValue, MaxValue))
	{
		return 0.0f;
	}

	return FMath::Clamp((Value - MinValue) / (MaxValue - MinValue), 0.0f, 1.0f);
}

float SCBLiquidGlassSlider::GetDisplayNormalizedValue() const
{
	return FMath::Clamp(VisualNormalizedValue, 0.0f, 1.0f);
}

float SCBLiquidGlassSlider::GetUsableWidth() const
{
	return FMath::Max(SliderLength - GetThumbVisualWidth(), 1.0f);
}

float SCBLiquidGlassSlider::GetThumbStretch() const
{
	const float PixelVelocity = FMath::Abs(VisualVelocity) * FMath::Max(SliderLength, 1.0f);
	const float DragBoost = bDragging ? 1.0f : 0.68f;
	return FMath::Clamp(PixelVelocity * 0.012f * ThumbBounce * DragBoost, 0.0f, ThumbSize.X * 0.18f);
}

float SCBLiquidGlassSlider::GetThumbMotionOffset() const
{
	const float PixelVelocity = VisualVelocity * FMath::Max(SliderLength, 1.0f);
	const float DragBoost = bDragging ? 1.0f : 0.55f;
	return FMath::Clamp(PixelVelocity * 0.0045f * ThumbBounce * DragBoost, -ThumbSize.X * 0.12f, ThumbSize.X * 0.12f);
}

float SCBLiquidGlassSlider::GetThumbVisualWidth() const
{
	return ThumbSize.X + GetThumbStretch();
}

float SCBLiquidGlassSlider::GetThumbVisualHeight() const
{
	return FMath::Max(TrackHeight * 2.1f, ThumbSize.Y - GetThumbStretch() * 0.08f);
}

float SCBLiquidGlassSlider::GetThumbCenterX() const
{
	const float Width = GetThumbVisualWidth();
	const float BaseCenter = Width * 0.5f + GetDisplayNormalizedValue() * FMath::Max(SliderLength - Width, 1.0f);
	return FMath::Clamp(BaseCenter + GetThumbMotionOffset(), Width * 0.5f, SliderLength - Width * 0.5f);
}

FVector2D SCBLiquidGlassSlider::GetTrackPosition() const
{
	return FVector2D(0.0f, (SliderHeight - TrackHeight) * 0.5f);
}

FVector2D SCBLiquidGlassSlider::GetTrackSize() const
{
	return FVector2D(SliderLength, TrackHeight);
}

FVector2D SCBLiquidGlassSlider::GetFillPosition() const
{
	return FVector2D(0.0f, (SliderHeight - TrackHeight) * 0.5f);
}

FVector2D SCBLiquidGlassSlider::GetFillSize() const
{
	return FVector2D(FMath::Clamp(GetThumbCenterX(), 0.0f, SliderLength), TrackHeight);
}

FVector2D SCBLiquidGlassSlider::GetThumbPosition() const
{
	const float Width = GetThumbVisualWidth();
	const float Height = GetThumbVisualHeight();
	return FVector2D(GetThumbCenterX() - Width * 0.5f, (SliderHeight - Height) * 0.5f);
}

FVector2D SCBLiquidGlassSlider::GetThumbVisualSize() const
{
	return FVector2D(GetThumbVisualWidth(), GetThumbVisualHeight());
}

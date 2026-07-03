// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBLiquidGlassTypes.h"

/**
 * Shared spring helpers used by every animated liquid-glass control (toggle thumb, segmented /
 * tab highlight, page indicator, dialog entrance, ...). Keeping a single solver here means all
 * controls share the same Apple-style feel and the same numeric stability guarantees.
 */
namespace CBLiquidGlassMotion
{
	/**
	 * Advances a damped spring toward Target by DeltaTime, mutating Value and Velocity in place.
	 *
	 * The spring is sub-stepped at a fixed 120 Hz and the frame delta is clamped to 30 Hz so the
	 * motion stays stable through frame-rate spikes. The tuning mirrors SwiftUI's
	 * spring(response:dampingFraction:): Response is the settling time in arbitrary units and
	 * Damping is the damping fraction (≈1 critically damped, <1 bouncier, >1 stiffer).
	 *
	 * @param Target     The value the spring is settling toward.
	 * @param Value       [in/out] Current spring position; updated in place.
	 * @param Velocity    [in/out] Current spring velocity; updated in place.
	 * @param Spring      Response / Damping tuning (Stretch and MaxOffset are used by callers, not here).
	 * @param DeltaTime   Frame time in seconds; internally clamped to [0, 1/30].
	 */
	inline void StepSpring(float Target, float& Value, float& Velocity, const FCBLiquidGlassSpringSettings& Spring, float DeltaTime)
	{
		float RemainingTime = FMath::Clamp(DeltaTime, 0.0f, 1.0f / 30.0f);
		while (RemainingTime > 0.0f)
		{
			const float StepTime = FMath::Min(RemainingTime, 1.0f / 120.0f);
			const float Response = FMath::Max(Spring.Response, 1.0f);
			const float Damping = FMath::Clamp(Spring.Damping, 0.1f, 3.0f);
			const float SpringForce = (Target - Value) * Response * Response;
			const float DampingForce = 2.0f * Response * Damping * Velocity;
			Velocity += (SpringForce - DampingForce) * StepTime;
			Value += Velocity * StepTime;
			RemainingTime -= StepTime;
		}
	}
}

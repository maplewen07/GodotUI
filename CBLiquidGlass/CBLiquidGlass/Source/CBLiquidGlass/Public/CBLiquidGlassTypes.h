// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "CBLiquidGlassTypes.generated.h"

/**
 * Convenience presets that write a complete set of Liquid Glass parameters.
 *
 * Presets are intentionally not "live styles": when a visual property is edited after a
 * preset is selected, the widget switches back to Custom so user tuning is not overwritten.
 */
UENUM(BlueprintType)
enum class ECBLiquidGlassPreset : uint8
{
	/** No preset is active; all visual properties are controlled manually. */
	Custom UMETA(DisplayName = "Custom"),

	/** Mostly transparent glass with clear center detail and stronger edge bending. */
	Clear UMETA(DisplayName = "Clear"),

	/** Balanced everyday glass: moderate frost, refraction, rim light and saturation. */
	Regular UMETA(DisplayName = "Regular"),

	/** Frostier floating menu style with softer prism colour and stronger separation. */
	FrostedMenu UMETA(DisplayName = "Frosted Menu"),

	/** Capsule button style with a clear center and a thick refractive rim. */
	PillLens UMETA(DisplayName = "Pill Lens"),

	/** Diffuse matte layer: heavy blur, low refraction and muted saturation. */
	MatteLayer UMETA(DisplayName = "Matte Layer"),

	/** Clear self-layer style: low blur and high lensing for stacked glass controls. */
	SelfLayer UMETA(DisplayName = "Self Layer"),
};

/** Shape mask used by the shader when compositing the glass. */
UENUM(BlueprintType)
enum class ECBLiquidGlassShape : uint8
{
	/** Continuous-curvature rounded rectangle driven by SquirclePower. */
	SuperellipseRect UMETA(DisplayName = "Superellipse Rect"),

	/** Fully rounded capsule, useful for pill buttons and toolbar chips. */
	Capsule UMETA(DisplayName = "Capsule"),

	/** Circular lens that uses the shortest widget side as its diameter. */
	Circle UMETA(DisplayName = "Circle"),

	/** Diamond lens for badges, markers and decorative glass chips. */
	Diamond UMETA(DisplayName = "Diamond"),

	/** Hexagonal lens for technical HUD-style controls. */
	Hexagon UMETA(DisplayName = "Hexagon"),

	/** Star-shaped lens for icon-like glass highlights. */
	Star UMETA(DisplayName = "Star"),

	/** Soft organic shape for irregular liquid blobs. */
	Blob UMETA(DisplayName = "Blob"),
};

/** Runtime quality profile used by the renderer to trade cost for blur/prism detail. */
UENUM(BlueprintType)
enum class ECBLiquidGlassQuality : uint8
{
	/** Higher downsample and softer effects for dense UI or low-end hardware. */
	Performance UMETA(DisplayName = "Performance"),

	/** Default profile: good quality with predictable cost. */
	Balanced UMETA(DisplayName = "Balanced"),

	/** Lower downsample and stronger detail for showcase panels. */
	Quality UMETA(DisplayName = "Quality"),
};

/** Standard size presets used by the higher-level liquid glass controls. */
UENUM(BlueprintType)
enum class ECBLiquidGlassControlSize : uint8
{
	Small UMETA(DisplayName = "Small"),
	Medium UMETA(DisplayName = "Medium"),
	Large UMETA(DisplayName = "Large"),
};

/** Placement of an item's icon relative to its text label. */
UENUM(BlueprintType)
enum class ECBLiquidGlassIconPosition : uint8
{
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right"),
	Top UMETA(DisplayName = "Top"),
	Only UMETA(DisplayName = "Icon Only"),
};

/** Axis used by grouped liquid glass controls. */
UENUM(BlueprintType)
enum class ECBLiquidGlassOrientation : uint8
{
	Horizontal UMETA(DisplayName = "Horizontal"),
	Vertical UMETA(DisplayName = "Vertical"),
};

/** Visual mode for Liquid Glass Progress. */
UENUM(BlueprintType)
enum class ECBLiquidGlassProgressStyle : uint8
{
	Linear UMETA(DisplayName = "Linear"),
	Circular UMETA(DisplayName = "Circular"),
};

/** State metadata shared by menu, toolbar, tab and segmented-control items. */
UENUM(BlueprintType)
enum class ECBLiquidGlassItemState : uint8
{
	Normal UMETA(DisplayName = "Normal"),
	Selected UMETA(DisplayName = "Selected"),
	Disabled UMETA(DisplayName = "Disabled"),
	Danger UMETA(DisplayName = "Danger"),
	Separator UMETA(DisplayName = "Separator"),
};

/** A reusable icon/text item for list-like liquid glass controls. */
USTRUCT(BlueprintType)
struct CBLIQUIDGLASS_API FCBLiquidGlassItem
{
	GENERATED_BODY()

	/** Text shown by the item. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	FText Label;

	/** Optional icon brush. Leave empty for text-only items. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	FSlateBrush Icon;

	/** User value returned by selection/click events. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	int32 Value = 0;

	/** Whether this item can be clicked. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	bool bEnabled = true;

	/** Additional visual state. Separator items render as non-clickable dividers. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	ECBLiquidGlassItemState State = ECBLiquidGlassItemState::Normal;
};

/** Shared damped-spring settings for moving thumbs and selection highlights. */
USTRUCT(BlueprintType)
struct CBLIQUIDGLASS_API FCBLiquidGlassSpringSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass", meta = (ClampMin = "1.0", ClampMax = "80.0"))
	float Response = 24.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass", meta = (ClampMin = "0.1", ClampMax = "3.0"))
	float Damping = 0.82f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass", meta = (ClampMin = "0.0", ClampMax = "3.0"))
	float Stretch = 0.72f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass", meta = (ClampMin = "0.0", ClampMax = "120.0"))
	float MaxOffset = 36.0f;
};

/** Compact visual style shared by high-level controls that actually use these fields. */
USTRUCT(BlueprintType)
struct CBLIQUIDGLASS_API FCBLiquidGlassControlStyle
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	ECBLiquidGlassPreset Preset = ECBLiquidGlassPreset::PillLens;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	ECBLiquidGlassQuality Quality = ECBLiquidGlassQuality::Balanced;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	ECBLiquidGlassControlSize Size = ECBLiquidGlassControlSize::Medium;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	FLinearColor TintColor = FLinearColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass")
	FLinearColor AccentColor = FLinearColor(0.0f, 0.52f, 1.0f, 1.0f);
};

/** Tunable layout and glass recipe for the two-layer liquid glass search box. */
USTRUCT(BlueprintType)
struct CBLIQUIDGLASS_API FCBLiquidGlassSearchBoxStyle
{
	GENERATED_BODY()

	/** Overall capsule size, including the outer glass shell and clear button. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box")
	FVector2D BoxSize = FVector2D(560.0f, 78.0f);

	/** Height of the inner frosted text capsule. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box", meta = (ClampMin = "12.0"))
	float TextLayerHeight = 56.0f;

	/** Size of the magnifier glyph area. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box", meta = (ClampMin = "8.0"))
	float IconSize = 34.0f;

	/** Diameter of the clear button. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box", meta = (ClampMin = "12.0"))
	float ClearButtonSize = 48.0f;

	/** Font size for the input text and hint. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box", meta = (ClampMin = "6.0"))
	float TextFontSize = 23.0f;

	/** Padding inside the outer glass shell. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box")
	FMargin OuterPadding = FMargin(18.0f, 0.0f, 16.0f, 0.0f);

	/** Padding inside the inner frosted text layer. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box")
	FMargin TextLayerPadding = FMargin(28.0f, 0.0f, 18.0f, 0.0f);

	/** Space between magnifier and text. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box", meta = (ClampMin = "0.0"))
	float IconTextSpacing = 24.0f;

	/** Space between the text layer and clear button. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box", meta = (ClampMin = "0.0"))
	float ClearButtonSpacing = 14.0f;

	/** Tint colour used by the outer glass shell. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Outer")
	FLinearColor OuterTintColor = FLinearColor(0.05f, 0.18f, 0.22f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Outer", meta = (ClampMin = "0.0"))
	float OuterBlurStrength = 1.18f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Outer", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float OuterFrostRadius = 0.42f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Outer", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float OuterRefractionStrength = 0.32f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Outer", meta = (ClampMin = "0.0"))
	float OuterRefractionThickness = 18.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Outer", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float OuterTintOpacity = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Outer", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float OuterGlassOpacity = 0.94f;

	/** Tint colour used by the inner frosted text capsule. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Inner")
	FLinearColor InnerTintColor = FLinearColor(0.02f, 0.16f, 0.2f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Inner", meta = (ClampMin = "0.0"))
	float InnerBlurStrength = 1.32f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Inner", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float InnerFrostRadius = 0.56f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Inner", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float InnerTintOpacity = 0.26f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Inner", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float InnerGlassOpacity = 0.72f;

	/** Magnifier glyph colour. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Content")
	FLinearColor IconColor = FLinearColor(0.94f, 1.0f, 1.0f, 0.95f);

	/** Editable text and hint colour. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Content")
	FLinearColor TextColor = FLinearColor(0.78f, 0.9f, 0.96f, 0.92f);

	/** Clear-button glass tint. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Clear Button")
	FLinearColor ClearButtonTintColor = FLinearColor(0.64f, 0.7f, 0.66f, 1.0f);

	/** Clear-button glyph colour. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Search Box|Clear Button")
	FLinearColor ClearButtonTextColor = FLinearColor(0.92f, 1.0f, 1.0f, 0.98f);
};

/** Presentation style for Liquid Glass Dialog (mirrors  alert / action sheet / sheet). */
UENUM(BlueprintType)
enum class ECBLiquidGlassDialogStyle : uint8
{
	/** Centered glass card with a dimmed backdrop, like UIAlertController .alert. */
	Alert UMETA(DisplayName = "Alert"),

	/** Bottom-anchored stack of choices, like UIAlertController .actionSheet. */
	ActionSheet UMETA(DisplayName = "Action Sheet"),

	/** Bottom sheet panel that slides up, like a SwiftUI .sheet. */
	Sheet UMETA(DisplayName = "Sheet"),
};

/**
 * One rounded sub-shape contributing to a Liquid Glass fusion container's merged silhouette.
 * Multiple blobs are smooth-unioned (smin) so neighbouring shapes melt together like Apple's
 * GlassEffectContainer, instead of compositing as separate panes.
 */
USTRUCT(BlueprintType)
struct CBLIQUIDGLASS_API FCBLiquidGlassFusionBlob
{
	GENERATED_BODY()

	/** Center of the blob in normalized container space (0,0 = top-left, 1,1 = bottom-right). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Fusion")
	FVector2D Position = FVector2D(0.5, 0.5);

	/** Blob size in pixels. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Fusion")
	FVector2D Size = FVector2D(120.0, 120.0);

	/** Corner rounding, 0 = sharp rectangle, 1 = fully rounded capsule/circle. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liquid Glass Fusion", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Roundness = 1.0f;
};

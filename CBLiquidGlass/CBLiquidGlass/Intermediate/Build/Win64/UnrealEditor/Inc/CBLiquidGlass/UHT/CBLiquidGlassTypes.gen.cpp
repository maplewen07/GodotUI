// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassTypes.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassTypes() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassItem();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ECBLiquidGlassPreset ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassPreset;
static UEnum* ECBLiquidGlassPreset_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassPreset.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassPreset.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassPreset"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassPreset.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassPreset>()
{
	return ECBLiquidGlassPreset_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Clear.Comment", "/** Mostly transparent glass with clear center detail and stronger edge bending. */" },
		{ "Clear.DisplayName", "Clear" },
		{ "Clear.Name", "ECBLiquidGlassPreset::Clear" },
		{ "Clear.ToolTip", "Mostly transparent glass with clear center detail and stronger edge bending." },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Convenience presets that write a complete set of Liquid Glass parameters.\n *\n * Presets are intentionally not \"live styles\": when a visual property is edited after a\n * preset is selected, the widget switches back to Custom so user tuning is not overwritten.\n */" },
#endif
		{ "Custom.Comment", "/** No preset is active; all visual properties are controlled manually. */" },
		{ "Custom.DisplayName", "Custom" },
		{ "Custom.Name", "ECBLiquidGlassPreset::Custom" },
		{ "Custom.ToolTip", "No preset is active; all visual properties are controlled manually." },
		{ "FrostedMenu.Comment", "/** Frostier floating menu style with softer prism colour and stronger separation. */" },
		{ "FrostedMenu.DisplayName", "Frosted Menu" },
		{ "FrostedMenu.Name", "ECBLiquidGlassPreset::FrostedMenu" },
		{ "FrostedMenu.ToolTip", "Frostier floating menu style with softer prism colour and stronger separation." },
		{ "MatteLayer.Comment", "/** Diffuse matte layer: heavy blur, low refraction and muted saturation. */" },
		{ "MatteLayer.DisplayName", "Matte Layer" },
		{ "MatteLayer.Name", "ECBLiquidGlassPreset::MatteLayer" },
		{ "MatteLayer.ToolTip", "Diffuse matte layer: heavy blur, low refraction and muted saturation." },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
		{ "PillLens.Comment", "/** Capsule button style with a clear center and a thick refractive rim. */" },
		{ "PillLens.DisplayName", "Pill Lens" },
		{ "PillLens.Name", "ECBLiquidGlassPreset::PillLens" },
		{ "PillLens.ToolTip", "Capsule button style with a clear center and a thick refractive rim." },
		{ "Regular.Comment", "/** Balanced everyday glass: moderate frost, refraction, rim light and saturation. */" },
		{ "Regular.DisplayName", "Regular" },
		{ "Regular.Name", "ECBLiquidGlassPreset::Regular" },
		{ "Regular.ToolTip", "Balanced everyday glass: moderate frost, refraction, rim light and saturation." },
		{ "SelfLayer.Comment", "/** Clear self-layer style: low blur and high lensing for stacked glass controls. */" },
		{ "SelfLayer.DisplayName", "Self Layer" },
		{ "SelfLayer.Name", "ECBLiquidGlassPreset::SelfLayer" },
		{ "SelfLayer.ToolTip", "Clear self-layer style: low blur and high lensing for stacked glass controls." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convenience presets that write a complete set of Liquid Glass parameters.\n\nPresets are intentionally not \"live styles\": when a visual property is edited after a\npreset is selected, the widget switches back to Custom so user tuning is not overwritten." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassPreset::Custom", (int64)ECBLiquidGlassPreset::Custom },
		{ "ECBLiquidGlassPreset::Clear", (int64)ECBLiquidGlassPreset::Clear },
		{ "ECBLiquidGlassPreset::Regular", (int64)ECBLiquidGlassPreset::Regular },
		{ "ECBLiquidGlassPreset::FrostedMenu", (int64)ECBLiquidGlassPreset::FrostedMenu },
		{ "ECBLiquidGlassPreset::PillLens", (int64)ECBLiquidGlassPreset::PillLens },
		{ "ECBLiquidGlassPreset::MatteLayer", (int64)ECBLiquidGlassPreset::MatteLayer },
		{ "ECBLiquidGlassPreset::SelfLayer", (int64)ECBLiquidGlassPreset::SelfLayer },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassPreset",
	"ECBLiquidGlassPreset",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassPreset.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassPreset.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassPreset.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassPreset ********************************************************

// ********** Begin Enum ECBLiquidGlassShape *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassShape;
static UEnum* ECBLiquidGlassShape_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassShape.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassShape.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassShape"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassShape.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassShape>()
{
	return ECBLiquidGlassShape_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Blob.Comment", "/** Soft organic shape for irregular liquid blobs. */" },
		{ "Blob.DisplayName", "Blob" },
		{ "Blob.Name", "ECBLiquidGlassShape::Blob" },
		{ "Blob.ToolTip", "Soft organic shape for irregular liquid blobs." },
		{ "BlueprintType", "true" },
		{ "Capsule.Comment", "/** Fully rounded capsule, useful for pill buttons and toolbar chips. */" },
		{ "Capsule.DisplayName", "Capsule" },
		{ "Capsule.Name", "ECBLiquidGlassShape::Capsule" },
		{ "Capsule.ToolTip", "Fully rounded capsule, useful for pill buttons and toolbar chips." },
		{ "Circle.Comment", "/** Circular lens that uses the shortest widget side as its diameter. */" },
		{ "Circle.DisplayName", "Circle" },
		{ "Circle.Name", "ECBLiquidGlassShape::Circle" },
		{ "Circle.ToolTip", "Circular lens that uses the shortest widget side as its diameter." },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shape mask used by the shader when compositing the glass. */" },
#endif
		{ "Diamond.Comment", "/** Diamond lens for badges, markers and decorative glass chips. */" },
		{ "Diamond.DisplayName", "Diamond" },
		{ "Diamond.Name", "ECBLiquidGlassShape::Diamond" },
		{ "Diamond.ToolTip", "Diamond lens for badges, markers and decorative glass chips." },
		{ "Hexagon.Comment", "/** Hexagonal lens for technical HUD-style controls. */" },
		{ "Hexagon.DisplayName", "Hexagon" },
		{ "Hexagon.Name", "ECBLiquidGlassShape::Hexagon" },
		{ "Hexagon.ToolTip", "Hexagonal lens for technical HUD-style controls." },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
		{ "Star.Comment", "/** Star-shaped lens for icon-like glass highlights. */" },
		{ "Star.DisplayName", "Star" },
		{ "Star.Name", "ECBLiquidGlassShape::Star" },
		{ "Star.ToolTip", "Star-shaped lens for icon-like glass highlights." },
		{ "SuperellipseRect.Comment", "/** Continuous-curvature rounded rectangle driven by SquirclePower. */" },
		{ "SuperellipseRect.DisplayName", "Superellipse Rect" },
		{ "SuperellipseRect.Name", "ECBLiquidGlassShape::SuperellipseRect" },
		{ "SuperellipseRect.ToolTip", "Continuous-curvature rounded rectangle driven by SquirclePower." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shape mask used by the shader when compositing the glass." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassShape::SuperellipseRect", (int64)ECBLiquidGlassShape::SuperellipseRect },
		{ "ECBLiquidGlassShape::Capsule", (int64)ECBLiquidGlassShape::Capsule },
		{ "ECBLiquidGlassShape::Circle", (int64)ECBLiquidGlassShape::Circle },
		{ "ECBLiquidGlassShape::Diamond", (int64)ECBLiquidGlassShape::Diamond },
		{ "ECBLiquidGlassShape::Hexagon", (int64)ECBLiquidGlassShape::Hexagon },
		{ "ECBLiquidGlassShape::Star", (int64)ECBLiquidGlassShape::Star },
		{ "ECBLiquidGlassShape::Blob", (int64)ECBLiquidGlassShape::Blob },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassShape",
	"ECBLiquidGlassShape",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassShape.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassShape.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassShape.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassShape *********************************************************

// ********** Begin Enum ECBLiquidGlassQuality *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassQuality;
static UEnum* ECBLiquidGlassQuality_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassQuality.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassQuality.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassQuality"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassQuality.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassQuality>()
{
	return ECBLiquidGlassQuality_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Balanced.Comment", "/** Default profile: good quality with predictable cost. */" },
		{ "Balanced.DisplayName", "Balanced" },
		{ "Balanced.Name", "ECBLiquidGlassQuality::Balanced" },
		{ "Balanced.ToolTip", "Default profile: good quality with predictable cost." },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Runtime quality profile used by the renderer to trade cost for blur/prism detail. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
		{ "Performance.Comment", "/** Higher downsample and softer effects for dense UI or low-end hardware. */" },
		{ "Performance.DisplayName", "Performance" },
		{ "Performance.Name", "ECBLiquidGlassQuality::Performance" },
		{ "Performance.ToolTip", "Higher downsample and softer effects for dense UI or low-end hardware." },
		{ "Quality.Comment", "/** Lower downsample and stronger detail for showcase panels. */" },
		{ "Quality.DisplayName", "Quality" },
		{ "Quality.Name", "ECBLiquidGlassQuality::Quality" },
		{ "Quality.ToolTip", "Lower downsample and stronger detail for showcase panels." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime quality profile used by the renderer to trade cost for blur/prism detail." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassQuality::Performance", (int64)ECBLiquidGlassQuality::Performance },
		{ "ECBLiquidGlassQuality::Balanced", (int64)ECBLiquidGlassQuality::Balanced },
		{ "ECBLiquidGlassQuality::Quality", (int64)ECBLiquidGlassQuality::Quality },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassQuality",
	"ECBLiquidGlassQuality",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassQuality.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassQuality.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassQuality.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassQuality *******************************************************

// ********** Begin Enum ECBLiquidGlassControlSize *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassControlSize;
static UEnum* ECBLiquidGlassControlSize_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassControlSize.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassControlSize.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassControlSize"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassControlSize.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassControlSize>()
{
	return ECBLiquidGlassControlSize_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Standard size presets used by the higher-level liquid glass controls. */" },
#endif
		{ "Large.DisplayName", "Large" },
		{ "Large.Name", "ECBLiquidGlassControlSize::Large" },
		{ "Medium.DisplayName", "Medium" },
		{ "Medium.Name", "ECBLiquidGlassControlSize::Medium" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
		{ "Small.DisplayName", "Small" },
		{ "Small.Name", "ECBLiquidGlassControlSize::Small" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Standard size presets used by the higher-level liquid glass controls." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassControlSize::Small", (int64)ECBLiquidGlassControlSize::Small },
		{ "ECBLiquidGlassControlSize::Medium", (int64)ECBLiquidGlassControlSize::Medium },
		{ "ECBLiquidGlassControlSize::Large", (int64)ECBLiquidGlassControlSize::Large },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassControlSize",
	"ECBLiquidGlassControlSize",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassControlSize.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassControlSize.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassControlSize.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassControlSize ***************************************************

// ********** Begin Enum ECBLiquidGlassIconPosition ************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassIconPosition;
static UEnum* ECBLiquidGlassIconPosition_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassIconPosition.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassIconPosition.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassIconPosition"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassIconPosition.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassIconPosition>()
{
	return ECBLiquidGlassIconPosition_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Placement of an item's icon relative to its text label. */" },
#endif
		{ "Left.DisplayName", "Left" },
		{ "Left.Name", "ECBLiquidGlassIconPosition::Left" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
		{ "Only.DisplayName", "Icon Only" },
		{ "Only.Name", "ECBLiquidGlassIconPosition::Only" },
		{ "Right.DisplayName", "Right" },
		{ "Right.Name", "ECBLiquidGlassIconPosition::Right" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Placement of an item's icon relative to its text label." },
#endif
		{ "Top.DisplayName", "Top" },
		{ "Top.Name", "ECBLiquidGlassIconPosition::Top" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassIconPosition::Left", (int64)ECBLiquidGlassIconPosition::Left },
		{ "ECBLiquidGlassIconPosition::Right", (int64)ECBLiquidGlassIconPosition::Right },
		{ "ECBLiquidGlassIconPosition::Top", (int64)ECBLiquidGlassIconPosition::Top },
		{ "ECBLiquidGlassIconPosition::Only", (int64)ECBLiquidGlassIconPosition::Only },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassIconPosition",
	"ECBLiquidGlassIconPosition",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassIconPosition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassIconPosition.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassIconPosition_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassIconPosition.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassIconPosition **************************************************

// ********** Begin Enum ECBLiquidGlassOrientation *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassOrientation;
static UEnum* ECBLiquidGlassOrientation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassOrientation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassOrientation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassOrientation"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassOrientation.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassOrientation>()
{
	return ECBLiquidGlassOrientation_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Axis used by grouped liquid glass controls. */" },
#endif
		{ "Horizontal.DisplayName", "Horizontal" },
		{ "Horizontal.Name", "ECBLiquidGlassOrientation::Horizontal" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Axis used by grouped liquid glass controls." },
#endif
		{ "Vertical.DisplayName", "Vertical" },
		{ "Vertical.Name", "ECBLiquidGlassOrientation::Vertical" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassOrientation::Horizontal", (int64)ECBLiquidGlassOrientation::Horizontal },
		{ "ECBLiquidGlassOrientation::Vertical", (int64)ECBLiquidGlassOrientation::Vertical },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassOrientation",
	"ECBLiquidGlassOrientation",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassOrientation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassOrientation.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassOrientation.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassOrientation ***************************************************

// ********** Begin Enum ECBLiquidGlassProgressStyle ***********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassProgressStyle;
static UEnum* ECBLiquidGlassProgressStyle_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassProgressStyle.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassProgressStyle.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassProgressStyle"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassProgressStyle.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassProgressStyle>()
{
	return ECBLiquidGlassProgressStyle_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Circular.DisplayName", "Circular" },
		{ "Circular.Name", "ECBLiquidGlassProgressStyle::Circular" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visual mode for Liquid Glass Progress. */" },
#endif
		{ "Linear.DisplayName", "Linear" },
		{ "Linear.Name", "ECBLiquidGlassProgressStyle::Linear" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual mode for Liquid Glass Progress." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassProgressStyle::Linear", (int64)ECBLiquidGlassProgressStyle::Linear },
		{ "ECBLiquidGlassProgressStyle::Circular", (int64)ECBLiquidGlassProgressStyle::Circular },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassProgressStyle",
	"ECBLiquidGlassProgressStyle",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassProgressStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassProgressStyle.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassProgressStyle.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassProgressStyle *************************************************

// ********** Begin Enum ECBLiquidGlassItemState ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassItemState;
static UEnum* ECBLiquidGlassItemState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassItemState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassItemState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassItemState"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassItemState.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassItemState>()
{
	return ECBLiquidGlassItemState_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** State metadata shared by menu, toolbar, tab and segmented-control items. */" },
#endif
		{ "Danger.DisplayName", "Danger" },
		{ "Danger.Name", "ECBLiquidGlassItemState::Danger" },
		{ "Disabled.DisplayName", "Disabled" },
		{ "Disabled.Name", "ECBLiquidGlassItemState::Disabled" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
		{ "Normal.DisplayName", "Normal" },
		{ "Normal.Name", "ECBLiquidGlassItemState::Normal" },
		{ "Selected.DisplayName", "Selected" },
		{ "Selected.Name", "ECBLiquidGlassItemState::Selected" },
		{ "Separator.DisplayName", "Separator" },
		{ "Separator.Name", "ECBLiquidGlassItemState::Separator" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State metadata shared by menu, toolbar, tab and segmented-control items." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassItemState::Normal", (int64)ECBLiquidGlassItemState::Normal },
		{ "ECBLiquidGlassItemState::Selected", (int64)ECBLiquidGlassItemState::Selected },
		{ "ECBLiquidGlassItemState::Disabled", (int64)ECBLiquidGlassItemState::Disabled },
		{ "ECBLiquidGlassItemState::Danger", (int64)ECBLiquidGlassItemState::Danger },
		{ "ECBLiquidGlassItemState::Separator", (int64)ECBLiquidGlassItemState::Separator },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassItemState",
	"ECBLiquidGlassItemState",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassItemState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassItemState.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassItemState.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassItemState *****************************************************

// ********** Begin ScriptStruct FCBLiquidGlassItem ************************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCBLiquidGlassItem); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCBLiquidGlassItem); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A reusable icon/text item for list-like liquid glass controls. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A reusable icon/text item for list-like liquid glass controls." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "Category", "Liquid Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text shown by the item. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text shown by the item." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "Liquid Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional icon brush. Leave empty for text-only items. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional icon brush. Leave empty for text-only items." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "Liquid Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** User value returned by selection/click events. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "User value returned by selection/click events." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Liquid Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this item can be clicked. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this item can be clicked." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "Liquid Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Additional visual state. Separator items render as non-clickable dividers. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Additional visual state. Separator items render as non-clickable dividers." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCBLiquidGlassItem constinit property declarations ****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Label;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCBLiquidGlassItem constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCBLiquidGlassItem>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCBLiquidGlassItem;
class UScriptStruct* FCBLiquidGlassItem::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassItem.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCBLiquidGlassItem.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCBLiquidGlassItem, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("CBLiquidGlassItem"));
	}
	return Z_Registration_Info_UScriptStruct_FCBLiquidGlassItem.OuterSingleton;
	}

// ********** Begin ScriptStruct FCBLiquidGlassItem Property Definitions ***************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassItem, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassItem, Icon), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) }; // 4278521822
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassItem, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((FCBLiquidGlassItem*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCBLiquidGlassItem), &Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassItem, State), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassItemState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 4177702898
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_Label,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewProp_State,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCBLiquidGlassItem Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	&NewStructOps,
	"CBLiquidGlassItem",
	Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::PropPointers),
	sizeof(FCBLiquidGlassItem),
	alignof(FCBLiquidGlassItem),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassItem()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassItem.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCBLiquidGlassItem.InnerSingleton, Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCBLiquidGlassItem.InnerSingleton);
}
// ********** End ScriptStruct FCBLiquidGlassItem **************************************************

// ********** Begin ScriptStruct FCBLiquidGlassSpringSettings **************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCBLiquidGlassSpringSettings); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCBLiquidGlassSpringSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shared damped-spring settings for moving thumbs and selection highlights. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shared damped-spring settings for moving thumbs and selection highlights." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Response_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ClampMax", "80.0" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damping_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stretch_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxOffset_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ClampMax", "120.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCBLiquidGlassSpringSettings constinit property declarations ******
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Response;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Stretch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCBLiquidGlassSpringSettings constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCBLiquidGlassSpringSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCBLiquidGlassSpringSettings;
class UScriptStruct* FCBLiquidGlassSpringSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassSpringSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCBLiquidGlassSpringSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("CBLiquidGlassSpringSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FCBLiquidGlassSpringSettings.OuterSingleton;
	}

// ********** Begin ScriptStruct FCBLiquidGlassSpringSettings Property Definitions *****************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewProp_Response = { "Response", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSpringSettings, Response), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Response_MetaData), NewProp_Response_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewProp_Damping = { "Damping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSpringSettings, Damping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damping_MetaData), NewProp_Damping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewProp_Stretch = { "Stretch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSpringSettings, Stretch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stretch_MetaData), NewProp_Stretch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewProp_MaxOffset = { "MaxOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSpringSettings, MaxOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxOffset_MetaData), NewProp_MaxOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewProp_Response,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewProp_Damping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewProp_Stretch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewProp_MaxOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCBLiquidGlassSpringSettings Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	&NewStructOps,
	"CBLiquidGlassSpringSettings",
	Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::PropPointers),
	sizeof(FCBLiquidGlassSpringSettings),
	alignof(FCBLiquidGlassSpringSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassSpringSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCBLiquidGlassSpringSettings.InnerSingleton, Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCBLiquidGlassSpringSettings.InnerSingleton);
}
// ********** End ScriptStruct FCBLiquidGlassSpringSettings ****************************************

// ********** Begin ScriptStruct FCBLiquidGlassControlStyle ****************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCBLiquidGlassControlStyle); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCBLiquidGlassControlStyle); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compact visual style shared by high-level controls that actually use these fields. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compact visual style shared by high-level controls that actually use these fields." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quality_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TintColor_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccentColor_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCBLiquidGlassControlStyle constinit property declarations ********
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Quality_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Quality;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Size_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Size;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TintColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccentColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCBLiquidGlassControlStyle constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCBLiquidGlassControlStyle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCBLiquidGlassControlStyle;
class UScriptStruct* FCBLiquidGlassControlStyle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassControlStyle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCBLiquidGlassControlStyle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("CBLiquidGlassControlStyle"));
	}
	return Z_Registration_Info_UScriptStruct_FCBLiquidGlassControlStyle.OuterSingleton;
	}

// ********** Begin ScriptStruct FCBLiquidGlassControlStyle Property Definitions *******************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassControlStyle, Preset), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Preset_MetaData), NewProp_Preset_MetaData) }; // 3360299489
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Quality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Quality = { "Quality", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassControlStyle, Quality), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quality_MetaData), NewProp_Quality_MetaData) }; // 2771085032
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Size_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassControlStyle, Size), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassControlSize, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) }; // 2700107835
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_TintColor = { "TintColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassControlStyle, TintColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TintColor_MetaData), NewProp_TintColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_AccentColor = { "AccentColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassControlStyle, AccentColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccentColor_MetaData), NewProp_AccentColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Quality_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Quality,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Size_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_TintColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewProp_AccentColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCBLiquidGlassControlStyle Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	&NewStructOps,
	"CBLiquidGlassControlStyle",
	Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::PropPointers),
	sizeof(FCBLiquidGlassControlStyle),
	alignof(FCBLiquidGlassControlStyle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassControlStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCBLiquidGlassControlStyle.InnerSingleton, Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCBLiquidGlassControlStyle.InnerSingleton);
}
// ********** End ScriptStruct FCBLiquidGlassControlStyle ******************************************

// ********** Begin ScriptStruct FCBLiquidGlassSearchBoxStyle **************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCBLiquidGlassSearchBoxStyle); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCBLiquidGlassSearchBoxStyle); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tunable layout and glass recipe for the two-layer liquid glass search box. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tunable layout and glass recipe for the two-layer liquid glass search box." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoxSize_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Overall capsule size, including the outer glass shell and clear button. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Overall capsule size, including the outer glass shell and clear button." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextLayerHeight_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
		{ "ClampMin", "12.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Height of the inner frosted text capsule. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the inner frosted text capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IconSize_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
		{ "ClampMin", "8.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Size of the magnifier glyph area. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Size of the magnifier glyph area." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClearButtonSize_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
		{ "ClampMin", "12.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Diameter of the clear button. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Diameter of the clear button." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextFontSize_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
		{ "ClampMin", "6.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Font size for the input text and hint. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Font size for the input text and hint." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterPadding_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Padding inside the outer glass shell. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Padding inside the outer glass shell." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextLayerPadding_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Padding inside the inner frosted text layer. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Padding inside the inner frosted text layer." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IconTextSpacing_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Space between magnifier and text. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Space between magnifier and text." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClearButtonSpacing_MetaData[] = {
		{ "Category", "Liquid Glass Search Box" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Space between the text layer and clear button. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Space between the text layer and clear button." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterTintColor_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Outer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tint colour used by the outer glass shell. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tint colour used by the outer glass shell." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterBlurStrength_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Outer" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterFrostRadius_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Outer" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterRefractionStrength_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Outer" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterRefractionThickness_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Outer" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterTintOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Outer" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterGlassOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Outer" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InnerTintColor_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Inner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tint colour used by the inner frosted text capsule. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tint colour used by the inner frosted text capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InnerBlurStrength_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Inner" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InnerFrostRadius_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Inner" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InnerTintOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Inner" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InnerGlassOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Inner" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IconColor_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Magnifier glyph colour. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Magnifier glyph colour." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextColor_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Editable text and hint colour. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editable text and hint colour." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClearButtonTintColor_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Clear Button" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Clear-button glass tint. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear-button glass tint." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClearButtonTextColor_MetaData[] = {
		{ "Category", "Liquid Glass Search Box|Clear Button" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Clear-button glyph colour. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear-button glyph colour." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCBLiquidGlassSearchBoxStyle constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_BoxSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TextLayerHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IconSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClearButtonSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TextFontSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OuterPadding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextLayerPadding;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IconTextSpacing;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClearButtonSpacing;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OuterTintColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OuterBlurStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OuterFrostRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OuterRefractionStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OuterRefractionThickness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OuterTintOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OuterGlassOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InnerTintColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InnerBlurStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InnerFrostRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InnerTintOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InnerGlassOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_IconColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClearButtonTintColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClearButtonTextColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCBLiquidGlassSearchBoxStyle constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCBLiquidGlassSearchBoxStyle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCBLiquidGlassSearchBoxStyle;
class UScriptStruct* FCBLiquidGlassSearchBoxStyle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassSearchBoxStyle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCBLiquidGlassSearchBoxStyle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("CBLiquidGlassSearchBoxStyle"));
	}
	return Z_Registration_Info_UScriptStruct_FCBLiquidGlassSearchBoxStyle.OuterSingleton;
	}

// ********** Begin ScriptStruct FCBLiquidGlassSearchBoxStyle Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_BoxSize = { "BoxSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, BoxSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoxSize_MetaData), NewProp_BoxSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_TextLayerHeight = { "TextLayerHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, TextLayerHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextLayerHeight_MetaData), NewProp_TextLayerHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_IconSize = { "IconSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, IconSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IconSize_MetaData), NewProp_IconSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_ClearButtonSize = { "ClearButtonSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, ClearButtonSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClearButtonSize_MetaData), NewProp_ClearButtonSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_TextFontSize = { "TextFontSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, TextFontSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextFontSize_MetaData), NewProp_TextFontSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterPadding = { "OuterPadding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, OuterPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterPadding_MetaData), NewProp_OuterPadding_MetaData) }; // 4099648758
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_TextLayerPadding = { "TextLayerPadding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, TextLayerPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextLayerPadding_MetaData), NewProp_TextLayerPadding_MetaData) }; // 4099648758
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_IconTextSpacing = { "IconTextSpacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, IconTextSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IconTextSpacing_MetaData), NewProp_IconTextSpacing_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_ClearButtonSpacing = { "ClearButtonSpacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, ClearButtonSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClearButtonSpacing_MetaData), NewProp_ClearButtonSpacing_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterTintColor = { "OuterTintColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, OuterTintColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterTintColor_MetaData), NewProp_OuterTintColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterBlurStrength = { "OuterBlurStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, OuterBlurStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterBlurStrength_MetaData), NewProp_OuterBlurStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterFrostRadius = { "OuterFrostRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, OuterFrostRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterFrostRadius_MetaData), NewProp_OuterFrostRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterRefractionStrength = { "OuterRefractionStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, OuterRefractionStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterRefractionStrength_MetaData), NewProp_OuterRefractionStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterRefractionThickness = { "OuterRefractionThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, OuterRefractionThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterRefractionThickness_MetaData), NewProp_OuterRefractionThickness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterTintOpacity = { "OuterTintOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, OuterTintOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterTintOpacity_MetaData), NewProp_OuterTintOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterGlassOpacity = { "OuterGlassOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, OuterGlassOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterGlassOpacity_MetaData), NewProp_OuterGlassOpacity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerTintColor = { "InnerTintColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, InnerTintColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InnerTintColor_MetaData), NewProp_InnerTintColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerBlurStrength = { "InnerBlurStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, InnerBlurStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InnerBlurStrength_MetaData), NewProp_InnerBlurStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerFrostRadius = { "InnerFrostRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, InnerFrostRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InnerFrostRadius_MetaData), NewProp_InnerFrostRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerTintOpacity = { "InnerTintOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, InnerTintOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InnerTintOpacity_MetaData), NewProp_InnerTintOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerGlassOpacity = { "InnerGlassOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, InnerGlassOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InnerGlassOpacity_MetaData), NewProp_InnerGlassOpacity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_IconColor = { "IconColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, IconColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IconColor_MetaData), NewProp_IconColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_TextColor = { "TextColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, TextColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextColor_MetaData), NewProp_TextColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_ClearButtonTintColor = { "ClearButtonTintColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, ClearButtonTintColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClearButtonTintColor_MetaData), NewProp_ClearButtonTintColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_ClearButtonTextColor = { "ClearButtonTextColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassSearchBoxStyle, ClearButtonTextColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClearButtonTextColor_MetaData), NewProp_ClearButtonTextColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_BoxSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_TextLayerHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_IconSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_ClearButtonSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_TextFontSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_TextLayerPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_IconTextSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_ClearButtonSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterTintColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterBlurStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterFrostRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterRefractionStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterRefractionThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterTintOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_OuterGlassOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerTintColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerBlurStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerFrostRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerTintOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_InnerGlassOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_IconColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_TextColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_ClearButtonTintColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewProp_ClearButtonTextColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCBLiquidGlassSearchBoxStyle Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	&NewStructOps,
	"CBLiquidGlassSearchBoxStyle",
	Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::PropPointers),
	sizeof(FCBLiquidGlassSearchBoxStyle),
	alignof(FCBLiquidGlassSearchBoxStyle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassSearchBoxStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCBLiquidGlassSearchBoxStyle.InnerSingleton, Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCBLiquidGlassSearchBoxStyle.InnerSingleton);
}
// ********** End ScriptStruct FCBLiquidGlassSearchBoxStyle ****************************************

// ********** Begin Enum ECBLiquidGlassDialogStyle *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECBLiquidGlassDialogStyle;
static UEnum* ECBLiquidGlassDialogStyle_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassDialogStyle.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECBLiquidGlassDialogStyle.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("ECBLiquidGlassDialogStyle"));
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassDialogStyle.OuterSingleton;
}
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassDialogStyle>()
{
	return ECBLiquidGlassDialogStyle_StaticEnum();
}
struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ActionSheet.Comment", "/** Bottom-anchored stack of choices, like UIAlertController .actionSheet. */" },
		{ "ActionSheet.DisplayName", "Action Sheet" },
		{ "ActionSheet.Name", "ECBLiquidGlassDialogStyle::ActionSheet" },
		{ "ActionSheet.ToolTip", "Bottom-anchored stack of choices, like UIAlertController .actionSheet." },
		{ "Alert.Comment", "/** Centered glass card with a dimmed backdrop, like UIAlertController .alert. */" },
		{ "Alert.DisplayName", "Alert" },
		{ "Alert.Name", "ECBLiquidGlassDialogStyle::Alert" },
		{ "Alert.ToolTip", "Centered glass card with a dimmed backdrop, like UIAlertController .alert." },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Presentation style for Liquid Glass Dialog (mirrors  alert / action sheet / sheet). */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
		{ "Sheet.Comment", "/** Bottom sheet panel that slides up, like a SwiftUI .sheet. */" },
		{ "Sheet.DisplayName", "Sheet" },
		{ "Sheet.Name", "ECBLiquidGlassDialogStyle::Sheet" },
		{ "Sheet.ToolTip", "Bottom sheet panel that slides up, like a SwiftUI .sheet." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Presentation style for Liquid Glass Dialog (mirrors  alert / action sheet / sheet)." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECBLiquidGlassDialogStyle::Alert", (int64)ECBLiquidGlassDialogStyle::Alert },
		{ "ECBLiquidGlassDialogStyle::ActionSheet", (int64)ECBLiquidGlassDialogStyle::ActionSheet },
		{ "ECBLiquidGlassDialogStyle::Sheet", (int64)ECBLiquidGlassDialogStyle::Sheet },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	"ECBLiquidGlassDialogStyle",
	"ECBLiquidGlassDialogStyle",
	Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle()
{
	if (!Z_Registration_Info_UEnum_ECBLiquidGlassDialogStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECBLiquidGlassDialogStyle.InnerSingleton, Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECBLiquidGlassDialogStyle.InnerSingleton;
}
// ********** End Enum ECBLiquidGlassDialogStyle ***************************************************

// ********** Begin ScriptStruct FCBLiquidGlassFusionBlob ******************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCBLiquidGlassFusionBlob); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCBLiquidGlassFusionBlob); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * One rounded sub-shape contributing to a Liquid Glass fusion container's merged silhouette.\n * Multiple blobs are smooth-unioned (smin) so neighbouring shapes melt together like Apple's\n * GlassEffectContainer, instead of compositing as separate panes.\n */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One rounded sub-shape contributing to a Liquid Glass fusion container's merged silhouette.\nMultiple blobs are smooth-unioned (smin) so neighbouring shapes melt together like Apple's\nGlassEffectContainer, instead of compositing as separate panes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "Liquid Glass Fusion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Center of the blob in normalized container space (0,0 = top-left, 1,1 = bottom-right). */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Center of the blob in normalized container space (0,0 = top-left, 1,1 = bottom-right)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "Category", "Liquid Glass Fusion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blob size in pixels. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blob size in pixels." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Roundness_MetaData[] = {
		{ "Category", "Liquid Glass Fusion" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Corner rounding, 0 = sharp rectangle, 1 = fully rounded capsule/circle. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Corner rounding, 0 = sharp rectangle, 1 = fully rounded capsule/circle." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCBLiquidGlassFusionBlob constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roundness;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCBLiquidGlassFusionBlob constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCBLiquidGlassFusionBlob>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCBLiquidGlassFusionBlob;
class UScriptStruct* FCBLiquidGlassFusionBlob::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassFusionBlob.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCBLiquidGlassFusionBlob.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob, (UObject*)Z_Construct_UPackage__Script_CBLiquidGlass(), TEXT("CBLiquidGlassFusionBlob"));
	}
	return Z_Registration_Info_UScriptStruct_FCBLiquidGlassFusionBlob.OuterSingleton;
	}

// ********** Begin ScriptStruct FCBLiquidGlassFusionBlob Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassFusionBlob, Position), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassFusionBlob, Size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::NewProp_Roundness = { "Roundness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCBLiquidGlassFusionBlob, Roundness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Roundness_MetaData), NewProp_Roundness_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::NewProp_Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::NewProp_Roundness,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCBLiquidGlassFusionBlob Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
	nullptr,
	&NewStructOps,
	"CBLiquidGlassFusionBlob",
	Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::PropPointers),
	sizeof(FCBLiquidGlassFusionBlob),
	alignof(FCBLiquidGlassFusionBlob),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob()
{
	if (!Z_Registration_Info_UScriptStruct_FCBLiquidGlassFusionBlob.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCBLiquidGlassFusionBlob.InnerSingleton, Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCBLiquidGlassFusionBlob.InnerSingleton);
}
// ********** End ScriptStruct FCBLiquidGlassFusionBlob ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h__Script_CBLiquidGlass_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECBLiquidGlassPreset_StaticEnum, TEXT("ECBLiquidGlassPreset"), &Z_Registration_Info_UEnum_ECBLiquidGlassPreset, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3360299489U) },
		{ ECBLiquidGlassShape_StaticEnum, TEXT("ECBLiquidGlassShape"), &Z_Registration_Info_UEnum_ECBLiquidGlassShape, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1987497363U) },
		{ ECBLiquidGlassQuality_StaticEnum, TEXT("ECBLiquidGlassQuality"), &Z_Registration_Info_UEnum_ECBLiquidGlassQuality, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2771085032U) },
		{ ECBLiquidGlassControlSize_StaticEnum, TEXT("ECBLiquidGlassControlSize"), &Z_Registration_Info_UEnum_ECBLiquidGlassControlSize, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2700107835U) },
		{ ECBLiquidGlassIconPosition_StaticEnum, TEXT("ECBLiquidGlassIconPosition"), &Z_Registration_Info_UEnum_ECBLiquidGlassIconPosition, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3199784050U) },
		{ ECBLiquidGlassOrientation_StaticEnum, TEXT("ECBLiquidGlassOrientation"), &Z_Registration_Info_UEnum_ECBLiquidGlassOrientation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1928438873U) },
		{ ECBLiquidGlassProgressStyle_StaticEnum, TEXT("ECBLiquidGlassProgressStyle"), &Z_Registration_Info_UEnum_ECBLiquidGlassProgressStyle, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2653204971U) },
		{ ECBLiquidGlassItemState_StaticEnum, TEXT("ECBLiquidGlassItemState"), &Z_Registration_Info_UEnum_ECBLiquidGlassItemState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4177702898U) },
		{ ECBLiquidGlassDialogStyle_StaticEnum, TEXT("ECBLiquidGlassDialogStyle"), &Z_Registration_Info_UEnum_ECBLiquidGlassDialogStyle, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1484063289U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCBLiquidGlassItem::StaticStruct, Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics::NewStructOps, TEXT("CBLiquidGlassItem"),&Z_Registration_Info_UScriptStruct_FCBLiquidGlassItem, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCBLiquidGlassItem), 688407273U) },
		{ FCBLiquidGlassSpringSettings::StaticStruct, Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics::NewStructOps, TEXT("CBLiquidGlassSpringSettings"),&Z_Registration_Info_UScriptStruct_FCBLiquidGlassSpringSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCBLiquidGlassSpringSettings), 4164173022U) },
		{ FCBLiquidGlassControlStyle::StaticStruct, Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics::NewStructOps, TEXT("CBLiquidGlassControlStyle"),&Z_Registration_Info_UScriptStruct_FCBLiquidGlassControlStyle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCBLiquidGlassControlStyle), 3956690548U) },
		{ FCBLiquidGlassSearchBoxStyle::StaticStruct, Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics::NewStructOps, TEXT("CBLiquidGlassSearchBoxStyle"),&Z_Registration_Info_UScriptStruct_FCBLiquidGlassSearchBoxStyle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCBLiquidGlassSearchBoxStyle), 65488991U) },
		{ FCBLiquidGlassFusionBlob::StaticStruct, Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics::NewStructOps, TEXT("CBLiquidGlassFusionBlob"),&Z_Registration_Info_UScriptStruct_FCBLiquidGlassFusionBlob, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCBLiquidGlassFusionBlob), 4080855366U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h__Script_CBLiquidGlass_2464007766{
	TEXT("/Script/CBLiquidGlass"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h__Script_CBLiquidGlass_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h__Script_CBLiquidGlass_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h__Script_CBLiquidGlass_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h__Script_CBLiquidGlass_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

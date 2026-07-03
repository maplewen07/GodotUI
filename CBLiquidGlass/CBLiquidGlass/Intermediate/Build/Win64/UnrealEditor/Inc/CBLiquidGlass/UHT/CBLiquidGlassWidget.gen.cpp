// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassWidget() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlass();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlass_NoRegister();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UMG_API UClass* Z_Construct_UClass_UContentWidget();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCBLiquidGlass Function SetAdaptiveTintStrength **************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics
{
	struct CBLiquidGlass_eventSetAdaptiveTintStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Tint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets adaptive tinting that brightens over dark backgrounds and darkens over light ones. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets adaptive tinting that brightens over dark backgrounds and darkens over light ones." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetAdaptiveTintStrength constinit property declarations ***************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAdaptiveTintStrength constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAdaptiveTintStrength Property Definitions **************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetAdaptiveTintStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::PropPointers) < 2048);
// ********** End Function SetAdaptiveTintStrength Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetAdaptiveTintStrength", 	Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::CBLiquidGlass_eventSetAdaptiveTintStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::CBLiquidGlass_eventSetAdaptiveTintStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetAdaptiveTintStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAdaptiveTintStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetAdaptiveTintStrength ****************************

// ********** Begin Class UCBLiquidGlass Function SetAlphaMaskSoftness *****************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics
{
	struct CBLiquidGlass_eventSetAlphaMaskSoftness_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Mask" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the feather around AlphaMaskThreshold. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the feather around AlphaMaskThreshold." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetAlphaMaskSoftness constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAlphaMaskSoftness constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAlphaMaskSoftness Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetAlphaMaskSoftness_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::PropPointers) < 2048);
// ********** End Function SetAlphaMaskSoftness Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetAlphaMaskSoftness", 	Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::CBLiquidGlass_eventSetAlphaMaskSoftness_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::CBLiquidGlass_eventSetAlphaMaskSoftness_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetAlphaMaskSoftness)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAlphaMaskSoftness(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetAlphaMaskSoftness *******************************

// ********** Begin Class UCBLiquidGlass Function SetAlphaMaskTexture ******************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics
{
	struct CBLiquidGlass_eventSetAlphaMaskTexture_Parms
	{
		UTexture2D* InTexture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Mask" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets an optional arbitrary texture alpha/RGB mask for the glass silhouette. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets an optional arbitrary texture alpha/RGB mask for the glass silhouette." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetAlphaMaskTexture constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InTexture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAlphaMaskTexture constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAlphaMaskTexture Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::NewProp_InTexture = { "InTexture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetAlphaMaskTexture_Parms, InTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::NewProp_InTexture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::PropPointers) < 2048);
// ********** End Function SetAlphaMaskTexture Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetAlphaMaskTexture", 	Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::CBLiquidGlass_eventSetAlphaMaskTexture_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::CBLiquidGlass_eventSetAlphaMaskTexture_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetAlphaMaskTexture)
{
	P_GET_OBJECT(UTexture2D,Z_Param_InTexture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAlphaMaskTexture(Z_Param_InTexture);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetAlphaMaskTexture ********************************

// ********** Begin Class UCBLiquidGlass Function SetAlphaMaskThreshold ****************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics
{
	struct CBLiquidGlass_eventSetAlphaMaskThreshold_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Mask" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the mask threshold used when AlphaMaskTexture is assigned. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the mask threshold used when AlphaMaskTexture is assigned." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetAlphaMaskThreshold constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAlphaMaskThreshold constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAlphaMaskThreshold Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetAlphaMaskThreshold_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::PropPointers) < 2048);
// ********** End Function SetAlphaMaskThreshold Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetAlphaMaskThreshold", 	Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::CBLiquidGlass_eventSetAlphaMaskThreshold_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::CBLiquidGlass_eventSetAlphaMaskThreshold_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetAlphaMaskThreshold)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAlphaMaskThreshold(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetAlphaMaskThreshold ******************************

// ********** Begin Class UCBLiquidGlass Function SetBlurStrength **********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics
{
	struct CBLiquidGlass_eventSetBlurStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Blur" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets how far the captured background is blurred before it is composited back into the widget. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets how far the captured background is blurred before it is composited back into the widget." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetBlurStrength constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBlurStrength constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBlurStrength Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetBlurStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::PropPointers) < 2048);
// ********** End Function SetBlurStrength Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetBlurStrength", 	Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::CBLiquidGlass_eventSetBlurStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::CBLiquidGlass_eventSetBlurStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetBlurStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBlurStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetBlurStrength ************************************

// ********** Begin Class UCBLiquidGlass Function SetChromaticAberration ***************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics
{
	struct CBLiquidGlass_eventSetChromaticAberration_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Refraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the base red/green/blue split amount at refractive edges. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the base red/green/blue split amount at refractive edges." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetChromaticAberration constinit property declarations ****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetChromaticAberration constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetChromaticAberration Property Definitions ***************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetChromaticAberration_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::PropPointers) < 2048);
// ********** End Function SetChromaticAberration Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetChromaticAberration", 	Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::CBLiquidGlass_eventSetChromaticAberration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::CBLiquidGlass_eventSetChromaticAberration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetChromaticAberration)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetChromaticAberration(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetChromaticAberration *****************************

// ********** Begin Class UCBLiquidGlass Function SetDownsampleAmount ******************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics
{
	struct CBLiquidGlass_eventSetDownsampleAmount_Parms
	{
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Blur" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the blur buffer downsample factor; higher values are cheaper and softer. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the blur buffer downsample factor; higher values are cheaper and softer." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetDownsampleAmount constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDownsampleAmount constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDownsampleAmount Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetDownsampleAmount_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::PropPointers) < 2048);
// ********** End Function SetDownsampleAmount Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetDownsampleAmount", 	Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::CBLiquidGlass_eventSetDownsampleAmount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::CBLiquidGlass_eventSetDownsampleAmount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetDownsampleAmount)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDownsampleAmount(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetDownsampleAmount ********************************

// ********** Begin Class UCBLiquidGlass Function SetEdgeSoftness **********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics
{
	struct CBLiquidGlass_eventSetEdgeSoftness_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Shape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the antialiasing width multiplier for the analytic shape edge. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the antialiasing width multiplier for the analytic shape edge." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetEdgeSoftness constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetEdgeSoftness constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetEdgeSoftness Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetEdgeSoftness_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::PropPointers) < 2048);
// ********** End Function SetEdgeSoftness Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetEdgeSoftness", 	Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::CBLiquidGlass_eventSetEdgeSoftness_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::CBLiquidGlass_eventSetEdgeSoftness_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetEdgeSoftness)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetEdgeSoftness(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetEdgeSoftness ************************************

// ********** Begin Class UCBLiquidGlass Function SetFrostRadius ***********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics
{
	struct CBLiquidGlass_eventSetFrostRadius_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Blur" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the mix between the sharp captured image and the blurred frost image. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the mix between the sharp captured image and the blurred frost image." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetFrostRadius constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFrostRadius constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFrostRadius Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetFrostRadius_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::PropPointers) < 2048);
// ********** End Function SetFrostRadius Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetFrostRadius", 	Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::CBLiquidGlass_eventSetFrostRadius_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::CBLiquidGlass_eventSetFrostRadius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetFrostRadius)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFrostRadius(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetFrostRadius *************************************

// ********** Begin Class UCBLiquidGlass Function SetGlassOpacity **********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics
{
	struct CBLiquidGlass_eventSetGlassOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the final alpha of the glass composite while keeping child content fully crisp. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the final alpha of the glass composite while keeping child content fully crisp." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetGlassOpacity constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGlassOpacity constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGlassOpacity Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetGlassOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetGlassOpacity Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetGlassOpacity", 	Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::CBLiquidGlass_eventSetGlassOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::CBLiquidGlass_eventSetGlassOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetGlassOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGlassOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetGlassOpacity ************************************

// ********** Begin Class UCBLiquidGlass Function SetGlowAmount ************************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics
{
	struct CBLiquidGlass_eventSetGlowAmount_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Highlight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the directional edge sheen strength. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the directional edge sheen strength." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetGlowAmount constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGlowAmount constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGlowAmount Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetGlowAmount_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::PropPointers) < 2048);
// ********** End Function SetGlowAmount Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetGlowAmount", 	Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::CBLiquidGlass_eventSetGlowAmount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::CBLiquidGlass_eventSetGlowAmount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetGlowAmount)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGlowAmount(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetGlowAmount **************************************

// ********** Begin Class UCBLiquidGlass Function SetGlowAngle *************************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics
{
	struct CBLiquidGlass_eventSetGlowAngle_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Highlight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the rim light direction in degrees. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the rim light direction in degrees." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetGlowAngle constinit property declarations **************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGlowAngle constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGlowAngle Property Definitions *************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetGlowAngle_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::PropPointers) < 2048);
// ********** End Function SetGlowAngle Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetGlowAngle", 	Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::CBLiquidGlass_eventSetGlowAngle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::CBLiquidGlass_eventSetGlowAngle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetGlowAngle)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGlowAngle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetGlowAngle ***************************************

// ********** Begin Class UCBLiquidGlass Function SetIndexOfRefraction *****************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics
{
	struct CBLiquidGlass_eventSetIndexOfRefraction_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Refraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the stylized index of refraction; 1.0 disables lens amplification. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the stylized index of refraction; 1.0 disables lens amplification." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetIndexOfRefraction constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetIndexOfRefraction constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetIndexOfRefraction Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetIndexOfRefraction_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::PropPointers) < 2048);
// ********** End Function SetIndexOfRefraction Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetIndexOfRefraction", 	Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::CBLiquidGlass_eventSetIndexOfRefraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::CBLiquidGlass_eventSetIndexOfRefraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetIndexOfRefraction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetIndexOfRefraction(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetIndexOfRefraction *******************************

// ********** Begin Class UCBLiquidGlass Function SetInnerGlowIntensity ****************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics
{
	struct CBLiquidGlass_eventSetInnerGlowIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Highlight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the soft light added just inside the glass edge. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the soft light added just inside the glass edge." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetInnerGlowIntensity constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInnerGlowIntensity constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInnerGlowIntensity Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetInnerGlowIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetInnerGlowIntensity Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetInnerGlowIntensity", 	Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::CBLiquidGlass_eventSetInnerGlowIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::CBLiquidGlass_eventSetInnerGlowIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetInnerGlowIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInnerGlowIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetInnerGlowIntensity ******************************

// ********** Begin Class UCBLiquidGlass Function SetInnerShadowIntensity **************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics
{
	struct CBLiquidGlass_eventSetInnerShadowIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Highlight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the inner edge shadow that separates frosted glass from bright backgrounds. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the inner edge shadow that separates frosted glass from bright backgrounds." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetInnerShadowIntensity constinit property declarations ***************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInnerShadowIntensity constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInnerShadowIntensity Property Definitions **************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetInnerShadowIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetInnerShadowIntensity Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetInnerShadowIntensity", 	Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::CBLiquidGlass_eventSetInnerShadowIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::CBLiquidGlass_eventSetInnerShadowIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetInnerShadowIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInnerShadowIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetInnerShadowIntensity ****************************

// ********** Begin Class UCBLiquidGlass Function SetInvertAlphaMask *******************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics
{
	struct CBLiquidGlass_eventSetInvertAlphaMask_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Mask" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets whether the alpha mask is inverted before thresholding. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets whether the alpha mask is inverted before thresholding." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetInvertAlphaMask constinit property declarations ********************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInvertAlphaMask constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInvertAlphaMask Property Definitions *******************************
void Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlass_eventSetInvertAlphaMask_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlass_eventSetInvertAlphaMask_Parms), &Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::PropPointers) < 2048);
// ********** End Function SetInvertAlphaMask Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetInvertAlphaMask", 	Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::CBLiquidGlass_eventSetInvertAlphaMask_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::CBLiquidGlass_eventSetInvertAlphaMask_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetInvertAlphaMask)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInvertAlphaMask(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetInvertAlphaMask *********************************

// ********** Begin Class UCBLiquidGlass Function SetMotionDamping *********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics
{
	struct CBLiquidGlass_eventSetMotionDamping_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Motion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets how quickly motion deformation settles after movement stops. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets how quickly motion deformation settles after movement stops." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMotionDamping constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMotionDamping constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMotionDamping Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetMotionDamping_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::PropPointers) < 2048);
// ********** End Function SetMotionDamping Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetMotionDamping", 	Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::CBLiquidGlass_eventSetMotionDamping_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::CBLiquidGlass_eventSetMotionDamping_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetMotionDamping)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMotionDamping(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetMotionDamping ***********************************

// ********** Begin Class UCBLiquidGlass Function SetMotionMaxOffset *******************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics
{
	struct CBLiquidGlass_eventSetMotionMaxOffset_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Motion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the maximum movement offset used by motion deformation. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the maximum movement offset used by motion deformation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMotionMaxOffset constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMotionMaxOffset constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMotionMaxOffset Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetMotionMaxOffset_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::PropPointers) < 2048);
// ********** End Function SetMotionMaxOffset Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetMotionMaxOffset", 	Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::CBLiquidGlass_eventSetMotionMaxOffset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::CBLiquidGlass_eventSetMotionMaxOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetMotionMaxOffset)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMotionMaxOffset(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetMotionMaxOffset *********************************

// ********** Begin Class UCBLiquidGlass Function SetMotionResponse ********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics
{
	struct CBLiquidGlass_eventSetMotionResponse_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Motion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets how quickly motion deformation follows active movement. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets how quickly motion deformation follows active movement." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMotionResponse constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMotionResponse constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMotionResponse Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetMotionResponse_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::PropPointers) < 2048);
// ********** End Function SetMotionResponse Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetMotionResponse", 	Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::CBLiquidGlass_eventSetMotionResponse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::CBLiquidGlass_eventSetMotionResponse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetMotionResponse)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMotionResponse(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetMotionResponse **********************************

// ********** Begin Class UCBLiquidGlass Function SetMotionStrength ********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics
{
	struct CBLiquidGlass_eventSetMotionStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Motion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets how strongly widget movement stretches the glass shape and refraction. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets how strongly widget movement stretches the glass shape and refraction." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMotionStrength constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMotionStrength constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMotionStrength Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetMotionStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::PropPointers) < 2048);
// ********** End Function SetMotionStrength Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetMotionStrength", 	Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::CBLiquidGlass_eventSetMotionStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::CBLiquidGlass_eventSetMotionStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetMotionStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMotionStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetMotionStrength **********************************

// ********** Begin Class UCBLiquidGlass Function SetNoiseAmount ***********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics
{
	struct CBLiquidGlass_eventSetNoiseAmount_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Refraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the subtle grain amount used to reduce smooth blur and tint banding. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the subtle grain amount used to reduce smooth blur and tint banding." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetNoiseAmount constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetNoiseAmount constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetNoiseAmount Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetNoiseAmount_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::PropPointers) < 2048);
// ********** End Function SetNoiseAmount Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetNoiseAmount", 	Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::CBLiquidGlass_eventSetNoiseAmount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::CBLiquidGlass_eventSetNoiseAmount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetNoiseAmount)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetNoiseAmount(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetNoiseAmount *************************************

// ********** Begin Class UCBLiquidGlass Function SetPreset ****************************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics
{
	struct CBLiquidGlass_eventSetPreset_Parms
	{
		ECBLiquidGlassPreset InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Applies one of the built-in looks by copying its values into the editable properties. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Applies one of the built-in looks by copying its values into the editable properties." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetPreset constinit property declarations *****************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPreset constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPreset Property Definitions ****************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetPreset_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(0, nullptr) }; // 3360299489
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::PropPointers) < 2048);
// ********** End Function SetPreset Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetPreset", 	Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::CBLiquidGlass_eventSetPreset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::CBLiquidGlass_eventSetPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetPreset)
{
	P_GET_ENUM(ECBLiquidGlassPreset,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPreset(ECBLiquidGlassPreset(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetPreset ******************************************

// ********** Begin Class UCBLiquidGlass Function SetPrismIntensity ********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics
{
	struct CBLiquidGlass_eventSetPrismIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Refraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the extra multiplier for prism-like colour separation. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the extra multiplier for prism-like colour separation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetPrismIntensity constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPrismIntensity constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPrismIntensity Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetPrismIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetPrismIntensity Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetPrismIntensity", 	Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::CBLiquidGlass_eventSetPrismIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::CBLiquidGlass_eventSetPrismIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetPrismIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPrismIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetPrismIntensity **********************************

// ********** Begin Class UCBLiquidGlass Function SetQuality ***************************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics
{
	struct CBLiquidGlass_eventSetQuality_Parms
	{
		ECBLiquidGlassQuality InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the renderer quality profile. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the renderer quality profile." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetQuality constinit property declarations ****************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetQuality constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetQuality Property Definitions ***************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetQuality_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(0, nullptr) }; // 2771085032
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::PropPointers) < 2048);
// ********** End Function SetQuality Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetQuality", 	Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::CBLiquidGlass_eventSetQuality_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::CBLiquidGlass_eventSetQuality_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetQuality()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetQuality_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetQuality)
{
	P_GET_ENUM(ECBLiquidGlassQuality,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetQuality(ECBLiquidGlassQuality(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetQuality *****************************************

// ********** Begin Class UCBLiquidGlass Function SetRefractionPower *******************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics
{
	struct CBLiquidGlass_eventSetRefractionPower_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Refraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets how sharply refraction falls off from the edge toward the center. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets how sharply refraction falls off from the edge toward the center." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetRefractionPower constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRefractionPower constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRefractionPower Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetRefractionPower_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::PropPointers) < 2048);
// ********** End Function SetRefractionPower Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetRefractionPower", 	Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::CBLiquidGlass_eventSetRefractionPower_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::CBLiquidGlass_eventSetRefractionPower_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetRefractionPower)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRefractionPower(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetRefractionPower *********************************

// ********** Begin Class UCBLiquidGlass Function SetRefractionStrength ****************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics
{
	struct CBLiquidGlass_eventSetRefractionStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Refraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the overall lensing strength applied near the glass edge. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the overall lensing strength applied near the glass edge." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetRefractionStrength constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRefractionStrength constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRefractionStrength Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetRefractionStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::PropPointers) < 2048);
// ********** End Function SetRefractionStrength Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetRefractionStrength", 	Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::CBLiquidGlass_eventSetRefractionStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::CBLiquidGlass_eventSetRefractionStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetRefractionStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRefractionStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetRefractionStrength ******************************

// ********** Begin Class UCBLiquidGlass Function SetRefractionThickness ***************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics
{
	struct CBLiquidGlass_eventSetRefractionThickness_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Refraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the width, in pixels, of the edge band that bends background UVs. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the width, in pixels, of the edge band that bends background UVs." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetRefractionThickness constinit property declarations ****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRefractionThickness constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRefractionThickness Property Definitions ***************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetRefractionThickness_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::PropPointers) < 2048);
// ********** End Function SetRefractionThickness Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetRefractionThickness", 	Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::CBLiquidGlass_eventSetRefractionThickness_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::CBLiquidGlass_eventSetRefractionThickness_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetRefractionThickness)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRefractionThickness(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetRefractionThickness *****************************

// ********** Begin Class UCBLiquidGlass Function SetRimIntensity **********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics
{
	struct CBLiquidGlass_eventSetRimIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Highlight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the bright rim highlight intensity around the glass edge. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the bright rim highlight intensity around the glass edge." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetRimIntensity constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRimIntensity constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRimIntensity Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetRimIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetRimIntensity Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetRimIntensity", 	Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::CBLiquidGlass_eventSetRimIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::CBLiquidGlass_eventSetRimIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetRimIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRimIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetRimIntensity ************************************

// ********** Begin Class UCBLiquidGlass Function SetSaturation ************************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics
{
	struct CBLiquidGlass_eventSetSaturation_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Tint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the saturation multiplier applied before tint and edge lighting. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the saturation multiplier applied before tint and edge lighting." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSaturation constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSaturation constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSaturation Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetSaturation_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::PropPointers) < 2048);
// ********** End Function SetSaturation Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetSaturation", 	Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::CBLiquidGlass_eventSetSaturation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::CBLiquidGlass_eventSetSaturation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetSaturation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetSaturation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetSaturation)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSaturation(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetSaturation **************************************

// ********** Begin Class UCBLiquidGlass Function SetShape *****************************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics
{
	struct CBLiquidGlass_eventSetShape_Parms
	{
		ECBLiquidGlassShape InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Shape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the analytic shape used by the composite shader. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the analytic shape used by the composite shader." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShape constinit property declarations ******************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShape constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShape Property Definitions *****************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetShape_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape, METADATA_PARAMS(0, nullptr) }; // 1987497363
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::PropPointers) < 2048);
// ********** End Function SetShape Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetShape", 	Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::CBLiquidGlass_eventSetShape_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::CBLiquidGlass_eventSetShape_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetShape()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetShape_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetShape)
{
	P_GET_ENUM(ECBLiquidGlassShape,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShape(ECBLiquidGlassShape(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetShape *******************************************

// ********** Begin Class UCBLiquidGlass Function SetSquirclePower *********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics
{
	struct CBLiquidGlass_eventSetSquirclePower_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Shape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the superellipse corner power used by SuperellipseRect; higher values are boxier. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the superellipse corner power used by SuperellipseRect; higher values are boxier." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSquirclePower constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSquirclePower constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSquirclePower Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetSquirclePower_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::PropPointers) < 2048);
// ********** End Function SetSquirclePower Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetSquirclePower", 	Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::CBLiquidGlass_eventSetSquirclePower_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::CBLiquidGlass_eventSetSquirclePower_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetSquirclePower)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSquirclePower(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetSquirclePower ***********************************

// ********** Begin Class UCBLiquidGlass Function SetTintColor *************************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics
{
	struct CBLiquidGlass_eventSetTintColor_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Tint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the colour blended over the sampled background. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the colour blended over the sampled background." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTintColor constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTintColor constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTintColor Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetTintColor_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::PropPointers) < 2048);
// ********** End Function SetTintColor Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetTintColor", 	Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::CBLiquidGlass_eventSetTintColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::CBLiquidGlass_eventSetTintColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetTintColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetTintColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetTintColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTintColor(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetTintColor ***************************************

// ********** Begin Class UCBLiquidGlass Function SetTintOpacity ***********************************
struct Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics
{
	struct CBLiquidGlass_eventSetTintOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass|Tint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets how strongly TintColor is blended over the sampled background. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets how strongly TintColor is blended over the sampled background." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTintOpacity constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTintOpacity constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTintOpacity Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlass_eventSetTintOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetTintOpacity Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlass, nullptr, "SetTintOpacity", 	Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::CBLiquidGlass_eventSetTintOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::CBLiquidGlass_eventSetTintOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlass::execSetTintOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTintOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlass Function SetTintOpacity *************************************

// ********** Begin Class UCBLiquidGlass ***********************************************************
void UCBLiquidGlass::GetPreset_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	ECBLiquidGlassPreset& Result = *(ECBLiquidGlassPreset*)OutValue;
	Result = (ECBLiquidGlassPreset)Obj->GetPreset();
}
void UCBLiquidGlass::SetPreset_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	ECBLiquidGlassPreset& Value = *(ECBLiquidGlassPreset*)InValue;
	Obj->SetPreset(Value);
}
void UCBLiquidGlass::GetBlurStrength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetBlurStrength();
}
void UCBLiquidGlass::SetBlurStrength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetBlurStrength(Value);
}
void UCBLiquidGlass::GetDownsampleAmount_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	int32& Result = *(int32*)OutValue;
	Result = (int32)Obj->GetDownsampleAmount();
}
void UCBLiquidGlass::SetDownsampleAmount_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	int32& Value = *(int32*)InValue;
	Obj->SetDownsampleAmount(Value);
}
void UCBLiquidGlass::GetFrostRadius_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetFrostRadius();
}
void UCBLiquidGlass::SetFrostRadius_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetFrostRadius(Value);
}
void UCBLiquidGlass::GetShape_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	ECBLiquidGlassShape& Result = *(ECBLiquidGlassShape*)OutValue;
	Result = (ECBLiquidGlassShape)Obj->GetShape();
}
void UCBLiquidGlass::SetShape_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	ECBLiquidGlassShape& Value = *(ECBLiquidGlassShape*)InValue;
	Obj->SetShape(Value);
}
void UCBLiquidGlass::GetSquirclePower_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetSquirclePower();
}
void UCBLiquidGlass::SetSquirclePower_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetSquirclePower(Value);
}
void UCBLiquidGlass::GetEdgeSoftness_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetEdgeSoftness();
}
void UCBLiquidGlass::SetEdgeSoftness_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetEdgeSoftness(Value);
}
void UCBLiquidGlass::GetAlphaMaskTexture_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	UTexture2D*& Result = *(UTexture2D**)OutValue;
	Result = (UTexture2D*)Obj->GetAlphaMaskTexture();
}
void UCBLiquidGlass::SetAlphaMaskTexture_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	UTexture2D*& Value = *(UTexture2D**)InValue;
	Obj->SetAlphaMaskTexture(Value);
}
void UCBLiquidGlass::GetAlphaMaskThreshold_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetAlphaMaskThreshold();
}
void UCBLiquidGlass::SetAlphaMaskThreshold_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetAlphaMaskThreshold(Value);
}
void UCBLiquidGlass::GetAlphaMaskSoftness_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetAlphaMaskSoftness();
}
void UCBLiquidGlass::SetAlphaMaskSoftness_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetAlphaMaskSoftness(Value);
}
void UCBLiquidGlass::GetInvertAlphaMask_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetInvertAlphaMask();
}
void UCBLiquidGlass::SetInvertAlphaMask_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetInvertAlphaMask(Value);
}
void UCBLiquidGlass::GetRefractionStrength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetRefractionStrength();
}
void UCBLiquidGlass::SetRefractionStrength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetRefractionStrength(Value);
}
void UCBLiquidGlass::GetRefractionPower_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetRefractionPower();
}
void UCBLiquidGlass::SetRefractionPower_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetRefractionPower(Value);
}
void UCBLiquidGlass::GetRefractionThickness_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetRefractionThickness();
}
void UCBLiquidGlass::SetRefractionThickness_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetRefractionThickness(Value);
}
void UCBLiquidGlass::GetIndexOfRefraction_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetIndexOfRefraction();
}
void UCBLiquidGlass::SetIndexOfRefraction_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetIndexOfRefraction(Value);
}
void UCBLiquidGlass::GetChromaticAberration_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetChromaticAberration();
}
void UCBLiquidGlass::SetChromaticAberration_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetChromaticAberration(Value);
}
void UCBLiquidGlass::GetPrismIntensity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetPrismIntensity();
}
void UCBLiquidGlass::SetPrismIntensity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetPrismIntensity(Value);
}
void UCBLiquidGlass::GetNoiseAmount_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetNoiseAmount();
}
void UCBLiquidGlass::SetNoiseAmount_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetNoiseAmount(Value);
}
void UCBLiquidGlass::GetGlowAmount_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetGlowAmount();
}
void UCBLiquidGlass::SetGlowAmount_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetGlowAmount(Value);
}
void UCBLiquidGlass::GetRimIntensity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetRimIntensity();
}
void UCBLiquidGlass::SetRimIntensity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetRimIntensity(Value);
}
void UCBLiquidGlass::GetGlowAngle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetGlowAngle();
}
void UCBLiquidGlass::SetGlowAngle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetGlowAngle(Value);
}
void UCBLiquidGlass::GetInnerGlowIntensity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetInnerGlowIntensity();
}
void UCBLiquidGlass::SetInnerGlowIntensity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetInnerGlowIntensity(Value);
}
void UCBLiquidGlass::GetInnerShadowIntensity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetInnerShadowIntensity();
}
void UCBLiquidGlass::SetInnerShadowIntensity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetInnerShadowIntensity(Value);
}
void UCBLiquidGlass::GetTintColor_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetTintColor();
}
void UCBLiquidGlass::SetTintColor_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetTintColor(Value);
}
void UCBLiquidGlass::GetTintOpacity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetTintOpacity();
}
void UCBLiquidGlass::SetTintOpacity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetTintOpacity(Value);
}
void UCBLiquidGlass::GetSaturation_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetSaturation();
}
void UCBLiquidGlass::SetSaturation_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetSaturation(Value);
}
void UCBLiquidGlass::GetAdaptiveTintStrength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetAdaptiveTintStrength();
}
void UCBLiquidGlass::SetAdaptiveTintStrength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetAdaptiveTintStrength(Value);
}
void UCBLiquidGlass::GetGlassOpacity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetGlassOpacity();
}
void UCBLiquidGlass::SetGlassOpacity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetGlassOpacity(Value);
}
void UCBLiquidGlass::GetQuality_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	ECBLiquidGlassQuality& Result = *(ECBLiquidGlassQuality*)OutValue;
	Result = (ECBLiquidGlassQuality)Obj->GetQuality();
}
void UCBLiquidGlass::SetQuality_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	ECBLiquidGlassQuality& Value = *(ECBLiquidGlassQuality*)InValue;
	Obj->SetQuality(Value);
}
void UCBLiquidGlass::GetMotionStrength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMotionStrength();
}
void UCBLiquidGlass::SetMotionStrength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMotionStrength(Value);
}
void UCBLiquidGlass::GetMotionMaxOffset_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMotionMaxOffset();
}
void UCBLiquidGlass::SetMotionMaxOffset_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMotionMaxOffset(Value);
}
void UCBLiquidGlass::GetMotionResponse_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMotionResponse();
}
void UCBLiquidGlass::SetMotionResponse_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMotionResponse(Value);
}
void UCBLiquidGlass::GetMotionDamping_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlass* Obj = (const UCBLiquidGlass*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMotionDamping();
}
void UCBLiquidGlass::SetMotionDamping_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlass* Obj = (UCBLiquidGlass*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMotionDamping(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlass;
UClass* UCBLiquidGlass::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlass;
	if (!Z_Registration_Info_UClass_UCBLiquidGlass.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlass"),
			Z_Registration_Info_UClass_UCBLiquidGlass.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlass,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlass.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlass_NoRegister()
{
	return UCBLiquidGlass::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Liquid Glass is a single-child container that renders an Apple-style frosted, refracting\n * glass panel behind its content. The backbuffer behind the widget is captured, blurred,\n * lensed at the rounded edges (with chromatic aberration), adaptively tinted and given a\n * specular rim highlight. Place any UMG content inside; it is drawn crisply on top.\n */" },
#endif
		{ "DisplayName", "Liquid Glass" },
		{ "IncludePath", "CBLiquidGlassWidget.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Liquid Glass is a single-child container that renders an Apple-style frosted, refracting\nglass panel behind its content. The backbuffer behind the widget is captured, blurred,\nlensed at the rounded edges (with chromatic aberration), adaptively tinted and given a\nspecular rim highlight. Place any UMG content inside; it is drawn crisply on top." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[] = {
		{ "Category", "Liquid Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Writes a complete set of visual parameters. Editing any visual parameter switches this back to Custom. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Writes a complete set of visual parameters. Editing any visual parameter switches this back to Custom." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlurStrength_MetaData[] = {
		{ "Category", "Liquid Glass|Blur" },
		{ "ClampMax", "8.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How far the background is blurred (texel multiplier). Higher = frostier. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How far the background is blurred (texel multiplier). Higher = frostier." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DownsampleAmount_MetaData[] = {
		{ "Category", "Liquid Glass|Blur" },
		{ "ClampMax", "8" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Background is processed at 1/N resolution. Higher = cheaper and softer. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Background is processed at 1/N resolution. Higher = cheaper and softer." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrostRadius_MetaData[] = {
		{ "Category", "Liquid Glass|Blur" },
		{ "ClampMax", "1.5" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mix between the clear captured background and the blurred/frosted background. 0 = clear, 1 = frosted. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mix between the clear captured background and the blurred/frosted background. 0 = clear, 1 = frosted." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shape_MetaData[] = {
		{ "Category", "Liquid Glass|Shape" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shape mask used by the glass composite shader. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shape mask used by the glass composite shader." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SquirclePower_MetaData[] = {
		{ "Category", "Liquid Glass|Shape" },
		{ "ClampMax", "12.0" },
		{ "ClampMin", "2.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Squircle (superellipse) corner power. ~4-5 gives Apple's continuous-curvature corners; higher = boxier. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Squircle (superellipse) corner power. ~4-5 gives Apple's continuous-curvature corners; higher = boxier." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EdgeSoftness_MetaData[] = {
		{ "Category", "Liquid Glass|Shape" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Anti-aliasing width multiplier of the shape edge. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Anti-aliasing width multiplier of the shape edge." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaMaskTexture_MetaData[] = {
		{ "Category", "Liquid Glass|Mask" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional texture alpha/RGB mask. When set, this replaces the analytic shape and allows arbitrary glass silhouettes. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional texture alpha/RGB mask. When set, this replaces the analytic shape and allows arbitrary glass silhouettes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaMaskThreshold_MetaData[] = {
		{ "Category", "Liquid Glass|Mask" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mask value where pixels become glass; lower values include more of the texture. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mask value where pixels become glass; lower values include more of the texture." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaMaskSoftness_MetaData[] = {
		{ "Category", "Liquid Glass|Mask" },
		{ "ClampMax", "0.5" },
		{ "ClampMin", "0.001" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Soft feather around the threshold, in normalized alpha space. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Soft feather around the threshold, in normalized alpha space." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InvertAlphaMask_MetaData[] = {
		{ "Category", "Liquid Glass|Mask" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Inverts the alpha/RGB mask before thresholding. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inverts the alpha/RGB mask before thresholding." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefractionStrength_MetaData[] = {
		{ "Category", "Liquid Glass|Refraction" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lens intensity (0 = none, 1 = full Apple-style edge bending). */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lens intensity (0 = none, 1 = full Apple-style edge bending)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefractionPower_MetaData[] = {
		{ "Category", "Liquid Glass|Refraction" },
		{ "ClampMax", "6.0" },
		{ "ClampMin", "0.5" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Edge-bend sharpness: higher concentrates the refraction tighter against the rim. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Edge-bend sharpness: higher concentrates the refraction tighter against the rim." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefractionThickness_MetaData[] = {
		{ "Category", "Liquid Glass|Refraction" },
		{ "ClampMax", "160.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Width in pixels of the refracting edge band. Higher = thicker lensing at the edge. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Width in pixels of the refracting edge band. Higher = thicker lensing at the edge." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IndexOfRefraction_MetaData[] = {
		{ "Category", "Liquid Glass|Refraction" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Simplified index of refraction. 1 = no lens amplification; 2 gives a strong glass bend. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simplified index of refraction. 1 = no lens amplification; 2 gives a strong glass bend." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChromaticAberration_MetaData[] = {
		{ "Category", "Liquid Glass|Refraction" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** RGB split amount at the refracting edges. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "RGB split amount at the refracting edges." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrismIntensity_MetaData[] = {
		{ "Category", "Liquid Glass|Refraction" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extra multiplier for prism-like colour separation at refracting edges. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extra multiplier for prism-like colour separation at refracting edges." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NoiseAmount_MetaData[] = {
		{ "Category", "Liquid Glass|Refraction" },
		{ "ClampMax", "0.3" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Grain/dither added to the glass to break up gradient banding. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grain/dither added to the glass to break up gradient banding." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlowAmount_MetaData[] = {
		{ "Category", "Liquid Glass|Highlight" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Directional edge sheen strength (brighter on the lit side, darker opposite). */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Directional edge sheen strength (brighter on the lit side, darker opposite)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RimIntensity_MetaData[] = {
		{ "Category", "Liquid Glass|Highlight" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Bright white edge rim brightness. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bright white edge rim brightness." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlowAngle_MetaData[] = {
		{ "Category", "Liquid Glass|Highlight" },
		{ "ClampMax", "180.0" },
		{ "ClampMin", "-180.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Direction of the rim light/sheen, in degrees. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Direction of the rim light/sheen, in degrees." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InnerGlowIntensity_MetaData[] = {
		{ "Category", "Liquid Glass|Highlight" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Soft glow inside the glass edge band. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Soft glow inside the glass edge band." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InnerShadowIntensity_MetaData[] = {
		{ "Category", "Liquid Glass|Highlight" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Subtle inner edge shadow that helps menu glass separate from bright backgrounds. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Subtle inner edge shadow that helps menu glass separate from bright backgrounds." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TintColor_MetaData[] = {
		{ "Category", "Liquid Glass|Tint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Glass tint colour. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Glass tint colour." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TintOpacity_MetaData[] = {
		{ "Category", "Liquid Glass|Tint" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How strongly the tint colour is applied. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How strongly the tint colour is applied." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Saturation_MetaData[] = {
		{ "Category", "Liquid Glass|Tint" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Background saturation multiplier (1 = unchanged). Apple's glass boosts colour vibrancy. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Background saturation multiplier (1 = unchanged). Apple's glass boosts colour vibrancy." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdaptiveTintStrength_MetaData[] = {
		{ "Category", "Liquid Glass|Tint" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Luminance-adaptive tint: brighten over dark backgrounds, darken over light ones. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Luminance-adaptive tint: brighten over dark backgrounds, darken over light ones." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlassOpacity_MetaData[] = {
		{ "Category", "Liquid Glass" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Overall opacity of the glass effect. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Overall opacity of the glass effect." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quality_MetaData[] = {
		{ "Category", "Liquid Glass|Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Runtime quality profile that trades blur/prism detail for cost. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime quality profile that trades blur/prism detail for cost." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionStrength_MetaData[] = {
		{ "Category", "Liquid Glass|Motion" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Amount of stretch applied when the widget moves; 0 disables liquid motion deformation. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Amount of stretch applied when the widget moves; 0 disables liquid motion deformation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionMaxOffset_MetaData[] = {
		{ "Category", "Liquid Glass|Motion" },
		{ "ClampMax", "160.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum movement offset, in pixels, used by the deformation solver. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum movement offset, in pixels, used by the deformation solver." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionResponse_MetaData[] = {
		{ "Category", "Liquid Glass|Motion" },
		{ "ClampMax", "40.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How quickly the glass catches up while it is moving. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How quickly the glass catches up while it is moving." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionDamping_MetaData[] = {
		{ "Category", "Liquid Glass|Motion" },
		{ "ClampMax", "40.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How quickly the glass returns to rest after movement stops. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How quickly the glass returns to rest after movement stops." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlass constinit property declarations ***************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlurStrength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DownsampleAmount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrostRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Shape_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Shape;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SquirclePower;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EdgeSoftness;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AlphaMaskTexture;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AlphaMaskThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AlphaMaskSoftness;
	static void NewProp_InvertAlphaMask_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InvertAlphaMask;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RefractionStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RefractionPower;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RefractionThickness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IndexOfRefraction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChromaticAberration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PrismIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NoiseAmount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlowAmount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RimIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlowAngle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InnerGlowIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InnerShadowIntensity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TintColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TintOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Saturation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AdaptiveTintStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlassOpacity;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Quality_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Quality;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MotionStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MotionMaxOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MotionResponse;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MotionDamping;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlass constinit property declarations *****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetAdaptiveTintStrength"), .Pointer = &UCBLiquidGlass::execSetAdaptiveTintStrength },
		{ .NameUTF8 = UTF8TEXT("SetAlphaMaskSoftness"), .Pointer = &UCBLiquidGlass::execSetAlphaMaskSoftness },
		{ .NameUTF8 = UTF8TEXT("SetAlphaMaskTexture"), .Pointer = &UCBLiquidGlass::execSetAlphaMaskTexture },
		{ .NameUTF8 = UTF8TEXT("SetAlphaMaskThreshold"), .Pointer = &UCBLiquidGlass::execSetAlphaMaskThreshold },
		{ .NameUTF8 = UTF8TEXT("SetBlurStrength"), .Pointer = &UCBLiquidGlass::execSetBlurStrength },
		{ .NameUTF8 = UTF8TEXT("SetChromaticAberration"), .Pointer = &UCBLiquidGlass::execSetChromaticAberration },
		{ .NameUTF8 = UTF8TEXT("SetDownsampleAmount"), .Pointer = &UCBLiquidGlass::execSetDownsampleAmount },
		{ .NameUTF8 = UTF8TEXT("SetEdgeSoftness"), .Pointer = &UCBLiquidGlass::execSetEdgeSoftness },
		{ .NameUTF8 = UTF8TEXT("SetFrostRadius"), .Pointer = &UCBLiquidGlass::execSetFrostRadius },
		{ .NameUTF8 = UTF8TEXT("SetGlassOpacity"), .Pointer = &UCBLiquidGlass::execSetGlassOpacity },
		{ .NameUTF8 = UTF8TEXT("SetGlowAmount"), .Pointer = &UCBLiquidGlass::execSetGlowAmount },
		{ .NameUTF8 = UTF8TEXT("SetGlowAngle"), .Pointer = &UCBLiquidGlass::execSetGlowAngle },
		{ .NameUTF8 = UTF8TEXT("SetIndexOfRefraction"), .Pointer = &UCBLiquidGlass::execSetIndexOfRefraction },
		{ .NameUTF8 = UTF8TEXT("SetInnerGlowIntensity"), .Pointer = &UCBLiquidGlass::execSetInnerGlowIntensity },
		{ .NameUTF8 = UTF8TEXT("SetInnerShadowIntensity"), .Pointer = &UCBLiquidGlass::execSetInnerShadowIntensity },
		{ .NameUTF8 = UTF8TEXT("SetInvertAlphaMask"), .Pointer = &UCBLiquidGlass::execSetInvertAlphaMask },
		{ .NameUTF8 = UTF8TEXT("SetMotionDamping"), .Pointer = &UCBLiquidGlass::execSetMotionDamping },
		{ .NameUTF8 = UTF8TEXT("SetMotionMaxOffset"), .Pointer = &UCBLiquidGlass::execSetMotionMaxOffset },
		{ .NameUTF8 = UTF8TEXT("SetMotionResponse"), .Pointer = &UCBLiquidGlass::execSetMotionResponse },
		{ .NameUTF8 = UTF8TEXT("SetMotionStrength"), .Pointer = &UCBLiquidGlass::execSetMotionStrength },
		{ .NameUTF8 = UTF8TEXT("SetNoiseAmount"), .Pointer = &UCBLiquidGlass::execSetNoiseAmount },
		{ .NameUTF8 = UTF8TEXT("SetPreset"), .Pointer = &UCBLiquidGlass::execSetPreset },
		{ .NameUTF8 = UTF8TEXT("SetPrismIntensity"), .Pointer = &UCBLiquidGlass::execSetPrismIntensity },
		{ .NameUTF8 = UTF8TEXT("SetQuality"), .Pointer = &UCBLiquidGlass::execSetQuality },
		{ .NameUTF8 = UTF8TEXT("SetRefractionPower"), .Pointer = &UCBLiquidGlass::execSetRefractionPower },
		{ .NameUTF8 = UTF8TEXT("SetRefractionStrength"), .Pointer = &UCBLiquidGlass::execSetRefractionStrength },
		{ .NameUTF8 = UTF8TEXT("SetRefractionThickness"), .Pointer = &UCBLiquidGlass::execSetRefractionThickness },
		{ .NameUTF8 = UTF8TEXT("SetRimIntensity"), .Pointer = &UCBLiquidGlass::execSetRimIntensity },
		{ .NameUTF8 = UTF8TEXT("SetSaturation"), .Pointer = &UCBLiquidGlass::execSetSaturation },
		{ .NameUTF8 = UTF8TEXT("SetShape"), .Pointer = &UCBLiquidGlass::execSetShape },
		{ .NameUTF8 = UTF8TEXT("SetSquirclePower"), .Pointer = &UCBLiquidGlass::execSetSquirclePower },
		{ .NameUTF8 = UTF8TEXT("SetTintColor"), .Pointer = &UCBLiquidGlass::execSetTintColor },
		{ .NameUTF8 = UTF8TEXT("SetTintOpacity"), .Pointer = &UCBLiquidGlass::execSetTintOpacity },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetAdaptiveTintStrength, "SetAdaptiveTintStrength" }, // 4116340203
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskSoftness, "SetAlphaMaskSoftness" }, // 2629165911
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskTexture, "SetAlphaMaskTexture" }, // 3052708743
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetAlphaMaskThreshold, "SetAlphaMaskThreshold" }, // 600046945
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetBlurStrength, "SetBlurStrength" }, // 2798740413
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetChromaticAberration, "SetChromaticAberration" }, // 3393280436
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetDownsampleAmount, "SetDownsampleAmount" }, // 2482481933
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetEdgeSoftness, "SetEdgeSoftness" }, // 3900369962
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetFrostRadius, "SetFrostRadius" }, // 4252523214
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetGlassOpacity, "SetGlassOpacity" }, // 2041149954
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetGlowAmount, "SetGlowAmount" }, // 1466267987
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetGlowAngle, "SetGlowAngle" }, // 3186719603
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetIndexOfRefraction, "SetIndexOfRefraction" }, // 916661448
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetInnerGlowIntensity, "SetInnerGlowIntensity" }, // 3463586615
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetInnerShadowIntensity, "SetInnerShadowIntensity" }, // 2052078049
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetInvertAlphaMask, "SetInvertAlphaMask" }, // 2048160981
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetMotionDamping, "SetMotionDamping" }, // 88118493
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetMotionMaxOffset, "SetMotionMaxOffset" }, // 1899504651
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetMotionResponse, "SetMotionResponse" }, // 1261140993
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetMotionStrength, "SetMotionStrength" }, // 1187654978
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetNoiseAmount, "SetNoiseAmount" }, // 3100321555
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetPreset, "SetPreset" }, // 1104447743
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetPrismIntensity, "SetPrismIntensity" }, // 936473585
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetQuality, "SetQuality" }, // 17251368
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetRefractionPower, "SetRefractionPower" }, // 1522527071
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetRefractionStrength, "SetRefractionStrength" }, // 2032077950
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetRefractionThickness, "SetRefractionThickness" }, // 1030909146
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetRimIntensity, "SetRimIntensity" }, // 4069396012
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetSaturation, "SetSaturation" }, // 1833750009
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetShape, "SetShape" }, // 1134189474
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetSquirclePower, "SetSquirclePower" }, // 653477829
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetTintColor, "SetTintColor" }, // 836993823
		{ &Z_Construct_UFunction_UCBLiquidGlass_SetTintOpacity, "SetTintOpacity" }, // 3695339818
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlass>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlass_Statics

// ********** Begin Class UCBLiquidGlass Property Definitions **************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetPreset_WrapperImpl, &UCBLiquidGlass::GetPreset_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, Preset), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Preset_MetaData), NewProp_Preset_MetaData) }; // 3360299489
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_BlurStrength = { "BlurStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetBlurStrength_WrapperImpl, &UCBLiquidGlass::GetBlurStrength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, BlurStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlurStrength_MetaData), NewProp_BlurStrength_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_DownsampleAmount = { "DownsampleAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetDownsampleAmount_WrapperImpl, &UCBLiquidGlass::GetDownsampleAmount_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, DownsampleAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DownsampleAmount_MetaData), NewProp_DownsampleAmount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_FrostRadius = { "FrostRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetFrostRadius_WrapperImpl, &UCBLiquidGlass::GetFrostRadius_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, FrostRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrostRadius_MetaData), NewProp_FrostRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Shape_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Shape = { "Shape", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetShape_WrapperImpl, &UCBLiquidGlass::GetShape_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, Shape), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shape_MetaData), NewProp_Shape_MetaData) }; // 1987497363
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_SquirclePower = { "SquirclePower", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetSquirclePower_WrapperImpl, &UCBLiquidGlass::GetSquirclePower_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, SquirclePower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SquirclePower_MetaData), NewProp_SquirclePower_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_EdgeSoftness = { "EdgeSoftness", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetEdgeSoftness_WrapperImpl, &UCBLiquidGlass::GetEdgeSoftness_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, EdgeSoftness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EdgeSoftness_MetaData), NewProp_EdgeSoftness_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_AlphaMaskTexture = { "AlphaMaskTexture", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetAlphaMaskTexture_WrapperImpl, &UCBLiquidGlass::GetAlphaMaskTexture_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, AlphaMaskTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaMaskTexture_MetaData), NewProp_AlphaMaskTexture_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_AlphaMaskThreshold = { "AlphaMaskThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetAlphaMaskThreshold_WrapperImpl, &UCBLiquidGlass::GetAlphaMaskThreshold_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, AlphaMaskThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaMaskThreshold_MetaData), NewProp_AlphaMaskThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_AlphaMaskSoftness = { "AlphaMaskSoftness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetAlphaMaskSoftness_WrapperImpl, &UCBLiquidGlass::GetAlphaMaskSoftness_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, AlphaMaskSoftness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaMaskSoftness_MetaData), NewProp_AlphaMaskSoftness_MetaData) };
void Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_InvertAlphaMask_SetBit(void* Obj)
{
	((UCBLiquidGlass*)Obj)->InvertAlphaMask = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_InvertAlphaMask = { "InvertAlphaMask", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetInvertAlphaMask_WrapperImpl, &UCBLiquidGlass::GetInvertAlphaMask_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlass), &Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_InvertAlphaMask_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InvertAlphaMask_MetaData), NewProp_InvertAlphaMask_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_RefractionStrength = { "RefractionStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetRefractionStrength_WrapperImpl, &UCBLiquidGlass::GetRefractionStrength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, RefractionStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefractionStrength_MetaData), NewProp_RefractionStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_RefractionPower = { "RefractionPower", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetRefractionPower_WrapperImpl, &UCBLiquidGlass::GetRefractionPower_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, RefractionPower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefractionPower_MetaData), NewProp_RefractionPower_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_RefractionThickness = { "RefractionThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetRefractionThickness_WrapperImpl, &UCBLiquidGlass::GetRefractionThickness_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, RefractionThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefractionThickness_MetaData), NewProp_RefractionThickness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_IndexOfRefraction = { "IndexOfRefraction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetIndexOfRefraction_WrapperImpl, &UCBLiquidGlass::GetIndexOfRefraction_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, IndexOfRefraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IndexOfRefraction_MetaData), NewProp_IndexOfRefraction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_ChromaticAberration = { "ChromaticAberration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetChromaticAberration_WrapperImpl, &UCBLiquidGlass::GetChromaticAberration_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, ChromaticAberration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChromaticAberration_MetaData), NewProp_ChromaticAberration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_PrismIntensity = { "PrismIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetPrismIntensity_WrapperImpl, &UCBLiquidGlass::GetPrismIntensity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, PrismIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrismIntensity_MetaData), NewProp_PrismIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_NoiseAmount = { "NoiseAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetNoiseAmount_WrapperImpl, &UCBLiquidGlass::GetNoiseAmount_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, NoiseAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NoiseAmount_MetaData), NewProp_NoiseAmount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_GlowAmount = { "GlowAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetGlowAmount_WrapperImpl, &UCBLiquidGlass::GetGlowAmount_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, GlowAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlowAmount_MetaData), NewProp_GlowAmount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_RimIntensity = { "RimIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetRimIntensity_WrapperImpl, &UCBLiquidGlass::GetRimIntensity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, RimIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RimIntensity_MetaData), NewProp_RimIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_GlowAngle = { "GlowAngle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetGlowAngle_WrapperImpl, &UCBLiquidGlass::GetGlowAngle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, GlowAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlowAngle_MetaData), NewProp_GlowAngle_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_InnerGlowIntensity = { "InnerGlowIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetInnerGlowIntensity_WrapperImpl, &UCBLiquidGlass::GetInnerGlowIntensity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, InnerGlowIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InnerGlowIntensity_MetaData), NewProp_InnerGlowIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_InnerShadowIntensity = { "InnerShadowIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetInnerShadowIntensity_WrapperImpl, &UCBLiquidGlass::GetInnerShadowIntensity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, InnerShadowIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InnerShadowIntensity_MetaData), NewProp_InnerShadowIntensity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_TintColor = { "TintColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetTintColor_WrapperImpl, &UCBLiquidGlass::GetTintColor_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, TintColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TintColor_MetaData), NewProp_TintColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_TintOpacity = { "TintOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetTintOpacity_WrapperImpl, &UCBLiquidGlass::GetTintOpacity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, TintOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TintOpacity_MetaData), NewProp_TintOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Saturation = { "Saturation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetSaturation_WrapperImpl, &UCBLiquidGlass::GetSaturation_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, Saturation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Saturation_MetaData), NewProp_Saturation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_AdaptiveTintStrength = { "AdaptiveTintStrength", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetAdaptiveTintStrength_WrapperImpl, &UCBLiquidGlass::GetAdaptiveTintStrength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, AdaptiveTintStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdaptiveTintStrength_MetaData), NewProp_AdaptiveTintStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_GlassOpacity = { "GlassOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetGlassOpacity_WrapperImpl, &UCBLiquidGlass::GetGlassOpacity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, GlassOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlassOpacity_MetaData), NewProp_GlassOpacity_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Quality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Quality = { "Quality", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetQuality_WrapperImpl, &UCBLiquidGlass::GetQuality_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, Quality), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quality_MetaData), NewProp_Quality_MetaData) }; // 2771085032
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_MotionStrength = { "MotionStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetMotionStrength_WrapperImpl, &UCBLiquidGlass::GetMotionStrength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, MotionStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionStrength_MetaData), NewProp_MotionStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_MotionMaxOffset = { "MotionMaxOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetMotionMaxOffset_WrapperImpl, &UCBLiquidGlass::GetMotionMaxOffset_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, MotionMaxOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionMaxOffset_MetaData), NewProp_MotionMaxOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_MotionResponse = { "MotionResponse", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetMotionResponse_WrapperImpl, &UCBLiquidGlass::GetMotionResponse_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, MotionResponse), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionResponse_MetaData), NewProp_MotionResponse_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_MotionDamping = { "MotionDamping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlass::SetMotionDamping_WrapperImpl, &UCBLiquidGlass::GetMotionDamping_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlass, MotionDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionDamping_MetaData), NewProp_MotionDamping_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_BlurStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_DownsampleAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_FrostRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Shape_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Shape,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_SquirclePower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_EdgeSoftness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_AlphaMaskTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_AlphaMaskThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_AlphaMaskSoftness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_InvertAlphaMask,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_RefractionStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_RefractionPower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_RefractionThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_IndexOfRefraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_ChromaticAberration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_PrismIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_NoiseAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_GlowAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_RimIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_GlowAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_InnerGlowIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_InnerShadowIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_TintColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_TintOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Saturation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_AdaptiveTintStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_GlassOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Quality_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_Quality,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_MotionStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_MotionMaxOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_MotionResponse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlass_Statics::NewProp_MotionDamping,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlass_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlass Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlass_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UContentWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlass_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlass_Statics::ClassParams = {
	&UCBLiquidGlass::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlass_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlass_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlass_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlass_Statics::Class_MetaDataParams)
};
void UCBLiquidGlass::StaticRegisterNativesUCBLiquidGlass()
{
	UClass* Class = UCBLiquidGlass::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlass_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlass()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlass.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlass.OuterSingleton, Z_Construct_UClass_UCBLiquidGlass_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlass.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlass);
UCBLiquidGlass::~UCBLiquidGlass() {}
// ********** End Class UCBLiquidGlass *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h__Script_CBLiquidGlass_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCBLiquidGlass, UCBLiquidGlass::StaticClass, TEXT("UCBLiquidGlass"), &Z_Registration_Info_UClass_UCBLiquidGlass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlass), 2565948044U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h__Script_CBLiquidGlass_1770746774{
	TEXT("/Script/CBLiquidGlass"),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h__Script_CBLiquidGlass_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h__Script_CBLiquidGlass_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassText.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassText() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassText();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassText_NoRegister();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateFontInfo();
UMG_API UClass* Z_Construct_UClass_UWidget();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCBLiquidGlassText Function SetColorAndOpacity ***************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics
{
	struct CBLiquidGlassText_eventSetColorAndOpacity_Parms
	{
		FSlateColor InColorAndOpacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetColorAndOpacity constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InColorAndOpacity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetColorAndOpacity constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetColorAndOpacity Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::NewProp_InColorAndOpacity = { "InColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetColorAndOpacity_Parms, InColorAndOpacity), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(0, nullptr) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::NewProp_InColorAndOpacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetColorAndOpacity Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetColorAndOpacity", 	Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::CBLiquidGlassText_eventSetColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::CBLiquidGlassText_eventSetColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetColorAndOpacity)
{
	P_GET_STRUCT(FSlateColor,Z_Param_InColorAndOpacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetColorAndOpacity(Z_Param_InColorAndOpacity);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetColorAndOpacity *****************************

// ********** Begin Class UCBLiquidGlassText Function SetFont **************************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics
{
	struct CBLiquidGlassText_eventSetFont_Parms
	{
		FSlateFontInfo InFont;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFont constinit property declarations *******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InFont;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFont constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFont Property Definitions ******************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::NewProp_InFont = { "InFont", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetFont_Parms, InFont), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(0, nullptr) }; // 167205173
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::NewProp_InFont,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::PropPointers) < 2048);
// ********** End Function SetFont Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetFont", 	Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::CBLiquidGlassText_eventSetFont_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::CBLiquidGlassText_eventSetFont_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetFont()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetFont_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetFont)
{
	P_GET_STRUCT(FSlateFontInfo,Z_Param_InFont);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFont(Z_Param_InFont);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetFont ****************************************

// ********** Begin Class UCBLiquidGlassText Function SetFrostRadius *******************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics
{
	struct CBLiquidGlassText_eventSetFrostRadius_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text|Glass" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFrostRadius constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFrostRadius constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFrostRadius Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetFrostRadius_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::PropPointers) < 2048);
// ********** End Function SetFrostRadius Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetFrostRadius", 	Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::CBLiquidGlassText_eventSetFrostRadius_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::CBLiquidGlassText_eventSetFrostRadius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetFrostRadius)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFrostRadius(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetFrostRadius *********************************

// ********** Begin Class UCBLiquidGlassText Function SetGlyphThickness ****************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics
{
	struct CBLiquidGlassText_eventSetGlyphThickness_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text|Typography" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetGlyphThickness constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGlyphThickness constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGlyphThickness Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetGlyphThickness_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::PropPointers) < 2048);
// ********** End Function SetGlyphThickness Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetGlyphThickness", 	Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::CBLiquidGlassText_eventSetGlyphThickness_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::CBLiquidGlassText_eventSetGlyphThickness_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetGlyphThickness)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGlyphThickness(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetGlyphThickness ******************************

// ********** Begin Class UCBLiquidGlassText Function SetLetterSpacing *****************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics
{
	struct CBLiquidGlassText_eventSetLetterSpacing_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text|Typography" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetLetterSpacing constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLetterSpacing constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLetterSpacing Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetLetterSpacing_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::PropPointers) < 2048);
// ********** End Function SetLetterSpacing Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetLetterSpacing", 	Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::CBLiquidGlassText_eventSetLetterSpacing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::CBLiquidGlassText_eventSetLetterSpacing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetLetterSpacing)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLetterSpacing(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetLetterSpacing *******************************

// ********** Begin Class UCBLiquidGlassText Function SetLineSpacing *******************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics
{
	struct CBLiquidGlassText_eventSetLineSpacing_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text|Typography" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetLineSpacing constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLineSpacing constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLineSpacing Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetLineSpacing_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::PropPointers) < 2048);
// ********** End Function SetLineSpacing Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetLineSpacing", 	Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::CBLiquidGlassText_eventSetLineSpacing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::CBLiquidGlassText_eventSetLineSpacing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetLineSpacing)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLineSpacing(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetLineSpacing *********************************

// ********** Begin Class UCBLiquidGlassText Function SetMotionStrength ****************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics
{
	struct CBLiquidGlassText_eventSetMotionStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text|Motion" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMotionStrength constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMotionStrength constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMotionStrength Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetMotionStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::PropPointers) < 2048);
// ********** End Function SetMotionStrength Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetMotionStrength", 	Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::CBLiquidGlassText_eventSetMotionStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::CBLiquidGlassText_eventSetMotionStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetMotionStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMotionStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetMotionStrength ******************************

// ********** Begin Class UCBLiquidGlassText Function SetPreset ************************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics
{
	struct CBLiquidGlassText_eventSetPreset_Parms
	{
		ECBLiquidGlassPreset InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text|Glass" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetPreset_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(0, nullptr) }; // 3360299489
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::PropPointers) < 2048);
// ********** End Function SetPreset Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetPreset", 	Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::CBLiquidGlassText_eventSetPreset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::CBLiquidGlassText_eventSetPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetPreset)
{
	P_GET_ENUM(ECBLiquidGlassPreset,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPreset(ECBLiquidGlassPreset(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetPreset **************************************

// ********** Begin Class UCBLiquidGlassText Function SetQuality ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics
{
	struct CBLiquidGlassText_eventSetQuality_Parms
	{
		ECBLiquidGlassQuality InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text|Glass" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetQuality_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(0, nullptr) }; // 2771085032
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::PropPointers) < 2048);
// ********** End Function SetQuality Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetQuality", 	Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::CBLiquidGlassText_eventSetQuality_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::CBLiquidGlassText_eventSetQuality_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetQuality()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetQuality_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetQuality)
{
	P_GET_ENUM(ECBLiquidGlassQuality,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetQuality(ECBLiquidGlassQuality(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetQuality *************************************

// ********** Begin Class UCBLiquidGlassText Function SetText **************************************
struct Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics
{
	struct CBLiquidGlassText_eventSetText_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Text" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetText constinit property declarations *******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetText constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetText Property Definitions ******************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassText_eventSetText_Parms, InText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::PropPointers) < 2048);
// ********** End Function SetText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassText, nullptr, "SetText", 	Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::CBLiquidGlassText_eventSetText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::CBLiquidGlassText_eventSetText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassText_SetText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassText_SetText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassText::execSetText)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetText(Z_Param_InText);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassText Function SetText ****************************************

// ********** Begin Class UCBLiquidGlassText *******************************************************
void UCBLiquidGlassText::GetText_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	FText& Result = *(FText*)OutValue;
	Result = (FText)Obj->GetText();
}
void UCBLiquidGlassText::SetText_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	FText& Value = *(FText*)InValue;
	Obj->SetText(Value);
}
void UCBLiquidGlassText::GetFont_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	FSlateFontInfo& Result = *(FSlateFontInfo*)OutValue;
	Result = (FSlateFontInfo)Obj->GetFont();
}
void UCBLiquidGlassText::SetFont_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	FSlateFontInfo& Value = *(FSlateFontInfo*)InValue;
	Obj->SetFont(Value);
}
void UCBLiquidGlassText::GetColorAndOpacity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	FSlateColor& Result = *(FSlateColor*)OutValue;
	Result = (FSlateColor)Obj->GetColorAndOpacity();
}
void UCBLiquidGlassText::SetColorAndOpacity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	FSlateColor& Value = *(FSlateColor*)InValue;
	Obj->SetColorAndOpacity(Value);
}
void UCBLiquidGlassText::GetPreset_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	ECBLiquidGlassPreset& Result = *(ECBLiquidGlassPreset*)OutValue;
	Result = (ECBLiquidGlassPreset)Obj->GetPreset();
}
void UCBLiquidGlassText::SetPreset_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	ECBLiquidGlassPreset& Value = *(ECBLiquidGlassPreset*)InValue;
	Obj->SetPreset(Value);
}
void UCBLiquidGlassText::GetQuality_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	ECBLiquidGlassQuality& Result = *(ECBLiquidGlassQuality*)OutValue;
	Result = (ECBLiquidGlassQuality)Obj->GetQuality();
}
void UCBLiquidGlassText::SetQuality_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	ECBLiquidGlassQuality& Value = *(ECBLiquidGlassQuality*)InValue;
	Obj->SetQuality(Value);
}
void UCBLiquidGlassText::GetFrostRadius_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetFrostRadius();
}
void UCBLiquidGlassText::SetFrostRadius_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	float& Value = *(float*)InValue;
	Obj->SetFrostRadius(Value);
}
void UCBLiquidGlassText::GetGlyphThickness_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetGlyphThickness();
}
void UCBLiquidGlassText::SetGlyphThickness_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	float& Value = *(float*)InValue;
	Obj->SetGlyphThickness(Value);
}
void UCBLiquidGlassText::GetLetterSpacing_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetLetterSpacing();
}
void UCBLiquidGlassText::SetLetterSpacing_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	float& Value = *(float*)InValue;
	Obj->SetLetterSpacing(Value);
}
void UCBLiquidGlassText::GetLineSpacing_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetLineSpacing();
}
void UCBLiquidGlassText::SetLineSpacing_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	float& Value = *(float*)InValue;
	Obj->SetLineSpacing(Value);
}
void UCBLiquidGlassText::GetMotionStrength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassText* Obj = (const UCBLiquidGlassText*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMotionStrength();
}
void UCBLiquidGlassText::SetMotionStrength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassText* Obj = (UCBLiquidGlassText*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMotionStrength(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassText;
UClass* UCBLiquidGlassText::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassText;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassText.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassText"),
			Z_Registration_Info_UClass_UCBLiquidGlassText.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassText,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassText.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassText_NoRegister()
{
	return UCBLiquidGlassText::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassText_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UMG wrapper for liquid-glass text.\n *\n * Unlike a normal TextBlock, the visible glyphs are copied into an alpha mask and used\n * as the glass shape. The selected Slate font and fallback chain decide which scripts\n * are available, so Chinese, digits, pinyin and punctuation work when the font supports them.\n */" },
#endif
		{ "DisplayName", "Liquid Glass Text" },
		{ "IncludePath", "CBLiquidGlassText.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG wrapper for liquid-glass text.\n\nUnlike a normal TextBlock, the visible glyphs are copied into an alpha mask and used\nas the glass shape. The selected Slate font and fallback chain decide which scripts\nare available, so Chinese, digits, pinyin and punctuation work when the font supports them." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "Category", "Liquid Glass Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text to draw as glyph-shaped liquid glass. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text to draw as glyph-shaped liquid glass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Font_MetaData[] = {
		{ "Category", "Liquid Glass Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Font used by Slate to shape and rasterize the glass text mask. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Font used by Slate to shape and rasterize the glass text mask." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ColorAndOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compatibility colour property kept for Blueprint API stability. The glass shader controls colour. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compatibility colour property kept for Blueprint API stability. The glass shader controls colour." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[] = {
		{ "Category", "Liquid Glass Text|Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base glass material applied to the generated text mask. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base glass material applied to the generated text mask." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quality_MetaData[] = {
		{ "Category", "Liquid Glass Text|Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Runtime quality profile for the text glass pass. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime quality profile for the text glass pass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrostRadius_MetaData[] = {
		{ "Category", "Liquid Glass Text|Glass" },
		{ "ClampMax", "1.5" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Frost mix used by the generated text glass. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Frost mix used by the generated text glass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlyphThickness_MetaData[] = {
		{ "Category", "Liquid Glass Text|Typography" },
		{ "ClampMax", "30.0" },
		{ "ClampMin", "4.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extra glass padding/thickness control used around the font mask. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extra glass padding/thickness control used around the font mask." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LetterSpacing_MetaData[] = {
		{ "Category", "Liquid Glass Text|Typography" },
		{ "ClampMax", "40.0" },
		{ "ClampMin", "-8.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Horizontal distance between generated glyphs before font-size scaling. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Horizontal distance between generated glyphs before font-size scaling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineSpacing_MetaData[] = {
		{ "Category", "Liquid Glass Text|Typography" },
		{ "ClampMax", "80.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Vertical distance between generated text lines before font-size scaling. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Vertical distance between generated text lines before font-size scaling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionStrength_MetaData[] = {
		{ "Category", "Liquid Glass Text|Motion" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Motion deformation amount applied to all generated text strokes. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassText.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Motion deformation amount applied to all generated text strokes." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassText constinit property declarations ***********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Font;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ColorAndOpacity;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Quality_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Quality;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrostRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlyphThickness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LetterSpacing;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineSpacing;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MotionStrength;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassText constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetColorAndOpacity"), .Pointer = &UCBLiquidGlassText::execSetColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("SetFont"), .Pointer = &UCBLiquidGlassText::execSetFont },
		{ .NameUTF8 = UTF8TEXT("SetFrostRadius"), .Pointer = &UCBLiquidGlassText::execSetFrostRadius },
		{ .NameUTF8 = UTF8TEXT("SetGlyphThickness"), .Pointer = &UCBLiquidGlassText::execSetGlyphThickness },
		{ .NameUTF8 = UTF8TEXT("SetLetterSpacing"), .Pointer = &UCBLiquidGlassText::execSetLetterSpacing },
		{ .NameUTF8 = UTF8TEXT("SetLineSpacing"), .Pointer = &UCBLiquidGlassText::execSetLineSpacing },
		{ .NameUTF8 = UTF8TEXT("SetMotionStrength"), .Pointer = &UCBLiquidGlassText::execSetMotionStrength },
		{ .NameUTF8 = UTF8TEXT("SetPreset"), .Pointer = &UCBLiquidGlassText::execSetPreset },
		{ .NameUTF8 = UTF8TEXT("SetQuality"), .Pointer = &UCBLiquidGlassText::execSetQuality },
		{ .NameUTF8 = UTF8TEXT("SetText"), .Pointer = &UCBLiquidGlassText::execSetText },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetColorAndOpacity, "SetColorAndOpacity" }, // 3261608455
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetFont, "SetFont" }, // 2014737485
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetFrostRadius, "SetFrostRadius" }, // 1675856065
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetGlyphThickness, "SetGlyphThickness" }, // 3063917923
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetLetterSpacing, "SetLetterSpacing" }, // 4070886093
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetLineSpacing, "SetLineSpacing" }, // 3668879187
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetMotionStrength, "SetMotionStrength" }, // 3795016993
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetPreset, "SetPreset" }, // 1948772857
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetQuality, "SetQuality" }, // 2772133367
		{ &Z_Construct_UFunction_UCBLiquidGlassText_SetText, "SetText" }, // 445711228
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassText>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassText_Statics

// ********** Begin Class UCBLiquidGlassText Property Definitions **********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetText_WrapperImpl, &UCBLiquidGlassText::GetText_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Font = { "Font", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetFont_WrapperImpl, &UCBLiquidGlassText::GetFont_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, Font), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Font_MetaData), NewProp_Font_MetaData) }; // 167205173
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_ColorAndOpacity = { "ColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetColorAndOpacity_WrapperImpl, &UCBLiquidGlassText::GetColorAndOpacity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, ColorAndOpacity), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ColorAndOpacity_MetaData), NewProp_ColorAndOpacity_MetaData) }; // 1663967387
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetPreset_WrapperImpl, &UCBLiquidGlassText::GetPreset_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, Preset), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Preset_MetaData), NewProp_Preset_MetaData) }; // 3360299489
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Quality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Quality = { "Quality", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetQuality_WrapperImpl, &UCBLiquidGlassText::GetQuality_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, Quality), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quality_MetaData), NewProp_Quality_MetaData) }; // 2771085032
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_FrostRadius = { "FrostRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetFrostRadius_WrapperImpl, &UCBLiquidGlassText::GetFrostRadius_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, FrostRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrostRadius_MetaData), NewProp_FrostRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_GlyphThickness = { "GlyphThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetGlyphThickness_WrapperImpl, &UCBLiquidGlassText::GetGlyphThickness_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, GlyphThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlyphThickness_MetaData), NewProp_GlyphThickness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_LetterSpacing = { "LetterSpacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetLetterSpacing_WrapperImpl, &UCBLiquidGlassText::GetLetterSpacing_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, LetterSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LetterSpacing_MetaData), NewProp_LetterSpacing_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_LineSpacing = { "LineSpacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetLineSpacing_WrapperImpl, &UCBLiquidGlassText::GetLineSpacing_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, LineSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineSpacing_MetaData), NewProp_LineSpacing_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_MotionStrength = { "MotionStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassText::SetMotionStrength_WrapperImpl, &UCBLiquidGlassText::GetMotionStrength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassText, MotionStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionStrength_MetaData), NewProp_MotionStrength_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Font,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_ColorAndOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Quality_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_Quality,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_FrostRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_GlyphThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_LetterSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_LineSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassText_Statics::NewProp_MotionStrength,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassText_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassText Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassText_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassText_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassText_Statics::ClassParams = {
	&UCBLiquidGlassText::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassText_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassText_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassText_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassText_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassText::StaticRegisterNativesUCBLiquidGlassText()
{
	UClass* Class = UCBLiquidGlassText::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassText_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassText()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassText.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassText.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassText_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassText.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassText);
UCBLiquidGlassText::~UCBLiquidGlassText() {}
// ********** End Class UCBLiquidGlassText *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h__Script_CBLiquidGlass_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCBLiquidGlassText, UCBLiquidGlassText::StaticClass, TEXT("UCBLiquidGlassText"), &Z_Registration_Info_UClass_UCBLiquidGlassText, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassText), 692997873U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h__Script_CBLiquidGlass_1588148120{
	TEXT("/Script/CBLiquidGlass"),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h__Script_CBLiquidGlass_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h__Script_CBLiquidGlass_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

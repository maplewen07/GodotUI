// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassSlider.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassSlider() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSlider();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSlider_NoRegister();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
UMG_API UClass* Z_Construct_UClass_UWidget();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FCBLiquidGlassSliderValueChangedEvent *********************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassSliderValueChangedEvent_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassSliderValueChangedEvent constinit property declarations *
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FCBLiquidGlassSliderValueChangedEvent constinit property declarations ***
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FCBLiquidGlassSliderValueChangedEvent Property Definitions ************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassSliderValueChangedEvent_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FCBLiquidGlassSliderValueChangedEvent Property Definitions **************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassSliderValueChangedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassSliderValueChangedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassSliderValueChangedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassSliderValueChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassSliderValueChangedEvent, float Value)
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassSliderValueChangedEvent_Parms
	{
		float Value;
	};
	_Script_CBLiquidGlass_eventCBLiquidGlassSliderValueChangedEvent_Parms Parms;
	Parms.Value=Value;
	CBLiquidGlassSliderValueChangedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FCBLiquidGlassSliderValueChangedEvent ***********************************

// ********** Begin Class UCBLiquidGlassSlider Function SetFillColor *******************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics
{
	struct CBLiquidGlassSlider_eventSetFillColor_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Style" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFillColor constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFillColor constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFillColor Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetFillColor_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::PropPointers) < 2048);
// ********** End Function SetFillColor Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetFillColor", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::CBLiquidGlassSlider_eventSetFillColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::CBLiquidGlassSlider_eventSetFillColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetFillColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFillColor(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetFillColor *********************************

// ********** Begin Class UCBLiquidGlassSlider Function SetMaxValue ********************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics
{
	struct CBLiquidGlassSlider_eventSetMaxValue_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMaxValue constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMaxValue constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMaxValue Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetMaxValue_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::PropPointers) < 2048);
// ********** End Function SetMaxValue Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetMaxValue", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::CBLiquidGlassSlider_eventSetMaxValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::CBLiquidGlassSlider_eventSetMaxValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetMaxValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaxValue(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetMaxValue **********************************

// ********** Begin Class UCBLiquidGlassSlider Function SetMinValue ********************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics
{
	struct CBLiquidGlassSlider_eventSetMinValue_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMinValue constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMinValue constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMinValue Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetMinValue_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::PropPointers) < 2048);
// ********** End Function SetMinValue Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetMinValue", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::CBLiquidGlassSlider_eventSetMinValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::CBLiquidGlassSlider_eventSetMinValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetMinValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMinValue(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetMinValue **********************************

// ********** Begin Class UCBLiquidGlassSlider Function SetQuality *********************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics
{
	struct CBLiquidGlassSlider_eventSetQuality_Parms
	{
		ECBLiquidGlassQuality InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Performance" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetQuality_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(0, nullptr) }; // 2771085032
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::PropPointers) < 2048);
// ********** End Function SetQuality Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetQuality", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::CBLiquidGlassSlider_eventSetQuality_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::CBLiquidGlassSlider_eventSetQuality_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetQuality)
{
	P_GET_ENUM(ECBLiquidGlassQuality,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetQuality(ECBLiquidGlassQuality(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetQuality ***********************************

// ********** Begin Class UCBLiquidGlassSlider Function SetSliderHeight ****************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics
{
	struct CBLiquidGlassSlider_eventSetSliderHeight_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Layout" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSliderHeight constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSliderHeight constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSliderHeight Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetSliderHeight_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::PropPointers) < 2048);
// ********** End Function SetSliderHeight Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetSliderHeight", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::CBLiquidGlassSlider_eventSetSliderHeight_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::CBLiquidGlassSlider_eventSetSliderHeight_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetSliderHeight)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSliderHeight(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetSliderHeight ******************************

// ********** Begin Class UCBLiquidGlassSlider Function SetSliderLength ****************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics
{
	struct CBLiquidGlassSlider_eventSetSliderLength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Layout" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSliderLength constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSliderLength constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSliderLength Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetSliderLength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::PropPointers) < 2048);
// ********** End Function SetSliderLength Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetSliderLength", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::CBLiquidGlassSlider_eventSetSliderLength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::CBLiquidGlassSlider_eventSetSliderLength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetSliderLength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSliderLength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetSliderLength ******************************

// ********** Begin Class UCBLiquidGlassSlider Function SetThumbBounce *****************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics
{
	struct CBLiquidGlassSlider_eventSetThumbBounce_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Jelly" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetThumbBounce constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetThumbBounce constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetThumbBounce Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetThumbBounce_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::PropPointers) < 2048);
// ********** End Function SetThumbBounce Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetThumbBounce", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::CBLiquidGlassSlider_eventSetThumbBounce_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::CBLiquidGlassSlider_eventSetThumbBounce_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetThumbBounce)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetThumbBounce(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetThumbBounce *******************************

// ********** Begin Class UCBLiquidGlassSlider Function SetThumbDamping ****************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics
{
	struct CBLiquidGlassSlider_eventSetThumbDamping_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Jelly" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetThumbDamping constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetThumbDamping constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetThumbDamping Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetThumbDamping_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::PropPointers) < 2048);
// ********** End Function SetThumbDamping Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetThumbDamping", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::CBLiquidGlassSlider_eventSetThumbDamping_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::CBLiquidGlassSlider_eventSetThumbDamping_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetThumbDamping)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetThumbDamping(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetThumbDamping ******************************

// ********** Begin Class UCBLiquidGlassSlider Function SetThumbMotionStrength *********************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics
{
	struct CBLiquidGlassSlider_eventSetThumbMotionStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Jelly" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetThumbMotionStrength constinit property declarations ****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetThumbMotionStrength constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetThumbMotionStrength Property Definitions ***************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetThumbMotionStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::PropPointers) < 2048);
// ********** End Function SetThumbMotionStrength Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetThumbMotionStrength", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::CBLiquidGlassSlider_eventSetThumbMotionStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::CBLiquidGlassSlider_eventSetThumbMotionStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetThumbMotionStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetThumbMotionStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetThumbMotionStrength ***********************

// ********** Begin Class UCBLiquidGlassSlider Function SetThumbPreset *****************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics
{
	struct CBLiquidGlassSlider_eventSetThumbPreset_Parms
	{
		ECBLiquidGlassPreset InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Style" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetThumbPreset constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetThumbPreset constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetThumbPreset Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetThumbPreset_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(0, nullptr) }; // 3360299489
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::PropPointers) < 2048);
// ********** End Function SetThumbPreset Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetThumbPreset", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::CBLiquidGlassSlider_eventSetThumbPreset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::CBLiquidGlassSlider_eventSetThumbPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetThumbPreset)
{
	P_GET_ENUM(ECBLiquidGlassPreset,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetThumbPreset(ECBLiquidGlassPreset(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetThumbPreset *******************************

// ********** Begin Class UCBLiquidGlassSlider Function SetThumbResponse ***************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics
{
	struct CBLiquidGlassSlider_eventSetThumbResponse_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Jelly" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetThumbResponse constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetThumbResponse constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetThumbResponse Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetThumbResponse_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::PropPointers) < 2048);
// ********** End Function SetThumbResponse Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetThumbResponse", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::CBLiquidGlassSlider_eventSetThumbResponse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::CBLiquidGlassSlider_eventSetThumbResponse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetThumbResponse)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetThumbResponse(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetThumbResponse *****************************

// ********** Begin Class UCBLiquidGlassSlider Function SetThumbSize *******************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics
{
	struct CBLiquidGlassSlider_eventSetThumbSize_Parms
	{
		FVector2D InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Layout" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetThumbSize constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetThumbSize constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetThumbSize Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetThumbSize_Parms, InValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::PropPointers) < 2048);
// ********** End Function SetThumbSize Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetThumbSize", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::CBLiquidGlassSlider_eventSetThumbSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::CBLiquidGlassSlider_eventSetThumbSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetThumbSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetThumbSize(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetThumbSize *********************************

// ********** Begin Class UCBLiquidGlassSlider Function SetTrackHeight *****************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics
{
	struct CBLiquidGlassSlider_eventSetTrackHeight_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Layout" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTrackHeight constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTrackHeight constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTrackHeight Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetTrackHeight_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::PropPointers) < 2048);
// ********** End Function SetTrackHeight Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetTrackHeight", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::CBLiquidGlassSlider_eventSetTrackHeight_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::CBLiquidGlassSlider_eventSetTrackHeight_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetTrackHeight)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTrackHeight(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetTrackHeight *******************************

// ********** Begin Class UCBLiquidGlassSlider Function SetTrackOpacity ****************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics
{
	struct CBLiquidGlassSlider_eventSetTrackOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Style" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTrackOpacity constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTrackOpacity constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTrackOpacity Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetTrackOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetTrackOpacity Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetTrackOpacity", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::CBLiquidGlassSlider_eventSetTrackOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::CBLiquidGlassSlider_eventSetTrackOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetTrackOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTrackOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetTrackOpacity ******************************

// ********** Begin Class UCBLiquidGlassSlider Function SetTrackTint *******************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics
{
	struct CBLiquidGlassSlider_eventSetTrackTint_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider|Style" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTrackTint constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTrackTint constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTrackTint Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetTrackTint_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::PropPointers) < 2048);
// ********** End Function SetTrackTint Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetTrackTint", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::CBLiquidGlassSlider_eventSetTrackTint_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::CBLiquidGlassSlider_eventSetTrackTint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetTrackTint)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTrackTint(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetTrackTint *********************************

// ********** Begin Class UCBLiquidGlassSlider Function SetValue ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics
{
	struct CBLiquidGlassSlider_eventSetValue_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Slider" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetValue constinit property declarations ******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetValue constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetValue Property Definitions *****************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlider_eventSetValue_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::PropPointers) < 2048);
// ********** End Function SetValue Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlider, nullptr, "SetValue", 	Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::CBLiquidGlassSlider_eventSetValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::CBLiquidGlassSlider_eventSetValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlider::execSetValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetValue(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlider Function SetValue *************************************

// ********** Begin Class UCBLiquidGlassSlider *****************************************************
void UCBLiquidGlassSlider::GetValue_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetValue();
}
void UCBLiquidGlassSlider::SetValue_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetValue(Value);
}
void UCBLiquidGlassSlider::GetMinValue_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMinValue();
}
void UCBLiquidGlassSlider::SetMinValue_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMinValue(Value);
}
void UCBLiquidGlassSlider::GetMaxValue_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMaxValue();
}
void UCBLiquidGlassSlider::SetMaxValue_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMaxValue(Value);
}
void UCBLiquidGlassSlider::GetSliderLength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetSliderLength();
}
void UCBLiquidGlassSlider::SetSliderLength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetSliderLength(Value);
}
void UCBLiquidGlassSlider::GetSliderHeight_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetSliderHeight();
}
void UCBLiquidGlassSlider::SetSliderHeight_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetSliderHeight(Value);
}
void UCBLiquidGlassSlider::GetTrackHeight_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetTrackHeight();
}
void UCBLiquidGlassSlider::SetTrackHeight_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetTrackHeight(Value);
}
void UCBLiquidGlassSlider::GetThumbSize_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	FVector2D& Result = *(FVector2D*)OutValue;
	Result = (FVector2D)Obj->GetThumbSize();
}
void UCBLiquidGlassSlider::SetThumbSize_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	FVector2D& Value = *(FVector2D*)InValue;
	Obj->SetThumbSize(Value);
}
void UCBLiquidGlassSlider::GetFillColor_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetFillColor();
}
void UCBLiquidGlassSlider::SetFillColor_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetFillColor(Value);
}
void UCBLiquidGlassSlider::GetTrackTint_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetTrackTint();
}
void UCBLiquidGlassSlider::SetTrackTint_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetTrackTint(Value);
}
void UCBLiquidGlassSlider::GetTrackOpacity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetTrackOpacity();
}
void UCBLiquidGlassSlider::SetTrackOpacity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetTrackOpacity(Value);
}
void UCBLiquidGlassSlider::GetThumbPreset_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	ECBLiquidGlassPreset& Result = *(ECBLiquidGlassPreset*)OutValue;
	Result = (ECBLiquidGlassPreset)Obj->GetThumbPreset();
}
void UCBLiquidGlassSlider::SetThumbPreset_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	ECBLiquidGlassPreset& Value = *(ECBLiquidGlassPreset*)InValue;
	Obj->SetThumbPreset(Value);
}
void UCBLiquidGlassSlider::GetQuality_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	ECBLiquidGlassQuality& Result = *(ECBLiquidGlassQuality*)OutValue;
	Result = (ECBLiquidGlassQuality)Obj->GetQuality();
}
void UCBLiquidGlassSlider::SetQuality_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	ECBLiquidGlassQuality& Value = *(ECBLiquidGlassQuality*)InValue;
	Obj->SetQuality(Value);
}
void UCBLiquidGlassSlider::GetThumbBounce_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetThumbBounce();
}
void UCBLiquidGlassSlider::SetThumbBounce_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetThumbBounce(Value);
}
void UCBLiquidGlassSlider::GetThumbResponse_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetThumbResponse();
}
void UCBLiquidGlassSlider::SetThumbResponse_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetThumbResponse(Value);
}
void UCBLiquidGlassSlider::GetThumbDamping_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetThumbDamping();
}
void UCBLiquidGlassSlider::SetThumbDamping_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetThumbDamping(Value);
}
void UCBLiquidGlassSlider::GetThumbMotionStrength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSlider* Obj = (const UCBLiquidGlassSlider*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetThumbMotionStrength();
}
void UCBLiquidGlassSlider::SetThumbMotionStrength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlider* Obj = (UCBLiquidGlassSlider*)Object;
	float& Value = *(float*)InValue;
	Obj->SetThumbMotionStrength(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassSlider;
UClass* UCBLiquidGlassSlider::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassSlider;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassSlider.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassSlider"),
			Z_Registration_Info_UClass_UCBLiquidGlassSlider.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassSlider,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassSlider.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassSlider_NoRegister()
{
	return UCBLiquidGlassSlider::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassSlider_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG slider with a liquid-glass thumb and spring-driven jelly motion while dragging. */" },
#endif
		{ "DisplayName", "Liquid Glass Slider" },
		{ "IncludePath", "CBLiquidGlassSlider.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG slider with a liquid-glass thumb and spring-driven jelly motion while dragging." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "Liquid Glass Slider" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current slider value. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current slider value." },
#endif
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinValue_MetaData[] = {
		{ "Category", "Liquid Glass Slider" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum logical value. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum logical value." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxValue_MetaData[] = {
		{ "Category", "Liquid Glass Slider" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum logical value. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum logical value." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SliderLength_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Layout" },
		{ "ClampMin", "32.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Desired Slate width of the slider. UMG layout can still scale the widget. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Desired Slate width of the slider. UMG layout can still scale the widget." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SliderHeight_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Layout" },
		{ "ClampMin", "12.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Desired Slate height used by the animated thumb and track. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Desired Slate height used by the animated thumb and track." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackHeight_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Layout" },
		{ "ClampMin", "2.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Height of the line track behind the glass thumb. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the line track behind the glass thumb." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbSize_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Resting thumb size before jelly stretch is applied. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resting thumb size before jelly stretch is applied." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillColor_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Colour of the filled progress bar. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Colour of the filled progress bar." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackTint_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tint applied to the translucent track glass. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tint applied to the translucent track glass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Style" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Overall opacity of the translucent track glass. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Overall opacity of the translucent track glass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbPreset_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Preset used by the movable glass thumb. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preset used by the movable glass thumb." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quality_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Renderer quality for the track and thumb. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Renderer quality for the track and thumb." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbBounce_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Jelly" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Multiplier for the subtle liquid stretch. 0 disables the extra width/height deformation. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Multiplier for the subtle liquid stretch. 0 disables the extra width/height deformation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbResponse_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Jelly" },
		{ "ClampMax", "60.0" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How quickly the visual thumb catches the real value. Higher = snappier and less laggy. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How quickly the visual thumb catches the real value. Higher = snappier and less laggy." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbDamping_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Jelly" },
		{ "ClampMax", "40.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spring damping ratio control. Around 8-10 gives a restrained Apple-like bounce. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring damping ratio control. Around 8-10 gives a restrained Apple-like bounce." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbMotionStrength_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Jelly" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extra shader deformation applied to the glass thumb as it moves. Keep this low for an Apple-like feel. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extra shader deformation applied to the glass thumb as it moves. Keep this low for an Apple-like feel." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnValueChanged_MetaData[] = {
		{ "Category", "Liquid Glass Slider|Event" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Broadcast whenever user input changes the value. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Broadcast whenever user input changes the value." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassSlider constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SliderLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SliderHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TrackHeight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ThumbSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FillColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TrackTint;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TrackOpacity;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ThumbPreset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ThumbPreset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Quality_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Quality;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThumbBounce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThumbResponse;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThumbDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThumbMotionStrength;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnValueChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassSlider constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetFillColor"), .Pointer = &UCBLiquidGlassSlider::execSetFillColor },
		{ .NameUTF8 = UTF8TEXT("SetMaxValue"), .Pointer = &UCBLiquidGlassSlider::execSetMaxValue },
		{ .NameUTF8 = UTF8TEXT("SetMinValue"), .Pointer = &UCBLiquidGlassSlider::execSetMinValue },
		{ .NameUTF8 = UTF8TEXT("SetQuality"), .Pointer = &UCBLiquidGlassSlider::execSetQuality },
		{ .NameUTF8 = UTF8TEXT("SetSliderHeight"), .Pointer = &UCBLiquidGlassSlider::execSetSliderHeight },
		{ .NameUTF8 = UTF8TEXT("SetSliderLength"), .Pointer = &UCBLiquidGlassSlider::execSetSliderLength },
		{ .NameUTF8 = UTF8TEXT("SetThumbBounce"), .Pointer = &UCBLiquidGlassSlider::execSetThumbBounce },
		{ .NameUTF8 = UTF8TEXT("SetThumbDamping"), .Pointer = &UCBLiquidGlassSlider::execSetThumbDamping },
		{ .NameUTF8 = UTF8TEXT("SetThumbMotionStrength"), .Pointer = &UCBLiquidGlassSlider::execSetThumbMotionStrength },
		{ .NameUTF8 = UTF8TEXT("SetThumbPreset"), .Pointer = &UCBLiquidGlassSlider::execSetThumbPreset },
		{ .NameUTF8 = UTF8TEXT("SetThumbResponse"), .Pointer = &UCBLiquidGlassSlider::execSetThumbResponse },
		{ .NameUTF8 = UTF8TEXT("SetThumbSize"), .Pointer = &UCBLiquidGlassSlider::execSetThumbSize },
		{ .NameUTF8 = UTF8TEXT("SetTrackHeight"), .Pointer = &UCBLiquidGlassSlider::execSetTrackHeight },
		{ .NameUTF8 = UTF8TEXT("SetTrackOpacity"), .Pointer = &UCBLiquidGlassSlider::execSetTrackOpacity },
		{ .NameUTF8 = UTF8TEXT("SetTrackTint"), .Pointer = &UCBLiquidGlassSlider::execSetTrackTint },
		{ .NameUTF8 = UTF8TEXT("SetValue"), .Pointer = &UCBLiquidGlassSlider::execSetValue },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetFillColor, "SetFillColor" }, // 3543731564
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetMaxValue, "SetMaxValue" }, // 322413429
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetMinValue, "SetMinValue" }, // 5968106
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetQuality, "SetQuality" }, // 3384034054
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderHeight, "SetSliderHeight" }, // 3765843668
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetSliderLength, "SetSliderLength" }, // 1007745935
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbBounce, "SetThumbBounce" }, // 184584333
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbDamping, "SetThumbDamping" }, // 2310253277
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbMotionStrength, "SetThumbMotionStrength" }, // 737031298
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbPreset, "SetThumbPreset" }, // 1757635185
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbResponse, "SetThumbResponse" }, // 174707559
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetThumbSize, "SetThumbSize" }, // 2689443649
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackHeight, "SetTrackHeight" }, // 3971577274
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackOpacity, "SetTrackOpacity" }, // 4283561318
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetTrackTint, "SetTrackTint" }, // 588952327
		{ &Z_Construct_UFunction_UCBLiquidGlassSlider_SetValue, "SetValue" }, // 2377756240
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassSlider>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassSlider_Statics

// ********** Begin Class UCBLiquidGlassSlider Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetValue_WrapperImpl, &UCBLiquidGlassSlider::GetValue_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_MinValue = { "MinValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetMinValue_WrapperImpl, &UCBLiquidGlassSlider::GetMinValue_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, MinValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinValue_MetaData), NewProp_MinValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_MaxValue = { "MaxValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetMaxValue_WrapperImpl, &UCBLiquidGlassSlider::GetMaxValue_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, MaxValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxValue_MetaData), NewProp_MaxValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_SliderLength = { "SliderLength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetSliderLength_WrapperImpl, &UCBLiquidGlassSlider::GetSliderLength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, SliderLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SliderLength_MetaData), NewProp_SliderLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_SliderHeight = { "SliderHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetSliderHeight_WrapperImpl, &UCBLiquidGlassSlider::GetSliderHeight_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, SliderHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SliderHeight_MetaData), NewProp_SliderHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_TrackHeight = { "TrackHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetTrackHeight_WrapperImpl, &UCBLiquidGlassSlider::GetTrackHeight_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, TrackHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackHeight_MetaData), NewProp_TrackHeight_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbSize = { "ThumbSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetThumbSize_WrapperImpl, &UCBLiquidGlassSlider::GetThumbSize_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, ThumbSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbSize_MetaData), NewProp_ThumbSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_FillColor = { "FillColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetFillColor_WrapperImpl, &UCBLiquidGlassSlider::GetFillColor_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, FillColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillColor_MetaData), NewProp_FillColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_TrackTint = { "TrackTint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetTrackTint_WrapperImpl, &UCBLiquidGlassSlider::GetTrackTint_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, TrackTint), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackTint_MetaData), NewProp_TrackTint_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_TrackOpacity = { "TrackOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetTrackOpacity_WrapperImpl, &UCBLiquidGlassSlider::GetTrackOpacity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, TrackOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackOpacity_MetaData), NewProp_TrackOpacity_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbPreset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbPreset = { "ThumbPreset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetThumbPreset_WrapperImpl, &UCBLiquidGlassSlider::GetThumbPreset_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, ThumbPreset), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbPreset_MetaData), NewProp_ThumbPreset_MetaData) }; // 3360299489
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_Quality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_Quality = { "Quality", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetQuality_WrapperImpl, &UCBLiquidGlassSlider::GetQuality_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, Quality), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quality_MetaData), NewProp_Quality_MetaData) }; // 2771085032
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbBounce = { "ThumbBounce", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetThumbBounce_WrapperImpl, &UCBLiquidGlassSlider::GetThumbBounce_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, ThumbBounce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbBounce_MetaData), NewProp_ThumbBounce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbResponse = { "ThumbResponse", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetThumbResponse_WrapperImpl, &UCBLiquidGlassSlider::GetThumbResponse_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, ThumbResponse), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbResponse_MetaData), NewProp_ThumbResponse_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbDamping = { "ThumbDamping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetThumbDamping_WrapperImpl, &UCBLiquidGlassSlider::GetThumbDamping_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, ThumbDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbDamping_MetaData), NewProp_ThumbDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbMotionStrength = { "ThumbMotionStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlider::SetThumbMotionStrength_WrapperImpl, &UCBLiquidGlassSlider::GetThumbMotionStrength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, ThumbMotionStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbMotionStrength_MetaData), NewProp_ThumbMotionStrength_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_OnValueChanged = { "OnValueChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassSlider, OnValueChanged), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSliderValueChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnValueChanged_MetaData), NewProp_OnValueChanged_MetaData) }; // 284382143
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassSlider_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_MinValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_MaxValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_SliderLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_SliderHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_TrackHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_FillColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_TrackTint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_TrackOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbPreset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbPreset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_Quality_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_Quality,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbBounce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbResponse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_ThumbMotionStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlider_Statics::NewProp_OnValueChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSlider_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassSlider Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassSlider_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSlider_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassSlider_Statics::ClassParams = {
	&UCBLiquidGlassSlider::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassSlider_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSlider_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSlider_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassSlider_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassSlider::StaticRegisterNativesUCBLiquidGlassSlider()
{
	UClass* Class = UCBLiquidGlassSlider::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassSlider_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassSlider()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassSlider.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassSlider.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassSlider_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassSlider.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassSlider);
UCBLiquidGlassSlider::~UCBLiquidGlassSlider() {}
// ********** End Class UCBLiquidGlassSlider *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h__Script_CBLiquidGlass_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCBLiquidGlassSlider, UCBLiquidGlassSlider::StaticClass, TEXT("UCBLiquidGlassSlider"), &Z_Registration_Info_UClass_UCBLiquidGlassSlider, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassSlider), 3330884553U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h__Script_CBLiquidGlass_1391939044{
	TEXT("/Script/CBLiquidGlass"),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h__Script_CBLiquidGlass_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h__Script_CBLiquidGlass_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

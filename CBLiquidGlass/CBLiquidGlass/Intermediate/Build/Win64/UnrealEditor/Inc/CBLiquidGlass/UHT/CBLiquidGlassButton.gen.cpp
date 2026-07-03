// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassButton.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassButton() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassButton();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassButton_NoRegister();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassButtonClickedEvent__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UContentWidget();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FCBLiquidGlassButtonClickedEvent **************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassButtonClickedEvent__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassButtonClickedEvent constinit property declarations ******
// ********** End Delegate FCBLiquidGlassButtonClickedEvent constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassButtonClickedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassButtonClickedEvent__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassButtonClickedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassButtonClickedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassButtonClickedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassButtonClickedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassButtonClickedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassButtonClickedEvent)
{
	CBLiquidGlassButtonClickedEvent.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FCBLiquidGlassButtonClickedEvent ****************************************

// ********** Begin Class UCBLiquidGlassButton Function SetDisabledOpacity *************************
struct Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics
{
	struct CBLiquidGlassButton_eventSetDisabledOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Button|Interaction" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDisabledOpacity constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDisabledOpacity constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDisabledOpacity Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButton_eventSetDisabledOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetDisabledOpacity Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButton, nullptr, "SetDisabledOpacity", 	Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::CBLiquidGlassButton_eventSetDisabledOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::CBLiquidGlassButton_eventSetDisabledOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButton::execSetDisabledOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDisabledOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButton Function SetDisabledOpacity ***************************

// ********** Begin Class UCBLiquidGlassButton Function SetHoverGlowBoost **************************
struct Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics
{
	struct CBLiquidGlassButton_eventSetHoverGlowBoost_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Button|Interaction" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetHoverGlowBoost constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHoverGlowBoost constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHoverGlowBoost Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButton_eventSetHoverGlowBoost_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::PropPointers) < 2048);
// ********** End Function SetHoverGlowBoost Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButton, nullptr, "SetHoverGlowBoost", 	Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::CBLiquidGlassButton_eventSetHoverGlowBoost_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::CBLiquidGlassButton_eventSetHoverGlowBoost_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButton::execSetHoverGlowBoost)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHoverGlowBoost(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButton Function SetHoverGlowBoost ****************************

// ********** Begin Class UCBLiquidGlassButton Function SetPreset **********************************
struct Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics
{
	struct CBLiquidGlassButton_eventSetPreset_Parms
	{
		ECBLiquidGlassPreset InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Button" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButton_eventSetPreset_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(0, nullptr) }; // 3360299489
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::PropPointers) < 2048);
// ********** End Function SetPreset Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButton, nullptr, "SetPreset", 	Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::CBLiquidGlassButton_eventSetPreset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::CBLiquidGlassButton_eventSetPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButton::execSetPreset)
{
	P_GET_ENUM(ECBLiquidGlassPreset,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPreset(ECBLiquidGlassPreset(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButton Function SetPreset ************************************

// ********** Begin Class UCBLiquidGlassButton Function SetPressedRefractionBoost ******************
struct Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics
{
	struct CBLiquidGlassButton_eventSetPressedRefractionBoost_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Button|Interaction" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPressedRefractionBoost constinit property declarations *************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPressedRefractionBoost constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPressedRefractionBoost Property Definitions ************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButton_eventSetPressedRefractionBoost_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::PropPointers) < 2048);
// ********** End Function SetPressedRefractionBoost Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButton, nullptr, "SetPressedRefractionBoost", 	Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::CBLiquidGlassButton_eventSetPressedRefractionBoost_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::CBLiquidGlassButton_eventSetPressedRefractionBoost_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButton::execSetPressedRefractionBoost)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPressedRefractionBoost(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButton Function SetPressedRefractionBoost ********************

// ********** Begin Class UCBLiquidGlassButton Function SetPressedTintBoost ************************
struct Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics
{
	struct CBLiquidGlassButton_eventSetPressedTintBoost_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Button|Interaction" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPressedTintBoost constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPressedTintBoost constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPressedTintBoost Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButton_eventSetPressedTintBoost_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::PropPointers) < 2048);
// ********** End Function SetPressedTintBoost Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButton, nullptr, "SetPressedTintBoost", 	Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::CBLiquidGlassButton_eventSetPressedTintBoost_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::CBLiquidGlassButton_eventSetPressedTintBoost_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButton::execSetPressedTintBoost)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPressedTintBoost(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButton Function SetPressedTintBoost **************************

// ********** Begin Class UCBLiquidGlassButton Function SetShape ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics
{
	struct CBLiquidGlassButton_eventSetShape_Parms
	{
		ECBLiquidGlassShape InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Button" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButton_eventSetShape_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape, METADATA_PARAMS(0, nullptr) }; // 1987497363
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::PropPointers) < 2048);
// ********** End Function SetShape Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButton, nullptr, "SetShape", 	Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::CBLiquidGlassButton_eventSetShape_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::CBLiquidGlassButton_eventSetShape_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButton_SetShape()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButton_SetShape_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButton::execSetShape)
{
	P_GET_ENUM(ECBLiquidGlassShape,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShape(ECBLiquidGlassShape(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButton Function SetShape *************************************

// ********** Begin Class UCBLiquidGlassButton *****************************************************
void UCBLiquidGlassButton::GetPreset_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassButton* Obj = (const UCBLiquidGlassButton*)Object;
	ECBLiquidGlassPreset& Result = *(ECBLiquidGlassPreset*)OutValue;
	Result = (ECBLiquidGlassPreset)Obj->GetPreset();
}
void UCBLiquidGlassButton::SetPreset_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButton* Obj = (UCBLiquidGlassButton*)Object;
	ECBLiquidGlassPreset& Value = *(ECBLiquidGlassPreset*)InValue;
	Obj->SetPreset(Value);
}
void UCBLiquidGlassButton::GetShape_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassButton* Obj = (const UCBLiquidGlassButton*)Object;
	ECBLiquidGlassShape& Result = *(ECBLiquidGlassShape*)OutValue;
	Result = (ECBLiquidGlassShape)Obj->GetShape();
}
void UCBLiquidGlassButton::SetShape_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButton* Obj = (UCBLiquidGlassButton*)Object;
	ECBLiquidGlassShape& Value = *(ECBLiquidGlassShape*)InValue;
	Obj->SetShape(Value);
}
void UCBLiquidGlassButton::GetHoverGlowBoost_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassButton* Obj = (const UCBLiquidGlassButton*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetHoverGlowBoost();
}
void UCBLiquidGlassButton::SetHoverGlowBoost_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButton* Obj = (UCBLiquidGlassButton*)Object;
	float& Value = *(float*)InValue;
	Obj->SetHoverGlowBoost(Value);
}
void UCBLiquidGlassButton::GetPressedRefractionBoost_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassButton* Obj = (const UCBLiquidGlassButton*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetPressedRefractionBoost();
}
void UCBLiquidGlassButton::SetPressedRefractionBoost_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButton* Obj = (UCBLiquidGlassButton*)Object;
	float& Value = *(float*)InValue;
	Obj->SetPressedRefractionBoost(Value);
}
void UCBLiquidGlassButton::GetPressedTintBoost_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassButton* Obj = (const UCBLiquidGlassButton*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetPressedTintBoost();
}
void UCBLiquidGlassButton::SetPressedTintBoost_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButton* Obj = (UCBLiquidGlassButton*)Object;
	float& Value = *(float*)InValue;
	Obj->SetPressedTintBoost(Value);
}
void UCBLiquidGlassButton::GetDisabledOpacity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassButton* Obj = (const UCBLiquidGlassButton*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetDisabledOpacity();
}
void UCBLiquidGlassButton::SetDisabledOpacity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButton* Obj = (UCBLiquidGlassButton*)Object;
	float& Value = *(float*)InValue;
	Obj->SetDisabledOpacity(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassButton;
UClass* UCBLiquidGlassButton::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassButton;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassButton.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassButton"),
			Z_Registration_Info_UClass_UCBLiquidGlassButton.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassButton,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassButton.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassButton_NoRegister()
{
	return UCBLiquidGlassButton::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassButton_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG button that uses liquid glass as its interactive background. */" },
#endif
		{ "DisplayName", "Liquid Glass Button" },
		{ "IncludePath", "CBLiquidGlassButton.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG button that uses liquid glass as its interactive background." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[] = {
		{ "Category", "Liquid Glass Button" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visual preset used as the button's base glass recipe. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual preset used as the button's base glass recipe." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shape_MetaData[] = {
		{ "Category", "Liquid Glass Button" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shape used by the glass button background. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shape used by the glass button background." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HoverGlowBoost_MetaData[] = {
		{ "Category", "Liquid Glass Button|Interaction" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extra rim and glow added while the pointer hovers the button. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extra rim and glow added while the pointer hovers the button." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressedRefractionBoost_MetaData[] = {
		{ "Category", "Liquid Glass Button|Interaction" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extra refraction added while the button is pressed. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extra refraction added while the button is pressed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressedTintBoost_MetaData[] = {
		{ "Category", "Liquid Glass Button|Interaction" },
		{ "ClampMax", "0.5" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extra tint added while the button is pressed. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extra tint added while the button is pressed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisabledOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Button|Interaction" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Glass opacity multiplier when the button is disabled. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Glass opacity multiplier when the button is disabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnClicked_MetaData[] = {
		{ "Category", "Liquid Glass Button|Event" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Broadcast when the button is clicked. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Broadcast when the button is clicked." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassButton constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Shape_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Shape;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HoverGlowBoost;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PressedRefractionBoost;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PressedTintBoost;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DisabledOpacity;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnClicked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassButton constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetDisabledOpacity"), .Pointer = &UCBLiquidGlassButton::execSetDisabledOpacity },
		{ .NameUTF8 = UTF8TEXT("SetHoverGlowBoost"), .Pointer = &UCBLiquidGlassButton::execSetHoverGlowBoost },
		{ .NameUTF8 = UTF8TEXT("SetPreset"), .Pointer = &UCBLiquidGlassButton::execSetPreset },
		{ .NameUTF8 = UTF8TEXT("SetPressedRefractionBoost"), .Pointer = &UCBLiquidGlassButton::execSetPressedRefractionBoost },
		{ .NameUTF8 = UTF8TEXT("SetPressedTintBoost"), .Pointer = &UCBLiquidGlassButton::execSetPressedTintBoost },
		{ .NameUTF8 = UTF8TEXT("SetShape"), .Pointer = &UCBLiquidGlassButton::execSetShape },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassButton_SetDisabledOpacity, "SetDisabledOpacity" }, // 1229450274
		{ &Z_Construct_UFunction_UCBLiquidGlassButton_SetHoverGlowBoost, "SetHoverGlowBoost" }, // 1863617336
		{ &Z_Construct_UFunction_UCBLiquidGlassButton_SetPreset, "SetPreset" }, // 3018846584
		{ &Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedRefractionBoost, "SetPressedRefractionBoost" }, // 852257733
		{ &Z_Construct_UFunction_UCBLiquidGlassButton_SetPressedTintBoost, "SetPressedTintBoost" }, // 1048013681
		{ &Z_Construct_UFunction_UCBLiquidGlassButton_SetShape, "SetShape" }, // 2760852276
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassButton_Statics

// ********** Begin Class UCBLiquidGlassButton Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButton::SetPreset_WrapperImpl, &UCBLiquidGlassButton::GetPreset_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassButton, Preset), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Preset_MetaData), NewProp_Preset_MetaData) }; // 3360299489
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_Shape_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_Shape = { "Shape", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButton::SetShape_WrapperImpl, &UCBLiquidGlassButton::GetShape_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassButton, Shape), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassShape, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shape_MetaData), NewProp_Shape_MetaData) }; // 1987497363
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_HoverGlowBoost = { "HoverGlowBoost", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButton::SetHoverGlowBoost_WrapperImpl, &UCBLiquidGlassButton::GetHoverGlowBoost_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassButton, HoverGlowBoost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HoverGlowBoost_MetaData), NewProp_HoverGlowBoost_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_PressedRefractionBoost = { "PressedRefractionBoost", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButton::SetPressedRefractionBoost_WrapperImpl, &UCBLiquidGlassButton::GetPressedRefractionBoost_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassButton, PressedRefractionBoost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressedRefractionBoost_MetaData), NewProp_PressedRefractionBoost_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_PressedTintBoost = { "PressedTintBoost", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButton::SetPressedTintBoost_WrapperImpl, &UCBLiquidGlassButton::GetPressedTintBoost_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassButton, PressedTintBoost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressedTintBoost_MetaData), NewProp_PressedTintBoost_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_DisabledOpacity = { "DisabledOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButton::SetDisabledOpacity_WrapperImpl, &UCBLiquidGlassButton::GetDisabledOpacity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassButton, DisabledOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisabledOpacity_MetaData), NewProp_DisabledOpacity_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_OnClicked = { "OnClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassButton, OnClicked), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassButtonClickedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnClicked_MetaData), NewProp_OnClicked_MetaData) }; // 3370703600
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassButton_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_Shape_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_Shape,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_HoverGlowBoost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_PressedRefractionBoost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_PressedTintBoost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_DisabledOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButton_Statics::NewProp_OnClicked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassButton_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassButton Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassButton_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UContentWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassButton_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassButton_Statics::ClassParams = {
	&UCBLiquidGlassButton::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassButton_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassButton_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassButton_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassButton_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassButton::StaticRegisterNativesUCBLiquidGlassButton()
{
	UClass* Class = UCBLiquidGlassButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassButton_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassButton()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassButton.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassButton_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassButton.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassButton);
UCBLiquidGlassButton::~UCBLiquidGlassButton() {}
// ********** End Class UCBLiquidGlassButton *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h__Script_CBLiquidGlass_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCBLiquidGlassButton, UCBLiquidGlassButton::StaticClass, TEXT("UCBLiquidGlassButton"), &Z_Registration_Info_UClass_UCBLiquidGlassButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassButton), 140588239U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h__Script_CBLiquidGlass_3811925609{
	TEXT("/Script/CBLiquidGlass"),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h__Script_CBLiquidGlass_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h__Script_CBLiquidGlass_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

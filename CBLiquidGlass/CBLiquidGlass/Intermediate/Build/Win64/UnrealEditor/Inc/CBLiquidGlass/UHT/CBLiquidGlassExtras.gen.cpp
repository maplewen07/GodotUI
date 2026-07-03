// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassExtras.h"
#include "CBLiquidGlassTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassExtras() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassBadge();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassBadge_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassContainer();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassContainer_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassDialog();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassDialog_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassNavigationBar();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassNavigationBar_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassPageControl();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassPageControl_NoRegister();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassItem();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
UMG_API UClass* Z_Construct_UClass_UContentWidget();
UMG_API UClass* Z_Construct_UClass_UWidget();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FCBLiquidGlassPageChangedEvent ****************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassPageChangedEvent_Parms
	{
		int32 PageIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassPageChangedEvent constinit property declarations ********
	static const UECodeGen_Private::FIntPropertyParams NewProp_PageIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FCBLiquidGlassPageChangedEvent constinit property declarations **********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FCBLiquidGlassPageChangedEvent Property Definitions *******************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::NewProp_PageIndex = { "PageIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassPageChangedEvent_Parms, PageIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::NewProp_PageIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FCBLiquidGlassPageChangedEvent Property Definitions *********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassPageChangedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassPageChangedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassPageChangedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassPageChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassPageChangedEvent, int32 PageIndex)
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassPageChangedEvent_Parms
	{
		int32 PageIndex;
	};
	_Script_CBLiquidGlass_eventCBLiquidGlassPageChangedEvent_Parms Parms;
	Parms.PageIndex=PageIndex;
	CBLiquidGlassPageChangedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FCBLiquidGlassPageChangedEvent ******************************************

// ********** Begin Delegate FCBLiquidGlassSimpleEvent *********************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassSimpleEvent constinit property declarations *************
// ********** End Delegate FCBLiquidGlassSimpleEvent constinit property declarations ***************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassSimpleEvent__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassSimpleEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassSimpleEvent)
{
	CBLiquidGlassSimpleEvent.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FCBLiquidGlassSimpleEvent ***********************************************

// ********** Begin Delegate FCBLiquidGlassActionEvent *********************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassActionEvent_Parms
	{
		int32 Index;
		int32 Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassActionEvent constinit property declarations *************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FCBLiquidGlassActionEvent constinit property declarations ***************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FCBLiquidGlassActionEvent Property Definitions ************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassActionEvent_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassActionEvent_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FCBLiquidGlassActionEvent Property Definitions **************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassActionEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassActionEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassActionEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassActionEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassActionEvent, int32 Index, int32 Value)
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassActionEvent_Parms
	{
		int32 Index;
		int32 Value;
	};
	_Script_CBLiquidGlass_eventCBLiquidGlassActionEvent_Parms Parms;
	Parms.Index=Index;
	Parms.Value=Value;
	CBLiquidGlassActionEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FCBLiquidGlassActionEvent ***********************************************

// ********** Begin Class UCBLiquidGlassBadge Function SetColor ************************************
struct Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics
{
	struct CBLiquidGlassBadge_eventSetColor_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Badge" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetColor constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetColor constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetColor Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassBadge_eventSetColor_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::PropPointers) < 2048);
// ********** End Function SetColor Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassBadge, nullptr, "SetColor", 	Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::CBLiquidGlassBadge_eventSetColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::CBLiquidGlassBadge_eventSetColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassBadge::execSetColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetColor(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassBadge Function SetColor **************************************

// ********** Begin Class UCBLiquidGlassBadge Function SetCount ************************************
struct Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics
{
	struct CBLiquidGlassBadge_eventSetCount_Parms
	{
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Badge" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCount constinit property declarations ******************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCount constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCount Property Definitions *****************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassBadge_eventSetCount_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::PropPointers) < 2048);
// ********** End Function SetCount Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassBadge, nullptr, "SetCount", 	Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::CBLiquidGlassBadge_eventSetCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::CBLiquidGlassBadge_eventSetCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassBadge::execSetCount)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCount(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassBadge Function SetCount **************************************

// ********** Begin Class UCBLiquidGlassBadge Function SetDotMode **********************************
struct Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics
{
	struct CBLiquidGlassBadge_eventSetDotMode_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Badge" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDotMode constinit property declarations ****************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDotMode constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDotMode Property Definitions ***************************************
void Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassBadge_eventSetDotMode_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassBadge_eventSetDotMode_Parms), &Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::PropPointers) < 2048);
// ********** End Function SetDotMode Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassBadge, nullptr, "SetDotMode", 	Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::CBLiquidGlassBadge_eventSetDotMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::CBLiquidGlassBadge_eventSetDotMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassBadge::execSetDotMode)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDotMode(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassBadge Function SetDotMode ************************************

// ********** Begin Class UCBLiquidGlassBadge Function SetMaxCount *********************************
struct Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics
{
	struct CBLiquidGlassBadge_eventSetMaxCount_Parms
	{
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Badge" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMaxCount constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMaxCount constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMaxCount Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassBadge_eventSetMaxCount_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::PropPointers) < 2048);
// ********** End Function SetMaxCount Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassBadge, nullptr, "SetMaxCount", 	Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::CBLiquidGlassBadge_eventSetMaxCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::CBLiquidGlassBadge_eventSetMaxCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassBadge::execSetMaxCount)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaxCount(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassBadge Function SetMaxCount ***********************************

// ********** Begin Class UCBLiquidGlassBadge ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassBadge;
UClass* UCBLiquidGlassBadge::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassBadge;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassBadge.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassBadge"),
			Z_Registration_Info_UClass_UCBLiquidGlassBadge.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassBadge,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassBadge.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassBadge_NoRegister()
{
	return UCBLiquidGlassBadge::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassBadge_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG count/notification badge (the red bubble UIKit puts on tab and app icons). */" },
#endif
		{ "DisplayName", "Liquid Glass Badge" },
		{ "IncludePath", "CBLiquidGlassExtras.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG count/notification badge (the red bubble UIKit puts on tab and app icons)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Count_MetaData[] = {
		{ "Category", "Liquid Glass Badge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number shown in the badge; values <= 0 hide it unless DotMode is on. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number shown in the badge; values <= 0 hide it unless DotMode is on." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCount_MetaData[] = {
		{ "Category", "Liquid Glass Badge" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Counts above this render as \"MaxCount+\". */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Counts above this render as \"MaxCount+\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDotMode_MetaData[] = {
		{ "Category", "Liquid Glass Badge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Draws a small dot with no number instead of a counted capsule. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Draws a small dot with no number instead of a counted capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[] = {
		{ "Category", "Liquid Glass Badge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Badge fill colour ( uses system red). */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Badge fill colour ( uses system red)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Badge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shared control style (quality). */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shared control style (quality)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassBadge constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxCount;
	static void NewProp_bDotMode_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDotMode;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassBadge constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetColor"), .Pointer = &UCBLiquidGlassBadge::execSetColor },
		{ .NameUTF8 = UTF8TEXT("SetCount"), .Pointer = &UCBLiquidGlassBadge::execSetCount },
		{ .NameUTF8 = UTF8TEXT("SetDotMode"), .Pointer = &UCBLiquidGlassBadge::execSetDotMode },
		{ .NameUTF8 = UTF8TEXT("SetMaxCount"), .Pointer = &UCBLiquidGlassBadge::execSetMaxCount },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassBadge_SetColor, "SetColor" }, // 1845900939
		{ &Z_Construct_UFunction_UCBLiquidGlassBadge_SetCount, "SetCount" }, // 2699777609
		{ &Z_Construct_UFunction_UCBLiquidGlassBadge_SetDotMode, "SetDotMode" }, // 2187535943
		{ &Z_Construct_UFunction_UCBLiquidGlassBadge_SetMaxCount, "SetMaxCount" }, // 1916046683
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassBadge>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassBadge_Statics

// ********** Begin Class UCBLiquidGlassBadge Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassBadge, Count), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Count_MetaData), NewProp_Count_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_MaxCount = { "MaxCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassBadge, MaxCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCount_MetaData), NewProp_MaxCount_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_bDotMode_SetBit(void* Obj)
{
	((UCBLiquidGlassBadge*)Obj)->bDotMode = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_bDotMode = { "bDotMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCBLiquidGlassBadge), &Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_bDotMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDotMode_MetaData), NewProp_bDotMode_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassBadge, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Color_MetaData), NewProp_Color_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassBadge, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassBadge_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_Count,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_MaxCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_bDotMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassBadge_Statics::NewProp_Style,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassBadge_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassBadge Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassBadge_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassBadge_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassBadge_Statics::ClassParams = {
	&UCBLiquidGlassBadge::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassBadge_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassBadge_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassBadge_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassBadge_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassBadge::StaticRegisterNativesUCBLiquidGlassBadge()
{
	UClass* Class = UCBLiquidGlassBadge::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassBadge_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassBadge()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassBadge.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassBadge.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassBadge_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassBadge.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassBadge);
UCBLiquidGlassBadge::~UCBLiquidGlassBadge() {}
// ********** End Class UCBLiquidGlassBadge ********************************************************

// ********** Begin Class UCBLiquidGlassPageControl Function SetCurrentPage ************************
struct Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics
{
	struct CBLiquidGlassPageControl_eventSetCurrentPage_Parms
	{
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCurrentPage constinit property declarations ************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCurrentPage constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCurrentPage Property Definitions ***********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassPageControl_eventSetCurrentPage_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::PropPointers) < 2048);
// ********** End Function SetCurrentPage Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassPageControl, nullptr, "SetCurrentPage", 	Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::CBLiquidGlassPageControl_eventSetCurrentPage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::CBLiquidGlassPageControl_eventSetCurrentPage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassPageControl::execSetCurrentPage)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCurrentPage(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassPageControl Function SetCurrentPage **************************

// ********** Begin Class UCBLiquidGlassPageControl Function SetNumPages ***************************
struct Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics
{
	struct CBLiquidGlassPageControl_eventSetNumPages_Parms
	{
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetNumPages constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetNumPages constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetNumPages Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassPageControl_eventSetNumPages_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::PropPointers) < 2048);
// ********** End Function SetNumPages Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassPageControl, nullptr, "SetNumPages", 	Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::CBLiquidGlassPageControl_eventSetNumPages_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::CBLiquidGlassPageControl_eventSetNumPages_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassPageControl::execSetNumPages)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetNumPages(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassPageControl Function SetNumPages *****************************

// ********** Begin Class UCBLiquidGlassPageControl ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassPageControl;
UClass* UCBLiquidGlassPageControl::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassPageControl;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassPageControl.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassPageControl"),
			Z_Registration_Info_UClass_UCBLiquidGlassPageControl.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassPageControl,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassPageControl.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassPageControl_NoRegister()
{
	return UCBLiquidGlassPageControl::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassPageControl_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG  page indicator with a spring-driven active pill. */" },
#endif
		{ "DisplayName", "Liquid Glass Page Control" },
		{ "IncludePath", "CBLiquidGlassExtras.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG  page indicator with a spring-driven active pill." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumPages_MetaData[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPage_MetaData[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DotSize_MetaData[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ClampMin", "2.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DotSpacing_MetaData[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveColor_MetaData[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InactiveColor_MetaData[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringSettings_MetaData[] = {
		{ "Category", "Liquid Glass Page Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPageChanged_MetaData[] = {
		{ "Category", "Liquid Glass Page Control|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassPageControl constinit property declarations ****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumPages;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentPage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DotSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DotSpacing;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActiveColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InactiveColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpringSettings;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPageChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassPageControl constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetCurrentPage"), .Pointer = &UCBLiquidGlassPageControl::execSetCurrentPage },
		{ .NameUTF8 = UTF8TEXT("SetNumPages"), .Pointer = &UCBLiquidGlassPageControl::execSetNumPages },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassPageControl_SetCurrentPage, "SetCurrentPage" }, // 1729332192
		{ &Z_Construct_UFunction_UCBLiquidGlassPageControl_SetNumPages, "SetNumPages" }, // 3114036992
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassPageControl>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassPageControl_Statics

// ********** Begin Class UCBLiquidGlassPageControl Property Definitions ***************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_NumPages = { "NumPages", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassPageControl, NumPages), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumPages_MetaData), NewProp_NumPages_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_CurrentPage = { "CurrentPage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassPageControl, CurrentPage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPage_MetaData), NewProp_CurrentPage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_DotSize = { "DotSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassPageControl, DotSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DotSize_MetaData), NewProp_DotSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_DotSpacing = { "DotSpacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassPageControl, DotSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DotSpacing_MetaData), NewProp_DotSpacing_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_ActiveColor = { "ActiveColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassPageControl, ActiveColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveColor_MetaData), NewProp_ActiveColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_InactiveColor = { "InactiveColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassPageControl, InactiveColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InactiveColor_MetaData), NewProp_InactiveColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_SpringSettings = { "SpringSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassPageControl, SpringSettings), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringSettings_MetaData), NewProp_SpringSettings_MetaData) }; // 4164173022
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_OnPageChanged = { "OnPageChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassPageControl, OnPageChanged), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassPageChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPageChanged_MetaData), NewProp_OnPageChanged_MetaData) }; // 3853358834
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_NumPages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_CurrentPage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_DotSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_DotSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_ActiveColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_InactiveColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_SpringSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::NewProp_OnPageChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassPageControl Property Definitions *****************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::ClassParams = {
	&UCBLiquidGlassPageControl::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassPageControl::StaticRegisterNativesUCBLiquidGlassPageControl()
{
	UClass* Class = UCBLiquidGlassPageControl::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassPageControl()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassPageControl.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassPageControl.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassPageControl_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassPageControl.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassPageControl);
UCBLiquidGlassPageControl::~UCBLiquidGlassPageControl() {}
// ********** End Class UCBLiquidGlassPageControl **************************************************

// ********** Begin Class UCBLiquidGlassNavigationBar Function SetLargeTitle ***********************
struct Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics
{
	struct CBLiquidGlassNavigationBar_eventSetLargeTitle_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetLargeTitle constinit property declarations *************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLargeTitle constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLargeTitle Property Definitions ************************************
void Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassNavigationBar_eventSetLargeTitle_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassNavigationBar_eventSetLargeTitle_Parms), &Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::PropPointers) < 2048);
// ********** End Function SetLargeTitle Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassNavigationBar, nullptr, "SetLargeTitle", 	Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::CBLiquidGlassNavigationBar_eventSetLargeTitle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::CBLiquidGlassNavigationBar_eventSetLargeTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassNavigationBar::execSetLargeTitle)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLargeTitle(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassNavigationBar Function SetLargeTitle *************************

// ********** Begin Class UCBLiquidGlassNavigationBar Function SetShowBackButton *******************
struct Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics
{
	struct CBLiquidGlassNavigationBar_eventSetShowBackButton_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowBackButton constinit property declarations *********************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowBackButton constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowBackButton Property Definitions ********************************
void Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassNavigationBar_eventSetShowBackButton_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassNavigationBar_eventSetShowBackButton_Parms), &Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::PropPointers) < 2048);
// ********** End Function SetShowBackButton Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassNavigationBar, nullptr, "SetShowBackButton", 	Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::CBLiquidGlassNavigationBar_eventSetShowBackButton_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::CBLiquidGlassNavigationBar_eventSetShowBackButton_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassNavigationBar::execSetShowBackButton)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowBackButton(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassNavigationBar Function SetShowBackButton *********************

// ********** Begin Class UCBLiquidGlassNavigationBar Function SetTitle ****************************
struct Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics
{
	struct CBLiquidGlassNavigationBar_eventSetTitle_Parms
	{
		FText InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTitle constinit property declarations ******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTitle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTitle Property Definitions *****************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassNavigationBar_eventSetTitle_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::PropPointers) < 2048);
// ********** End Function SetTitle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassNavigationBar, nullptr, "SetTitle", 	Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::CBLiquidGlassNavigationBar_eventSetTitle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::CBLiquidGlassNavigationBar_eventSetTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassNavigationBar::execSetTitle)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTitle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassNavigationBar Function SetTitle ******************************

// ********** Begin Class UCBLiquidGlassNavigationBar Function SetTrailingItems ********************
struct Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics
{
	struct CBLiquidGlassNavigationBar_eventSetTrailingItems_Parms
	{
		TArray<FCBLiquidGlassItem> InItems;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItems_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTrailingItems constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InItems;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTrailingItems constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTrailingItems Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::NewProp_InItems_Inner = { "InItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::NewProp_InItems = { "InItems", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassNavigationBar_eventSetTrailingItems_Parms, InItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItems_MetaData), NewProp_InItems_MetaData) }; // 688407273
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::NewProp_InItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::NewProp_InItems,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::PropPointers) < 2048);
// ********** End Function SetTrailingItems Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassNavigationBar, nullptr, "SetTrailingItems", 	Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::CBLiquidGlassNavigationBar_eventSetTrailingItems_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::CBLiquidGlassNavigationBar_eventSetTrailingItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassNavigationBar::execSetTrailingItems)
{
	P_GET_TARRAY_REF(FCBLiquidGlassItem,Z_Param_Out_InItems);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTrailingItems(Z_Param_Out_InItems);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassNavigationBar Function SetTrailingItems **********************

// ********** Begin Class UCBLiquidGlassNavigationBar **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassNavigationBar;
UClass* UCBLiquidGlassNavigationBar::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassNavigationBar;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassNavigationBar.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassNavigationBar"),
			Z_Registration_Info_UClass_UCBLiquidGlassNavigationBar.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassNavigationBar,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassNavigationBar.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassNavigationBar_NoRegister()
{
	return UCBLiquidGlassNavigationBar::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG glass navigation bar (leading back button, centered/large title, trailing actions). */" },
#endif
		{ "DisplayName", "Liquid Glass Navigation Bar" },
		{ "IncludePath", "CBLiquidGlassExtras.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG glass navigation bar (leading back button, centered/large title, trailing actions)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowBackButton_MetaData[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLargeTitle_MetaData[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrailingItems_MetaData[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Navigation Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnBackClicked_MetaData[] = {
		{ "Category", "Liquid Glass Navigation Bar|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTrailingItemClicked_MetaData[] = {
		{ "Category", "Liquid Glass Navigation Bar|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassNavigationBar constinit property declarations **************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Title;
	static void NewProp_bShowBackButton_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowBackButton;
	static void NewProp_bLargeTitle_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLargeTitle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TrailingItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TrailingItems;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBackClicked;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTrailingItemClicked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassNavigationBar constinit property declarations ****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetLargeTitle"), .Pointer = &UCBLiquidGlassNavigationBar::execSetLargeTitle },
		{ .NameUTF8 = UTF8TEXT("SetShowBackButton"), .Pointer = &UCBLiquidGlassNavigationBar::execSetShowBackButton },
		{ .NameUTF8 = UTF8TEXT("SetTitle"), .Pointer = &UCBLiquidGlassNavigationBar::execSetTitle },
		{ .NameUTF8 = UTF8TEXT("SetTrailingItems"), .Pointer = &UCBLiquidGlassNavigationBar::execSetTrailingItems },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetLargeTitle, "SetLargeTitle" }, // 1534721814
		{ &Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetShowBackButton, "SetShowBackButton" }, // 1097803835
		{ &Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTitle, "SetTitle" }, // 2565013456
		{ &Z_Construct_UFunction_UCBLiquidGlassNavigationBar_SetTrailingItems, "SetTrailingItems" }, // 3516746474
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassNavigationBar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics

// ********** Begin Class UCBLiquidGlassNavigationBar Property Definitions *************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassNavigationBar, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_bShowBackButton_SetBit(void* Obj)
{
	((UCBLiquidGlassNavigationBar*)Obj)->bShowBackButton = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_bShowBackButton = { "bShowBackButton", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCBLiquidGlassNavigationBar), &Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_bShowBackButton_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowBackButton_MetaData), NewProp_bShowBackButton_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_bLargeTitle_SetBit(void* Obj)
{
	((UCBLiquidGlassNavigationBar*)Obj)->bLargeTitle = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_bLargeTitle = { "bLargeTitle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCBLiquidGlassNavigationBar), &Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_bLargeTitle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLargeTitle_MetaData), NewProp_bLargeTitle_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_TrailingItems_Inner = { "TrailingItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_TrailingItems = { "TrailingItems", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassNavigationBar, TrailingItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrailingItems_MetaData), NewProp_TrailingItems_MetaData) }; // 688407273
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassNavigationBar, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_OnBackClicked = { "OnBackClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassNavigationBar, OnBackClicked), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnBackClicked_MetaData), NewProp_OnBackClicked_MetaData) }; // 2661696606
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_OnTrailingItemClicked = { "OnTrailingItemClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassNavigationBar, OnTrailingItemClicked), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTrailingItemClicked_MetaData), NewProp_OnTrailingItemClicked_MetaData) }; // 1312018797
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_bShowBackButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_bLargeTitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_TrailingItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_TrailingItems,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_OnBackClicked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::NewProp_OnTrailingItemClicked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassNavigationBar Property Definitions ***************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::ClassParams = {
	&UCBLiquidGlassNavigationBar::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassNavigationBar::StaticRegisterNativesUCBLiquidGlassNavigationBar()
{
	UClass* Class = UCBLiquidGlassNavigationBar::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassNavigationBar()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassNavigationBar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassNavigationBar.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassNavigationBar.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassNavigationBar);
UCBLiquidGlassNavigationBar::~UCBLiquidGlassNavigationBar() {}
// ********** End Class UCBLiquidGlassNavigationBar ************************************************

// ********** Begin Class UCBLiquidGlassDialog Function Dismiss ************************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_Dismiss_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Animates the dialog out and fires OnDismissed when finished. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Animates the dialog out and fires OnDismissed when finished." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Dismiss constinit property declarations *******************************
// ********** End Function Dismiss constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_Dismiss_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "Dismiss", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_Dismiss_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_Dismiss_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_Dismiss()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_Dismiss_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execDismiss)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Dismiss();
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function Dismiss **************************************

// ********** Begin Class UCBLiquidGlassDialog Function Present ************************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_Present_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Animates the dialog in. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Animates the dialog in." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Present constinit property declarations *******************************
// ********** End Function Present constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_Present_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "Present", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_Present_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_Present_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_Present()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_Present_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execPresent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Present();
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function Present **************************************

// ********** Begin Class UCBLiquidGlassDialog Function SetButtons *********************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics
{
	struct CBLiquidGlassDialog_eventSetButtons_Parms
	{
		TArray<FCBLiquidGlassItem> InButtons;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InButtons_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetButtons constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InButtons_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InButtons;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetButtons constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetButtons Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::NewProp_InButtons_Inner = { "InButtons", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::NewProp_InButtons = { "InButtons", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetButtons_Parms, InButtons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InButtons_MetaData), NewProp_InButtons_MetaData) }; // 688407273
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::NewProp_InButtons_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::NewProp_InButtons,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::PropPointers) < 2048);
// ********** End Function SetButtons Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetButtons", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::CBLiquidGlassDialog_eventSetButtons_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::CBLiquidGlassDialog_eventSetButtons_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetButtons)
{
	P_GET_TARRAY_REF(FCBLiquidGlassItem,Z_Param_Out_InButtons);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetButtons(Z_Param_Out_InButtons);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetButtons ***********************************

// ********** Begin Class UCBLiquidGlassDialog Function SetCardBlurStrength ************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics
{
	struct CBLiquidGlassDialog_eventSetCardBlurStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCardBlurStrength constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCardBlurStrength constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCardBlurStrength Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetCardBlurStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::PropPointers) < 2048);
// ********** End Function SetCardBlurStrength Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetCardBlurStrength", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::CBLiquidGlassDialog_eventSetCardBlurStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::CBLiquidGlassDialog_eventSetCardBlurStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetCardBlurStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardBlurStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetCardBlurStrength **************************

// ********** Begin Class UCBLiquidGlassDialog Function SetCardFrostRadius *************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics
{
	struct CBLiquidGlassDialog_eventSetCardFrostRadius_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCardFrostRadius constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCardFrostRadius constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCardFrostRadius Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetCardFrostRadius_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::PropPointers) < 2048);
// ********** End Function SetCardFrostRadius Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetCardFrostRadius", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::CBLiquidGlassDialog_eventSetCardFrostRadius_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::CBLiquidGlassDialog_eventSetCardFrostRadius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetCardFrostRadius)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardFrostRadius(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetCardFrostRadius ***************************

// ********** Begin Class UCBLiquidGlassDialog Function SetCardGlassOpacity ************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics
{
	struct CBLiquidGlassDialog_eventSetCardGlassOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCardGlassOpacity constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCardGlassOpacity constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCardGlassOpacity Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetCardGlassOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetCardGlassOpacity Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetCardGlassOpacity", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::CBLiquidGlassDialog_eventSetCardGlassOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::CBLiquidGlassDialog_eventSetCardGlassOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetCardGlassOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardGlassOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetCardGlassOpacity **************************

// ********** Begin Class UCBLiquidGlassDialog Function SetCardPrismIntensity **********************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics
{
	struct CBLiquidGlassDialog_eventSetCardPrismIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCardPrismIntensity constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCardPrismIntensity constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCardPrismIntensity Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetCardPrismIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetCardPrismIntensity Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetCardPrismIntensity", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::CBLiquidGlassDialog_eventSetCardPrismIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::CBLiquidGlassDialog_eventSetCardPrismIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetCardPrismIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardPrismIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetCardPrismIntensity ************************

// ********** Begin Class UCBLiquidGlassDialog Function SetCardRefractionStrength ******************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics
{
	struct CBLiquidGlassDialog_eventSetCardRefractionStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCardRefractionStrength constinit property declarations *************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCardRefractionStrength constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCardRefractionStrength Property Definitions ************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetCardRefractionStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::PropPointers) < 2048);
// ********** End Function SetCardRefractionStrength Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetCardRefractionStrength", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::CBLiquidGlassDialog_eventSetCardRefractionStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::CBLiquidGlassDialog_eventSetCardRefractionStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetCardRefractionStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardRefractionStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetCardRefractionStrength ********************

// ********** Begin Class UCBLiquidGlassDialog Function SetCardRefractionThickness *****************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics
{
	struct CBLiquidGlassDialog_eventSetCardRefractionThickness_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCardRefractionThickness constinit property declarations ************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCardRefractionThickness constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCardRefractionThickness Property Definitions ***********************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetCardRefractionThickness_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::PropPointers) < 2048);
// ********** End Function SetCardRefractionThickness Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetCardRefractionThickness", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::CBLiquidGlassDialog_eventSetCardRefractionThickness_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::CBLiquidGlassDialog_eventSetCardRefractionThickness_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetCardRefractionThickness)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardRefractionThickness(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetCardRefractionThickness *******************

// ********** Begin Class UCBLiquidGlassDialog Function SetCardRimIntensity ************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics
{
	struct CBLiquidGlassDialog_eventSetCardRimIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCardRimIntensity constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCardRimIntensity constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCardRimIntensity Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetCardRimIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetCardRimIntensity Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetCardRimIntensity", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::CBLiquidGlassDialog_eventSetCardRimIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::CBLiquidGlassDialog_eventSetCardRimIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetCardRimIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardRimIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetCardRimIntensity **************************

// ********** Begin Class UCBLiquidGlassDialog Function SetDimBackground ***************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics
{
	struct CBLiquidGlassDialog_eventSetDimBackground_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDimBackground constinit property declarations **********************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDimBackground constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDimBackground Property Definitions *********************************
void Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassDialog_eventSetDimBackground_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassDialog_eventSetDimBackground_Parms), &Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::PropPointers) < 2048);
// ********** End Function SetDimBackground Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetDimBackground", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::CBLiquidGlassDialog_eventSetDimBackground_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::CBLiquidGlassDialog_eventSetDimBackground_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetDimBackground)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDimBackground(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetDimBackground *****************************

// ********** Begin Class UCBLiquidGlassDialog Function SetDimOpacity ******************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics
{
	struct CBLiquidGlassDialog_eventSetDimOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDimOpacity constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDimOpacity constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDimOpacity Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetDimOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetDimOpacity Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetDimOpacity", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::CBLiquidGlassDialog_eventSetDimOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::CBLiquidGlassDialog_eventSetDimOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetDimOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDimOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetDimOpacity ********************************

// ********** Begin Class UCBLiquidGlassDialog Function SetMessage *********************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics
{
	struct CBLiquidGlassDialog_eventSetMessage_Parms
	{
		FText InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMessage constinit property declarations ****************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMessage constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMessage Property Definitions ***************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetMessage_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::PropPointers) < 2048);
// ********** End Function SetMessage Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetMessage", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::CBLiquidGlassDialog_eventSetMessage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::CBLiquidGlassDialog_eventSetMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetMessage)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMessage(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetMessage ***********************************

// ********** Begin Class UCBLiquidGlassDialog Function SetTitle ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics
{
	struct CBLiquidGlassDialog_eventSetTitle_Parms
	{
		FText InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTitle constinit property declarations ******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTitle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTitle Property Definitions *****************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassDialog_eventSetTitle_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::PropPointers) < 2048);
// ********** End Function SetTitle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassDialog, nullptr, "SetTitle", 	Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::CBLiquidGlassDialog_eventSetTitle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::CBLiquidGlassDialog_eventSetTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassDialog::execSetTitle)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTitle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassDialog Function SetTitle *************************************

// ********** Begin Class UCBLiquidGlassDialog *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassDialog;
UClass* UCBLiquidGlassDialog::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassDialog;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassDialog.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassDialog"),
			Z_Registration_Info_UClass_UCBLiquidGlassDialog.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassDialog,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassDialog.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassDialog_NoRegister()
{
	return UCBLiquidGlassDialog::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassDialog_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG modal glass dialog (alert / action sheet / sheet) with a spring entrance. */" },
#endif
		{ "DisplayName", "Liquid Glass Dialog" },
		{ "IncludePath", "CBLiquidGlassExtras.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG modal glass dialog (alert / action sheet / sheet) with a spring entrance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Buttons_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogStyle_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDimBackground_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DimOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStartPresented_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the dialog is shown as soon as it is constructed. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the dialog is shown as soon as it is constructed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardBlurStrength_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Card" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardFrostRadius_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Card" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardRefractionStrength_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Card" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardRefractionThickness_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Card" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardPrismIntensity_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Card" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardRimIntensity_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Card" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardGlassOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Card" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringSettings_MetaData[] = {
		{ "Category", "Liquid Glass Dialog" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnButtonClicked_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDismissed_MetaData[] = {
		{ "Category", "Liquid Glass Dialog|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassDialog constinit property declarations *********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Title;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Buttons_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Buttons;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DialogStyle_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DialogStyle;
	static void NewProp_bDimBackground_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDimBackground;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DimOpacity;
	static void NewProp_bStartPresented_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStartPresented;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CardBlurStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CardFrostRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CardRefractionStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CardRefractionThickness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CardPrismIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CardRimIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CardGlassOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpringSettings;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnButtonClicked;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDismissed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassDialog constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Dismiss"), .Pointer = &UCBLiquidGlassDialog::execDismiss },
		{ .NameUTF8 = UTF8TEXT("Present"), .Pointer = &UCBLiquidGlassDialog::execPresent },
		{ .NameUTF8 = UTF8TEXT("SetButtons"), .Pointer = &UCBLiquidGlassDialog::execSetButtons },
		{ .NameUTF8 = UTF8TEXT("SetCardBlurStrength"), .Pointer = &UCBLiquidGlassDialog::execSetCardBlurStrength },
		{ .NameUTF8 = UTF8TEXT("SetCardFrostRadius"), .Pointer = &UCBLiquidGlassDialog::execSetCardFrostRadius },
		{ .NameUTF8 = UTF8TEXT("SetCardGlassOpacity"), .Pointer = &UCBLiquidGlassDialog::execSetCardGlassOpacity },
		{ .NameUTF8 = UTF8TEXT("SetCardPrismIntensity"), .Pointer = &UCBLiquidGlassDialog::execSetCardPrismIntensity },
		{ .NameUTF8 = UTF8TEXT("SetCardRefractionStrength"), .Pointer = &UCBLiquidGlassDialog::execSetCardRefractionStrength },
		{ .NameUTF8 = UTF8TEXT("SetCardRefractionThickness"), .Pointer = &UCBLiquidGlassDialog::execSetCardRefractionThickness },
		{ .NameUTF8 = UTF8TEXT("SetCardRimIntensity"), .Pointer = &UCBLiquidGlassDialog::execSetCardRimIntensity },
		{ .NameUTF8 = UTF8TEXT("SetDimBackground"), .Pointer = &UCBLiquidGlassDialog::execSetDimBackground },
		{ .NameUTF8 = UTF8TEXT("SetDimOpacity"), .Pointer = &UCBLiquidGlassDialog::execSetDimOpacity },
		{ .NameUTF8 = UTF8TEXT("SetMessage"), .Pointer = &UCBLiquidGlassDialog::execSetMessage },
		{ .NameUTF8 = UTF8TEXT("SetTitle"), .Pointer = &UCBLiquidGlassDialog::execSetTitle },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_Dismiss, "Dismiss" }, // 3721307714
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_Present, "Present" }, // 404142366
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetButtons, "SetButtons" }, // 2717553217
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardBlurStrength, "SetCardBlurStrength" }, // 3186778440
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardFrostRadius, "SetCardFrostRadius" }, // 2590885354
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardGlassOpacity, "SetCardGlassOpacity" }, // 2335323441
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardPrismIntensity, "SetCardPrismIntensity" }, // 3852202030
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionStrength, "SetCardRefractionStrength" }, // 2558624695
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRefractionThickness, "SetCardRefractionThickness" }, // 2655056514
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetCardRimIntensity, "SetCardRimIntensity" }, // 3075990916
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimBackground, "SetDimBackground" }, // 2100331267
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetDimOpacity, "SetDimOpacity" }, // 2348161989
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetMessage, "SetMessage" }, // 4001826391
		{ &Z_Construct_UFunction_UCBLiquidGlassDialog_SetTitle, "SetTitle" }, // 118039356
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassDialog>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassDialog_Statics

// ********** Begin Class UCBLiquidGlassDialog Property Definitions ********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Buttons_Inner = { "Buttons", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Buttons = { "Buttons", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, Buttons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Buttons_MetaData), NewProp_Buttons_MetaData) }; // 688407273
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_DialogStyle_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_DialogStyle = { "DialogStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, DialogStyle), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassDialogStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogStyle_MetaData), NewProp_DialogStyle_MetaData) }; // 1484063289
void Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_bDimBackground_SetBit(void* Obj)
{
	((UCBLiquidGlassDialog*)Obj)->bDimBackground = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_bDimBackground = { "bDimBackground", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCBLiquidGlassDialog), &Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_bDimBackground_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDimBackground_MetaData), NewProp_bDimBackground_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_DimOpacity = { "DimOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, DimOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DimOpacity_MetaData), NewProp_DimOpacity_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_bStartPresented_SetBit(void* Obj)
{
	((UCBLiquidGlassDialog*)Obj)->bStartPresented = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_bStartPresented = { "bStartPresented", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCBLiquidGlassDialog), &Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_bStartPresented_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStartPresented_MetaData), NewProp_bStartPresented_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardBlurStrength = { "CardBlurStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, CardBlurStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardBlurStrength_MetaData), NewProp_CardBlurStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardFrostRadius = { "CardFrostRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, CardFrostRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardFrostRadius_MetaData), NewProp_CardFrostRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardRefractionStrength = { "CardRefractionStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, CardRefractionStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardRefractionStrength_MetaData), NewProp_CardRefractionStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardRefractionThickness = { "CardRefractionThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, CardRefractionThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardRefractionThickness_MetaData), NewProp_CardRefractionThickness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardPrismIntensity = { "CardPrismIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, CardPrismIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardPrismIntensity_MetaData), NewProp_CardPrismIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardRimIntensity = { "CardRimIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, CardRimIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardRimIntensity_MetaData), NewProp_CardRimIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardGlassOpacity = { "CardGlassOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, CardGlassOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardGlassOpacity_MetaData), NewProp_CardGlassOpacity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_SpringSettings = { "SpringSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, SpringSettings), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringSettings_MetaData), NewProp_SpringSettings_MetaData) }; // 4164173022
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_OnButtonClicked = { "OnButtonClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, OnButtonClicked), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassActionEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnButtonClicked_MetaData), NewProp_OnButtonClicked_MetaData) }; // 1312018797
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_OnDismissed = { "OnDismissed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassDialog, OnDismissed), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassSimpleEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDismissed_MetaData), NewProp_OnDismissed_MetaData) }; // 2661696606
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassDialog_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Buttons_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Buttons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_DialogStyle_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_DialogStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_bDimBackground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_DimOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_bStartPresented,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardBlurStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardFrostRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardRefractionStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardRefractionThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardPrismIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardRimIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_CardGlassOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_SpringSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_OnButtonClicked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassDialog_Statics::NewProp_OnDismissed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassDialog_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassDialog Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassDialog_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassDialog_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassDialog_Statics::ClassParams = {
	&UCBLiquidGlassDialog::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassDialog_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassDialog_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassDialog_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassDialog_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassDialog::StaticRegisterNativesUCBLiquidGlassDialog()
{
	UClass* Class = UCBLiquidGlassDialog::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassDialog_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassDialog()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassDialog.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassDialog.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassDialog_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassDialog.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassDialog);
UCBLiquidGlassDialog::~UCBLiquidGlassDialog() {}
// ********** End Class UCBLiquidGlassDialog *******************************************************

// ********** Begin Class UCBLiquidGlassContainer Function SetBlobs ********************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics
{
	struct CBLiquidGlassContainer_eventSetBlobs_Parms
	{
		TArray<FCBLiquidGlassFusionBlob> InBlobs;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBlobs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBlobs constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBlobs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InBlobs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBlobs constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBlobs Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::NewProp_InBlobs_Inner = { "InBlobs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob, METADATA_PARAMS(0, nullptr) }; // 4080855366
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::NewProp_InBlobs = { "InBlobs", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetBlobs_Parms, InBlobs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBlobs_MetaData), NewProp_InBlobs_MetaData) }; // 4080855366
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::NewProp_InBlobs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::NewProp_InBlobs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::PropPointers) < 2048);
// ********** End Function SetBlobs Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetBlobs", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::CBLiquidGlassContainer_eventSetBlobs_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::CBLiquidGlassContainer_eventSetBlobs_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetBlobs)
{
	P_GET_TARRAY_REF(FCBLiquidGlassFusionBlob,Z_Param_Out_InBlobs);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBlobs(Z_Param_Out_InBlobs);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetBlobs **********************************

// ********** Begin Class UCBLiquidGlassContainer Function SetBlurStrength *************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics
{
	struct CBLiquidGlassContainer_eventSetBlurStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBlurStrength constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBlurStrength constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBlurStrength Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetBlurStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::PropPointers) < 2048);
// ********** End Function SetBlurStrength Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetBlurStrength", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::CBLiquidGlassContainer_eventSetBlurStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::CBLiquidGlassContainer_eventSetBlurStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetBlurStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBlurStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetBlurStrength ***************************

// ********** Begin Class UCBLiquidGlassContainer Function SetCanvasSize ***************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics
{
	struct CBLiquidGlassContainer_eventSetCanvasSize_Parms
	{
		FVector2D InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCanvasSize constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCanvasSize constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCanvasSize Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetCanvasSize_Parms, InValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::PropPointers) < 2048);
// ********** End Function SetCanvasSize Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetCanvasSize", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::CBLiquidGlassContainer_eventSetCanvasSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::CBLiquidGlassContainer_eventSetCanvasSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetCanvasSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCanvasSize(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetCanvasSize *****************************

// ********** Begin Class UCBLiquidGlassContainer Function SetFrostRadius **************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics
{
	struct CBLiquidGlassContainer_eventSetFrostRadius_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFrostRadius constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFrostRadius constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFrostRadius Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetFrostRadius_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::PropPointers) < 2048);
// ********** End Function SetFrostRadius Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetFrostRadius", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::CBLiquidGlassContainer_eventSetFrostRadius_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::CBLiquidGlassContainer_eventSetFrostRadius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetFrostRadius)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFrostRadius(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetFrostRadius ****************************

// ********** Begin Class UCBLiquidGlassContainer Function SetGlassOpacity *************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics
{
	struct CBLiquidGlassContainer_eventSetGlassOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetGlassOpacity constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGlassOpacity constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGlassOpacity Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetGlassOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetGlassOpacity Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetGlassOpacity", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::CBLiquidGlassContainer_eventSetGlassOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::CBLiquidGlassContainer_eventSetGlassOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetGlassOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGlassOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetGlassOpacity ***************************

// ********** Begin Class UCBLiquidGlassContainer Function SetMaskResolution ***********************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics
{
	struct CBLiquidGlassContainer_eventSetMaskResolution_Parms
	{
		FVector2D InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMaskResolution constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMaskResolution constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMaskResolution Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetMaskResolution_Parms, InValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::PropPointers) < 2048);
// ********** End Function SetMaskResolution Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetMaskResolution", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::CBLiquidGlassContainer_eventSetMaskResolution_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::CBLiquidGlassContainer_eventSetMaskResolution_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetMaskResolution)
{
	P_GET_STRUCT(FVector2D,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaskResolution(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetMaskResolution *************************

// ********** Begin Class UCBLiquidGlassContainer Function SetPreset *******************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics
{
	struct CBLiquidGlassContainer_eventSetPreset_Parms
	{
		ECBLiquidGlassPreset InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetPreset_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(0, nullptr) }; // 3360299489
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::PropPointers) < 2048);
// ********** End Function SetPreset Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetPreset", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::CBLiquidGlassContainer_eventSetPreset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::CBLiquidGlassContainer_eventSetPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetPreset)
{
	P_GET_ENUM(ECBLiquidGlassPreset,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPreset(ECBLiquidGlassPreset(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetPreset *********************************

// ********** Begin Class UCBLiquidGlassContainer Function SetPrismIntensity ***********************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics
{
	struct CBLiquidGlassContainer_eventSetPrismIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPrismIntensity constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPrismIntensity constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPrismIntensity Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetPrismIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetPrismIntensity Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetPrismIntensity", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::CBLiquidGlassContainer_eventSetPrismIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::CBLiquidGlassContainer_eventSetPrismIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetPrismIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPrismIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetPrismIntensity *************************

// ********** Begin Class UCBLiquidGlassContainer Function SetQuality ******************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics
{
	struct CBLiquidGlassContainer_eventSetQuality_Parms
	{
		ECBLiquidGlassQuality InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetQuality_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(0, nullptr) }; // 2771085032
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::PropPointers) < 2048);
// ********** End Function SetQuality Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetQuality", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::CBLiquidGlassContainer_eventSetQuality_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::CBLiquidGlassContainer_eventSetQuality_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetQuality)
{
	P_GET_ENUM(ECBLiquidGlassQuality,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetQuality(ECBLiquidGlassQuality(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetQuality ********************************

// ********** Begin Class UCBLiquidGlassContainer Function SetRefractionStrength *******************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics
{
	struct CBLiquidGlassContainer_eventSetRefractionStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetRefractionStrength constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRefractionStrength constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRefractionStrength Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetRefractionStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::PropPointers) < 2048);
// ********** End Function SetRefractionStrength Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetRefractionStrength", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::CBLiquidGlassContainer_eventSetRefractionStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::CBLiquidGlassContainer_eventSetRefractionStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetRefractionStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRefractionStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetRefractionStrength *********************

// ********** Begin Class UCBLiquidGlassContainer Function SetRefractionThickness ******************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics
{
	struct CBLiquidGlassContainer_eventSetRefractionThickness_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetRefractionThickness constinit property declarations ****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRefractionThickness constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRefractionThickness Property Definitions ***************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetRefractionThickness_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::PropPointers) < 2048);
// ********** End Function SetRefractionThickness Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetRefractionThickness", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::CBLiquidGlassContainer_eventSetRefractionThickness_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::CBLiquidGlassContainer_eventSetRefractionThickness_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetRefractionThickness)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRefractionThickness(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetRefractionThickness ********************

// ********** Begin Class UCBLiquidGlassContainer Function SetRimIntensity *************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics
{
	struct CBLiquidGlassContainer_eventSetRimIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetRimIntensity constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRimIntensity constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRimIntensity Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetRimIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetRimIntensity Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetRimIntensity", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::CBLiquidGlassContainer_eventSetRimIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::CBLiquidGlassContainer_eventSetRimIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetRimIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRimIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetRimIntensity ***************************

// ********** Begin Class UCBLiquidGlassContainer Function SetSmoothing ****************************
struct Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics
{
	struct CBLiquidGlassContainer_eventSetSmoothing_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSmoothing constinit property declarations **************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSmoothing constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSmoothing Property Definitions *************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassContainer_eventSetSmoothing_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::PropPointers) < 2048);
// ********** End Function SetSmoothing Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassContainer, nullptr, "SetSmoothing", 	Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::CBLiquidGlassContainer_eventSetSmoothing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::CBLiquidGlassContainer_eventSetSmoothing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassContainer::execSetSmoothing)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSmoothing(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassContainer Function SetSmoothing ******************************

// ********** Begin Class UCBLiquidGlassContainer **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassContainer;
UClass* UCBLiquidGlassContainer::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassContainer;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassContainer.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassContainer"),
			Z_Registration_Info_UClass_UCBLiquidGlassContainer.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassContainer,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassContainer.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassContainer_NoRegister()
{
	return UCBLiquidGlassContainer::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassContainer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG Liquid Glass fusion container (Apple GlassEffectContainer): blobs melt into one silhouette. */" },
#endif
		{ "DisplayName", "Liquid Glass Container" },
		{ "IncludePath", "CBLiquidGlassExtras.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG Liquid Glass fusion container (Apple GlassEffectContainer): blobs melt into one silhouette." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Blobs_MetaData[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Smoothing_MetaData[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Merge radius in pixels; larger melts neighbouring blobs together more. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Merge radius in pixels; larger melts neighbouring blobs together more." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CanvasSize_MetaData[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaskResolution_MetaData[] = {
		{ "Category", "Liquid Glass Container" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Resolution of the generated alpha mask. Leave at zero to derive it from CanvasSize\n\x09 * and clamp to a safe 1024 px maximum per axis.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resolution of the generated alpha mask. Leave at zero to derive it from CanvasSize\nand clamp to a safe 1024 px maximum per axis." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlurStrength_MetaData[] = {
		{ "Category", "Liquid Glass Container|Visual" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrostRadius_MetaData[] = {
		{ "Category", "Liquid Glass Container|Visual" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefractionStrength_MetaData[] = {
		{ "Category", "Liquid Glass Container|Visual" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefractionThickness_MetaData[] = {
		{ "Category", "Liquid Glass Container|Visual" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrismIntensity_MetaData[] = {
		{ "Category", "Liquid Glass Container|Visual" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RimIntensity_MetaData[] = {
		{ "Category", "Liquid Glass Container|Visual" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlassOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Container|Visual" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quality_MetaData[] = {
		{ "Category", "Liquid Glass Container" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassExtras.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassContainer constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Blobs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Blobs;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Smoothing;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CanvasSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaskResolution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlurStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrostRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RefractionStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RefractionThickness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PrismIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RimIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlassOpacity;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Quality_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Quality;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassContainer constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetBlobs"), .Pointer = &UCBLiquidGlassContainer::execSetBlobs },
		{ .NameUTF8 = UTF8TEXT("SetBlurStrength"), .Pointer = &UCBLiquidGlassContainer::execSetBlurStrength },
		{ .NameUTF8 = UTF8TEXT("SetCanvasSize"), .Pointer = &UCBLiquidGlassContainer::execSetCanvasSize },
		{ .NameUTF8 = UTF8TEXT("SetFrostRadius"), .Pointer = &UCBLiquidGlassContainer::execSetFrostRadius },
		{ .NameUTF8 = UTF8TEXT("SetGlassOpacity"), .Pointer = &UCBLiquidGlassContainer::execSetGlassOpacity },
		{ .NameUTF8 = UTF8TEXT("SetMaskResolution"), .Pointer = &UCBLiquidGlassContainer::execSetMaskResolution },
		{ .NameUTF8 = UTF8TEXT("SetPreset"), .Pointer = &UCBLiquidGlassContainer::execSetPreset },
		{ .NameUTF8 = UTF8TEXT("SetPrismIntensity"), .Pointer = &UCBLiquidGlassContainer::execSetPrismIntensity },
		{ .NameUTF8 = UTF8TEXT("SetQuality"), .Pointer = &UCBLiquidGlassContainer::execSetQuality },
		{ .NameUTF8 = UTF8TEXT("SetRefractionStrength"), .Pointer = &UCBLiquidGlassContainer::execSetRefractionStrength },
		{ .NameUTF8 = UTF8TEXT("SetRefractionThickness"), .Pointer = &UCBLiquidGlassContainer::execSetRefractionThickness },
		{ .NameUTF8 = UTF8TEXT("SetRimIntensity"), .Pointer = &UCBLiquidGlassContainer::execSetRimIntensity },
		{ .NameUTF8 = UTF8TEXT("SetSmoothing"), .Pointer = &UCBLiquidGlassContainer::execSetSmoothing },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlobs, "SetBlobs" }, // 1236300778
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetBlurStrength, "SetBlurStrength" }, // 19837011
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetCanvasSize, "SetCanvasSize" }, // 3173468745
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetFrostRadius, "SetFrostRadius" }, // 877928341
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetGlassOpacity, "SetGlassOpacity" }, // 196087317
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetMaskResolution, "SetMaskResolution" }, // 248450434
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetPreset, "SetPreset" }, // 4082491260
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetPrismIntensity, "SetPrismIntensity" }, // 2626760788
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetQuality, "SetQuality" }, // 2005982054
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionStrength, "SetRefractionStrength" }, // 1249710618
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetRefractionThickness, "SetRefractionThickness" }, // 3950894818
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetRimIntensity, "SetRimIntensity" }, // 1800261197
		{ &Z_Construct_UFunction_UCBLiquidGlassContainer_SetSmoothing, "SetSmoothing" }, // 2553852987
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassContainer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassContainer_Statics

// ********** Begin Class UCBLiquidGlassContainer Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Blobs_Inner = { "Blobs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob, METADATA_PARAMS(0, nullptr) }; // 4080855366
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Blobs = { "Blobs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, Blobs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Blobs_MetaData), NewProp_Blobs_MetaData) }; // 4080855366
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Smoothing = { "Smoothing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, Smoothing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Smoothing_MetaData), NewProp_Smoothing_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_CanvasSize = { "CanvasSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, CanvasSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CanvasSize_MetaData), NewProp_CanvasSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_MaskResolution = { "MaskResolution", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, MaskResolution), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaskResolution_MetaData), NewProp_MaskResolution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_BlurStrength = { "BlurStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, BlurStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlurStrength_MetaData), NewProp_BlurStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_FrostRadius = { "FrostRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, FrostRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrostRadius_MetaData), NewProp_FrostRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_RefractionStrength = { "RefractionStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, RefractionStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefractionStrength_MetaData), NewProp_RefractionStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_RefractionThickness = { "RefractionThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, RefractionThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefractionThickness_MetaData), NewProp_RefractionThickness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_PrismIntensity = { "PrismIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, PrismIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrismIntensity_MetaData), NewProp_PrismIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_RimIntensity = { "RimIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, RimIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RimIntensity_MetaData), NewProp_RimIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_GlassOpacity = { "GlassOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, GlassOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlassOpacity_MetaData), NewProp_GlassOpacity_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, Preset), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Preset_MetaData), NewProp_Preset_MetaData) }; // 3360299489
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Quality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Quality = { "Quality", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassContainer, Quality), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quality_MetaData), NewProp_Quality_MetaData) }; // 2771085032
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassContainer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Blobs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Blobs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Smoothing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_CanvasSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_MaskResolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_BlurStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_FrostRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_RefractionStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_RefractionThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_PrismIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_RimIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_GlassOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Quality_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassContainer_Statics::NewProp_Quality,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassContainer_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassContainer Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassContainer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UContentWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassContainer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassContainer_Statics::ClassParams = {
	&UCBLiquidGlassContainer::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassContainer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassContainer_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassContainer_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassContainer_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassContainer::StaticRegisterNativesUCBLiquidGlassContainer()
{
	UClass* Class = UCBLiquidGlassContainer::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassContainer_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassContainer()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassContainer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassContainer.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassContainer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassContainer.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassContainer);
UCBLiquidGlassContainer::~UCBLiquidGlassContainer() {}
// ********** End Class UCBLiquidGlassContainer ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h__Script_CBLiquidGlass_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCBLiquidGlassBadge, UCBLiquidGlassBadge::StaticClass, TEXT("UCBLiquidGlassBadge"), &Z_Registration_Info_UClass_UCBLiquidGlassBadge, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassBadge), 3820040807U) },
		{ Z_Construct_UClass_UCBLiquidGlassPageControl, UCBLiquidGlassPageControl::StaticClass, TEXT("UCBLiquidGlassPageControl"), &Z_Registration_Info_UClass_UCBLiquidGlassPageControl, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassPageControl), 4032882227U) },
		{ Z_Construct_UClass_UCBLiquidGlassNavigationBar, UCBLiquidGlassNavigationBar::StaticClass, TEXT("UCBLiquidGlassNavigationBar"), &Z_Registration_Info_UClass_UCBLiquidGlassNavigationBar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassNavigationBar), 3526075518U) },
		{ Z_Construct_UClass_UCBLiquidGlassDialog, UCBLiquidGlassDialog::StaticClass, TEXT("UCBLiquidGlassDialog"), &Z_Registration_Info_UClass_UCBLiquidGlassDialog, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassDialog), 2305611427U) },
		{ Z_Construct_UClass_UCBLiquidGlassContainer, UCBLiquidGlassContainer::StaticClass, TEXT("UCBLiquidGlassContainer"), &Z_Registration_Info_UClass_UCBLiquidGlassContainer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassContainer), 3367896113U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h__Script_CBLiquidGlass_828425061{
	TEXT("/Script/CBLiquidGlass"),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h__Script_CBLiquidGlass_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h__Script_CBLiquidGlass_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

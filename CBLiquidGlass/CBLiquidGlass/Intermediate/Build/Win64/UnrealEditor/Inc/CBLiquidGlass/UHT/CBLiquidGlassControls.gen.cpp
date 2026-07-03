// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassControls.h"
#include "CBLiquidGlassTypes.h"
#include "Layout/Margin.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassControls() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassMenu();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassMenu_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassProgress();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassProgress_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSearchBar();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSearchBar_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSegmentedControl();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSegmentedControl_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassStepper();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassStepper_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassTabBar();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassTabBar_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassToggle();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassToggle_NoRegister();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassToolbar();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassToolbar_NoRegister();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle();
CBLIQUIDGLASS_API UEnum* Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature();
CBLIQUIDGLASS_API UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassItem();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle();
CBLIQUIDGLASS_API UScriptStruct* Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
UMG_API UClass* Z_Construct_UClass_UWidget();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FCBLiquidGlassToggleChangedEvent **************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassToggleChangedEvent_Parms
	{
		bool bChecked;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassToggleChangedEvent constinit property declarations ******
	static void NewProp_bChecked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bChecked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FCBLiquidGlassToggleChangedEvent constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FCBLiquidGlassToggleChangedEvent Property Definitions *****************
void Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::NewProp_bChecked_SetBit(void* Obj)
{
	((_Script_CBLiquidGlass_eventCBLiquidGlassToggleChangedEvent_Parms*)Obj)->bChecked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::NewProp_bChecked = { "bChecked", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_CBLiquidGlass_eventCBLiquidGlassToggleChangedEvent_Parms), &Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::NewProp_bChecked_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::NewProp_bChecked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FCBLiquidGlassToggleChangedEvent Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassToggleChangedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassToggleChangedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassToggleChangedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassToggleChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassToggleChangedEvent, bool bChecked)
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassToggleChangedEvent_Parms
	{
		bool bChecked;
	};
	_Script_CBLiquidGlass_eventCBLiquidGlassToggleChangedEvent_Parms Parms;
	Parms.bChecked=bChecked ? true : false;
	CBLiquidGlassToggleChangedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FCBLiquidGlassToggleChangedEvent ****************************************

// ********** Begin Delegate FCBLiquidGlassIndexChangedEvent ***************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassIndexChangedEvent_Parms
	{
		int32 Index;
		int32 Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassIndexChangedEvent constinit property declarations *******
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FCBLiquidGlassIndexChangedEvent constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FCBLiquidGlassIndexChangedEvent Property Definitions ******************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassIndexChangedEvent_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassIndexChangedEvent_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FCBLiquidGlassIndexChangedEvent Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassIndexChangedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassIndexChangedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassIndexChangedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassIndexChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassIndexChangedEvent, int32 Index, int32 Value)
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassIndexChangedEvent_Parms
	{
		int32 Index;
		int32 Value;
	};
	_Script_CBLiquidGlass_eventCBLiquidGlassIndexChangedEvent_Parms Parms;
	Parms.Index=Index;
	Parms.Value=Value;
	CBLiquidGlassIndexChangedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FCBLiquidGlassIndexChangedEvent *****************************************

// ********** Begin Delegate FCBLiquidGlassItemClickedEvent ****************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassItemClickedEvent_Parms
	{
		int32 Index;
		int32 Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassItemClickedEvent constinit property declarations ********
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FCBLiquidGlassItemClickedEvent constinit property declarations **********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FCBLiquidGlassItemClickedEvent Property Definitions *******************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassItemClickedEvent_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassItemClickedEvent_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FCBLiquidGlassItemClickedEvent Property Definitions *********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassItemClickedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassItemClickedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassItemClickedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassItemClickedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassItemClickedEvent, int32 Index, int32 Value)
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassItemClickedEvent_Parms
	{
		int32 Index;
		int32 Value;
	};
	_Script_CBLiquidGlass_eventCBLiquidGlassItemClickedEvent_Parms Parms;
	Parms.Index=Index;
	Parms.Value=Value;
	CBLiquidGlassItemClickedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FCBLiquidGlassItemClickedEvent ******************************************

// ********** Begin Delegate FCBLiquidGlassTextChangedEvent ****************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassTextChangedEvent_Parms
	{
		FText Text;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassTextChangedEvent constinit property declarations ********
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FCBLiquidGlassTextChangedEvent constinit property declarations **********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FCBLiquidGlassTextChangedEvent Property Definitions *******************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassTextChangedEvent_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::NewProp_Text,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FCBLiquidGlassTextChangedEvent Property Definitions *********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassTextChangedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassTextChangedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassTextChangedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassTextChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassTextChangedEvent, FText const& Text)
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassTextChangedEvent_Parms
	{
		FText Text;
	};
	_Script_CBLiquidGlass_eventCBLiquidGlassTextChangedEvent_Parms Parms;
	Parms.Text=Text;
	CBLiquidGlassTextChangedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FCBLiquidGlassTextChangedEvent ******************************************

// ********** Begin Delegate FCBLiquidGlassFloatChangedEvent ***************************************
struct Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassFloatChangedEvent_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FCBLiquidGlassFloatChangedEvent constinit property declarations *******
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FCBLiquidGlassFloatChangedEvent constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FCBLiquidGlassFloatChangedEvent Property Definitions ******************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CBLiquidGlass_eventCBLiquidGlassFloatChangedEvent_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FCBLiquidGlassFloatChangedEvent Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CBLiquidGlass, nullptr, "CBLiquidGlassFloatChangedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassFloatChangedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::_Script_CBLiquidGlass_eventCBLiquidGlassFloatChangedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCBLiquidGlassFloatChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassFloatChangedEvent, float Value)
{
	struct _Script_CBLiquidGlass_eventCBLiquidGlassFloatChangedEvent_Parms
	{
		float Value;
	};
	_Script_CBLiquidGlass_eventCBLiquidGlassFloatChangedEvent_Parms Parms;
	Parms.Value=Value;
	CBLiquidGlassFloatChangedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FCBLiquidGlassFloatChangedEvent *****************************************

// ********** Begin Class UCBLiquidGlassToggle Function SetChecked *********************************
struct Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics
{
	struct CBLiquidGlassToggle_eventSetChecked_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toggle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the checked state and moves the glass thumb to the matching side. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the checked state and moves the glass thumb to the matching side." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetChecked constinit property declarations ****************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetChecked constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetChecked Property Definitions ***************************************
void Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassToggle_eventSetChecked_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassToggle_eventSetChecked_Parms), &Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::PropPointers) < 2048);
// ********** End Function SetChecked Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToggle, nullptr, "SetChecked", 	Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::CBLiquidGlassToggle_eventSetChecked_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::CBLiquidGlassToggle_eventSetChecked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToggle::execSetChecked)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetChecked(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToggle Function SetChecked ***********************************

// ********** Begin Class UCBLiquidGlassToggle Function SetOffColor ********************************
struct Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics
{
	struct CBLiquidGlassToggle_eventSetOffColor_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toggle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the track tint used when the toggle is unchecked. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the track tint used when the toggle is unchecked." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetOffColor constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetOffColor constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetOffColor Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToggle_eventSetOffColor_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::PropPointers) < 2048);
// ********** End Function SetOffColor Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToggle, nullptr, "SetOffColor", 	Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::CBLiquidGlassToggle_eventSetOffColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::CBLiquidGlassToggle_eventSetOffColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToggle::execSetOffColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOffColor(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToggle Function SetOffColor **********************************

// ********** Begin Class UCBLiquidGlassToggle Function SetOnColor *********************************
struct Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics
{
	struct CBLiquidGlassToggle_eventSetOnColor_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toggle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the track tint used when the toggle is checked. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the track tint used when the toggle is checked." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetOnColor constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetOnColor constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetOnColor Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToggle_eventSetOnColor_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::PropPointers) < 2048);
// ********** End Function SetOnColor Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToggle, nullptr, "SetOnColor", 	Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::CBLiquidGlassToggle_eventSetOnColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::CBLiquidGlassToggle_eventSetOnColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToggle::execSetOnColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOnColor(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToggle Function SetOnColor ***********************************

// ********** Begin Class UCBLiquidGlassToggle Function SetSpringSettings **************************
struct Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics
{
	struct CBLiquidGlassToggle_eventSetSpringSettings_Parms
	{
		FCBLiquidGlassSpringSettings InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toggle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the spring used by the thumb animation. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the spring used by the thumb animation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSpringSettings constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSpringSettings constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSpringSettings Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToggle_eventSetSpringSettings_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, METADATA_PARAMS(0, nullptr) }; // 4164173022
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::PropPointers) < 2048);
// ********** End Function SetSpringSettings Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToggle, nullptr, "SetSpringSettings", 	Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::CBLiquidGlassToggle_eventSetSpringSettings_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::CBLiquidGlassToggle_eventSetSpringSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToggle::execSetSpringSettings)
{
	P_GET_STRUCT(FCBLiquidGlassSpringSettings,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSpringSettings(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToggle Function SetSpringSettings ****************************

// ********** Begin Class UCBLiquidGlassToggle Function SetStyle ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics
{
	struct CBLiquidGlassToggle_eventSetStyle_Parms
	{
		FCBLiquidGlassControlStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toggle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the shared glass preset, quality, size and accent colour used by the toggle. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the shared glass preset, quality, size and accent colour used by the toggle." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStyle constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStyle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStyle Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToggle_eventSetStyle_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(0, nullptr) }; // 3956690548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::PropPointers) < 2048);
// ********** End Function SetStyle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToggle, nullptr, "SetStyle", 	Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::CBLiquidGlassToggle_eventSetStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::CBLiquidGlassToggle_eventSetStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToggle::execSetStyle)
{
	P_GET_STRUCT(FCBLiquidGlassControlStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStyle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToggle Function SetStyle *************************************

// ********** Begin Class UCBLiquidGlassToggle *****************************************************
void UCBLiquidGlassToggle::GetbChecked_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToggle* Obj = (const UCBLiquidGlassToggle*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetChecked();
}
void UCBLiquidGlassToggle::SetbChecked_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToggle* Obj = (UCBLiquidGlassToggle*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetChecked(Value);
}
void UCBLiquidGlassToggle::GetOnColor_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToggle* Obj = (const UCBLiquidGlassToggle*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetOnColor();
}
void UCBLiquidGlassToggle::SetOnColor_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToggle* Obj = (UCBLiquidGlassToggle*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetOnColor(Value);
}
void UCBLiquidGlassToggle::GetOffColor_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToggle* Obj = (const UCBLiquidGlassToggle*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetOffColor();
}
void UCBLiquidGlassToggle::SetOffColor_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToggle* Obj = (UCBLiquidGlassToggle*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetOffColor(Value);
}
void UCBLiquidGlassToggle::GetStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToggle* Obj = (const UCBLiquidGlassToggle*)Object;
	FCBLiquidGlassControlStyle& Result = *(FCBLiquidGlassControlStyle*)OutValue;
	Result = (FCBLiquidGlassControlStyle)Obj->GetStyle();
}
void UCBLiquidGlassToggle::SetStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToggle* Obj = (UCBLiquidGlassToggle*)Object;
	FCBLiquidGlassControlStyle& Value = *(FCBLiquidGlassControlStyle*)InValue;
	Obj->SetStyle(Value);
}
void UCBLiquidGlassToggle::GetSpringSettings_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToggle* Obj = (const UCBLiquidGlassToggle*)Object;
	FCBLiquidGlassSpringSettings& Result = *(FCBLiquidGlassSpringSettings*)OutValue;
	Result = (FCBLiquidGlassSpringSettings)Obj->GetSpringSettings();
}
void UCBLiquidGlassToggle::SetSpringSettings_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToggle* Obj = (UCBLiquidGlassToggle*)Object;
	FCBLiquidGlassSpringSettings& Value = *(FCBLiquidGlassSpringSettings*)InValue;
	Obj->SetSpringSettings(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassToggle;
UClass* UCBLiquidGlassToggle::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassToggle;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassToggle.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassToggle"),
			Z_Registration_Info_UClass_UCBLiquidGlassToggle.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassToggle,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassToggle.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassToggle_NoRegister()
{
	return UCBLiquidGlassToggle::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassToggle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG  liquid glass switch. */" },
#endif
		{ "DisplayName", "Liquid Glass Toggle" },
		{ "IncludePath", "CBLiquidGlassControls.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG  liquid glass switch." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bChecked_MetaData[] = {
		{ "Category", "Liquid Glass Toggle" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnColor_MetaData[] = {
		{ "Category", "Liquid Glass Toggle" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffColor_MetaData[] = {
		{ "Category", "Liquid Glass Toggle" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Toggle" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringSettings_MetaData[] = {
		{ "Category", "Liquid Glass Toggle" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCheckStateChanged_MetaData[] = {
		{ "Category", "Liquid Glass Toggle|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassToggle constinit property declarations *********************
	static void NewProp_bChecked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bChecked;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OnColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OffColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpringSettings;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCheckStateChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassToggle constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetChecked"), .Pointer = &UCBLiquidGlassToggle::execSetChecked },
		{ .NameUTF8 = UTF8TEXT("SetOffColor"), .Pointer = &UCBLiquidGlassToggle::execSetOffColor },
		{ .NameUTF8 = UTF8TEXT("SetOnColor"), .Pointer = &UCBLiquidGlassToggle::execSetOnColor },
		{ .NameUTF8 = UTF8TEXT("SetSpringSettings"), .Pointer = &UCBLiquidGlassToggle::execSetSpringSettings },
		{ .NameUTF8 = UTF8TEXT("SetStyle"), .Pointer = &UCBLiquidGlassToggle::execSetStyle },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassToggle_SetChecked, "SetChecked" }, // 3821516538
		{ &Z_Construct_UFunction_UCBLiquidGlassToggle_SetOffColor, "SetOffColor" }, // 1114174800
		{ &Z_Construct_UFunction_UCBLiquidGlassToggle_SetOnColor, "SetOnColor" }, // 3548579579
		{ &Z_Construct_UFunction_UCBLiquidGlassToggle_SetSpringSettings, "SetSpringSettings" }, // 1211095167
		{ &Z_Construct_UFunction_UCBLiquidGlassToggle_SetStyle, "SetStyle" }, // 2823636079
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassToggle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassToggle_Statics

// ********** Begin Class UCBLiquidGlassToggle Property Definitions ********************************
void Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_bChecked_SetBit(void* Obj)
{
	((UCBLiquidGlassToggle*)Obj)->bChecked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_bChecked = { "bChecked", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToggle::SetbChecked_WrapperImpl, &UCBLiquidGlassToggle::GetbChecked_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassToggle), &Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_bChecked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bChecked_MetaData), NewProp_bChecked_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_OnColor = { "OnColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToggle::SetOnColor_WrapperImpl, &UCBLiquidGlassToggle::GetOnColor_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToggle, OnColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnColor_MetaData), NewProp_OnColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_OffColor = { "OffColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToggle::SetOffColor_WrapperImpl, &UCBLiquidGlassToggle::GetOffColor_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToggle, OffColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffColor_MetaData), NewProp_OffColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToggle::SetStyle_WrapperImpl, &UCBLiquidGlassToggle::GetStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToggle, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_SpringSettings = { "SpringSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToggle::SetSpringSettings_WrapperImpl, &UCBLiquidGlassToggle::GetSpringSettings_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToggle, SpringSettings), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringSettings_MetaData), NewProp_SpringSettings_MetaData) }; // 4164173022
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_OnCheckStateChanged = { "OnCheckStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassToggle, OnCheckStateChanged), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassToggleChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCheckStateChanged_MetaData), NewProp_OnCheckStateChanged_MetaData) }; // 1560302945
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassToggle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_bChecked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_OnColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_OffColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_SpringSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToggle_Statics::NewProp_OnCheckStateChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassToggle_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassToggle Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassToggle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassToggle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassToggle_Statics::ClassParams = {
	&UCBLiquidGlassToggle::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassToggle_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassToggle_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassToggle_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassToggle_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassToggle::StaticRegisterNativesUCBLiquidGlassToggle()
{
	UClass* Class = UCBLiquidGlassToggle::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassToggle_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassToggle()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassToggle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassToggle.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassToggle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassToggle.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassToggle);
UCBLiquidGlassToggle::~UCBLiquidGlassToggle() {}
// ********** End Class UCBLiquidGlassToggle *******************************************************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetItems *************************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetItems_Parms
	{
		TArray<FCBLiquidGlassItem> InItems;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replaces all selectable segment items and clamps the current selection to the new range. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replaces all selectable segment items and clamps the current selection to the new range." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItems_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetItems constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InItems;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItems constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItems Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::NewProp_InItems_Inner = { "InItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::NewProp_InItems = { "InItems", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSegmentedControl_eventSetItems_Parms, InItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItems_MetaData), NewProp_InItems_MetaData) }; // 688407273
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::NewProp_InItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::NewProp_InItems,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::PropPointers) < 2048);
// ********** End Function SetItems Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetItems", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::CBLiquidGlassSegmentedControl_eventSetItems_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::CBLiquidGlassSegmentedControl_eventSetItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetItems)
{
	P_GET_TARRAY_REF(FCBLiquidGlassItem,Z_Param_Out_InItems);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItems(Z_Param_Out_InItems);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetItems ***************************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetItemSize **********************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetItemSize_Parms
	{
		FVector2D InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the fixed cell size used by each segment item. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the fixed cell size used by each segment item." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetItemSize constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItemSize constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItemSize Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSegmentedControl_eventSetItemSize_Parms, InValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::PropPointers) < 2048);
// ********** End Function SetItemSize Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetItemSize", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::CBLiquidGlassSegmentedControl_eventSetItemSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::CBLiquidGlassSegmentedControl_eventSetItemSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetItemSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItemSize(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetItemSize ************************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetOrientation *******************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetOrientation_Parms
	{
		ECBLiquidGlassOrientation InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets horizontal or vertical layout for the segment list. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets horizontal or vertical layout for the segment list." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetOrientation constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetOrientation constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetOrientation Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSegmentedControl_eventSetOrientation_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation, METADATA_PARAMS(0, nullptr) }; // 1928438873
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::PropPointers) < 2048);
// ********** End Function SetOrientation Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetOrientation", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::CBLiquidGlassSegmentedControl_eventSetOrientation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::CBLiquidGlassSegmentedControl_eventSetOrientation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetOrientation)
{
	P_GET_ENUM(ECBLiquidGlassOrientation,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOrientation(ECBLiquidGlassOrientation(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetOrientation *********************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetPadding ***********************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetPadding_Parms
	{
		FMargin InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets padding between the outer glass capsule and item cells. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets padding between the outer glass capsule and item cells." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetPadding constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPadding constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPadding Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSegmentedControl_eventSetPadding_Parms, InValue), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::PropPointers) < 2048);
// ********** End Function SetPadding Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetPadding", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::CBLiquidGlassSegmentedControl_eventSetPadding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::CBLiquidGlassSegmentedControl_eventSetPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetPadding)
{
	P_GET_STRUCT(FMargin,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPadding(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetPadding *************************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetSelectedIndex *****************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetSelectedIndex_Parms
	{
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Selects an item by index and animates the liquid highlight to it. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Selects an item by index and animates the liquid highlight to it." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSelectedIndex constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSelectedIndex constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSelectedIndex Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSegmentedControl_eventSetSelectedIndex_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::PropPointers) < 2048);
// ********** End Function SetSelectedIndex Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetSelectedIndex", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::CBLiquidGlassSegmentedControl_eventSetSelectedIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::CBLiquidGlassSegmentedControl_eventSetSelectedIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetSelectedIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSelectedIndex(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetSelectedIndex *******************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetShowIcons *********************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetShowIcons_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides item icons without affecting labels. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides item icons without affecting labels." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowIcons constinit property declarations **************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowIcons constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowIcons Property Definitions *************************************
void Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassSegmentedControl_eventSetShowIcons_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassSegmentedControl_eventSetShowIcons_Parms), &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::PropPointers) < 2048);
// ********** End Function SetShowIcons Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetShowIcons", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::CBLiquidGlassSegmentedControl_eventSetShowIcons_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::CBLiquidGlassSegmentedControl_eventSetShowIcons_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetShowIcons)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowIcons(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetShowIcons ***********************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetShowLabels ********************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetShowLabels_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides item labels without affecting icons. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides item labels without affecting icons." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowLabels constinit property declarations *************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowLabels constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowLabels Property Definitions ************************************
void Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassSegmentedControl_eventSetShowLabels_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassSegmentedControl_eventSetShowLabels_Parms), &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::PropPointers) < 2048);
// ********** End Function SetShowLabels Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetShowLabels", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::CBLiquidGlassSegmentedControl_eventSetShowLabels_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::CBLiquidGlassSegmentedControl_eventSetShowLabels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetShowLabels)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowLabels(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetShowLabels **********************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetSpringSettings ****************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetSpringSettings_Parms
	{
		FCBLiquidGlassSpringSettings InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the spring used by the sliding selection highlight. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the spring used by the sliding selection highlight." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSpringSettings constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSpringSettings constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSpringSettings Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSegmentedControl_eventSetSpringSettings_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, METADATA_PARAMS(0, nullptr) }; // 4164173022
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::PropPointers) < 2048);
// ********** End Function SetSpringSettings Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetSpringSettings", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::CBLiquidGlassSegmentedControl_eventSetSpringSettings_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::CBLiquidGlassSegmentedControl_eventSetSpringSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetSpringSettings)
{
	P_GET_STRUCT(FCBLiquidGlassSpringSettings,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSpringSettings(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetSpringSettings ******************

// ********** Begin Class UCBLiquidGlassSegmentedControl Function SetStyle *************************
struct Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics
{
	struct CBLiquidGlassSegmentedControl_eventSetStyle_Parms
	{
		FCBLiquidGlassControlStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the glass preset, quality, size and colour recipe. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the glass preset, quality, size and colour recipe." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStyle constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStyle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStyle Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSegmentedControl_eventSetStyle_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(0, nullptr) }; // 3956690548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::PropPointers) < 2048);
// ********** End Function SetStyle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSegmentedControl, nullptr, "SetStyle", 	Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::CBLiquidGlassSegmentedControl_eventSetStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::CBLiquidGlassSegmentedControl_eventSetStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSegmentedControl::execSetStyle)
{
	P_GET_STRUCT(FCBLiquidGlassControlStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStyle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSegmentedControl Function SetStyle ***************************

// ********** Begin Class UCBLiquidGlassSegmentedControl *******************************************
void UCBLiquidGlassSegmentedControl::GetItems_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	TArray<FCBLiquidGlassItem>& Result = *(TArray<FCBLiquidGlassItem>*)OutValue;
	Result = (TArray<FCBLiquidGlassItem>)Obj->GetItems();
}
void UCBLiquidGlassSegmentedControl::SetItems_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	TArray<FCBLiquidGlassItem>& Value = *(TArray<FCBLiquidGlassItem>*)InValue;
	Obj->SetItems(Value);
}
void UCBLiquidGlassSegmentedControl::GetSelectedIndex_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	int32& Result = *(int32*)OutValue;
	Result = (int32)Obj->GetSelectedIndex();
}
void UCBLiquidGlassSegmentedControl::SetSelectedIndex_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	int32& Value = *(int32*)InValue;
	Obj->SetSelectedIndex(Value);
}
void UCBLiquidGlassSegmentedControl::GetOrientation_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	ECBLiquidGlassOrientation& Result = *(ECBLiquidGlassOrientation*)OutValue;
	Result = (ECBLiquidGlassOrientation)Obj->GetOrientation();
}
void UCBLiquidGlassSegmentedControl::SetOrientation_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	ECBLiquidGlassOrientation& Value = *(ECBLiquidGlassOrientation*)InValue;
	Obj->SetOrientation(Value);
}
void UCBLiquidGlassSegmentedControl::GetbShowIcons_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowIcons();
}
void UCBLiquidGlassSegmentedControl::SetbShowIcons_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowIcons(Value);
}
void UCBLiquidGlassSegmentedControl::GetbShowLabels_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowLabels();
}
void UCBLiquidGlassSegmentedControl::SetbShowLabels_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowLabels(Value);
}
void UCBLiquidGlassSegmentedControl::GetItemSize_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	FVector2D& Result = *(FVector2D*)OutValue;
	Result = (FVector2D)Obj->GetItemSize();
}
void UCBLiquidGlassSegmentedControl::SetItemSize_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	FVector2D& Value = *(FVector2D*)InValue;
	Obj->SetItemSize(Value);
}
void UCBLiquidGlassSegmentedControl::GetPadding_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	FMargin& Result = *(FMargin*)OutValue;
	Result = (FMargin)Obj->GetPadding();
}
void UCBLiquidGlassSegmentedControl::SetPadding_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	FMargin& Value = *(FMargin*)InValue;
	Obj->SetPadding(Value);
}
void UCBLiquidGlassSegmentedControl::GetStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	FCBLiquidGlassControlStyle& Result = *(FCBLiquidGlassControlStyle*)OutValue;
	Result = (FCBLiquidGlassControlStyle)Obj->GetStyle();
}
void UCBLiquidGlassSegmentedControl::SetStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	FCBLiquidGlassControlStyle& Value = *(FCBLiquidGlassControlStyle*)InValue;
	Obj->SetStyle(Value);
}
void UCBLiquidGlassSegmentedControl::GetSpringSettings_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSegmentedControl* Obj = (const UCBLiquidGlassSegmentedControl*)Object;
	FCBLiquidGlassSpringSettings& Result = *(FCBLiquidGlassSpringSettings*)OutValue;
	Result = (FCBLiquidGlassSpringSettings)Obj->GetSpringSettings();
}
void UCBLiquidGlassSegmentedControl::SetSpringSettings_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSegmentedControl* Obj = (UCBLiquidGlassSegmentedControl*)Object;
	FCBLiquidGlassSpringSettings& Value = *(FCBLiquidGlassSpringSettings*)InValue;
	Obj->SetSpringSettings(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassSegmentedControl;
UClass* UCBLiquidGlassSegmentedControl::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassSegmentedControl;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassSegmentedControl.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassSegmentedControl"),
			Z_Registration_Info_UClass_UCBLiquidGlassSegmentedControl.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassSegmentedControl,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassSegmentedControl.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassSegmentedControl_NoRegister()
{
	return UCBLiquidGlassSegmentedControl::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG multi-option selector with a sliding liquid highlight. */" },
#endif
		{ "DisplayName", "Liquid Glass Segmented Control" },
		{ "IncludePath", "CBLiquidGlassControls.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG multi-option selector with a sliding liquid highlight." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedIndex_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowIcons_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether item icons are visible. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether item icons are visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowLabels_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether item labels are visible. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether item labels are visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemSize_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Size of each segment cell before outer padding is applied. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Size of each segment cell before outer padding is applied." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Padding between the outer glass capsule and the segment cells. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Padding between the outer glass capsule and the segment cells." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringSettings_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSelectionChanged_MetaData[] = {
		{ "Category", "Liquid Glass Segmented Control|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassSegmentedControl constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Items;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Orientation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Orientation;
	static void NewProp_bShowIcons_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowIcons;
	static void NewProp_bShowLabels_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowLabels;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpringSettings;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSelectionChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassSegmentedControl constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetItems"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetItems },
		{ .NameUTF8 = UTF8TEXT("SetItemSize"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetItemSize },
		{ .NameUTF8 = UTF8TEXT("SetOrientation"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetOrientation },
		{ .NameUTF8 = UTF8TEXT("SetPadding"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetPadding },
		{ .NameUTF8 = UTF8TEXT("SetSelectedIndex"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetSelectedIndex },
		{ .NameUTF8 = UTF8TEXT("SetShowIcons"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetShowIcons },
		{ .NameUTF8 = UTF8TEXT("SetShowLabels"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetShowLabels },
		{ .NameUTF8 = UTF8TEXT("SetSpringSettings"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetSpringSettings },
		{ .NameUTF8 = UTF8TEXT("SetStyle"), .Pointer = &UCBLiquidGlassSegmentedControl::execSetStyle },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItems, "SetItems" }, // 3808695932
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetItemSize, "SetItemSize" }, // 1242300396
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetOrientation, "SetOrientation" }, // 720368502
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetPadding, "SetPadding" }, // 2149410009
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSelectedIndex, "SetSelectedIndex" }, // 294552382
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowIcons, "SetShowIcons" }, // 2285314876
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetShowLabels, "SetShowLabels" }, // 3692565991
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetSpringSettings, "SetSpringSettings" }, // 1280363650
		{ &Z_Construct_UFunction_UCBLiquidGlassSegmentedControl_SetStyle, "SetStyle" }, // 3143857235
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassSegmentedControl>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics

// ********** Begin Class UCBLiquidGlassSegmentedControl Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Items_Inner = { "Items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetItems_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetItems_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSegmentedControl, Items), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 688407273
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_SelectedIndex = { "SelectedIndex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetSelectedIndex_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetSelectedIndex_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSegmentedControl, SelectedIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedIndex_MetaData), NewProp_SelectedIndex_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Orientation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetOrientation_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetOrientation_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSegmentedControl, Orientation), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orientation_MetaData), NewProp_Orientation_MetaData) }; // 1928438873
void Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_bShowIcons_SetBit(void* Obj)
{
	((UCBLiquidGlassSegmentedControl*)Obj)->bShowIcons = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_bShowIcons = { "bShowIcons", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetbShowIcons_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetbShowIcons_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassSegmentedControl), &Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_bShowIcons_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowIcons_MetaData), NewProp_bShowIcons_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_bShowLabels_SetBit(void* Obj)
{
	((UCBLiquidGlassSegmentedControl*)Obj)->bShowLabels = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_bShowLabels = { "bShowLabels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetbShowLabels_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetbShowLabels_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassSegmentedControl), &Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_bShowLabels_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowLabels_MetaData), NewProp_bShowLabels_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_ItemSize = { "ItemSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetItemSize_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetItemSize_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSegmentedControl, ItemSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemSize_MetaData), NewProp_ItemSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetPadding_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetPadding_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSegmentedControl, Padding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) }; // 4099648758
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetStyle_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSegmentedControl, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_SpringSettings = { "SpringSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSegmentedControl::SetSpringSettings_WrapperImpl, &UCBLiquidGlassSegmentedControl::GetSpringSettings_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSegmentedControl, SpringSettings), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringSettings_MetaData), NewProp_SpringSettings_MetaData) }; // 4164173022
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_OnSelectionChanged = { "OnSelectionChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassSegmentedControl, OnSelectionChanged), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSelectionChanged_MetaData), NewProp_OnSelectionChanged_MetaData) }; // 1290240071
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Items_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Items,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_SelectedIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Orientation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Orientation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_bShowIcons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_bShowLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_ItemSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_SpringSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::NewProp_OnSelectionChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassSegmentedControl Property Definitions ************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::ClassParams = {
	&UCBLiquidGlassSegmentedControl::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassSegmentedControl::StaticRegisterNativesUCBLiquidGlassSegmentedControl()
{
	UClass* Class = UCBLiquidGlassSegmentedControl::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassSegmentedControl()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassSegmentedControl.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassSegmentedControl.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassSegmentedControl.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassSegmentedControl);
UCBLiquidGlassSegmentedControl::~UCBLiquidGlassSegmentedControl() {}
// ********** End Class UCBLiquidGlassSegmentedControl *********************************************

// ********** Begin Class UCBLiquidGlassTabBar Function SetItems ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics
{
	struct CBLiquidGlassTabBar_eventSetItems_Parms
	{
		TArray<FCBLiquidGlassItem> InItems;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Tab Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replaces all tabs and clamps the current selected tab to the new range. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replaces all tabs and clamps the current selected tab to the new range." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItems_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetItems constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InItems;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItems constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItems Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::NewProp_InItems_Inner = { "InItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::NewProp_InItems = { "InItems", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassTabBar_eventSetItems_Parms, InItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItems_MetaData), NewProp_InItems_MetaData) }; // 688407273
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::NewProp_InItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::NewProp_InItems,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::PropPointers) < 2048);
// ********** End Function SetItems Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassTabBar, nullptr, "SetItems", 	Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::CBLiquidGlassTabBar_eventSetItems_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::CBLiquidGlassTabBar_eventSetItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassTabBar::execSetItems)
{
	P_GET_TARRAY_REF(FCBLiquidGlassItem,Z_Param_Out_InItems);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItems(Z_Param_Out_InItems);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassTabBar Function SetItems *************************************

// ********** Begin Class UCBLiquidGlassTabBar Function SetItemSize ********************************
struct Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics
{
	struct CBLiquidGlassTabBar_eventSetItemSize_Parms
	{
		FVector2D InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Tab Bar|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the fixed cell size used by each tab. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the fixed cell size used by each tab." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetItemSize constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItemSize constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItemSize Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassTabBar_eventSetItemSize_Parms, InValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::PropPointers) < 2048);
// ********** End Function SetItemSize Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassTabBar, nullptr, "SetItemSize", 	Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::CBLiquidGlassTabBar_eventSetItemSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::CBLiquidGlassTabBar_eventSetItemSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassTabBar::execSetItemSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItemSize(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassTabBar Function SetItemSize **********************************

// ********** Begin Class UCBLiquidGlassTabBar Function SetPadding *********************************
struct Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics
{
	struct CBLiquidGlassTabBar_eventSetPadding_Parms
	{
		FMargin InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Tab Bar|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets padding between the tab cells and the outer glass capsule. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets padding between the tab cells and the outer glass capsule." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetPadding constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPadding constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPadding Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassTabBar_eventSetPadding_Parms, InValue), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::PropPointers) < 2048);
// ********** End Function SetPadding Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassTabBar, nullptr, "SetPadding", 	Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::CBLiquidGlassTabBar_eventSetPadding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::CBLiquidGlassTabBar_eventSetPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassTabBar::execSetPadding)
{
	P_GET_STRUCT(FMargin,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPadding(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassTabBar Function SetPadding ***********************************

// ********** Begin Class UCBLiquidGlassTabBar Function SetSelectedIndex ***************************
struct Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics
{
	struct CBLiquidGlassTabBar_eventSetSelectedIndex_Parms
	{
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Tab Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Selects a tab by index and moves the liquid capsule to it. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Selects a tab by index and moves the liquid capsule to it." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSelectedIndex constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSelectedIndex constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSelectedIndex Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassTabBar_eventSetSelectedIndex_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::PropPointers) < 2048);
// ********** End Function SetSelectedIndex Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassTabBar, nullptr, "SetSelectedIndex", 	Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::CBLiquidGlassTabBar_eventSetSelectedIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::CBLiquidGlassTabBar_eventSetSelectedIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassTabBar::execSetSelectedIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSelectedIndex(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassTabBar Function SetSelectedIndex *****************************

// ********** Begin Class UCBLiquidGlassTabBar Function SetShowIcons *******************************
struct Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics
{
	struct CBLiquidGlassTabBar_eventSetShowIcons_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Tab Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides tab icons. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides tab icons." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowIcons constinit property declarations **************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowIcons constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowIcons Property Definitions *************************************
void Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassTabBar_eventSetShowIcons_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassTabBar_eventSetShowIcons_Parms), &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::PropPointers) < 2048);
// ********** End Function SetShowIcons Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassTabBar, nullptr, "SetShowIcons", 	Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::CBLiquidGlassTabBar_eventSetShowIcons_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::CBLiquidGlassTabBar_eventSetShowIcons_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassTabBar::execSetShowIcons)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowIcons(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassTabBar Function SetShowIcons *********************************

// ********** Begin Class UCBLiquidGlassTabBar Function SetShowLabels ******************************
struct Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics
{
	struct CBLiquidGlassTabBar_eventSetShowLabels_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Tab Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides tab labels. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides tab labels." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowLabels constinit property declarations *************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowLabels constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowLabels Property Definitions ************************************
void Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassTabBar_eventSetShowLabels_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassTabBar_eventSetShowLabels_Parms), &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::PropPointers) < 2048);
// ********** End Function SetShowLabels Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassTabBar, nullptr, "SetShowLabels", 	Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::CBLiquidGlassTabBar_eventSetShowLabels_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::CBLiquidGlassTabBar_eventSetShowLabels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassTabBar::execSetShowLabels)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowLabels(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassTabBar Function SetShowLabels ********************************

// ********** Begin Class UCBLiquidGlassTabBar Function SetSpringSettings **************************
struct Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics
{
	struct CBLiquidGlassTabBar_eventSetSpringSettings_Parms
	{
		FCBLiquidGlassSpringSettings InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Tab Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the spring used by the selected-tab capsule. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the spring used by the selected-tab capsule." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSpringSettings constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSpringSettings constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSpringSettings Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassTabBar_eventSetSpringSettings_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, METADATA_PARAMS(0, nullptr) }; // 4164173022
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::PropPointers) < 2048);
// ********** End Function SetSpringSettings Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassTabBar, nullptr, "SetSpringSettings", 	Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::CBLiquidGlassTabBar_eventSetSpringSettings_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::CBLiquidGlassTabBar_eventSetSpringSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassTabBar::execSetSpringSettings)
{
	P_GET_STRUCT(FCBLiquidGlassSpringSettings,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSpringSettings(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassTabBar Function SetSpringSettings ****************************

// ********** Begin Class UCBLiquidGlassTabBar Function SetStyle ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics
{
	struct CBLiquidGlassTabBar_eventSetStyle_Parms
	{
		FCBLiquidGlassControlStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Tab Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the glass preset, quality, size and colour recipe. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the glass preset, quality, size and colour recipe." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStyle constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStyle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStyle Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassTabBar_eventSetStyle_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(0, nullptr) }; // 3956690548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::PropPointers) < 2048);
// ********** End Function SetStyle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassTabBar, nullptr, "SetStyle", 	Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::CBLiquidGlassTabBar_eventSetStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::CBLiquidGlassTabBar_eventSetStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassTabBar::execSetStyle)
{
	P_GET_STRUCT(FCBLiquidGlassControlStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStyle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassTabBar Function SetStyle *************************************

// ********** Begin Class UCBLiquidGlassTabBar *****************************************************
void UCBLiquidGlassTabBar::GetItems_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassTabBar* Obj = (const UCBLiquidGlassTabBar*)Object;
	TArray<FCBLiquidGlassItem>& Result = *(TArray<FCBLiquidGlassItem>*)OutValue;
	Result = (TArray<FCBLiquidGlassItem>)Obj->GetItems();
}
void UCBLiquidGlassTabBar::SetItems_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassTabBar* Obj = (UCBLiquidGlassTabBar*)Object;
	TArray<FCBLiquidGlassItem>& Value = *(TArray<FCBLiquidGlassItem>*)InValue;
	Obj->SetItems(Value);
}
void UCBLiquidGlassTabBar::GetSelectedIndex_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassTabBar* Obj = (const UCBLiquidGlassTabBar*)Object;
	int32& Result = *(int32*)OutValue;
	Result = (int32)Obj->GetSelectedIndex();
}
void UCBLiquidGlassTabBar::SetSelectedIndex_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassTabBar* Obj = (UCBLiquidGlassTabBar*)Object;
	int32& Value = *(int32*)InValue;
	Obj->SetSelectedIndex(Value);
}
void UCBLiquidGlassTabBar::GetbShowLabels_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassTabBar* Obj = (const UCBLiquidGlassTabBar*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowLabels();
}
void UCBLiquidGlassTabBar::SetbShowLabels_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassTabBar* Obj = (UCBLiquidGlassTabBar*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowLabels(Value);
}
void UCBLiquidGlassTabBar::GetbShowIcons_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassTabBar* Obj = (const UCBLiquidGlassTabBar*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowIcons();
}
void UCBLiquidGlassTabBar::SetbShowIcons_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassTabBar* Obj = (UCBLiquidGlassTabBar*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowIcons(Value);
}
void UCBLiquidGlassTabBar::GetItemSize_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassTabBar* Obj = (const UCBLiquidGlassTabBar*)Object;
	FVector2D& Result = *(FVector2D*)OutValue;
	Result = (FVector2D)Obj->GetItemSize();
}
void UCBLiquidGlassTabBar::SetItemSize_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassTabBar* Obj = (UCBLiquidGlassTabBar*)Object;
	FVector2D& Value = *(FVector2D*)InValue;
	Obj->SetItemSize(Value);
}
void UCBLiquidGlassTabBar::GetPadding_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassTabBar* Obj = (const UCBLiquidGlassTabBar*)Object;
	FMargin& Result = *(FMargin*)OutValue;
	Result = (FMargin)Obj->GetPadding();
}
void UCBLiquidGlassTabBar::SetPadding_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassTabBar* Obj = (UCBLiquidGlassTabBar*)Object;
	FMargin& Value = *(FMargin*)InValue;
	Obj->SetPadding(Value);
}
void UCBLiquidGlassTabBar::GetStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassTabBar* Obj = (const UCBLiquidGlassTabBar*)Object;
	FCBLiquidGlassControlStyle& Result = *(FCBLiquidGlassControlStyle*)OutValue;
	Result = (FCBLiquidGlassControlStyle)Obj->GetStyle();
}
void UCBLiquidGlassTabBar::SetStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassTabBar* Obj = (UCBLiquidGlassTabBar*)Object;
	FCBLiquidGlassControlStyle& Value = *(FCBLiquidGlassControlStyle*)InValue;
	Obj->SetStyle(Value);
}
void UCBLiquidGlassTabBar::GetSpringSettings_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassTabBar* Obj = (const UCBLiquidGlassTabBar*)Object;
	FCBLiquidGlassSpringSettings& Result = *(FCBLiquidGlassSpringSettings*)OutValue;
	Result = (FCBLiquidGlassSpringSettings)Obj->GetSpringSettings();
}
void UCBLiquidGlassTabBar::SetSpringSettings_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassTabBar* Obj = (UCBLiquidGlassTabBar*)Object;
	FCBLiquidGlassSpringSettings& Value = *(FCBLiquidGlassSpringSettings*)InValue;
	Obj->SetSpringSettings(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassTabBar;
UClass* UCBLiquidGlassTabBar::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassTabBar;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassTabBar.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassTabBar"),
			Z_Registration_Info_UClass_UCBLiquidGlassTabBar.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassTabBar,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassTabBar.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassTabBar_NoRegister()
{
	return UCBLiquidGlassTabBar::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassTabBar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG icon+label tab bar with liquid selected capsule. */" },
#endif
		{ "DisplayName", "Liquid Glass Tab Bar" },
		{ "IncludePath", "CBLiquidGlassControls.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG icon+label tab bar with liquid selected capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedIndex_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowLabels_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowIcons_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemSize_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Size of each tab cell. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Size of each tab cell." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Padding inside the tab bar glass capsule. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Padding inside the tab bar glass capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringSettings_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTabChanged_MetaData[] = {
		{ "Category", "Liquid Glass Tab Bar|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassTabBar constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Items;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedIndex;
	static void NewProp_bShowLabels_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowLabels;
	static void NewProp_bShowIcons_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowIcons;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpringSettings;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTabChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassTabBar constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetItems"), .Pointer = &UCBLiquidGlassTabBar::execSetItems },
		{ .NameUTF8 = UTF8TEXT("SetItemSize"), .Pointer = &UCBLiquidGlassTabBar::execSetItemSize },
		{ .NameUTF8 = UTF8TEXT("SetPadding"), .Pointer = &UCBLiquidGlassTabBar::execSetPadding },
		{ .NameUTF8 = UTF8TEXT("SetSelectedIndex"), .Pointer = &UCBLiquidGlassTabBar::execSetSelectedIndex },
		{ .NameUTF8 = UTF8TEXT("SetShowIcons"), .Pointer = &UCBLiquidGlassTabBar::execSetShowIcons },
		{ .NameUTF8 = UTF8TEXT("SetShowLabels"), .Pointer = &UCBLiquidGlassTabBar::execSetShowLabels },
		{ .NameUTF8 = UTF8TEXT("SetSpringSettings"), .Pointer = &UCBLiquidGlassTabBar::execSetSpringSettings },
		{ .NameUTF8 = UTF8TEXT("SetStyle"), .Pointer = &UCBLiquidGlassTabBar::execSetStyle },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItems, "SetItems" }, // 3665870248
		{ &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetItemSize, "SetItemSize" }, // 2505382674
		{ &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetPadding, "SetPadding" }, // 3806927978
		{ &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSelectedIndex, "SetSelectedIndex" }, // 3401315756
		{ &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowIcons, "SetShowIcons" }, // 556198378
		{ &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetShowLabels, "SetShowLabels" }, // 3823754649
		{ &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetSpringSettings, "SetSpringSettings" }, // 877831212
		{ &Z_Construct_UFunction_UCBLiquidGlassTabBar_SetStyle, "SetStyle" }, // 146934179
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassTabBar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassTabBar_Statics

// ********** Begin Class UCBLiquidGlassTabBar Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_Items_Inner = { "Items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassTabBar::SetItems_WrapperImpl, &UCBLiquidGlassTabBar::GetItems_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassTabBar, Items), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 688407273
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_SelectedIndex = { "SelectedIndex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassTabBar::SetSelectedIndex_WrapperImpl, &UCBLiquidGlassTabBar::GetSelectedIndex_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassTabBar, SelectedIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedIndex_MetaData), NewProp_SelectedIndex_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_bShowLabels_SetBit(void* Obj)
{
	((UCBLiquidGlassTabBar*)Obj)->bShowLabels = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_bShowLabels = { "bShowLabels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassTabBar::SetbShowLabels_WrapperImpl, &UCBLiquidGlassTabBar::GetbShowLabels_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassTabBar), &Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_bShowLabels_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowLabels_MetaData), NewProp_bShowLabels_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_bShowIcons_SetBit(void* Obj)
{
	((UCBLiquidGlassTabBar*)Obj)->bShowIcons = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_bShowIcons = { "bShowIcons", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassTabBar::SetbShowIcons_WrapperImpl, &UCBLiquidGlassTabBar::GetbShowIcons_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassTabBar), &Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_bShowIcons_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowIcons_MetaData), NewProp_bShowIcons_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_ItemSize = { "ItemSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassTabBar::SetItemSize_WrapperImpl, &UCBLiquidGlassTabBar::GetItemSize_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassTabBar, ItemSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemSize_MetaData), NewProp_ItemSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassTabBar::SetPadding_WrapperImpl, &UCBLiquidGlassTabBar::GetPadding_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassTabBar, Padding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) }; // 4099648758
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassTabBar::SetStyle_WrapperImpl, &UCBLiquidGlassTabBar::GetStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassTabBar, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_SpringSettings = { "SpringSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassTabBar::SetSpringSettings_WrapperImpl, &UCBLiquidGlassTabBar::GetSpringSettings_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassTabBar, SpringSettings), Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringSettings_MetaData), NewProp_SpringSettings_MetaData) }; // 4164173022
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_OnTabChanged = { "OnTabChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassTabBar, OnTabChanged), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassIndexChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTabChanged_MetaData), NewProp_OnTabChanged_MetaData) }; // 1290240071
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_Items_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_Items,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_SelectedIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_bShowLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_bShowIcons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_ItemSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_SpringSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::NewProp_OnTabChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassTabBar Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::ClassParams = {
	&UCBLiquidGlassTabBar::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassTabBar::StaticRegisterNativesUCBLiquidGlassTabBar()
{
	UClass* Class = UCBLiquidGlassTabBar::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassTabBar()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassTabBar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassTabBar.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassTabBar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassTabBar.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassTabBar);
UCBLiquidGlassTabBar::~UCBLiquidGlassTabBar() {}
// ********** End Class UCBLiquidGlassTabBar *******************************************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetItems **********************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics
{
	struct CBLiquidGlassToolbar_eventSetItems_Parms
	{
		TArray<FCBLiquidGlassItem> InItems;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replaces toolbar actions. Disabled and separator item states are respected. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replaces toolbar actions. Disabled and separator item states are respected." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItems_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetItems constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InItems;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItems constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItems Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::NewProp_InItems_Inner = { "InItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::NewProp_InItems = { "InItems", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToolbar_eventSetItems_Parms, InItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItems_MetaData), NewProp_InItems_MetaData) }; // 688407273
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::NewProp_InItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::NewProp_InItems,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::PropPointers) < 2048);
// ********** End Function SetItems Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetItems", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::CBLiquidGlassToolbar_eventSetItems_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::CBLiquidGlassToolbar_eventSetItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetItems)
{
	P_GET_TARRAY_REF(FCBLiquidGlassItem,Z_Param_Out_InItems);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItems(Z_Param_Out_InItems);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetItems ************************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetItemSize *******************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics
{
	struct CBLiquidGlassToolbar_eventSetItemSize_Parms
	{
		FVector2D InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the fixed visual cell size for toolbar items. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the fixed visual cell size for toolbar items." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetItemSize constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItemSize constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItemSize Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToolbar_eventSetItemSize_Parms, InValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::PropPointers) < 2048);
// ********** End Function SetItemSize Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetItemSize", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::CBLiquidGlassToolbar_eventSetItemSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::CBLiquidGlassToolbar_eventSetItemSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetItemSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItemSize(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetItemSize *********************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetOrientation ****************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics
{
	struct CBLiquidGlassToolbar_eventSetOrientation_Parms
	{
		ECBLiquidGlassOrientation InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets horizontal or vertical toolbar layout. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets horizontal or vertical toolbar layout." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetOrientation constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetOrientation constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetOrientation Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToolbar_eventSetOrientation_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation, METADATA_PARAMS(0, nullptr) }; // 1928438873
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::PropPointers) < 2048);
// ********** End Function SetOrientation Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetOrientation", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::CBLiquidGlassToolbar_eventSetOrientation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::CBLiquidGlassToolbar_eventSetOrientation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetOrientation)
{
	P_GET_ENUM(ECBLiquidGlassOrientation,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOrientation(ECBLiquidGlassOrientation(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetOrientation ******************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetPadding ********************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics
{
	struct CBLiquidGlassToolbar_eventSetPadding_Parms
	{
		FMargin InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets padding inside the toolbar glass capsule. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets padding inside the toolbar glass capsule." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetPadding constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPadding constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPadding Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToolbar_eventSetPadding_Parms, InValue), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::PropPointers) < 2048);
// ********** End Function SetPadding Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetPadding", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::CBLiquidGlassToolbar_eventSetPadding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::CBLiquidGlassToolbar_eventSetPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetPadding)
{
	P_GET_STRUCT(FMargin,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPadding(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetPadding **********************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetSelectedIndex **************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics
{
	struct CBLiquidGlassToolbar_eventSetSelectedIndex_Parms
	{
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Selects the active toolbar item when toggle mode is enabled. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Selects the active toolbar item when toggle mode is enabled." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSelectedIndex constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSelectedIndex constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSelectedIndex Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToolbar_eventSetSelectedIndex_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::PropPointers) < 2048);
// ********** End Function SetSelectedIndex Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetSelectedIndex", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::CBLiquidGlassToolbar_eventSetSelectedIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::CBLiquidGlassToolbar_eventSetSelectedIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetSelectedIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSelectedIndex(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetSelectedIndex ****************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetShowIcons ******************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics
{
	struct CBLiquidGlassToolbar_eventSetShowIcons_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides toolbar icons. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides toolbar icons." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowIcons constinit property declarations **************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowIcons constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowIcons Property Definitions *************************************
void Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassToolbar_eventSetShowIcons_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassToolbar_eventSetShowIcons_Parms), &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::PropPointers) < 2048);
// ********** End Function SetShowIcons Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetShowIcons", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::CBLiquidGlassToolbar_eventSetShowIcons_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::CBLiquidGlassToolbar_eventSetShowIcons_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetShowIcons)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowIcons(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetShowIcons ********************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetShowLabels *****************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics
{
	struct CBLiquidGlassToolbar_eventSetShowLabels_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides toolbar labels. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides toolbar labels." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowLabels constinit property declarations *************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowLabels constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowLabels Property Definitions ************************************
void Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassToolbar_eventSetShowLabels_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassToolbar_eventSetShowLabels_Parms), &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::PropPointers) < 2048);
// ********** End Function SetShowLabels Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetShowLabels", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::CBLiquidGlassToolbar_eventSetShowLabels_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::CBLiquidGlassToolbar_eventSetShowLabels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetShowLabels)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowLabels(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetShowLabels *******************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetStyle **********************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics
{
	struct CBLiquidGlassToolbar_eventSetStyle_Parms
	{
		FCBLiquidGlassControlStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the glass preset, quality, size and colour recipe. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the glass preset, quality, size and colour recipe." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStyle constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStyle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStyle Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassToolbar_eventSetStyle_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(0, nullptr) }; // 3956690548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::PropPointers) < 2048);
// ********** End Function SetStyle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetStyle", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::CBLiquidGlassToolbar_eventSetStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::CBLiquidGlassToolbar_eventSetStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetStyle)
{
	P_GET_STRUCT(FCBLiquidGlassControlStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStyle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetStyle ************************************

// ********** Begin Class UCBLiquidGlassToolbar Function SetToggleMode *****************************
struct Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics
{
	struct CBLiquidGlassToolbar_eventSetToggleMode_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enables a persistent selected item with a moving glass highlight. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables a persistent selected item with a moving glass highlight." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetToggleMode constinit property declarations *************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetToggleMode constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetToggleMode Property Definitions ************************************
void Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassToolbar_eventSetToggleMode_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassToolbar_eventSetToggleMode_Parms), &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::PropPointers) < 2048);
// ********** End Function SetToggleMode Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassToolbar, nullptr, "SetToggleMode", 	Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::CBLiquidGlassToolbar_eventSetToggleMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::CBLiquidGlassToolbar_eventSetToggleMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassToolbar::execSetToggleMode)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetToggleMode(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassToolbar Function SetToggleMode *******************************

// ********** Begin Class UCBLiquidGlassToolbar ****************************************************
void UCBLiquidGlassToolbar::GetItems_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	TArray<FCBLiquidGlassItem>& Result = *(TArray<FCBLiquidGlassItem>*)OutValue;
	Result = (TArray<FCBLiquidGlassItem>)Obj->GetItems();
}
void UCBLiquidGlassToolbar::SetItems_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	TArray<FCBLiquidGlassItem>& Value = *(TArray<FCBLiquidGlassItem>*)InValue;
	Obj->SetItems(Value);
}
void UCBLiquidGlassToolbar::GetOrientation_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	ECBLiquidGlassOrientation& Result = *(ECBLiquidGlassOrientation*)OutValue;
	Result = (ECBLiquidGlassOrientation)Obj->GetOrientation();
}
void UCBLiquidGlassToolbar::SetOrientation_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	ECBLiquidGlassOrientation& Value = *(ECBLiquidGlassOrientation*)InValue;
	Obj->SetOrientation(Value);
}
void UCBLiquidGlassToolbar::GetbToggleMode_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetToggleMode();
}
void UCBLiquidGlassToolbar::SetbToggleMode_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetToggleMode(Value);
}
void UCBLiquidGlassToolbar::GetSelectedIndex_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	int32& Result = *(int32*)OutValue;
	Result = (int32)Obj->GetSelectedIndex();
}
void UCBLiquidGlassToolbar::SetSelectedIndex_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	int32& Value = *(int32*)InValue;
	Obj->SetSelectedIndex(Value);
}
void UCBLiquidGlassToolbar::GetbShowIcons_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowIcons();
}
void UCBLiquidGlassToolbar::SetbShowIcons_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowIcons(Value);
}
void UCBLiquidGlassToolbar::GetbShowLabels_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowLabels();
}
void UCBLiquidGlassToolbar::SetbShowLabels_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowLabels(Value);
}
void UCBLiquidGlassToolbar::GetItemSize_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	FVector2D& Result = *(FVector2D*)OutValue;
	Result = (FVector2D)Obj->GetItemSize();
}
void UCBLiquidGlassToolbar::SetItemSize_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	FVector2D& Value = *(FVector2D*)InValue;
	Obj->SetItemSize(Value);
}
void UCBLiquidGlassToolbar::GetPadding_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	FMargin& Result = *(FMargin*)OutValue;
	Result = (FMargin)Obj->GetPadding();
}
void UCBLiquidGlassToolbar::SetPadding_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	FMargin& Value = *(FMargin*)InValue;
	Obj->SetPadding(Value);
}
void UCBLiquidGlassToolbar::GetStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassToolbar* Obj = (const UCBLiquidGlassToolbar*)Object;
	FCBLiquidGlassControlStyle& Result = *(FCBLiquidGlassControlStyle*)OutValue;
	Result = (FCBLiquidGlassControlStyle)Obj->GetStyle();
}
void UCBLiquidGlassToolbar::SetStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassToolbar* Obj = (UCBLiquidGlassToolbar*)Object;
	FCBLiquidGlassControlStyle& Value = *(FCBLiquidGlassControlStyle*)InValue;
	Obj->SetStyle(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassToolbar;
UClass* UCBLiquidGlassToolbar::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassToolbar;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassToolbar.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassToolbar"),
			Z_Registration_Info_UClass_UCBLiquidGlassToolbar.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassToolbar,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassToolbar.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassToolbar_NoRegister()
{
	return UCBLiquidGlassToolbar::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassToolbar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG liquid glass toolbar. */" },
#endif
		{ "DisplayName", "Liquid Glass Toolbar" },
		{ "IncludePath", "CBLiquidGlassControls.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG liquid glass toolbar." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bToggleMode_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedIndex_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowIcons_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether toolbar item icons are visible. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether toolbar item icons are visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowLabels_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether toolbar item labels are visible. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether toolbar item labels are visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemSize_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Size of each toolbar item. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Size of each toolbar item." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Padding inside the toolbar glass capsule. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Padding inside the toolbar glass capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnToolClicked_MetaData[] = {
		{ "Category", "Liquid Glass Toolbar|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassToolbar constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Items;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Orientation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Orientation;
	static void NewProp_bToggleMode_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bToggleMode;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedIndex;
	static void NewProp_bShowIcons_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowIcons;
	static void NewProp_bShowLabels_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowLabels;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnToolClicked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassToolbar constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetItems"), .Pointer = &UCBLiquidGlassToolbar::execSetItems },
		{ .NameUTF8 = UTF8TEXT("SetItemSize"), .Pointer = &UCBLiquidGlassToolbar::execSetItemSize },
		{ .NameUTF8 = UTF8TEXT("SetOrientation"), .Pointer = &UCBLiquidGlassToolbar::execSetOrientation },
		{ .NameUTF8 = UTF8TEXT("SetPadding"), .Pointer = &UCBLiquidGlassToolbar::execSetPadding },
		{ .NameUTF8 = UTF8TEXT("SetSelectedIndex"), .Pointer = &UCBLiquidGlassToolbar::execSetSelectedIndex },
		{ .NameUTF8 = UTF8TEXT("SetShowIcons"), .Pointer = &UCBLiquidGlassToolbar::execSetShowIcons },
		{ .NameUTF8 = UTF8TEXT("SetShowLabels"), .Pointer = &UCBLiquidGlassToolbar::execSetShowLabels },
		{ .NameUTF8 = UTF8TEXT("SetStyle"), .Pointer = &UCBLiquidGlassToolbar::execSetStyle },
		{ .NameUTF8 = UTF8TEXT("SetToggleMode"), .Pointer = &UCBLiquidGlassToolbar::execSetToggleMode },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItems, "SetItems" }, // 2725896717
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetItemSize, "SetItemSize" }, // 751914064
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetOrientation, "SetOrientation" }, // 3514588484
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetPadding, "SetPadding" }, // 1464301596
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetSelectedIndex, "SetSelectedIndex" }, // 3852935205
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowIcons, "SetShowIcons" }, // 2193893337
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetShowLabels, "SetShowLabels" }, // 672642235
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetStyle, "SetStyle" }, // 1251404048
		{ &Z_Construct_UFunction_UCBLiquidGlassToolbar_SetToggleMode, "SetToggleMode" }, // 427754735
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassToolbar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassToolbar_Statics

// ********** Begin Class UCBLiquidGlassToolbar Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Items_Inner = { "Items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetItems_WrapperImpl, &UCBLiquidGlassToolbar::GetItems_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToolbar, Items), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 688407273
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Orientation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetOrientation_WrapperImpl, &UCBLiquidGlassToolbar::GetOrientation_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToolbar, Orientation), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassOrientation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orientation_MetaData), NewProp_Orientation_MetaData) }; // 1928438873
void Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bToggleMode_SetBit(void* Obj)
{
	((UCBLiquidGlassToolbar*)Obj)->bToggleMode = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bToggleMode = { "bToggleMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetbToggleMode_WrapperImpl, &UCBLiquidGlassToolbar::GetbToggleMode_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassToolbar), &Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bToggleMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bToggleMode_MetaData), NewProp_bToggleMode_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_SelectedIndex = { "SelectedIndex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetSelectedIndex_WrapperImpl, &UCBLiquidGlassToolbar::GetSelectedIndex_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToolbar, SelectedIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedIndex_MetaData), NewProp_SelectedIndex_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bShowIcons_SetBit(void* Obj)
{
	((UCBLiquidGlassToolbar*)Obj)->bShowIcons = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bShowIcons = { "bShowIcons", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetbShowIcons_WrapperImpl, &UCBLiquidGlassToolbar::GetbShowIcons_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassToolbar), &Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bShowIcons_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowIcons_MetaData), NewProp_bShowIcons_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bShowLabels_SetBit(void* Obj)
{
	((UCBLiquidGlassToolbar*)Obj)->bShowLabels = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bShowLabels = { "bShowLabels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetbShowLabels_WrapperImpl, &UCBLiquidGlassToolbar::GetbShowLabels_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassToolbar), &Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bShowLabels_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowLabels_MetaData), NewProp_bShowLabels_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_ItemSize = { "ItemSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetItemSize_WrapperImpl, &UCBLiquidGlassToolbar::GetItemSize_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToolbar, ItemSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemSize_MetaData), NewProp_ItemSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetPadding_WrapperImpl, &UCBLiquidGlassToolbar::GetPadding_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToolbar, Padding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) }; // 4099648758
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassToolbar::SetStyle_WrapperImpl, &UCBLiquidGlassToolbar::GetStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassToolbar, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_OnToolClicked = { "OnToolClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassToolbar, OnToolClicked), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnToolClicked_MetaData), NewProp_OnToolClicked_MetaData) }; // 426524792
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Items_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Items,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Orientation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Orientation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bToggleMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_SelectedIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bShowIcons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_bShowLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_ItemSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::NewProp_OnToolClicked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassToolbar Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::ClassParams = {
	&UCBLiquidGlassToolbar::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassToolbar::StaticRegisterNativesUCBLiquidGlassToolbar()
{
	UClass* Class = UCBLiquidGlassToolbar::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassToolbar()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassToolbar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassToolbar.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassToolbar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassToolbar.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassToolbar);
UCBLiquidGlassToolbar::~UCBLiquidGlassToolbar() {}
// ********** End Class UCBLiquidGlassToolbar ******************************************************

// ********** Begin Class UCBLiquidGlassMenu Function SetCloseOnClick ******************************
struct Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics
{
	struct CBLiquidGlassMenu_eventSetCloseOnClick_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Collapses the menu after a row click when enabled. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collapses the menu after a row click when enabled." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetCloseOnClick constinit property declarations ***********************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCloseOnClick constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCloseOnClick Property Definitions **********************************
void Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassMenu_eventSetCloseOnClick_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassMenu_eventSetCloseOnClick_Parms), &Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::PropPointers) < 2048);
// ********** End Function SetCloseOnClick Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassMenu, nullptr, "SetCloseOnClick", 	Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::CBLiquidGlassMenu_eventSetCloseOnClick_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::CBLiquidGlassMenu_eventSetCloseOnClick_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassMenu::execSetCloseOnClick)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCloseOnClick(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassMenu Function SetCloseOnClick ********************************

// ********** Begin Class UCBLiquidGlassMenu Function SetItemHeight ********************************
struct Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics
{
	struct CBLiquidGlassMenu_eventSetItemHeight_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the height of each non-separator row. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the height of each non-separator row." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetItemHeight constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItemHeight constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItemHeight Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassMenu_eventSetItemHeight_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::PropPointers) < 2048);
// ********** End Function SetItemHeight Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassMenu, nullptr, "SetItemHeight", 	Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::CBLiquidGlassMenu_eventSetItemHeight_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::CBLiquidGlassMenu_eventSetItemHeight_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassMenu::execSetItemHeight)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItemHeight(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassMenu Function SetItemHeight **********************************

// ********** Begin Class UCBLiquidGlassMenu Function SetItems *************************************
struct Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics
{
	struct CBLiquidGlassMenu_eventSetItems_Parms
	{
		TArray<FCBLiquidGlassItem> InItems;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replaces menu rows, including disabled, danger and separator states. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replaces menu rows, including disabled, danger and separator states." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItems_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetItems constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InItems;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItems constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItems Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::NewProp_InItems_Inner = { "InItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::NewProp_InItems = { "InItems", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassMenu_eventSetItems_Parms, InItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItems_MetaData), NewProp_InItems_MetaData) }; // 688407273
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::NewProp_InItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::NewProp_InItems,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::PropPointers) < 2048);
// ********** End Function SetItems Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassMenu, nullptr, "SetItems", 	Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::CBLiquidGlassMenu_eventSetItems_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::CBLiquidGlassMenu_eventSetItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassMenu::execSetItems)
{
	P_GET_TARRAY_REF(FCBLiquidGlassItem,Z_Param_Out_InItems);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItems(Z_Param_Out_InItems);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassMenu Function SetItems ***************************************

// ********** Begin Class UCBLiquidGlassMenu Function SetShowIcons *********************************
struct Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics
{
	struct CBLiquidGlassMenu_eventSetShowIcons_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides row icons. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides row icons." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowIcons constinit property declarations **************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowIcons constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowIcons Property Definitions *************************************
void Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassMenu_eventSetShowIcons_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassMenu_eventSetShowIcons_Parms), &Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::PropPointers) < 2048);
// ********** End Function SetShowIcons Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassMenu, nullptr, "SetShowIcons", 	Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::CBLiquidGlassMenu_eventSetShowIcons_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::CBLiquidGlassMenu_eventSetShowIcons_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassMenu::execSetShowIcons)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowIcons(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassMenu Function SetShowIcons ***********************************

// ********** Begin Class UCBLiquidGlassMenu Function SetShowLabels ********************************
struct Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics
{
	struct CBLiquidGlassMenu_eventSetShowLabels_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides row labels. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides row labels." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowLabels constinit property declarations *************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowLabels constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowLabels Property Definitions ************************************
void Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassMenu_eventSetShowLabels_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassMenu_eventSetShowLabels_Parms), &Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::PropPointers) < 2048);
// ********** End Function SetShowLabels Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassMenu, nullptr, "SetShowLabels", 	Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::CBLiquidGlassMenu_eventSetShowLabels_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::CBLiquidGlassMenu_eventSetShowLabels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassMenu::execSetShowLabels)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowLabels(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassMenu Function SetShowLabels **********************************

// ********** Begin Class UCBLiquidGlassMenu Function SetStyle *************************************
struct Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics
{
	struct CBLiquidGlassMenu_eventSetStyle_Parms
	{
		FCBLiquidGlassControlStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the glass preset, quality, size and colour recipe. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the glass preset, quality, size and colour recipe." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStyle constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStyle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStyle Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassMenu_eventSetStyle_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(0, nullptr) }; // 3956690548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::PropPointers) < 2048);
// ********** End Function SetStyle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassMenu, nullptr, "SetStyle", 	Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::CBLiquidGlassMenu_eventSetStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::CBLiquidGlassMenu_eventSetStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassMenu::execSetStyle)
{
	P_GET_STRUCT(FCBLiquidGlassControlStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStyle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassMenu Function SetStyle ***************************************

// ********** Begin Class UCBLiquidGlassMenu *******************************************************
void UCBLiquidGlassMenu::GetItems_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassMenu* Obj = (const UCBLiquidGlassMenu*)Object;
	TArray<FCBLiquidGlassItem>& Result = *(TArray<FCBLiquidGlassItem>*)OutValue;
	Result = (TArray<FCBLiquidGlassItem>)Obj->GetItems();
}
void UCBLiquidGlassMenu::SetItems_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassMenu* Obj = (UCBLiquidGlassMenu*)Object;
	TArray<FCBLiquidGlassItem>& Value = *(TArray<FCBLiquidGlassItem>*)InValue;
	Obj->SetItems(Value);
}
void UCBLiquidGlassMenu::GetItemHeight_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassMenu* Obj = (const UCBLiquidGlassMenu*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetItemHeight();
}
void UCBLiquidGlassMenu::SetItemHeight_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassMenu* Obj = (UCBLiquidGlassMenu*)Object;
	float& Value = *(float*)InValue;
	Obj->SetItemHeight(Value);
}
void UCBLiquidGlassMenu::GetbCloseOnClick_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassMenu* Obj = (const UCBLiquidGlassMenu*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetCloseOnClick();
}
void UCBLiquidGlassMenu::SetbCloseOnClick_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassMenu* Obj = (UCBLiquidGlassMenu*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetCloseOnClick(Value);
}
void UCBLiquidGlassMenu::GetbShowIcons_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassMenu* Obj = (const UCBLiquidGlassMenu*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowIcons();
}
void UCBLiquidGlassMenu::SetbShowIcons_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassMenu* Obj = (UCBLiquidGlassMenu*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowIcons(Value);
}
void UCBLiquidGlassMenu::GetbShowLabels_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassMenu* Obj = (const UCBLiquidGlassMenu*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowLabels();
}
void UCBLiquidGlassMenu::SetbShowLabels_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassMenu* Obj = (UCBLiquidGlassMenu*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowLabels(Value);
}
void UCBLiquidGlassMenu::GetStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassMenu* Obj = (const UCBLiquidGlassMenu*)Object;
	FCBLiquidGlassControlStyle& Result = *(FCBLiquidGlassControlStyle*)OutValue;
	Result = (FCBLiquidGlassControlStyle)Obj->GetStyle();
}
void UCBLiquidGlassMenu::SetStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassMenu* Obj = (UCBLiquidGlassMenu*)Object;
	FCBLiquidGlassControlStyle& Value = *(FCBLiquidGlassControlStyle*)InValue;
	Obj->SetStyle(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassMenu;
UClass* UCBLiquidGlassMenu::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassMenu;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassMenu.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassMenu"),
			Z_Registration_Info_UClass_UCBLiquidGlassMenu.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassMenu,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassMenu.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassMenu_NoRegister()
{
	return UCBLiquidGlassMenu::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG frosted liquid glass menu. */" },
#endif
		{ "DisplayName", "Liquid Glass Menu" },
		{ "IncludePath", "CBLiquidGlassControls.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG frosted liquid glass menu." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "Category", "Liquid Glass Menu" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemHeight_MetaData[] = {
		{ "Category", "Liquid Glass Menu" },
		{ "ClampMin", "24.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCloseOnClick_MetaData[] = {
		{ "Category", "Liquid Glass Menu" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowIcons_MetaData[] = {
		{ "Category", "Liquid Glass Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether row icons are visible. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether row icons are visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowLabels_MetaData[] = {
		{ "Category", "Liquid Glass Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether row labels are visible. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether row labels are visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Menu" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMenuItemClicked_MetaData[] = {
		{ "Category", "Liquid Glass Menu|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassMenu constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Items;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ItemHeight;
	static void NewProp_bCloseOnClick_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCloseOnClick;
	static void NewProp_bShowIcons_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowIcons;
	static void NewProp_bShowLabels_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowLabels;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMenuItemClicked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassMenu constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetCloseOnClick"), .Pointer = &UCBLiquidGlassMenu::execSetCloseOnClick },
		{ .NameUTF8 = UTF8TEXT("SetItemHeight"), .Pointer = &UCBLiquidGlassMenu::execSetItemHeight },
		{ .NameUTF8 = UTF8TEXT("SetItems"), .Pointer = &UCBLiquidGlassMenu::execSetItems },
		{ .NameUTF8 = UTF8TEXT("SetShowIcons"), .Pointer = &UCBLiquidGlassMenu::execSetShowIcons },
		{ .NameUTF8 = UTF8TEXT("SetShowLabels"), .Pointer = &UCBLiquidGlassMenu::execSetShowLabels },
		{ .NameUTF8 = UTF8TEXT("SetStyle"), .Pointer = &UCBLiquidGlassMenu::execSetStyle },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassMenu_SetCloseOnClick, "SetCloseOnClick" }, // 2018097769
		{ &Z_Construct_UFunction_UCBLiquidGlassMenu_SetItemHeight, "SetItemHeight" }, // 3173888140
		{ &Z_Construct_UFunction_UCBLiquidGlassMenu_SetItems, "SetItems" }, // 2988519937
		{ &Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowIcons, "SetShowIcons" }, // 513411241
		{ &Z_Construct_UFunction_UCBLiquidGlassMenu_SetShowLabels, "SetShowLabels" }, // 437065811
		{ &Z_Construct_UFunction_UCBLiquidGlassMenu_SetStyle, "SetStyle" }, // 2489547549
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassMenu>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassMenu_Statics

// ********** Begin Class UCBLiquidGlassMenu Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_Items_Inner = { "Items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCBLiquidGlassItem, METADATA_PARAMS(0, nullptr) }; // 688407273
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassMenu::SetItems_WrapperImpl, &UCBLiquidGlassMenu::GetItems_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassMenu, Items), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 688407273
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_ItemHeight = { "ItemHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassMenu::SetItemHeight_WrapperImpl, &UCBLiquidGlassMenu::GetItemHeight_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassMenu, ItemHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemHeight_MetaData), NewProp_ItemHeight_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bCloseOnClick_SetBit(void* Obj)
{
	((UCBLiquidGlassMenu*)Obj)->bCloseOnClick = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bCloseOnClick = { "bCloseOnClick", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassMenu::SetbCloseOnClick_WrapperImpl, &UCBLiquidGlassMenu::GetbCloseOnClick_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassMenu), &Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bCloseOnClick_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCloseOnClick_MetaData), NewProp_bCloseOnClick_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bShowIcons_SetBit(void* Obj)
{
	((UCBLiquidGlassMenu*)Obj)->bShowIcons = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bShowIcons = { "bShowIcons", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassMenu::SetbShowIcons_WrapperImpl, &UCBLiquidGlassMenu::GetbShowIcons_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassMenu), &Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bShowIcons_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowIcons_MetaData), NewProp_bShowIcons_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bShowLabels_SetBit(void* Obj)
{
	((UCBLiquidGlassMenu*)Obj)->bShowLabels = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bShowLabels = { "bShowLabels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassMenu::SetbShowLabels_WrapperImpl, &UCBLiquidGlassMenu::GetbShowLabels_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassMenu), &Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bShowLabels_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowLabels_MetaData), NewProp_bShowLabels_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassMenu::SetStyle_WrapperImpl, &UCBLiquidGlassMenu::GetStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassMenu, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_OnMenuItemClicked = { "OnMenuItemClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassMenu, OnMenuItemClicked), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassItemClickedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMenuItemClicked_MetaData), NewProp_OnMenuItemClicked_MetaData) }; // 426524792
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassMenu_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_Items_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_Items,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_ItemHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bCloseOnClick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bShowIcons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_bShowLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassMenu_Statics::NewProp_OnMenuItemClicked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassMenu_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassMenu Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassMenu_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassMenu_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassMenu_Statics::ClassParams = {
	&UCBLiquidGlassMenu::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassMenu_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassMenu_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassMenu_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassMenu_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassMenu::StaticRegisterNativesUCBLiquidGlassMenu()
{
	UClass* Class = UCBLiquidGlassMenu::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassMenu_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassMenu()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassMenu.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassMenu.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassMenu_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassMenu.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassMenu);
UCBLiquidGlassMenu::~UCBLiquidGlassMenu() {}
// ********** End Class UCBLiquidGlassMenu *********************************************************

// ********** Begin Class UCBLiquidGlassSearchBar Function SetHintText *****************************
struct Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics
{
	struct CBLiquidGlassSearchBar_eventSetHintText_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the placeholder text shown when Text is empty. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the placeholder text shown when Text is empty." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetHintText constinit property declarations ***************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHintText constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHintText Property Definitions **************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSearchBar_eventSetHintText_Parms, InText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::PropPointers) < 2048);
// ********** End Function SetHintText Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSearchBar, nullptr, "SetHintText", 	Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::CBLiquidGlassSearchBar_eventSetHintText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::CBLiquidGlassSearchBar_eventSetHintText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSearchBar::execSetHintText)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHintText(Z_Param_InText);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSearchBar Function SetHintText *******************************

// ********** Begin Class UCBLiquidGlassSearchBar Function SetSearchBoxStyle ***********************
struct Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics
{
	struct CBLiquidGlassSearchBar_eventSetSearchBoxStyle_Parms
	{
		FCBLiquidGlassSearchBoxStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the two-layer search-box layout, colours and glass recipe. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the two-layer search-box layout, colours and glass recipe." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSearchBoxStyle constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSearchBoxStyle constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSearchBoxStyle Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSearchBar_eventSetSearchBoxStyle_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle, METADATA_PARAMS(0, nullptr) }; // 65488991
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::PropPointers) < 2048);
// ********** End Function SetSearchBoxStyle Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSearchBar, nullptr, "SetSearchBoxStyle", 	Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::CBLiquidGlassSearchBar_eventSetSearchBoxStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::CBLiquidGlassSearchBar_eventSetSearchBoxStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSearchBar::execSetSearchBoxStyle)
{
	P_GET_STRUCT(FCBLiquidGlassSearchBoxStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSearchBoxStyle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSearchBar Function SetSearchBoxStyle *************************

// ********** Begin Class UCBLiquidGlassSearchBar Function SetShowClearButton **********************
struct Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics
{
	struct CBLiquidGlassSearchBar_eventSetShowClearButton_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides the circular clear button. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides the circular clear button." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowClearButton constinit property declarations ********************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowClearButton constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowClearButton Property Definitions *******************************
void Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassSearchBar_eventSetShowClearButton_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassSearchBar_eventSetShowClearButton_Parms), &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::PropPointers) < 2048);
// ********** End Function SetShowClearButton Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSearchBar, nullptr, "SetShowClearButton", 	Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::CBLiquidGlassSearchBar_eventSetShowClearButton_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::CBLiquidGlassSearchBar_eventSetShowClearButton_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSearchBar::execSetShowClearButton)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowClearButton(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSearchBar Function SetShowClearButton ************************

// ********** Begin Class UCBLiquidGlassSearchBar Function SetShowSearchIcon ***********************
struct Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics
{
	struct CBLiquidGlassSearchBar_eventSetShowSearchIcon_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides the magnifier glyph in the inner text layer. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides the magnifier glyph in the inner text layer." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowSearchIcon constinit property declarations *********************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowSearchIcon constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowSearchIcon Property Definitions ********************************
void Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassSearchBar_eventSetShowSearchIcon_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassSearchBar_eventSetShowSearchIcon_Parms), &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::PropPointers) < 2048);
// ********** End Function SetShowSearchIcon Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSearchBar, nullptr, "SetShowSearchIcon", 	Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::CBLiquidGlassSearchBar_eventSetShowSearchIcon_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::CBLiquidGlassSearchBar_eventSetShowSearchIcon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSearchBar::execSetShowSearchIcon)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowSearchIcon(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSearchBar Function SetShowSearchIcon *************************

// ********** Begin Class UCBLiquidGlassSearchBar Function SetShowText *****************************
struct Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics
{
	struct CBLiquidGlassSearchBar_eventSetShowText_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides the editable text box while preserving its value. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides the editable text box while preserving its value." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowText constinit property declarations ***************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowText constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowText Property Definitions **************************************
void Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassSearchBar_eventSetShowText_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassSearchBar_eventSetShowText_Parms), &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::PropPointers) < 2048);
// ********** End Function SetShowText Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSearchBar, nullptr, "SetShowText", 	Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::CBLiquidGlassSearchBar_eventSetShowText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::CBLiquidGlassSearchBar_eventSetShowText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSearchBar::execSetShowText)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowText(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSearchBar Function SetShowText *******************************

// ********** Begin Class UCBLiquidGlassSearchBar Function SetStyle ********************************
struct Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics
{
	struct CBLiquidGlassSearchBar_eventSetStyle_Parms
	{
		FCBLiquidGlassControlStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the shared quality/preset data used by the search box glass layers. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the shared quality/preset data used by the search box glass layers." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStyle constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStyle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStyle Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSearchBar_eventSetStyle_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(0, nullptr) }; // 3956690548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::PropPointers) < 2048);
// ********** End Function SetStyle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSearchBar, nullptr, "SetStyle", 	Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::CBLiquidGlassSearchBar_eventSetStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::CBLiquidGlassSearchBar_eventSetStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSearchBar::execSetStyle)
{
	P_GET_STRUCT(FCBLiquidGlassControlStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStyle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSearchBar Function SetStyle **********************************

// ********** Begin Class UCBLiquidGlassSearchBar Function SetText *********************************
struct Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics
{
	struct CBLiquidGlassSearchBar_eventSetText_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the editable text without changing the hint. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the editable text without changing the hint." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetText constinit property declarations *******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetText constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetText Property Definitions ******************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSearchBar_eventSetText_Parms, InText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::PropPointers) < 2048);
// ********** End Function SetText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSearchBar, nullptr, "SetText", 	Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::CBLiquidGlassSearchBar_eventSetText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::CBLiquidGlassSearchBar_eventSetText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSearchBar::execSetText)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetText(Z_Param_InText);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSearchBar Function SetText ***********************************

// ********** Begin Class UCBLiquidGlassSearchBar **************************************************
void UCBLiquidGlassSearchBar::GetText_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSearchBar* Obj = (const UCBLiquidGlassSearchBar*)Object;
	FText& Result = *(FText*)OutValue;
	Result = (FText)Obj->GetText();
}
void UCBLiquidGlassSearchBar::SetText_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSearchBar* Obj = (UCBLiquidGlassSearchBar*)Object;
	FText& Value = *(FText*)InValue;
	Obj->SetText(Value);
}
void UCBLiquidGlassSearchBar::GetHintText_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSearchBar* Obj = (const UCBLiquidGlassSearchBar*)Object;
	FText& Result = *(FText*)OutValue;
	Result = (FText)Obj->GetHintText();
}
void UCBLiquidGlassSearchBar::SetHintText_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSearchBar* Obj = (UCBLiquidGlassSearchBar*)Object;
	FText& Value = *(FText*)InValue;
	Obj->SetHintText(Value);
}
void UCBLiquidGlassSearchBar::GetbShowClearButton_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSearchBar* Obj = (const UCBLiquidGlassSearchBar*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowClearButton();
}
void UCBLiquidGlassSearchBar::SetbShowClearButton_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSearchBar* Obj = (UCBLiquidGlassSearchBar*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowClearButton(Value);
}
void UCBLiquidGlassSearchBar::GetbShowSearchIcon_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSearchBar* Obj = (const UCBLiquidGlassSearchBar*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowSearchIcon();
}
void UCBLiquidGlassSearchBar::SetbShowSearchIcon_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSearchBar* Obj = (UCBLiquidGlassSearchBar*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowSearchIcon(Value);
}
void UCBLiquidGlassSearchBar::GetbShowText_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSearchBar* Obj = (const UCBLiquidGlassSearchBar*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowText();
}
void UCBLiquidGlassSearchBar::SetbShowText_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSearchBar* Obj = (UCBLiquidGlassSearchBar*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowText(Value);
}
void UCBLiquidGlassSearchBar::GetStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSearchBar* Obj = (const UCBLiquidGlassSearchBar*)Object;
	FCBLiquidGlassControlStyle& Result = *(FCBLiquidGlassControlStyle*)OutValue;
	Result = (FCBLiquidGlassControlStyle)Obj->GetStyle();
}
void UCBLiquidGlassSearchBar::SetStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSearchBar* Obj = (UCBLiquidGlassSearchBar*)Object;
	FCBLiquidGlassControlStyle& Value = *(FCBLiquidGlassControlStyle*)InValue;
	Obj->SetStyle(Value);
}
void UCBLiquidGlassSearchBar::GetSearchBoxStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassSearchBar* Obj = (const UCBLiquidGlassSearchBar*)Object;
	FCBLiquidGlassSearchBoxStyle& Result = *(FCBLiquidGlassSearchBoxStyle*)OutValue;
	Result = (FCBLiquidGlassSearchBoxStyle)Obj->GetSearchBoxStyle();
}
void UCBLiquidGlassSearchBar::SetSearchBoxStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSearchBar* Obj = (UCBLiquidGlassSearchBar*)Object;
	FCBLiquidGlassSearchBoxStyle& Value = *(FCBLiquidGlassSearchBoxStyle*)InValue;
	Obj->SetSearchBoxStyle(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassSearchBar;
UClass* UCBLiquidGlassSearchBar::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassSearchBar;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassSearchBar.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassSearchBar"),
			Z_Registration_Info_UClass_UCBLiquidGlassSearchBar.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassSearchBar,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassSearchBar.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassSearchBar_NoRegister()
{
	return UCBLiquidGlassSearchBar::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG liquid glass search bar. */" },
#endif
		{ "DisplayName", "Liquid Glass Search Bar" },
		{ "IncludePath", "CBLiquidGlassControls.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG liquid glass search bar." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HintText_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowClearButton_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowSearchIcon_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the magnifier glyph is visible. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the magnifier glyph is visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowText_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the editable text layer is visible. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the editable text layer is visible." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchBoxStyle_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTextChanged_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTextCommitted_MetaData[] = {
		{ "Category", "Liquid Glass Search Bar|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassSearchBar constinit property declarations ******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FTextPropertyParams NewProp_HintText;
	static void NewProp_bShowClearButton_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowClearButton;
	static void NewProp_bShowSearchIcon_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowSearchIcon;
	static void NewProp_bShowText_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SearchBoxStyle;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTextChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTextCommitted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassSearchBar constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetHintText"), .Pointer = &UCBLiquidGlassSearchBar::execSetHintText },
		{ .NameUTF8 = UTF8TEXT("SetSearchBoxStyle"), .Pointer = &UCBLiquidGlassSearchBar::execSetSearchBoxStyle },
		{ .NameUTF8 = UTF8TEXT("SetShowClearButton"), .Pointer = &UCBLiquidGlassSearchBar::execSetShowClearButton },
		{ .NameUTF8 = UTF8TEXT("SetShowSearchIcon"), .Pointer = &UCBLiquidGlassSearchBar::execSetShowSearchIcon },
		{ .NameUTF8 = UTF8TEXT("SetShowText"), .Pointer = &UCBLiquidGlassSearchBar::execSetShowText },
		{ .NameUTF8 = UTF8TEXT("SetStyle"), .Pointer = &UCBLiquidGlassSearchBar::execSetStyle },
		{ .NameUTF8 = UTF8TEXT("SetText"), .Pointer = &UCBLiquidGlassSearchBar::execSetText },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetHintText, "SetHintText" }, // 2761949925
		{ &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetSearchBoxStyle, "SetSearchBoxStyle" }, // 3521466164
		{ &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowClearButton, "SetShowClearButton" }, // 1156667524
		{ &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowSearchIcon, "SetShowSearchIcon" }, // 3020240631
		{ &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetShowText, "SetShowText" }, // 1040624040
		{ &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetStyle, "SetStyle" }, // 815584394
		{ &Z_Construct_UFunction_UCBLiquidGlassSearchBar_SetText, "SetText" }, // 2563936917
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassSearchBar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics

// ********** Begin Class UCBLiquidGlassSearchBar Property Definitions *****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSearchBar::SetText_WrapperImpl, &UCBLiquidGlassSearchBar::GetText_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSearchBar, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_HintText = { "HintText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSearchBar::SetHintText_WrapperImpl, &UCBLiquidGlassSearchBar::GetHintText_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSearchBar, HintText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HintText_MetaData), NewProp_HintText_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowClearButton_SetBit(void* Obj)
{
	((UCBLiquidGlassSearchBar*)Obj)->bShowClearButton = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowClearButton = { "bShowClearButton", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSearchBar::SetbShowClearButton_WrapperImpl, &UCBLiquidGlassSearchBar::GetbShowClearButton_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassSearchBar), &Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowClearButton_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowClearButton_MetaData), NewProp_bShowClearButton_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowSearchIcon_SetBit(void* Obj)
{
	((UCBLiquidGlassSearchBar*)Obj)->bShowSearchIcon = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowSearchIcon = { "bShowSearchIcon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSearchBar::SetbShowSearchIcon_WrapperImpl, &UCBLiquidGlassSearchBar::GetbShowSearchIcon_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassSearchBar), &Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowSearchIcon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowSearchIcon_MetaData), NewProp_bShowSearchIcon_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowText_SetBit(void* Obj)
{
	((UCBLiquidGlassSearchBar*)Obj)->bShowText = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowText = { "bShowText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSearchBar::SetbShowText_WrapperImpl, &UCBLiquidGlassSearchBar::GetbShowText_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassSearchBar), &Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowText_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowText_MetaData), NewProp_bShowText_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSearchBar::SetStyle_WrapperImpl, &UCBLiquidGlassSearchBar::GetStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSearchBar, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_SearchBoxStyle = { "SearchBoxStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSearchBar::SetSearchBoxStyle_WrapperImpl, &UCBLiquidGlassSearchBar::GetSearchBoxStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassSearchBar, SearchBoxStyle), Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchBoxStyle_MetaData), NewProp_SearchBoxStyle_MetaData) }; // 65488991
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_OnTextChanged = { "OnTextChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassSearchBar, OnTextChanged), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTextChanged_MetaData), NewProp_OnTextChanged_MetaData) }; // 1202461114
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_OnTextCommitted = { "OnTextCommitted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassSearchBar, OnTextCommitted), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassTextChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTextCommitted_MetaData), NewProp_OnTextCommitted_MetaData) }; // 1202461114
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_HintText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowClearButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowSearchIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_bShowText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_SearchBoxStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_OnTextChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::NewProp_OnTextCommitted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassSearchBar Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::ClassParams = {
	&UCBLiquidGlassSearchBar::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassSearchBar::StaticRegisterNativesUCBLiquidGlassSearchBar()
{
	UClass* Class = UCBLiquidGlassSearchBar::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassSearchBar()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassSearchBar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassSearchBar.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassSearchBar.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassSearchBar);
UCBLiquidGlassSearchBar::~UCBLiquidGlassSearchBar() {}
// ********** End Class UCBLiquidGlassSearchBar ****************************************************

// ********** Begin Class UCBLiquidGlassProgress Function SetBlurStrength **************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics
{
	struct CBLiquidGlassProgress_eventSetBlurStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the outer glass blur amount. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the outer glass blur amount." },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetBlurStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::PropPointers) < 2048);
// ********** End Function SetBlurStrength Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetBlurStrength", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::CBLiquidGlassProgress_eventSetBlurStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::CBLiquidGlassProgress_eventSetBlurStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetBlurStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBlurStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetBlurStrength ****************************

// ********** Begin Class UCBLiquidGlassProgress Function SetCircularSize **************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics
{
	struct CBLiquidGlassProgress_eventSetCircularSize_Parms
	{
		FVector2D InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the desired size of the circular progress widget. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the desired size of the circular progress widget." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetCircularSize constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCircularSize constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCircularSize Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetCircularSize_Parms, InValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::PropPointers) < 2048);
// ********** End Function SetCircularSize Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetCircularSize", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::CBLiquidGlassProgress_eventSetCircularSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::CBLiquidGlassProgress_eventSetCircularSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetCircularSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCircularSize(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetCircularSize ****************************

// ********** Begin Class UCBLiquidGlassProgress Function SetEndCapSize ****************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics
{
	struct CBLiquidGlassProgress_eventSetEndCapSize_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the droplet cap diameter at the current linear fill endpoint. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the droplet cap diameter at the current linear fill endpoint." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetEndCapSize constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetEndCapSize constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetEndCapSize Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetEndCapSize_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::PropPointers) < 2048);
// ********** End Function SetEndCapSize Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetEndCapSize", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::CBLiquidGlassProgress_eventSetEndCapSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::CBLiquidGlassProgress_eventSetEndCapSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetEndCapSize)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetEndCapSize(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetEndCapSize ******************************

// ********** Begin Class UCBLiquidGlassProgress Function SetFillColor *****************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics
{
	struct CBLiquidGlassProgress_eventSetFillColor_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the filled progress colour. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the filled progress colour." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetFillColor constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFillColor constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFillColor Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetFillColor_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::PropPointers) < 2048);
// ********** End Function SetFillColor Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetFillColor", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::CBLiquidGlassProgress_eventSetFillColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::CBLiquidGlassProgress_eventSetFillColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetFillColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFillColor(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetFillColor *******************************

// ********** Begin Class UCBLiquidGlassProgress Function SetFrostRadius ***************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics
{
	struct CBLiquidGlassProgress_eventSetFrostRadius_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the outer glass frost amount. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the outer glass frost amount." },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetFrostRadius_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::PropPointers) < 2048);
// ********** End Function SetFrostRadius Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetFrostRadius", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::CBLiquidGlassProgress_eventSetFrostRadius_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::CBLiquidGlassProgress_eventSetFrostRadius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetFrostRadius)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFrostRadius(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetFrostRadius *****************************

// ********** Begin Class UCBLiquidGlassProgress Function SetGlassOpacity **************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics
{
	struct CBLiquidGlassProgress_eventSetGlassOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the opacity of the outer glass shell. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the opacity of the outer glass shell." },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetGlassOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetGlassOpacity Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetGlassOpacity", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::CBLiquidGlassProgress_eventSetGlassOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::CBLiquidGlassProgress_eventSetGlassOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetGlassOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGlassOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetGlassOpacity ****************************

// ********** Begin Class UCBLiquidGlassProgress Function SetLinearSize ****************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics
{
	struct CBLiquidGlassProgress_eventSetLinearSize_Parms
	{
		FVector2D InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the desired size of the linear capsule progress widget. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the desired size of the linear capsule progress widget." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetLinearSize constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLinearSize constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLinearSize Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetLinearSize_Parms, InValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::PropPointers) < 2048);
// ********** End Function SetLinearSize Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetLinearSize", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::CBLiquidGlassProgress_eventSetLinearSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::CBLiquidGlassProgress_eventSetLinearSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetLinearSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLinearSize(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetLinearSize ******************************

// ********** Begin Class UCBLiquidGlassProgress Function SetPrismIntensity ************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics
{
	struct CBLiquidGlassProgress_eventSetPrismIntensity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the chromatic edge strength. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the chromatic edge strength." },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetPrismIntensity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::PropPointers) < 2048);
// ********** End Function SetPrismIntensity Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetPrismIntensity", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::CBLiquidGlassProgress_eventSetPrismIntensity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::CBLiquidGlassProgress_eventSetPrismIntensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetPrismIntensity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPrismIntensity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetPrismIntensity **************************

// ********** Begin Class UCBLiquidGlassProgress Function SetProgressStyle *************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics
{
	struct CBLiquidGlassProgress_eventSetProgressStyle_Parms
	{
		ECBLiquidGlassProgressStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Switches between the linear capsule bar and circular ring styles. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Switches between the linear capsule bar and circular ring styles." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetProgressStyle constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetProgressStyle constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetProgressStyle Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetProgressStyle_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle, METADATA_PARAMS(0, nullptr) }; // 2653204971
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::PropPointers) < 2048);
// ********** End Function SetProgressStyle Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetProgressStyle", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::CBLiquidGlassProgress_eventSetProgressStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::CBLiquidGlassProgress_eventSetProgressStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetProgressStyle)
{
	P_GET_ENUM(ECBLiquidGlassProgressStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetProgressStyle(ECBLiquidGlassProgressStyle(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetProgressStyle ***************************

// ********** Begin Class UCBLiquidGlassProgress Function SetQuality *******************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics
{
	struct CBLiquidGlassProgress_eventSetQuality_Parms
	{
		ECBLiquidGlassQuality InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the renderer quality used by all glass layers inside the progress widget. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the renderer quality used by all glass layers inside the progress widget." },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::NewProp_InValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetQuality_Parms, InValue), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(0, nullptr) }; // 2771085032
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::NewProp_InValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::PropPointers) < 2048);
// ********** End Function SetQuality Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetQuality", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::CBLiquidGlassProgress_eventSetQuality_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::CBLiquidGlassProgress_eventSetQuality_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetQuality)
{
	P_GET_ENUM(ECBLiquidGlassQuality,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetQuality(ECBLiquidGlassQuality(Z_Param_InValue));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetQuality *********************************

// ********** Begin Class UCBLiquidGlassProgress Function SetRefractionStrength ********************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics
{
	struct CBLiquidGlassProgress_eventSetRefractionStrength_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the outer glass refraction strength. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the outer glass refraction strength." },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetRefractionStrength_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::PropPointers) < 2048);
// ********** End Function SetRefractionStrength Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetRefractionStrength", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::CBLiquidGlassProgress_eventSetRefractionStrength_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::CBLiquidGlassProgress_eventSetRefractionStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetRefractionStrength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRefractionStrength(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetRefractionStrength **********************

// ********** Begin Class UCBLiquidGlassProgress Function SetShowPercentText ***********************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics
{
	struct CBLiquidGlassProgress_eventSetShowPercentText_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows or hides the percentage text. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows or hides the percentage text." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShowPercentText constinit property declarations ********************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShowPercentText constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShowPercentText Property Definitions *******************************
void Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassProgress_eventSetShowPercentText_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassProgress_eventSetShowPercentText_Parms), &Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::PropPointers) < 2048);
// ********** End Function SetShowPercentText Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetShowPercentText", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::CBLiquidGlassProgress_eventSetShowPercentText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::CBLiquidGlassProgress_eventSetShowPercentText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetShowPercentText)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShowPercentText(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetShowPercentText *************************

// ********** Begin Class UCBLiquidGlassProgress Function SetTextColor *****************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics
{
	struct CBLiquidGlassProgress_eventSetTextColor_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the percentage text colour. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the percentage text colour." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextColor constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextColor constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextColor Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetTextColor_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::PropPointers) < 2048);
// ********** End Function SetTextColor Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetTextColor", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::CBLiquidGlassProgress_eventSetTextColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::CBLiquidGlassProgress_eventSetTextColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetTextColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextColor(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetTextColor *******************************

// ********** Begin Class UCBLiquidGlassProgress Function SetThickness *****************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics
{
	struct CBLiquidGlassProgress_eventSetThickness_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the line/ring thickness in pixels. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the line/ring thickness in pixels." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetThickness constinit property declarations **************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetThickness constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetThickness Property Definitions *************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetThickness_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::PropPointers) < 2048);
// ********** End Function SetThickness Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetThickness", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::CBLiquidGlassProgress_eventSetThickness_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::CBLiquidGlassProgress_eventSetThickness_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetThickness)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetThickness(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetThickness *******************************

// ********** Begin Class UCBLiquidGlassProgress Function SetTrackColor ****************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics
{
	struct CBLiquidGlassProgress_eventSetTrackColor_Parms
	{
		FLinearColor InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the colour of the unfilled track/ring. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the colour of the unfilled track/ring." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTrackColor constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTrackColor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTrackColor Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetTrackColor_Parms, InValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::PropPointers) < 2048);
// ********** End Function SetTrackColor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetTrackColor", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::CBLiquidGlassProgress_eventSetTrackColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::CBLiquidGlassProgress_eventSetTrackColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetTrackColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTrackColor(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetTrackColor ******************************

// ********** Begin Class UCBLiquidGlassProgress Function SetTrackOpacity **************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics
{
	struct CBLiquidGlassProgress_eventSetTrackOpacity_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the opacity multiplier for the unfilled track/ring. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the opacity multiplier for the unfilled track/ring." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTrackOpacity constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTrackOpacity constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTrackOpacity Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetTrackOpacity_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetTrackOpacity Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetTrackOpacity", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::CBLiquidGlassProgress_eventSetTrackOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::CBLiquidGlassProgress_eventSetTrackOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetTrackOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTrackOpacity(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetTrackOpacity ****************************

// ********** Begin Class UCBLiquidGlassProgress Function SetValue *********************************
struct Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics
{
	struct CBLiquidGlassProgress_eventSetValue_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets normalized progress in the [0, 1] range. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets normalized progress in the [0, 1] range." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetValue constinit property declarations ******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetValue constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetValue Property Definitions *****************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassProgress_eventSetValue_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::PropPointers) < 2048);
// ********** End Function SetValue Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassProgress, nullptr, "SetValue", 	Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::CBLiquidGlassProgress_eventSetValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::CBLiquidGlassProgress_eventSetValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassProgress::execSetValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetValue(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassProgress Function SetValue ***********************************

// ********** Begin Class UCBLiquidGlassProgress ***************************************************
void UCBLiquidGlassProgress::GetValue_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetValue();
}
void UCBLiquidGlassProgress::SetValue_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetValue(Value);
}
void UCBLiquidGlassProgress::GetProgressStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	ECBLiquidGlassProgressStyle& Result = *(ECBLiquidGlassProgressStyle*)OutValue;
	Result = (ECBLiquidGlassProgressStyle)Obj->GetProgressStyle();
}
void UCBLiquidGlassProgress::SetProgressStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	ECBLiquidGlassProgressStyle& Value = *(ECBLiquidGlassProgressStyle*)InValue;
	Obj->SetProgressStyle(Value);
}
void UCBLiquidGlassProgress::GetFillColor_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetFillColor();
}
void UCBLiquidGlassProgress::SetFillColor_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetFillColor(Value);
}
void UCBLiquidGlassProgress::GetThickness_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetThickness();
}
void UCBLiquidGlassProgress::SetThickness_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetThickness(Value);
}
void UCBLiquidGlassProgress::GetLinearSize_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	FVector2D& Result = *(FVector2D*)OutValue;
	Result = (FVector2D)Obj->GetLinearSize();
}
void UCBLiquidGlassProgress::SetLinearSize_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	FVector2D& Value = *(FVector2D*)InValue;
	Obj->SetLinearSize(Value);
}
void UCBLiquidGlassProgress::GetCircularSize_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	FVector2D& Result = *(FVector2D*)OutValue;
	Result = (FVector2D)Obj->GetCircularSize();
}
void UCBLiquidGlassProgress::SetCircularSize_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	FVector2D& Value = *(FVector2D*)InValue;
	Obj->SetCircularSize(Value);
}
void UCBLiquidGlassProgress::GetEndCapSize_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetEndCapSize();
}
void UCBLiquidGlassProgress::SetEndCapSize_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetEndCapSize(Value);
}
void UCBLiquidGlassProgress::GetTrackColor_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetTrackColor();
}
void UCBLiquidGlassProgress::SetTrackColor_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetTrackColor(Value);
}
void UCBLiquidGlassProgress::GetTrackOpacity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetTrackOpacity();
}
void UCBLiquidGlassProgress::SetTrackOpacity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetTrackOpacity(Value);
}
void UCBLiquidGlassProgress::GetbShowPercentText_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetShowPercentText();
}
void UCBLiquidGlassProgress::SetbShowPercentText_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetShowPercentText(Value);
}
void UCBLiquidGlassProgress::GetTextColor_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetTextColor();
}
void UCBLiquidGlassProgress::SetTextColor_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetTextColor(Value);
}
void UCBLiquidGlassProgress::GetBlurStrength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetBlurStrength();
}
void UCBLiquidGlassProgress::SetBlurStrength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetBlurStrength(Value);
}
void UCBLiquidGlassProgress::GetFrostRadius_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetFrostRadius();
}
void UCBLiquidGlassProgress::SetFrostRadius_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetFrostRadius(Value);
}
void UCBLiquidGlassProgress::GetRefractionStrength_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetRefractionStrength();
}
void UCBLiquidGlassProgress::SetRefractionStrength_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetRefractionStrength(Value);
}
void UCBLiquidGlassProgress::GetPrismIntensity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetPrismIntensity();
}
void UCBLiquidGlassProgress::SetPrismIntensity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetPrismIntensity(Value);
}
void UCBLiquidGlassProgress::GetGlassOpacity_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetGlassOpacity();
}
void UCBLiquidGlassProgress::SetGlassOpacity_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	float& Value = *(float*)InValue;
	Obj->SetGlassOpacity(Value);
}
void UCBLiquidGlassProgress::GetQuality_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassProgress* Obj = (const UCBLiquidGlassProgress*)Object;
	ECBLiquidGlassQuality& Result = *(ECBLiquidGlassQuality*)OutValue;
	Result = (ECBLiquidGlassQuality)Obj->GetQuality();
}
void UCBLiquidGlassProgress::SetQuality_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassProgress* Obj = (UCBLiquidGlassProgress*)Object;
	ECBLiquidGlassQuality& Value = *(ECBLiquidGlassQuality*)InValue;
	Obj->SetQuality(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassProgress;
UClass* UCBLiquidGlassProgress::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassProgress;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassProgress.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassProgress"),
			Z_Registration_Info_UClass_UCBLiquidGlassProgress.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassProgress,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassProgress.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassProgress_NoRegister()
{
	return UCBLiquidGlassProgress::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassProgress_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG linear or circular liquid glass progress. */" },
#endif
		{ "DisplayName", "Liquid Glass Progress" },
		{ "IncludePath", "CBLiquidGlassControls.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG linear or circular liquid glass progress." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "Liquid Glass Progress" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProgressStyle_MetaData[] = {
		{ "Category", "Liquid Glass Progress" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillColor_MetaData[] = {
		{ "Category", "Liquid Glass Progress" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Thickness_MetaData[] = {
		{ "Category", "Liquid Glass Progress" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinearSize_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Desired size for the linear capsule progress bar. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Desired size for the linear capsule progress bar." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CircularSize_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Desired size for the circular progress ring. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Desired size for the circular progress ring." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndCapSize_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Layout" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Diameter of the droplet cap at the end of the linear fill. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Diameter of the droplet cap at the end of the linear fill." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackColor_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Colour of the unfilled track layer. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Colour of the unfilled track layer." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Style" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opacity of the unfilled track layer. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opacity of the unfilled track layer." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowPercentText_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the numeric percentage is drawn. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the numeric percentage is drawn." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextColor_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Colour used for the percentage text. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Colour used for the percentage text." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlurStrength_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Glass blur used by the outer shell. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Glass blur used by the outer shell." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrostRadius_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Frost amount used by the outer shell. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Frost amount used by the outer shell." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefractionStrength_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Refraction strength used by the outer shell and end cap. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refraction strength used by the outer shell and end cap." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrismIntensity_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Chromatic edge strength used by the outer shell and end cap. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Chromatic edge strength used by the outer shell and end cap." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlassOpacity_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Glass" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Overall opacity of the outer glass shell. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Overall opacity of the outer glass shell." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quality_MetaData[] = {
		{ "Category", "Liquid Glass Progress|Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Renderer quality profile for all glass layers inside the progress widget. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Renderer quality profile for all glass layers inside the progress widget." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassProgress constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ProgressStyle_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ProgressStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FillColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Thickness;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LinearSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CircularSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EndCapSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TrackColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TrackOpacity;
	static void NewProp_bShowPercentText_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowPercentText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlurStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrostRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RefractionStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PrismIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlassOpacity;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Quality_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Quality;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassProgress constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetBlurStrength"), .Pointer = &UCBLiquidGlassProgress::execSetBlurStrength },
		{ .NameUTF8 = UTF8TEXT("SetCircularSize"), .Pointer = &UCBLiquidGlassProgress::execSetCircularSize },
		{ .NameUTF8 = UTF8TEXT("SetEndCapSize"), .Pointer = &UCBLiquidGlassProgress::execSetEndCapSize },
		{ .NameUTF8 = UTF8TEXT("SetFillColor"), .Pointer = &UCBLiquidGlassProgress::execSetFillColor },
		{ .NameUTF8 = UTF8TEXT("SetFrostRadius"), .Pointer = &UCBLiquidGlassProgress::execSetFrostRadius },
		{ .NameUTF8 = UTF8TEXT("SetGlassOpacity"), .Pointer = &UCBLiquidGlassProgress::execSetGlassOpacity },
		{ .NameUTF8 = UTF8TEXT("SetLinearSize"), .Pointer = &UCBLiquidGlassProgress::execSetLinearSize },
		{ .NameUTF8 = UTF8TEXT("SetPrismIntensity"), .Pointer = &UCBLiquidGlassProgress::execSetPrismIntensity },
		{ .NameUTF8 = UTF8TEXT("SetProgressStyle"), .Pointer = &UCBLiquidGlassProgress::execSetProgressStyle },
		{ .NameUTF8 = UTF8TEXT("SetQuality"), .Pointer = &UCBLiquidGlassProgress::execSetQuality },
		{ .NameUTF8 = UTF8TEXT("SetRefractionStrength"), .Pointer = &UCBLiquidGlassProgress::execSetRefractionStrength },
		{ .NameUTF8 = UTF8TEXT("SetShowPercentText"), .Pointer = &UCBLiquidGlassProgress::execSetShowPercentText },
		{ .NameUTF8 = UTF8TEXT("SetTextColor"), .Pointer = &UCBLiquidGlassProgress::execSetTextColor },
		{ .NameUTF8 = UTF8TEXT("SetThickness"), .Pointer = &UCBLiquidGlassProgress::execSetThickness },
		{ .NameUTF8 = UTF8TEXT("SetTrackColor"), .Pointer = &UCBLiquidGlassProgress::execSetTrackColor },
		{ .NameUTF8 = UTF8TEXT("SetTrackOpacity"), .Pointer = &UCBLiquidGlassProgress::execSetTrackOpacity },
		{ .NameUTF8 = UTF8TEXT("SetValue"), .Pointer = &UCBLiquidGlassProgress::execSetValue },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetBlurStrength, "SetBlurStrength" }, // 3068586044
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetCircularSize, "SetCircularSize" }, // 4091395759
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetEndCapSize, "SetEndCapSize" }, // 868384834
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetFillColor, "SetFillColor" }, // 2127184614
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetFrostRadius, "SetFrostRadius" }, // 2455038896
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetGlassOpacity, "SetGlassOpacity" }, // 2189367148
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetLinearSize, "SetLinearSize" }, // 2338166511
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetPrismIntensity, "SetPrismIntensity" }, // 2021574804
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetProgressStyle, "SetProgressStyle" }, // 1408242020
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetQuality, "SetQuality" }, // 2515896559
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetRefractionStrength, "SetRefractionStrength" }, // 3120898977
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetShowPercentText, "SetShowPercentText" }, // 2885338758
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetTextColor, "SetTextColor" }, // 2764659173
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetThickness, "SetThickness" }, // 3022368562
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackColor, "SetTrackColor" }, // 3724830492
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetTrackOpacity, "SetTrackOpacity" }, // 612740734
		{ &Z_Construct_UFunction_UCBLiquidGlassProgress_SetValue, "SetValue" }, // 2203496783
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassProgress>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassProgress_Statics

// ********** Begin Class UCBLiquidGlassProgress Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetValue_WrapperImpl, &UCBLiquidGlassProgress::GetValue_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_ProgressStyle_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_ProgressStyle = { "ProgressStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetProgressStyle_WrapperImpl, &UCBLiquidGlassProgress::GetProgressStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, ProgressStyle), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassProgressStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProgressStyle_MetaData), NewProp_ProgressStyle_MetaData) }; // 2653204971
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_FillColor = { "FillColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetFillColor_WrapperImpl, &UCBLiquidGlassProgress::GetFillColor_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, FillColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillColor_MetaData), NewProp_FillColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetThickness_WrapperImpl, &UCBLiquidGlassProgress::GetThickness_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, Thickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Thickness_MetaData), NewProp_Thickness_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_LinearSize = { "LinearSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetLinearSize_WrapperImpl, &UCBLiquidGlassProgress::GetLinearSize_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, LinearSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinearSize_MetaData), NewProp_LinearSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_CircularSize = { "CircularSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetCircularSize_WrapperImpl, &UCBLiquidGlassProgress::GetCircularSize_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, CircularSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CircularSize_MetaData), NewProp_CircularSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_EndCapSize = { "EndCapSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetEndCapSize_WrapperImpl, &UCBLiquidGlassProgress::GetEndCapSize_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, EndCapSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndCapSize_MetaData), NewProp_EndCapSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_TrackColor = { "TrackColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetTrackColor_WrapperImpl, &UCBLiquidGlassProgress::GetTrackColor_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, TrackColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackColor_MetaData), NewProp_TrackColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_TrackOpacity = { "TrackOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetTrackOpacity_WrapperImpl, &UCBLiquidGlassProgress::GetTrackOpacity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, TrackOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackOpacity_MetaData), NewProp_TrackOpacity_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_bShowPercentText_SetBit(void* Obj)
{
	((UCBLiquidGlassProgress*)Obj)->bShowPercentText = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_bShowPercentText = { "bShowPercentText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetbShowPercentText_WrapperImpl, &UCBLiquidGlassProgress::GetbShowPercentText_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassProgress), &Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_bShowPercentText_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowPercentText_MetaData), NewProp_bShowPercentText_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_TextColor = { "TextColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetTextColor_WrapperImpl, &UCBLiquidGlassProgress::GetTextColor_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, TextColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextColor_MetaData), NewProp_TextColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_BlurStrength = { "BlurStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetBlurStrength_WrapperImpl, &UCBLiquidGlassProgress::GetBlurStrength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, BlurStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlurStrength_MetaData), NewProp_BlurStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_FrostRadius = { "FrostRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetFrostRadius_WrapperImpl, &UCBLiquidGlassProgress::GetFrostRadius_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, FrostRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrostRadius_MetaData), NewProp_FrostRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_RefractionStrength = { "RefractionStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetRefractionStrength_WrapperImpl, &UCBLiquidGlassProgress::GetRefractionStrength_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, RefractionStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefractionStrength_MetaData), NewProp_RefractionStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_PrismIntensity = { "PrismIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetPrismIntensity_WrapperImpl, &UCBLiquidGlassProgress::GetPrismIntensity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, PrismIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrismIntensity_MetaData), NewProp_PrismIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_GlassOpacity = { "GlassOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetGlassOpacity_WrapperImpl, &UCBLiquidGlassProgress::GetGlassOpacity_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, GlassOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlassOpacity_MetaData), NewProp_GlassOpacity_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_Quality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_Quality = { "Quality", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassProgress::SetQuality_WrapperImpl, &UCBLiquidGlassProgress::GetQuality_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassProgress, Quality), Z_Construct_UEnum_CBLiquidGlass_ECBLiquidGlassQuality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quality_MetaData), NewProp_Quality_MetaData) }; // 2771085032
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_ProgressStyle_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_ProgressStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_FillColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_Thickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_LinearSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_CircularSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_EndCapSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_TrackColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_TrackOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_bShowPercentText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_TextColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_BlurStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_FrostRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_RefractionStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_PrismIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_GlassOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_Quality_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassProgress_Statics::NewProp_Quality,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassProgress_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassProgress Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassProgress_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassProgress_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassProgress_Statics::ClassParams = {
	&UCBLiquidGlassProgress::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassProgress_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassProgress_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassProgress_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassProgress_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassProgress::StaticRegisterNativesUCBLiquidGlassProgress()
{
	UClass* Class = UCBLiquidGlassProgress::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassProgress_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassProgress()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassProgress.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassProgress.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassProgress_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassProgress.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassProgress);
UCBLiquidGlassProgress::~UCBLiquidGlassProgress() {}
// ********** End Class UCBLiquidGlassProgress *****************************************************

// ********** Begin Class UCBLiquidGlassStepper Function SetIntegerOnly ****************************
struct Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics
{
	struct CBLiquidGlassStepper_eventSetIntegerOnly_Parms
	{
		bool bInValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Stepper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rounds displayed and committed values to whole numbers when enabled. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rounds displayed and committed values to whole numbers when enabled." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetIntegerOnly constinit property declarations ************************
	static void NewProp_bInValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetIntegerOnly constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetIntegerOnly Property Definitions ***********************************
void Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::NewProp_bInValue_SetBit(void* Obj)
{
	((CBLiquidGlassStepper_eventSetIntegerOnly_Parms*)Obj)->bInValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::NewProp_bInValue = { "bInValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CBLiquidGlassStepper_eventSetIntegerOnly_Parms), &Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::NewProp_bInValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::NewProp_bInValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::PropPointers) < 2048);
// ********** End Function SetIntegerOnly Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassStepper, nullptr, "SetIntegerOnly", 	Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::CBLiquidGlassStepper_eventSetIntegerOnly_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::CBLiquidGlassStepper_eventSetIntegerOnly_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassStepper::execSetIntegerOnly)
{
	P_GET_UBOOL(Z_Param_bInValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetIntegerOnly(Z_Param_bInValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassStepper Function SetIntegerOnly ******************************

// ********** Begin Class UCBLiquidGlassStepper Function SetMaxValue *******************************
struct Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics
{
	struct CBLiquidGlassStepper_eventSetMaxValue_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Stepper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the upper bound and re-clamps the current value. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the upper bound and re-clamps the current value." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMaxValue constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMaxValue constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMaxValue Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassStepper_eventSetMaxValue_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::PropPointers) < 2048);
// ********** End Function SetMaxValue Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassStepper, nullptr, "SetMaxValue", 	Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::CBLiquidGlassStepper_eventSetMaxValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::CBLiquidGlassStepper_eventSetMaxValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassStepper::execSetMaxValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaxValue(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassStepper Function SetMaxValue *********************************

// ********** Begin Class UCBLiquidGlassStepper Function SetMinValue *******************************
struct Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics
{
	struct CBLiquidGlassStepper_eventSetMinValue_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Stepper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the lower bound and re-clamps the current value. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the lower bound and re-clamps the current value." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMinValue constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMinValue constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMinValue Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassStepper_eventSetMinValue_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::PropPointers) < 2048);
// ********** End Function SetMinValue Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassStepper, nullptr, "SetMinValue", 	Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::CBLiquidGlassStepper_eventSetMinValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::CBLiquidGlassStepper_eventSetMinValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassStepper::execSetMinValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMinValue(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassStepper Function SetMinValue *********************************

// ********** Begin Class UCBLiquidGlassStepper Function SetStep ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics
{
	struct CBLiquidGlassStepper_eventSetStep_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Stepper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets how much the minus/plus buttons change the value per click. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets how much the minus/plus buttons change the value per click." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStep constinit property declarations *******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStep constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStep Property Definitions ******************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassStepper_eventSetStep_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::PropPointers) < 2048);
// ********** End Function SetStep Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassStepper, nullptr, "SetStep", 	Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::CBLiquidGlassStepper_eventSetStep_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::CBLiquidGlassStepper_eventSetStep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassStepper::execSetStep)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStep(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassStepper Function SetStep *************************************

// ********** Begin Class UCBLiquidGlassStepper Function SetStyle **********************************
struct Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics
{
	struct CBLiquidGlassStepper_eventSetStyle_Parms
	{
		FCBLiquidGlassControlStyle InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Stepper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the glass preset, quality, size and colour recipe. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the glass preset, quality, size and colour recipe." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStyle constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStyle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStyle Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassStepper_eventSetStyle_Parms, InValue), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(0, nullptr) }; // 3956690548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::PropPointers) < 2048);
// ********** End Function SetStyle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassStepper, nullptr, "SetStyle", 	Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::CBLiquidGlassStepper_eventSetStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::CBLiquidGlassStepper_eventSetStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassStepper::execSetStyle)
{
	P_GET_STRUCT(FCBLiquidGlassControlStyle,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStyle(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassStepper Function SetStyle ************************************

// ********** Begin Class UCBLiquidGlassStepper Function SetValue **********************************
struct Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics
{
	struct CBLiquidGlassStepper_eventSetValue_Parms
	{
		float InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Liquid Glass Stepper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the current numeric value and clamps it to MinValue/MaxValue. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the current numeric value and clamps it to MinValue/MaxValue." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetValue constinit property declarations ******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetValue constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetValue Property Definitions *****************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassStepper_eventSetValue_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::PropPointers) < 2048);
// ********** End Function SetValue Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassStepper, nullptr, "SetValue", 	Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::CBLiquidGlassStepper_eventSetValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::CBLiquidGlassStepper_eventSetValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassStepper::execSetValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetValue(Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassStepper Function SetValue ************************************

// ********** Begin Class UCBLiquidGlassStepper ****************************************************
void UCBLiquidGlassStepper::GetValue_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassStepper* Obj = (const UCBLiquidGlassStepper*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetValue();
}
void UCBLiquidGlassStepper::SetValue_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassStepper* Obj = (UCBLiquidGlassStepper*)Object;
	float& Value = *(float*)InValue;
	Obj->SetValue(Value);
}
void UCBLiquidGlassStepper::GetMinValue_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassStepper* Obj = (const UCBLiquidGlassStepper*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMinValue();
}
void UCBLiquidGlassStepper::SetMinValue_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassStepper* Obj = (UCBLiquidGlassStepper*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMinValue(Value);
}
void UCBLiquidGlassStepper::GetMaxValue_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassStepper* Obj = (const UCBLiquidGlassStepper*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMaxValue();
}
void UCBLiquidGlassStepper::SetMaxValue_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassStepper* Obj = (UCBLiquidGlassStepper*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMaxValue(Value);
}
void UCBLiquidGlassStepper::GetStep_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassStepper* Obj = (const UCBLiquidGlassStepper*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetStep();
}
void UCBLiquidGlassStepper::SetStep_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassStepper* Obj = (UCBLiquidGlassStepper*)Object;
	float& Value = *(float*)InValue;
	Obj->SetStep(Value);
}
void UCBLiquidGlassStepper::GetbIntegerOnly_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassStepper* Obj = (const UCBLiquidGlassStepper*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetIntegerOnly();
}
void UCBLiquidGlassStepper::SetbIntegerOnly_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassStepper* Obj = (UCBLiquidGlassStepper*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetIntegerOnly(Value);
}
void UCBLiquidGlassStepper::GetStyle_WrapperImpl(const void* Object, void* OutValue)
{
	const UCBLiquidGlassStepper* Obj = (const UCBLiquidGlassStepper*)Object;
	FCBLiquidGlassControlStyle& Result = *(FCBLiquidGlassControlStyle*)OutValue;
	Result = (FCBLiquidGlassControlStyle)Obj->GetStyle();
}
void UCBLiquidGlassStepper::SetStyle_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassStepper* Obj = (UCBLiquidGlassStepper*)Object;
	FCBLiquidGlassControlStyle& Value = *(FCBLiquidGlassControlStyle*)InValue;
	Obj->SetStyle(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassStepper;
UClass* UCBLiquidGlassStepper::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassStepper;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassStepper.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassStepper"),
			Z_Registration_Info_UClass_UCBLiquidGlassStepper.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassStepper,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassStepper.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassStepper_NoRegister()
{
	return UCBLiquidGlassStepper::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassStepper_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG liquid glass numeric stepper. */" },
#endif
		{ "DisplayName", "Liquid Glass Stepper" },
		{ "IncludePath", "CBLiquidGlassControls.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG liquid glass numeric stepper." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "Liquid Glass Stepper" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinValue_MetaData[] = {
		{ "Category", "Liquid Glass Stepper" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxValue_MetaData[] = {
		{ "Category", "Liquid Glass Stepper" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Step_MetaData[] = {
		{ "Category", "Liquid Glass Stepper" },
		{ "ClampMin", "0.0001" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIntegerOnly_MetaData[] = {
		{ "Category", "Liquid Glass Stepper" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "Category", "Liquid Glass Stepper" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnValueChanged_MetaData[] = {
		{ "Category", "Liquid Glass Stepper|Event" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassControls.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassStepper constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Step;
	static void NewProp_bIntegerOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIntegerOnly;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnValueChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassStepper constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetIntegerOnly"), .Pointer = &UCBLiquidGlassStepper::execSetIntegerOnly },
		{ .NameUTF8 = UTF8TEXT("SetMaxValue"), .Pointer = &UCBLiquidGlassStepper::execSetMaxValue },
		{ .NameUTF8 = UTF8TEXT("SetMinValue"), .Pointer = &UCBLiquidGlassStepper::execSetMinValue },
		{ .NameUTF8 = UTF8TEXT("SetStep"), .Pointer = &UCBLiquidGlassStepper::execSetStep },
		{ .NameUTF8 = UTF8TEXT("SetStyle"), .Pointer = &UCBLiquidGlassStepper::execSetStyle },
		{ .NameUTF8 = UTF8TEXT("SetValue"), .Pointer = &UCBLiquidGlassStepper::execSetValue },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassStepper_SetIntegerOnly, "SetIntegerOnly" }, // 2471388369
		{ &Z_Construct_UFunction_UCBLiquidGlassStepper_SetMaxValue, "SetMaxValue" }, // 101214961
		{ &Z_Construct_UFunction_UCBLiquidGlassStepper_SetMinValue, "SetMinValue" }, // 1021563458
		{ &Z_Construct_UFunction_UCBLiquidGlassStepper_SetStep, "SetStep" }, // 3867368572
		{ &Z_Construct_UFunction_UCBLiquidGlassStepper_SetStyle, "SetStyle" }, // 202614637
		{ &Z_Construct_UFunction_UCBLiquidGlassStepper_SetValue, "SetValue" }, // 261931570
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassStepper>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassStepper_Statics

// ********** Begin Class UCBLiquidGlassStepper Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassStepper::SetValue_WrapperImpl, &UCBLiquidGlassStepper::GetValue_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassStepper, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_MinValue = { "MinValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassStepper::SetMinValue_WrapperImpl, &UCBLiquidGlassStepper::GetMinValue_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassStepper, MinValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinValue_MetaData), NewProp_MinValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_MaxValue = { "MaxValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassStepper::SetMaxValue_WrapperImpl, &UCBLiquidGlassStepper::GetMaxValue_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassStepper, MaxValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxValue_MetaData), NewProp_MaxValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_Step = { "Step", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassStepper::SetStep_WrapperImpl, &UCBLiquidGlassStepper::GetStep_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassStepper, Step), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Step_MetaData), NewProp_Step_MetaData) };
void Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_bIntegerOnly_SetBit(void* Obj)
{
	((UCBLiquidGlassStepper*)Obj)->bIntegerOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_bIntegerOnly = { "bIntegerOnly", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassStepper::SetbIntegerOnly_WrapperImpl, &UCBLiquidGlassStepper::GetbIntegerOnly_WrapperImpl, 1, sizeof(bool), sizeof(UCBLiquidGlassStepper), &Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_bIntegerOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIntegerOnly_MetaData), NewProp_bIntegerOnly_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassStepper::SetStyle_WrapperImpl, &UCBLiquidGlassStepper::GetStyle_WrapperImpl, 1, STRUCT_OFFSET(UCBLiquidGlassStepper, Style), Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 3956690548
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_OnValueChanged = { "OnValueChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassStepper, OnValueChanged), Z_Construct_UDelegateFunction_CBLiquidGlass_CBLiquidGlassFloatChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnValueChanged_MetaData), NewProp_OnValueChanged_MetaData) }; // 3415648293
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassStepper_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_MinValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_MaxValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_Step,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_bIntegerOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_Style,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassStepper_Statics::NewProp_OnValueChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassStepper_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassStepper Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassStepper_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassStepper_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassStepper_Statics::ClassParams = {
	&UCBLiquidGlassStepper::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassStepper_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassStepper_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassStepper_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassStepper_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassStepper::StaticRegisterNativesUCBLiquidGlassStepper()
{
	UClass* Class = UCBLiquidGlassStepper::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassStepper_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassStepper()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassStepper.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassStepper.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassStepper_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassStepper.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassStepper);
UCBLiquidGlassStepper::~UCBLiquidGlassStepper() {}
// ********** End Class UCBLiquidGlassStepper ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h__Script_CBLiquidGlass_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCBLiquidGlassToggle, UCBLiquidGlassToggle::StaticClass, TEXT("UCBLiquidGlassToggle"), &Z_Registration_Info_UClass_UCBLiquidGlassToggle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassToggle), 879562284U) },
		{ Z_Construct_UClass_UCBLiquidGlassSegmentedControl, UCBLiquidGlassSegmentedControl::StaticClass, TEXT("UCBLiquidGlassSegmentedControl"), &Z_Registration_Info_UClass_UCBLiquidGlassSegmentedControl, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassSegmentedControl), 537882367U) },
		{ Z_Construct_UClass_UCBLiquidGlassTabBar, UCBLiquidGlassTabBar::StaticClass, TEXT("UCBLiquidGlassTabBar"), &Z_Registration_Info_UClass_UCBLiquidGlassTabBar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassTabBar), 883209574U) },
		{ Z_Construct_UClass_UCBLiquidGlassToolbar, UCBLiquidGlassToolbar::StaticClass, TEXT("UCBLiquidGlassToolbar"), &Z_Registration_Info_UClass_UCBLiquidGlassToolbar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassToolbar), 2777088800U) },
		{ Z_Construct_UClass_UCBLiquidGlassMenu, UCBLiquidGlassMenu::StaticClass, TEXT("UCBLiquidGlassMenu"), &Z_Registration_Info_UClass_UCBLiquidGlassMenu, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassMenu), 1445799103U) },
		{ Z_Construct_UClass_UCBLiquidGlassSearchBar, UCBLiquidGlassSearchBar::StaticClass, TEXT("UCBLiquidGlassSearchBar"), &Z_Registration_Info_UClass_UCBLiquidGlassSearchBar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassSearchBar), 3526687546U) },
		{ Z_Construct_UClass_UCBLiquidGlassProgress, UCBLiquidGlassProgress::StaticClass, TEXT("UCBLiquidGlassProgress"), &Z_Registration_Info_UClass_UCBLiquidGlassProgress, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassProgress), 871153422U) },
		{ Z_Construct_UClass_UCBLiquidGlassStepper, UCBLiquidGlassStepper::StaticClass, TEXT("UCBLiquidGlassStepper"), &Z_Registration_Info_UClass_UCBLiquidGlassStepper, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassStepper), 819206178U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h__Script_CBLiquidGlass_3009404553{
	TEXT("/Script/CBLiquidGlass"),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h__Script_CBLiquidGlass_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h__Script_CBLiquidGlass_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

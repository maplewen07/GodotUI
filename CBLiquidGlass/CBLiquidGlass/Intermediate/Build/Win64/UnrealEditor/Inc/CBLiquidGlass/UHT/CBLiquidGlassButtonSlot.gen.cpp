// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassButtonSlot.h"
#include "Layout/Margin.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassButtonSlot() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassButtonSlot();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassButtonSlot_NoRegister();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EHorizontalAlignment();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EVerticalAlignment();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
UMG_API UClass* Z_Construct_UClass_UPanelSlot();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCBLiquidGlassButtonSlot Function SetHorizontalAlignment *****************
struct Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics
{
	struct CBLiquidGlassButtonSlot_eventSetHorizontalAlignment_Parms
	{
		TEnumAsByte<EHorizontalAlignment> InHorizontalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Layout|Liquid Glass Button Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets horizontal alignment of the child inside the glass button. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButtonSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets horizontal alignment of the child inside the glass button." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetHorizontalAlignment constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InHorizontalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHorizontalAlignment constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHorizontalAlignment Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::NewProp_InHorizontalAlignment = { "InHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButtonSlot_eventSetHorizontalAlignment_Parms, InHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(0, nullptr) }; // 990570535
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::NewProp_InHorizontalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::PropPointers) < 2048);
// ********** End Function SetHorizontalAlignment Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButtonSlot, nullptr, "SetHorizontalAlignment", 	Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::CBLiquidGlassButtonSlot_eventSetHorizontalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::CBLiquidGlassButtonSlot_eventSetHorizontalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButtonSlot::execSetHorizontalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InHorizontalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHorizontalAlignment(EHorizontalAlignment(Z_Param_InHorizontalAlignment));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButtonSlot Function SetHorizontalAlignment *******************

// ********** Begin Class UCBLiquidGlassButtonSlot Function SetPadding *****************************
struct Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics
{
	struct CBLiquidGlassButtonSlot_eventSetPadding_Parms
	{
		FMargin InPadding;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Layout|Liquid Glass Button Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets inner spacing between the button glass bounds and child content. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButtonSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets inner spacing between the button glass bounds and child content." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetPadding constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InPadding;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPadding constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPadding Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::NewProp_InPadding = { "InPadding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButtonSlot_eventSetPadding_Parms, InPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::NewProp_InPadding,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::PropPointers) < 2048);
// ********** End Function SetPadding Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButtonSlot, nullptr, "SetPadding", 	Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::CBLiquidGlassButtonSlot_eventSetPadding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::CBLiquidGlassButtonSlot_eventSetPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButtonSlot::execSetPadding)
{
	P_GET_STRUCT(FMargin,Z_Param_InPadding);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPadding(Z_Param_InPadding);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButtonSlot Function SetPadding *******************************

// ********** Begin Class UCBLiquidGlassButtonSlot Function SetVerticalAlignment *******************
struct Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics
{
	struct CBLiquidGlassButtonSlot_eventSetVerticalAlignment_Parms
	{
		TEnumAsByte<EVerticalAlignment> InVerticalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Layout|Liquid Glass Button Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets vertical alignment of the child inside the glass button. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassButtonSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets vertical alignment of the child inside the glass button." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetVerticalAlignment constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InVerticalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVerticalAlignment constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVerticalAlignment Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::NewProp_InVerticalAlignment = { "InVerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassButtonSlot_eventSetVerticalAlignment_Parms, InVerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(0, nullptr) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::NewProp_InVerticalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::PropPointers) < 2048);
// ********** End Function SetVerticalAlignment Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassButtonSlot, nullptr, "SetVerticalAlignment", 	Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::CBLiquidGlassButtonSlot_eventSetVerticalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::CBLiquidGlassButtonSlot_eventSetVerticalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassButtonSlot::execSetVerticalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InVerticalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVerticalAlignment(EVerticalAlignment(Z_Param_InVerticalAlignment));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassButtonSlot Function SetVerticalAlignment *********************

// ********** Begin Class UCBLiquidGlassButtonSlot *************************************************
void UCBLiquidGlassButtonSlot::SetPadding_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButtonSlot* Obj = (UCBLiquidGlassButtonSlot*)Object;
	FMargin& Value = *(FMargin*)InValue;
	Obj->SetPadding(Value);
}
void UCBLiquidGlassButtonSlot::SetHorizontalAlignment_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButtonSlot* Obj = (UCBLiquidGlassButtonSlot*)Object;
	EHorizontalAlignment Value = (EHorizontalAlignment)*(uint8*)InValue;
	Obj->SetHorizontalAlignment(Value);
}
void UCBLiquidGlassButtonSlot::SetVerticalAlignment_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassButtonSlot* Obj = (UCBLiquidGlassButtonSlot*)Object;
	EVerticalAlignment Value = (EVerticalAlignment)*(uint8*)InValue;
	Obj->SetVerticalAlignment(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassButtonSlot;
UClass* UCBLiquidGlassButtonSlot::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassButtonSlot;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassButtonSlot.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassButtonSlot"),
			Z_Registration_Info_UClass_UCBLiquidGlassButtonSlot.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassButtonSlot,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassButtonSlot.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassButtonSlot_NoRegister()
{
	return UCBLiquidGlassButtonSlot::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The single content slot for a UCBLiquidGlassButton. */" },
#endif
		{ "IncludePath", "CBLiquidGlassButtonSlot.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButtonSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The single content slot for a UCBLiquidGlassButton." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "Category", "Layout|Liquid Glass Button Slot" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButtonSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HorizontalAlignment_MetaData[] = {
		{ "Category", "Layout|Liquid Glass Button Slot" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButtonSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VerticalAlignment_MetaData[] = {
		{ "Category", "Layout|Liquid Glass Button Slot" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassButtonSlot.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassButtonSlot constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FBytePropertyParams NewProp_HorizontalAlignment;
	static const UECodeGen_Private::FBytePropertyParams NewProp_VerticalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassButtonSlot constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetHorizontalAlignment"), .Pointer = &UCBLiquidGlassButtonSlot::execSetHorizontalAlignment },
		{ .NameUTF8 = UTF8TEXT("SetPadding"), .Pointer = &UCBLiquidGlassButtonSlot::execSetPadding },
		{ .NameUTF8 = UTF8TEXT("SetVerticalAlignment"), .Pointer = &UCBLiquidGlassButtonSlot::execSetVerticalAlignment },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetHorizontalAlignment, "SetHorizontalAlignment" }, // 2651661178
		{ &Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetPadding, "SetPadding" }, // 1904074476
		{ &Z_Construct_UFunction_UCBLiquidGlassButtonSlot_SetVerticalAlignment, "SetVerticalAlignment" }, // 4103535830
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassButtonSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics

// ********** Begin Class UCBLiquidGlassButtonSlot Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButtonSlot::SetPadding_WrapperImpl, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassButtonSlot, Padding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) }; // 4099648758
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::NewProp_HorizontalAlignment = { "HorizontalAlignment", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButtonSlot::SetHorizontalAlignment_WrapperImpl, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassButtonSlot, HorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HorizontalAlignment_MetaData), NewProp_HorizontalAlignment_MetaData) }; // 990570535
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::NewProp_VerticalAlignment = { "VerticalAlignment", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassButtonSlot::SetVerticalAlignment_WrapperImpl, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassButtonSlot, VerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VerticalAlignment_MetaData), NewProp_VerticalAlignment_MetaData) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::NewProp_HorizontalAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::NewProp_VerticalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassButtonSlot Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPanelSlot,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::ClassParams = {
	&UCBLiquidGlassButtonSlot::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassButtonSlot::StaticRegisterNativesUCBLiquidGlassButtonSlot()
{
	UClass* Class = UCBLiquidGlassButtonSlot::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassButtonSlot()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassButtonSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassButtonSlot.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassButtonSlot.OuterSingleton;
}
UCBLiquidGlassButtonSlot::UCBLiquidGlassButtonSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassButtonSlot);
UCBLiquidGlassButtonSlot::~UCBLiquidGlassButtonSlot() {}
// ********** End Class UCBLiquidGlassButtonSlot ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h__Script_CBLiquidGlass_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCBLiquidGlassButtonSlot, UCBLiquidGlassButtonSlot::StaticClass, TEXT("UCBLiquidGlassButtonSlot"), &Z_Registration_Info_UClass_UCBLiquidGlassButtonSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassButtonSlot), 302319972U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h__Script_CBLiquidGlass_1913163572{
	TEXT("/Script/CBLiquidGlass"),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h__Script_CBLiquidGlass_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h__Script_CBLiquidGlass_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

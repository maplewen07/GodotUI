// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CBLiquidGlassSlot.h"
#include "Layout/Margin.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCBLiquidGlassSlot() {}

// ********** Begin Cross Module References ********************************************************
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSlot();
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSlot_NoRegister();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EHorizontalAlignment();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EVerticalAlignment();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
UMG_API UClass* Z_Construct_UClass_UPanelSlot();
UPackage* Z_Construct_UPackage__Script_CBLiquidGlass();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCBLiquidGlassSlot Function SetHorizontalAlignment ***********************
struct Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics
{
	struct CBLiquidGlassSlot_eventSetHorizontalAlignment_Parms
	{
		TEnumAsByte<EHorizontalAlignment> InHorizontalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Layout|Liquid Glass Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets horizontal alignment of the child inside the glass container. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets horizontal alignment of the child inside the glass container." },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::NewProp_InHorizontalAlignment = { "InHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlot_eventSetHorizontalAlignment_Parms, InHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(0, nullptr) }; // 990570535
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::NewProp_InHorizontalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::PropPointers) < 2048);
// ********** End Function SetHorizontalAlignment Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlot, nullptr, "SetHorizontalAlignment", 	Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::CBLiquidGlassSlot_eventSetHorizontalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::CBLiquidGlassSlot_eventSetHorizontalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlot::execSetHorizontalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InHorizontalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHorizontalAlignment(EHorizontalAlignment(Z_Param_InHorizontalAlignment));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlot Function SetHorizontalAlignment *************************

// ********** Begin Class UCBLiquidGlassSlot Function SetPadding ***********************************
struct Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics
{
	struct CBLiquidGlassSlot_eventSetPadding_Parms
	{
		FMargin InPadding;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Layout|Liquid Glass Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets inner spacing between the glass bounds and the child content. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets inner spacing between the glass bounds and the child content." },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::NewProp_InPadding = { "InPadding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlot_eventSetPadding_Parms, InPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::NewProp_InPadding,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::PropPointers) < 2048);
// ********** End Function SetPadding Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlot, nullptr, "SetPadding", 	Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::CBLiquidGlassSlot_eventSetPadding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::CBLiquidGlassSlot_eventSetPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlot::execSetPadding)
{
	P_GET_STRUCT(FMargin,Z_Param_InPadding);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPadding(Z_Param_InPadding);
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlot Function SetPadding *************************************

// ********** Begin Class UCBLiquidGlassSlot Function SetVerticalAlignment *************************
struct Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics
{
	struct CBLiquidGlassSlot_eventSetVerticalAlignment_Parms
	{
		TEnumAsByte<EVerticalAlignment> InVerticalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Layout|Liquid Glass Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets vertical alignment of the child inside the glass container. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets vertical alignment of the child inside the glass container." },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::NewProp_InVerticalAlignment = { "InVerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLiquidGlassSlot_eventSetVerticalAlignment_Parms, InVerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(0, nullptr) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::NewProp_InVerticalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::PropPointers) < 2048);
// ********** End Function SetVerticalAlignment Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCBLiquidGlassSlot, nullptr, "SetVerticalAlignment", 	Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::CBLiquidGlassSlot_eventSetVerticalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::CBLiquidGlassSlot_eventSetVerticalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCBLiquidGlassSlot::execSetVerticalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InVerticalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVerticalAlignment(EVerticalAlignment(Z_Param_InVerticalAlignment));
	P_NATIVE_END;
}
// ********** End Class UCBLiquidGlassSlot Function SetVerticalAlignment ***************************

// ********** Begin Class UCBLiquidGlassSlot *******************************************************
void UCBLiquidGlassSlot::SetPadding_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlot* Obj = (UCBLiquidGlassSlot*)Object;
	FMargin& Value = *(FMargin*)InValue;
	Obj->SetPadding(Value);
}
void UCBLiquidGlassSlot::SetHorizontalAlignment_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlot* Obj = (UCBLiquidGlassSlot*)Object;
	EHorizontalAlignment Value = (EHorizontalAlignment)*(uint8*)InValue;
	Obj->SetHorizontalAlignment(Value);
}
void UCBLiquidGlassSlot::SetVerticalAlignment_WrapperImpl(void* Object, const void* InValue)
{
	UCBLiquidGlassSlot* Obj = (UCBLiquidGlassSlot*)Object;
	EVerticalAlignment Value = (EVerticalAlignment)*(uint8*)InValue;
	Obj->SetVerticalAlignment(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCBLiquidGlassSlot;
UClass* UCBLiquidGlassSlot::GetPrivateStaticClass()
{
	using TClass = UCBLiquidGlassSlot;
	if (!Z_Registration_Info_UClass_UCBLiquidGlassSlot.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CBLiquidGlassSlot"),
			Z_Registration_Info_UClass_UCBLiquidGlassSlot.InnerSingleton,
			StaticRegisterNativesUCBLiquidGlassSlot,
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
	return Z_Registration_Info_UClass_UCBLiquidGlassSlot.InnerSingleton;
}
UClass* Z_Construct_UClass_UCBLiquidGlassSlot_NoRegister()
{
	return UCBLiquidGlassSlot::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCBLiquidGlassSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The single content slot for a UCBLiquidGlass panel. */" },
#endif
		{ "IncludePath", "CBLiquidGlassSlot.h" },
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The single content slot for a UCBLiquidGlass panel." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "Category", "Layout|Liquid Glass Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UMG slot padding forwarded to SCBLiquidGlass::ChildSlot. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UMG slot padding forwarded to SCBLiquidGlass::ChildSlot." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HorizontalAlignment_MetaData[] = {
		{ "Category", "Layout|Liquid Glass Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Horizontal alignment forwarded to the underlying Slate child slot. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Horizontal alignment forwarded to the underlying Slate child slot." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VerticalAlignment_MetaData[] = {
		{ "Category", "Layout|Liquid Glass Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Vertical alignment forwarded to the underlying Slate child slot. */" },
#endif
		{ "ModuleRelativePath", "Public/CBLiquidGlassSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Vertical alignment forwarded to the underlying Slate child slot." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCBLiquidGlassSlot constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FBytePropertyParams NewProp_HorizontalAlignment;
	static const UECodeGen_Private::FBytePropertyParams NewProp_VerticalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCBLiquidGlassSlot constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetHorizontalAlignment"), .Pointer = &UCBLiquidGlassSlot::execSetHorizontalAlignment },
		{ .NameUTF8 = UTF8TEXT("SetPadding"), .Pointer = &UCBLiquidGlassSlot::execSetPadding },
		{ .NameUTF8 = UTF8TEXT("SetVerticalAlignment"), .Pointer = &UCBLiquidGlassSlot::execSetVerticalAlignment },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCBLiquidGlassSlot_SetHorizontalAlignment, "SetHorizontalAlignment" }, // 393332033
		{ &Z_Construct_UFunction_UCBLiquidGlassSlot_SetPadding, "SetPadding" }, // 2477245065
		{ &Z_Construct_UFunction_UCBLiquidGlassSlot_SetVerticalAlignment, "SetVerticalAlignment" }, // 249293690
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCBLiquidGlassSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCBLiquidGlassSlot_Statics

// ********** Begin Class UCBLiquidGlassSlot Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCBLiquidGlassSlot_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlot::SetPadding_WrapperImpl, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassSlot, Padding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) }; // 4099648758
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassSlot_Statics::NewProp_HorizontalAlignment = { "HorizontalAlignment", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlot::SetHorizontalAlignment_WrapperImpl, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassSlot, HorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HorizontalAlignment_MetaData), NewProp_HorizontalAlignment_MetaData) }; // 990570535
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCBLiquidGlassSlot_Statics::NewProp_VerticalAlignment = { "VerticalAlignment", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &UCBLiquidGlassSlot::SetVerticalAlignment_WrapperImpl, nullptr, 1, STRUCT_OFFSET(UCBLiquidGlassSlot, VerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VerticalAlignment_MetaData), NewProp_VerticalAlignment_MetaData) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCBLiquidGlassSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlot_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlot_Statics::NewProp_HorizontalAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCBLiquidGlassSlot_Statics::NewProp_VerticalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSlot_Statics::PropPointers) < 2048);
// ********** End Class UCBLiquidGlassSlot Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UCBLiquidGlassSlot_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPanelSlot,
	(UObject* (*)())Z_Construct_UPackage__Script_CBLiquidGlass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSlot_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCBLiquidGlassSlot_Statics::ClassParams = {
	&UCBLiquidGlassSlot::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCBLiquidGlassSlot_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSlot_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCBLiquidGlassSlot_Statics::Class_MetaDataParams), Z_Construct_UClass_UCBLiquidGlassSlot_Statics::Class_MetaDataParams)
};
void UCBLiquidGlassSlot::StaticRegisterNativesUCBLiquidGlassSlot()
{
	UClass* Class = UCBLiquidGlassSlot::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCBLiquidGlassSlot_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCBLiquidGlassSlot()
{
	if (!Z_Registration_Info_UClass_UCBLiquidGlassSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCBLiquidGlassSlot.OuterSingleton, Z_Construct_UClass_UCBLiquidGlassSlot_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCBLiquidGlassSlot.OuterSingleton;
}
UCBLiquidGlassSlot::UCBLiquidGlassSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCBLiquidGlassSlot);
UCBLiquidGlassSlot::~UCBLiquidGlassSlot() {}
// ********** End Class UCBLiquidGlassSlot *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h__Script_CBLiquidGlass_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCBLiquidGlassSlot, UCBLiquidGlassSlot::StaticClass, TEXT("UCBLiquidGlassSlot"), &Z_Registration_Info_UClass_UCBLiquidGlassSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCBLiquidGlassSlot), 4097539187U) },
	};
}; // Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h__Script_CBLiquidGlass_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h__Script_CBLiquidGlass_4082836898{
	TEXT("/Script/CBLiquidGlass"),
	Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h__Script_CBLiquidGlass_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h__Script_CBLiquidGlass_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

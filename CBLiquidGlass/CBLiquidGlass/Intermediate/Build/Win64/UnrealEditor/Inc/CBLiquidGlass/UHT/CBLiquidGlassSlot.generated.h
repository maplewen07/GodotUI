// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassSlot.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassSlot_generated_h
#error "CBLiquidGlassSlot.generated.h already included, missing '#pragma once' in CBLiquidGlassSlot.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassSlot_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FMargin;

// ********** Begin Class UCBLiquidGlassSlot *******************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetVerticalAlignment); \
	DECLARE_FUNCTION(execSetHorizontalAlignment); \
	DECLARE_FUNCTION(execSetPadding);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_ACCESSORS \
static void SetPadding_WrapperImpl(void* Object, const void* InValue); \
static void SetHorizontalAlignment_WrapperImpl(void* Object, const void* InValue); \
static void SetVerticalAlignment_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassSlot_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSlot_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassSlot(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassSlot_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassSlot_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassSlot, UPanelSlot, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassSlot_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassSlot)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	CBLIQUIDGLASS_API UCBLiquidGlassSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassSlot(UCBLiquidGlassSlot&&) = delete; \
	UCBLiquidGlassSlot(const UCBLiquidGlassSlot&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassSlot); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassSlot); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCBLiquidGlassSlot) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassSlot();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_14_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassSlot;

// ********** End Class UCBLiquidGlassSlot *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlot_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

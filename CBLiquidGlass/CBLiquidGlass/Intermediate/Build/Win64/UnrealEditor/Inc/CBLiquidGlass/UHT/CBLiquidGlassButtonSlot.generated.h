// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassButtonSlot.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassButtonSlot_generated_h
#error "CBLiquidGlassButtonSlot.generated.h already included, missing '#pragma once' in CBLiquidGlassButtonSlot.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassButtonSlot_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FMargin;

// ********** Begin Class UCBLiquidGlassButtonSlot *************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetVerticalAlignment); \
	DECLARE_FUNCTION(execSetHorizontalAlignment); \
	DECLARE_FUNCTION(execSetPadding);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_ACCESSORS \
static void SetPadding_WrapperImpl(void* Object, const void* InValue); \
static void SetHorizontalAlignment_WrapperImpl(void* Object, const void* InValue); \
static void SetVerticalAlignment_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassButtonSlot_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassButtonSlot(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassButtonSlot_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassButtonSlot_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassButtonSlot, UPanelSlot, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassButtonSlot_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassButtonSlot)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	CBLIQUIDGLASS_API UCBLiquidGlassButtonSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassButtonSlot(UCBLiquidGlassButtonSlot&&) = delete; \
	UCBLiquidGlassButtonSlot(const UCBLiquidGlassButtonSlot&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassButtonSlot); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassButtonSlot); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCBLiquidGlassButtonSlot) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassButtonSlot();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_14_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassButtonSlot;

// ********** End Class UCBLiquidGlassButtonSlot ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButtonSlot_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassButton.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassButton_generated_h
#error "CBLiquidGlassButton.generated.h already included, missing '#pragma once' in CBLiquidGlassButton.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassButton_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECBLiquidGlassPreset : uint8;
enum class ECBLiquidGlassShape : uint8;

// ********** Begin Delegate FCBLiquidGlassButtonClickedEvent **************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_12_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassButtonClickedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassButtonClickedEvent);


// ********** End Delegate FCBLiquidGlassButtonClickedEvent ****************************************

// ********** Begin Class UCBLiquidGlassButton *****************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetDisabledOpacity); \
	DECLARE_FUNCTION(execSetPressedTintBoost); \
	DECLARE_FUNCTION(execSetPressedRefractionBoost); \
	DECLARE_FUNCTION(execSetHoverGlowBoost); \
	DECLARE_FUNCTION(execSetShape); \
	DECLARE_FUNCTION(execSetPreset);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_ACCESSORS \
static void GetPreset_WrapperImpl(const void* Object, void* OutValue); \
static void SetPreset_WrapperImpl(void* Object, const void* InValue); \
static void GetShape_WrapperImpl(const void* Object, void* OutValue); \
static void SetShape_WrapperImpl(void* Object, const void* InValue); \
static void GetHoverGlowBoost_WrapperImpl(const void* Object, void* OutValue); \
static void SetHoverGlowBoost_WrapperImpl(void* Object, const void* InValue); \
static void GetPressedRefractionBoost_WrapperImpl(const void* Object, void* OutValue); \
static void SetPressedRefractionBoost_WrapperImpl(void* Object, const void* InValue); \
static void GetPressedTintBoost_WrapperImpl(const void* Object, void* OutValue); \
static void SetPressedTintBoost_WrapperImpl(void* Object, const void* InValue); \
static void GetDisabledOpacity_WrapperImpl(const void* Object, void* OutValue); \
static void SetDisabledOpacity_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassButton_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassButton_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassButton(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassButton_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassButton_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassButton, UContentWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassButton_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassButton)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassButton(UCBLiquidGlassButton&&) = delete; \
	UCBLiquidGlassButton(const UCBLiquidGlassButton&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassButton); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassButton); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassButton) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassButton();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_15_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassButton;

// ********** End Class UCBLiquidGlassButton *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassButton_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

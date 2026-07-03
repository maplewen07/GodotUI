// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassSlider.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassSlider_generated_h
#error "CBLiquidGlassSlider.generated.h already included, missing '#pragma once' in CBLiquidGlassSlider.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassSlider_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECBLiquidGlassPreset : uint8;
enum class ECBLiquidGlassQuality : uint8;
struct FLinearColor;

// ********** Begin Delegate FCBLiquidGlassSliderValueChangedEvent *********************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_12_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassSliderValueChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassSliderValueChangedEvent, float Value);


// ********** End Delegate FCBLiquidGlassSliderValueChangedEvent ***********************************

// ********** Begin Class UCBLiquidGlassSlider *****************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetThumbMotionStrength); \
	DECLARE_FUNCTION(execSetThumbDamping); \
	DECLARE_FUNCTION(execSetThumbResponse); \
	DECLARE_FUNCTION(execSetThumbBounce); \
	DECLARE_FUNCTION(execSetQuality); \
	DECLARE_FUNCTION(execSetThumbPreset); \
	DECLARE_FUNCTION(execSetTrackOpacity); \
	DECLARE_FUNCTION(execSetTrackTint); \
	DECLARE_FUNCTION(execSetFillColor); \
	DECLARE_FUNCTION(execSetThumbSize); \
	DECLARE_FUNCTION(execSetTrackHeight); \
	DECLARE_FUNCTION(execSetSliderHeight); \
	DECLARE_FUNCTION(execSetSliderLength); \
	DECLARE_FUNCTION(execSetMaxValue); \
	DECLARE_FUNCTION(execSetMinValue); \
	DECLARE_FUNCTION(execSetValue);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_ACCESSORS \
static void GetValue_WrapperImpl(const void* Object, void* OutValue); \
static void SetValue_WrapperImpl(void* Object, const void* InValue); \
static void GetMinValue_WrapperImpl(const void* Object, void* OutValue); \
static void SetMinValue_WrapperImpl(void* Object, const void* InValue); \
static void GetMaxValue_WrapperImpl(const void* Object, void* OutValue); \
static void SetMaxValue_WrapperImpl(void* Object, const void* InValue); \
static void GetSliderLength_WrapperImpl(const void* Object, void* OutValue); \
static void SetSliderLength_WrapperImpl(void* Object, const void* InValue); \
static void GetSliderHeight_WrapperImpl(const void* Object, void* OutValue); \
static void SetSliderHeight_WrapperImpl(void* Object, const void* InValue); \
static void GetTrackHeight_WrapperImpl(const void* Object, void* OutValue); \
static void SetTrackHeight_WrapperImpl(void* Object, const void* InValue); \
static void GetThumbSize_WrapperImpl(const void* Object, void* OutValue); \
static void SetThumbSize_WrapperImpl(void* Object, const void* InValue); \
static void GetFillColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetFillColor_WrapperImpl(void* Object, const void* InValue); \
static void GetTrackTint_WrapperImpl(const void* Object, void* OutValue); \
static void SetTrackTint_WrapperImpl(void* Object, const void* InValue); \
static void GetTrackOpacity_WrapperImpl(const void* Object, void* OutValue); \
static void SetTrackOpacity_WrapperImpl(void* Object, const void* InValue); \
static void GetThumbPreset_WrapperImpl(const void* Object, void* OutValue); \
static void SetThumbPreset_WrapperImpl(void* Object, const void* InValue); \
static void GetQuality_WrapperImpl(const void* Object, void* OutValue); \
static void SetQuality_WrapperImpl(void* Object, const void* InValue); \
static void GetThumbBounce_WrapperImpl(const void* Object, void* OutValue); \
static void SetThumbBounce_WrapperImpl(void* Object, const void* InValue); \
static void GetThumbResponse_WrapperImpl(const void* Object, void* OutValue); \
static void SetThumbResponse_WrapperImpl(void* Object, const void* InValue); \
static void GetThumbDamping_WrapperImpl(const void* Object, void* OutValue); \
static void SetThumbDamping_WrapperImpl(void* Object, const void* InValue); \
static void GetThumbMotionStrength_WrapperImpl(const void* Object, void* OutValue); \
static void SetThumbMotionStrength_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassSlider_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSlider_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassSlider(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassSlider_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassSlider_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassSlider, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassSlider_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassSlider)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassSlider(UCBLiquidGlassSlider&&) = delete; \
	UCBLiquidGlassSlider(const UCBLiquidGlassSlider&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassSlider); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassSlider); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassSlider) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassSlider();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_15_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassSlider;

// ********** End Class UCBLiquidGlassSlider *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassSlider_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

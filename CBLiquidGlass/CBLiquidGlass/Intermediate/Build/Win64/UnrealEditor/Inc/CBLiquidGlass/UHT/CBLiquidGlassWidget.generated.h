// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassWidget.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassWidget_generated_h
#error "CBLiquidGlassWidget.generated.h already included, missing '#pragma once' in CBLiquidGlassWidget.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
enum class ECBLiquidGlassPreset : uint8;
enum class ECBLiquidGlassQuality : uint8;
enum class ECBLiquidGlassShape : uint8;
struct FLinearColor;

// ********** Begin Class UCBLiquidGlass ***********************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetMotionDamping); \
	DECLARE_FUNCTION(execSetMotionResponse); \
	DECLARE_FUNCTION(execSetMotionMaxOffset); \
	DECLARE_FUNCTION(execSetMotionStrength); \
	DECLARE_FUNCTION(execSetQuality); \
	DECLARE_FUNCTION(execSetGlassOpacity); \
	DECLARE_FUNCTION(execSetAdaptiveTintStrength); \
	DECLARE_FUNCTION(execSetSaturation); \
	DECLARE_FUNCTION(execSetTintOpacity); \
	DECLARE_FUNCTION(execSetTintColor); \
	DECLARE_FUNCTION(execSetInnerShadowIntensity); \
	DECLARE_FUNCTION(execSetInnerGlowIntensity); \
	DECLARE_FUNCTION(execSetGlowAngle); \
	DECLARE_FUNCTION(execSetRimIntensity); \
	DECLARE_FUNCTION(execSetGlowAmount); \
	DECLARE_FUNCTION(execSetNoiseAmount); \
	DECLARE_FUNCTION(execSetPrismIntensity); \
	DECLARE_FUNCTION(execSetChromaticAberration); \
	DECLARE_FUNCTION(execSetIndexOfRefraction); \
	DECLARE_FUNCTION(execSetRefractionThickness); \
	DECLARE_FUNCTION(execSetRefractionPower); \
	DECLARE_FUNCTION(execSetRefractionStrength); \
	DECLARE_FUNCTION(execSetInvertAlphaMask); \
	DECLARE_FUNCTION(execSetAlphaMaskSoftness); \
	DECLARE_FUNCTION(execSetAlphaMaskThreshold); \
	DECLARE_FUNCTION(execSetAlphaMaskTexture); \
	DECLARE_FUNCTION(execSetEdgeSoftness); \
	DECLARE_FUNCTION(execSetSquirclePower); \
	DECLARE_FUNCTION(execSetShape); \
	DECLARE_FUNCTION(execSetFrostRadius); \
	DECLARE_FUNCTION(execSetDownsampleAmount); \
	DECLARE_FUNCTION(execSetBlurStrength); \
	DECLARE_FUNCTION(execSetPreset);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_ACCESSORS \
static void GetPreset_WrapperImpl(const void* Object, void* OutValue); \
static void SetPreset_WrapperImpl(void* Object, const void* InValue); \
static void GetBlurStrength_WrapperImpl(const void* Object, void* OutValue); \
static void SetBlurStrength_WrapperImpl(void* Object, const void* InValue); \
static void GetDownsampleAmount_WrapperImpl(const void* Object, void* OutValue); \
static void SetDownsampleAmount_WrapperImpl(void* Object, const void* InValue); \
static void GetFrostRadius_WrapperImpl(const void* Object, void* OutValue); \
static void SetFrostRadius_WrapperImpl(void* Object, const void* InValue); \
static void GetShape_WrapperImpl(const void* Object, void* OutValue); \
static void SetShape_WrapperImpl(void* Object, const void* InValue); \
static void GetSquirclePower_WrapperImpl(const void* Object, void* OutValue); \
static void SetSquirclePower_WrapperImpl(void* Object, const void* InValue); \
static void GetEdgeSoftness_WrapperImpl(const void* Object, void* OutValue); \
static void SetEdgeSoftness_WrapperImpl(void* Object, const void* InValue); \
static void GetAlphaMaskTexture_WrapperImpl(const void* Object, void* OutValue); \
static void SetAlphaMaskTexture_WrapperImpl(void* Object, const void* InValue); \
static void GetAlphaMaskThreshold_WrapperImpl(const void* Object, void* OutValue); \
static void SetAlphaMaskThreshold_WrapperImpl(void* Object, const void* InValue); \
static void GetAlphaMaskSoftness_WrapperImpl(const void* Object, void* OutValue); \
static void SetAlphaMaskSoftness_WrapperImpl(void* Object, const void* InValue); \
static void GetInvertAlphaMask_WrapperImpl(const void* Object, void* OutValue); \
static void SetInvertAlphaMask_WrapperImpl(void* Object, const void* InValue); \
static void GetRefractionStrength_WrapperImpl(const void* Object, void* OutValue); \
static void SetRefractionStrength_WrapperImpl(void* Object, const void* InValue); \
static void GetRefractionPower_WrapperImpl(const void* Object, void* OutValue); \
static void SetRefractionPower_WrapperImpl(void* Object, const void* InValue); \
static void GetRefractionThickness_WrapperImpl(const void* Object, void* OutValue); \
static void SetRefractionThickness_WrapperImpl(void* Object, const void* InValue); \
static void GetIndexOfRefraction_WrapperImpl(const void* Object, void* OutValue); \
static void SetIndexOfRefraction_WrapperImpl(void* Object, const void* InValue); \
static void GetChromaticAberration_WrapperImpl(const void* Object, void* OutValue); \
static void SetChromaticAberration_WrapperImpl(void* Object, const void* InValue); \
static void GetPrismIntensity_WrapperImpl(const void* Object, void* OutValue); \
static void SetPrismIntensity_WrapperImpl(void* Object, const void* InValue); \
static void GetNoiseAmount_WrapperImpl(const void* Object, void* OutValue); \
static void SetNoiseAmount_WrapperImpl(void* Object, const void* InValue); \
static void GetGlowAmount_WrapperImpl(const void* Object, void* OutValue); \
static void SetGlowAmount_WrapperImpl(void* Object, const void* InValue); \
static void GetRimIntensity_WrapperImpl(const void* Object, void* OutValue); \
static void SetRimIntensity_WrapperImpl(void* Object, const void* InValue); \
static void GetGlowAngle_WrapperImpl(const void* Object, void* OutValue); \
static void SetGlowAngle_WrapperImpl(void* Object, const void* InValue); \
static void GetInnerGlowIntensity_WrapperImpl(const void* Object, void* OutValue); \
static void SetInnerGlowIntensity_WrapperImpl(void* Object, const void* InValue); \
static void GetInnerShadowIntensity_WrapperImpl(const void* Object, void* OutValue); \
static void SetInnerShadowIntensity_WrapperImpl(void* Object, const void* InValue); \
static void GetTintColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetTintColor_WrapperImpl(void* Object, const void* InValue); \
static void GetTintOpacity_WrapperImpl(const void* Object, void* OutValue); \
static void SetTintOpacity_WrapperImpl(void* Object, const void* InValue); \
static void GetSaturation_WrapperImpl(const void* Object, void* OutValue); \
static void SetSaturation_WrapperImpl(void* Object, const void* InValue); \
static void GetAdaptiveTintStrength_WrapperImpl(const void* Object, void* OutValue); \
static void SetAdaptiveTintStrength_WrapperImpl(void* Object, const void* InValue); \
static void GetGlassOpacity_WrapperImpl(const void* Object, void* OutValue); \
static void SetGlassOpacity_WrapperImpl(void* Object, const void* InValue); \
static void GetQuality_WrapperImpl(const void* Object, void* OutValue); \
static void SetQuality_WrapperImpl(void* Object, const void* InValue); \
static void GetMotionStrength_WrapperImpl(const void* Object, void* OutValue); \
static void SetMotionStrength_WrapperImpl(void* Object, const void* InValue); \
static void GetMotionMaxOffset_WrapperImpl(const void* Object, void* OutValue); \
static void SetMotionMaxOffset_WrapperImpl(void* Object, const void* InValue); \
static void GetMotionResponse_WrapperImpl(const void* Object, void* OutValue); \
static void SetMotionResponse_WrapperImpl(void* Object, const void* InValue); \
static void GetMotionDamping_WrapperImpl(const void* Object, void* OutValue); \
static void SetMotionDamping_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlass_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlass_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlass(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlass_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlass_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlass, UContentWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlass_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlass)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlass(UCBLiquidGlass&&) = delete; \
	UCBLiquidGlass(const UCBLiquidGlass&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlass); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlass); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlass) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlass();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_19_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlass;

// ********** End Class UCBLiquidGlass *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

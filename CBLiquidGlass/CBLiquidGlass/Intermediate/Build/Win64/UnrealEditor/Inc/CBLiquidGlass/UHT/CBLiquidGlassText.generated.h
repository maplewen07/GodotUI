// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassText.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassText_generated_h
#error "CBLiquidGlassText.generated.h already included, missing '#pragma once' in CBLiquidGlassText.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassText_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECBLiquidGlassPreset : uint8;
enum class ECBLiquidGlassQuality : uint8;
struct FSlateColor;
struct FSlateFontInfo;

// ********** Begin Class UCBLiquidGlassText *******************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetMotionStrength); \
	DECLARE_FUNCTION(execSetLineSpacing); \
	DECLARE_FUNCTION(execSetLetterSpacing); \
	DECLARE_FUNCTION(execSetGlyphThickness); \
	DECLARE_FUNCTION(execSetFrostRadius); \
	DECLARE_FUNCTION(execSetQuality); \
	DECLARE_FUNCTION(execSetPreset); \
	DECLARE_FUNCTION(execSetColorAndOpacity); \
	DECLARE_FUNCTION(execSetFont); \
	DECLARE_FUNCTION(execSetText);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_ACCESSORS \
static void GetText_WrapperImpl(const void* Object, void* OutValue); \
static void SetText_WrapperImpl(void* Object, const void* InValue); \
static void GetFont_WrapperImpl(const void* Object, void* OutValue); \
static void SetFont_WrapperImpl(void* Object, const void* InValue); \
static void GetColorAndOpacity_WrapperImpl(const void* Object, void* OutValue); \
static void SetColorAndOpacity_WrapperImpl(void* Object, const void* InValue); \
static void GetPreset_WrapperImpl(const void* Object, void* OutValue); \
static void SetPreset_WrapperImpl(void* Object, const void* InValue); \
static void GetQuality_WrapperImpl(const void* Object, void* OutValue); \
static void SetQuality_WrapperImpl(void* Object, const void* InValue); \
static void GetFrostRadius_WrapperImpl(const void* Object, void* OutValue); \
static void SetFrostRadius_WrapperImpl(void* Object, const void* InValue); \
static void GetGlyphThickness_WrapperImpl(const void* Object, void* OutValue); \
static void SetGlyphThickness_WrapperImpl(void* Object, const void* InValue); \
static void GetLetterSpacing_WrapperImpl(const void* Object, void* OutValue); \
static void SetLetterSpacing_WrapperImpl(void* Object, const void* InValue); \
static void GetLineSpacing_WrapperImpl(const void* Object, void* OutValue); \
static void SetLineSpacing_WrapperImpl(void* Object, const void* InValue); \
static void GetMotionStrength_WrapperImpl(const void* Object, void* OutValue); \
static void SetMotionStrength_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassText_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassText_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassText(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassText_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassText_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassText, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassText_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassText)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassText(UCBLiquidGlassText&&) = delete; \
	UCBLiquidGlassText(const UCBLiquidGlassText&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassText); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassText); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassText) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassText();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_21_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassText;

// ********** End Class UCBLiquidGlassText *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassText_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

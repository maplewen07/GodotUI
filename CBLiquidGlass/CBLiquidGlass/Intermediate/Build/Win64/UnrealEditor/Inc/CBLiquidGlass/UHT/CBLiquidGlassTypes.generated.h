// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassTypes.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassTypes_generated_h
#error "CBLiquidGlassTypes.generated.h already included, missing '#pragma once' in CBLiquidGlassTypes.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FCBLiquidGlassItem ************************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics;
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h_130_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FCBLiquidGlassItem_Statics; \
	static class UScriptStruct* StaticStruct();


struct FCBLiquidGlassItem;
// ********** End ScriptStruct FCBLiquidGlassItem **************************************************

// ********** Begin ScriptStruct FCBLiquidGlassSpringSettings **************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics;
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h_157_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FCBLiquidGlassSpringSettings_Statics; \
	static class UScriptStruct* StaticStruct();


struct FCBLiquidGlassSpringSettings;
// ********** End ScriptStruct FCBLiquidGlassSpringSettings ****************************************

// ********** Begin ScriptStruct FCBLiquidGlassControlStyle ****************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics;
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h_176_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FCBLiquidGlassControlStyle_Statics; \
	static class UScriptStruct* StaticStruct();


struct FCBLiquidGlassControlStyle;
// ********** End ScriptStruct FCBLiquidGlassControlStyle ******************************************

// ********** Begin ScriptStruct FCBLiquidGlassSearchBoxStyle **************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics;
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h_198_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FCBLiquidGlassSearchBoxStyle_Statics; \
	static class UScriptStruct* StaticStruct();


struct FCBLiquidGlassSearchBoxStyle;
// ********** End ScriptStruct FCBLiquidGlassSearchBoxStyle ****************************************

// ********** Begin ScriptStruct FCBLiquidGlassFusionBlob ******************************************
struct Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics;
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h_313_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FCBLiquidGlassFusionBlob_Statics; \
	static class UScriptStruct* StaticStruct();


struct FCBLiquidGlassFusionBlob;
// ********** End ScriptStruct FCBLiquidGlassFusionBlob ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassTypes_h

// ********** Begin Enum ECBLiquidGlassPreset ******************************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSPRESET(op) \
	op(ECBLiquidGlassPreset::Custom) \
	op(ECBLiquidGlassPreset::Clear) \
	op(ECBLiquidGlassPreset::Regular) \
	op(ECBLiquidGlassPreset::FrostedMenu) \
	op(ECBLiquidGlassPreset::PillLens) \
	op(ECBLiquidGlassPreset::MatteLayer) \
	op(ECBLiquidGlassPreset::SelfLayer) 

enum class ECBLiquidGlassPreset : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassPreset> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassPreset>();
// ********** End Enum ECBLiquidGlassPreset ********************************************************

// ********** Begin Enum ECBLiquidGlassShape *******************************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSSHAPE(op) \
	op(ECBLiquidGlassShape::SuperellipseRect) \
	op(ECBLiquidGlassShape::Capsule) \
	op(ECBLiquidGlassShape::Circle) \
	op(ECBLiquidGlassShape::Diamond) \
	op(ECBLiquidGlassShape::Hexagon) \
	op(ECBLiquidGlassShape::Star) \
	op(ECBLiquidGlassShape::Blob) 

enum class ECBLiquidGlassShape : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassShape> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassShape>();
// ********** End Enum ECBLiquidGlassShape *********************************************************

// ********** Begin Enum ECBLiquidGlassQuality *****************************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSQUALITY(op) \
	op(ECBLiquidGlassQuality::Performance) \
	op(ECBLiquidGlassQuality::Balanced) \
	op(ECBLiquidGlassQuality::Quality) 

enum class ECBLiquidGlassQuality : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassQuality> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassQuality>();
// ********** End Enum ECBLiquidGlassQuality *******************************************************

// ********** Begin Enum ECBLiquidGlassControlSize *************************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSCONTROLSIZE(op) \
	op(ECBLiquidGlassControlSize::Small) \
	op(ECBLiquidGlassControlSize::Medium) \
	op(ECBLiquidGlassControlSize::Large) 

enum class ECBLiquidGlassControlSize : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassControlSize> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassControlSize>();
// ********** End Enum ECBLiquidGlassControlSize ***************************************************

// ********** Begin Enum ECBLiquidGlassIconPosition ************************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSICONPOSITION(op) \
	op(ECBLiquidGlassIconPosition::Left) \
	op(ECBLiquidGlassIconPosition::Right) \
	op(ECBLiquidGlassIconPosition::Top) \
	op(ECBLiquidGlassIconPosition::Only) 

enum class ECBLiquidGlassIconPosition : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassIconPosition> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassIconPosition>();
// ********** End Enum ECBLiquidGlassIconPosition **************************************************

// ********** Begin Enum ECBLiquidGlassOrientation *************************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSORIENTATION(op) \
	op(ECBLiquidGlassOrientation::Horizontal) \
	op(ECBLiquidGlassOrientation::Vertical) 

enum class ECBLiquidGlassOrientation : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassOrientation> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassOrientation>();
// ********** End Enum ECBLiquidGlassOrientation ***************************************************

// ********** Begin Enum ECBLiquidGlassProgressStyle ***********************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSPROGRESSSTYLE(op) \
	op(ECBLiquidGlassProgressStyle::Linear) \
	op(ECBLiquidGlassProgressStyle::Circular) 

enum class ECBLiquidGlassProgressStyle : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassProgressStyle> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassProgressStyle>();
// ********** End Enum ECBLiquidGlassProgressStyle *************************************************

// ********** Begin Enum ECBLiquidGlassItemState ***************************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSITEMSTATE(op) \
	op(ECBLiquidGlassItemState::Normal) \
	op(ECBLiquidGlassItemState::Selected) \
	op(ECBLiquidGlassItemState::Disabled) \
	op(ECBLiquidGlassItemState::Danger) \
	op(ECBLiquidGlassItemState::Separator) 

enum class ECBLiquidGlassItemState : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassItemState> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassItemState>();
// ********** End Enum ECBLiquidGlassItemState *****************************************************

// ********** Begin Enum ECBLiquidGlassDialogStyle *************************************************
#define FOREACH_ENUM_ECBLIQUIDGLASSDIALOGSTYLE(op) \
	op(ECBLiquidGlassDialogStyle::Alert) \
	op(ECBLiquidGlassDialogStyle::ActionSheet) \
	op(ECBLiquidGlassDialogStyle::Sheet) 

enum class ECBLiquidGlassDialogStyle : uint8;
template<> struct TIsUEnumClass<ECBLiquidGlassDialogStyle> { enum { Value = true }; };
template<> CBLIQUIDGLASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECBLiquidGlassDialogStyle>();
// ********** End Enum ECBLiquidGlassDialogStyle ***************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

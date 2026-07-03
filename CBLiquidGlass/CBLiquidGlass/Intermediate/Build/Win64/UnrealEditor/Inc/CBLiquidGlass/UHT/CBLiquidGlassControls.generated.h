// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassControls.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassControls_generated_h
#error "CBLiquidGlassControls.generated.h already included, missing '#pragma once' in CBLiquidGlassControls.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassControls_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECBLiquidGlassOrientation : uint8;
enum class ECBLiquidGlassProgressStyle : uint8;
enum class ECBLiquidGlassQuality : uint8;
struct FCBLiquidGlassControlStyle;
struct FCBLiquidGlassItem;
struct FCBLiquidGlassSearchBoxStyle;
struct FCBLiquidGlassSpringSettings;
struct FLinearColor;
struct FMargin;

// ********** Begin Delegate FCBLiquidGlassToggleChangedEvent **************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_19_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassToggleChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassToggleChangedEvent, bool bChecked);


// ********** End Delegate FCBLiquidGlassToggleChangedEvent ****************************************

// ********** Begin Delegate FCBLiquidGlassIndexChangedEvent ***************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_20_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassIndexChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassIndexChangedEvent, int32 Index, int32 Value);


// ********** End Delegate FCBLiquidGlassIndexChangedEvent *****************************************

// ********** Begin Delegate FCBLiquidGlassItemClickedEvent ****************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_21_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassItemClickedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassItemClickedEvent, int32 Index, int32 Value);


// ********** End Delegate FCBLiquidGlassItemClickedEvent ******************************************

// ********** Begin Delegate FCBLiquidGlassTextChangedEvent ****************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_22_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassTextChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassTextChangedEvent, FText const& Text);


// ********** End Delegate FCBLiquidGlassTextChangedEvent ******************************************

// ********** Begin Delegate FCBLiquidGlassFloatChangedEvent ***************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_23_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassFloatChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassFloatChangedEvent, float Value);


// ********** End Delegate FCBLiquidGlassFloatChangedEvent *****************************************

// ********** Begin Class UCBLiquidGlassToggle *****************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetSpringSettings); \
	DECLARE_FUNCTION(execSetStyle); \
	DECLARE_FUNCTION(execSetOffColor); \
	DECLARE_FUNCTION(execSetOnColor); \
	DECLARE_FUNCTION(execSetChecked);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_ACCESSORS \
static void GetbChecked_WrapperImpl(const void* Object, void* OutValue); \
static void SetbChecked_WrapperImpl(void* Object, const void* InValue); \
static void GetOnColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetOnColor_WrapperImpl(void* Object, const void* InValue); \
static void GetOffColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetOffColor_WrapperImpl(void* Object, const void* InValue); \
static void GetStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetStyle_WrapperImpl(void* Object, const void* InValue); \
static void GetSpringSettings_WrapperImpl(const void* Object, void* OutValue); \
static void SetSpringSettings_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassToggle_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassToggle_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassToggle(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassToggle_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassToggle_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassToggle, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassToggle_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassToggle)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassToggle(UCBLiquidGlassToggle&&) = delete; \
	UCBLiquidGlassToggle(const UCBLiquidGlassToggle&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassToggle); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassToggle); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassToggle) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassToggle();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_26_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassToggle;

// ********** End Class UCBLiquidGlassToggle *******************************************************

// ********** Begin Class UCBLiquidGlassSegmentedControl *******************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetSpringSettings); \
	DECLARE_FUNCTION(execSetStyle); \
	DECLARE_FUNCTION(execSetPadding); \
	DECLARE_FUNCTION(execSetItemSize); \
	DECLARE_FUNCTION(execSetShowLabels); \
	DECLARE_FUNCTION(execSetShowIcons); \
	DECLARE_FUNCTION(execSetOrientation); \
	DECLARE_FUNCTION(execSetSelectedIndex); \
	DECLARE_FUNCTION(execSetItems);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_ACCESSORS \
static void GetItems_WrapperImpl(const void* Object, void* OutValue); \
static void SetItems_WrapperImpl(void* Object, const void* InValue); \
static void GetSelectedIndex_WrapperImpl(const void* Object, void* OutValue); \
static void SetSelectedIndex_WrapperImpl(void* Object, const void* InValue); \
static void GetOrientation_WrapperImpl(const void* Object, void* OutValue); \
static void SetOrientation_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowIcons_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowIcons_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowLabels_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowLabels_WrapperImpl(void* Object, const void* InValue); \
static void GetItemSize_WrapperImpl(const void* Object, void* OutValue); \
static void SetItemSize_WrapperImpl(void* Object, const void* InValue); \
static void GetPadding_WrapperImpl(const void* Object, void* OutValue); \
static void SetPadding_WrapperImpl(void* Object, const void* InValue); \
static void GetStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetStyle_WrapperImpl(void* Object, const void* InValue); \
static void GetSpringSettings_WrapperImpl(const void* Object, void* OutValue); \
static void SetSpringSettings_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSegmentedControl_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassSegmentedControl(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassSegmentedControl_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassSegmentedControl_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassSegmentedControl, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassSegmentedControl_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassSegmentedControl)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassSegmentedControl(UCBLiquidGlassSegmentedControl&&) = delete; \
	UCBLiquidGlassSegmentedControl(const UCBLiquidGlassSegmentedControl&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassSegmentedControl); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassSegmentedControl); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassSegmentedControl) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassSegmentedControl();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_85_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_88_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassSegmentedControl;

// ********** End Class UCBLiquidGlassSegmentedControl *********************************************

// ********** Begin Class UCBLiquidGlassTabBar *****************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetSpringSettings); \
	DECLARE_FUNCTION(execSetStyle); \
	DECLARE_FUNCTION(execSetPadding); \
	DECLARE_FUNCTION(execSetItemSize); \
	DECLARE_FUNCTION(execSetShowIcons); \
	DECLARE_FUNCTION(execSetShowLabels); \
	DECLARE_FUNCTION(execSetSelectedIndex); \
	DECLARE_FUNCTION(execSetItems);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_ACCESSORS \
static void GetItems_WrapperImpl(const void* Object, void* OutValue); \
static void SetItems_WrapperImpl(void* Object, const void* InValue); \
static void GetSelectedIndex_WrapperImpl(const void* Object, void* OutValue); \
static void SetSelectedIndex_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowLabels_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowLabels_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowIcons_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowIcons_WrapperImpl(void* Object, const void* InValue); \
static void GetItemSize_WrapperImpl(const void* Object, void* OutValue); \
static void SetItemSize_WrapperImpl(void* Object, const void* InValue); \
static void GetPadding_WrapperImpl(const void* Object, void* OutValue); \
static void SetPadding_WrapperImpl(void* Object, const void* InValue); \
static void GetStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetStyle_WrapperImpl(void* Object, const void* InValue); \
static void GetSpringSettings_WrapperImpl(const void* Object, void* OutValue); \
static void SetSpringSettings_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassTabBar_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassTabBar_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassTabBar(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassTabBar_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassTabBar_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassTabBar, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassTabBar_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassTabBar)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassTabBar(UCBLiquidGlassTabBar&&) = delete; \
	UCBLiquidGlassTabBar(const UCBLiquidGlassTabBar&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassTabBar); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassTabBar); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassTabBar) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassTabBar();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_172_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_175_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassTabBar;

// ********** End Class UCBLiquidGlassTabBar *******************************************************

// ********** Begin Class UCBLiquidGlassToolbar ****************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetStyle); \
	DECLARE_FUNCTION(execSetPadding); \
	DECLARE_FUNCTION(execSetItemSize); \
	DECLARE_FUNCTION(execSetShowLabels); \
	DECLARE_FUNCTION(execSetShowIcons); \
	DECLARE_FUNCTION(execSetSelectedIndex); \
	DECLARE_FUNCTION(execSetToggleMode); \
	DECLARE_FUNCTION(execSetOrientation); \
	DECLARE_FUNCTION(execSetItems);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_ACCESSORS \
static void GetItems_WrapperImpl(const void* Object, void* OutValue); \
static void SetItems_WrapperImpl(void* Object, const void* InValue); \
static void GetOrientation_WrapperImpl(const void* Object, void* OutValue); \
static void SetOrientation_WrapperImpl(void* Object, const void* InValue); \
static void GetbToggleMode_WrapperImpl(const void* Object, void* OutValue); \
static void SetbToggleMode_WrapperImpl(void* Object, const void* InValue); \
static void GetSelectedIndex_WrapperImpl(const void* Object, void* OutValue); \
static void SetSelectedIndex_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowIcons_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowIcons_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowLabels_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowLabels_WrapperImpl(void* Object, const void* InValue); \
static void GetItemSize_WrapperImpl(const void* Object, void* OutValue); \
static void SetItemSize_WrapperImpl(void* Object, const void* InValue); \
static void GetPadding_WrapperImpl(const void* Object, void* OutValue); \
static void SetPadding_WrapperImpl(void* Object, const void* InValue); \
static void GetStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetStyle_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassToolbar_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassToolbar_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassToolbar(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassToolbar_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassToolbar_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassToolbar, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassToolbar_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassToolbar)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassToolbar(UCBLiquidGlassToolbar&&) = delete; \
	UCBLiquidGlassToolbar(const UCBLiquidGlassToolbar&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassToolbar); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassToolbar); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassToolbar) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassToolbar();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_251_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_254_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassToolbar;

// ********** End Class UCBLiquidGlassToolbar ******************************************************

// ********** Begin Class UCBLiquidGlassMenu *******************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetStyle); \
	DECLARE_FUNCTION(execSetShowLabels); \
	DECLARE_FUNCTION(execSetShowIcons); \
	DECLARE_FUNCTION(execSetCloseOnClick); \
	DECLARE_FUNCTION(execSetItemHeight); \
	DECLARE_FUNCTION(execSetItems);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_ACCESSORS \
static void GetItems_WrapperImpl(const void* Object, void* OutValue); \
static void SetItems_WrapperImpl(void* Object, const void* InValue); \
static void GetItemHeight_WrapperImpl(const void* Object, void* OutValue); \
static void SetItemHeight_WrapperImpl(void* Object, const void* InValue); \
static void GetbCloseOnClick_WrapperImpl(const void* Object, void* OutValue); \
static void SetbCloseOnClick_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowIcons_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowIcons_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowLabels_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowLabels_WrapperImpl(void* Object, const void* InValue); \
static void GetStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetStyle_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassMenu_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassMenu_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassMenu(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassMenu_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassMenu_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassMenu, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassMenu_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassMenu)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassMenu(UCBLiquidGlassMenu&&) = delete; \
	UCBLiquidGlassMenu(const UCBLiquidGlassMenu&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassMenu); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassMenu) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassMenu();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_338_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_341_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassMenu;

// ********** End Class UCBLiquidGlassMenu *********************************************************

// ********** Begin Class UCBLiquidGlassSearchBar **************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetSearchBoxStyle); \
	DECLARE_FUNCTION(execSetStyle); \
	DECLARE_FUNCTION(execSetShowText); \
	DECLARE_FUNCTION(execSetShowSearchIcon); \
	DECLARE_FUNCTION(execSetShowClearButton); \
	DECLARE_FUNCTION(execSetHintText); \
	DECLARE_FUNCTION(execSetText);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_ACCESSORS \
static void GetText_WrapperImpl(const void* Object, void* OutValue); \
static void SetText_WrapperImpl(void* Object, const void* InValue); \
static void GetHintText_WrapperImpl(const void* Object, void* OutValue); \
static void SetHintText_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowClearButton_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowClearButton_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowSearchIcon_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowSearchIcon_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowText_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowText_WrapperImpl(void* Object, const void* InValue); \
static void GetStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetStyle_WrapperImpl(void* Object, const void* InValue); \
static void GetSearchBoxStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetSearchBoxStyle_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassSearchBar_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassSearchBar(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassSearchBar_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassSearchBar_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassSearchBar, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassSearchBar_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassSearchBar)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassSearchBar(UCBLiquidGlassSearchBar&&) = delete; \
	UCBLiquidGlassSearchBar(const UCBLiquidGlassSearchBar&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassSearchBar); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassSearchBar); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassSearchBar) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassSearchBar();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_405_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_408_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassSearchBar;

// ********** End Class UCBLiquidGlassSearchBar ****************************************************

// ********** Begin Class UCBLiquidGlassProgress ***************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetQuality); \
	DECLARE_FUNCTION(execSetGlassOpacity); \
	DECLARE_FUNCTION(execSetPrismIntensity); \
	DECLARE_FUNCTION(execSetRefractionStrength); \
	DECLARE_FUNCTION(execSetFrostRadius); \
	DECLARE_FUNCTION(execSetBlurStrength); \
	DECLARE_FUNCTION(execSetTextColor); \
	DECLARE_FUNCTION(execSetShowPercentText); \
	DECLARE_FUNCTION(execSetTrackOpacity); \
	DECLARE_FUNCTION(execSetTrackColor); \
	DECLARE_FUNCTION(execSetEndCapSize); \
	DECLARE_FUNCTION(execSetCircularSize); \
	DECLARE_FUNCTION(execSetLinearSize); \
	DECLARE_FUNCTION(execSetThickness); \
	DECLARE_FUNCTION(execSetFillColor); \
	DECLARE_FUNCTION(execSetProgressStyle); \
	DECLARE_FUNCTION(execSetValue);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_ACCESSORS \
static void GetValue_WrapperImpl(const void* Object, void* OutValue); \
static void SetValue_WrapperImpl(void* Object, const void* InValue); \
static void GetProgressStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetProgressStyle_WrapperImpl(void* Object, const void* InValue); \
static void GetFillColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetFillColor_WrapperImpl(void* Object, const void* InValue); \
static void GetThickness_WrapperImpl(const void* Object, void* OutValue); \
static void SetThickness_WrapperImpl(void* Object, const void* InValue); \
static void GetLinearSize_WrapperImpl(const void* Object, void* OutValue); \
static void SetLinearSize_WrapperImpl(void* Object, const void* InValue); \
static void GetCircularSize_WrapperImpl(const void* Object, void* OutValue); \
static void SetCircularSize_WrapperImpl(void* Object, const void* InValue); \
static void GetEndCapSize_WrapperImpl(const void* Object, void* OutValue); \
static void SetEndCapSize_WrapperImpl(void* Object, const void* InValue); \
static void GetTrackColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetTrackColor_WrapperImpl(void* Object, const void* InValue); \
static void GetTrackOpacity_WrapperImpl(const void* Object, void* OutValue); \
static void SetTrackOpacity_WrapperImpl(void* Object, const void* InValue); \
static void GetbShowPercentText_WrapperImpl(const void* Object, void* OutValue); \
static void SetbShowPercentText_WrapperImpl(void* Object, const void* InValue); \
static void GetTextColor_WrapperImpl(const void* Object, void* OutValue); \
static void SetTextColor_WrapperImpl(void* Object, const void* InValue); \
static void GetBlurStrength_WrapperImpl(const void* Object, void* OutValue); \
static void SetBlurStrength_WrapperImpl(void* Object, const void* InValue); \
static void GetFrostRadius_WrapperImpl(const void* Object, void* OutValue); \
static void SetFrostRadius_WrapperImpl(void* Object, const void* InValue); \
static void GetRefractionStrength_WrapperImpl(const void* Object, void* OutValue); \
static void SetRefractionStrength_WrapperImpl(void* Object, const void* InValue); \
static void GetPrismIntensity_WrapperImpl(const void* Object, void* OutValue); \
static void SetPrismIntensity_WrapperImpl(void* Object, const void* InValue); \
static void GetGlassOpacity_WrapperImpl(const void* Object, void* OutValue); \
static void SetGlassOpacity_WrapperImpl(void* Object, const void* InValue); \
static void GetQuality_WrapperImpl(const void* Object, void* OutValue); \
static void SetQuality_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassProgress_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassProgress_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassProgress(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassProgress_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassProgress_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassProgress, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassProgress_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassProgress)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassProgress(UCBLiquidGlassProgress&&) = delete; \
	UCBLiquidGlassProgress(const UCBLiquidGlassProgress&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassProgress); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassProgress); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassProgress) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassProgress();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_482_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_485_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassProgress;

// ********** End Class UCBLiquidGlassProgress *****************************************************

// ********** Begin Class UCBLiquidGlassStepper ****************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetStyle); \
	DECLARE_FUNCTION(execSetIntegerOnly); \
	DECLARE_FUNCTION(execSetStep); \
	DECLARE_FUNCTION(execSetMaxValue); \
	DECLARE_FUNCTION(execSetMinValue); \
	DECLARE_FUNCTION(execSetValue);


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_ACCESSORS \
static void GetValue_WrapperImpl(const void* Object, void* OutValue); \
static void SetValue_WrapperImpl(void* Object, const void* InValue); \
static void GetMinValue_WrapperImpl(const void* Object, void* OutValue); \
static void SetMinValue_WrapperImpl(void* Object, const void* InValue); \
static void GetMaxValue_WrapperImpl(const void* Object, void* OutValue); \
static void SetMaxValue_WrapperImpl(void* Object, const void* InValue); \
static void GetStep_WrapperImpl(const void* Object, void* OutValue); \
static void SetStep_WrapperImpl(void* Object, const void* InValue); \
static void GetbIntegerOnly_WrapperImpl(const void* Object, void* OutValue); \
static void SetbIntegerOnly_WrapperImpl(void* Object, const void* InValue); \
static void GetStyle_WrapperImpl(const void* Object, void* OutValue); \
static void SetStyle_WrapperImpl(void* Object, const void* InValue);


struct Z_Construct_UClass_UCBLiquidGlassStepper_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassStepper_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassStepper(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassStepper_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassStepper_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassStepper, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassStepper_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassStepper)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassStepper(UCBLiquidGlassStepper&&) = delete; \
	UCBLiquidGlassStepper(const UCBLiquidGlassStepper&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassStepper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassStepper); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassStepper) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassStepper();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_622_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_ACCESSORS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h_625_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassStepper;

// ********** End Class UCBLiquidGlassStepper ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassControls_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

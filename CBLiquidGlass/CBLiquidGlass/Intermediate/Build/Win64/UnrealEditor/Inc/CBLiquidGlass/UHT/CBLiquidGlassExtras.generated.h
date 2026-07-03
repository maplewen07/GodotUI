// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CBLiquidGlassExtras.h"

#ifdef CBLIQUIDGLASS_CBLiquidGlassExtras_generated_h
#error "CBLiquidGlassExtras.generated.h already included, missing '#pragma once' in CBLiquidGlassExtras.h"
#endif
#define CBLIQUIDGLASS_CBLiquidGlassExtras_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECBLiquidGlassPreset : uint8;
enum class ECBLiquidGlassQuality : uint8;
struct FCBLiquidGlassFusionBlob;
struct FCBLiquidGlassItem;
struct FLinearColor;

// ********** Begin Delegate FCBLiquidGlassPageChangedEvent ****************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_17_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassPageChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassPageChangedEvent, int32 PageIndex);


// ********** End Delegate FCBLiquidGlassPageChangedEvent ******************************************

// ********** Begin Delegate FCBLiquidGlassSimpleEvent *********************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_18_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassSimpleEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassSimpleEvent);


// ********** End Delegate FCBLiquidGlassSimpleEvent ***********************************************

// ********** Begin Delegate FCBLiquidGlassActionEvent *********************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_19_DELEGATE \
CBLIQUIDGLASS_API void FCBLiquidGlassActionEvent_DelegateWrapper(const FMulticastScriptDelegate& CBLiquidGlassActionEvent, int32 Index, int32 Value);


// ********** End Delegate FCBLiquidGlassActionEvent ***********************************************

// ********** Begin Class UCBLiquidGlassBadge ******************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetColor); \
	DECLARE_FUNCTION(execSetDotMode); \
	DECLARE_FUNCTION(execSetMaxCount); \
	DECLARE_FUNCTION(execSetCount);


struct Z_Construct_UClass_UCBLiquidGlassBadge_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassBadge_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassBadge(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassBadge_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassBadge_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassBadge, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassBadge_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassBadge)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassBadge(UCBLiquidGlassBadge&&) = delete; \
	UCBLiquidGlassBadge(const UCBLiquidGlassBadge&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassBadge); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassBadge); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassBadge) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassBadge();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_22_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_25_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassBadge;

// ********** End Class UCBLiquidGlassBadge ********************************************************

// ********** Begin Class UCBLiquidGlassPageControl ************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_73_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetCurrentPage); \
	DECLARE_FUNCTION(execSetNumPages);


struct Z_Construct_UClass_UCBLiquidGlassPageControl_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassPageControl_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_73_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassPageControl(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassPageControl_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassPageControl_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassPageControl, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassPageControl_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassPageControl)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_73_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassPageControl(UCBLiquidGlassPageControl&&) = delete; \
	UCBLiquidGlassPageControl(const UCBLiquidGlassPageControl&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassPageControl); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassPageControl); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassPageControl) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassPageControl();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_70_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_73_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_73_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_73_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_73_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassPageControl;

// ********** End Class UCBLiquidGlassPageControl **************************************************

// ********** Begin Class UCBLiquidGlassNavigationBar **********************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_124_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetTrailingItems); \
	DECLARE_FUNCTION(execSetLargeTitle); \
	DECLARE_FUNCTION(execSetShowBackButton); \
	DECLARE_FUNCTION(execSetTitle);


struct Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassNavigationBar_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_124_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassNavigationBar(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassNavigationBar_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassNavigationBar_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassNavigationBar, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassNavigationBar_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassNavigationBar)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_124_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassNavigationBar(UCBLiquidGlassNavigationBar&&) = delete; \
	UCBLiquidGlassNavigationBar(const UCBLiquidGlassNavigationBar&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassNavigationBar); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassNavigationBar); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassNavigationBar) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassNavigationBar();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_121_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_124_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_124_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_124_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_124_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassNavigationBar;

// ********** End Class UCBLiquidGlassNavigationBar ************************************************

// ********** Begin Class UCBLiquidGlassDialog *****************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_175_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetCardGlassOpacity); \
	DECLARE_FUNCTION(execSetCardRimIntensity); \
	DECLARE_FUNCTION(execSetCardPrismIntensity); \
	DECLARE_FUNCTION(execSetCardRefractionThickness); \
	DECLARE_FUNCTION(execSetCardRefractionStrength); \
	DECLARE_FUNCTION(execSetCardFrostRadius); \
	DECLARE_FUNCTION(execSetCardBlurStrength); \
	DECLARE_FUNCTION(execSetDimOpacity); \
	DECLARE_FUNCTION(execSetDimBackground); \
	DECLARE_FUNCTION(execSetButtons); \
	DECLARE_FUNCTION(execSetMessage); \
	DECLARE_FUNCTION(execSetTitle); \
	DECLARE_FUNCTION(execDismiss); \
	DECLARE_FUNCTION(execPresent);


struct Z_Construct_UClass_UCBLiquidGlassDialog_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassDialog_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_175_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassDialog(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassDialog_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassDialog_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassDialog, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassDialog_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassDialog)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_175_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassDialog(UCBLiquidGlassDialog&&) = delete; \
	UCBLiquidGlassDialog(const UCBLiquidGlassDialog&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassDialog); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassDialog); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassDialog) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassDialog();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_172_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_175_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_175_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_175_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_175_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassDialog;

// ********** End Class UCBLiquidGlassDialog *******************************************************

// ********** Begin Class UCBLiquidGlassContainer **************************************************
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_272_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetQuality); \
	DECLARE_FUNCTION(execSetPreset); \
	DECLARE_FUNCTION(execSetGlassOpacity); \
	DECLARE_FUNCTION(execSetRimIntensity); \
	DECLARE_FUNCTION(execSetPrismIntensity); \
	DECLARE_FUNCTION(execSetRefractionThickness); \
	DECLARE_FUNCTION(execSetRefractionStrength); \
	DECLARE_FUNCTION(execSetFrostRadius); \
	DECLARE_FUNCTION(execSetBlurStrength); \
	DECLARE_FUNCTION(execSetMaskResolution); \
	DECLARE_FUNCTION(execSetCanvasSize); \
	DECLARE_FUNCTION(execSetSmoothing); \
	DECLARE_FUNCTION(execSetBlobs);


struct Z_Construct_UClass_UCBLiquidGlassContainer_Statics;
CBLIQUIDGLASS_API UClass* Z_Construct_UClass_UCBLiquidGlassContainer_NoRegister();

#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_272_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCBLiquidGlassContainer(); \
	friend struct ::Z_Construct_UClass_UCBLiquidGlassContainer_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CBLIQUIDGLASS_API UClass* ::Z_Construct_UClass_UCBLiquidGlassContainer_NoRegister(); \
public: \
	DECLARE_CLASS2(UCBLiquidGlassContainer, UContentWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CBLiquidGlass"), Z_Construct_UClass_UCBLiquidGlassContainer_NoRegister) \
	DECLARE_SERIALIZER(UCBLiquidGlassContainer)


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_272_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCBLiquidGlassContainer(UCBLiquidGlassContainer&&) = delete; \
	UCBLiquidGlassContainer(const UCBLiquidGlassContainer&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CBLIQUIDGLASS_API, UCBLiquidGlassContainer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCBLiquidGlassContainer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCBLiquidGlassContainer) \
	CBLIQUIDGLASS_API virtual ~UCBLiquidGlassContainer();


#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_269_PROLOG
#define FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_272_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_272_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_272_INCLASS_NO_PURE_DECLS \
	FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h_272_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCBLiquidGlassContainer;

// ********** End Class UCBLiquidGlassContainer ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CBEngine57_Plugins_CBLiquidGlass_Source_CBLiquidGlass_Public_CBLiquidGlassExtras_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

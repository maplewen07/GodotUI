// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/** Runtime module that registers plugin shader paths for the Slate liquid glass renderer. */
class FCBLiquidGlassModule : public IModuleInterface
{
public:

	/** Registers shader source directory mappings before global shaders compile. */
	virtual void StartupModule() override;

	/** No persistent resources are held by the module after startup. */
	virtual void ShutdownModule() override;
};

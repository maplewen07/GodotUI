// Copyright 2026-Present SteveSantoso. All Rights Reserved.

#include "CBLiquidGlass.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"

#define LOCTEXT_NAMESPACE "FCBLiquidGlassModule"

void FCBLiquidGlassModule::StartupModule()
{
	// Map the plugin's virtual shader directory so the liquid glass global shaders can be found.
	// Done in StartupModule (PostConfigInit phase) so the mapping exists before global shaders compile.
	const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("CBLiquidGlass"));
	if (Plugin.IsValid())
	{
		const FString PluginShaderDir = FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shaders"));
		AddShaderSourceDirectoryMapping(TEXT("/Plugin/CBLiquidGlass"), PluginShaderDir);
	}
}

void FCBLiquidGlassModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCBLiquidGlassModule, CBLiquidGlass)
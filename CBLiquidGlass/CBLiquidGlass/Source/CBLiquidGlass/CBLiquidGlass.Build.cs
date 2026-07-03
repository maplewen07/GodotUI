// Copyright 2026-Present SteveSantoso. All Rights Reserved.

using UnrealBuildTool;

public class CBLiquidGlass : ModuleRules
{
	public CBLiquidGlass(ReadOnlyTargetRules Target) : base(Target)
	{
		// The plugin exposes UMG types but implements the effect through custom Slate/RDG rendering.
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		// Public because game code and Blueprints include the UMG widget headers.
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"SlateCore",
				"UMG",
			}
			);

		// Private render dependencies are only needed by the Slate element and global shaders.
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"InputCore",
				"RHI",
				"RenderCore",
				"Projects",
			}
			);
	}
}

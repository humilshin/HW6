// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HW6 : ModuleRules
{
	public HW6(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

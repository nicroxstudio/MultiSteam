// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class MultiBrainCloudServerTarget : TargetRules
{
    public MultiBrainCloudServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		BuildEnvironment = TargetBuildEnvironment.Shared;
		ExtraModuleNames.Add("MultiBrainCloud");
	}
}

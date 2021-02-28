// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MultiBrainCloudGameMode.h"
#include "MultiBrainCloudCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiBrainCloudGameMode::AMultiBrainCloudGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

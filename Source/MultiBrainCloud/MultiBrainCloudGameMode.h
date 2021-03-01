// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BrainCloudS2S.h"
#include "GameFramework/GameModeBase.h"
#include "MultiBrainCloudGameMode.generated.h"

UCLASS(minimalapi)
class AMultiBrainCloudGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMultiBrainCloudGameMode();

protected:
	virtual void Tick(float DeltaSeconds);

private:
	TSharedPtr<UBrainCloudS2S> pS2S;
};




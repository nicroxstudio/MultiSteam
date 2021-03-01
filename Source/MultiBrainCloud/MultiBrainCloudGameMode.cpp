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

	if (GetNetMode() == NM_DedicatedServer) // Make sure we are dedicated
	{
		// Load environment variables passed in by brainCloud to our container.
		auto appId =
			FGenericPlatformMisc::GetEnvironmentVariable(TEXT("APP_ID"));
		auto serverName =
			FGenericPlatformMisc::GetEnvironmentVariable(TEXT("SERVER_NAME"));
		auto serverSecret =
			FGenericPlatformMisc::GetEnvironmentVariable(TEXT("SERVER_SECRET"));
		auto lobbyId =
			FGenericPlatformMisc::GetEnvironmentVariable(TEXT("LOBBY_ID"));

		// Create S2S context
		pS2S = MakeShareable(new UBrainCloudS2S(appId,
			serverName,
			serverSecret));

		// Verbose log
		pS2S->setLogEnabled(true);

		// Start tick function so we can update the S2S lib
		PrimaryActorTick.bCanEverTick = true;

		// Request Lobby data.
		// Check out S2S Explorer in the portal to know more about calls that
		// can be done.
		pS2S->request("{\"service\":\"lobby\",\"operation\":\"GET_LOBBY_DATA\",\"data\":{\"lobbyId\":\"" + lobbyId + "\"}}",
			[this, lobbyId](const FString &result)
		{
			// ... Do server setup, decode result json, 
			// cache user/passcode for validation, etc.

			// Notify brainCloud that our server is ready
			pS2S->request("{\"service\":\"lobby\",\"operation\":\"SYS_ROOM_READY\",\"data\":{\"lobbyId\":\"" + lobbyId + "\"}}", nullptr);
		});
	}
}

// Update the S2S library inside our Tick callback.
void AMultiBrainCloudGameMode::Tick(float DeltaSeconds)
{
	pS2S->runCallbacks();
}


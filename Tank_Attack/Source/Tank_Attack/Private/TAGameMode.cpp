// Fill out your copyright notice in the Description page of Project Settings.

#include "TAGameMode.h"
#include "TAGameState.h"
#include "TAPlayerState.h"
#include "TAPlayerController.h"

void ATAGameMode::PostLogin(APlayerController* NewPlayer)
{
	ATAPlayerState* playerState = Cast<ATAPlayerState>(NewPlayer->PlayerState);
	FName PlayerNameID = FName(PlayerName.Append(FString::FromInt(PlayerID)));

	if (IsValid(playerState))
	{
		playerState->SetPlayerID(PlayerNameID);
		++PlayerID;
	}

	ATAPlayerController* playerController = Cast<ATAPlayerController>(NewPlayer);

	if (IsValid(playerController))
	{
		playerController->SpawnVehicle();
	}

	ATAGameState* gameState = Cast<ATAGameState>(GameState);

	if (IsValid(gameState))
	{
		gameState->UpdateScore(PlayerNameID);
	}
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "TAGameMode.h"
#include "TAGameState.h"
#include "TAPlayerState.h"
#include "TAPlayerController.h"

void ATAGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (HasAuthority())
	{
		ATAPlayerState* playerState = Cast<ATAPlayerState>(NewPlayer->PlayerState);
		FName PlayerNameID = FName(PlayerName + (FString::FromInt(PlayerID)));

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
}

void ATAGameMode::OnHit(APawn* Source, APawn* Target)
{
	ATAVehicleAIController* SourceAIController = Cast<ATAVehicleAIController>(Source->Controller);
	ATAVehicleAIController* TargetAIController = Cast<ATAVehicleAIController>(Target->Controller);
	ATAPlayerController* SourcePlayerController = Cast<ATAPlayerController>(SourceAIController->Owner);
	ATAPlayerController* TargetPlayerController = Cast<ATAPlayerController>(TargetAIController->Owner);
	ATAPlayerState* SourcePlayerState = Cast<ATAPlayerState>(SourcePlayerController->PlayerState);

	ATAGameState* gameState = Cast<ATAGameState>(GameState);

	if (IsValid(gameState))
	{
		gameState->UpdateScore(SourcePlayerState->GetPlayerID());
	}

	TargetPlayerController->ResetVehicle();
}
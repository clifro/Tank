// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TAGameState.generated.h"

USTRUCT(BlueprintType)
struct FScoreData
{
	GENERATED_BODY()

	FName PlayerID{ "" };
	int Score{ 0 };
};

UCLASS()
class TANK_ATTACK_API ATAGameState : public AGameState
{
	GENERATED_BODY()
	
private:
	TArray<FScoreData> PlayerScores;
public:
	void UpdateScore(FName PlayerID);
};

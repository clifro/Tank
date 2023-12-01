// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Net/UnrealNetwork.h"
#include "TAGameState.generated.h"

USTRUCT(BlueprintType)
struct FScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FName PlayerID{ "" };

	UPROPERTY(BlueprintReadWrite)
	int Score{ 0 };
};

UCLASS()
class TANK_ATTACK_API ATAGameState : public AGameState
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing = OnRep_ScoresUpdated, BlueprintReadWrite)
	TArray<FScoreData> PlayerScores;

	UFUNCTION()
	void UpdateScore(FName PlayerID);

	UFUNCTION()
	void OnRep_ScoresUpdated(TArray<FScoreData> prevScores);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateScoreUI();
};

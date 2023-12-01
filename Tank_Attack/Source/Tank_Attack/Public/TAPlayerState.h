// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "TAPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TANK_ATTACK_API ATAPlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	FName PlayerID;
public:

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
	int PlayerScore;

	FORCEINLINE void SetPlayerID(FName InPlayerID) { PlayerID = InPlayerID; }
	FORCEINLINE FName GetPlayerID() { return PlayerID; }
};

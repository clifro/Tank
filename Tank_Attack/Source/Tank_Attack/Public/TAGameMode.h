// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TAGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TANK_ATTACK_API ATAGameMode : public AGameMode
{
	GENERATED_BODY()
	
private:
	int PlayerID{ 1 };
	FString PlayerName{ "Player_" };
public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};

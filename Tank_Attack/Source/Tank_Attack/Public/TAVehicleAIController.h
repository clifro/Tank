// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TAVehicleAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_ATTACK_API ATAVehicleAIController : public AAIController
{
	GENERATED_BODY()
private:
	
public:
	UPROPERTY(BlueprintReadWrite)
	FVector Location;
	FORCEINLINE void SetLocation(FVector destination) { Location = destination; }
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float inDeltaTime) override;
};

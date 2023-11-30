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
public:
	virtual void OnPossess(APawn* InPawn) override;
};

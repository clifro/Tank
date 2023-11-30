// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TAVehicleAIController.h"
#include "TAVehicleBase.h"
#include "Net/UnrealNetwork.h"
#include "TAPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_ATTACK_API ATAPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATAPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UPROPERTY(EditDefaultsOnly)
	UClass* VehicleClass;

	UPROPERTY(EditDefaultsOnly)
	UClass* VehicleAIControllerClass;
	
	UFUNCTION()
	void SpawnVehicle();

	UFUNCTION()
	void ResetVehicle();

	UPROPERTY(Replicated)
	ATAVehicleAIController* VehicleAIController;

private:

	UPROPERTY()
	ATAVehicleBase* Vehicle;
};

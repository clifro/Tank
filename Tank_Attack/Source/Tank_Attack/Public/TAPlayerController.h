// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TAVehicleAIController.h"
#include "TAVehicleBase.h"
#include "TACamera.h"
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

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	virtual void SetupInputComponent() override;

	void Fire();

	void Move();

	UPROPERTY(EditDefaultsOnly)
	UClass* VehicleClass;

	UPROPERTY(EditDefaultsOnly)
	UClass* VehicleAIControllerClass;

	UPROPERTY(EditDefaultsOnly)
	UClass* CameraClass;

	UFUNCTION(Server, Reliable)
	void Server_SetDestination(FVector location);

	UFUNCTION(Server, Reliable)
	void Server_Fire();
	
	UFUNCTION()
	void SpawnVehicle();

	UFUNCTION()
	FVector GetRandomLocation();

	UFUNCTION()
	void SpawnCamera();

	UFUNCTION()
	void ResetVehicle();

	UPROPERTY(Replicated)
	ATAVehicleAIController* VehicleAIController;

	UPROPERTY()
	ATACamera* CameraRef;

	UPROPERTY(ReplicatedUsing = OnRep_VehicleSpawned)
	ATAVehicleBase* Vehicle;

	UFUNCTION()
	void OnRep_VehicleSpawned(ATAVehicleBase* prevVehicle);

	virtual void Tick(float DeltaTime) override;
private:
};

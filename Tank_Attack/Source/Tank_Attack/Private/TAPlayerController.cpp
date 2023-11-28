// Fill out your copyright notice in the Description page of Project Settings.


#include "TAPlayerController.h"
#include "Net/UnrealNetwork.h"

ATAPlayerController::ATAPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;
}

void ATAPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATAPlayerController, Owner);
	DOREPLIFETIME_CONDITION(ATAPlayerController, VehicleAIController, COND_OwnerOnly);
}

void ATAPlayerController::SpawnVehicle()
{
	if (!IsValid(VehicleAIController))
	{
		VehicleAIController = GetWorld()->SpawnActor<ATAVehicleAIController>(VehicleAIControllerClass);
	}

	if (!IsValid(Vehicle))
	{
		FActorSpawnParameters spawnParams;
		spawnParams.Instigator = nullptr;
		spawnParams.Owner = this;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		FTransform VehicleTransform;
		VehicleTransform.SetLocation(FVector::Zero());
		Vehicle = GetWorld()->SpawnActor<ATAVehicleBase>(VehicleClass, VehicleTransform, spawnParams);
		VehicleAIController->Possess(Vehicle);
	}
}

void ATAPlayerController::ResetVehicle()
{
	if (IsValid(Vehicle))
	{
		Vehicle->SetActorLocation(FVector::Zero());
	}
}
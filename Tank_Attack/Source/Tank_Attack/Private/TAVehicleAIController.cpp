// Fill out your copyright notice in the Description page of Project Settings.


#include "TAVehicleAIController.h"

void ATAVehicleAIController::OnPossess(APawn* InPawn)
{

}

void ATAVehicleAIController::Tick(float inDeltaTime)
{
	Super::Tick(inDeltaTime);

	if (HasAuthority())
	{
		MoveToLocation(Location);
	}
}
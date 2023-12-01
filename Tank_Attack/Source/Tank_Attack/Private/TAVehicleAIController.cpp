// Fill out your copyright notice in the Description page of Project Settings.


#include "TAVehicleAIController.h"

//void ATAVehicleAIController::OnPossess(APawn* InPawn)
//{
//	Super::OnPossess(InPawn);
//
//	if (GetPawn())
//	{
//		Location = FVector(-1200, 0, 30);// GetPawn()->GetActorLocation();
//	}
//}

void ATAVehicleAIController::Tick(float inDeltaTime)
{
	Super::Tick(inDeltaTime);

	if (HasAuthority())
	{
		MoveToLocation(Location);
	}
}
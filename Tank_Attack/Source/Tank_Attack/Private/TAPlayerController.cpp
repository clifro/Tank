// Fill out your copyright notice in the Description page of Project Settings.


#include "TAPlayerController.h"

ATAPlayerController::ATAPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;
}

void ATAPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	//Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATAPlayerController, Owner);
	DOREPLIFETIME_CONDITION(ATAPlayerController, VehicleAIController, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(ATAPlayerController, Vehicle, COND_OwnerOnly);
}

void ATAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ATAPlayerController::Fire);
	InputComponent->BindAction("Move", EInputEvent::IE_Pressed, this, &ATAPlayerController::Move);
}

void ATAPlayerController::Fire()
{

}

void ATAPlayerController::Move()
{
	FHitResult hitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, hitResult);

	if (hitResult.bBlockingHit)
	{
		Server_SetDestination(hitResult.Location);
	}
}

void ATAPlayerController::Server_SetDestination_Implementation(FVector location)
{
	if (IsValid(VehicleAIController))
	{
		VehicleAIController->SetLocation(location);
	}
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

void ATAPlayerController::OnRep_VehicleSpawned(ATAVehicleBase* prevVehicle)
{
	if (IsLocalController())
	{
		SpawnCamera();
	}
}

void ATAPlayerController::SpawnCamera()
{
	if (!IsValid(CameraRef))
	{
		CameraRef = GetWorld()->SpawnActor<ATACamera>(CameraClass);
		SetViewTarget(CameraRef);
	}
}

void ATAPlayerController::ResetVehicle()
{
	if (IsValid(Vehicle))
	{
		Vehicle->SetActorLocation(FVector::Zero());
	}
}

void ATAPlayerController::Tick(float DeltaTime)
{
   	if (IsLocalController() && IsValid(CameraRef) && IsValid(Vehicle))
	{
		CameraRef->SetActorLocation(Vehicle->GetActorLocation());
	}
}
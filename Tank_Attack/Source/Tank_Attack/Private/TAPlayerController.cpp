// Fill out your copyright notice in the Description page of Project Settings.


#include "TAPlayerController.h"
#include "TAFireInterface.h"

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

	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ATAPlayerController::Server_Fire);
	InputComponent->BindAction("Move", EInputEvent::IE_Pressed, this, &ATAPlayerController::Move);
}

void ATAPlayerController::Fire()
{
	if (IsValid(Vehicle))
	{
		ITAFireInterface* FireInterface = Cast<ITAFireInterface>(Vehicle);

		if (FireInterface)
		{
			FireInterface->Fire(this);
		}
	}
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

void ATAPlayerController::Server_Fire_Implementation()
{
	Fire();
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
	FVector NewLocation = GetRandomLocation();

	if (!IsValid(Vehicle))
	{
		FActorSpawnParameters spawnParams;
		spawnParams.Instigator = nullptr;
		spawnParams.Owner = this;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		FTransform VehicleTransform;
		VehicleTransform.SetLocation(NewLocation);
		Vehicle = GetWorld()->SpawnActor<ATAVehicleBase>(VehicleClass, VehicleTransform, spawnParams);
	}

	if (!IsValid(VehicleAIController))
	{
		FActorSpawnParameters spawnParams;
		spawnParams.Instigator = nullptr;
		spawnParams.Owner = this;
		FTransform VehicleTransform;
		VehicleTransform.SetLocation(NewLocation);
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		VehicleAIController = GetWorld()->SpawnActor<ATAVehicleAIController>(VehicleAIControllerClass, VehicleTransform, spawnParams);
	}

	VehicleAIController->SetLocation(NewLocation);
	VehicleAIController->Possess(Vehicle);
}

FVector ATAPlayerController::GetRandomLocation()
{
	float X_location = FMath::RandRange(25, -1200);
	float Y_location = FMath::RandRange(-1700, 1700);
	return FVector(X_location, Y_location, 30);
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
		FVector NewLocation = GetRandomLocation();
		VehicleAIController->SetLocation(NewLocation);
		Vehicle->SetActorLocation(NewLocation);
		Vehicle->SetActorRotation(FQuat::Identity);
	}
}

void ATAPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

   	if (IsLocalController() && IsValid(CameraRef) && IsValid(Vehicle))
	{
		CameraRef->SetActorLocation(Vehicle->GetActorLocation());
	}
}
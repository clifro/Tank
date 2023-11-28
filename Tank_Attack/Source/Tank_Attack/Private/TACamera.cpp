// Fill out your copyright notice in the Description page of Project Settings.


#include "TACamera.h"

// Sets default values
ATACamera::ATACamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATACamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATACamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


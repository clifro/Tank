// Fill out your copyright notice in the Description page of Project Settings.


#include "TATank.h"
#include "Engine/World.h"


void ATATank::Fire(AController* OwningController)
{
	FActorSpawnParameters spawnParams;
	spawnParams.Instigator = this;
	spawnParams.Owner = OwningController;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ATAProjectile* projectile = GetWorld()->SpawnActor<ATAProjectile>(ProjectileClass, GetTurretTransform(), spawnParams);
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TAVehicleBase.h"
#include "TAFireInterface.h"
#include "TAProjectile.h"
#include "TATank.generated.h"

/**
 * 
 */
UCLASS()
class TANK_ATTACK_API ATATank : public ATAVehicleBase, public ITAFireInterface
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	UClass* ProjectileClass;

	UFUNCTION(BlueprintImplementableEvent)
	FTransform GetTurretTransform();

	UFUNCTION()
	virtual void Fire(AController* OwningController) override;
};

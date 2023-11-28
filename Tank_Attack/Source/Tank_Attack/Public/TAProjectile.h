// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TAProjectile.generated.h"

UCLASS()
class TANK_ATTACK_API ATAProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATAProjectile();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ProjectileMeshComponent;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereColliderComponent;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* ProjectileMoveComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

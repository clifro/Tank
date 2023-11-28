// Fill out your copyright notice in the Description page of Project Settings.


#include "TAProjectile.h"

// Sets default values
ATAProjectile::ATAProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	SetRootComponent(ProjectileMeshComponent);
	ProjectileMeshComponent->SetIsReplicated(true);
	SphereColliderComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollider"));
	SphereColliderComponent->SetupAttachment(RootComponent);
	ProjectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMove"));
}

// Called when the game starts or when spawned
void ATAProjectile::BeginPlay()
{
	Super::BeginPlay();

	SphereColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ATAProjectile::OnBeginOverlap);
	
}

// Called every frame
void ATAProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATAProjectile::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT(" COLLIDED "));
}


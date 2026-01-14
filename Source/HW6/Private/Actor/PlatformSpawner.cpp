// Fill out your copyright notice in the Description page of Project Settings.
#include "Actor/PlatformSpawner.h"
#include "Actor/MovingPlatform.h"
#include "Actor/RotatingPlatform.h"

// Sets default values
APlatformSpawner::APlatformSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (!World) return;
	
	// MovingPlatform Spawn
	for (int32 i = 0; i < MovingPlatformSpawnCount; i++)
	{
		FVector SpawnLocation = FVector(
			FMath::RandRange(MinSpawnRange.X, MaxSpawnRange.X),
			FMath::RandRange(MinSpawnRange.Y, MaxSpawnRange.Y),
			FMath::RandRange(MinSpawnRange.Z, MaxSpawnRange.Z)
		);
		
		FVector RandomDirection = FVector(
		FMath::RandRange(-1.f, 1.f),
		FMath::RandRange(-1.f, 1.f),
		0.f
		).GetSafeNormal();
		
		float RandomVelocity = FMath::RandRange(500.f, 1500.f);
		
		FRotator SpawnRotation(0.f, 0.f, 0.f);
		
		AMovingPlatform* SpawnedMovingPlatform = World->SpawnActor<AMovingPlatform>(MovingPlatformClass, SpawnLocation, SpawnRotation);

		SpawnedMovingPlatform->MoveSpeed = RandomDirection * RandomVelocity;
		SpawnedMovingPlatform->MaxRange = FMath::RandRange(1500.f, 2500.f);
		SpawnedMovingPlatform->SwitchInterval = FMath::RandRange(5.f, 10.f);
		SpawnedMovingPlatform->StopTime = FMath::RandRange(0.2f, 1.f);
	}
	
	// RotatingPlatform Spawn
	for (int32 i = 0; i < RotatingPlatformSpawnCount; i++)
	{
		FVector SpawnLocation = FVector(
			FMath::RandRange(MinSpawnRange.X, MaxSpawnRange.X),
			FMath::RandRange(MinSpawnRange.Y, MaxSpawnRange.Y),
			FMath::RandRange(MinSpawnRange.Z, MaxSpawnRange.Z)
		);
		
		FRotator SpawnRotation(0.f, 0.f, 0.f);
		
		ARotatingPlatform* SpawnedRotatingPlatform = World->SpawnActor<ARotatingPlatform>(RotatingPlatformClass, SpawnLocation, SpawnRotation);

		SpawnedRotatingPlatform->RotationSpeed = FMath::RandRange(5.f, 100.f);
		SpawnedRotatingPlatform->SwitchInterval = FMath::RandRange(1.f ,5.f);
	}
}


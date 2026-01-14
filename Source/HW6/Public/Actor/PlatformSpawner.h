// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

class AMovingPlatform;
class ARotatingPlatform;

UCLASS()
class HW6_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformSpawner();
	
	UPROPERTY(EditAnywhere, Category="Spawn")
	TSubclassOf<AMovingPlatform> MovingPlatformClass;

	UPROPERTY(EditAnywhere, Category="Spawn")
	TSubclassOf<ARotatingPlatform> RotatingPlatformClass;
	
	UPROPERTY(EditAnywhere, Category="Spawn")
	int32 MovingPlatformSpawnCount = 15;
	
	UPROPERTY(EditAnywhere, Category="Spawn")
	int32 RotatingPlatformSpawnCount = 15;
	
	UPROPERTY(EditAnywhere, Category="Spawn")
	FVector MinSpawnRange = FVector(0, -2000, -300);

	UPROPERTY(EditAnywhere, Category="Spawn")
	FVector MaxSpawnRange = FVector(3500, 2000, 300);;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

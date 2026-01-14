// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class HW6_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, Category="Mesh")
	UStaticMeshComponent* PlatformMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	FVector MoveSpeed = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MaxRange = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SwitchInterval = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float StopTime = 1.f;
	
private:
	bool bCanMove = true;
	FVector StartLocation;
	
	FTimerHandle SwitchTimerHandle;
	FTimerHandle StopTimerHandle;
	
	void StopPlatform();
	void MovePlatform();
};

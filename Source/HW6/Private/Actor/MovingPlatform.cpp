// Fill out your copyright notice in the Description page of Project Settings.
#include "Actor/MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	PlatformMesh->SetupAttachment(Root);
	
	PlatformMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PlatformMesh->SetCollisionObjectType(ECC_WorldDynamic);
	PlatformMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	PlatformMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	PlatformMesh->SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	
	GetWorldTimerManager().SetTimer(
		SwitchTimerHandle,
		this,
		&AMovingPlatform::StopPlatform,
		SwitchInterval,
		true   
	);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!bCanMove)
		return;
	
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (MoveSpeed * DeltaTime);
	SetActorLocation(CurrentLocation);
	
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
	
	if (DistanceMoved > MaxRange)
	{
		FVector MoveDirection = MoveSpeed.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MaxRange;
		SetActorLocation(StartLocation);
		MoveSpeed = -MoveSpeed;
	}
}

void AMovingPlatform::StopPlatform()
{
	bCanMove = false;
	
	GetWorldTimerManager().SetTimer(
		StopTimerHandle,
		this,
		&AMovingPlatform::MovePlatform,
		StopTime,
		false
	);
}

void AMovingPlatform::MovePlatform()
{
	bCanMove = true;
}


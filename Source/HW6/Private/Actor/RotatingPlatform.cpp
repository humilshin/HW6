// Fill out your copyright notice in the Description page of Project Settings.
#include "Actor/RotatingPlatform.h"

// Sets default values
ARotatingPlatform::ARotatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

// Called when the game starts or when spawned
void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(
	SwitchTimerHandle,
	this,
	&ARotatingPlatform::SwitchRotation,
	SwitchInterval,
	true   
);
}

// Called every frame
void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation.Yaw += RotationSpeed * DeltaTime;

	SetActorRotation(CurrentRotation);
}

void ARotatingPlatform::SwitchRotation()
{
	RotationSpeed = -RotationSpeed;
}


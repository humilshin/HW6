// Copyright Epic Games, Inc. All Rights Reserved.

#include "HW6GameMode.h"
#include "HW6Character.h"
#include "UObject/ConstructorHelpers.h"

AHW6GameMode::AHW6GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

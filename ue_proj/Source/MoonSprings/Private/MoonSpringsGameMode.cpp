// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoonSprings/Public/MoonSpringsGameMode.h"
#include "MoonSprings/Public/Characters/MSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMoonSpringsGameMode::AMoonSpringsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

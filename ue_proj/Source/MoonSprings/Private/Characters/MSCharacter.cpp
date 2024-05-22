// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoonSprings/Public/Characters/MSCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AMSCharacter::AMSCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
}

void AMSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

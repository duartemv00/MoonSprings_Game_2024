// Fill out your copyright notice in the Description page of Project Settings.


#include "MoonSprings/Public/Camera/MSCamera.h"


// Sets default values
AMSCamera::AMSCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMSCamera::BeginPlay()
{
	Super::BeginPlay();
	GetPlayerReference();
	FollowCharacter();
}

void AMSCamera::GetPlayerReference()
{
	CharacterRef = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void AMSCamera::FollowCharacter()
{
	if(CharacterRef)
	{
		//FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &AMSCamera::Timer_FollowCharacter, CharacterRef);
		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &AMSCamera::Timer_FollowCharacter);
		GetWorldTimerManager().SetTimer(TimerHandle_FollowCharacter, TimerDelegate, 0.01f, true);
		// You can not pass any FTimerDelegate parameter to the SetTimer() and Unreal Engine will just ignore it and don't crash
	}
}

void AMSCamera::Timer_FollowCharacter()
{
	FVector NewLocation = CharacterRef->GetActorLocation();
	NewLocation.X += CamOffsetX;
	NewLocation.Z = GetActorLocation().Z;
	NewLocation.Y = FMath::Clamp(NewLocation.Y, CamLeftLimit, CamRightLimit);
	NewLocation.X = FMath::Clamp(NewLocation.X, CamDownLimit, CamTopLimit);
	SetActorLocation(NewLocation);
}



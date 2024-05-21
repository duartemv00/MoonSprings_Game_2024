// Fill out your copyright notice in the Description page of Project Settings.


#include "MoonSprings/Public/Characters/Momo.h"


// Sets default values
AMomo::AMomo()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMomo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMomo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMomo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


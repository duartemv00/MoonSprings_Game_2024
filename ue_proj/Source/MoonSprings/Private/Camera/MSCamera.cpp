// Fill out your copyright notice in the Description page of Project Settings.


#include "MoonSprings/Public/Camera/MSCamera.h"


// Sets default values
AMSCamera::AMSCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMSCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMSCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


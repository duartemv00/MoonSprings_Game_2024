// Fill out your copyright notice in the Description page of Project Settings.


#include "MoonSprings/Public/PoolParent.h"


// Sets default values
APoolParent::APoolParent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APoolParent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APoolParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


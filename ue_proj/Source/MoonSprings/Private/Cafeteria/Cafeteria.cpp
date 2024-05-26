// Fill out your copyright notice in the Description page of Project Settings.


#include "Cafeteria/Cafeteria.h"


ACafeteria::ACafeteria()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SplineComponent->SetupAttachment(MeshComponent);
}

void ACafeteria::StartProductGeneration()
{
}

void ACafeteria::GenerateProduct()
{
	if (UWorld* World = GetWorld())
	{
		FActorSpawnParameters ProductSpawnParams;
		ProductSpawnParams.Owner = this;
		ProductSpawnParams.Instigator = GetInstigator();

		const FVector Location = SplineComponent->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World);
		const FRotator Rotation = SplineComponent->GetRotationAtSplinePoint(0, ESplineCoordinateSpace::World);
		
		const int32 Index = FMath::RandRange(0, Products.Num() - 1); // Create random index

		if(UPDAProduct* NewProductInformation = Products[Index])
		{
			AParentProduct* NewProductRef = World->SpawnActor<AParentProduct>(Location, Rotation, ProductSpawnParams);
			//Set the values for the just created product
			NewProductRef->SetValues(NewProductInformation->GetStaticMesh());
		}
	}
}

// Called when the game starts or when spawned
void ACafeteria::BeginPlay()
{
	Super::BeginPlay();
	GenerateProduct();
	
}


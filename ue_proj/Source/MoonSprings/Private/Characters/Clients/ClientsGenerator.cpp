// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Clients/ClientsGenerator.h"

#include "Characters/Clients/ParentClient.h"
#include "Components/ArrowComponent.h"

AClientsGenerator::AClientsGenerator()
{
	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(MeshComponent);
	SpawnPoint->SetRelativeLocation(FVector(0,0,40.f));

}

void AClientsGenerator::StartClientGeneration()
{
	//AParentClient* aux = CurrentClient;
	//CurrentClient = nullptr;
	//aux->Leave();
	if(CurrentClient)
	{
		CurrentClient->Leave();
		CurrentClient = nullptr;
	}
	GenerateClient();
}

void AClientsGenerator::GenerateClient()
{
	if (UWorld* World = GetWorld())
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		const FVector Location = SpawnPoint->GetComponentLocation();
		const FRotator Rotation = SpawnRotation;

		const int32 Index = FMath::RandRange(0, ClientsTemplates.Num() - 1); // Create random index
		// In this implementation every client has the same possibility to spawn

		if(UPDAClient* NewClientInformation = ClientsTemplates[Index].ClientClass)
		{
			CurrentClient = World->SpawnActor<AParentClient>(Location, Rotation, SpawnParams);
			//Set the values for the just created client
			CurrentClient->SetValues(NewClientInformation->GetSkeletalMesh(),
				NewClientInformation->GetAnimBlueprint(),
				NewClientInformation->GetPatience(),
				NewClientInformation->GetMinAskingTime(),
				NewClientInformation->GetMaxAskingTime());
		}
	}
	GetWorldTimerManager().SetTimer(ClientGenerationTimerHandle, this,
		&AClientsGenerator::StartClientGeneration,
		FMath::RandRange(MinTimeBetweenClients, MaxTimeBetweenClients), false);
}

// Called when the game starts or when spawned
void AClientsGenerator::BeginPlay()
{
	Super::BeginPlay();
	GenerateClient();
}


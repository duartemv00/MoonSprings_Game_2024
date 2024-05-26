// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PDAClient.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "ClientsGenerator.generated.h"

USTRUCT()
struct FClientTemplate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UPDAClient* ClientClass;

	UPROPERTY(EditAnywhere)
	float Probability;
};

UCLASS()
class MOONSPRINGS_API AClientsGenerator : public AActor
{
	GENERATED_BODY()

public:
	AClientsGenerator();

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent *MeshComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UArrowComponent *SpawnPoint;
	
	UPROPERTY(EditAnywhere, Category = "Configuration | Default")
	float MinTimeBetweenClients;

	UPROPERTY(EditAnywhere, Category = "Configuration | Default")
	float MaxTimeBetweenClients;
	
	UPROPERTY(EditAnywhere, Category = "Configuration | Clients")
	TArray<FClientTemplate> ClientsTemplates;

	UPROPERTY(EditAnywhere, Category = "Configuration | Clients" )
	FRotator SpawnRotation;

	UPROPERTY(EditAnywhere, Category = "Configuration | Clients")
	FVector LocationOffset;
	
	//***** PRIVATE FUNCTIONS ****+
	//Start the timer to generate a new client
	UFUNCTION() void StartClientGeneration();
	// Generate a new client
	UFUNCTION() void GenerateNewClient();

protected:
	virtual void BeginPlay() override;
};

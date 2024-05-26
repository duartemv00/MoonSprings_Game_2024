// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PDAProduct.h"
#include "Cafeteria/ParentProduct.h"

#include "Cafeteria.generated.h"

UCLASS()
class MOONSPRINGS_API ACafeteria : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditDefaultsOnly)
	USplineComponent *SplineComponent;

	UPROPERTY(EditAnywhere, Category = "Products")
	TArray<class UPDAProduct*> Products;
	

public:
	ACafeteria();

	UFUNCTION()
	void StartProductGeneration();
	UFUNCTION()
	void GenerateProduct();

protected:
	virtual void BeginPlay() override;
};
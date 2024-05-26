// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParentProduct.generated.h"

UCLASS()
class MOONSPRINGS_API AParentProduct : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MeshComponent;

public:
	AParentProduct();

	void SetValues(UStaticMesh* _Mesh);

protected:
	virtual void BeginPlay() override;
};

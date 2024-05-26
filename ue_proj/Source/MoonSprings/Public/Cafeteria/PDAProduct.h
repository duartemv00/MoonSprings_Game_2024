// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MSTypes.h"
#include "Engine/DataAsset.h"
#include "PDAProduct.generated.h"

/**
 * 
 */
UCLASS()
class MOONSPRINGS_API UPDAProduct : public UPrimaryDataAsset
{
	GENERATED_BODY()
	// Visuals
	UPROPERTY(EditAnywhere, Category = "Product visuals")
	UStaticMesh* MeshComponent;
	UPROPERTY(EditAnywhere, Category = "Product visuals")
	UMaterial* Skin;
	
	// Stats
	UPROPERTY(EditAnywhere,
		meta = (ToolTip = "Kind of product this is"),
		Category = "Product Config")
	EProductType ProductType;

	UPROPERTY(EditAnywhere,
		meta = (ToolTip = "If the product is or not in a good state"),
		Category = "Product Config")
	bool IsGood;

public:
	//***** PUBLIC FUNCTIONS *****
	// Getters
	UStaticMesh* GetStaticMesh() const { return MeshComponent; }
	UMaterial* GetSkin() const { return Skin; }
	EProductType GetPatience() const { return ProductType; }
	bool GetMinAskingTime() const { return IsGood; }
};

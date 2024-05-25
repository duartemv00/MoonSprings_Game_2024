// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PDAClient.generated.h"

/**
 * 
 */
UCLASS()
class MOONSPRINGS_API UPDAClient : public UPrimaryDataAsset
{
	GENERATED_BODY()
	// Visuals
	UPROPERTY(EditAnywhere, Category = "Client visuals")
	USkeletalMesh* MeshComponent;
	UPROPERTY(EditAnywhere, Category = "Client visuals")
	UAnimBlueprint* AnimBlueprint;
	// Stats
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0"),
		meta = (ToolTip = "Time before the client leaves if unattended"),
		Category = "Client stats | Default")
	float Patience;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0"),
		meta = (ToolTip = "Minimum time the client will wait before asking for something"),
		Category = "Client stats | Asking Time")
	float MinAskingTime;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0"),
		meta = (ToolTip = "Maximum time the client will wait before asking for something"),
		Category = "Client stats | Asking Time")
	float MaxAskingTime;

public:
	//***** PUBLIC FUNCTIONS *****
	// Getters
	USkeletalMesh* GetSkeletalMesh() const { return MeshComponent; }
	UAnimBlueprint* GetAnimBlueprint() const { return AnimBlueprint; }
	float GetPatience() const { return Patience; }
	float GetMinAskingTime() const { return MinAskingTime; }
	float GetMaxAskingTime() const { return MaxAskingTime; }
};

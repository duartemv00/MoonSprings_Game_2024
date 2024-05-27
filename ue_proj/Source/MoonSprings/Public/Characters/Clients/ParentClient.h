// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoonSprings/Public/Characters/MSCharacter.h"
#include "ParentClient.generated.h"

UCLASS()
class MOONSPRINGS_API AParentClient : public AMSCharacter
{
	GENERATED_BODY()
	
	// Client Stats
	UPROPERTY(EditAnywhere)
	float Patience;
	UPROPERTY(EditAnywhere)
	float MinAskingTime;
	UPROPERTY(EditAnywhere)
	float MaxAskingTime;

public:
	AParentClient();

protected:
	virtual void BeginPlay() override;

public:
	// Set the values of the client
	UFUNCTION()
	void SetValues(USkeletalMesh* _Mesh, UAnimBlueprint* _AnimBlueprint, float _Patience, float _MinAskingTime, float _MaxAskingTime);

	UFUNCTION()
	void Leave();

};

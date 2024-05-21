// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoonSprings/Public/Characters/MoonSpringsCharacter.h"
#include "ParentClient.generated.h"

UCLASS()
class MOONSPRINGS_API AParentClient : public AMoonSpringsCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AParentClient();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "MSCamera.generated.h"

UCLASS()
class MOONSPRINGS_API AMSCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMSCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	FTimerHandle TimerHandle_FollowCharacter;

	UPROPERTY()
	AActor* CharacterRef;

	UPROPERTY(EditInstanceOnly, meta = (MakeEditWidget = true))
	float CamTopLimit;
	UPROPERTY(EditInstanceOnly, meta = (MakeEditWidget = true))
	float CamDownLimit;
	UPROPERTY(EditInstanceOnly, meta = (MakeEditWidget = true))
	float CamLeftLimit;
	UPROPERTY(EditInstanceOnly, meta = (MakeEditWidget = true))
	float CamRightLimit;
	UPROPERTY(EditDefaultsOnly)
	float CamOffsetX;

	UFUNCTION()
	void GetPlayerReference();
	
	UFUNCTION()
	void FollowCharacter();
	UFUNCTION()
	void Timer_FollowCharacter();

};

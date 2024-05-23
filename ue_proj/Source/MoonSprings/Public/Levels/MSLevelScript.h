// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Engine/LevelScriptBlueprint.h"
#include "MSLevelScript.generated.h"

/**
 * 
 */
UCLASS()
class MOONSPRINGS_API AMSLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "MSLevelScript")
	void SetCameraView();
};

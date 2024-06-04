// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IMSInteractInterface.generated.h"

UINTERFACE()
class UIMSInteractInterface : public UInterface
{
	GENERATED_BODY()
};

class MOONSPRINGS_API IIMSInteractInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void Interact() = 0;
};

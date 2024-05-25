// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MSCharacter.h"
#include "Momo.generated.h"

UENUM(BlueprintType)
enum class EMomoState : uint8
{
	Default,
	HasClient,
	HasItem
};

UCLASS()
class MOONSPRINGS_API AMomo : public AMSCharacter
{
	GENERATED_BODY()
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	/** Sprint Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SprintAction;
	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category = Client, meta = (AllowPrivate))
	EMomoState MomoState;
	
public:
	AMomo();

	UFUNCTION(BlueprintCallable)
	void SetMomoState(EMomoState NewState) { MomoState = NewState; }

	UFUNCTION(BlueprintCallable)
	EMomoState GetMomoState() const { return MomoState; }

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& InputValue);
	// APawn interface
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
};

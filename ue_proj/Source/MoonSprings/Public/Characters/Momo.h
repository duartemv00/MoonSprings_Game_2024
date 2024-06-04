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
	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;
	
	UPROPERTY(EditAnywhere, Category = Client, meta = (AllowPrivate))
	EMomoState MomoState;
	
public:
	AMomo();

	// Setters
	UFUNCTION(BlueprintCallable)
	void SetMomoState(EMomoState NewState) { MomoState = NewState; }
	// Getters
	UFUNCTION(BlueprintCallable)
	EMomoState GetMomoState() const { return MomoState; }

	UFUNCTION()
	void SearchForInteractable();

	UFUNCTION()
	void Sprint();
	

protected:
	/** Called for movement input */
	UFUNCTION()
	void Move(const FInputActionValue& InputValue);
	// APawn interface
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
};

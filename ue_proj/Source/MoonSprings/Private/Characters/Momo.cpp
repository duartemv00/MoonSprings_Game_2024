// Fill out your copyright notice in the Description page of Project Settings.

#include "MoonSprings/Public/Characters/Momo.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InteractSystem/IMSInteractInterface.h"

AMomo::AMomo()
{
	PrimaryActorTick.bCanEverTick = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate
	
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 750.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->MaxStepHeight = 45.f;
	GetCharacterMovement()->SetWalkableFloorAngle(50);
}

void AMomo::SearchForInteractable()
{
	const FVector StartPosition = GetActorLocation();
	//const FVector EndPosition = StartPosition + GetActorForwardVector() * 300.f;
	//const FVector EndPosition = StartPosition + GetArrowComponent()->GetForwardVector() * 300.f;
	const FVector EndPosition = StartPosition + FVector(GetCapsuleComponent()->GetForwardVector().X * 300.f,0,0);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	FHitResult Hit;

	bool bHitSomething = GetWorld()->LineTraceSingleByChannel(Hit, StartPosition,
		EndPosition, ECollisionChannel::ECC_Camera, Params);

	DrawDebugLine(GetWorld(), StartPosition, EndPosition, FColor::Red, false,
		2.f, 0, 2.f);
	
	if(bHitSomething)
	{
		AActor* HitActor = Hit.GetActor();
		if(HitActor->GetClass()->ImplementsInterface(UIMSInteractInterface::StaticClass()))
		{
			// IIMSInteractInterface::Execute_Interact(HitActor);
			IIMSInteractInterface* InterfaceRef = Cast<IIMSInteractInterface>(HitActor);
			// InterfaceRef->Interact(HitActor);
			InterfaceRef->Interact();
			
		}
	}
}

void AMomo::Sprint()
{
	// Implementation
}

void AMomo::Move(const FInputActionValue& InputValue)
{
	// input is a Vector2D
	FVector2D MovementVector = InputValue.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		//AddControllerYawInput(YawRotation.Yaw); //No aporta nada
		
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); // get forward vector
		AddMovementInput(ForwardDirection, -MovementVector.Y); // apply forward movement
		
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); // get right vector 
		AddMovementInput(RightDirection, -MovementVector.X); // apply right movement
		
		SetActorRotation(FRotator(0, YawRotation.Yaw, 0)); // rotate the character to the direction of the movement
	}
}

void AMomo::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AMomo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMomo::Move);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AMomo::SearchForInteractable);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AMomo::Sprint);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


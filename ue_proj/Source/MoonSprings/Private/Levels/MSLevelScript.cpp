// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/MSLevelScript.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void AMSLevelScript::BeginPlay()
{
	Super::BeginPlay();
	SetCameraView();
}

void AMSLevelScript::SetCameraView()
{
	AActor* aux1 = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());
	APlayerController* aux2 = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	aux2->SetViewTargetWithBlend(aux1, 0, EViewTargetBlendFunction::VTBlend_Cubic);
}

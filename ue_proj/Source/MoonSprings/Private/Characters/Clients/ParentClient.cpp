// Fill out your copyright notice in the Description page of Project Settings.


#include "MoonSprings/Public/Characters/Clients/ParentClient.h"

AParentClient::AParentClient()
{
	PrimaryActorTick.bCanEverTick = false;
	ClientMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	ClientMesh->SetupAttachment(RootComponent);
	ClientMesh->SetCollisionProfileName(TEXT("BlockAll"));
	//ClientMesh->SetSimulatePhysics(true); // This is for ragdoll
	ClientMesh->SetEnableGravity(true);
}

void AParentClient::BeginPlay()
{
	Super::BeginPlay();
}

void AParentClient::SetValues(USkeletalMesh* _Mesh,
	UAnimBlueprint* _AnimBlueprint,
	const float _Patience,
	const float _MinAskingTime,
	const float _MaxAskingTime)
{
	
	this->ClientMesh->SetSkinnedAssetAndUpdate(_Mesh);
	this->AnimBlueprint = _AnimBlueprint;
	this->Patience = _Patience;
	this->MinAskingTime = _MinAskingTime;
	this->MaxAskingTime = _MaxAskingTime;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "MoonSprings/Public/Characters/Clients/ParentClient.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


AParentClient::AParentClient()
{
	PrimaryActorTick.bCanEverTick = false;
	GetMesh()->AddRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	
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
	if(GetMesh() && IsValid(_Mesh)) {
		GetMesh()->SetSkinnedAssetAndUpdate(_Mesh);
		if(IsValid(_AnimBlueprint))
		{
			// THE CODE BELOW IS NOT WORKING BECAUSE WE ARE NOT IN THE CONSTRUCTOR
			// FString AnimBPPath = _AnimBlueprint->GetPathName();
			// UCHAR Symbol = '/';
			// int32 Pos;
			// if (AnimBPPath.FindLastChar(Symbol, Pos))
			// {
			// 	FString CorrectAnimBPPath = AnimBPPath.Left(Pos);
			// 	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimBPClass(*CorrectAnimBPPath);
			// 	if(AnimBPClass.Succeeded())
			// 	{
			// 		GetMesh()->SetAnimInstanceClass(AnimBPClass.Class);
			// 	}
			// }
			GetMesh()->SetAnimInstanceClass(_AnimBlueprint->GeneratedClass); // This is the correct way to set the AnimInstanceClass (not GetClass())
		}
	}
	Patience = _Patience;
	MinAskingTime = _MinAskingTime;
	MaxAskingTime = _MaxAskingTime;
}

void AParentClient::Leave()
{
	this->SetLifeSpan(0.01f);
}


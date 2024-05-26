// Fill out your copyright notice in the Description page of Project Settings.


#include "Cafeteria/ParentProduct.h"

AParentProduct::AParentProduct()
{
	PrimaryActorTick.bCanEverTick = false;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("`MeshComponent");
}

void AParentProduct::SetValues(UStaticMesh* _Mesh)
{
	if(MeshComponent && IsValid(_Mesh))
	{
		MeshComponent->SetStaticMesh(_Mesh);
	}
}

void AParentProduct::BeginPlay()
{
	Super::BeginPlay();
}


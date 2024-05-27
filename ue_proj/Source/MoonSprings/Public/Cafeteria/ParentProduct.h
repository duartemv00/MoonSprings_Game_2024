// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ParentProduct.generated.h"

UCLASS()
class MOONSPRINGS_API AParentProduct : public AActor
{
	GENERATED_BODY()

	FTimerHandle MovAlongSplineTimer;
	float SplinePercentageTravelled = 0.0f;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MeshComponent;

	class USplineComponent* CafeteriaSpline;

public:
	AParentProduct();

	void SetValues(UStaticMesh* _Mesh);

	void Timer_StartMovementAlongSpline();
	void StartMovementAlongSpline(USplineComponent* CafeteriaSpline);

	void ProductLeavesCafeteria() const;

protected:
	virtual void BeginPlay() override;
};

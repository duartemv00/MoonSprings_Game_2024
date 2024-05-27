// Fill out your copyright notice in the Description page of Project Settings.


#include "Cafeteria/ParentProduct.h"

#include "FrameTypes.h"
#include "Components/SplineComponent.h"

AParentProduct::AParentProduct()
{
	PrimaryActorTick.bCanEverTick = false;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("`MeshComponent");
}

void AParentProduct::SetValues(UStaticMesh* _Mesh)
{
	// Initialize the product with the information provided by the cafeteria (parent)
	if(MeshComponent && IsValid(_Mesh))
	{
		MeshComponent->SetStaticMesh(_Mesh);
	}
}

void AParentProduct::Timer_StartMovementAlongSpline()
{
	if(GetActorLocation() == CafeteriaSpline->GetLocationAtSplinePoint(CafeteriaSpline->GetSplineLength(),
		ESplineCoordinateSpace::World))
	{
		this->Destroy(); // Destroy the product if it reaches the end of the spline
	} else
	{
		// Continue moving the product along the spline
		SplinePercentageTravelled += 0.001f;
		float FragmentOfSpline = FMath::Lerp(0.f, CafeteriaSpline->GetSplineLength(),
			SplinePercentageTravelled);
		SetActorLocation(CafeteriaSpline->GetLocationAtDistanceAlongSpline(FragmentOfSpline,
			ESplineCoordinateSpace::World));
		
	}
	
}

void AParentProduct::StartMovementAlongSpline(USplineComponent* _CafeteriaSpline)
{
	GetWorldTimerManager().SetTimer(MovAlongSplineTimer, this,
			&AParentProduct::Timer_StartMovementAlongSpline, .01f, true);
	CafeteriaSpline = _CafeteriaSpline;
}

void AParentProduct::ProductLeavesCafeteria() const
{
	// Produce needs to stop following the spline when it leaves the cafeteria
	GetWorldTimerManager().PauseTimer(MovAlongSplineTimer);
}

void AParentProduct::BeginPlay()
{
	Super::BeginPlay();
}


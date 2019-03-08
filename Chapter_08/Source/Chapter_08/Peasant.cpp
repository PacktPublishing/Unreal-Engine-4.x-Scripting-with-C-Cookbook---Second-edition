// Fill out your copyright notice in the Description page of Project Settings.

#include "Peasant.h"
#include "ConstructorHelpers.h"

APeasant::APeasant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	UStaticMeshComponent * SM = GetStaticMeshComponent();

	if (SM != nullptr)
	{
		if (MeshAsset.Object != nullptr)
		{
			SM->SetStaticMesh(MeshAsset.Object);
			SM->SetGenerateOverlapEvents(true);
		}
		SM->SetMobility(EComponentMobility::Movable);
	}
}

void APeasant::Flee(AKing* DeadKing)
{
    // Display message on the screen
    GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red,
        TEXT("Waily Waily!"));

    // Get the direction away from the dead king
    FVector FleeVector = GetActorLocation() -
        DeadKing->GetActorLocation();

    // Set the magnitude (length) of the vector to 1
    FleeVector.Normalize();

    // Make the vector 500 times longer
    FleeVector *= 500;

    // Set the Actor's new location
    SetActorLocation(GetActorLocation() + FleeVector);
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"

ADoor::ADoor()
{
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
        SM->SetWorldScale3D(FVector(0.3, 2, 3));
    }

    SetActorEnableCollision(true);
}

bool ADoor::CanInteract_Implementation()
{
    return true;
}

void ADoor::PerformInteract_Implementation()
{
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("The door refuses to budge. Perhaps there is a hidden switch nearby ? ")); 
}

void ADoor::Open_Implementation()
{
    AddActorLocalOffset(FVector(0, 0, 200));
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorBell.h"
#include "ConstructorHelpers.h"
#include "Openable.h"

ADoorBell::ADoorBell()
{
    HasBeenPushed = false;

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
        SM->SetWorldScale3D(FVector(0.5, 0.5, 0.5));
    }

    SetActorEnableCollision(true);

    DoorToOpen = nullptr;
}

bool ADoorBell::CanInteract_Implementation()
{
    return !HasBeenPushed;
}

void ADoorBell::PerformInteract_Implementation()
{
    HasBeenPushed = true;
    if (DoorToOpen->GetClass()->ImplementsInterface(UOpenable::StaticClass()))
    {
        IOpenable::Execute_Open(DoorToOpen);
    }
}
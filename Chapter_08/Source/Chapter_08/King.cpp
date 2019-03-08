// Fill out your copyright notice in the Description page of Project Settings.

#include "King.h"
#include "ConstructorHelpers.h"

// Sets default values
AKing::AKing()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));

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

void AKing::Die()
{
    OnKingDeath.Broadcast(this);
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "SlidingDoor.h"
#include "ConstructorHelpers.h"

// Sets default values
ASlidingDoor::ASlidingDoor()
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
        SM->SetWorldScale3D(FVector(0.3, 2, 3));
    }

    SetActorEnableCollision(true);

    IsOpen = false;
    PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void ASlidingDoor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ASlidingDoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (IsOpen)
    {
        SetActorLocation(FMath::Lerp(GetActorLocation(), TargetLocation, 0.05));
    }
}

void ASlidingDoor::Open()
{
    TargetLocation = ActorToWorld().TransformPositionNoScale(FVector(0, 0, 200));
    IsOpen = true;
}


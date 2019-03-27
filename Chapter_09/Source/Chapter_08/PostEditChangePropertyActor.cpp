// Fill out your copyright notice in the Description page of Project Settings.

#include "PostEditChangePropertyActor.h"
#include "ConstructorHelpers.h"

APostEditChangePropertyActor::APostEditChangePropertyActor()
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

void APostEditChangePropertyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    // Check if property is valid
    if (PropertyChangedEvent.Property != nullptr)
    {
        // Get the name of the changed property
        const FName PropertyName(
            PropertyChangedEvent.Property->GetFName());

        // If the changed property is ShowStaticMesh then we will set   
        // the visibility of the actor
        if (PropertyName == GET_MEMBER_NAME_CHECKED(APostEditChangePropertyActor, ShowStaticMesh))
        {
            UStaticMeshComponent * SM = GetStaticMeshComponent();

            if (SM != nullptr)
            {
                SM->SetVisibility(ShowStaticMesh);
            }
        }
    }

    // Then call the parent version of this function
    Super::PostEditChangeProperty(PropertyChangedEvent);
}
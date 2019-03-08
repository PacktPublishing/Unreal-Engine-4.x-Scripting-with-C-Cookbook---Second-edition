// Fill out your copyright notice in the Description page of Project Settings.

#include "GravityObject.h"

// Add default functionality here for any IGravityObject functions that are not pure virtual.
void IGravityObject::EnableGravity()
{
    AActor* ThisAsActor = Cast<AActor>(this);
    if (ThisAsActor != nullptr)
    {
        TArray<UPrimitiveComponent*> PrimitiveComponents;

        ThisAsActor->GetComponents(PrimitiveComponents);

        for (UPrimitiveComponent* Component : PrimitiveComponents)
        {
            Component->SetEnableGravity(true);
        }

        GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Enabling Gravity"));
    }
}

void IGravityObject::DisableGravity()
{
    AActor* ThisAsActor = Cast<AActor>(this);
    if (ThisAsActor != nullptr)
    {
        TArray<UPrimitiveComponent*> PrimitiveComponents;

        ThisAsActor->GetComponents(PrimitiveComponents);

        for (UPrimitiveComponent* Component : PrimitiveComponents)
        {
            Component->SetEnableGravity(false);
        }

        GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Disabling Gravity"));
    }
}
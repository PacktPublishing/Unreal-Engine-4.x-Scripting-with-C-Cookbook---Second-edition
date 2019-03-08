// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_04_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AInventoryActor();

    virtual void PickUp();
    virtual void PutDown(FTransform TargetLocation);
	
};

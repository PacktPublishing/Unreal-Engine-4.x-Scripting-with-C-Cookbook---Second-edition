// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "PostEditChangePropertyActor.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_08_API APostEditChangePropertyActor : public AStaticMeshActor
{
    GENERATED_BODY()

    // Sets default values for this actor's properties
    APostEditChangePropertyActor();

    UPROPERTY(EditAnywhere)
    bool ShowStaticMesh = true;

    virtual void PostEditChangeProperty(FPropertyChangedEvent& 
                                        PropertyChangedEvent) override;
    
};

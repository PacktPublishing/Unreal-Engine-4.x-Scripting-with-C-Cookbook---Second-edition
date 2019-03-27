// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "OnConstructionActor.generated.h"

UCLASS()
class CHAPTER_08_API AOnConstructionActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
    AOnConstructionActor();

    virtual void OnConstruction(const FTransform& Transform) override;

    UPROPERTY(EditAnywhere)
        bool ShowStaticMesh;
	
};

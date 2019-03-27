// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Spotter.generated.h"

UCLASS()
class CHAPTER_08_API ASpotter : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
    // Sets default values for this actor's properties
    ASpotter();

    // Called every frame
    virtual void Tick(float DeltaSeconds) override;

    UFUNCTION(BlueprintImplementableEvent)
    void OnPlayerSpotted(APawn* Player);

};

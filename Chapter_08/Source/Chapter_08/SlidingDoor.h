// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SlidingDoor.generated.h"

UCLASS()
class CHAPTER_08_API ASlidingDoor : public AStaticMeshActor
{
    GENERATED_BODY()
    
public:	
    // Sets default values for this actor's properties
    ASlidingDoor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = Door)
    void Open();

    UPROPERTY()
    bool IsOpen;

    UPROPERTY()
    FVector TargetLocation;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleObject.generated.h"

UCLASS()
class CHAPTER_12_API ACollectibleObject : public AActor
{
    GENERATED_BODY()
    
public:	
    // Sets default values for this actor's properties
    ACollectibleObject();

    // Event called when something starts to overlaps the
    // sphere collider
    // Note: UFUNCTION required for replication callbacks
    UFUNCTION() 
    void OnBeginOverlap(class UPrimitiveComponent*
        HitComp, 
        class AActor* OtherActor,
        class UPrimitiveComponent*
        OtherComp,
        int32 OtherBodyIndex, bool
        bFromSweep,
        const FHitResult& SweepResult);

    // Our server function to update the score.
    UFUNCTION(Reliable, Server, WithValidation)
    void UpdateScore(int32 Amount);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AntiGravityVolume.generated.h"

UCLASS()
class CHAPTER_07_API AAntiGravityVolume : public AActor
{
    GENERATED_BODY()
    
public:	
    // Sets default values for this actor's properties
    AAntiGravityVolume();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY()
    UBoxComponent* CollisionComponent;

    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
    virtual void NotifyActorEndOverlap(AActor* OtherActor) override;


};

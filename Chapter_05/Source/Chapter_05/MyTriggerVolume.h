// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MyTriggerVolume.generated.h"

DECLARE_EVENT(AMyTriggerVolume, FPlayerEntered)
UCLASS()
class CHAPTER_05_API AMyTriggerVolume : public AActor
{
    GENERATED_BODY()
    
public:	
    // Sets default values for this actor's properties
    AMyTriggerVolume();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY() 
    UBoxComponent* TriggerZone; 
 
    UFUNCTION() 
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override; 

    UFUNCTION() 
    virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

    FPlayerEntered OnPlayerEntered;

};

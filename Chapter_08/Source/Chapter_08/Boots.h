// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wearable.h"
#include "Boots.generated.h"

UCLASS()
class CHAPTER_08_API ABoots : public AActor, public IWearable
{
    GENERATED_BODY()
    
public:	
    // Sets default values for this actor's properties
    ABoots();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Implementing the functions needed for IWearable
    virtual void OnEquip_Implementation(APawn* Wearer) override
    {
        GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red,
            "Item being worn");
    }

    virtual bool CanEquip_Implementation(APawn* Wearer) override
    {
        return true;
    }

    virtual int32 GetStrengthRequirement_Implementation() override
    {
        return 0;
    }


};

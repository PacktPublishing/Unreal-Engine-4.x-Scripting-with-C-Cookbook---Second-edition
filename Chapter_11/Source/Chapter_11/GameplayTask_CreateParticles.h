// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "Particles/ParticleSystem.h"
#include "GameplayTask_CreateParticles.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_11_API UGameplayTask_CreateParticles : public UGameplayTask
{
    GENERATED_BODY()
    
public:
    virtual void Activate();

    // A static constructor for an instance of a UGameplayTask_CreateEmitter instance,
    // including args of (what class of emitter, where to create it).
    UFUNCTION(BlueprintCallable, Category = "GameplayTasks", meta = (AdvancedDisplay = "TaskOwner", DefaultToSelf = "TaskOwner", BlueprintInternalUseOnly = "TRUE"))
        static UGameplayTask_CreateParticles* ConstructTask(
            TScriptInterface<IGameplayTaskOwnerInterface> TaskOwner,
            UParticleSystem* particleSystem,
            FVector location);

    UParticleSystem* ParticleSystem;
    FVector Location;
};

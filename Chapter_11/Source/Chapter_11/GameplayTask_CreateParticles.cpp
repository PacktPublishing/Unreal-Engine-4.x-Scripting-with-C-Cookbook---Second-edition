// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayTask_CreateParticles.h"
#include "Kismet/GameplayStatics.h"

// Like a constructor.
UGameplayTask_CreateParticles* UGameplayTask_CreateParticles::ConstructTask(
    TScriptInterface<IGameplayTaskOwnerInterface> TaskOwner,
    UParticleSystem* particleSystem,
    FVector location)
{

    IGameplayTaskOwnerInterface& AsTaskOwner = *TaskOwner;

    UGameplayTask_CreateParticles* task = NewTask<UGameplayTask_CreateParticles>(TaskOwner);

    // Fill fields
    if (task)
    {
        task->ParticleSystem = particleSystem;
        task->Location = location;
    }

    return task;
}

void UGameplayTask_CreateParticles::Activate()
{
    Super::Activate();

    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, Location);
}



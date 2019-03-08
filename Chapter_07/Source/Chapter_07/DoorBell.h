// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interactable.h"
#include "DoorBell.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_07_API ADoorBell : public AStaticMeshActor, public IInteractable
{
	GENERATED_BODY()
	
public:
    ADoorBell();

    virtual bool CanInteract_Implementation() override;
    virtual void PerformInteract_Implementation() override;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    AActor* DoorToOpen;

private:
    bool HasBeenPushed;
};

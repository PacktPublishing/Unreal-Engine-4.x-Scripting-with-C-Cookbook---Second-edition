// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "InteractingPawn.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_07_API AInteractingPawn : public ADefaultPawn
{
    GENERATED_BODY()
    
public:
    void TryInteract();

private:
    virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override;
};

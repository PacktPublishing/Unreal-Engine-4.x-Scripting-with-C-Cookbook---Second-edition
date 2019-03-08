// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_04_API AMyGameStateBase : public AGameStateBase
{
    GENERATED_BODY()

public:
    // Constructor to initialize CurrentScore
    AMyGameStateBase();  
 
    // Will set the CurrentScore variable
    UFUNCTION() 
    void SetScore(int32 NewScore); 
 
    // Getter
    UFUNCTION() 
    int32 GetScore(); 

private: 
    UPROPERTY() 
    int32 CurrentScore; 
    
};

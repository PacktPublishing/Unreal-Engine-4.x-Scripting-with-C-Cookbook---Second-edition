// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_10_API AEnemyAIController : public AAIController
{
    GENERATED_BODY()
    
private:
    // AI Component references
    UBehaviorTreeComponent* BehaviorComp;
    UBlackboardComponent* BlackboardComp;

public:
    AEnemyAIController();

    // Called when the controller possesses a Pawn/Character
    virtual void Possess(APawn* InPawn) override;

    FBlackboard::FKey TargetKeyID;

};

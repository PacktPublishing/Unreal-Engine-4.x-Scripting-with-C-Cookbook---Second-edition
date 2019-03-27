// Fill out your copyright notice in the Description page of Project Settings.
#include "EnemyAIController.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/BehaviorTree.h"


AEnemyAIController::AEnemyAIController()
{
    // Initialize components
    BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

// Called when the controller possesses a Pawn/Character
void AEnemyAIController::Possess(APawn* InPawn)
{
    Super::Possess(InPawn);

    // Convert InPawn to EnemyCharacter
    auto Character = Cast<AEnemyCharacter>(InPawn);

    // Check if pointers are valid
    if(Character && Character->EnemyBehaviorTree)
    {
        BlackboardComp->InitializeBlackboard(*Character->EnemyBehaviorTree->BlackboardAsset);

        TargetKeyID = BlackboardComp->GetKeyID("Target");

        BehaviorComp->StartTree(*Character->EnemyBehaviorTree);
    }
}
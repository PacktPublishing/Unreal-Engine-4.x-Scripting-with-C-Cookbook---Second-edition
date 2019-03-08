// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MoveToPlayer.h"
#include "EnemyAIController.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    auto EnemyController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
    auto Blackboard = OwnerComp.GetBlackboardComponent();

    ACharacter * Target = Cast<ACharacter>(Blackboard->GetValue<UBlackboardKeyType_Object>(EnemyController->TargetKeyID));

    if(Target)
    {
        EnemyController->MoveToActor(Target, 50.0f);
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}
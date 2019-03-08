// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_FindPlayer.h"
#include "EnemyAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UBTService_FindPlayer::UBTService_FindPlayer()
{
    bCreateNodeInstance = true;
}

void UBTService_FindPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    auto EnemyAIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

    if(EnemyAIController)
    {
        auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
        OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyAIController->TargetKeyID, PlayerPawn);
        UE_LOG(LogTemp, Warning, TEXT("Target has been set!"));
    }

}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbility_Attack.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_11_API UGameplayAbility_Attack : public UGameplayAbility
{
	GENERATED_BODY()

        /** Returns true if this ability can be activated right now. Has no side effects */
        virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const {
        UE_LOG(LogTemp, Warning, TEXT("ability_attack CanActivateAbility!"));
        return true;
    }

    /** Checks cost. returns true if we can pay for the ability. False if not */
    virtual bool CheckCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const {
        UE_LOG(LogTemp, Warning, TEXT("ability_attack CheckCost!"));
        return true;
        //return Super::CheckCost( Handle, ActorInfo, OptionalRelevantTags );
    }

    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
        const FGameplayEventData* TriggerEventData)
    {
        UE_LOG(LogTemp, Warning, TEXT("Activating ugameplayability_attack().. swings weapon!"));
        Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
    }

    /** Input binding stub. */
    virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) {
        UE_LOG(LogTemp, Warning, TEXT("ability_attack inputpressed!"));
        Super::InputPressed(Handle, ActorInfo, ActivationInfo);
    }

	
};

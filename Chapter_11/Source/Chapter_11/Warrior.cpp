// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"
#include "AbilitySystemComponent.h"
#include "GameUnitAttributeSet.h" // 11-08 - GameplayAbilities API - Implementing stats with UAttributeSet
#include "GameplayAbility.h"
#include "GameplayTask_CreateParticles.h"


// Sets default values
AWarrior::AWarrior()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("UAbilitySystemComponent");
    GameplayTasksComponent = CreateDefaultSubobject<UGameplayTasksComponent>("UGameplayTasksComponent");
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* Input)
{
    Super::SetupPlayerInputComponent(Input);

    // Connect the class's AbilitySystemComponent 
    // to the actor's input component 
    AbilitySystemComponent->BindToInputComponent(Input);

    // Go thru each BindInfo in the gameplayAbilitySet. 
    // Give & try and activate each on the AbilitySystemComponent. 
    for (const FGameplayAbilityBindInfo& BindInfo :
        gameplayAbilitySet->Abilities)
    {

        FGameplayAbilitySpec spec(
            // Gets you an instance of the UClass 
            BindInfo.GameplayAbilityClass->
            GetDefaultObject<UGameplayAbility>(),
            1, (int32)BindInfo.Command);

        // STORE THE ABILITY HANDLE FOR LATER INVOKATION 
        // OF THE ABILITY 
        FGameplayAbilitySpecHandle abilityHandle =
            AbilitySystemComponent->GiveAbility(spec);

        // The integer id that invokes the ability  
        // (ith value in enum listing) 
        int32 AbilityID = (int32)BindInfo.Command;

        // CONSTRUCT the inputBinds object, which will 
        // allow us to wire-up an input event to the 
        // InputPressed() / InputReleased() events of 
        // the GameplayAbility. 
        FGameplayAbilityInputBinds inputBinds(
            // These are supposed to be unique strings that define 
            // what kicks off the ability for the actor instance. 
            // Using strings of the format  
            // "ConfirmTargetting_Player0_AbilityClass" 
            FS("ConfirmTargetting_%s_%s", *GetName(),
                *BindInfo.GameplayAbilityClass->GetName()),
            FS("CancelTargetting_%s_%s", *GetName(),
                *BindInfo.GameplayAbilityClass->GetName()),
            "EGameplayAbilityInputBinds", // The name of the ENUM that  
            // has the abilities listing (GameplayAbilitySet.h). 
            AbilityID, AbilityID
        );
        // MUST BIND EACH ABILITY TO THE INPUTCOMPONENT, OTHERWISE 
        // THE ABILITY CANNOT "HEAR" INPUT EVENTS. 
        // Enables triggering of InputPressed() / InputReleased()  
        // events, which you can in-turn use to call  
        // TryActivateAbility() if you so choose. 
        AbilitySystemComponent->BindAbilityActivationToInputComponent(
            Input, inputBinds
        );

        // Test-kicks the ability to active state. 
        // You can try invoking this manually via your 
        // own hookups to keypresses in this Warrior class 
        // TryActivateAbility() calls ActivateAbility() if 
        // the ability is indeed invokable at this time according 
        // to rules internal to the Ability's class (such as cooldown 
        // is ready and cost is met) 
        AbilitySystemComponent->TryActivateAbility(
            abilityHandle, 1);
    }
}

// 11-08 - GameplayAbilities API - Implementing stats with UAttributeSet
void AWarrior::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    if(AbilitySystemComponent)
    {
        AbilitySystemComponent->InitStats(UGameUnitAttributeSet::StaticClass(), NULL);
    }

    // 11-10 - GameplayTasks API - Making things happen with GameplayTasks
    
    UGameplayTask_CreateParticles* task =
        UGameplayTask_CreateParticles::ConstructTask(this, particleSystem, FVector(200.f, 0.f, 200.f));
            

    if (GameplayTasksComponent && task)
    {
        GameplayTasksComponent->AddTaskReadyForActivation(*task);
    }
}

// 11-09 - GameplayAbilities API - Implementing buffs with GameplayEffect
inline UGameplayEffect* ConstructGameplayEffect(FString name)
{
    return NewObject<UGameplayEffect>(GetTransientPackage(), FName(*name));
}

inline FGameplayModifierInfo& AddModifier(
    UGameplayEffect* Effect, UProperty* Property,
    EGameplayModOp::Type Op,
    const FGameplayEffectModifierMagnitude& Magnitude)
{
    int32 index = Effect->Modifiers.Num();
    Effect->Modifiers.SetNum(index + 1);
    FGameplayModifierInfo& Info = Effect->Modifiers[index];
    Info.ModifierMagnitude = Magnitude;
    Info.ModifierOp = Op;
    Info.Attribute.SetUProperty(Property);
    return Info;
}

void AWarrior::TestGameplayEffect()
{
    // Construct & retrieve UProperty to affect
    UGameplayEffect* RecoverHP = ConstructGameplayEffect("RecoverHP");

    // Compile-time checked retrieval of Hp UPROPERTY()
    // from our UGameUnitAttributeSet class (listed in
    // UGameUnitAttributeSet.h)
    UProperty* hpProperty = FindFieldChecked<UProperty>(
        UGameUnitAttributeSet::StaticClass(),
        GET_MEMBER_NAME_CHECKED(UGameUnitAttributeSet, Hp));

    // Command the addition of +5 HP to the hpProperty
    AddModifier(RecoverHP, hpProperty, EGameplayModOp::Additive, FScalableFloat(50.f));

    // .. for a fixed-duration of 10 seconds ..
    RecoverHP->DurationPolicy = EGameplayEffectDurationType::HasDuration;
    RecoverHP->DurationMagnitude = FScalableFloat(10.f);

    // .. with 100% chance of success ..
    RecoverHP->ChanceToApplyToTarget = 1.f;

    // .. with recurrency (Period) of 0.5 seconds
    RecoverHP->Period = 0.5f;

    // Finally, begin application of the effect.
    FActiveGameplayEffectHandle recoverHpEffectHandle =
        AbilitySystemComponent->ApplyGameplayEffectToTarget(
            RecoverHP, AbilitySystemComponent, 1.f);

    // Retrieve the delegate. If it has no duration how can we
    // make sure the lambda runs before effect terminates?
    FOnActiveGameplayEffectRemoved* ep = AbilitySystemComponent->
        OnGameplayEffectRemovedDelegate(recoverHpEffectHandle);

    if (ep) 
    {
        ep->AddLambda([]() 
        {
            UE_LOG(LogTemp, Warning, TEXT("Recover effect has been removed."), 1);
        });
    }

}


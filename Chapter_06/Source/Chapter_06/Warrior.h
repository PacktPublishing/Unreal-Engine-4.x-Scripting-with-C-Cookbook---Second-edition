// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Warrior.generated.h"

UCLASS()
class CHAPTER_06_API AWarrior : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AWarrior();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // The movement from the previous frame
    FVector2D lastInput;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Movement functions
    void Forward(float amount);
    void Back(float amount);
    void Right(float amount);
    void Left(float amount);

    UFUNCTION(BlueprintNativeEvent, Category = Collision)
    void OnOverlapsBegin(UPrimitiveComponent* Comp,
                         AActor* OtherActor, 
                         UPrimitiveComponent* OtherComp,
                         int32 OtherBodyIndex,
                         bool bFromSweep, 
                         const FHitResult&SweepResult);

    UFUNCTION(BlueprintNativeEvent, Category = Collision)
    void OnOverlapsEnd(UPrimitiveComponent* Comp,
                       AActor* OtherActor, 
                       UPrimitiveComponent* OtherComp,
                       int32 OtherBodyIndex);

    virtual void PostInitializeComponents() override;

};

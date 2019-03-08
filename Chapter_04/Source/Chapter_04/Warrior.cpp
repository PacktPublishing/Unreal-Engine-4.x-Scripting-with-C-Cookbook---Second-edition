// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();

	// Will destroy this object in 10 seconds
	SetLifeSpan(10); 
	
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AWarrior::ToString() 
{ 
  return FString::Printf(TEXT("An instance of AWarrior: %s"), *Name); 
} 


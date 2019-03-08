// Fill out your copyright notice in the Description page of Project Settings.

#include "UECookbookGameModeBase.h"
#include "MyFirstActor.h" // AMyFirstActor

void AUECookbookGameModeBase::BeginPlay()
{
	// Call the parent class version of this function
	Super::BeginPlay();

	// Displays a red message on the screen for 10 seconds
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, 
									 TEXT("Actor Spawning")); 

	// Spawn an instance of the AMyFirstActor class at the default 
	// location.
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), 
										                 SpawnLocation);

	FTimerHandle Timer; 
	GetWorldTimerManager().SetTimer(Timer, this, &AUECookbookGameModeBase::DestroyActorFunction, 10);
}

void AUECookbookGameModeBase::DestroyActorFunction() 
{ 
  if (SpawnedActor != nullptr) 
  { 
	// Displays a red message on the screen for 10 seconds
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, 
									 TEXT("Actor Destroyed")); 
    SpawnedActor->Destroy(); 
  } 
} 

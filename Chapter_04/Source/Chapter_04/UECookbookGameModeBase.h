// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstActor.h"
#include "UECookbookGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class CHAPTER_04_API AUECookbookGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override; 

	UPROPERTY() 
	AMyFirstActor* SpawnedActor; 

	UFUNCTION() 
	void DestroyActorFunction(); 
};

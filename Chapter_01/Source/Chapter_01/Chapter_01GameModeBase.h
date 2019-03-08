// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_01GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_01_API AChapter_01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	void BeginPlay();
	
};

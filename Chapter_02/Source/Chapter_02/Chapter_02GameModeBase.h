// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "Chapter_02GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_02_API AChapter_02GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = UClassNames ) 
	TSubclassOf<UUserProfile> UPBlueprintClassName; 

	void BeginPlay();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_06GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_06_API AChapter_06GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = UIFuncs)
    void ButtonClicked()
    {
        UE_LOG(LogTemp, Warning, TEXT("UI Button Clicked"));
    }

    void BeginPlay();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUserWidget> Widget;
};

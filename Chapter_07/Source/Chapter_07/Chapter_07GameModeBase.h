// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyInterface.h"
#include "Chapter_07GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_07_API AChapter_07GameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    TArray<IMyInterface*> MyInterfaceInstances;
};

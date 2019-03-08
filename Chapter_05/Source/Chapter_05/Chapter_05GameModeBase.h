// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_05GameModeBase.generated.h"


DECLARE_DELEGATE(FStandardDelegateSignature)
DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor)
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)

/**
 * 
 */
UCLASS()
class CHAPTER_05_API AChapter_05GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
    FStandardDelegateSignature MyStandardDelegate;

    FParamDelegateSignature MyParameterDelegate;

    FMulticastDelegateSignature MyMulticastDelegate;

};

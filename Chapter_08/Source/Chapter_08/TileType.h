// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TileType.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CHAPTER_08_API UTileType : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY()
    int32 MovementCost;

    UPROPERTY()
    bool CanBeBuiltOn;

    UPROPERTY()
    FString TileName;
};

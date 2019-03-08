// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Talker.h"
#include "TalkingMesh.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_07_API ATalkingMesh : public AStaticMeshActor, public ITalker
{
    GENERATED_BODY()
    
public:
    ATalkingMesh();
    void StartTalking_Implementation();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PostBeginPlay.h"
#include "PostBeginPlayTest.generated.h"

UCLASS()
class CHAPTER_07_API APostBeginPlayTest : public AActor, public IPostBeginPlay
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APostBeginPlayTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

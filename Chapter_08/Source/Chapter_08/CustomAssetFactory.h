// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "CustomAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_08_API UCustomAssetFactory : public UFactory
{
    GENERATED_BODY()
    
public:
    UCustomAssetFactory();

    virtual UObject* FactoryCreateNew(UClass* InClass,
        UObject* InParent, FName InName, EObjectFlags Flags,
        UObject* Context, FFeedbackContext* Warn, FName
        CallingContext) override;
};

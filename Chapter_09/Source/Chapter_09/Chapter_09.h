// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CookbookStyle.h"

class Chapter_09Module : public FDefaultGameModuleImpl
{
    virtual void StartupModule() override
    {
        FCookbookStyle::Initialize();
    };
    virtual void ShutdownModule() override
    {
        FCookbookStyle::Shutdown();
    };
};
// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomHUDGameMode.h"
#include "CustomHUD.h"

ACustomHUDGameMode::ACustomHUDGameMode() : AGameModeBase()
{
    HUDClass = ACustomHUD::StaticClass();
}
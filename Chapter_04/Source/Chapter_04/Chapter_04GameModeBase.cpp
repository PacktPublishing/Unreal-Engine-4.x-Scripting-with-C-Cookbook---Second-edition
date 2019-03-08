// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_04GameModeBase.h"
#include "InventoryCharacter.h"

AChapter_04GameModeBase::AChapter_04GameModeBase()
{
    DefaultPawnClass = AInventoryCharacter::StaticClass();
}
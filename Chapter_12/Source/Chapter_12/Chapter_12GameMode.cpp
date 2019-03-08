// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Chapter_12GameMode.h"
#include "Chapter_12Character.h"
#include "NetworkHUD.h"
#include "UObject/ConstructorHelpers.h"

AChapter_12GameMode::AChapter_12GameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

    HUDClass = ANetworkHUD::StaticClass();
}

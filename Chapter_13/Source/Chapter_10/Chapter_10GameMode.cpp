// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Chapter_10GameMode.h"
#include "Chapter_10Character.h"
#include "UObject/ConstructorHelpers.h"

AChapter_10GameMode::AChapter_10GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

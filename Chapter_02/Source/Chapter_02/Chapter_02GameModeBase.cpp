// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_02GameModeBase.h"


void AChapter_02GameModeBase::BeginPlay()
{
	AChapter_02GameModeBase * gm = Cast<AChapter_02GameModeBase>( GetWorld()->GetAuthGameMode() );

	if( gm )
	{
		// Create object
		UUserProfile* newobject = NewObject<UUserProfile>( (UObject*)GetTransientPackage(), 
															UUserProfile::StaticClass() );
		// Destroy object
		if(newobject)
		{
			newobject->ConditionalBeginDestroy();
			newobject = nullptr;
		}
	}

}

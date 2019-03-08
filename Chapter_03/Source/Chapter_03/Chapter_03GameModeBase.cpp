// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_03GameModeBase.h"
#include "Action.h"

void AChapter_03GameModeBase::BeginPlay()
{
	// Create an object
	UAction * action = NewObject<UAction>(GetTransientPackage(), 
										  UAction::StaticClass() 
										  /* RF_* flags */ ); 

	// Destroy an object
	action->ConditionalBeginDestroy();

	// Force garbage collection
	GetWorld()->ForceGarbageCollection( true ); 


	
}
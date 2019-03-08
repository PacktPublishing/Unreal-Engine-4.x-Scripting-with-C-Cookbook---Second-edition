// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_06GameModeBase.h"
#include "Blueprint/UserWidget.h"

void AChapter_06GameModeBase::BeginPlay()
{
    Super::BeginPlay();

    if(Widget)
    {
        UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(), Widget);

        if(Menu)
        {
            Menu->AddToViewport();

            GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
        }
        
    }
    
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "NonSelectableCube.h"

bool ANonSelectableCube::IsSelectable()
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Not Selectable"); 
    return false;
}

bool ANonSelectableCube::TrySelect()
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Refusing Selection");
    return false;
}

void ANonSelectableCube::Deselect()
{
    unimplemented();
}
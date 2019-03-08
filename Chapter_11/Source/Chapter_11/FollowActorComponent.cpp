// Fill out your copyright notice in the Description page of Project Settings.

#include "FollowActorComponent.h"

// Sets default values for this component's properties
UFollowActorComponent::UFollowActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFollowActorComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UFollowActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    FVector toFollow = target->GetActorLocation() - GetOwner()->GetActorLocation();

    FMatrix rotationMatrix = FRotationMatrix::MakeFromXZ(toFollow, GetOwner()->GetActorUpVector());

    GetOwner()->SetActorRotation(rotationMatrix.Rotator());

}


// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractingPawn.h"
#include "Interactable.h"
#include "Camera/PlayerCameraManager.h"
#include "CollisionQueryParams.h"
#include "WorldCollision.h"

void AInteractingPawn::TryInteract()
{
    APlayerController* MyController = Cast<APlayerController>(Controller);

    if (MyController)
    {
        APlayerCameraManager* MyCameraManager = MyController->PlayerCameraManager;

        auto StartLocation = MyCameraManager->GetCameraLocation();
        auto EndLocation = StartLocation + (MyCameraManager->GetActorForwardVector() * 100);

        FCollisionObjectQueryParams Params;
        FHitResult HitResult;

        GetWorld()->SweepSingleByObjectType(HitResult, StartLocation, 
                                            EndLocation, 
                                            FQuat::Identity,
                                            FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects), 
                                            FCollisionShape::MakeSphere(25),
                                            FCollisionQueryParams(FName("Interaction"), true, this));

        if (HitResult.Actor != nullptr)
        {
            auto Class = HitResult.Actor->GetClass();
            if (Class->ImplementsInterface(UInteractable::StaticClass()))
            {
                if (IInteractable::Execute_CanInteract(HitResult.Actor.Get()))
                {
                    IInteractable::Execute_PerformInteract(HitResult.Actor.Get());
                }
            }
        }

    }


}

void AInteractingPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
    Super::SetupPlayerInputComponent(InInputComponent);
    InInputComponent->BindAction("Interact", IE_Released, this, &AInteractingPawn::TryInteract);
}
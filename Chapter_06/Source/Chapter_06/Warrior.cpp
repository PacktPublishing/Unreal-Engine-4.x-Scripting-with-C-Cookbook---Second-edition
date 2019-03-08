// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"
#include "GameFramework/PlayerInput.h"
#include "Chapter_06GameModeBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AWarrior::AWarrior()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    lastInput = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void AWarrior::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    float len = lastInput.Size();

    // If the player's input is greater than 1, normalize it
    if (len > 1.f)
    {
        lastInput /= len;
    }
            
    AddMovementInput(GetActorForwardVector(), lastInput.Y);
    AddMovementInput(GetActorRightVector(), lastInput.X);

    // Zero off last input values
    lastInput = FVector2D(0.f, 0.f);
}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Forward", this, &AWarrior::Forward);
    PlayerInputComponent->BindAxis("Back", this, &AWarrior::Back);
    PlayerInputComponent->BindAxis("Right", this, &AWarrior::Right);
    PlayerInputComponent->BindAxis("Left", this, &AWarrior::Left);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AWarrior::Jump);

    // Example of adding bindings via code instead of the editor
    FInputAxisKeyMapping backKey("Back", EKeys::S, 1.f);
    FInputActionKeyMapping jump("Jump", EKeys::SpaceBar, 0, 0, 0, 0);

    GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(backKey);
    GetWorld()->GetFirstPlayerController()->PlayerInput->AddActionMapping(jump);

    // Calling function for HotKey
    auto GameMode = Cast<AChapter_06GameModeBase>(GetWorld()->GetAuthGameMode());
    auto Func = &AChapter_06GameModeBase::ButtonClicked;

    if(GameMode && Func)
    {
        PlayerInputComponent->BindAction("HotKey_UIButton_Spell", IE_Pressed, GameMode, Func);
    }
    
}

void AWarrior::Forward(float amount)
{
    // We use a += of the amount added so that when the other function 
    // modifying .Y (::Back()) affects lastInput, it won't overwrite 
    // with 0's 
    lastInput.Y += amount;
}

void AWarrior::Back(float amount)
{
    // In this case we are using -= since we are moving backwards
    lastInput.Y -= amount;
}

void AWarrior::Right(float amount)
{
    lastInput.X += amount;
}

void AWarrior::Left(float amount)
{
    lastInput.X -= amount;
}

void AWarrior::OnOverlapsBegin_Implementation(
    UPrimitiveComponent* Comp,
    AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult&SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior began"));
}

void AWarrior::OnOverlapsEnd_Implementation(
    UPrimitiveComponent* Comp,
    AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior ended"));
}

void AWarrior::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    if (RootComponent)
    {
        // Attach contact function to all bounding components. 
        GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AWarrior::OnOverlapsBegin);
        GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AWarrior::OnOverlapsEnd);
    }
}



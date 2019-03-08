// Fill out your copyright notice in the Description page of Project Settings.

#include "CollectibleObject.h"
#include "Components/SphereComponent.h"
#include "ConstructorHelpers.h"



// Sets default values
ACollectibleObject::ACollectibleObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Must be true for an Actor to replicate anything
    bReplicates = true;

    // Create a sphere collider for players to hit
    USphereComponent * SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

    // Sets the root of our object to be the sphere collider
    RootComponent = SphereCollider;

    // Sets the size of our collider to have a radius of
    // 64 units
    SphereCollider->InitSphereRadius(64.0f);

    // Makes it so that OnBeginOverlap will be called
    // whenever something hits this.
    SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectibleObject::OnBeginOverlap);

    // Create a visual to make it easier to see
    UStaticMeshComponent * SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

    // Attach the static mesh to the root
    SphereVisual->SetupAttachment(RootComponent);

    // Get a reference to a sphere mesh
    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

    // Assign the mesh if valid
    if (MeshAsset.Object != nullptr)
    {
        SphereVisual->SetStaticMesh(MeshAsset.Object);
    }

    // Resize to be smaller than the larger sphere collider
    SphereVisual->SetWorldScale3D(FVector(0.5f));


}

// Called when the game starts or when spawned
void ACollectibleObject::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACollectibleObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Event called when something starts to overlaps the
// sphere collider
void ACollectibleObject::OnBeginOverlap(
    class UPrimitiveComponent* HitComp,
    class AActor* OtherActor,
    class UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    // If I am the server
    if (Role == ROLE_Authority)
    {
        // Then a coin will be gained!
        UpdateScore(1);
        Destroy();
    }
}

// Do something here that modifies game state.
void ACollectibleObject::UpdateScore_Implementation(int32
    Amount)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f,
            FColor::Green,
            "Collected!");
    }
}

// Optionally validate the request and return false if the
// function should not be run.
bool ACollectibleObject::UpdateScore_Validate(int32 Amount)
{
    return true;
}


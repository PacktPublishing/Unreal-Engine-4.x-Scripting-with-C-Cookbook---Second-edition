// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFirstActor.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off 
	// to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a StaticMeshComponent on this object and assigns Mesh 
	// to it
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>
		   ("BaseMeshComponent");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// Check if the MeshAsset is valid before setting it
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);		
	}

}

// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


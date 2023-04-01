// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->mpStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	this->placedLocation = FVector(0.0f);
	this->initialLocation = FVector(0.0f);
	this->worldOrigin = FVector(0.0f, 0.0f, 0.0f);

	this->bInitializeFloaterLocations = false;
	this->bShouldFloat = false;
	this->initialDirection = FVector(1.0f, 1.0f, 1.0f);
	this->initialForce = FVector(0.0f, 0.0f, 0.0f);
	this->initialTorque = FVector(0.0f, 0.0f, 0.0f);
	this->runningTime = 0.0f;

	a = 0.0f;
	b = 0.0f;
	c = 0.0f;
	d = 0.0f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	float fInitialX = FMath::FRandRange(-500.0f, 500.0f);
	float fInitialY = FMath::FRandRange(-500.0f, 500.0f);
	float fInitialZ = FMath::FRandRange(0.0f, 500.0f);

	this->initialLocation.X = fInitialX;
	this->initialLocation.Y = fInitialY;
	this->initialLocation.Z = fInitialZ;
	//this->initialLocation *= 500.f;
	
	this->placedLocation = GetActorLocation();
	if (bInitializeFloaterLocations)
	{
		SetActorLocation(this->initialLocation);
	}

	this->baseZLocation = this->placedLocation.Z;
	//mpStaticMesh->AddForce(initialForce);
	//mpStaticMesh->AddTorqueInRadians(initialTorque);
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat) 
	{

		FVector newLocation = GetActorLocation();

		newLocation.Z = baseZLocation + a *  FMath::Sin(b * runningTime - c) + d;
		SetActorLocation(newLocation);
		runningTime += DeltaTime;
	}

}


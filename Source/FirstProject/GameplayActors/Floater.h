// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ActorMeshComponents")
	UStaticMeshComponent* mpStaticMesh;

	// Location used by SetActorLocation when BeginPlay is called
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FloaterVariables")
	FVector initialLocation;

	// Location of the actor when dragged from the Editor
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "FloaterVariables")
	FVector placedLocation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "FloaterVariables")
	FVector worldOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables")
	FVector initialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables")
	bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FloaterVariables")
	bool bInitializeFloaterLocations;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FloaterVariables")
	FVector initialForce;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FloaterVariables")
	FVector initialTorque;

	/// <summary>
  /// Amplitude - How much we oscillate up and down
  /// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables")
	float a;
	/// <summary>
	/// Period - 2 * PI / ABS(b)
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables")
	float b;
	/// <summary>
	/// Phase Shift is C / B
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables")
	float c;
	/// <summary>
	/// Vertical Shift
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloaterVariables")
	float d;
private:
	UPROPERTY()
	float runningTime;
	UPROPERTY()
	float baseZLocation;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	const FVector MOVEMENT_SPEED = FVector(1.0f);
};

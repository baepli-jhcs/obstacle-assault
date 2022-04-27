// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include "ElevatorPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AElevatorPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AElevatorPlatform();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// create original rotation property
	FVector OriginalRotation;

	FVector OriginalLocation;

	UPROPERTY(EditAnywhere, Category = "Elevator")
		float MoveDistance;

	UPROPERTY(EditAnywhere, Category = "Elevator")
		float MoveSpeed;
	
	UPROPERTY(EditAnywhere, Category = "Elevator")
		float RotationSpeed;


	bool IsOnPlatform() const;
};

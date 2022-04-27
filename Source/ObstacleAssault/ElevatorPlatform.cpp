// Fill out your copyright notice in the Description page of Project Settings.

#include "ElevatorPlatform.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AElevatorPlatform::AElevatorPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AElevatorPlatform::BeginPlay()
{
	Super::BeginPlay();
	OriginalLocation = GetActorLocation();
	OriginalRotation = GetActorRotation().Vector();
}

// Called every frame
void AElevatorPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	FVector Rotation = GetActorRotation().Vector();
	
	if (IsOnPlatform()) {
		if (Location.Z < OriginalLocation.Z + MoveDistance) {
			Location.Z += MoveSpeed * DeltaTime;
		}
		else {
			Location.Z = OriginalLocation.Z + MoveDistance;
		}
	}
	else {
		if (Location.Z > OriginalLocation.Z) {
			Location.Z -= MoveSpeed * DeltaTime;
		}
		else {
			Location.Z = OriginalLocation.Z;
		}
	}

	SetActorLocation(Location);
}

bool AElevatorPlatform::IsOnPlatform() const {
	APlayerController* Player = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FVector PlayerPos = Player->GetPawn()->GetActorLocation();
	FVector PlayerBounds = Player->GetPawn()->GetComponentsBoundingBox().GetExtent();

	// get platform position
	FVector PlatformPos = GetActorLocation();
	FVector PlatformBounds = GetComponentsBoundingBox().GetExtent();

	// check if player is on platform
	return (PlayerPos.X > PlatformPos.X - PlatformBounds.X && PlayerPos.X < PlatformPos.X + PlatformBounds.X &&
		PlayerPos.Y > PlatformPos.Y - PlatformBounds.Y && PlayerPos.Y < PlatformPos.Y + PlatformBounds.Y);
}
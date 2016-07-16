// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


// Sets default values
ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true; // We won't be ticked by default
}


// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay(); // Call parent class tick function

	ATank* Tank = GetControlledTank();
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("Possessing %s"), *Tank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No tank found!"));
	}
}


// Called every frame
void ATankPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime ); // Call parent class tick function
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


// Gets the hit location where the crosshair is and returns true if within the tanks range
bool ATankPlayerController::GetCrosshairHit( FVector& out_HitLocation ) const
{
	float MaxRange = GetControlledTank()->GetMaxTargetRange();

	// TODO Line-trace to the crosshair
	// TODO Set the hit location to object hit within range, or location at max range

	out_HitLocation = FVector(1.f);
	return true;
}


// Aims the turret towards where the crosshair is aiming
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	// Tank has a max range for accurate targeting, but shell can go further.

	FVector HitLocation;
	// Get the line-trace location
	if (GetCrosshairHit(HitLocation))
	{
		// TODO Make the controlled tank aim towards the hit location
		UE_LOG(LogTemp, Warning, TEXT("Hitlocation %s"), *HitLocation.ToString());
	}
}


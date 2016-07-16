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


// Find the look direction from the crosshair location
FVector ATankPlayerController::GetLookDirection() const
{
	// Get the viewport size
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	// Find the crosshair screen position
	FVector2D ScreenPosition(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	// De-project the screen position of the crosshair to world direction
	FVector WorldLocation, WorldDirection;
	DeprojectScreenPositionToWorld(ScreenPosition.X, ScreenPosition.Y, WorldLocation, WorldDirection);

	return WorldDirection;
}


// Gets the hit location where the crosshair is and returns true if within the tanks range
FVector ATankPlayerController::GetCrosshairHit() const
{
	float MaxRange = GetControlledTank()->GetMaxTargetRange() * 100.f;

	FVector LookDirection(GetLookDirection());

	// Line-trace along that look direction
	FHitResult HitResult;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, 
		PlayerCameraManager->GetCameraLocation(), 
		LookDirection * MaxRange, 
		ECollisionChannel::ECC_Visibility))
	{
		// Return the hit location
		return HitResult.Location;
	}
	// No hit, return MaxRange location
	return FVector(PlayerCameraManager->GetCameraLocation() + LookDirection * MaxRange);
}


// Aims the turret towards where the crosshair is aiming
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	// Get the line-traced aiming hit location
	FVector HitLocation = GetCrosshairHit();
	
	// Make the controlled tank aim towards the hit location
	GetControlledTank()->AimAt(HitLocation);
}


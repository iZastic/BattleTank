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
	// Aim towards crosshair
	UE_LOG(LogTemp, Warning, TEXT("I NEED TO DO SOMETHING"));
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	/* Course comments
		Get the world location where the crosshair is pointed
		If it hits the landscape
			Tell the controlled tank to aim at this point
	*/
	// The turret should always move toward the crosshair if capable
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay(); // Call parent class tick function  

	ATank* Tank = GetControlledTank();
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("AI tank is %s"), *Tank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No tank found!"));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player tank is %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No player tank found!"));
	}
}


// Called every frame
void ATankAIController::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime); // Call parent class tick function

	if (GetPlayerTank())
	{
		// TODO If player is out of range, move towards the player
		// TODO If player is within range and AI is ready to fire, FIRE!
		FVector AimLocation(GetPlayerTank()->GetRootComponent()->GetSocketLocation(FName("Turret")));
		GetControlledTank()->AimAt(AimLocation);
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


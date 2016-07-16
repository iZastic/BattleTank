// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	// Sets default values
	ATankPlayerController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaTime ) override;

	ATank* GetControlledTank() const;

	// Gets the hit location where the crosshair is and returns true if within the tanks range
	FVector GetCrosshairHit() const;

	// Aims the turret towards where the crosshair is aiming
	void AimTowardsCrosshair();
};


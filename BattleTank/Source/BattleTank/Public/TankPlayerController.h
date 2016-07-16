// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Sets default values
	ATankPlayerController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaTime ) override;

private:
	// Horizontal location of the cross hair on the screen (0.0 to 1.0)
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	// Vertical location of the cross hair on the screen (0.0 to 1.0)
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3;

	ATank* GetControlledTank() const;

	// Find the look direction from the crosshair location
	FVector GetLookDirection() const;

	// Gets the hit location where the crosshair is and returns true if within the tanks range
	FVector GetCrosshairHit() const;

	// Aims the turret towards where the crosshair is aiming
	void AimTowardsCrosshair();
};


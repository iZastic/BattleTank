// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
}


void UTankAimingComponent::AimAt( FVector TargetLocation, float LaunchSpeed )
{
	if (!Barrel || !Turret) return;

	FVector LaunchVelocity;
	FVector StartLocation(Barrel->GetSocketLocation(FName("Projectile")));

	// Calculate the launch velocity
	if (UGameplayStatics::SuggestProjectileVelocity(this,
		LaunchVelocity,
		StartLocation,
		TargetLocation,
		1000000,
		ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		// Move barrel towards aim direction
		MoveBarrel(LaunchVelocity.GetSafeNormal());
	}

	// TODO Implement aim at function for the tank
}


void UTankAimingComponent::SetTurretReference( UStaticMeshComponent* TurretToSet )
{
	Turret = TurretToSet;
}


void UTankAimingComponent::SetBarrelReference( UTankBarrel* BarrelToSet )
{
	Barrel = BarrelToSet;
}


void UTankAimingComponent::MoveBarrel( FVector AimDirection )
{
	FRotator AimRotation = AimDirection.Rotation();

	Barrel->Elevate(5.f);
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt( FVector TargetLocation, float LaunchSpeed );
	void SetTurretReference(UStaticMeshComponent* TurretToSet);
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

private:
	UStaticMeshComponent* Turret;
	UStaticMeshComponent* Barrel;
	void MoveBarrel( FVector AimDirection );
};


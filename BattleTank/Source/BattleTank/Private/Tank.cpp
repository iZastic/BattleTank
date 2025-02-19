// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// No need to protect pointer as it's created at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}


float ATank::GetMaxTargetRange() const
{
	return MaxTargetRange;
}


void ATank::AimAt(FVector TargetLocation)
{
	TankAimingComponent->AimAt(TargetLocation, 4000.f);
}


void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}


void ATank::SetTurretReference(UStaticMeshComponent * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}


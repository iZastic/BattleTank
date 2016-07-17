// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}


void UTankAimingComponent::AimAt( FVector TargetLocation, float LaunchSpeed )
{
	if (!Barrel) return;

	FVector LaunchVelocity;
	FVector StartLocation(Barrel->GetSocketLocation(FName("Projectile")));

	// Calculate the launch velocity
	if (UGameplayStatics::SuggestProjectileVelocity(this,
		LaunchVelocity,
		StartLocation,
		TargetLocation,
		1000000,
		false,
		0.f,
		0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		// Get aim direction
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%s has a valid target."), *GetOwner()->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s has no valid target"), *GetOwner()->GetName());
	}

	// TODO Implement aim at function for the tank
	//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from %s"), *GetOwner()->GetName(), *TargetLocation.ToString(), *Barrel->GetComponentLocation().ToString());
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}


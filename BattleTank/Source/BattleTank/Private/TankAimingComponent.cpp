// copyright MCo 2016

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"




// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true; // TODO should this tick????

	// ...
}
void UTankAimingComponent::BeginPlay()
{
	//so first fire is after initial reload
	LastFireTime = FPlatformTime::Seconds();
}
void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	if (!ensure(BarrelToSet && TurretToSet)) { return; }
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}
EFiringStatus UTankAimingComponent::GetFiringState()
{
	return FiringStatus;
}

int32 UTankAimingComponent::GetRoundsLeft() const
{
	return RoundsLeft;
}



void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
		if(RoundsLeft <= 0)
		{
			FiringStatus = EFiringStatus::Empty;
		}
		else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
		{
			FiringStatus = EFiringStatus::Reloading;
		}
		else if (IsBarrelMoving())
		{
			FiringStatus = EFiringStatus::Aiming;
		}
		else
		{
			FiringStatus = EFiringStatus::Locked;
		}

}




void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel && Turret)) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace // parameter must be present to prevent bug
	);
	if (bHaveAimSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		ElevateBarrelTowards(AimDirection);
		RotateTurrretTowards(AimDirection);
	}
	else
	{
		return;
	}
}
void UTankAimingComponent::ElevateBarrelTowards(FVector AimDirection)
{
	//work out difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
}
void UTankAimingComponent::RotateTurrretTowards(FVector AimDirection)
{
	//work out difference between current barrel rotation and AimDirection
	auto TurretRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;
	// always yaw the shortest way
	if (FMath::Abs(DeltaRotator.Yaw < 180))
	{
		Turret->Rotate(DeltaRotator.Yaw);
	}
	else
	{
		Turret->Rotate(-DeltaRotator.Yaw);
	}
}
void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (FiringStatus == EFiringStatus::Locked || FiringStatus == EFiringStatus::Aiming)
	{
		//spawn a projectile at the socket location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();

		RoundsLeft--;
	}


}
bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelForward = Barrel->GetForwardVector();
	return !(BarrelForward.Equals(AimDirection, 0.1f));
}
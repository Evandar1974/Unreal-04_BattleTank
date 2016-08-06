// copyright MCo 2016

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
//forward declaration
class UTankBarrel; 

// Holds barrels properties and elivate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);


	// TODO Add set turet reference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:

	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};

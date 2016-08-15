// copyright MCo 2016

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Donkey: Tank C++ Constructor"), *TankName)
}

void ATank::BeginPlay()
{
	Super::BeginPlay();//needed for blueprints to run in begin play
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Donkey: Tank C++ Begin Play"), *TankName)

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}
void ATank::Fire()
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->Fire();
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
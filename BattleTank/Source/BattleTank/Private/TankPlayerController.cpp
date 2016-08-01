// copyright MCo 2016

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	if (!GetControledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Controlled"));

	}
	else
	{
		FString ControlledTank = GetControledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Tank Controlled is %s"), *ControlledTank);
	}
}

void ATankPlayerController::Tick(float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}



ATank* ATankPlayerController::GetControledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControledTank()) { return; }

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation))// has side effect is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *HitLocation.ToString());
		//TODO tell controlled tank to aim at this point
	}
}
// get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}
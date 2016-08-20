// copyright MCo 2016


#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"
#include "Tank.h"
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(TankAimingComponent)) { return; }
	FoundAimingComponent(TankAimingComponent);
}
void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossessedTankDeath);
	}

}
void ATankPlayerController::OnPossessedTankDeath()
{
	StartSpectatingOnly();
}
void ATankPlayerController::Tick(float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; } // eg if not possesing a pawn
	if (!ensure(TankAimingComponent)) {	return;	}
	FVector HitLocation; // out parameter
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	if (bGotHitLocation)// has side effect is going to line trace
	{
		TankAimingComponent->AimAt(HitLocation);
	}
	
}
// get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// find crosshair position in pixel cordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
		// "de-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
		if (GetLookDirection(ScreenLocation, LookDirection))
		{
			// line trace along that direction and see what we hit upto maximum range
			return GetLookVectorHitLocation(LookDirection, HitLocation);
			
		}
		else
		{
			return false;
		}
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;// to be discarded
	DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection);
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		HitLocation = FVector(0.0);
		return false;
	}
}

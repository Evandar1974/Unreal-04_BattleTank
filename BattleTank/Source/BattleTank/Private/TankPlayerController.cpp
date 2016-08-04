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
		GetControledTank()->AimAt(HitLocation);
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
		GetLookVectorHitLocation(LookDirection, HitLocation);
		// line trace along that direction and see what we hit upto maximum range
			//GetLookVectorHitLocation
	}
	return true;
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
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0.0);
	return false;
}

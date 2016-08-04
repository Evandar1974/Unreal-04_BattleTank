// copyright MCo 2016

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	// start the tank moving the barrel so that a shot would hit where the crosshair is
	void AimTowardsCrosshair();
	// return out peramiter
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};

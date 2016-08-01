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
};

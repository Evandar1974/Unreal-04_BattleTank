// copyright MCo 2016

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;
class UTankAimingComponent;
/**
 * Responsible for helping the palyer aim
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	// start the tank moving the barrel so that a shot would hit where the crosshair is
	void AimTowardsCrosshair();
	// return out peramiter
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.33333;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 100000.0;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;



};

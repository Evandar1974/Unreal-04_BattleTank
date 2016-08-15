// copyright MCo 2016

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"//put ne classes above this


//forward declarations
class UTankAimingComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 5000;

private:
	// Sets default values for this pawn's properties
	ATank();
	virtual void BeginPlay() override;
};

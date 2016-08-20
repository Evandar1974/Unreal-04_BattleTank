// copyright MCo 2016

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declarations
class UTankAimingComponent;


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
	
	// how close can the ai tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 8000;
private:

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
		void OnPossessedTankDeath();
	
	
};

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
	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAimingComponent = nullptr;
	
private:

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	void BeginPlay() override;

	// how close can the ai tank get
	float AcceptanceRadius = 3000;
	
};

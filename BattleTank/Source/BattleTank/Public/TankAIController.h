// copyright MCo 2016

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void AimTowardsPlayer();

	ATank* GetControledTank() const;
	ATank* GetPlayerTank() const;
	void BeginPlay() override;


	
};

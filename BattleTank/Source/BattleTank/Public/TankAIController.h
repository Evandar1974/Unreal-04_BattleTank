// copyright MCo 2016

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declarations
class ATank;

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
	void BeginPlay() override;


	
};

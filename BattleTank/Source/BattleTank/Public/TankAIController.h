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
	ATank* GetControledTank() const;
	ATank* GetPlayerTank() const;
	void BeginPlay() override;


	
};

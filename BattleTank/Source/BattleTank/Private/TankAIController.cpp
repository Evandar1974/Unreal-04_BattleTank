// copyright MCo 2016

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsPlayer();
}

void ATankAIController::AimTowardsPlayer()
{
	if (!(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{ 
		return; 
	}
	else
	{
		if (!(Cast<ATank>(GetPawn())))
		{
			return;
		}
		else
		{
			auto PlayerPawn = (GetWorld()->GetFirstPlayerController()->GetPawn());
			auto ControledTank = (Cast<ATank>(GetPawn()));
			//TODO move towards player
			//aim towards player
			ControledTank->AimAt(PlayerPawn->GetActorLocation());
			//Fire if ready
			ControledTank->Fire();
		}
	}
}


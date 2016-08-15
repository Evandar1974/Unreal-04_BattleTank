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

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = (Cast<ATank>(GetPawn()));
	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius );//TODO check radius is in blueprint
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); // TODO dont fire every frame
	}


}


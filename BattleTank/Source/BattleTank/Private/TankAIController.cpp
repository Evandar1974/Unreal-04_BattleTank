// copyright MCo 2016

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!ensure(TankAimingComponent)) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("Aiming component not found"))
		return; 
	}
	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius );//TODO check radius is in blueprint
		TankAimingComponent->AimAt(PlayerTank->GetActorLocation());
		TankAimingComponent->Fire(); // TODO dont fire every frame
	}


}


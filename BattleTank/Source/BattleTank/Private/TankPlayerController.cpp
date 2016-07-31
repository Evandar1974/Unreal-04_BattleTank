// copyright MCo 2016

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	if (!GetControledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Controlled"));
		
	}
	else
	{
		FString ControlledTank = GetControledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Tank Controlled is %s"), *ControlledTank);
	}
}

ATank* ATankPlayerController::GetControledTank() const
{
	return Cast<ATank>(GetPawn());
}


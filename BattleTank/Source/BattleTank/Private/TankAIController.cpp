// copyright MCo 2016

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));
	if (!GetControledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Controlled"));

	}
	else
	{
		FString ControlledTank = GetControledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AI Tank Controlled is %s"), *ControlledTank);
	}
}

ATank* ATankAIController::GetControledTank() const
{
	return Cast<ATank>(GetPawn());
}


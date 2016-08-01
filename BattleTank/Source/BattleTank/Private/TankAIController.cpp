// copyright MCo 2016

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Controlled"));

	}
	else
	{
		if (!GetPlayerTank())
		{
			
			UE_LOG(LogTemp, Warning, TEXT("AI Tank Controlled is %s"), *GetControledTank()->GetName());
			UE_LOG(LogTemp, Warning, TEXT("No Player Tank Present!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AI Tank Controlled is %s"), *GetControledTank()->GetName());
			UE_LOG(LogTemp, Warning, TEXT("%s is targeting %s"), *GetControledTank()->GetName(), *GetPlayerTank()->GetName());
		}
	}

	
}

ATank* ATankAIController::GetControledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = (GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
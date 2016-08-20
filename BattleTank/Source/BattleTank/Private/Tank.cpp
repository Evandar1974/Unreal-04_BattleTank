// copyright MCo 2016

#include "BattleTank.h"
#include "Tank.h"


// Sets default values

float ATank::GetHealthPercent() const 
{
	return (float)CurrentHealth / (float)StartingHealth;
}
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();//needed for blueprints to run in begin play
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	UE_LOG(LogTemp, Warning, TEXT("Base Damage %i. Actual Damage %i"), DamagePoints, DamageToApply);
	if (DamageToApply > 0)
	{
	
		CurrentHealth -= DamageToApply;
		// If the damage depletes our health set our lifespan to zero - which will destroy the actor  
		if (CurrentHealth <= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Tank Died"));
			OnDeath.Broadcast();
			SetLifeSpan(0.001f);
		}
	}
	
	return DamageToApply;

}



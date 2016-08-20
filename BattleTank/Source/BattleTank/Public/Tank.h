// copyright MCo 2016

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"//put new classes above this


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// called by engine when actor damage dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;
	// return current health percentage

	UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealthPercent() const;

	FTankDelegate OnDeath;

private:
	// Sets default values for this pawn's properties
	ATank();
	virtual void BeginPlay() override;

	

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 StartingHealth = 100;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 CurrentHealth;
	float ActualDamage;
	
};

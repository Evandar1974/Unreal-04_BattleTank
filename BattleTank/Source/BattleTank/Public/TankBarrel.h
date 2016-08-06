// copyright MCo 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collison"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; 
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 40; 
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0;
	
};

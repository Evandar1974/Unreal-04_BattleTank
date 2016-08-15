// copyright MCo 2016

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"//put ne classes above this

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
private:
	// Sets default values for this pawn's properties
	ATank();
	virtual void BeginPlay() override;
};

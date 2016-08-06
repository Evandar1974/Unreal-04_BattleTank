// copyright MCo 2016

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//Move Barrell the right amount this frame
	//Given a max elevation speed. and the frame time.
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elivate() called at speed: %f"), DegreesPerSecond);
}


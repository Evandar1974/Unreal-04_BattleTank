// copyright MCo 2016

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	auto TankRoot = GetOwner();
	UE_LOG(LogTemp, Warning, TEXT("intend move forward throw: %f"), Throw);
}


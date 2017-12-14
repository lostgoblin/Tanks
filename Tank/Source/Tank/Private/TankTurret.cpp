// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RotationSpeed)
{
	// move the turret the right amount this frame
	// given a max roatation speed and the frame time
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1, +1);
	auto RotationChange = RotationSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));

}



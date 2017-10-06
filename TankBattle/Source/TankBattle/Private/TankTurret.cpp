// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"


void UTankTurret::RotateTurret(float RelativeSpeed)
{
	// Move the turret the correct amount this frame
	// Given a max rotation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationDiff = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationDiff;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}


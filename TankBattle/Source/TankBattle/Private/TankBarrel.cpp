// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::ElevateBarrel(float DegreesPerSecond)
{
	// Move the barrel the correct amount this frame
	// Given a max elevation speed, and the frame time

	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevation Called at speed %f"), DegreesPerSecond);
}


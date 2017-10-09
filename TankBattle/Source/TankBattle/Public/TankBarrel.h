// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, and +1 is max upward movement
	void ElevateBarrel(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 5;
	
	UPROPERTY(EditAnywhere)
		float MinElevationDegrees = 0;

	UPROPERTY(EditAnywhere)
		float MaxElevationDegrees = 30;





};

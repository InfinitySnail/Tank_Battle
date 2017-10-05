// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void ElevateBarrel(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 20;
	
	UPROPERTY(EditAnywhere)
		float MinElevationDegrees = 0;

	UPROPERTY(EditAnywhere)
		float MaxElevationDegrees = 30;





};

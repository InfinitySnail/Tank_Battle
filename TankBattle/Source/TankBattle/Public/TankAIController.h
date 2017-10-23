// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
		
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float AcceptanceRadius = 3000; // how close the AI tank can get
};

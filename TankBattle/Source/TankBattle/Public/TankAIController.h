// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()


protected:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float AcceptanceRadius = 6000; // how close the AI tank can get

private:
		
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};

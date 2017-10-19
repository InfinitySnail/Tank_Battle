// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float ControlThrow); // ControlThrow is how far forward or back the thumbstick is moved

		UFUNCTION(BlueprintCallable, Category = "Input")
		void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

		UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float Throw);

private:

	// Called from the AI pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankBattle.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
		// fire if aim is locked
		if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
		{ AimingComponent->Fire();}
		
		// TODO fix acceptance radius

	}
}





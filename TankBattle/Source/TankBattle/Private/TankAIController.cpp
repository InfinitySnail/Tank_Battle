// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankBattle.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn())	{return;}
	GetPawn()->DetachFromControllerPendingDestroy();

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





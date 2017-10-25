// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Projectile.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel; 

// Forward declaration
class UTankTurret;

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Locked,
	Aiming,
	Reloading,
	OutOfAmmo
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();
	
	UFUNCTION(BlueprintCallable, Category = "Input")
		void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	EFiringStatus GetFiringStatus() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

protected:
	
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000; 

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	virtual void BeginPlay() override;

	double LastFireTime = 0; // for reload timer
	FVector AimDirection;
	int32 RoundsLeft = 100;
};

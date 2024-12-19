#include "PlayerTank.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.h"

APlayerTank::APlayerTank()
	: ATank()
{
}

void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerTank::Move(float Value)
{
	FVector direction = GetActorForwardVector();
	direction *= Value * Speed;

	SetActorLocation(GetActorLocation() + direction);
}

void APlayerTank::RotateHull(float Value)
{
	FRotator rotator = GetActorRotation();
	rotator.Yaw += Value * TraverseSpeed;
	SetActorRotation(rotator);
}

void APlayerTank::Aim(FVector Value)
{
	if (!TankTurret)
	{
		UE_LOG(LogTemp, Error, TEXT("No turret set"));
		return;
	}

	FRotator rotator = FRotationMatrix::MakeFromX(Value).Rotator();
	rotator.Pitch = 0.0f;
	rotator.Roll = 0.0f;
	TankTurret->SetRelativeRotation(rotator);
}

void APlayerTank::BeginPlay()
{
	Super::BeginPlay();
}

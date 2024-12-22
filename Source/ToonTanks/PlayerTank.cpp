#include "PlayerTank.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.h"
#include "EnemyTank.h"

APlayerTank::APlayerTank()
	: ATank()
{
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

void APlayerTank::Aim(FVector Location)
{
	if (!TankTurret)
	{
		UE_LOG(LogTemp, Error, TEXT("No turret set"));
		return;
	}

	FVector AimDirection = (Location - GetActorLocation()).GetSafeNormal();
	AimDirection.Z = 0.0f;
	TankTurret->SetWorldRotation(AimDirection.Rotation());
}

void APlayerTank::ApplyDamage(float Damage)
{
	ATank::ApplyDamage(Damage);

	if (Health <= 0.0f)
	{
		// Game over
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
}

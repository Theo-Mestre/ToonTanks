#include "EnemyTank.h"
#include "Kismet/GameplayStatics.h"

AEnemyTank::AEnemyTank()
	: ATank()
{
}

void AEnemyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Aim();
}

void AEnemyTank::Aim(FVector Value)
{
	if (TargetTanks == nullptr || TankTurret == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("TargetTanks or TankTurret is nullptr"));
		return;
	}

	FVector HitLocation = TargetTanks->GetActorLocation();
	FVector AimDirection = (HitLocation - GetActorLocation()).GetSafeNormal();
	
	TankTurret->SetWorldRotation(AimDirection.Rotation());
}

void AEnemyTank::BeginPlay()
{
	Super::BeginPlay();

	TargetTanks = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (TargetTanks == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("TargetTanks is nullptr"));
	}
}

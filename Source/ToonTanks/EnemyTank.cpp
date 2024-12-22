#include "EnemyTank.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BillboardComponent.h"

AEnemyTank::AEnemyTank()
	: ATank()
{
}

void AEnemyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsTargetInRange() == false) return;

	Aim();
	EngageTarget(DeltaTime);
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

void AEnemyTank::EngageTarget(float DeltaTime)
{
	if (TargetTanks == nullptr || BillboardComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("TargetTanks or TankTurret is nullptr"));
		return;
	}

	TimeSinceLastShot += DeltaTime;
	if (TimeSinceLastShot < FireRate) return;

	FVector Origin = BillboardComponent->GetComponentLocation();
	Shoot(Origin);
	TimeSinceLastShot = 0.0f;
}

void AEnemyTank::BeginPlay()
{
	Super::BeginPlay();

	// Get target pointer
	TargetTanks = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (TargetTanks == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("TargetTanks is nullptr"));
	}

	BillboardComponent = FindComponentByClass<UBillboardComponent>();
}

bool AEnemyTank::IsTargetInRange() const
{
	FVector DistanceBetwenTanks = TargetTanks->GetActorLocation() - GetActorLocation();
	return DistanceBetwenTanks.Size() < Range;
}

#include "Tank.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

#include "Projectile.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;

	TankHull = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Body"));
	RootComponent = TankHull;

	TankTurret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Turret"));
	TankTurret->SetupAttachment(TankHull);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Move(float Value)
{
}

void ATank::RotateHull(float Value)
{
}

void ATank::Aim(FVector Value)
{
}

void ATank::Shoot(FVector _origin)
{
	if (!ProjectileClass || !TankTurret)
	{
		UE_LOG(LogTemp, Error, TEXT("No projectile class set"));
		return;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.bDeferConstruction = false;
	SpawnParams.Owner = GetOwner();
	SpawnParams.Instigator = GetOwner()->GetInstigator();

	UE_LOG(LogTemp, Warning, TEXT("Shooting at %s"), *_origin.ToString());
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, _origin, TankTurret->GetRelativeRotation() + GetActorRotation(), SpawnParams);

	projectile->SetOwner(this);
	projectile->SetInstigator(GetInstigator());
	projectile->FireInDirection(-projectile->GetActorRightVector());

	if (ShotSound == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No shot sound set"));
		return;
	}

	UGameplayStatics::PlaySoundAtLocation(this, ShotSound, GetActorLocation());
}

void ATank::ApplyDamage(float Damage)
{
	Health -= Damage;
	if (Health > 0) return;
	
	Destroy();
	
	if (DeathSound == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No death sound set"));
		return;
	}
	
	UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

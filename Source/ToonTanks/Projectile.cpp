#include "Projectile.h"

#include "Damageable.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision Component"));
	CollisionComponent->SetCollisionProfileName(TEXT("Projectile"));
	CollisionComponent->SetWorldRotation(FRotator(0.0f, 90.0f, 0.0f));
	CollisionComponent->SetCapsuleSize(10.0f, 22.0f);
	RootComponent = CollisionComponent;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->SetUpdatedComponent(CollisionComponent);
	ProjectileMovement->InitialSpeed = MovementSpeed;
	ProjectileMovement->MaxSpeed = MovementSpeed;
	ProjectileMovement->bShouldBounce = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->SetupAttachment(CollisionComponent);

	TrailParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System"));
	TrailParticleSystem->SetupAttachment(CollisionComponent);
	TrailParticleSystem->SetAutoActivate(true);
	
	OnDestroyParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("On Destroy Particle System"));
	OnDestroyParticleSystem->SetupAttachment(CollisionComponent);
	OnDestroyParticleSystem->SetAutoActivate(false);
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(AActor* other)
{
	Destroy();

	UE_LOG(LogTemp, Warning, TEXT("Projectile hit %s"), *other->GetName());
}

void AProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;
}

void AProjectile::ApplyDamage(AActor* other)
{
	if (other == nullptr) return;
	IDamageable* damageable = Cast<IDamageable>(other);

	if (damageable == nullptr)	return;
	damageable->ApplyDamage(Damage);
}

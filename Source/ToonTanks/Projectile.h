#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();

	void OnHit(AActor* other);

	void FireInDirection(const FVector& ShootDirection);

	UFUNCTION(BlueprintCallable)
	void ApplyDamage(AActor* other);

	void SetDamageValue(float Value) { Damage = Value; }
	float GetDamageValue() const { return Damage; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float Damage = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float MovementSpeed = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UCapsuleComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UParticleSystemComponent* TrailParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UParticleSystemComponent* OnDestroyParticleSystem;
};
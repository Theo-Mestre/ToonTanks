#pragma once

#include "CoreMinimal.h"
#include "Damageable.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UStaticMeshComponent;

UCLASS()
class TOONTANKS_API ATank 
	: public APawn
	, public IDamageable
{
	GENERATED_BODY()

public:
	ATank();

	UFUNCTION(BlueprintCallable)
	virtual void Move(float Value);

	UFUNCTION(BlueprintCallable)
	virtual void RotateHull(float Value);

	UFUNCTION(BlueprintCallable)
	virtual void Aim(FVector Location);

	UFUNCTION(BlueprintCallable)
	virtual void Shoot(FVector _origin);

	UFUNCTION(BlueprintCallable)
	virtual void ApplyDamage(float Damage) override;

	UFUNCTION(BlueprintCallable)
	virtual float GetDamange() override { return Health; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	UStaticMeshComponent* TankHull = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	UStaticMeshComponent* TankTurret = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	TSubclassOf<class AProjectile> ProjectileClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	float Health = 100.f;
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	float Speed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	float TraverseSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	float DamagePerShot = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	class USoundCue* ShotSound = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	class USoundCue* DeathSound = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
	class UParticleSystemComponent* ExplodeParticleSystem;
};
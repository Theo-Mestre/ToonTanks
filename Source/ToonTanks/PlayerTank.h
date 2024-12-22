#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "PlayerTank.generated.h"

UCLASS()
class TOONTANKS_API APlayerTank : public ATank
{
	GENERATED_BODY()
	
public:
	APlayerTank();
	virtual void Move(float Value) override;
	virtual void RotateHull(float Value) override;
	virtual void Aim(FVector Location) override;
	virtual void ApplyDamage(float Damage) override;
};

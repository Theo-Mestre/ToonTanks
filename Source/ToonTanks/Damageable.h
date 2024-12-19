#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Damageable.generated.h"

UINTERFACE(MinimalAPI)
class UDamageable : public UInterface
{
	GENERATED_BODY()
};

class TOONTANKS_API IDamageable
{
	GENERATED_BODY()
public:
	virtual void ApplyDamage(float Damage) = 0;
	virtual float GetDamange() = 0;
};

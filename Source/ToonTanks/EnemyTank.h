// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "EnemyTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AEnemyTank : public ATank
{
	GENERATED_BODY()

public:
	AEnemyTank();
	virtual void Tick(float DeltaTime) override;
	virtual void Aim(FVector Value = FVector()) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	ATank* TargetTanks = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float FireRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float Range = 100.0f;


protected:
	virtual void BeginPlay() override;	
};

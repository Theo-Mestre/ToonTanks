// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "PlayerTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerTank : public ATank
{
	GENERATED_BODY()
	
public:

	APlayerTank();
	virtual void Tick(float DeltaTime) override;
	virtual void Move(float Value) override;
	virtual void RotateHull(float Value) override;
	virtual void Aim(FVector Value) override;

protected:
	virtual void BeginPlay() override;
};
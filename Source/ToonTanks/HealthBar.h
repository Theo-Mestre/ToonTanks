#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

UCLASS()
class TOONTANKS_API UHealthBar : public UUserWidget
{
    GENERATED_BODY()

public:

	void SetHealthPercentage(float Percent);

public:
    UPROPERTY(meta = (BindWidget))
    class UProgressBar* ProgressBar;
};
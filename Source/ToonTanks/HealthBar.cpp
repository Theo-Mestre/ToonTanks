#include "HealthBar.h"
#include "Components/ProgressBar.h"

void UHealthBar::SetHealthPercentage(float Percent)
{
	if (!ProgressBar) { return; }

	ProgressBar->SetVisibility(Percent <= 0.0f ? ESlateVisibility::Hidden : ESlateVisibility::Visible);

	ProgressBar->SetPercent(Percent);
}
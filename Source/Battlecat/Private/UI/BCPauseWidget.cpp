// Battlecat Game. All Rights Reserved.

#include "UI/BCPauseWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"

bool UBCPauseWidget::Initialize()
{
    const auto InitStatus = Super::Initialize();

    if (ClearPauseButton)
    {
        ClearPauseButton->OnClicked.AddDynamic(this, &UBCPauseWidget::OnClearPause);
    }
    return InitStatus;
}

void UBCPauseWidget::OnClearPause()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->ClearPause();
}
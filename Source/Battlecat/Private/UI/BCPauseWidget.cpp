// Battlecat Game. All Rights Reserved.

#include "UI/BCPauseWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"

void UBCPauseWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (ClearPauseButton)
    {
        ClearPauseButton->OnClicked.AddDynamic(this, &UBCPauseWidget::OnClearPause);
    }
}

void UBCPauseWidget::OnClearPause()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->ClearPause();
}
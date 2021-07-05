// Battlecat Game. All Rights Reserved.

#include "UI/BCGameDataWidget.h"
#include "BCGameModeBase.h"
#include "Player/BCPlayerState.h"

int32 UBCGameDataWidget::GetKillsNum() const
{
    const auto PlayerState = GetBCPlayerState();
    return PlayerState ? PlayerState->GetKillsNum() : 0;
}

int32 UBCGameDataWidget::GetCurrentRoundNum() const
{
    const auto GameMode = GetBCGameMode();
    return GameMode ? GameMode->GetCurrentRoundNum() : 0;
}

int32 UBCGameDataWidget::GetTotalRoundsNum() const
{
    const auto GameMode = GetBCGameMode();
    return GameMode ? GameMode->GetGameData().RoundsNum : 0;
}

int32 UBCGameDataWidget::GetRoundSecondsRemaining() const
{
    const auto GameMode = GetBCGameMode();
    return GameMode ? GameMode->GetRoundSecondsRemaining() : 0;
}

ABCGameModeBase* UBCGameDataWidget::GetBCGameMode() const
{
    return GetWorld() ? Cast<ABCGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}

ABCPlayerState* UBCGameDataWidget::GetBCPlayerState() const
{
    return GetOwningPlayer() ? Cast<ABCPlayerState>(GetOwningPlayer()->PlayerState) : nullptr;
}
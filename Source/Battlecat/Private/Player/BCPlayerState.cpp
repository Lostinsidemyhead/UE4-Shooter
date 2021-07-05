// Battlecat Game. All Rights Reserved.

#include "Player/BCPlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogBCPlayerState, All, All);

void ABCPlayerState::LogInfo()
{
    UE_LOG(LogBCPlayerState, Display, TEXT("TeamID: %i, Kills: %i, Death: %i"), TeamID, KillsNum, DeathNum);
}

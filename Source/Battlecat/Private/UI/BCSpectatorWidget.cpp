// Battlecat Game. All Rights Reserved.

#include "UI/BCSpectatorWidget.h"
#include "BCUtils.h"
#include "Components/BCRespawnComponent.h"

bool UBCSpectatorWidget::GetRespawnTime(int32& CountDownTime) const
{
    const auto RespawnComponent = BCUtils::GetBCPlayerComponent<UBCRespawnComponent>(GetOwningPlayer());
    if (!RespawnComponent || !RespawnComponent->IsRespawnInProgress()) return false;
    
    CountDownTime = RespawnComponent->GetRespawnCountDown();
    return true;
}

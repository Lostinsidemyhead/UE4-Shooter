// Battlecat Game. All Rights Reserved.

#include "Components/BCRespawnComponent.h"
#include "BCGameModeBase.h"

UBCRespawnComponent::UBCRespawnComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBCRespawnComponent::Respawn(int32 RespawnTime)
{
    if (!GetWorld()) return;

    RespawnCountDown = RespawnTime;
    GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &UBCRespawnComponent::RespawnTimerUpdate, 1.0f, true);
}

void UBCRespawnComponent::RespawnTimerUpdate()
{
    if (--RespawnCountDown == 0)
    {
        if (!GetWorld()) return;
        GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHandle);

        const auto GameMode = Cast<ABCGameModeBase>(GetWorld()->GetAuthGameMode());
        if (!GameMode) return;

        GameMode->RespawnRequest(Cast<AController>(GetOwner()));
    }
}

bool UBCRespawnComponent::IsRespawnInProgress() const
{
    return GetWorld() && GetWorld()->GetTimerManager().IsTimerActive(RespawnTimerHandle);
}

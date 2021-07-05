// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BCRespawnComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLECAT_API UBCRespawnComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBCRespawnComponent();

    void Respawn(int32 RespawnTime);
    int32 GetRespawnCountDown() const { return RespawnCountDown; }
    bool IsRespawnInProgress() const;

private:
    FTimerHandle RespawnTimerHandle;
    int32 RespawnCountDown = 0;

    void RespawnTimerUpdate();
};

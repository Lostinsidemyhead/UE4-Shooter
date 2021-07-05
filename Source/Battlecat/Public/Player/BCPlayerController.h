// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BCPlayerController.generated.h"

class UBCRespawnComponent;

UCLASS()
class BATTLECAT_API ABCPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ABCPlayerController();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UBCRespawnComponent* RespawnComponent;
};

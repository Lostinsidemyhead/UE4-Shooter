// Battlecat Game. All Rights Reserved.


#include "Player/BCPlayerController.h"
#include "Components/BCRespawnComponent.h"

ABCPlayerController::ABCPlayerController()
{
    RespawnComponent = CreateDefaultSubobject<UBCRespawnComponent>("RespawnComponent");
}
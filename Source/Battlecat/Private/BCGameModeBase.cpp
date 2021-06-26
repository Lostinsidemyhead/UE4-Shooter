// Battlecat Game. All Rights Reserved.

#include "BCGameModeBase.h"
#include "Player/BCBaseCharacter.h"
#include "Player/BCPlayerController.h"

ABCGameModeBase::ABCGameModeBase()
{
    DefaultPawnClass = ABCBaseCharacter::StaticClass();
    PlayerControllerClass = ABCPlayerController::StaticClass();
}
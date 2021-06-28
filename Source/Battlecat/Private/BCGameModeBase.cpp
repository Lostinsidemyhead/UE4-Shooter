// Battlecat Game. All Rights Reserved.

#include "BCGameModeBase.h"
#include "Player/BCBaseCharacter.h"
#include "Player/BCPlayerController.h"
#include "UI/BCGameHUD.h"

ABCGameModeBase::ABCGameModeBase()
{
    DefaultPawnClass = ABCBaseCharacter::StaticClass();
    PlayerControllerClass = ABCPlayerController::StaticClass();
    HUDClass = ABCGameHUD::StaticClass();
}
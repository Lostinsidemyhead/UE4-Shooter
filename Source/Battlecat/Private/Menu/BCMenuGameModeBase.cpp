// Battlecat Game. All Rights Reserved.


#include "Menu/BCMenuGameModeBase.h"
#include "Menu/BCMenuPlayerController.h"
#include "Menu/UI/BCMenuHUD.h"

ABCMenuGameModeBase::ABCMenuGameModeBase()
{
    PlayerControllerClass = ABCMenuPlayerController::StaticClass();
    HUDClass = ABCMenuHUD::StaticClass();
}
// Battlecat Game. All Rights Reserved.

#include "Menu/BCMenuPlayerController.h"
#include "BCGameInstance.h"


void ABCMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}
// Battlecat Game. All Rights Reserved.

#include "Menu/BCMenuPlayerController.h"

void ABCMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}
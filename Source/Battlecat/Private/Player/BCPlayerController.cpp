// Battlecat Game. All Rights Reserved.

#include "Player/BCPlayerController.h"
#include "Components/BCRespawnComponent.h"
#include "BCGameModeBase.h"

ABCPlayerController::ABCPlayerController()
{
    RespawnComponent = CreateDefaultSubobject<UBCRespawnComponent>("RespawnComponent");
}

void ABCPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        const auto GameMode = Cast<ABCGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ABCPlayerController::OnMatchStateChanged);
        }
    }
}

void ABCPlayerController::OnMatchStateChanged(EBCMatchState State)
{
    if (State == EBCMatchState::InProgress)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
    else
    {
        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}

void ABCPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (!InputComponent) return;

    InputComponent->BindAction("PauseGame", IE_Pressed, this, &ABCPlayerController::OnPauseGame);
}

void ABCPlayerController::OnPauseGame()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->SetPause(this);
}
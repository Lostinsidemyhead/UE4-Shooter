// Battlecat Game. All Rights Reserved.

#include "BCGameModeBase.h"
#include "Player/BCBaseCharacter.h"
#include "Player/BCPlayerController.h"
#include "UI/BCGameHUD.h"
#include "AIController.h"

DEFINE_LOG_CATEGORY_STATIC(LogBCGameModeBase, All, All);

ABCGameModeBase::ABCGameModeBase()
{
    DefaultPawnClass = ABCBaseCharacter::StaticClass();
    PlayerControllerClass = ABCPlayerController::StaticClass();
    HUDClass = ABCGameHUD::StaticClass();
}

void ABCGameModeBase::StartPlay()
{
    Super::StartPlay();

    SpawnBots();

    CurrentRound = 1;
    StartRound();
}

UClass* ABCGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
    if (InController && InController->IsA<AAIController>())
    {
        return AIPawnClass;
    }
    return Super::GetDefaultPawnClassForController_Implementation(InController);
}
void ABCGameModeBase::SpawnBots()
{
    if (!GetWorld()) return;

    for (int32 i = 0; i < GameData.PlayersNum - 1; ++i)
    {
        FActorSpawnParameters SpawnInfo;
        SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        const auto BCAIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, SpawnInfo);
        RestartPlayer(BCAIController);
    }
}

void ABCGameModeBase::StartRound()
{
    RoundCountDown = GameData.RoundTime;
    GetWorldTimerManager().SetTimer(GameRoundTimerHandle, this, &ABCGameModeBase::GameTimerUpdate, 1.0f, true);
}

void ABCGameModeBase::GameTimerUpdate()
{
    UE_LOG(LogBCGameModeBase, Display, TEXT("Time: %i / Round:%i/%i"), RoundCountDown, CurrentRound, GameData.RoundsNum);

    if (--RoundCountDown == 0)
    {
        GetWorldTimerManager().ClearTimer(GameRoundTimerHandle);

        if (CurrentRound + 1 <= GameData.RoundsNum)
        {
            CurrentRound++;
            ResetPlayers();
            StartRound();
        }
        else
        {
            UE_LOG(LogBCGameModeBase, Display, TEXT("------------GAME OVER------------"));
        }
    }
}

void ABCGameModeBase::ResetPlayers()
{
    if (!GetWorld()) return;

    for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        ResetOnePlayer(It->Get());
    }
}

void ABCGameModeBase::ResetOnePlayer(AController* Controller)
{
    if (Controller && Controller->GetPawn())
    {
        Controller->GetPawn()->Reset();
    }
    RestartPlayer(Controller);
}
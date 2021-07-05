// Battlecat Game. All Rights Reserved.

#include "BCGameModeBase.h"
#include "Player/BCBaseCharacter.h"
#include "Player/BCPlayerController.h"
#include "UI/BCGameHUD.h"
#include "AIController.h"
#include "Player/BCPlayerState.h"
#include "BCUtils.h"
#include "Components/BCRespawnComponent.h"
#include "EngineUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogBCGameModeBase, All, All);

constexpr static int32 MinRoundTimeForRespawn = 5;

ABCGameModeBase::ABCGameModeBase()
{
    DefaultPawnClass = ABCBaseCharacter::StaticClass();
    PlayerControllerClass = ABCPlayerController::StaticClass();
    HUDClass = ABCGameHUD::StaticClass();
    PlayerStateClass = ABCPlayerState::StaticClass();
}

void ABCGameModeBase::StartPlay()
{
    Super::StartPlay();

    SpawnBots();
    CreateTeamsInfo();

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
            GameOver();
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
    SetPlayerColor(Controller);
}

void ABCGameModeBase::CreateTeamsInfo()
{
    if (!GetWorld()) return;

    int32 TeamID = 1;
    for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        const auto Controller = It->Get();
        if (!Controller) continue;

        const auto PlayerState = Cast<ABCPlayerState>(Controller->PlayerState);
        if (!PlayerState) continue;

        PlayerState->SetTeamID(TeamID);
        PlayerState->SetTeamColor(DetermineColorByTeamID(TeamID));
        SetPlayerColor(Controller);
        TeamID = TeamID == 1 ? 2 : 1;
    }
}

FLinearColor ABCGameModeBase::DetermineColorByTeamID(int32 TeamID) const
{
    if (TeamID - 1 < GameData.TeamColors.Num())
    {
        return GameData.TeamColors[TeamID - 1];
    }
    UE_LOG(LogBCGameModeBase, Warning, TEXT("No color for team id: %i, set as default: %s"), TeamID, *GameData.DefaultTeamColor.ToString());
    return GameData.DefaultTeamColor;
}

void ABCGameModeBase::SetPlayerColor(AController* Controller)
{
    UE_LOG(LogTemp, Display, TEXT("COLOR"));

    if (!Controller) return;

    const auto Character = Cast<ABCBaseCharacter>(Controller->GetPawn());
    if (!Character) return;

    const auto PlayerState = Cast<ABCPlayerState>(Controller->PlayerState);
    if (!PlayerState) return;

    Character->SetPlayerColor(PlayerState->GetTeamColor());
}

void ABCGameModeBase::Killed(AController* KillerController, AController* VictimController)
{
    const auto KillerPlayerState = KillerController ? Cast<ABCPlayerState>(KillerController->PlayerState) : nullptr;
    const auto VictimPlayerState = VictimController ? Cast<ABCPlayerState>(VictimController->PlayerState) : nullptr;

    if (KillerPlayerState)
    {
        KillerPlayerState->AddKill();
    }

    if (VictimPlayerState)
    {
        VictimPlayerState->AddDeath();
    }

    StartRespawn(VictimController);
}

void ABCGameModeBase::LogPlayerInfo()
{
    if (!GetWorld()) return;

    for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        const auto Controller = It->Get();
        if (!Controller) continue;

        const auto PlayerState = Cast<ABCPlayerState>(Controller->PlayerState);
        if (!PlayerState) continue;

        PlayerState->LogInfo();
    }
}

void ABCGameModeBase::RespawnRequest(AController* Controller)
{
    ResetOnePlayer(Controller);
}

void ABCGameModeBase::StartRespawn(AController* Controller)
{
    const auto RespawnAvailable = RoundCountDown > MinRoundTimeForRespawn + GameData.RespawnTime;
    if (!RespawnAvailable) return;

    const auto RespawnComponent = BCUtils::GetBCPlayerComponent<UBCRespawnComponent>(Controller);
    if (!RespawnComponent) return;

    RespawnComponent->Respawn(GameData.RespawnTime);
}

void ABCGameModeBase::GameOver()
{
    UE_LOG(LogBCGameModeBase, Display, TEXT("------------GAME OVER------------"));
    LogPlayerInfo();

    for (auto Pawn : TActorRange<APawn>(GetWorld()))
    {
        if (Pawn)
        {
            Pawn->TurnOff();
            Pawn->DisableInput(nullptr);
        }
    }
}

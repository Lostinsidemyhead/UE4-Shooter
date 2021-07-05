// Battlecat Game. All Rights Reserved.

#include "UI/BCGameOverWidget.h"
#include "BCGameModeBase.h"
#include "Player/BCPlayerState.h"
#include "UI/BCPlayerStatRowWidget.h"
#include "Components/VerticalBox.h"
#include "BCUtils.h"

bool UBCGameOverWidget::Initialize()
{
    if (GetWorld())
    {
        const auto GameMode = Cast<ABCGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &UBCGameOverWidget::OnMatchStateChanged);
        }
    }
    return Super::Initialize();
}

void UBCGameOverWidget::OnMatchStateChanged(EBCMatchState State)
{
    if (State == EBCMatchState::GameOver)
    {
        UpdatePlayerStat();
    }
}

void UBCGameOverWidget::UpdatePlayerStat()
{
    if (!GetWorld() || !PlayerStatBox) return;

    PlayerStatBox->ClearChildren();

    for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
    {
        const auto Controller = It->Get();
        if (!Controller) continue;

        const auto PlayerState = Cast<ABCPlayerState>(Controller->PlayerState);
        if (!PlayerState) continue;

        const auto PlayerStatRowWidget = CreateWidget<UBCPlayerStatRowWidget>(GetWorld(), PlayerStatRowWidgetClass);
        if (!PlayerStatRowWidget) continue;

        PlayerStatRowWidget->SetPlayerName(FText::FromString(PlayerState->GetPlayerName()));
        PlayerStatRowWidget->SetKills(BCUtils::TextFromInt(PlayerState->GetKillsNum()));
        PlayerStatRowWidget->SetDeaths(BCUtils::TextFromInt(PlayerState->GetDeathNum()));
        PlayerStatRowWidget->SetTeam(BCUtils::TextFromInt(PlayerState->GetTeamID()));
        PlayerStatRowWidget->SetPlayerIndicatorVisibility(Controller->IsPlayerController());

        PlayerStatBox->AddChild(PlayerStatRowWidget);
    }
}
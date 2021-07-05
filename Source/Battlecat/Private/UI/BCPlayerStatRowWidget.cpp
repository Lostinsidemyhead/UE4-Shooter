// Battlecat Game. All Rights Reserved.

#include "UI/BCPlayerStatRowWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UBCPlayerStatRowWidget::SetPlayerName(const FText& Text)
{
    if (!PlayerNameTextBlock) return;
    PlayerNameTextBlock->SetText(Text);
}

void UBCPlayerStatRowWidget::SetKills(const FText& Text)
{
    if (!KillsTextBlock) return;
    KillsTextBlock->SetText(Text);
}

void UBCPlayerStatRowWidget::SetDeaths(const FText& Text)
{
    if (!DeathsTextBlock) return;
    DeathsTextBlock->SetText(Text);
}

void UBCPlayerStatRowWidget::SetTeam(const FText& Text)
{
    if (!TeamTextBlock) return;
    TeamTextBlock->SetText(Text);
}

void UBCPlayerStatRowWidget::SetPlayerIndicatorVisibility(bool Visible)
{
    if (!PlayerIndicatorImage) return;
    PlayerIndicatorImage->SetVisibility(Visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}
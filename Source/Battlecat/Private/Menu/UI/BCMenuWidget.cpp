// Battlecat Game. All Rights Reserved.

#include "Menu/UI/BCMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "BCGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/HorizontalBox.h"
#include "Menu/UI/BCLevelItemWidget.h"

DEFINE_LOG_CATEGORY_STATIC(LogBCMenuWidget, All, All);

void UBCMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UBCMenuWidget::OnStartGame);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &UBCMenuWidget::OnQuitGame);
    }

    InitLevelItems();
}

void UBCMenuWidget::InitLevelItems()
{
    const auto BCGameInstance = GetBCGameInstance();
    if (!BCGameInstance) return;

    checkf(BCGameInstance->GetLevelsData().Num() != 0, TEXT("Levels data must not be empty!"));

    if (!LevelItemsBox) return;
    LevelItemsBox->ClearChildren();

    for (auto LevelData : BCGameInstance->GetLevelsData())
    {
        const auto LevelItemWidget = CreateWidget<UBCLevelItemWidget>(GetWorld(), LevelItemWidgetClass);
        if (!LevelItemWidget) continue;

        LevelItemWidget->SetLevelData(LevelData);
        LevelItemWidget->OnLevelSelected.AddUObject(this, &UBCMenuWidget::OnLevelSelected);

        LevelItemsBox->AddChild(LevelItemWidget);
        LevelItemWidgets.Add(LevelItemWidget);
    }

    if (BCGameInstance->GetStartupLevel().LevelName.IsNone())
    {
        OnLevelSelected(BCGameInstance->GetLevelsData()[0]);
    }
    else
    {
        OnLevelSelected(BCGameInstance->GetStartupLevel());
    }
}

void UBCMenuWidget::OnLevelSelected(const FLevelData& Data)
{
    const auto BCGameInstance = GetBCGameInstance();
    if (!BCGameInstance) return;

    BCGameInstance->SetStartupLevel(Data);

    for (auto LevelItemWidget : LevelItemWidgets)
    {
        if (LevelItemWidget)
        {
            const auto IsSelected = Data.LevelName == LevelItemWidget->GetLevelData().LevelName;
            LevelItemWidget->SetSelected(IsSelected);
        }
    }
}

void UBCMenuWidget::OnStartGame()
{
    PlayAnimation(HideAnimation);
}

void UBCMenuWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
    if (Animation != HideAnimation) return;

    const auto BCGameInstance = GetBCGameInstance();
    if (!BCGameInstance) return;

    UGameplayStatics::OpenLevel(this, BCGameInstance->GetStartupLevel().LevelName);
}

void UBCMenuWidget::OnQuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

UBCGameInstance* UBCMenuWidget::GetBCGameInstance() const
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->GetGameInstance<UBCGameInstance>();
}

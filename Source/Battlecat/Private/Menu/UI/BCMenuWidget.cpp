// Battlecat Game. All Rights Reserved.

#include "Menu/UI/BCMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "BCGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogBCMenuWidget, All, All);

void UBCMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UBCMenuWidget::OnStartGame);
    }
}

void UBCMenuWidget::OnStartGame()
{
    if (!GetWorld()) return;

    const auto BCGameInstance = GetWorld()->GetGameInstance<UBCGameInstance>();
    if (!BCGameInstance) return;

    if (BCGameInstance->GetStartupLevelName().IsNone())
    {

        UE_LOG(LogBCMenuWidget, Error, TEXT("Level name is NONE"));
        return;
    }

    UGameplayStatics::OpenLevel(this, BCGameInstance->GetStartupLevelName());
}
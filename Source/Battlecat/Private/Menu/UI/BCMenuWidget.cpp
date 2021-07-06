// Battlecat Game. All Rights Reserved.

#include "Menu/UI/BCMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

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
    const FName StartupLevelName = "TestLevel";
    UGameplayStatics::OpenLevel(this, StartupLevelName);
}
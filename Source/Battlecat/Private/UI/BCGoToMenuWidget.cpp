// Battlecat Game. All Rights Reserved.

#include "UI/BCGoToMenuWidget.h"
#include "Components/Button.h"
#include "BCGameInstance.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogBCGoToMenuWidget, All, All);

void UBCGoToMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();
    
    if (GoToMenuButton)
    {
        GoToMenuButton->OnClicked.AddDynamic(this, &UBCGoToMenuWidget::OnGoToMenu);
    }
}

void UBCGoToMenuWidget::OnGoToMenu()
{
    if (!GetWorld()) return;

    const auto BCGameInstance = GetWorld()->GetGameInstance<UBCGameInstance>();
    if (!BCGameInstance) return;

    if (BCGameInstance->GetMenuLevelName().IsNone())
    {

        UE_LOG(LogBCGoToMenuWidget, Error, TEXT("Menu level name is NONE"));
        return;
    }

    UGameplayStatics::OpenLevel(this, BCGameInstance->GetMenuLevelName());
}
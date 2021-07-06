// Battlecat Game. All Rights Reserved.

#include "Menu/UI/BCMenuHUD.h"
#include "Blueprint/UserWidget.h"

void ABCMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (MenuWidgetClass)
    {
        const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
        }
    }
}
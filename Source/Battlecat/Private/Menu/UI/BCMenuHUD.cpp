// Battlecat Game. All Rights Reserved.

#include "Menu/UI/BCMenuHUD.h"
#include "UI/BCBaseWidget.h"

void ABCMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (MenuWidgetClass)
    {
        const auto MenuWidget = CreateWidget<UBCBaseWidget>(GetWorld(), MenuWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
            MenuWidget->Show();
        }
    }
}
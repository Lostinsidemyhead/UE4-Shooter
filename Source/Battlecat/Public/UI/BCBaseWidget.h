// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BCBaseWidget.generated.h"

UCLASS()
class BATTLECAT_API UBCBaseWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    void Show(); 

protected:
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* ShowAnimation;
};

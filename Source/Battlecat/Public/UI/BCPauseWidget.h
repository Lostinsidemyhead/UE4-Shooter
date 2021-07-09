// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/BCBaseWidget.h"
#include "BCPauseWidget.generated.h"

class UButton;

UCLASS()
class BATTLECAT_API UBCPauseWidget : public UBCBaseWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* ClearPauseButton;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnClearPause();
};

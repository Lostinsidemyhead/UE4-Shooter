// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BCPauseWidget.generated.h"

class UButton;

UCLASS()
class BATTLECAT_API UBCPauseWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual bool Initialize() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* ClearPauseButton;

private:
    UFUNCTION()
    void OnClearPause();
};

// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BCMenuWidget.generated.h"

class UButton;

UCLASS()
class BATTLECAT_API UBCMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitGameButton;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnStartGame();

    UFUNCTION()
    void OnQuitGame();
};

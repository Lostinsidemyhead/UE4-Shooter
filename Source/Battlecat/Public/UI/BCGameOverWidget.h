// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/BCBaseWidget.h"
#include "BCCoreTypes.h"
#include "BCGameOverWidget.generated.h"

class UVerticalBox;
class UButton;

UCLASS()
class BATTLECAT_API UBCGameOverWidget : public UBCBaseWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* PlayerStatBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerStatRowWidgetClass;

    UPROPERTY(meta = (BindWidget))
    UButton* ResetLevelButton;

    virtual void NativeOnInitialized() override;

private:
    void OnMatchStateChanged(EBCMatchState  State);
    void UpdatePlayerStat();

    UFUNCTION()
    void OnResetLevel();
};

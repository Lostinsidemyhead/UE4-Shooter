// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/BCBaseWidget.h"
#include "BCCoreTypes.h"
#include "BCMenuWidget.generated.h"

class UButton;
class UHorizontalBox;
class UBCGameInstance;
class UBCLevelItemWidget;

UCLASS()
class BATTLECAT_API UBCMenuWidget : public UBCBaseWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitGameButton;

    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* LevelItemsBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> LevelItemWidgetClass;

    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* HideAnimation;

    virtual void NativeOnInitialized() override;
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

private:
    UPROPERTY()
    TArray<UBCLevelItemWidget*> LevelItemWidgets;

    UFUNCTION()
    void OnStartGame();

    UFUNCTION()
    void OnQuitGame();

    void InitLevelItems();
    void OnLevelSelected(const FLevelData& Data);

    UBCGameInstance* GetBCGameInstance() const;
};

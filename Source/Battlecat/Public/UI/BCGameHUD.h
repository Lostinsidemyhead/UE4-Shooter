// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BCCoreTypes.h"
#include "BCGameHUD.generated.h"

UCLASS()
class BATTLECAT_API ABCGameHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PauseWidgetClass;

    virtual void BeginPlay() override  ;

private:
    UPROPERTY()
    TMap<EBCMatchState, UUserWidget*> GameWidgets;

    UPROPERTY()
    UUserWidget* CurrentWidget = nullptr;

    void DrawCrossHair();
    void OnMatchStateChanged(EBCMatchState State);
};

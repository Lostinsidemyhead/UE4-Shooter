// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BCSpectatorWidget.generated.h"

UCLASS()
class BATTLECAT_API UBCSpectatorWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    bool GetRespawnTime(int32& CountDownTime) const;
};

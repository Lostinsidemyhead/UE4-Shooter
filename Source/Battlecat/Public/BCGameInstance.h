// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BCGameInstance.generated.h"

UCLASS()
class BATTLECAT_API UBCGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    FName GetStartupLevelName() const { return StartupLevelName; }    
    FName GetMenuLevelName() const { return MenuLevelName; }    

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FName StartupLevelName = NAME_None;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FName MenuLevelName = NAME_None;
};

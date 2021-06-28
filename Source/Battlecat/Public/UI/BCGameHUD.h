// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BCGameHUD.generated.h"

/**
 *
 */
UCLASS()
class BATTLECAT_API ABCGameHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

public:
    void DrawCrossHair();
};

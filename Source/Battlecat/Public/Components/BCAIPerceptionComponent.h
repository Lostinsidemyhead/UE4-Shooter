// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "BCAIPerceptionComponent.generated.h"

UCLASS()
class BATTLECAT_API UBCAIPerceptionComponent : public UAIPerceptionComponent
{
    GENERATED_BODY()

public:
    AActor* GetClosestEnemy() const;
};

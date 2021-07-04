// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BCHealthPercentDecorator.generated.h"

UCLASS()
class BATTLECAT_API UBCHealthPercentDecorator : public UBTDecorator
{
    GENERATED_BODY()

public:
    UBCHealthPercentDecorator();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float HealthPercent = 0.6f;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};

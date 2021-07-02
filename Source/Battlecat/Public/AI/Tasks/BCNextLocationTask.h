// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BCNextLocationTask.generated.h"

UCLASS()
class BATTLECAT_API UBCNextLocationTask : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBCNextLocationTask();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, CAtegory = "AI")
    float Radius = 1000.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, CAtegory = "AI")
    FBlackboardKeySelector AimLocationKey;
};

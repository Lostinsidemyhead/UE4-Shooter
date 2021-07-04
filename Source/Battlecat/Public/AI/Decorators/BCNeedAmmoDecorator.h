// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BCNeedAmmoDecorator.generated.h"

class ABCBaseWeapon;

UCLASS()
class BATTLECAT_API UBCNeedAmmoDecorator : public UBTDecorator
{
    GENERATED_BODY()

public:
    UBCNeedAmmoDecorator();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    TSubclassOf<ABCBaseWeapon> WeaponType;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};

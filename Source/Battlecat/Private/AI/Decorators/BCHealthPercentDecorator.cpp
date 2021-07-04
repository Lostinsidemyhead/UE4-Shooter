// Battlecat Game. All Rights Reserved.

#include "AI/Decorators/BCHealthPercentDecorator.h"
#include "AIController.h"
#include "BCUtils.h"
#include "Components/BCHealthComponent.h"

UBCHealthPercentDecorator::UBCHealthPercentDecorator()
{
    NodeName = "Health Percent";
}

bool UBCHealthPercentDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;

    const auto HealthComponent = BCUtils::GetBCPlayerComponent<UBCHealthComponent>(Controller->GetPawn());
    if (!HealthComponent || HealthComponent->IsDead()) return false;

    return HealthComponent->GetHealthPercent() <= HealthPercent;
}
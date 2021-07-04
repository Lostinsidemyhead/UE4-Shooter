// Battlecat Game. All Rights Reserved.

#include "AI/Decorators/BCNeedAmmoDecorator.h"
#include "AIController.h"
#include "BCUtils.h"
#include "Components/BCWeaponComponent.h"

UBCNeedAmmoDecorator::UBCNeedAmmoDecorator()
{
    NodeName = "Need Ammo";
}

bool UBCNeedAmmoDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;

    const auto WeaponComponent = BCUtils::GetBCPlayerComponent<UBCWeaponComponent>(Controller->GetPawn());
    if (!WeaponComponent) return false;

    return WeaponComponent->NeedAmmo(WeaponType);
}
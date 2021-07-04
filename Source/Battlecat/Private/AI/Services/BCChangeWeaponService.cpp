// Battlecat Game. All Rights Reserved.

#include "AI/Services/BCChangeWeaponService.h"
#include "Components/BCWeaponComponent.h"
#include "AIController.h"
#include "BCUtils.h"

UBCChangeWeaponService::UBCChangeWeaponService()
{
    NodeName = "Change Weapon";
}

void UBCChangeWeaponService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (Controller)
    {
        const auto WeaponComponent = BCUtils::GetBCPlayerComponent<UBCWeaponComponent>(Controller->GetPawn());
        if (WeaponComponent && Probability > 0 && FMath::FRand() <= Probability)
        {
            WeaponComponent->NextWeapon();
        }
    }

    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

// Battlecat Game. All Rights Reserved.

#include "Pickups/BCHealthPickup.h"
#include "Components/BCHealthComponent.h"
#include "Components/BCWeaponComponent.h"
#include "BCUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);

bool ABCHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponent = BCUtils::GetBCPlayerComponent<UBCHealthComponent>(PlayerPawn);
    if (!HealthComponent) return false;

    return HealthComponent->TryToAddHealth(HealthAmount);
}
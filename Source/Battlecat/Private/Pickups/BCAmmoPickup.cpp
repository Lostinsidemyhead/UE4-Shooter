// Battlecat Game. All Rights Reserved.

#include "Pickups/BCAmmoPickup.h"
#include "Components/BCHealthComponent.h"
#include "Components/BCWeaponComponent.h"
#include "BCUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);

bool ABCAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponent = BCUtils::GetBCPlayerComponent<UBCHealthComponent>(PlayerPawn);
    if (!HealthComponent || HealthComponent->IsDead()) return false;

    const auto WeaponComponent = BCUtils::GetBCPlayerComponent<UBCWeaponComponent>(PlayerPawn);
    if (!WeaponComponent) return false;

    return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}
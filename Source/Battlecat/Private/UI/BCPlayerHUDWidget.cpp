// Battlecat Game. All Rights Reserved.

#include "UI/BCPlayerHUDWidget.h"
#include "Components/BCHealthComponent.h"
#include "Components/BCWeaponComponent.h"
#include "BCUtils.h"

float UBCPlayerHUDWidget::GetHealthPercent() const
{
    const auto HealthComponent = BCUtils::GetBCPlayerComponent<UBCHealthComponent>(GetOwningPlayerPawn());
    if (!HealthComponent) return 0.0f;

    return HealthComponent->GetHealthPercent();
}

bool UBCPlayerHUDWidget::GetCurrentWeaponUIData(FWeaponUIData& UIData) const
{
    const auto WeaponComponent = BCUtils::GetBCPlayerComponent<UBCWeaponComponent>(GetOwningPlayerPawn());
    if (!WeaponComponent) return false;

    return WeaponComponent->GetWeaponUIData(UIData);
}

bool UBCPlayerHUDWidget::GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const
{
    const auto WeaponComponent = BCUtils::GetBCPlayerComponent<UBCWeaponComponent>(GetOwningPlayerPawn());
    if (!WeaponComponent) return false;

    return WeaponComponent->GetWeaponAmmoData(AmmoData);
}

bool UBCPlayerHUDWidget::IsPlayerAlive() const
{
    const auto HealthComponent = BCUtils::GetBCPlayerComponent<UBCHealthComponent>(GetOwningPlayerPawn());
    return HealthComponent && !HealthComponent->IsDead();
}

bool UBCPlayerHUDWidget::IsPlayerSpectating() const
{
    const auto Controller = GetOwningPlayer();
    return Controller && Controller->GetStateName() == NAME_Spectating;
}
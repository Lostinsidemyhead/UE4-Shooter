// Battlecat Game. All Rights Reserved.

#include "UI/BCPlayerHUDWidget.h"
#include "Components/BCHealthComponent.h"
#include "Components/BCWeaponComponent.h"

float UBCPlayerHUDWidget::GetHealthPercent() const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return 0.0f;

    const auto Component = Player->GetComponentByClass(UBCHealthComponent::StaticClass());
    const auto HealthComponent = Cast<UBCHealthComponent>(Component);
    if (!HealthComponent) return 0.0f;

    return HealthComponent->GetHealthPercent();
}

bool UBCPlayerHUDWidget::GetCurrentWeaponUIData(FWeaponUIData& UIData) const
{
    const auto WeaponComponent = GetWeaponComponent();
    if (!WeaponComponent) return false;

    return WeaponComponent->GetWeaponUIData(UIData);
}

bool UBCPlayerHUDWidget::GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const
{
    const auto WeaponComponent = GetWeaponComponent();
    if (!WeaponComponent) return false;

    return WeaponComponent->GetWeaponAmmoData(AmmoData);
}

UBCWeaponComponent* UBCPlayerHUDWidget::GetWeaponComponent() const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return nullptr;

    const auto Component = Player->GetComponentByClass(UBCWeaponComponent::StaticClass());
    const auto WeaponComponent = Cast<UBCWeaponComponent>(Component);
    return WeaponComponent;
}
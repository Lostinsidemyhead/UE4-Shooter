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

bool UBCPlayerHUDWidget::GetWeaponUIData(FWeaponUIData& UIData) const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return false;

    const auto Component = Player->GetComponentByClass(UBCWeaponComponent::StaticClass());
    const auto WeaponComponent = Cast<UBCWeaponComponent>(Component);
    if (!WeaponComponent) return false;

    return WeaponComponent->GetWeaponUIData(UIData);
}
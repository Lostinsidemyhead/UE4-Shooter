// Battlecat Game. All Rights Reserved.

#include "UI/BCPlayerHUDWidget.h"
#include "Components/BCHealthComponent.h"
#include "Components/BCWeaponComponent.h"
#include "BCUtils.h"

void UBCPlayerHUDWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (GetOwningPlayer())
    {
        GetOwningPlayer()->GetOnNewPawnNotifier().AddUObject(this, &UBCPlayerHUDWidget::OnNewPawn);
        OnNewPawn(GetOwningPlayerPawn());
    }
}

void UBCPlayerHUDWidget::OnNewPawn(APawn* NewPawn)
{
    const auto HealthComponent = BCUtils::GetBCPlayerComponent<UBCHealthComponent>(NewPawn);
    if (HealthComponent && !HealthComponent->OnHealthChanged.IsBoundToObject(this))
    {
        HealthComponent->OnHealthChanged.AddUObject(this, &UBCPlayerHUDWidget::OnHealthChanged);
    }
}

void UBCPlayerHUDWidget::OnHealthChanged(float Health, float HealthDelta)
{
    if (HealthDelta < 0.0f)
    {
        OnTakeDamage();
    }
}

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
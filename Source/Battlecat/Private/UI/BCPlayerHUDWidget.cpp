// Battlecat Game. All Rights Reserved.

#include "UI/BCPlayerHUDWidget.h"
#include "Components/BCHealthComponent.h"
#include "Components/BCWeaponComponent.h"
#include "BCUtils.h"
#include "Components/ProgressBar.h"
#include "Player/BCPlayerState.h"

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
    UpdateHealthBar();
}

void UBCPlayerHUDWidget::OnHealthChanged(float Health, float HealthDelta)
{
    if (HealthDelta < 0.0f)
    {
        OnTakeDamage();
    }

    UpdateHealthBar();
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

int32 UBCPlayerHUDWidget::GetKillsNum() const
{
    const auto Controller = GetOwningPlayer();
    if (!Controller) return 0;

    const auto PlayerState = Cast<ABCPlayerState>(Controller->PlayerState);
    return PlayerState ? PlayerState->GetKillsNum() : 0;
}

void UBCPlayerHUDWidget::UpdateHealthBar()
{
    if (HealthProgressBar)
    {
        HealthProgressBar->SetFillColorAndOpacity(GetHealthPercent() > PercentColorThreshold ? GoodColor : BadColor);
    }
}

FString UBCPlayerHUDWidget::FormatBullets(int32 BulletsNum) const
{
    const int32 MaxLen = 3;
    const TCHAR PrefixSymbol = '0';

    auto BulletStr = FString::FromInt(BulletsNum);
    const auto SymbolsNumToAdd = MaxImmutableSamplers - BulletStr.Len();

    if (SymbolsNumToAdd > 0)
    {
        BulletStr = FString::ChrN(SymbolsNumToAdd, PrefixSymbol).Append(BulletStr);
    }

    return BulletStr;
}

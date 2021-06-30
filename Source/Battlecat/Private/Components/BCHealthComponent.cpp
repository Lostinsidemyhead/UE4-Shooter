// Battlecat Game. All Rights Reserved.

#include "Components/BCHealthComponent.h"
#include "GameFramework/Actor.h"
//#include "GameFramework/Pawn.h"
//#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "TimerManager.h"
//#include "Camera/CameraShake.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All);

UBCHealthComponent::UBCHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBCHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    check(MaxHealth > 0);

    SetHealth(MaxHealth);

    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UBCHealthComponent::OnTakeAnyDamage);
    }
}

void UBCHealthComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || IsDead() || !GetWorld()) return;

    SetHealth(Health - Damage);
    GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);

    if (IsDead())
    {
        OnDeath.Broadcast();
    }
    else if (AutoHeal)
    {
        GetWorld()->GetTimerManager().SetTimer(HealTimerHandle, this, &UBCHealthComponent::HealUpdate, HealUpdateTime, true, HealDelay);
    }

}

void UBCHealthComponent::HealUpdate()
{
    SetHealth(Health + HealModifier);

    if (IsHealthFull() && GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
    }
}

void UBCHealthComponent::SetHealth(float NewHealth)
{
    Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(Health);
}

bool UBCHealthComponent::TryToAddHealth(float HealthAmount)
{
    if (IsDead() || IsHealthFull()) return false;

    SetHealth(Health + HealthAmount);
    return true;
}

bool UBCHealthComponent::IsHealthFull() const
{
    return FMath::IsNearlyEqual(Health, MaxHealth);
}

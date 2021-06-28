// Battlecat Game. All Rights Reserved.

#include "Components/BCWeaponComponent.h"
#include "Weapon/BCBaseWeapon.h"
#include "GameFramework/Character.h"


UBCWeaponComponent::UBCWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UBCWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    SpawnWeapon();
}

void UBCWeaponComponent::SpawnWeapon()
{
    if (!GetWorld()) return;

    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character) return;

    CurrentWeapon = GetWorld()->SpawnActor<ABCBaseWeapon>(WeaponClass);
    if (!CurrentWeapon) return;

    FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
    CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
    CurrentWeapon->SetOwner(Character);
}

void UBCWeaponComponent::StartFire()
{
    if (!CurrentWeapon) return;
    
    CurrentWeapon->StartFire();
}

void UBCWeaponComponent::StopFire()
{
    if (!CurrentWeapon) return;

    CurrentWeapon->StopFire();
}
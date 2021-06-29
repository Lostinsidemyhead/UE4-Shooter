// Battlecat Game. All Rights Reserved.

#include "Weapon/BCBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseWeapon, All, All);

ABCBaseWeapon::ABCBaseWeapon()
{
    PrimaryActorTick.bCanEverTick = false;
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
    SetRootComponent(WeaponMesh);
}

void ABCBaseWeapon::BeginPlay()
{
    Super::BeginPlay();

    check(WeaponMesh);
    checkf(DefaultAmmo.Bullets > 0, TEXT("Bullets count couldn't be less or equal zelo"));
    checkf(DefaultAmmo.Clips > 0, TEXT("Clips count couldn't be less or equal zelo"));

    CurrentAmmo = DefaultAmmo;
}

void ABCBaseWeapon::StartFire() {}

void ABCBaseWeapon::StopFire() {}

void ABCBaseWeapon::MakeShot() {}

APlayerController* ABCBaseWeapon::GetPlayerController() const
{
    const auto Player = Cast<ACharacter>(GetOwner());
    if (!Player) return nullptr;

    return Player->GetController<APlayerController>();
}

bool ABCBaseWeapon::GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const
{
    const auto Controller = GetPlayerController();
    if (!Controller) return false;

    Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
    return true;
}

FVector ABCBaseWeapon::GetMuzzleWorldLocation() const
{
    return WeaponMesh->GetSocketLocation(MuzzleSocketName);
}

bool ABCBaseWeapon::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
    FVector ViewLocation;
    FRotator ViewRotation;
    if (!GetPlayerViewPoint(ViewLocation, ViewRotation)) return false;

    TraceStart = ViewLocation;
    const FVector ShootDirection = ViewRotation.Vector();
    TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
    return true;
}

void ABCBaseWeapon::MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd)
{
    if (!GetWorld()) return;
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());

    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility, CollisionParams);
}

void ABCBaseWeapon::DecreaseAmmo()
{
    if (CurrentAmmo.Bullets == 0)
    {
        UE_LOG(LogBaseWeapon, Warning, TEXT("-------Clip is empty-------"));
        return;
    }

    CurrentAmmo.Bullets--;

    if (IsClipEmpry() && !IsAmmoEmpty())
    {
        StopFire();
        OnClipEmpty.Broadcast();
    }
}

bool ABCBaseWeapon::IsAmmoEmpty() const
{
    return !CurrentAmmo.Infinite && CurrentAmmo.Clips == 0 && IsClipEmpry();
}

bool ABCBaseWeapon::IsClipEmpry() const
{
    return CurrentAmmo.Bullets == 0;
}

void ABCBaseWeapon::ChangeClip()
{

    if (!CurrentAmmo.Infinite)
    {
        if (CurrentAmmo.Clips == 0)
        {
            UE_LOG(LogBaseWeapon, Warning, TEXT("-------No more clips-------"));
            return;
        }
        CurrentAmmo.Clips--;
    }
    CurrentAmmo.Bullets = DefaultAmmo.Bullets;
    UE_LOG(LogBaseWeapon, Display, TEXT("-------Change Clip-------"));
}

bool ABCBaseWeapon::CanReload() const
{
    return CurrentAmmo.Bullets < DefaultAmmo.Bullets && CurrentAmmo.Clips > 0;
}
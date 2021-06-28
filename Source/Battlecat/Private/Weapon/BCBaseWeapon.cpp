// Battlecat Game. All Rights Reserved.

#include "Weapon/BCBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"

ABCBaseWeapon::ABCBaseWeapon()
{
    PrimaryActorTick.bCanEverTick = false;
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
    SetRootComponent(WeaponMesh);
}

void ABCBaseWeapon::BeginPlay()
{
    Super::BeginPlay();
}

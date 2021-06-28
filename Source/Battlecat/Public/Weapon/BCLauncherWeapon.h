// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/BCBaseWeapon.h"
#include "BCLauncherWeapon.generated.h"

class ABCProjectile;

UCLASS() class BATTLECAT_API ABCLauncherWeapon : public ABCBaseWeapon
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<ABCProjectile> ProjectileClass;

    virtual void MakeShot() override;
};

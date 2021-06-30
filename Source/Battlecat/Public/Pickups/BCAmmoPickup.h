// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/BCBasePickup.h"
#include "BCAmmoPickup.generated.h"

class ABCBaseWeapon;

UCLASS()
class BATTLECAT_API ABCAmmoPickup : public ABCBasePickup
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "10.0"))
    int32 ClipsAmount = 10;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, CAtegory = "Pickup")
    TSubclassOf<ABCBaseWeapon> WeaponType;

private:
    virtual bool GivePickupTo(APawn* PlayerPawn) override;
};

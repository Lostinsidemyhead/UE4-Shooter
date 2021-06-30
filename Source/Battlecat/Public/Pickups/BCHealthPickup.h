// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/BCBasePickup.h"
#include "BCHealthPickup.generated.h"

UCLASS()
class BATTLECAT_API ABCHealthPickup : public ABCBasePickup
{
    GENERATED_BODY()
    
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "100.0"))
    float HealthAmount = 100.0f;

private:
     virtual bool GivePickupTo(APawn* PlayerPawn) override;
};

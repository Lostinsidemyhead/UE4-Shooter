// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/BCBaseWeapon.h"
#include "BCRifleWeapon.generated.h"

/**
 *
 */
UCLASS()
class BATTLECAT_API ABCRifleWeapon : public ABCBaseWeapon
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;
    virtual void StopFire() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float TimeBetweenShots = 0.1f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float BulletSpread = 1.5f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DamageAmount = 10.0f;

    virtual void MakeShot() override;
    virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;


private:
    FTimerHandle ShotTimerHandle;
    void MakeDamage(const FHitResult& HitResult);
};

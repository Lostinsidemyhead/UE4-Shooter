// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BCWeaponComponent.generated.h"

class ABCBaseWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLECAT_API UBCWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBCWeaponComponent();

    void StartFire();
    void StopFire();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ABCBaseWeapon> WeaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponAttachPointName = "WeaponPoint";

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    ABCBaseWeapon* CurrentWeapon = nullptr;

    void SpawnWeapon();
};
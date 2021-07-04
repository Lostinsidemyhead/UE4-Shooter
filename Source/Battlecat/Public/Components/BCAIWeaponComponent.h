// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/BCWeaponComponent.h"
#include "BCAIWeaponComponent.generated.h"

UCLASS()
class BATTLECAT_API UBCAIWeaponComponent : public UBCWeaponComponent
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;
    virtual void NextWeapon() override;
};

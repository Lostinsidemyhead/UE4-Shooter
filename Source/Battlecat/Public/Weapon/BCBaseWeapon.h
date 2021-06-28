// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BCBaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class BATTLECAT_API ABCBaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    ABCBaseWeapon();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* WeaponMesh;

    virtual void BeginPlay() override;
};

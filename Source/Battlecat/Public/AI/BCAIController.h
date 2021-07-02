// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BCAIController.generated.h"

class UBCAIPerceptionComponent;

UCLASS()
class BATTLECAT_API ABCAIController : public AAIController
{
    GENERATED_BODY()

public:
    ABCAIController();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UBCAIPerceptionComponent* BCAIPerceptionComponent;

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaTime) override;
};

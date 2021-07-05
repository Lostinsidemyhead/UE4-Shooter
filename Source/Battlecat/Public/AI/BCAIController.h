// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BCAIController.generated.h"

class UBCAIPerceptionComponent;
class UBCRespawnComponent;

UCLASS()
class BATTLECAT_API ABCAIController : public AAIController
{
    GENERATED_BODY()

public:
    ABCAIController();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UBCAIPerceptionComponent* BCAIPerceptionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UBCRespawnComponent* RespawnComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FName FocusOnKeyName = "EnemyActor";

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaTime) override;

private:
    AActor* GetFocusOnActor() const;
};

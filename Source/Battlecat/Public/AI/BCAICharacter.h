// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/BCBaseCharacter.h"
#include "BCAICharacter.generated.h"

class UBehaviorTree;
class UWidgetComponent;

UCLASS()
class BATTLECAT_API ABCAICharacter : public ABCBaseCharacter
{
    GENERATED_BODY()

public:
    ABCAICharacter(const FObjectInitializer& ObjInit);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UWidgetComponent* HealthWidgetComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    float HealthVisibilityDistance = 1500.0f;

    virtual void BeginPlay() override;
    virtual void OnDeath() override;
    virtual void OnHealthChanged(float Health, float HealthDelta) override;

private:
    void UpdateHealthWidgetVisibility();
};

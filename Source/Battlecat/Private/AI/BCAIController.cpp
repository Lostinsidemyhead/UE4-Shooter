// Battlecat Game. All Rights Reserved.

#include "AI/BCAIController.h"
#include "AI/BCAICharacter.h"
#include "Components/BCAIPerceptionComponent.h"

ABCAIController::ABCAIController()
{
    BCAIPerceptionComponent = CreateDefaultSubobject<UBCAIPerceptionComponent>("BCPerceptionComponent");
    SetPerceptionComponent(*BCAIPerceptionComponent);
}

void ABCAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto BCCharacter = Cast<ABCAICharacter>(InPawn);
    if (BCCharacter)
    {
        RunBehaviorTree(BCCharacter->BehaviorTreeAsset);
    }
}

void ABCAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    const auto AimActor = BCAIPerceptionComponent->GetClosestEnemy();
    SetFocus(AimActor);
}

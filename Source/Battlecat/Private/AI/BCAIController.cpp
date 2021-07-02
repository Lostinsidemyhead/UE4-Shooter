// Battlecat Game. All Rights Reserved.

#include "AI/BCAIController.h"
#include "AI/BCAICharacter.h"
#include "Components/BCAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


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
    const auto AimActor = GetFocusOnActor();
    SetFocus(AimActor);
}

AActor* ABCAIController::GetFocusOnActor() const
{
    if (!GetBlackboardComponent()) return nullptr;
    return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}

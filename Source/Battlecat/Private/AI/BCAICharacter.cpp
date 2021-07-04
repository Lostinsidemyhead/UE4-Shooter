// Battlecat Game. All Rights Reserved.

#include "AI/BCAICharacter.h"
#include "AI/BCAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BCAIWeaponComponent.h"
#include "BrainComponent.h"

ABCAICharacter::ABCAICharacter(const FObjectInitializer& ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<UBCAIWeaponComponent>("WeaponComponent"))
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = ABCAIController::StaticClass();

    bUseControllerRotationYaw = false;
    if (GetCharacterMovement())
    {
        GetCharacterMovement()->bUseControllerDesiredRotation = true;
        GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
    }
}

void ABCAICharacter::OnDeath()
{
    Super::OnDeath();
    const auto BCController = Cast<AAIController>(Controller);
    if (BCController && BCController->BrainComponent)
    {
        BCController->BrainComponent->Cleanup();
    }
}
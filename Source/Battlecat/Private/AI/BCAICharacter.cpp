// Battlecat Game. All Rights Reserved.

#include "AI/BCAICharacter.h"
#include "AI/BCAIController.h"

ABCAICharacter::ABCAICharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = ABCAIController::StaticClass();
}
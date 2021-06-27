// Battlecat Game. All Rights Reserved.

#include "Components/BCCharacterMovementComponent.h"
#include "Player/BCBaseCharacter.h"

float UBCCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ABCBaseCharacter* Player = Cast<ABCBaseCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}
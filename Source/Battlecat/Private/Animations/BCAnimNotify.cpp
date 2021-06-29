// Battlecat Game. All Rights Reserved.


#include "Animations/BCAnimNotify.h"

void UBCAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    OnNotified.Broadcast(MeshComp);
    Super::Notify(MeshComp, Animation);
}
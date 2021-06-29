// Battlecat Game. All Rights Reserved.

#include "Animations/BCEquipFinishedAnimNotify.h"

void UBCEquipFinishedAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    OnNotified.Broadcast(MeshComp);
    Super::Notify(MeshComp, Animation);
}
// Battlecat Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/BCBaseCharacter.h"
#include "BCAICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class BATTLECAT_API ABCAICharacter : public ABCBaseCharacter
{
    GENERATED_BODY()

public:
    ABCAICharacter(const FObjectInitializer& ObjInit);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;
};

// Battlecat Game. All Rights Reserved.

#include "AI/BCAICharacter.h"
#include "AI/BCAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BCAIWeaponComponent.h"
#include "BrainComponent.h"
#include "Components/WidgetComponent.h"
#include "UI/BCHealthBarWidget.h"
#include "Components/BCHealthComponent.h"

ABCAICharacter::ABCAICharacter(const FObjectInitializer& ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<UBCAIWeaponComponent>("WeaponComponent"))
{
    AutoPossessAI = EAutoPossessAI::Disabled;
    AIControllerClass = ABCAIController::StaticClass();

    bUseControllerRotationYaw = false;
    if (GetCharacterMovement())
    {
        GetCharacterMovement()->bUseControllerDesiredRotation = true;
        GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
    }

    HealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("HealthWidgetComponent");
    HealthWidgetComponent->SetupAttachment(GetRootComponent());
    HealthWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
    HealthWidgetComponent->SetDrawAtDesiredSize(true);
}

void ABCAICharacter::BeginPlay()
{
    Super::BeginPlay();

    check(HealthWidgetComponent);
}

void ABCAICharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateHealthWidgetVisibility();
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

void ABCAICharacter::OnHealthChanged(float Health, float HealthDelta)
{
    Super::OnHealthChanged(Health, HealthDelta);

    const auto HealthBarWidget = Cast<UBCHealthBarWidget>(HealthWidgetComponent->GetUserWidgetObject());
    if (!HealthBarWidget) return;
    HealthBarWidget->SetHealthPercent(HealthComponent->GetHealthPercent());
}

void ABCAICharacter::UpdateHealthWidgetVisibility()
{
    if (!GetWorld()                                 //
        || !GetWorld()->GetFirstPlayerController()  //
        || !GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator())
        return;

    const auto PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
    const auto Distance = FVector::Distance(PlayerLocation, GetActorLocation());
    HealthWidgetComponent->SetVisibility(Distance < HealthVisibilityDistance, true);
}

// Battlecat Game. All Rights Reserved.

#include "Player/BCBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABCBaseCharacter::ABCBaseCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ABCBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABCBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABCBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ABCBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ABCBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ABCBaseCharacter::LookUp);
    PlayerInputComponent->BindAxis("TurnAround", this, &ABCBaseCharacter::TurnAround);
}

void ABCBaseCharacter::MoveForward(float Amount)
{
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ABCBaseCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void ABCBaseCharacter::LookUp(float Amount)
{
    AddControllerPitchInput(Amount);
}

void ABCBaseCharacter::TurnAround(float Amount)
{
    AddControllerYawInput(Amount);
}

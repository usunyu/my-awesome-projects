// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollector.h"
#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "SpawnVolume.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

    DecayRate = 0.1f;
}

void ABatteryCollectorGameMode::BeginPlay() {
    Super::BeginPlay();

    // find all spawn volume Actors
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

    for (auto Actor : FoundActors)
    {
        ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
        if (SpawnVolumeActor)
        {
            SpawnVolumeActors.AddUnique(SpawnVolumeActor);
        }
    }

    SetCurrentState(EBatteryPlayState::EPlaying);

    ABatteryCollectorCharacter* MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
    if (MyCharacter) {
        PowerToWin = (MyCharacter->GetInitialPower()) * 1.25f;
    }

    if (HUDWidgetClass != nullptr) {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

void ABatteryCollectorGameMode::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    ABatteryCollectorCharacter* MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
    if (MyCharacter) {

        // If our power is greater than needed to win, set the game's state to Won
        if (MyCharacter->GetCurrentPower() > PowerToWin) {
            SetCurrentState(EBatteryPlayState::EWon);
        }
        else if (MyCharacter->GetCurrentPower() > 0) {
            MyCharacter->UpdatePower(-DeltaTime * DecayRate * (MyCharacter->GetInitialPower()));
        }
        else {
            SetCurrentState(EBatteryPlayState::EGameOver);
        }
    }
}

float ABatteryCollectorGameMode::GetPowerToWin() const {
    return PowerToWin;
}

EBatteryPlayState ABatteryCollectorGameMode::GetCurrentState() const
{
    return CurrentState;
}

void ABatteryCollectorGameMode::SetCurrentState(EBatteryPlayState NewState)
{
    //set current state
    CurrentState = NewState;
    // handle the new current state
    HandleNewState(CurrentState);

}

void ABatteryCollectorGameMode::HandleNewState(EBatteryPlayState NewState)
{
    switch (NewState)
    {
        // If the game is playing
    case EBatteryPlayState::EPlaying:
    {
        // spawn volumes active
        for (ASpawnVolume* Volume : SpawnVolumeActors)
        {
            Volume->SetSpawningActive(true);
        }
    }
    break;
    // If we've won the game
    case EBatteryPlayState::EWon:
    {
        // spawn volumes inactive
        for (ASpawnVolume* Volume : SpawnVolumeActors)
        {
            Volume->SetSpawningActive(false);
        }
    }
    break;
    // If we've lost the game
    case EBatteryPlayState::EGameOver:
    {
        // spawn volumes inactive
        for (ASpawnVolume* Volume : SpawnVolumeActors)
        {
            Volume->SetSpawningActive(false);
        }
        // block player input
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (PlayerController)
        {
            PlayerController->SetCinematicMode(true, false, false, true, true);
        }
        // ragdoll the character
        ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
        if (MyCharacter)
        {
            MyCharacter->GetMesh()->SetSimulatePhysics(true);
            MyCharacter->GetMovementComponent()->MovementState.bCanJump = false;
        }
    }
    break;
    // Unknown/default state
    default:
    case EBatteryPlayState::EUnknown:
    {
        // do nothing
    }
    break;
    }

}
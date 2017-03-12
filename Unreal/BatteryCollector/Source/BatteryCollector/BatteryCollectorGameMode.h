// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "BatteryCollectorGameMode.generated.h"

//enum to store the current state of gameplay
UENUM(BlueprintType)
enum class EBatteryPlayState
{
    EPlaying,
    EGameOver,
    EWon,
    EUnknown
};


UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintPure, Category = "Power")
    float GetPowerToWin() const;

    virtual void BeginPlay() override;

    /** Returns the current playing state */
    UFUNCTION(BlueprintPure, Category = "Power")
        EBatteryPlayState GetCurrentState() const;

    /** Sets a new playing state */
    void SetCurrentState(EBatteryPlayState NewState);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProteced = "true"))
    float DecayRate;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProteced = "true"))
    float PowerToWin;

    // The Widget class to user for our HUD screen
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProteced = "true"))
    TSubclassOf<class UUserWidget> HUDWidgetClass;

    // The instance of the HUD
    UPROPERTY()
    class UUserWidget* CurrentWidget;

private:
    EBatteryPlayState CurrentState;

    TArray<class ASpawnVolume*> SpawnVolumeActors;

    /**Handle any function calls that rely upon changing the playing state of our game */
    void HandleNewState(EBatteryPlayState NewState);
};




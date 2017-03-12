// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:
    // Sets default values for this actor's properties
    ABatteryPickup();
	
    // Override the WasCollected function - use Implementation becase it's a Blueprint Native Event
    void WasCollected_Implementation() override;

    // Public's way to access the battery's power level
    float GetPower();

protected:
    // Set the amount of power the battery gives to the character
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProteced = "true"))
    float BatteryPower;
};

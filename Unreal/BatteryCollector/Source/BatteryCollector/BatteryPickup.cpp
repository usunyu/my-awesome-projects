// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"


// Set default values
ABatteryPickup::ABatteryPickup() {
    GetMesh()->SetSimulatePhysics(true);

    // the base power level of battery
    BatteryPower = 150.0f;
}

void ABatteryPickup::WasCollected_Implementation() {
    // Use the base pickup behavior
    Super::WasCollected_Implementation();
    // Destroy the battery
    Destroy();
}

// report the power level of battery
float ABatteryPickup::GetPower() {
    return BatteryPower;
}
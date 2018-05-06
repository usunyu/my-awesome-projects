// Here we define a basic component of a space ship
// Any part that implements the interface Factory.ESEngine
// can replace that part in any ship

import Factory.ESEngine;

public class ESUFOBossEngine implements ESEngine {

    // Factory.EnemyShip contains a reference to the object
    // Factory.ESWeapon. It is stored in the field weapon

    // The Strategy design pattern is being used here

    // When the field that is of type Factory.ESUFOGun is printed
    // the following shows on the screen

    public String toString() {
        return "2000 mph";
    }

}
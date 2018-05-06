package Factory;

//public abstract class Factory.EnemyShip {
//
//    private String name;
//    private double amtDamage;
//
//    public String getName() {
//        return name;
//    }
//
//    public void setName(String newName) {
//        name = newName;
//    }
//
//    public double getDamage() {
//        return amtDamage;
//    }
//
//    public void setDamage(double newDamage) {
//        amtDamage = newDamage;
//    }
//
//    public void displayEnemyShip(){
//        System.out.println(getName() + " is on the screen");
//    }
//
//    public void followHelloShip() {
//        System.out.println(getName() + " is following the hero");
//    }
//
//    public void enemyShipShoots() {
//        System.out.println(getName() + " attacks and does " + getDamage());
//    }
//}

public abstract class EnemyShip {

    private String name;

    // Newly defined objects that represent weapon & engine
    // These can be changed easily by assigning new parts
    // in Factory.UFOEnemyShipFactory or Factory.UFOBossEnemyShipFactory

    ESWeapon weapon;
    ESEngine engine;

    public String getName() {
        return name;
    }

    public void setName(String newName) {
        name = newName;
    }

    abstract void makeShip();

    // Because I defined the toString method in engine
    // when it is printed the String defined in toString goes
    // on the screen

    public void followHeroShip() {

        System.out.println(getName() + " is following the hero at " + engine);

    }

    public void displayEnemyShip() {

        System.out.println(getName() + " is on the screen");

    }

    public void enemyShipShoots() {

        System.out.println(getName() + " attacks and does " + weapon);

    }

    // If any Factory.EnemyShip object is printed to screen this shows up

    public String toString() {

        String infoOnShip = "The " + name + " has a top speed of " + engine +
                " and an attack power of " + weapon;

        return infoOnShip;

    }

}
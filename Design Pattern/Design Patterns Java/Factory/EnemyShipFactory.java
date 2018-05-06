package Factory;

//public class Factory.EnemyShipFactory {
//
//    public Factory.EnemyShip makeEnemyShip(String newShipType) {
//
//        Factory.EnemyShip newShip = null;
//
//        if (newShipType.equals("U")) {
//            return new Factory.UFOEnemyShip();
//        }
//        else if (newShipType.equals("R")) {
//            return new Factory.RocketEnemyShip();
//        }
//        else if (newShipType.equals("B")) {
//            return new Factory.BigUFOEnemyShip();
//        }
//        return null;
//    }
//}

// With an Abstract Factory Pattern you won't
// just build ships, but also all of the components
// for the ships

// Here is where you define the parts that are required
// if an object wants to be an enemy ship

public interface EnemyShipFactory {

    public ESWeapon addESGun();
    public ESEngine addESEngine();

}
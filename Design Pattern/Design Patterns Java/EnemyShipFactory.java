//public class EnemyShipFactory {
//
//    public EnemyShip makeEnemyShip(String newShipType) {
//
//        EnemyShip newShip = null;
//
//        if (newShipType.equals("U")) {
//            return new UFOEnemyShip();
//        }
//        else if (newShipType.equals("R")) {
//            return new RocketEnemyShip();
//        }
//        else if (newShipType.equals("B")) {
//            return new BigUFOEnemyShip();
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
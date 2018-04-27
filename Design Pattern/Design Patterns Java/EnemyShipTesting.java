import java.util.Scanner;

public class EnemyShipTesting {

    public static void main(String[] args) {

////        EnemyShip ufoShip = new UFOEnemyShip();
//
//        EnemyShipFactory shipFactory = new EnemyShipFactory();
//
//        Scanner userInput = new Scanner(System.in);
//
//        String enemyShipOption = "";
//
//        EnemyShip theEnemy = null;
//
//        System.out.print("What type of ship? (U / R / B)");
//
//        if (userInput.hasNextLine()) {
//            enemyShipOption = userInput.nextLine();
//
//            theEnemy = shipFactory.makeEnemyShip(enemyShipOption);
//        }
//
////        if (enemyShipOption.equals("U")) {
////            theEnemy = new UFOEnemyShip();
////        }
////        else if (enemyShipOption.equals("R")) {
////            theEnemy = new RocketEnemyShip();
////        }
//
//        if (theEnemy != null) {
//            doStuffEnemyShip(theEnemy);
//        }
//        else {
//            System.out.println("Enter a U, R or B next time");
//        }

        // EnemyShipBuilding handles orders for new EnemyShips
        // You send it a code using the orderTheShip method &
        // it sends the order to the right factory for creation
        EnemyShipBuilding MakeUFOs = new UFOEnemyShipBuilding();
        EnemyShip theGrunt = MakeUFOs.orderTheShip("UFO");
        System.out.println(theGrunt + "\n");
        EnemyShip theBoss = MakeUFOs.orderTheShip("UFO BOSS");
        System.out.println(theBoss + "\n");
    }

//    public static void doStuffEnemyShip(EnemyShip anEnemyShip) {
//
//        anEnemyShip.displayEnemyShip();
//        anEnemyShip.followHelloShip();
//        anEnemyShip.enemyShipShoots();
//    }
}

public class AnimalPlay {

    public static void main(String[] args) {
        Animal sparky = new Dog();
        Animal tweety = new Bird();

        System.out.println("OOP.Dog: " + sparky.tryToFly());
        System.out.println("OOP.Bird: " + tweety.tryToFly());

        sparky.setFlyingAbility(new ItFlys());
        System.out.println("OOP.Dog: " + sparky.tryToFly());
    }
}
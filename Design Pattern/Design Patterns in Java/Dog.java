public class Dog extends Animal {

    public void digHole() {
        System.out.println("Dig a hole");
    }

    public Dog() {
        super();

        setSound("Bark");
    }

    public void changeVar(int randNum) {
        randNum = 12;
        System.out.println("randNum in method: " + randNum);
    }

    private void bePrivate() {
        System.out.println("In a private method");
    }

    public void accessPrivate() {
        bePrivate();
    }
}
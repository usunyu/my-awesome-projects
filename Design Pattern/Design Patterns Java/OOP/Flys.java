public interface Flys {

    String fly();
}

class ItFlys implements Flys {

    @Override
    public String fly() {
        return "Flying High";
    }
}

class CantFly implements Flys {

    @Override
    public String fly() {
        return "I can't fly";
    }
}
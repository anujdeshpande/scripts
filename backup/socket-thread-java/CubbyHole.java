public class CubbyHole {
    private int contents;

    public int get() {
        System.out.println("  Consumer gets: " + contents);
        return contents;
    }

    public void put(int value) {
        contents = value;
        System.out.println("Producer puts: " + contents);
    }
}


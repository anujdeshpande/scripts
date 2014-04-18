public class Consumer implements Runnable {
    private CubbyHole cubbyhole;

    public Consumer(CubbyHole c) {
        cubbyhole = c;
    }

    public void run() {
        int value = 0;
        for (int i = 1; i <= 5; i++) {
            value = cubbyhole.get();
            try {
                Thread.sleep((int)(Math.random() * 100));
            } catch (InterruptedException e) { }
        }
    }
}

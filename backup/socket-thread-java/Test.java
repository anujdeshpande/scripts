public class Test {
    public static void main( String[] args ) {
	CubbyHole c = new CubbyHole();
	Producer producer = new Producer( c );
	Consumer consumer = new Consumer( c );
	new Thread(producer).start();
	new Thread(consumer).start();
    }
}

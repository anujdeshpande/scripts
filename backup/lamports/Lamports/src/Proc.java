
public class Proc extends Thread  {

	public int aliveTime ;
	
	public int getTime(){
		
		return (int) (System.currentTimeMillis()-aliveTime);
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		aliveTime = (int) System.currentTimeMillis();
	}

}

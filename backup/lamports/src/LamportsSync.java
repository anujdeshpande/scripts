import java.util.ArrayList;
import java.util.Scanner;

public class LamportsSync {
	public static int processCount = 0;
	public static ArrayList<Thread> threadList = new ArrayList<Thread>();

	public static void GUI() {
		String op = "";
		do {
			System.out.println("1. Add Process");
			System.out.println("2. View Clocks");
			System.out.println("3. Send message");
			System.out.println("4. Exit");
			Scanner s = new Scanner(System.in); // take input using Scanner
												// <java.util.Scanner>
			System.out.print(">>>");
			op = s.next();
			if (op.equals("1")) {
				System.out.println(" Process created with PID:" + addProcess());
			}
			if (op.equals("2")) {
				System.out
						.println(" Current logical clocks for all processes are:");
				printClockTimes();
			}
			if (op.equals("3")) {
				System.out.println(" Enter from and to PID: ");

				sendMessage(s.next(), s.next());
			}

		} while (!op.equals("4"));

	}

	private static void sendMessage(String next, String next2) {
		// TODO Auto-generated method stub

	}

	public static void main(String args[]) {
		GUI();
	}

	public static int addProcess() {
		Proc t = new Proc();
		threadList.add(t);
		t.start();
		processCount = processCount + 1;
		return processCount;
	}

	public static void printClockTimes(){
	    for (int i=0;i<threadList.size();i++)
	    {
	        System.out.println(Integer.toString(((Proc)threadList.get(i)).getTime()));
	    }
	}
}

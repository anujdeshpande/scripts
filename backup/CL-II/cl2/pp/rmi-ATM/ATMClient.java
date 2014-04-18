/*This is the client file accessing the remote object for RMI of ATM operations*/

import java.rmi.*;
import java.util.Scanner;
import java.io.IOException;

public class ATMClient
{
	//All the attr's of class need to be static
	static String msg="blank";
	static String op;
	static int balance;
	static ATM obj=null;
	public static void main(String args[])
	{
		try
		{
			obj=(ATM)Naming.lookup("/ATMmachine"); //registry look up
			
			/*-------------ATM Machine Operations done using the reference to remote object--------*/
			System.out.println("What to do ? :");
			System.out.println("\tinit x");
			System.out.println("\twithdraw x");
			System.out.println("\tcheck-balance");
			System.out.println("\tbye");
			
			Scanner s=new Scanner(System.in);	//take input using Scanner <java.util.Scanner>
			System.out.print(">>>");
			op=s.next();			
			while(!op.equals("bye"))
			{
				if(op.equals("init"))
				{
					balance=s.nextInt();
					obj.init(balance);		//RMI call
					System.out.println("Now your balance is : "+balance);
				}
				if(op.equals("withdraw"))
				{
					System.out.println("Old Balance :"+balance);				
					int b=s.nextInt();
					if(b%100==0)
					{
						balance=obj.withDraw(b);	//RMI call
						System.out.println("New Balance :"+balance);	
					}
					else
						System.out.println("Enter amount in multiples of 100");
				}
				if(op.equals("check-balance"))
				{
					balance=obj.checkBalance();	//RMI call
					System.out.println("Your Balance :"+balance);
				}
				System.out.print(">>>");
				op=s.next();
			}			
		}
		catch(Exception e)
		{
			System.out.println("Client Error");
			e.printStackTrace();
		}
	}
}

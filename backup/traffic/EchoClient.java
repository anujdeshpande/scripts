import java.net.*;
import java.util.Scanner;
import java.io.*;

public class EchoClient {

	public static void main(String args[]){
		
		//int portno=Integer.parseInt(args[1]);
		//String  name=args[0];
		Scanner sr=new Scanner(System.in);
		String msg;
		int signal;
		
		try{
			Socket client =new Socket("127.0.0.1",12345);
			System.out.println("Connected to IP :" + client.getInetAddress().getHostName());
			
			DataInputStream in=new DataInputStream(client.getInputStream());
			DataOutputStream out =new DataOutputStream(client.getOutputStream());
			
			while(true)
			{
				msg=(in.readUTF());
				
				System.out.println(msg);
				
				/*if(signal==1)
				{
					System.out.println("Red");
				}else if(signal==2)
				{
					System.out.println("Green");
				}else if(signal==3)
				{
					System.out.println("Yellow");
				}*/
			}
			
		}catch (Exception e) {
			// TODO: handle exception
		}
	}
}

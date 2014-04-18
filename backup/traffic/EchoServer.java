import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.*;
import java.util.Scanner;
import java.io.*;

public class EchoServer {
	
	int signal=1;
	
	ServerSocket m_serversocket;
	static Socket client[]=new Socket[100];
	static int count=0;
	
	public EchoServer(){
		
		try
		{
			m_serversocket=new ServerSocket(12345);
			server_thread ser_thr=new server_thread();
			ser_thr.start();
			
			System.out.println("Waiting for Client....");
			int id=0;
			
			while(true)
			{
				client[count]=m_serversocket.accept();
				ClientService m_client=new ClientService(client[count],++id);
				count++;
				
				m_client.start();
				
			}
			
		}catch (Exception e) {
			// TODO: handle exception
		}
		
	}
	
	public class server_thread extends Thread
	{
		int i;
		int green_flag=0;
		
		public void update()
		{
			for(i=0;i<EchoServer.count;i++)
			{
				try
				{
					DataOutputStream out=new DataOutputStream(EchoServer.client[i].getOutputStream());
					
					if(green_flag==i)
						out.writeUTF("GREEN");
					else
						out.writeUTF("RED");
					   
					//green_flag=(green_flag+1)%EchoServer.count;
				} 
				
				catch (IOException e) {	}
			}
			
			
		}
		public void run()
		{
			while(true)
			{
				update();
				try 
				{
					Thread.sleep(3000);
				} 
				
				catch (InterruptedException e) { }
				if(EchoServer.count>0)
				green_flag=(green_flag+1)%EchoServer.count;
			}
		}
	}
	
	public class ClientService extends Thread{
		
		Socket m_client;
		int m_id;
		Scanner sr=new Scanner(System.in);
		String msg;
		public ClientService(Socket client,int id)
		{
			m_client=client;
			m_id=id;
		}
		 
		public void run()
		{
			
			System.out.println("Thread for Client "+ m_id + "created");
			
			while(true)
			{
			try
			{
				DataInputStream in =new DataInputStream(m_client.getInputStream());
				DataOutputStream out=new DataOutputStream(m_client.getOutputStream());
			
				 /*while(true)
				 {
					 if(signal==1)
					 {
						 //System.out.println("Red");
						 out.writeUTF("1");
						 signal=2;	
						 	
					 }else if(signal==2)
					 {
						 System.out.println("Green");
						 out.writeUTF("2");
						 signal=3;	
						 
					 }else if(signal==3)
					 {
						 System.out.println("Yellow");
						 out.writeUTF("3");
						 signal=1;	
						 
					 }
					 Thread.sleep(3000);
				 }*/
				
			}catch (Exception e) {
				// TODO: handle exception
			}
			}	
		}
	}
	public static void main(String args[]){
		//int portno=Integer.parseInt(args[0]);
		
		new EchoServer();
		
	}
}

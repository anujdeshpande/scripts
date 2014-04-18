package com.anuj.cl2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Main {
	public static int port = 8888;
	public static int max_conn = 0;
	ArrayList<Socket> socklist = new ArrayList<Socket>(20);  
public static void main(String args[]){
	
		try {
			ServerSocket listen = new ServerSocket(port);
			Socket client = listen.accept();
			BufferedReader is = new BufferedReader(new InputStreamReader(client.getInputStream()));
			PrintStream os = new PrintStream(client.getOutputStream());
			String line = is.readLine();
			os.println( "Echo: " + line );
			is.close();   
			os.close();
			client.close();
			listen.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	
}
}

/**
 * Server.java
 *
 * This is a time of day server that listens on port 5155.
 *
 * @author Greg Gagne, Peter Galvin, Avi Silberschatz
 * @version 1.0 - July 15, 1999
 * Copyright 2000 by Greg Gagne, Peter Galvin, Avi Silberschatz
 * Applied Operating Systems Concepts - John Wiley and Sons, Inc.
 */

import java.net.*;

public class Server
{
	public Server() {
		// create the socket the server will listen to
		try {
			s = new ServerSocket(5155);
		}
		catch (java.io.IOException e) {
			System.out.println(e);
			System.exit(1);
		}

		// OK, now listen for connections

		System.out.println("Server is listening ....");

		try {
			while (true) {
				client = s.accept();
				
				// create a separate thread 
				// to service the request
				c = new Connection(client);
				c.start();
			}
		}
		catch (java.io.IOException e) {
			System.out.println(e);
		}
	}

	public static void main(String args[]) {
		Server timeOfDayServer = new Server();
	}
	
	private ServerSocket	s;
	private Socket		client;
	private Connection	c;
}

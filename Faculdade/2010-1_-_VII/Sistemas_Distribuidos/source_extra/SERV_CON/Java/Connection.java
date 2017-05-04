/**
 * Connection.java
 *
 * This is the separate thread that services each request.
 *
 * @author Greg Gagne, Peter Galvin, Avi Silberschatz
 * @version 1.0 - July 15, 1999
 * Copyright 2000 by Greg Gagne, Peter Galvin, Avi Silberschatz
 * Applied Operating Systems Concepts - John Wiley and Sons, Inc.
 */

import java.net.*;
import java.io.*;

public class Connection extends Thread
{
	public Connection(Socket s) {
		outputLine = s;
	}

	public void run() {
		// getOutputStream returns an OutputStream object
		// allowing ordinary file IO over the socket.

		try {
			// create a new PrintWriter with automatic flushing
			PrintWriter pout = new PrintWriter(outputLine.getOutputStream(), true);

			// now send a message to the client
			pout.println("The Date and Time is " + new java.util.Date().toString());

			// now close the socket
			outputLine.close();
		}
		catch (java.io.IOException e) {
			System.out.println(e);
		}
	}

	private Socket	outputLine;
}

/**
 * Client.java
 *
 * This client accesses the time of day from a server.
 *
 * @author Greg Gagne, Peter Galvin, Avi Silberschatz
 * @version 1.0 - July 15, 1999
 * Copyright 2000 by Greg Gagne, Peter Galvin, Avi Silberschatz
 * Applied Operating Systems Concepts - John Wiley and Sons, Inc.
 */

import java.net.*;
import java.io.*;

public class Client
{
	public Client() {
		try {
			Socket s = new Socket("127.0.0.1",5155);

			InputStream in = s.getInputStream();
			BufferedReader bin = new BufferedReader(new InputStreamReader(in));

			System.out.println(bin.readLine());

			s.close();
		}
		catch (java.io.IOException e) {
			System.out.println(e);
			System.exit(1);
		}
	}

	public static void main(String args[]) {
		Client client = new Client();
	}
}

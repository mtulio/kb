import java.net.*;
import java.io.*;

class NetClient
{
  
  static final int PORT = 3040;
  
  public static void main( String args[] )
	throws Exception
  {
	String req = (args.length >= 1) ? args[0] : "3";
	String dst = (args.length >= 2) ? args[1] : "127.0.0.1";

	Socket sock = new Socket( dst , PORT );

	PrintWriter w =
	  new PrintWriter (sock.getOutputStream(), true);  // autoFlush

	BufferedReader r =
	  new BufferedReader (new InputStreamReader (sock.getInputStream()) );

	w.println (req);

	while (true)
	{
	  String s = r.readLine();

	  if (s != null)
		System.out.println (s);
	  else
		break;
	}

	r.close();
	w.close();

	sock.close();
  }  
}
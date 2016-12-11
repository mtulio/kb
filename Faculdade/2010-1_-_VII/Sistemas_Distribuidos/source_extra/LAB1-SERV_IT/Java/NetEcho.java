import java.net.*;
import java.io.*;

//aguarda uma conexão de cliente, lê um número enviado pelo cliente e, então, gera uma
//resposta com base no número recebido
class NetEcho
{
  static final int PORT = 3040;
  
  public static void main( String args[] )
	throws Exception
  {
	ServerSocket serv = new ServerSocket(PORT);

	System.out.println( "NetEcho pronto..." );

	while (true)
	{
	  Socket sock = serv.accept();

	  BufferedReader r =
		new BufferedReader (new InputStreamReader (sock.getInputStream()) );

	  PrintWriter w =
		new PrintWriter (sock.getOutputStream(), false);  // sem autoFlush

	  int n = Integer.parseInt( r.readLine() );

	  System.out.println( "Requisicao do cliente: " + n);

	  if (n <= 0) break;

	  w.println ("Valor recebido do cliente: " + n + " \r");

	  for (int k=1; k <= n; k++)
		w.println ("Linha número: " + k + "\r");

	  w.println ("Servidor finalizado\r");

	  w.flush();

	  r.close();
	  w.close();

	  sock.close();
	}

	serv.close();
  }  
}
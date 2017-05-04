	package trabalho1;	
	import java.io.File;
	import java.io.BufferedReader;
	
	import java.io.FileNotFoundException;
	
	import java.io.FileReader;

import java.io.IOException;
	import java.io.InputStreamReader;

	import java.io.PrintWriter;
	import java.net.ServerSocket;
	import java.net.Socket;
import java.net.SocketException;

	//especificaço do protocolo
	public class serv1 
	{
	
	      static final int PORT = 3058;
	      	public static void main( String args[] ) throws Exception  {
	        ServerSocket serv = new ServerSocket(PORT); // cria um socket servidor ouvindo a porta especificadaa
	        System.out.println( "NetEcho pronto, Ouvindo a porta 3058..." );
	       
	        while (true)
	        {      
	           try{
	        	 String arquivoServ;
	             Socket sock = serv.accept();	//Accept bloqueia até que uma conexão é feita.
	             BufferedReader r = new BufferedReader (new InputStreamReader (sock.getInputStream()) ); //estancia um objeto r, que guarda um buffer de entrada ( para ler)
	             PrintWriter w = new PrintWriter (sock.getOutputStream(), false);  //estancia um objeto w, que guarda um buffer de saida ( para escrever )
	        //   System.out.println(sock.getChannel());	
	             // sem autoFlush
	              	String bufferCliente = r.readLine();     //(lendo buffer recebido e guardando em bufferCliente)
	             	String palavraReservada = obterPalavraReservada(bufferCliente);
	              	String nomeArquivo = ObterNomeArquivo(bufferCliente);
	              	System.out.println("Ultimo cliente que esteve conectado: "+sock.getInetAddress());
	            
	              	if(nomeArquivo == ""){
	              		w.println("tecle GET [arquivo que deseja fazer o download]");
	                                		
	              	}
	                      	
	              	else if(palavraReservada.equalsIgnoreCase("get")){
	            	  File diretorio = new File("D:/Luan/Facul/7 periodo/Sistemas distribuidos/aula5/Java");  
	              		try{	              			
	                        w.println(varrerArquivo(diretorio, nomeArquivo)); // envia o buffer pro cliente, caso tenha achado  o arquivo
	              		}catch(FileNotFoundException e){ // caso nao encontre o arquivo
	              			w.println("arquivo nao encontrado");
	              		}        
	              }
	              	else{
	              		w.println("arquivo nao encontrado");
	              	}
	            
	             	
	              		
	              		w.flush();
	              		r.close();
	              		w.close();
	              		sock.close();
//	              		      	}catch(ArrayIndexOutOfBoundsException e){
//		        			System.out.println("nao aperta enter o babaca");
//		        } 
	        }catch(SocketException e){
	        	System.out.println("o cliente foi desconectado");
	        }
	     }
	  }
	      	
	public static String varrerArquivo(File diretorio,String arquivoEncontrar ) throws IOException{
		String resposta = "";
		String controle;
		BufferedReader ler=new BufferedReader(new FileReader(diretorio+"/"+arquivoEncontrar));
		while ((controle=ler.readLine())!= null){    // enquanto nao chega no fim pega oque ta escrito
			resposta += controle + " ";
			
		}
		ler.close();
		return resposta;

	}   
	public static String obterPalavraReservada(String bufferCliente){
		String palavraReservada = "";
		char bufferClienteChar[]= bufferCliente.toCharArray();
	      
      	int j = 0;
      	for(int i = 0 ; i < 3 ; i++){
      		palavraReservada += bufferClienteChar[i];
      		j++;
      	}
      	return palavraReservada;
	}
	public static String ObterNomeArquivo(String bufferCliente){
		String arquivo = "";
		char bufferClienteChar[]= bufferCliente.toCharArray();
      	  int j = 4;
		for( ;  j <bufferClienteChar.length ; j++){
      		arquivo += bufferClienteChar[j];
      	}
		return arquivo;
	}
}
package trabalho1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.SocketException;
import java.util.Scanner;



public class cliente {
	static final int PORT = 3058;
	public static void main( String args[] ) throws Exception {
	String dst = (args.length >= 2) ? args[1] : "127.0.0.1";
		Socket sock = new Socket( dst , PORT );//Cria um socket e conecta para o número 
												   //da porta especificado no endereço IP especificado.
		
	//imprime formatado representações de objetos para um texto-fluxo de saída
		PrintWriter w =  new PrintWriter (sock.getOutputStream(), true);  
		//imprime formatado representações de objetos para um texto-fluxo de entrada
		BufferedReader r =  new BufferedReader (new InputStreamReader (sock.getInputStream()) );
			Scanner scan = new Scanner(System.in);
			
			String arquivo;
			
				
			System.out.println("Informe o nome do arquivo que deseja: ");
		//	arquivo = JOptionPane.showInputDialog(null,"Informe o nome do arquivo que deseja fazer o Download: " , "Entrada de dados", JOptionPane.QUESTION_MESSAGE);
			arquivo = scan.nextLine();
			
			
			
			w.println (arquivo); // envia o buffer
			String mensagemControle = "";
			String arquivoEncontrar = "";
			char control[] = arquivo.toCharArray();
			int j = 0;
			for(int i = 0 ; i < 3 ; i++){
          		mensagemControle += control[i];
          		j++;
          	}
          	for(j ++ ;  j <control.length ; j++){
          		arquivoEncontrar += control[j];
          	}
	
				while (true){
					try{
					String ReceberDoServ;
						File diretorio = new File("C:/Users/luan/Desktop"); 
						ReceberDoServ = r.readLine();
						System.out.println(ReceberDoServ);
							if(ReceberDoServ.equalsIgnoreCase("arquivo nao encontrado") || ReceberDoServ.equalsIgnoreCase("tecle GET [arquivo que deseja fazer o download]")){
								System.out.println("O arquivo "+arquivoEncontrar+" nao foi encontrado");				
								//JOptionPane.showMessageDialog(null,"O arquivo nao foi encontrado", "Resultado da pesquisa", JOptionPane.ERROR_MESSAGE);
								r.close();
								w.close();
								sock.close();
								System.exit(0);
							}
							else{
								
								// abrir um arquivo para escrita
								PrintStream escrever = new PrintStream(new FileOutputStream(diretorio+"/"+arquivoEncontrar, true));      
								// escreve no arquivo
								escrever.println(ReceberDoServ);  
								System.out.println("O arquivo foi gravado em: C:/Users/luan/Desktop/"+arquivoEncontrar);
								//JOptionPane.showMessageDialog(null,"O arquivo foi gravado em: C:/Users/luan/Desktop/"+arquivo, "Resultado da pesquisa", JOptionPane.INFORMATION_MESSAGE);
								
								escrever.close();
								
							}
				//			escrever.close();
							break;
				}catch(SocketException e){
					System.out.println("o servidor caiu, tente conexão novamente mais tarde");
					System.exit(0);
				}
		}
		r.close();
		w.close();
		sock.close();
	}  
	}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main( argc, argv)
int argc;
char **argv;
{
	int sockint, s; 
	unsigned short port ; /* numero porta servidor */
	struct sockaddr_in server; /* end servidor */
	char buf[32]; 
	
	if( argc != 4 ) { 
		fprintf( stderr, "CLI--Uso correto: %s hostname porta nome_arquivo\n", argv[0] );
		exit(1);
	}

	//copia para a variavel port o 2 argumento
	port = (unsigned short) atoi(argv[2]); /* porta */

	//COpia a mensagem para a variavel buf
//	strcpy( buf, "String enviada - MARCO TULIO"); /* messagem */
	strcpy( buf, argv[3]); /* messagem */

	//imprimi uma mensagem na tela
	fprintf(stderr, "CLI--Criando socket TCP\n");
	
	s = socket(AF_INET, SOCK_STREAM, 0);
	if( s == -1 ) { // -1 eh msg de erros
		fprintf(stderr, "CLI--Erro Socket ()\n"); //imprimi uma mensagem de erro
		exit(2);
	}
	else
		fprintf(stderr, "CLI--Socket criado com successo\n");  //imrpimi uma mensagem de sucesso

	server.sin_family = AF_INET; 
	server.sin_port = htons(port); //informando a porta do servidor
	server.sin_addr.s_addr = inet_addr( argv[1] ); //definindo o servido no qual vai se conectar

	
	if( connect(s, &server, sizeof(server)) < 0) {
		fprintf(stderr, "CLI--Erro connect ()\n");
		exit(3);
	}


	//argumento 3
//	printf("Parametro 03 inf pela linha de comando: %s",argv[3]);

	//O ARQUIVO DEVE SER ENVIADO AQUI
//	char in_name[25], out_name[25];
	char in_name[25];
//	FILE *in_file, *out_file, *fopen ();
	FILE *out_file, *fopen ();	
	int c;

	printf("CLI--Nome do arquivo para copiar:\n");
	scanf("%24s", in_name);
//	printf("Output filename:\n");
//	scanf("%24s", out_name);

//	in_file = fopen ( in_name, "r"); // r = read
//	printf("\n\nNome do arquivo: %s",argv[3]);
//	out_name = (char) atoi(argv[3]);
//	printf("\n\nNome do arquivo: %s",out_name);

	//enviando o nome do arquivo
	printf("CLI--Enviando nome do arquivo: %s\n", in_name);
	if( send(s, in_name, sizeof(in_name), 0) < 0 ) {
		fprintf(stderr, "CLI--Erro send () - envio nome do arquivo\n");
		exit(4);
	}

	//confirmacao se foi encontrado ou n
	

	//criando um novo arquivo para gravação
	out_file = fopen (buf, "w"); //w = write
	if( out_file == NULL )
		printf("CLI--Can't open %s for writing.\n",buf);
	else {
		printf("\nCLI--entrou no else/if\n");			
		//recv(s, buf, sizeof(buf), 0);
		printf("\nCLI--valor de buf: %s\n",buf);			
		//while( buf==(-1) ) {
		int tam=5, cont=0;
		do{
			printf("\nCLI--entrou no while\n");			
			//recv(s, buf, sizeof(buf), 0);			
//			if( send(s, buf, sizeof(buf), 0) < 0 ) {
//				fprintf(stderr, "CLI--Erro send ()\n");
//				exit(4);
//			}
			if( (recv(s, buf, sizeof(buf), 0) < 0) ) {
				fprintf(stderr, "CLI--Erro receive ()\n");
				exit(5);
			}	
			//c = getc( in_file);
			putc (buf, out_file);
			printf("CLI--valor recebido: %s",buf);
			cont++;

		}while(	cont<=tam);	
		//}while( buf==("-1") );
		printf("\nCLI--O Arquivo foi copiado.\n");
		fclose (out_file);
	}
	
//	if( in_file == NULL )
//		printf("Cannot open %s for reading.\n", in_name);
//	else {
//		out_file = fopen (out_name, "w"); //w = write
//		if( out_file == NULL )
//			printf("Can't open %s for writing.\n",out_name);
//		else {
//			while( !feof(in_file) ) {
//				c = getc( in_file);
//				putc (c, out_file);
//			}
//			printf("File has been copied.\n");
//			fclose (out_file);
//		}
//		fclose (in_file);
//	}

	//fim do metodo copiar


	//enviando primeira mensagem par ao servidor
	printf("CLI--Enviando menssagem: %s\n", buf);
	if( send(s, buf, sizeof(buf), 0) < 0 ) {
		fprintf(stderr, "CLI--Erro send ()\n");
		exit(4);
	}

	//recebendo a primeira mensagem do servidor
	/* recebe msg d echo do servidor */
	if( recv(s, buf, sizeof(buf), 0) < 0 ) {
		fprintf(stderr, "CLI--Erro receive ()\n");
		exit(5);
	}

	printf("CLI--Menssagem 01 do servidor: %s\n", buf);

	//enviando segunda mensagem par ao servidor
	printf("CLI--Enviando menssagem: %s\n", buf);
	if( send(s, buf, sizeof(buf), 0) < 0 ) {
		fprintf(stderr, "CLI--Erro send ()\n");
		exit(4);
	}

	//recebendo a segunda mensagem do servidor
	/* recebe msg d echo do servidor */
	if( recv(s, buf, sizeof(buf), 0) < 0 ) {
		fprintf(stderr, "CLI--Erro receive ()\n");
		exit(5);
	}

	printf("CLI--Menssagem 02 do servidor: %s\n", buf);

	close(s);
	printf("close () cliente ok\n"); 
	exit(0);
}

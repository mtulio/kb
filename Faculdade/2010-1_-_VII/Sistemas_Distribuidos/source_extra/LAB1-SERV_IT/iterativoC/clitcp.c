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
	
	if( argc != 3 ) { 
		fprintf( stderr, "Uso: %s hostname porta\n", argv[0] );
		exit(1);
	}

	//copia para a variavel port o 2 argumento
	port = (unsigned short) atoi(argv[2]); /* porta */

	//COpia a mensagem para a variavel buf
	strcpy( buf, "String enviada - MARCO TULIO"); /* messagem */

	//imprimi uma mensagem na tela
	fprintf(stderr, "Criando socket TCP\n");
	
	s = socket(AF_INET, SOCK_STREAM, 0);
	if( s == -1 ) { // -1 eh msg de erros
		fprintf(stderr, "Erro Socket ()\n"); //imprimi uma mensagem de erro
		exit(2);
	}
	else
		fprintf(stderr, "Socket criado com successo\n");  //imrpimi uma mensagem de sucesso

	server.sin_family = AF_INET; 
	server.sin_port = htons(port); //informando a porta do servidor
	server.sin_addr.s_addr = inet_addr( argv[1] ); //definindo o servido no qual vai se conectar

	
	if( connect(s, &server, sizeof(server)) < 0) {
		fprintf(stderr, "Erro connect ()\n");
		exit(3);
	}

	//O ARQUIVO DEVE SER ENVIADO AQUI

	printf("Enviadno menssagem: %s\n", buf);
	if( send(s, buf, sizeof(buf), 0) < 0 ) {
		fprintf(stderr, "Erro send ()\n");
		exit(4);
	}

	/* recebe msg d echo do servidor */
	if( recv(s, buf, sizeof(buf), 0) < 0 ) {
		fprintf(stderr, "Erro receive ()\n");
		exit(5);
	}
	printf("Menssagem do servidor: %s\n", buf);

	close(s);
	printf("close () cliente ok\n"); 
	exit(0);
}

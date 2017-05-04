//exemplo de programa que le o audio da placa de som /dev/audio
//e envia para o socket

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>


 
main (int argc,int * argv[])
{
	int sock,i,j;
	struct sockaddr_in server;
	int msgsock;
	unsigned char buf[32];
	int rval;
	int length;
	int  audio_escrita;

	audio_escrita = open("/dev/audio", O_WRONLY);

	/* Cria um socket */
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror (" Abertura de socket errado. ");
		exit (1);
	}

	/* Nomeia socket usando wildcards */
	server.sin_family = PF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));
	if (bind (sock, (struct sockaddr *) &server, sizeof server) < 0)
	{
		perror ("ligacao (bind) no socket errado");
		exit (1);
	}
	
	/* encontra o numero da porta associado e o imprime */
	length = sizeof server;
	if (getsockname (sock, (struct sockaddr *) &server, &length) < 0)
	{
		perror ("obtencao do nome do socket errado");
		exit (1);
	}
	printf ("Socket port %d\n\r", ntohs (server.sin_port));

	/* Inicia aceitacao das conexoes */
	listen (sock, 10);
	msgsock = accept (sock, (struct sockaddr *) 0, (int *) 0);
	if (msgsock == -1)
		perror ("Accept com erro");
	else
		do
		{   i=0;
			bzero (buf, sizeof buf);
			if ((rval = read (msgsock, buf, 32)) < 0)
				perror (" Lendo mensagem...");
			if (rval == 0)
				printf ("terminando conexao...\n\r");
			else{
   
		         write(audio_escrita, buf, 32);

		       }
		} while (rval != 0);
	close (msgsock);

	close(audio_escrita);
	close(sock);

	exit (0);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main()
{
	int sockint, s; /* descritor do socket */
	int namelen; /* comprimento do nome do cliente */
	int ns; /* socket cliente */
	struct sockaddr_in client; /* informacao do end do cliente*/
	struct sockaddr_in server; /* informacao do end do servidor*/
	char buf[32]; /* buffer de dados */

	s = socket(AF_INET, SOCK_STREAM, 0);
	if( s == -1 ) {
		fprintf(stderr, "SRV--ERRO em socket()\n");
		exit(2);
	}
	else
		fprintf(stderr,"SRV--Socket criado com sucesso\n");

	server.sin_family = AF_INET; 
	server.sin_port = 0; /* usa a primeira porta disponivel */
	server.sin_addr.s_addr = INADDR_ANY;

	if( bind(s, &server, sizeof( server )) < 0 ) { 
		fprintf(stderr,"SRV--Erro em bind()\n");
		exit(3);
	}

	/* descobre a porta associada*/
	namelen = sizeof( server );
	if( getsockname( s, (struct sockaddr *) &server, &namelen) < 0 ) {
		fprintf(stderr, "SRV--Erro em getsockname()\n");
		exit(4);
	}
	fprintf(stderr,"SRV--Numero de porta : %d\n", ntohs( server.sin_port));

	if( listen(s, 1) != 0 ) { 
		fprintf(stderr, "SRV--Erro em listen()\n");
		exit(5);
	}

	namelen = sizeof(client); 
	if( (ns = accept(s, &client, &namelen)) == -1) {
		fprintf(stderr, "SRV--Erro em accept()\n");
		exit(6);
	}
	
// ***********************

	char in_name[25], out_name[25];
	FILE *in_file, *out_file, *fopen ();
//	int c;
	char c;

//	printf("File to be copied:\n");
//	scanf("%24s", in_name);
//	printf("Output filename:\n");
//	scanf("%24s", out_name);


	//recebendo nome do arquivo
	if( recv(ns, in_name, sizeof(in_name), 0) == -1 ) { 
		fprintf(stderr, "SRV--Erro em recv() - 01\n");
		exit(7);
	}

	in_file = fopen ( in_name, "r"); // r = read

	printf("\nSRV--Arquivo para copiar: %s\n",in_name);

	if( in_file == NULL )
		printf("SRV--Cannot open %s for reading.\n", in_name);
	else {
		//out_name = in_name;		
//		out_file = fopen (out_name, "w"); //w = write
		in_file = fopen (in_name, "r"); //w = write
		
		if( in_file == NULL )
			printf("SRV--Can't open %s for writing.\n",in_name);
		else {
			if(in_file!=NULL) printf("\narquivo %s aberto com sucesso\n",in_name);
			while(!feof(in_file)) {
				c = getc( in_file);
				printf("\nSRV--var c dentro do while: %c\n",c);
				if( !send( ns, c, sizeof(c), 0) < 0) {
					fprintf(stderr, "SRV--Erro em send() - dentro while\n");
					exit(8);
				}
				//putc (c, out_file);
				printf("\nSRV--var c dentro do while depois de send: %c\n",c);
				if( recv(ns, buf, sizeof(buf), 0) == -1 ) { 
					fprintf(stderr, "SRV--Erro em recv()\n");
					exit(7);
				}
			}
			printf("SRV--O arquivo foi copiado.\n");
			fclose (in_file);
		}
		printf("\nSRV--fechando o arquivo!!!\n");
		//fclose (in_file);
	}



// ************************

	//recebendo primeira mensagem do cliente
//	if( recv(ns, buf, sizeof(buf), 0) == -1 ) { 
//		fprintf(stderr, "SRV--Erro em recv()\n");
//		exit(7);
//	}
	
	//enviando primeira mensagem de responsta par ao cleinte
//	if( send( ns, buf, sizeof(buf), 0) < 0) {
//		fprintf(stderr, " SRV--Erro em send()\n");
//		exit(8);
//	}

	//recebendo segunda mensagem do cliente
//	if( recv(ns, buf, sizeof(buf), 0) == -1 ) { 
//		fprintf(stderr, "SRV--Erro em recv()\n");
//		exit(7);
//	}
	
	//enviando segunda mensagem de responsta par ao cleinte
//	if( send( ns, buf, sizeof(buf), 0) < 0) {
//		fprintf(stderr, "SRV--Erro em send()\n");
//		exit(8);
//	}

	close(ns); /* close socket cliente */
	close(s); /* close  socket servidor*/

	printf("SRV--Servidor finalizado\n");
	exit(0);
}


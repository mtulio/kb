#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <winsock2.h>

#define TAM 4096

main()
{
   int sockint, s; /* descritor do socket */
   int namelen; /* comprimento do nome do cliente */
   int ns; /* socket cliente */
   struct sockaddr_in client; /* informacao do end do cliente*/
   struct sockaddr_in server; /* informacao do end do servidor*/
   char buf[TAM]; /* buffer de dados */
   FILE *arquivoSaida;
   int n;
 WORD wVersion;
 WSADATA wStart;


 wVersion = MAKEWORD(2, 0);
 WSAStartup(wVersion,&wStart);  
   arquivoSaida = fopen("arquivoSaida.txt", "w");
   
   s = socket(AF_INET, SOCK_STREAM, 0);
   if( s == -1 ) {
      fprintf(stderr, "ERRO em socket()\n");
      exit(2);
   }
   else
      fprintf(stderr,"Socket criado com sucesso\n");
   
   server.sin_family = AF_INET; 
   server.sin_port = 0; /* usa a primeira porta disponivel */
   server.sin_addr.s_addr = INADDR_ANY;
   
   if( bind(s, &server, sizeof( server )) < 0 ) { 
      fprintf(stderr,"Erro em bind()\n");
      exit(3);
   }
   
   /* descobre a porta associada*/
   namelen = sizeof( server );
   if( getsockname( s, (struct sockaddr *) &server, &namelen) < 0 ) {
      fprintf(stderr, "Erro em getsockname()\n");
      exit(4);
   }
   fprintf(stderr,"Numero de porta : %d\n", ntohs( server.sin_port));
   
   if( listen(s, 1) != 0 ) { 
      fprintf(stderr, "Erro em listen()\n");
      exit(5);
   }
   
   namelen = sizeof(client); 
   if( (ns = accept(s, &client, &namelen)) == -1) {
      fprintf(stderr, "Erro em accept()\n");
      exit(6);
   }
   do
   {
         n=recv(ns, buf, sizeof(buf), 0);
      if(n<=0)
         break;
      fwrite(buf,sizeof(char),n,arquivoSaida);
      } while(1);
      
   
   if( send( ns, buf, sizeof(buf), 0) < 0) {
      fprintf(stderr, " Erro em send()\n");
      exit(8);
   }
   
   close(ns); /* close socket cliente */
   close(s); /* close  socket servidor*/
   
   printf("Servidor finalizado\n");
   exit(0);
}


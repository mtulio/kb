#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <winsock2.h>

#define TAM 4096

main(int argc, char **argv)
{
   int meuSocket;
   unsigned short porta;
   char conteudoArquivo[TAM];
   struct sockaddr_in receptor;
   char nomeArquivo[25];
   FILE *arquivoEntrada;
   int read;
   WORD wVersion;
 WSADATA wStart;


 wVersion = MAKEWORD(2, 0);
 WSAStartup(wVersion,&wStart);
   if(argc != 3)
   {
      printf("Use: %s hostname porta\n",argv[0]);
      exit(0);
   }
   else
   {
      porta = (unsigned short) atoi(argv[2]);
      
      printf("Entre com o nome do arquivo\n");
      scanf("%s",nomeArquivo);
      
      arquivoEntrada = fopen(nomeArquivo,"r");
      printf("abriu arquivo\n");
      if(nomeArquivo == NULL )
      {
         printf("Impossivel de abrir o arquivo\n");
      }
      
      meuSocket = socket(AF_INET, SOCK_STREAM, 0);
      if( meuSocket == -1 ) {
         printf("Erro Socket ()\n");
         exit(2);
      }
      else
         fprintf(stderr, "Socket criado com successo\n");
      
      receptor.sin_family = AF_INET;
      receptor.sin_port = htons(porta);
      receptor.sin_addr.s_addr = inet_addr( argv[1]);
      
      if( connect(meuSocket, &receptor, sizeof(receptor)) < 0) {
         fprintf(stderr, "Erro connect ()\n");
         exit(3);
      }
      while(!feof(arquivoEntrada))
      {
         read = fread(conteudoArquivo, sizeof(char), TAM, arquivoEntrada);
         if(send(meuSocket,conteudoArquivo, read, 0)<0)
         {
            printf("nao foi possivel enviar os dados!\n");
         }
         
      }
   }
}

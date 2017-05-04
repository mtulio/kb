#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h> //para uso do printf

//tratamento de erros
void error(char *msg)
{
    perror(msg); //pega os erros do programa e envia como parametro
    exit(0); //e sai do programa
} //fim eror

//Inicio do main
int main(int argc, char *argv[])
{
    system("clear");
    int sock, length, n;
    struct sockaddr_in server, from;
    struct hostent *hp;
    char msg[250];

    if (argc != 3) {
        printf("\n\t\"CLIENT error\" - Uso correto: servidor porta\n\n");
        exit(1);
    } //fim if

    sock= socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        error("\n\tCLIENT - error: socket\n\t");

    server.sin_family = AF_INET;
    hp = gethostbyname(argv[1]);
    if (hp==0) error("\n\tCLIENT - error: host desconhecido");
    bcopy((char *)hp->h_addr,(char *)&server.sin_addr,hp->h_length);
    server.sin_port = htons(atoi(argv[2]));
    length=sizeof(struct sockaddr_in);

//status qdo conectado
   n=sendto(sock,"CONECTADO",strlen(msg),0,&server,length);
   if (n < 0) error("\n\tCLIENT error: received from - erro ao receber");

   while(1){
      printf("\n\tDigite a menssagem,0 pra sair: ");
      scanf("%s",&msg);
//      bzero(msg,256);
//      fgets(msg,255,stdin);	

      n=sendto(sock,msg,strlen(msg),0,&server,length);
      if (n < 0) error("\n\tCLIENT error: Send to - erro ao enviar");

      printf("\n\tEsperando mensagem do Server...");

      n = recvfrom(sock,msg,256,0,&from, &length);
      if (n < 0) error("\n\tCLIENT error: received from - erro ao receber");

     //condicao para saida do programa	
     if(msg[0]=='0') return;
      write(1,"\n\tServer Diz: ",17);
      write(1,msg,n);

   }//fim do laco dowhile
} //fim main

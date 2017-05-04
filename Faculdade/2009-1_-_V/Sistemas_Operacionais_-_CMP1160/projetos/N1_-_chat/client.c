#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h> //para uso do printf
//#include <string>

//declarando ometodo error
//void error(char *);

//tratamento de erros
void error(char *msg)
{
    perror(msg); //pega os erros do programa e envia como parametro
    exit(0); //e sai do programa
} //fim eror

//Inicio do main
int main(int argc, char *argv[])
{
    int sock, length, n;
    struct sockaddr_in server, from;
    struct hostent *hp;
    //char buffer[256];
    char nick[50], msg[50];

//condicao para execucao do progr
    if (argc != 3) {
        printf("\n\t\"CLIENT error\" - Uso correto: servidor porta\n\n");
        exit(1);
    } //fim if

//cria um socket
    sock= socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        error("\n\tCLIENT - error: socket\n\t");

    server.sin_family = AF_INET;
    hp = gethostbyname(argv[1]);
    if (hp==0) error("\n\tCLIENT - error: host desconhecido");
    bcopy((char *)hp->h_addr,(char *)&server.sin_addr,hp->h_length);
    server.sin_port = htons(atoi(argv[2]));
    length=sizeof(struct sockaddr_in);

//   printf("Digite o seu nick: ");
//   scanf("%c",&nick);

   //estabeleceu conexao
   //colocar condicao de repeticao aki
//para nao pular a linha
//getchar();
   while(1){
      printf("\nCLIENT: Digite a menssagem - 0 pra sair: ");
      scanf("%s",&msg);
//o comando bzero zera a string, no caso oq for digitado
//    bzero(buffer,256);
//    fgets(buffer,255,stdin);
//    if(buffer=='0') exit(0);
	//msg=nick+" Diz: "+msg;

       //n=sendto(sock,buffer,strlen(buffer),0,&server,length); //envio d msg ao server 
      n=sendto(sock,msg,strlen(msg),0,&server,length);
      if (n < 0) error("\n\tCLIENT - error: Send to - erro ao enviar");

      printf("\nEsperando mensagem do Server...\n");

      //esperanddo recebermsg do servidor
      n = recvfrom(sock,msg,256,0,&from, &length);
      //n = recvfrom(sock,buffer,256,0,&from, &length);
      if (n < 0) error("\nCLIENT - error: received from - erro ao receber");

      //imprimindo a msg recebida pelo servidor 
      write(1,"Server Diz:  ",12);
      write(1,msg,n);
      //write(1,buffer,n);

   }//fim do laco dowhile
} //fim main

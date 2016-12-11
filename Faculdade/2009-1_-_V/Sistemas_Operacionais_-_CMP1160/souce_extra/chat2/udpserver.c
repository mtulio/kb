#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>

//msgs de erro
void error(char *msg)
{
    perror(msg);
    exit(0);
}//fim metodo q trata os erros

int main(int argc, char *argv[])
{
//declarando  as variaveis q ser�o usadas para o prog
    int sock, length, fromlen, n;
    struct sockaddr_in server;//endereco do servidor	/*1*/
    struct sockaddr_in from;//endereco do destino	/*2*/
    char buf[1024]; 					/*3*/

//verifica se o argumento digitado pelo user eh valido
//se nao for sai do programa
    if (argc < 2) { /*4*/
        fprintf(stderr, "\n\tSERVER - error: porta não informada\n");
    exit(0);
    }

//cria o socket
//criando um socket que retorna um valor maior do q zero
//caso retornar menor que zero existe um erro ao criar o socket
    sock=socket(PF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        error("\n\tSERVER - error: Opening socket\n\t");

//define as estruturas de end para socket
    length = sizeof(server); // tamanho do end
    bzero(&server,length);

//elimina espacos nulos da struct de end
    server.sin_family=AF_INET;// define a familia de protocolos
    server.sin_addr.s_addr=INADDR_ANY;


//associa ao end local
    server.sin_port=htons(atoi(argv[1]));
//porta forneciada pelo usuario

//associa end ao socket

    if (bind(sock,(struct sockaddr *)&server,length)<0)
        error("\nSERVER - error: binding\n");
    fromlen = sizeof(struct sockaddr_in);

//faz leitura
//faz a leitura e espera a resposta do servidor
//repete enquanto
printf("\nStatus: Serrvidor conectado!");
//printf("\n\t Servidor iniciado ");

    while (1) {
	//colocar a digitacao de mensagem aki
//chamada ao cliente

//printf("\nStatus: Agurdando mensagem do Usuario...");

//printf("\nValor de n antes: %i\n",n);
printf("\nStatus: Agurdando mensagem do Usuario...");
	n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);
//printf("\nValor de n antes: %i\n",n);
//tratamento de erros do recvfrom
        if (n < 0)
            error("\n\tSERVER:- error: received from\n\n");
//Imprimindo a mensagem recebida pelo user
      printf("\nCLIENT conversa: ");
	//write(1,"\n\tClienteDiz: ",21);
        write(1,buf,n);

  //envia resposa pra cliente
	printf("\nDigite a mensagem e tecle enter: ");
	bzero(buf,256);
    	fgets(buf,255,stdin);
    	printf("\nStatus: Agurdando mensagem do Usuario...");
        n = sendto(sock,buf,30,0,(struct sockaddr *)&from,fromlen);
        if (n < 0) error("\n\tSERVER - error: send to\n\n");
    } //fim while
}//fim principal

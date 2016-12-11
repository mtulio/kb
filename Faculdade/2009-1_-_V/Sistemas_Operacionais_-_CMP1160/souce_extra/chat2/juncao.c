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
} 

int main(int argc, char *argv[]) 
{ 
//declarando  as variaveis q serão usadas para o prog
    int sock, length, fromlen, n; 
    struct sockaddr_in server;//endereco do servidor 
    struct sockaddr_in from;//endereco do destino 
    char buf[1024]; 

//verifica se o argumento digitado pelo user eh valido
//se nao for sai do programa
    if (argc < 2) { 
        fprintf(stderr, "\n\tSERVER: ERRO: porta nÃo informada\n"); 
    exit(0); 
    } 

//cria o socket
    sock=socket(PF_INET, SOCK_DGRAM, 0); 
    if (sock < 0) 
        error("\n\tSERVER:-error: Opening socket\n\t"); 
  
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
        error("\nSERVER:-error: binding\n"); 
    fromlen = sizeof(struct sockaddr_in); 

//faz leitura
//faz a leitura e espera a resposta do servidor
//repete enquanto
    while (1) {
	printf("\n\t teste antes de rec from\n");
        n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen); 
	printf("\n\tteste depois do rec from\n");
        if (n < 0) 
            error("\n\tSERVER:- error: received from\n\n"); 
  
        write(1,"\n\tSERVER: Datagrama: ",21); 
        write(1,buf,n); 
  
  //envia resposa
//o arg 30 eh o tamanho da string a ser impressa
        n = sendto(sock,"\n\tSERVER: MSG recebida ! \n\n",30,0,(struct sockaddr *)&from,fromlen); 
        if (n < 0) error("\n\tSERVER: send to\n\n"); 
    } //fim while

}//fim principal

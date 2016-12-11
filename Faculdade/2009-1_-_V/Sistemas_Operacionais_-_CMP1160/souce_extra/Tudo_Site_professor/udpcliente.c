#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <netdb.h> 
#include <stdio.h> 

//declarando ometodo error
void error(char *); 

int main(int argc, char *argv[]) 
{ 
    int sock, length, n; 
    struct sockaddr_in server, from; 
    struct hostent *hp; 
    char buffer[256]; 

//condicao para execucao do progr
    if (argc != 3) { 
        printf("\n\tCLIENT: Uso correto: servidor porta\n\n"); 
        exit(1); 
    } //fim if

//cria um socket

    sock= socket(AF_INET, SOCK_DGRAM, 0); 
    if (sock < 0) 
        error("\n\tCLIENT:error: socket\n\t"); 
  
    server.sin_family = AF_INET; 
    hp = gethostbyname(argv[1]); 
    if (hp==0) error("\n\tCLIENT:-error: host desconhecido"); 
    bcopy((char *)hp->h_addr,(char *)&server.sin_addr,hp->h_length); 
    server.sin_port = htons(atoi(argv[2])); 
    length=sizeof(struct sockaddr_in); 

//estabeleceu conexao
//colocar condicao de repeticao aki
do{
    printf("\n\tCLIENT: Digite a menssagem - 0 pra sair: "); 
//o comando bzero zera a string, no caso oq for digitado
    bzero(buffer,256); 
    fgets(buffer,255,stdin); 

    n=sendto(sock,buffer,strlen(buffer),0,&server,length); 
    if (n < 0) error("\n\tCLIENT: erro: Send to - erro ao enviar"); 

    n = recvfrom(sock,buffer,256,0,&from, &length); 
    if (n < 0) error("\n\tCLIENT: error: received from - erro ao receber\n\t"); 

    write(1,"CLIENT: ACK:  ",12); 
    write(1,buffer,n); 
}while((n>=0) || (buffer=='0'));//fim do laco dowhile

} //fim main

void error(char *msg) 
{ 
    perror(msg); //pega os erros do programa e envia como parametro
    exit(0); //e sai do programa
} //fim eror


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

    int sock, length, fromlen, n; 
    struct sockaddr_in server;//endereco do servidor 
    struct sockaddr_in from;//endereco do destino 
    char buf[1024]; 

    if (argc < 2) { 
        fprintf(stderr, "ERRO: porta nÃo informada\n"); 
    exit(0); 
    } 


//cria o socket

    sock=socket(PF_INET, SOCK_DGRAM, 0); 
    if (sock < 0) 
        error("Opening socket"); 
  
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
        error("binding"); 
    fromlen = sizeof(struct sockaddr_in); 

//faz leitura
    while (1) { 
        n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen); 
        if (n < 0) 
            error("recvfrom"); 
  
        write(1,"Datagrama: ",21); 
        write(1,buf,n); 
  
  //envia resposa
        n = sendto(sock,"MSG recebida ! \n",17,0,(struct sockaddr *)&from,fromlen); 
        if (n < 0) error("sendto"); 
    } 

}

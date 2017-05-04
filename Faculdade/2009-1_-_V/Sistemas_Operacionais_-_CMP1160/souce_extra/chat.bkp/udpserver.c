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
/*
char *cliente()
{//inicio cliente

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
while(1){
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

//fazer a chamada do server aki
	 
}//fim do laco dowhile
}//fim cliente

*/

int main(int argc, char *argv[]) 
{ 
//declarando  as variaveis q serão usadas para o prog
    int sock, length, fromlen, n; 
    struct sockaddr_in server;//endereco do servidor	/*1*/
    struct sockaddr_in from;//endereco do destino	/*2*/
    char buf[1024]; 					/*3*/

//verifica se o argumento digitado pelo user eh valido
//se nao for sai do programa
    if (argc < 2) { /*4*/
        fprintf(stderr, "\n\tSERVER: ERRO: porta nÃo informada\n"); 
    exit(0); 
    } 

//cria o socket
//criando um socket que retorna um valor maior do q zero
//caso retornar menor que zero existe um erro ao criar o socket
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
printf("\nStatus: Servervidor conectado!");
//printf("\n\t Servidor iniciado ");
    while (1) {
	//colocar a digitacao de mensagem aki	
//chamada ao cliente

printf("\nStatus:Agurdando mensagem do Usuario...");

printf("\nValor de n antes: %i\n",n);        
	n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen); 
printf("\nValor de n antes: %i\n",n);
//tratamento de erros do recvfrom
        if (n < 0) 
            error("\n\tSERVER:- error: received from\n\n"); 
//Imprimindo a mensagem recebida pelo user  
        printf("\nCliente %i conversa: ",sock);
	//write(1,"\n\tClienteDiz: ",21); 
        write(1,buf,n); 
  
  //envia resposa pra cliente
	printf("\n\tDigite a mensagem e tecle enter: ");
	bzero(buf,256); 
    	fgets(buf,255,stdin); 

        n = sendto(sock,buf,30,0,(struct sockaddr *)&from,fromlen); 
        if (n < 0) error("\n\tSERVER: error: send to\n\n"); 
    } //fim while

}//fim principal

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h> //para uso do printf

//msgs de erro
void error(char *msg)
{
    perror(msg);
    exit(0);
}//fim metodo  de tratamento de erros

//inicio do main
int main(int argc, char *argv[])
{
   system("clear");
    int sock, length, fromlen, n;
    struct sockaddr_in server;//endereco do servidor	/*1*/
    struct sockaddr_in from;//endereco do destino	/*2*/
    char buf[1024]; 					/*3*/

    if (argc < 2) { /*4*/
        fprintf(stderr, "\n\tSERVER error: porta não informada\n\n");
        exit(0);
    }//fim do if de tratamento de erros

    sock=socket(PF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        error("\n\tSERVER error: Opening socket - Criando socket\n\n");

    length = sizeof(server); // tamanho do end
    bzero(&server,length);

    server.sin_family=AF_INET;// define a familia de protocolos
    server.sin_addr.s_addr=INADDR_ANY;

    server.sin_port=htons(atoi(argv[1]));

    if (bind(sock,(struct sockaddr *)&server,length)<0)
        error("\n\tSERVER error: binding\n\n");
    fromlen = sizeof(struct sockaddr_in);

    write(1,"\n\tStatus-Srv: Servidor Conectado!",35);

//STATUS 
   n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);
   if (n < 0)error("\n\tSERVER - error: received from\n");

   write(1,"\n\tStatus-Srv: cliente conectado!",38);

    while (1) {
	
	write(1,"\n\tStatus-Srv: Aguardando msg cli!",35);
	
//aguarda recebimento de msg do cliente
	bzero(buf,256);	
	n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);
        
        //tratamento de erros do recvfrom
        if (n < 0)
            error("\n\tSERVER - error: received from\n");
        
	printf("\n\tCliente Diz: %s",buf);
      	//write(1,"\nCliente Diz: ",22);
        //write(1,buf,n);
		
	
	printf("\n\tDigite msg e tecle enter,0 p.sair: ");
	bzero(buf,256);
    	fgets(buf,255,stdin);
	
	//condicao para fechar o cliente	
	if(buf[0]=='0')buf[0]='0';
	
        n = sendto(sock,buf,30,0,(struct sockaddr *)&from,fromlen);
	//condicao para saida do programa	
	if(buf[0]=='0')return;
        if (n < 0) error("\n\tSERVER - error: send to\n");
    } //fim while
}//fim principal

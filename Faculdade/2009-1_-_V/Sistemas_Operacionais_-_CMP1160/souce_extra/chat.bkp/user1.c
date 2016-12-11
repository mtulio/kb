#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <netdb.h> 
#include <stdio.h> 

#include <pthread.h>


void func1(int *id);
void func2(int *id);
void error(char *); 
int argc1=2;//qtde de var q tem q ter o servidor
int argc2=3;//qtd de argumentos q o cliente tem q ter
char *argv1[];//={"./user1","1051"};
char *argv2[];//={"./user1","127.0.0.1","1051"};
			
int main(int argc, char *argv[]){
int opcao;
char portSktServ[20], portConnectServ[20], ipServ[20];

do{
	printf("\n\nMessenger\n\n");
	printf("\n\n(1) Iniciar servidor\n(2) Sincronizar Cliente\n(3) Iniciar o Chat\n");
	printf("digite a opcao: ");
	int opcao;
	scanf("%i",&opcao);
	switch(opcao)
	{//inico switch
		case 1:
		{//inico case1
			printf("Informe o numero da porta para liberar: ");
			scanf("%s",portSktServ);
			if(portSktServ<="1024") printf("Porta reservada, informe > 1024, tente novamente");
			else {
				argv1[2] = portSktServ;

			}//fim else
		printf("Porta do servidor informada: %s",portSktServ);
		getchar();getchar();
		break;
		}//fimm case 1

		case 2:
		{//inico case 2
			
			printf("Informe o IP do Servidor: ");
			fflush(stdin);			
			scanf("%s",ipServ);
			printf("Informe a Porta do Servidor: ");
			fflush(stdin);
			scanf("%s",portConnectServ);
			argv2[1]=ipServ;
			argv2[2] = portConnectServ;
			printf("\n\nIP Serv: %s", argv2);
			

			break;

			printf("\n\tIP do Serv Informado: %s ... Porta do Serv informada: %s",ipServ,portConnectServ);
			getchar();geetchar();
		}//fim case 2
	
		case 3:
		{//inico case 3
			
			pthread_t thr1,thr2; /* declara as threads */
			int nThrID1,nThrID2;/*define Thread ID*/
			nThrID1 = 1;
			nThrID2 = 2;	


	/* cria threads: id, inic, funcao, param funcao */
			pthread_create(&thr1,NULL,(void* )func1,&nThrID1);
			pthread_create(&thr2,NULL,(void* )func2,&nThrID2);


			/* espera fim das threads: id, status de saida */
			pthread_join(thr1,NULL);//analogo a chamada wait()/
			pthread_join(thr2,NULL);

		break;
		}//fim case 3

		case 0: { return; }		

		default:{
			printf("\n\nOpcao invalida\n\n");
			getchar();getchar();
		break;
		}

	}//fim switch
}while(opcao!=0);

printf("\nargc1: %s\n",argv1);
printf("\nargc1: %i\n",argc1);

}//fim memtodo main
//funcao server
void func1(int *id)//funcao que preenche o vetor a, executada pela thread 1
{
//declarando  as variaveis q serão usadas para o prog
    int sock, length, fromlen, n; 
    struct sockaddr_in server;//endereco do servidor 
    struct sockaddr_in from;//endereco do destino 
    char buf[1024]; 

//verifica a qtd de argumentos digitados pelo user
    if (argc1 < 2) { 
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
    server.sin_port=htons(atoi(argv1[1])); 
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

}//ifm fun1
//*********************************
void func2(int *id)//funcao que preenche o vetor b, executada pela thread 2
{
    int sock, length, n; 
    struct sockaddr_in server, from; 
    struct hostent *hp; 
    char buffer[256]; 

//condicao para execucao do progr
    if (argc2 != 3) { 
        printf("\n\tCLIENT: Uso correto: servidor porta\n\n"); 
        exit(1); 
    } //fim if

//cria um socket

    sock= socket(AF_INET, SOCK_DGRAM, 0); 
    if (sock < 0) 
        error("\n\tCLIENT:error: socket\n\t"); 
  
    server.sin_family = AF_INET; 
    hp = gethostbyname(argv2[1]); 
    if (hp==0) error("\n\tCLIENT:-error: host desconhecido"); 
    bcopy((char *)hp->h_addr,(char *)&server.sin_addr,hp->h_length); 
    server.sin_port = htons(atoi(argv2[2])); 
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

}//fim func 2


void error(char *msg) 
{ 
    perror(msg); //pega os erros do programa e envia como parametro
    exit(0); //e sai do programa
} //fim eror



/* compilacao: gcc -o threads  threads.c -lpthread */ 



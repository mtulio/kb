//servidor concorrente single process event-driven
//usando chamada select ()  

#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

main()
{
   fd_set read_template;//conjunto de descritores de arquivos
   struct timeval wait;//arg do select, diz quanto esperar
		      //para que algum descritor fique pronto	
   struct   sockaddr_in server;
   char   buf[102];
   int   sock, length, s1,s2, nb, cc, ready,eof1,eof2;

//Cria socket 
   sock = socket (PF_INET,SOCK_STREAM,0);
   if ( sock < 0 ) {
      perror("Erro na execucao da chamada socket()");
      exit(0);
   }

//preenche o struct de enderecos PF_INET
//faz o Bind
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = 0;
   if ( bind (sock,&server,sizeof(server)) ) {
      perror("Erro na execucao da chamada bind()");
   }
// Usa a chamada getsockname para descobrir o n. de porta
//associado, haja visto que, server.sin_port = 0
   length = sizeof(server);
   if ( getsockname (sock,&server,&length) ) {
      perror("Erro na execucao da chamada getsockname()");
      exit(0);
   }
   printf("SERVIDOR EXECUTANDO: aguardando conexoes dos clientes\n");
   printf("Numero da porta usada pelo servidor: #%d\n", ntohs(server.sin_port));
   
//inicia a aceitacao de conexoes
//note que existem duas execucoes do accept
//ou seja, no maximo dois sockets de cliente
//poderam ser manipulados pelo processo gerado por srverselect.c

   listen (sock, 5);
   s1= accept(sock,0,0);
   eof1=0;//testa status da conexao
   printf("Cliente 1 conectado\n");
   s2 = accept(sock,0,0);
   eof2=0;
   printf("Cliente 2 conectado\n");
   wait.tv_sec = 1;//struct de tempo duracao da selecao em seg
   wait.tv_usec = 0;//microseg
   //se timeout = 0 situacao de polling
   do {
      FD_ZERO(&read_template);//MACRO que limpa o fdset
      if (!eof1) FD_SET(s1,&read_template);//liga s1 no fdset e testa STATUS da conexao 
      if (!eof2) FD_SET(s2,&read_template);//liga s2 no fdset e testa STATUS da conexao

//executa o select ems1 e s2
//select aguarda que um dos dois mude o STATUS
 nb = select(FD_SETSIZE, &read_template, (fd_set *) 0, (fd_set *) 0, &wait);
// select (tamanho de fdset, ponteiro para leitura de dados, escrita de dados
// ,excecao, timeout);//excecoes: apenas dados outband em sockets
//caso nao queira testar nada e so passar ponteiro nulo.
//sucesso nb = numero de descritores aptos no fdset 
//se retornar = 0 foi devido ao timeout
      if (nb <0) {
         perror("Erro na chamada select()");
         exit(1);
      }
      if (nb != 0) {      /* 0 time out */
         if(FD_ISSET(s1, &read_template)){//testa a existencia de s1 com menbro do fdset
		EchoServe(s1, &eof1);//responde para s1
         }
         if(FD_ISSET(s2, &read_template)){//faz polling s2
		EchoServe(s2, &eof2);//responde s2
         }

      }
   }   while ( !eof1 || !eof2 );
   printf("Exit : finalizando programa\n");//somente se nao tiver nenhuma conexao ativa
   close(s1);
   close(s2);
   exit(0);
}

//servico executado pelo servidor:
//recebe uma string do cliente, imprime na tela e
//depois retorna a mesma string para o cliente
//um servidor de echo

EchoServe(int psd,int *eof)
//int psd, *eof;

{
  char buf[512];
  int rc;
  
    if( (rc=recv(psd, buf, sizeof(buf), 0)) < 0)
      perror("Erro ao executar a chamada recv()");
    if (rc > 0){
      buf[rc]=NULL;
      printf("Mensagem recebida: %s\n", buf);
      if (send(psd, buf, rc, 0) <0 )
        perror("Erro ao executar a chamada send()");
    }
    else {
      printf("Desconectando..\n");
      close (psd);
      *eof=1;//testa se determinado socket falhou
    }
}

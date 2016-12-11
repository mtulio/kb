/*****************************************************************************/

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>

void PANIC(char* msg);
#define PANIC(msg)  { perror(msg); exit(-1); }

/*--------------------------------------------------------------------*/
/*- captura o sinal: SIGCHLD  (consultar man signal; man sigaction) --*/
/*--------------------------------------------------------------------*/
void sig_handler(int sig)
{
    if ( sig == SIGCHLD )
    {   int retval;
        wait(&retval);
    }
}

/*--------------------------------------------------------------------*/
/*--- processo filho (slave)                                       ---*/
/*--------------------------------------------------------------------*/
void Child(void* arg)
{   char line[100];
    int bytes_read;
    int client = *(int *)arg;

    do
    {
        bytes_read = recv(client, line, sizeof(line), 0);
		if ( bytes_read < 0 )
			perror("Read socket");
        send(client, line, bytes_read, 0);
    }
    while (strncmp(line, "bye\r", 4) != 0  ||  bytes_read < 0 );
    close(client);
    exit(0);
}

/*--------------------------------------------------------------------*/
/*--- processo pai (master)                                        ---*/
/*--------------------------------------------------------------------*/
int main(void)
{   int sd;
	struct sigaction act;
    struct sockaddr_in addr;

    bzero(&act, sizeof(act));
	act.sa_handler = sig_handler;
	act.sa_flags = SA_NOCLDSTOP;
    sigaction(SIGCHLD, &act, 0);
    if ( (sd = socket(PF_INET, SOCK_STREAM, 0)) < 0 )
        PANIC("Socket");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3030);
    addr.sin_addr.s_addr = INADDR_ANY;
    if ( bind(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
        PANIC("Bind");
    if ( listen(sd, 20) != 0 )
        PANIC("Listen");
    while (1)
    {   int client, addr_size = sizeof(addr);

        client = accept(sd, (struct sockaddr*)&addr, &addr_size);
		if ( client < 0 )
			perror("Accept");
		else
		{
	        printf("Conectado por: %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
    	    if ( fork() )
        	    close(client);
	        else
    	    {
        	    close(sd);
            	Child(&client);
	            exit(0);
    	    }
		}
    }
    return 0;
}

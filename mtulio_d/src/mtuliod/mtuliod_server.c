/* Server and connection Mgr 
 * Create a server - bind on port
 * Manage threads
 * Check msgs from client
 * Send to Pars message*/


/*
    C socket server example, handles multiple clients using threads
    Compile
    gcc server.c -lpthread -o server
*/

#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread

/* GLOBALS */
int countConn;
/*typedef struct {
	int socket_fd;
	struct sockaddr_in socket_addr;
	unsigned int clientId;
} mtd_srv_client_t;*/

void *mtd_srv_connection_handler(void *);

/*  Init server - bind & listen */
int mtd_srv_init(struct sockaddr_in *server, int *socket_desc)
{
    int ret = -99;

    //Create socket
    *socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (*socket_desc == -1)
    {
        printf("Could not create socket");
    }

    //Prepare the sockaddr_in structure
    server->sin_family = AF_INET;
    server->sin_addr.s_addr = INADDR_ANY;
    server->sin_port = htons( 8888 );

    printf(" Starting Server on address %x:%x ... ",
    		ntohl(server->sin_addr.s_addr), ntohs(server->sin_port) );
    fflush(stdout);

    //Bind
    ret = bind(*socket_desc,(struct sockaddr *)server , sizeof(*server) );
    if( ret<0 )
    {
        //print the error message
        perror(" [FAIL] Bind failed. Error");
        return ret;
    }

    //Listen
    return listen(*socket_desc , 3);
}

/*
 * This will handle connection for each client
 * */
#define MAX_BUFF_SIZE 2000

void *mtd_srv_connection_handler(void *socket_data)
{
	//Get the socket descriptor
    int socket = *(int*)socket_data;
    int read_size;
    char *message , client_message[MAX_BUFF_SIZE];

    //Send some messages to the client
	message = "[MTd] Hello! Welcome to MTd (MTulio Daemon)\n";
    write(socket, message , strlen(message));

    message = "[MTd] If you want to see all available commands. just type HELP and enjoy! ;D\n";
    write(socket , message , strlen(message));

    message = "[MTd]$ ";
    write(socket , message , strlen(message));

    //Receive a message from client
    int terminate_client = 0;
    do
    {
		if ((read_size = recv(socket , client_message , MAX_BUFF_SIZE , 0)) > 0) {

    		//client_message[read_size] = '\0';
    		//printf("%s\n", client_message);

    		// Escape string 'QUIT'
    		/*if (strncmp(client_message, "QUIT", 4) == 0) {
    			printf(" # [HandlerID: %x] Closing connection by command QUIT\n", socket);
    			fflush(stdout);
    			terminate_client=1;
    			continue; // goto next loop
    		}*/

    		if (mtd_srv_cmd_parseMessage(client_message/*, message_out*/) == 99 ){ // loop 'til QUIT
    			printf(" # [HandlerID: %x] Closing connection by command QUIT\n", socket);
				fflush(stdout);
				terminate_client=1;
				continue; // goto next loop
    		}

    		//Send the message back to client
            write(socket, client_message , strlen(client_message));

    		//clear the message buffer
    		memset(client_message, 0, MAX_BUFF_SIZE);

    	    message = "[MTd]$ ";
    	    write(socket , message , strlen(message));
    	}
    	else {
    		puts(" %% Term received");
    		terminate_client=1;
    	}
    } while (!terminate_client);

    //puts("1 exit rcv");

    if(read_size == 0)
    {
        puts(" %% Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror(" %% Recv failed");
    }

    countConn--;

    //pthread_exit(0);
    // Close TCP socket for client
    if (socket) close(socket);

    /*if (socket) puts(" %% Client not disconnected.");
    else puts(" %% Client disconnected.");*/
    //printf(" # [HandlerID: %x] Client disconnected\n", socket);
	fflush(stdout);

    return 0;
}


/* Main */
int mtd_srv_main(void)
{
    int socket_desc , client_sock , len;
    struct sockaddr_in server , client;
    pthread_t thread_id;

    //mtd_srv_client_t mtd_srv_client;

    socket_desc = countConn = 0;
    len = sizeof(struct sockaddr_in);

	// Start server
	if ( mtd_srv_init(&server, &socket_desc) == 0 ) {
	    printf (" [Success] \n");
	} else {
		fflush(stdout); printf(" %% Error starting server \n");
		exit(1);
	}

	// Client

    //Accept and incoming connection
    puts(" # Waiting for incoming connections...");

	while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&len)) )
    {
        countConn++;
    	printf(" # Receiving connection [%d] ... ", countConn);

        if( pthread_create( &thread_id , NULL , mtd_srv_connection_handler , (void*)&client_sock) < 0)
        {
            perror(" [FAIL] could not create thread");
            return 1;
        }
        else
        	printf("[OK] [Handler assigned: %x]\n", client_sock);
    }

    if (client_sock < 0)
    {
        perror(" %% Accept failed ");
        return 1;
    }

    return 0;
}


int main(int argc , char *argv[])
{
	mtd_srv_main();
}

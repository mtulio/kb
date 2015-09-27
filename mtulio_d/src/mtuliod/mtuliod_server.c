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


//the thread function
void *mtd_srv_connection_handler(void *);

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

// Custom types
int countConn;
typedef struct {
	int socket_fd;
	struct sockaddr_in socket_addr;
	unsigned int clientId;
} mtd_srv_client_t;

int mtd_srv_main()
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


    //while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
	/*while( (mtd_srv_client.socket_fd = accept(socket_desc, (struct sockaddr *)&mtd_srv_client.socket_addr, (socklen_t*)&len)) )*/
	while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&len)) )
    {
        countConn++;
    	printf(" # Receiving connection [%d] ... ", countConn);
    	//mtd_srv_client.clientId = countConn;
    	//printf("s: socket_fd[%d]", mtd_srv_client.socket_fd);

        if( pthread_create( &thread_id , NULL , mtd_srv_connection_handler ,
				/*(void*)&mtd_srv_client*/ (void*)&client_sock) < 0)
        {
            perror(" [FAIL] could not create thread");
            return 1;
        }
        else {
        	printf("[OK] Handler assigned [%x]\n", client_sock);
        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( thread_id , NULL);
        //puts("Handler assigned");
        // check treads,
    }

    if (client_sock < 0)
    {
        perror(" %% Accept failed ");
        return 1;
    }

    return 0;
}


/**/

int main(int argc , char *argv[])
{
	mtd_srv_main();
}

/*
 * This will handle connection for each client
 * */
void *mtd_srv_connection_handler(void *socket_data)
{
	// Getting struct from parent
	//mtd_srv_client_t mtd_srv_client = *(mtd_srv_client_t*)socket_data;

	//Get the socket descriptor
    int socket = *(int*)socket_data;
	//printf("h: socket_fd[%d]", mtd_srv_client.socket_fd);
	//int sock = mtd_srv_client.socket_fd;
	//int clientId = mtd_srv_client.clientId;

    int read_size;
    char *message , client_message[2000];

    //Send some messages to the client
	message = "Greetings! I am your connection handler\n";
	//sprintf(message, "Greetings Client[%d]! I am your connection handler\n", clientId);
    //write(mtd_srv_client.socket_fd , message , strlen(message));
    write(socket, message , strlen(message));

    message = "Now type something and i shall repeat what you type \n";
    //write(mtd_srv_client.socket_fd , message , strlen(message));
    write(socket , message , strlen(message));

    //Receive a message from client
    int terminate_client = 0;
    //while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    do
    {
    	//if ((read_size = recv(mtd_srv_client.socket_fd , client_message , 2000 , 0)) > 0) {
		if ((read_size = recv(socket , client_message , 2000 , 0)) > 0) {
            //end of string marker
    		client_message[read_size] = '\0';
    		printf("%s\n", client_message);
    		if (strncmp(client_message, "QUIT", 4) == 0) {
    			printf("received QUIT\n");
    			terminate_client=1;
    		}

    		//Send the message back to client
    		//write(mtd_srv_client.socket_fd , client_message , strlen(client_message));
            write(socket, client_message , strlen(client_message));

    		//clear the message buffer
    		memset(client_message, 0, 2000);
    	}
    	else {
    		puts("1 term received");
    		terminate_client=1;
    	}
    } while (!terminate_client);

    puts("1 exit rcv");

    if(read_size == 0)
    {
        puts("1 Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    puts("2 Client disconnected");
    countConn--;
    //pthread_exit(0);
    // Close TCP socket for client
    //if (mtd_srv_client.socket_fd) close(mtd_srv_client.socket_fd);
    if (socket) close(socket);
    //if (socket_data) free(socket_data);
    return 0;
}

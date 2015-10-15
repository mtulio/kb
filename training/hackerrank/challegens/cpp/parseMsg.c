#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GLOBALS
unsigned int N=0;

unsigned int check_bank(int a, int b) {
	if (a==b) {
		/*printf ("\n1__FUNCTION__ = %s : a[%d] b[%d]\n", __FUNCTION__, a, b);*/ return 0;
	} else if ( a<1 || b<1 || a>N || b>N )  {
		/*printf ("\n2__FUNCTION__ = %s\n", __FUNCTION__);*/ return 0;
	} else {
		/*printf ("\n3__FUNCTION__ = %s\n", __FUNCTION__);*/ return 1; }
}

unsigned int check_maxNodes(int q) {
	if ( q<0 || q>100 ) {
		/*printf ("\n1__FUNCTION__ = %s : q[%d] \n", __FUNCTION__, q);*/ return 0;
	} else 
		return 1;
}

/* Function to get number of Columns by delimiter from an string */
int mtdLib_str_getColNumbers(char *array, char delimiter)
{
	int pos, count;
	pos = count = 0;
	for (pos=0; array[pos]!='\0'; pos++)
		if (array[pos] == delimiter)
			count++;

	// check line is not finishing with delimiter. Eg. delimiter=',': [A,B,]
	if (array[pos-1]!=delimiter)
		count++;

	return count;
}

/* Get integer value from column by position of delimiter - number of
 * column could be get by function mtdLib_str_getColNumbers() */
void mtdLib_str_getColByDelPos_int(char *array_in, char delimiter, int posDel, int *resp)
{
	int count=1; // considering that exist at least delimiter

	char *buff;
	buff = malloc(sizeof(char *)*strlen(array_in));
	memset(buff,strlen(buff),'\0');

	for (int posA=0, posB=0; posA<strlen(array_in); posA++) {
		if (array_in[posA]==delimiter)
			count++;
		else
			if (count==posDel) { // save data of Column
				buff[posB]=array_in[posA];
				posB++;
			}
	}
	*resp=atoi(buff);
	//printf("%s(resp[%d]) buff(%s)\n", __FUNCTION__, resp, buff);
	if (buff) free(buff);

	return;
}


void process_client_message(char *messageLine)
{
	char delimiter = ',';
	int nCol = mtdLib_str_getColNumbers(messageLine, delimiter);
	int a, b, q;
	a = b = q = 0;

	mtdLib_str_getColByDelPos_int(messageLine, delimiter, 1, &a);
	mtdLib_str_getColByDelPos_int(messageLine, delimiter, 2, &b);
	mtdLib_str_getColByDelPos_int(messageLine, delimiter, 3, &q);
	if (!check_bank(a,b)) {
		printf("\nNO2"); printf(" a[%d] b[%d] q[%d]", a, b, q);
		return;
	}
	if (!check_maxNodes(q)) {
		// send NO answer
		printf("\nNO"); printf(" a[%d] b[%d] q[%d]", a, b, q);
		return;
	} else {
		// send answer to client
		printf("\nYES"); printf(" a[%d] b[%d] q[%d]", a, b, q);
		return;
	}

}

/*******************************************/
/*
 * This function is called only once before any client connection is accepted by the server.
 * Read any global datasets or configurations here
 * */
void init_server(void)
{
	printf("Reading configuration\n");
	fflush(stdout);

	FILE *fd;
	char config_file[] = "parseMsg_bank_training.txt";
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int count_lines = 0;

	// Open Config file
	if ((fd = fopen(config_file, "r")) == NULL)
		return;

	// Reading Config File - line by line / one line
	while ((read = getline(&line,  &len, fd)) != -1 ){
		count_lines++;
		if (count_lines <= 1) {
			N=atoi(line);
			//printf(" Number of banks: %zu [%d] :\n", read, N);
			//printf("%s", line);
		}
		else
			break;
	}
 
	//printf("#> Number of Banks: %d \n", N);

	if (fd) fclose(fd);
	if (line) free(line);

	//printf("# Server init success.");
	return;
}  

/* Original function */
/*
 * Write your code here
 * This function is called everytime a new connection is accepted by the server

void process_client_connection(void)
{
	// read client
    connection_t * conn;

    if (!ptr) pthread_exit(0);
    conn = (connection_t *)ptr;

    printf("Connection received\n");
     fflush(stdout);

    int terminate_client = 0;
    do
    {
        // read length of message
        char *message = NULL;
        uint32_t message_length = 0;

        // read message
        read_string_from_socket(conn->sock, &message, &message_length);

        printf("Received = %s\n", message);

        // End of operation on this clinet
        if (strcmp(message, "END") == 0)
            terminate_client = 1;
        else {
            // parsing message
            for (pos=0; message)
            strncmp(message,)

            // write message
            write_string_to_socket(conn->sock, message, message_length);
        }


        free(message);

    } while(!terminate_client);

    // close socket and clean up
    printf("Closing client on socket %d\n", conn->sock);
    fflush(stdout);
    close(conn->sock);
    free(conn);
    pthread_exit(0);
}*/
void process_client_connection(void)
{
	// Get msgs from a file
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int count_lines, count_lines_ok;
	count_lines = count_lines_ok = 0;
	char config_file[] = "parseMsg_client_training.txt";

	// Open Config file
	if ((fd = fopen(config_file, "r")) == NULL)
	{
		printf("Unable to load config file named %s", config_file);
		exit(1);
	}

	// Reading Config File - line by line
	while ((read = getline(&line,  &len, fd)) != -1 ){
		fflush(stdout);
		count_lines++;
		if ((strncmp(line,"END",strlen("END")))) {
			process_client_message(line);
			count_lines_ok++;
		}
	}

	printf("\n#> Number of msgs  processed from client: %d", count_lines);
	printf("\n#> Number of valid msgs  processed from client: %d \n", count_lines_ok);

	if (fd) fclose(fd);
	if (line) free(line);


}

int main(void) {

	init_server();
	process_client_connection();

	printf("\n");
	exit (0);
}


#include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
#include <time.h>



int teclado()
{
  fd_set fdset;
  int fd = 0;//teclado
  struct timeval timeout;
  FD_ZERO(&fdset);
  FD_SET(fd, &fdset);
  timeout.tv_sec  = 1;
  timeout.tv_usec = 0;
  return(select(1, &fdset, 0, 0, &timeout));
}




int audio_leitura;
unsigned char buffer[32];
main(argc, argv)
	int argc;
	char *argv[];
{
	int sock;
    unsigned short int i,j,k;
    short int dif=0;
	struct sockaddr_in server;
	struct hostent *hp, *gethostbyname();
	

/* Cria o socket */
	sock=socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("abertura de socket");
		exit(0);
	}

/* Conecta o socket utilizando o nome especificado na linha de comando */

	server.sin_family = PF_INET;
	hp = gethostbyname(argv[1]);
	if (hp==0) {
		fprintf(stderr, "%s: host desconhecido.", argv[1]);
		exit(2);
	}

	bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
	server.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (struct sockaddr *)&server, sizeof server) < 0)
	{
		perror(" conexao de socket ");
		exit(1);
	}
	audio_leitura = open("/dev/audio", O_RDONLY);
	while (!teclado())
	{
		read(audio_leitura, buffer,32);   
		if(write(sock, buffer, 32) < 0)
			perror(" escrita no socket ");
	}
	close(audio_leitura);
	close(sock);
	exit(0);
}

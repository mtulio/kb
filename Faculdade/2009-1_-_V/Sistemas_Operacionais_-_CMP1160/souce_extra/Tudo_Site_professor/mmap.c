//CMP1160 - Sistemas operacionais 
//Programa para efetuar a copia de um arquivo para outro
//por meio do compartilhamento de memoria. A referencia é pelo
//descritor de arquivos adotado por mmap() 

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>    /* mmap */
#include <fcntl.h>
#include <unistd.h>

#ifndef MAP_FILE  /* Unix 4.3 BSD define esta macro e a requer */
#define MAP_FILE 0   /* para que compile em outros sistemas */
#endif

int
main (int argc, char *argv[])
{
  int             fdin, fdout;
  char            *src, *dst;
  struct stat     statbuf;
  
  if (argc != 3) {
    fprintf(stderr, "Uso e' %s <arq origem> <arq destino>\n",
	    argv[0]);
    exit(1);
  }

  if ( (fdin = open(argv[1], O_RDONLY) ) < 0 ) {
    fprintf(stderr, "Arquivo %s nao pode ser  aberto para reading\n",
	    argv[1]);
    exit(1);
  }

  if ( (fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 
		     (S_IRUSR | S_IWUSR | S_IXGRP | S_IXOTH) ) ) < 0 ) {
    fprintf(stderr, "Arquivo %s nao pode ser  criado para writing \n",
	    argv[2]);
    exit(1);
  }

  if (fstat(fdin, &statbuf) < 0)  { /* precisamos do tamanho do
				    ** arquivo de entrada */
    perror("Erro no fstat");
    exit(1);
  }

  if (lseek(fdout, statbuf.st_size - 1, SEEK_SET) == -1 ) {
    perror("Erro no lseek");
    exit(1);
  }

  if (write(fdout, "", 1) != 1) {
    perror ("Erro no write");
    exit(1);
  }

  if ( (src = mmap (0, statbuf.st_size, PROT_READ,
		    MAP_FILE | MAP_SHARED, fdin, 0 ) ) == (caddr_t) -1) {
    fprintf(stderr, "Erro no mmap para input");
    exit(1);
  }

  if ( (dst = mmap (0, statbuf.st_size, PROT_READ | PROT_WRITE,
		    MAP_FILE | MAP_SHARED, fdout, 0 ) ) == (caddr_t) -1) {
    fprintf(stderr, "Erro no mmap para output");
    exit(1);
  }
  
  memcpy (dst, src, statbuf.st_size);   /* faz a copia */

  exit(0);
}


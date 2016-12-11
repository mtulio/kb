// semabinit.c - inicializacao do semaforo contador para uso de sema.c and semb.c
//compilacao : gcc -o semabinit semabinit.c

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

#define KEY (1492)  
//identificador externo para o semaforo ser acessado por outros
//programa . Ex mude o valor de key recompile e verifique a alocacao
//dos semaforos com ipcs -s

int main(void)
{
   int id; //identificador do semaforo dentro do programa

 //define o argumanto para semctl() maiores detalhes digite: man semctl()

	union semun {
		int val;
		struct semid_ds *buf;
		ushort * array;
	} argument;

   argument.val = 0;
   
   id = semget(KEY, 1, 0666 | IPC_CREAT);//cria novo semaforo


   if(id < 0)
   {
      fprintf(stderr, "Erro na criacao do semaforo\n");
      exit(0);
   }

   //definindo valor para semaforo
   
   if( semctl(id, 0, SETVAL, argument) < 0)
   {
      fprintf( stderr, "Erro na definicao do valor do semaforo\n");
   }
   else
   {
      fprintf(stderr, "Semaforo %d inicializado\n", KEY);
   }
return 0;
}

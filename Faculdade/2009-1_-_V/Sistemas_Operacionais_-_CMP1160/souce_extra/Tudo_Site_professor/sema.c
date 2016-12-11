/* Realiza operacao V () no semaforo criado por semainit*/
/* Compilacao:gcc -o sema sema.c */
//Execucao : Execute ./semainit (para criar o semaforo)
//              "    ./semab & (para fazer espera bloqueada no semaforo)
//              "    ./sema & (para verificar que os processos bloqueado vao
//                           sendo liberado um-a-um)
//              " Para obeservar processo execute : ps -yla    

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY (1492)

int main(void)
{
   int id;  /* identificador interno do semaforo */
   struct sembuf operations[1];
   /* um  "array" de operacoes executadas pelo semaforo */

   int retval; /* retorna o valor de semop() */

   /* obtem o index para o semaforo via KEY. */
   id = semget(KEY, 1, 0666);
   if(id < 0)
   /* Se o semaforo ainda nao foi criado */
   {
      fprintf(stderr, "Semaforo Inexistente! Execute ./semabinit\n");
      exit(0);
   }

   /* Inicio da operacao V () */
   printf("Inicio da operacao V ()\n");

   /* Configura a struct sembuf*/
    operations[0].sem_num = 0;
    operations[0].sem_op = 1;
    operations[0].sem_flg = 0;

    /* Executa operacao */
    retval = semop(id, operations, 1);

    if(retval == 0)
    {
       printf("Operacao V () executada com sucesso\n");
    }
    else
    {
       printf("Erro em semop ()\n");
    }
return 0;
}


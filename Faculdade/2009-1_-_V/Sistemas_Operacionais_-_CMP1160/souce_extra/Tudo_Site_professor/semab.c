//exemplo que executa operacao P() no semaforo
//semab deve ser inicializado antes que sema [V() no semaforo]
//para tanto :
// Execute semb & (& e para evitar a necessidade de executar sema
// em outro terminal)

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY (1492) 
//identificado do semaforo manipulado

int main(void)
{
   int id;  //identificador interno do semaforo
   struct sembuf operations[1];
   //Um "array" que define uma no semaforo

   int retval; //Retorna valor de semop() 

   //obtem o index para o semaforo com nome externo apartir de KEY
   id = semget(KEY, 1, 0666);
   if(id < 0)
   // Semaforo nao existe
   {
      fprintf(stderr, "Semaforo nao localizado\n");
      exit(0);
   }

   /* prepara para execucao de P () */
   operations[0].sem_num = 0;
   operations[0].sem_op = -1;//subtrai 1 do semaforo
   operations[0].sem_flg = 0;//processo vai ficar bloqueado

   retval = semop(id, operations, 1);

    if(retval == 0)
    {
    printf("Operacao P() executada com sucesso pelo Processo : %d \n", getpid());
    }
    else
    {
       printf("Falha em P()\n");
    }
return 0;
}


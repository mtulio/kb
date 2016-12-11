//exemplo de semaforo binario
//usando pthread_mutex para assegurar exclusao mutua
//compilacao:  gcc -o mutex mutex.c -lpthread 

#include <pthread.h>
#include <stdio.h>

void * simple(void *);

#define NUM_THREADS 100
pthread_t tid[NUM_THREADS];      /* IDs das threads */

int bignum = 0;
pthread_mutex_t mut;

main( int argc, char *argv[] ) 
{
  int i, ret;

  pthread_mutex_init(&mut, NULL);

  for (i=0; i<NUM_THREADS; i++) {
    pthread_create(&tid[i], NULL, simple, NULL);
  }
  for ( i = 0; i < NUM_THREADS; i++) { pthread_join(tid[i], NULL);}

  printf(" %d threads criadas e finalizadas\n", i);
  printf("Valor da SCritica=%d\n", bignum);

}  /* main */

  

void * simple(void * parm)
{ 
  int i;
  for(i=0;i<100;i++) {
     pthread_mutex_lock(&mut);   
       bignum++;  /* secao critica */
     pthread_mutex_unlock(&mut);
  }
}    


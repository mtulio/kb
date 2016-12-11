// codigo produtor/consumidor usando mutex e variaveis de condicao
// para melhor entendimento use o manual do linux man <nome da funcao>
// Ex. altere o tamnho de NUMITENS para verificar a espera do produtor
//compilacao:  gcc -o prodcons prodcons.c -lpthread 


#include <pthread.h>
#include <stdio.h>

#define BSIZE 4
#define NUMITEMS 3

typedef struct {
  char buf[BSIZE];
  int occupied;
  int nextin, nextout;
  pthread_mutex_t mutex;
  pthread_cond_t more;
  pthread_cond_t less;
} buffer_t;

buffer_t buffer;

void * producer(void *);
void * consumer(void *);


#define NUM_THREADS 2
pthread_t tid[NUM_THREADS];      /* conjunto de IDs de thread */

main( int argc, char *argv[] ) 
{
  int i;

  pthread_cond_init(&(buffer.more), NULL);
  pthread_cond_init(&(buffer.less), NULL);

  pthread_create(&tid[1], NULL, consumer, NULL);
  pthread_create(&tid[0], NULL, producer, NULL);
  for ( i = 0; i < NUM_THREADS; i++)
    pthread_join(tid[i], NULL);

  printf("\nTodas as %d threads terminaram\n", i);

} 

  

void * producer(void * parm)
{
  char item[NUMITEMS]="SOI";
  int i;

  printf("Produtor iniciado...\n");

  for(i=0;i<NUMITEMS;i++)
    { /* produz um item, um caracter por vez para item[] */

      if (item[i] == '\0') break;  /* Finaliza se chegar ao final da String */

      pthread_mutex_lock(&(buffer.mutex));

      if (buffer.occupied >= BSIZE) printf("Produtor esperando ???\n");
      while (buffer.occupied >= BSIZE)
	pthread_cond_wait(&(buffer.less), &(buffer.mutex) );
      printf("Produtor executando: colocando caracter %d no buffer\n",i);

      buffer.buf[buffer.nextin++] = item[i];
      buffer.nextin %= BSIZE;
      buffer.occupied++;
      
      pthread_cond_signal(&(buffer.more));
      pthread_mutex_unlock(&(buffer.mutex));
    }
  printf("Produtor Finalizando!\n");
  pthread_exit(0);
}    

void * consumer(void * parm)
{
  char item;
  int i;

  printf("Consumidor iniciado...\n");

  for(i=0;i<NUMITEMS;i++){

  pthread_mutex_lock(&(buffer.mutex) );

  if (buffer.occupied <= 0) printf("Consumidor esperando ???\n");
  while(buffer.occupied <= 0)
    pthread_cond_wait(&(buffer.more), &(buffer.mutex) );
  printf("Consumidor executando : retirando caracter %d do buffer\n",i);

  item = buffer.buf[buffer.nextout++];
  printf("Conteudo do slot %d => %c\n",i,item);
  buffer.nextout %= BSIZE;
  buffer.occupied--;

  pthread_cond_signal(&(buffer.less));
  pthread_mutex_unlock(&(buffer.mutex));
  }
  printf("Consumidor finalizando!\n");
  pthread_exit(0);
}



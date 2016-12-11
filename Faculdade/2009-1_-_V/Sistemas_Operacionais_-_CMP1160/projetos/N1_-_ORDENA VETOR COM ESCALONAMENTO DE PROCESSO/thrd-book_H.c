#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#define NUM_THREADS 5

void aleatorio(int *vet,int tam)
{
	vet[tam];
	srand(tam); //gerando nros aleatorios
	int num, i;
	for(i=0;i<tam;i++){//inicio for
		num = rand() % tam; //gera um numero
		vet[i] = num;
	}//fim for
	      //return vet;
}

void imprimir(int *vet ,int tam)

{
	int i;
	for(i=0; i<tam; i++)
    {
        printf(" Vetor[%i]=%i \n",i,vet[i]);   
    }//fim for impressao
}

void Selecao(int *vetor,int tam)
{ 
	int x, i, j, Min;
  
  for (i = 1; i <= tam - 1; i++) 
    {
	  Min = i;
      for (j = i + 1; j <= tam; j++) if (vetor[j] < vetor[Min]) Min = j;
      x = vetor[Min]; vetor[Min] = vetor[i]; vetor[i] = x;
    }
}

/* the thread runs in this function */
void *runner(void *param); 

int main(int argc, char *argv[])
{
	int i, scope;
	pthread_t tid[NUM_THREADS]; 	/* the thread identifier */
	pthread_attr_t attr; 		/* set of attributes for the thread */

	/* get the default attributes */
	pthread_attr_init(&attr);

	/* first inquire on the current scope */
	if (pthread_attr_getscope(&attr, &scope) != 0)
		fprintf(stderr, "Unable to get scheduling scope\n");
	else {
		if (scope == PTHREAD_SCOPE_PROCESS)
			printf("PTHREAD_SCOPE_PROCESS\n");
		else if (scope == PTHREAD_SCOPE_SYSTEM)
			printf("PTHREAD_SCOPE_SYSTEM\n");
		else 
			fprintf(stderr,"Illegal scope value\n");
	}
	
	/* set the scheduling algorithm PROCESS or SYSTEM */
	/* On Linux and Mac OS X 10.3.4 systems, 
	 * only PTHREAD_SCOPE_SYSTEM is supported. 
	 * Solaris supports both. */
	if (pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM) != 0)
		fprintf(stderr, "Unable to set scheduling scope\n");
	
	/* now create the threads */
	for (i = 0; i < NUM_THREADS; i++) 
		pthread_create(&tid[i],&attr,runner,NULL); 

	/**
	 * Now join on each thread
	 */
	for (i = 0; i < NUM_THREADS; i++) 
		pthread_join(tid[i], NULL);
}

/**
 * The thread will begin control in this function.
 * Each thread will output its own version of "Hello World"
 */
void *runner(void *param) 
{
	int tam=1000;
	int vet[tam];
	double ti,tf,insert,qu,sh,he,se;
	struct timeval tempo_inicio, tempo_fim;
	aleatorio(vet,tam);
	//imprimir(vet,tam);
	gettimeofday(&tempo_inicio,NULL);
	Selecao(vet,tam);
	gettimeofday(&tempo_fim,NULL);
	//imprimir(vet,tam);
	tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
	ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
	se = (tf-ti);
	printf("|  Selecao  | %.0lf microsegundos \n",se);
	pthread_exit(0);
}


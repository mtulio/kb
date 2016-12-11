//CMP1160 - Sistemas Operacionais
//pthread.h - implementa e gerencia threads nivel usuario
//Este programa usa tres threads: as duas primeiras preenchem um vetor cada (vetor a e b)
//enquanto a terceira soma os elementos dois dois vetores e armazena em um terceiro (vetor c)

#include <stdio.h>
#include <pthread.h>


void func1(int *id);
void func2(int *id);
void func3(int *id);

/*Os vetores devem ser maiores que o total que sera utilizado, 
porque a thread nao preenche a ultima celula */

int a[10],b[10],c[10]; //vetores

int main(){

pthread_t thr1,thr2,thr3; /* declara as threads */
int nThrID1,nThrID2,nThrID3;/*define Thread ID*/
nThrID1 = 1;
nThrID2 = 2;
nThrID3 = 3;

	/* cria threads: id, inic, funcao, param funcao */
	pthread_create(&thr1,NULL,(void* )func1,&nThrID1);
	pthread_create(&thr2,NULL,(void* )func2,&nThrID2);
	pthread_create(&thr3,NULL,(void* )func3,&nThrID3);

	/* espera fim das threads: id, status de saida */
	pthread_join(thr1,NULL);//analogo a chamada wait()/
	pthread_join(thr2,NULL);
	pthread_join(thr3,NULL);


}


void func1(int *id)//funcao que preenche o vetor a, executada pela thread 1
{
  int cont=0;
  for(cont;cont < 6;cont++) a[cont]=cont;
  printf("\nValores do vetor a\n");
  cont=0;
  printf("\n");
  for(cont;cont < 6;cont++) printf(" %d ",a[cont]);
  printf("\n");
}

void func2(int *id)//funcao que preenche o vetor b, executada pela thread 2
{
  int cont=0;
  for(cont;cont < 6;cont++) b[cont]=cont;
  printf("\nValores do vetor b\n\n");
  cont=0;
  for(cont;cont < 6;cont++) printf(" %d ",b[cont]);
  printf("\n");
}

void func3(int *id)//funcao que soma os vetores a e b, executada pela thread 3
{
  int cont=0;
  for(cont;cont < 6;cont++) c[cont]=a[cont]+b[cont];
  printf("\nSoma dos outros vetores\n\n");
  cont=0;
  for(cont;cont < 6;cont++) printf(" %d ",c[cont]);
  printf("\n");
}


/* compilacao: gcc -o threads  threads.c -lpthread */ 



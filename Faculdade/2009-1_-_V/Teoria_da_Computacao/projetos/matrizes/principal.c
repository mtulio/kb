#include <stdio.h>
#include <sys/time.h>
#include "algoritmos.h"

void echo(int **A, int n)
{
	int i, j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			printf("A[%d][%d]=%d\n",i+1, j+1, A[i][j]);
}

int main(void)
{
	int **A, *b, *x, ordem, i, j, e;
	printf("Lendo do arquivo a ordem da matriz, aguarde");
	scanf("%d", &ordem);

	A = (int **) malloc(ordem * sizeof(int *));
	for(i = 0; i < ordem; i++)
	{
		A[i] = (int *) malloc(ordem * sizeof(int));
		for(j = 0; j < ordem; j++)
		{
			//printf("A[%d][%d]= ", i + 1, j + 1);
			scanf("%d", &e);
			A[i][j] = e;
		}
	}

	printf("\nLendo os valores do vetor, por favor aguarde\n");

	b = (int *)  malloc(ordem * sizeof(int));
	for(i = 0; i < ordem; i++)
	{
		//printf("b[%d] = ", i);
		scanf("%d", &e);
		b[i] = e;
	}
	double ti, tf, tr;
	struct timeval tempo_inicio, tempo_fim;
	gettimeofday(&tempo_inicio, NULL);

	//execução do algoritmos aqui
	x = algoritmo2(A, b, ordem);
	//execução do algoritmos aqui
	gettimeofday(&tempo_fim, NULL);

	tf = (double) tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * 1000000);
	ti = (double) tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * 1000000);

	tr = tf - ti;

	for(i = 0; i < ordem; i++)
		printf("\nx[%d] = %d.\n", i + 1, x[i]);

	printf("\nO tempo gasto foi %.3f usec.\n", tr);

	for(i = 0; i < ordem; i++)
	{
		free(A[i]);
	}
	free(A);
	free(b);
	return 0;
}

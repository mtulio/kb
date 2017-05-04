#include <math.h>
#include <stdlib.h>
/* SUBMATRIZ
 * Escolhe um elemento, elimina a linha e a coluna daquele elemento e calcula
 * o determinante dos restantes dos elementos
 * */
int** subMatriz(int **A, int ordem, int linha, int coluna)
{
	int i, j, c, l, **aux; //decalração
	aux = (int **) malloc((ordem - 1) * sizeof(int *)); //aloca o ponteiro
	for(i = 0, l = 0; i < ordem; i++) //variando o elemento pelas linhas
	{
		if(i != linha) //se o elemento for diferente da linha (fazendo a eliminaçao)
		{
			aux[l] = (int *) malloc((ordem - 1) * sizeof(int));
			//caso for aloca um ponteiro
			//faço a operação onde vou ter meu vetor de linhas sem o elemento
			//escolhido em outras palavras aux[l] é o vetor de linhas
			for(j = 0, c = 0; j < ordem; j++) //variando o elemento pelas colunas
			{
				if(j != coluna) //se o elemento for diferente da coluna
				{
					aux[l][c] = A[i][j];
					//faço o meu elemento aux receber o original
					c++;
				}
			}
		l++;
		}
	}
	return aux; //retorno o meu auxiliar
}
/*Algoritmo 1
 * Passo a minha matriz (ponteiro de um ponteiro) e a minha ordem (1x1, 2x2, 3x3 ...) por parametro
/* objetivo: calcular o determinante dependendo da ordem
 */
int algoritmo1(int** A, int ordem)
{
	int i, j, determinante = 0;
	if(ordem == 1)
		determinante = A[0][0]; //se for 1 o determinante é o proprio elemento
	if(ordem == 2)
		determinante = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	//se a ordem for 2 eu multiplico as diagonais principais e subtraio elas logo em seguida
	if(ordem > 2)
		for(i = 0, j = 0; j < ordem; j++)
			determinante = determinante + A[i][j] * pow(-1, (i + j)) * algoritmo1(subMatriz(A, ordem, i, j), ordem - 1);
	//se for maior que 2 uso o algoritmo passado pelo professor usando uma certa recursividade
	return determinante; //retorno o determinante
}
/* Algoritmo 2 (CRAMER)
 * passo minha matriz, meu b (do termo Ax = b), e a minha ordem (1x1, 2x2, 3x3, .....)
 * */
int* algoritmo2(int **A, int *b, int ordem)
{
	int *x, i, j, *aux; //declarando as variaveis, ponteiros ..
	x = (int *)malloc(ordem * sizeof(int )); //aloco meu ponteiro x
	aux = (int *)malloc(ordem * sizeof(int )); //aloco meu ponteiro aux
	if(ordem == 1) //se for igual a 1
		x[0] = b[0] / A[0][0]; //faço a operação para achar o x[0]
	if(ordem > 1)
	{
		int detA, detB;
		detA = algoritmo1(A, ordem); //calculando o determinante da
		// matriz original e já fazendo o detA receber o proprio

		for(j = 0; j < ordem; j++)//laço para rodar/variar minhas linhas
		{
			for(i = 0; i < ordem; i++) //laço para rodar/variar minhas colunas
			{
				aux[i] = A[i][j]; //fazendo backup.. para nao perder o elemento atual
				A[i][j] = b[i]; //fazendo a substituiçao necessária
			}

			detB = algoritmo1(A, ordem); //calculo o determinante
			//como possuo dois determinantes meu x vai ser a divisao dos dois
			x[j] = (int )(detB / detA);

			for(i = 0; i < ordem; i++)
				A[i][j] = aux[i]; //voltando a matriz original
		}
	}
	return x;
}

/*
 * CHEATER
 */
int* algoritmo3(int **A, int *b, int n)
{
	int *x, i, j, soma;
	x = (int *)malloc(n * sizeof(int));
	x[n - 1] = b[n - 1] / A[n - 1][n - 1];
	for(i = n - 2; i >= 0; i--)
	{
		soma = 0;
		for(j = i + 1; j < n; j++)
			soma = soma + A[i][j] * x[j];
		b[i] = (b[i] - soma) / A[i][i];
		x[i] = b[i];
	}
	return x;
}
/*
 * CHEATER
 */
int* algoritmo4(int **A, int *b, int n)
{
	int m, i, j, k;
	for(k = 0; k < n - 1; k++)
	{
		for(i = k + 1; i < n; i++)
		{
			m = A[i][k] / A[k][k];
			A[i][k] = 0;
			for(j = k + 1; j < n; j++)
				A[i][j] = A[i][j] - m * A[k][j];
			b[i] = b[i] - m * b[k];
		}
	}
	return algoritmo3(A, b, n);
}

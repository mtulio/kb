/*
 * matrizThread.c
 *
 *  Created on: 12/04/2009
 *      Author: marcotulio
 */

#include<stdio.h>
#include<pthread.h>//biblioteca para uso de threads
#include<stdio.h>

//criando ponteiros para elementos da diag princi e secundaria
int diagPrinc, diagSec, determinante,
	matriz[4];//criando uma matriz de 4 elementos

//descricao dos metodos
void diagPrincipal(){ diagPrinc = matriz[0]*matriz[3]; }
void diagSecundaria(){ diagSec = matriz[1]*matriz[2]; }
void somaDeterminante(){ determinante = diagPrinc - diagSec; }

int main()
{
	system("clear");

	//lendo os elementos da matriz
	printf("\tSistemas Operacionais - N1(Matriz)\n\n");

	int elemento;

	//pegando os valores da matriz
	int i;
	for(i=0; i<4; i++)
	{
		printf("\nDigite o elemento da posicao %i do vetor:",i);
		scanf("%i",&elemento);
		//printf("\nelemento: %i",elemento);
		matriz[i]=elemento;
	}//fim for

	//imprimindo a matriz digitada
	printf("A seguinte matriz foi digitada: \n");
	for(i=0; i<4; i++)
	{
		if(i==0) printf("\n   %i  ",matriz[i]);
		if(i==1) printf("  %i   \n",matriz[i]);
		if(i==2) printf("   %i   ",matriz[i]);
		if(i==3) printf(" %i  \n",matriz[i]);
		//scanf("%i",elemento);
		//matriz[i]=elemento;
	}//fim for

	//criando 3 vars thread para serem executadas no pthread_create
	pthread_t thread1,thread2,thread3;

	//definicao do pthread
	//ptharead(endereçothread, NULL, (tipoFunçao *)nomeFunção,NULL);

	//criando uma thread para diagonal principal
	pthread_create(&thread1,NULL,(void*)diagPrincipal,NULL);

	//criando uma thread para a diagonal secundaria
	pthread_create(&thread2,NULL,(void*)diagSecundaria,NULL);

	//cria uma rhread, thd3, para soma da determinante
	pthread_create(&thread3,NULL,(void*)somaDeterminante,NULL);

	//faz com que a thread3 espera as outras terminarem de executar
	pthread_join(thread3,NULL);

	//imprimindo o resultado final
	printf("\n\t O valor da Determinante é = %d\n",determinante);

}//fim do prog principal

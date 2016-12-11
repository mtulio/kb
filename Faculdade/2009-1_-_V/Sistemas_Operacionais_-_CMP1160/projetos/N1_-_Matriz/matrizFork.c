/*
 * matrizFork.c
 *
 *  Created on: 12/04/2009
 *      Author: marcotulio
 */
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//criando ponteiros para elementos da diag princi e secundaria
int diagPrinc, diagSec;
int matriz[4];//criando uma matriz de 4 elementos

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
	}//fim for

	//criando o processo
	pid_t pid1,pid2;
	//vfork cria um processo filho compartilhando blocos, trocando valores entre eles
	pid1=vfork();
	//verificando se pid1 foi criado, se foi cria o pid2	
	if(pid1>0)pid2=vfork();

	if(pid1<0)
	{	//houve erro-- nao foi possivel criar outro processo
		fprintf(stderr, "ERROR: FALHA NA EXECUÇÃO DO PID1");
		exit(-1);
	}//fim verif erros do pid1
	else if(pid1==0)
	{	//processo filho criado
		diagPrinc = matriz[0]*matriz[3];
		exit(0);
	}//fim da execucao do pid1

	//verificando se n houver erros na criacao do PID2
	if(pid2<0)
	{	//houve erro-- nao foi possivel criar outro processo
		fprintf(stderr, "ERROR: FALHA NA EXECUÇÃO DO PID2");
		exit(-1);
	}//fim verif a criacao do 2 vfork
	else if(pid2==0)
	{	//processo filho criado pid2
		diagSec=matriz[1]*matriz[2];
		exit(0);
	}//fim execucao do 2 fork
	else
	{	//processo pai, espera o processamento das diag principais
		wait(NULL);
		int determinante=0;//determinante
		//calculando o determinante		
		determinante=diagPrinc-diagSec;
		printf("\n\tDeterminante: %i\n\n",determinante);
	}//fim else de espera da execucao do 2 processo
}//fim programa principal

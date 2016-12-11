#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int *dp, *ds;
int mat[4];

int main()
{
	dp=(int*)malloc(sizeof (int));
	ds=(int*)malloc(sizeof (int));

	int x;
	int elemento;

	for(x=0; x<4; x++)
	{
	int n=4;
	elemento=rand()%(n*10);
	mat[x]=elemento;
	printf("\n\tvalor: %i", elemento);
	getchar();
	}

	pid_t pid,pid2;
	//cria outro processo
	pid=vfork();

	if(pid>0)pid2=vfork();


	if(pid<0)
	{	//houve erro-- nao foi possivel criar outro processo
		fprintf(stderr, "ERROR: FALHA NA EXECUÇÃO DO PID1");
		exit(-1);
	}
	else if(pid==0)
	{	//processo filho criado
		int p=0; //diagonal principal
		p=mat[0]*mat[3];
		*dp=p;
		printf("\ndp: %i",*dp);
		exit(0);
	}

	if(pid2<0)
	{	//houve erro-- nao foi possivel criar outro processo
		fprintf(stderr, "ERROR: FALHA NA EXECUÇÃO DO PID2");
		exit(-1);
	}

	else if(pid2==0)
	{	//processo filho criado pid2
		int s=0; //diagonal Secundaria
		s=mat[1]*mat[2];
		*ds=s;
		printf("ds: %i",*ds);
		exit(0);
	}
	else
	{	//processo pai
		wait(NULL);
		int dt=0;//determinante
		dt=*dp-*ds;
		printf("\n\n\tDeterminante: %i\n\n",dt);
	}
}


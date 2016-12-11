#include<stdio.h>
#include<pthread.h>

int mat[4], dp,ds,det;

void dgpri()
{
	dp=mat[0]*mat[3];
}

void dgsec()
{
	ds=mat[1]*mat[2];
}

void somaF()
{
	det=dp-ds;
}


int main()
{	

	pthread_t thd1,thd2,thd3;

	int x;
	int elemento;

	//printf("\n\tUma constante qualquer:\n" );
	//scanf("%i",n);
	
	for(x=0; x<4; x++)
	{ 
	int n=2;
	elemento=rand()%(n*10);
	mat[x]=elemento;
	printf("\n\tvalor: %i", elemento);
	getchar();
	}
	
	//ptharead(endereçothread, NULL, (tipoFunçao *)nomeFunção,NULL);
	
	pthread_create(&thd1,NULL,(void*)dgpri,NULL);// cria a 1 thd para diagonal principal 
	pthread_create(&thd2,NULL,(void*)dgsec,NULL);// cria a 2 thd para diagonal secundaria
	pthread_create(&thd3,NULL,(void*)somaF,NULL);// cria a 3 thd para a soma das diagonais
	
	pthread_join(thd3,NULL);//a thd 3 espera as outras thd (diagonal prin e diagonal sec)
	
	printf("\n\tDeterminante= %d\n",det);

}


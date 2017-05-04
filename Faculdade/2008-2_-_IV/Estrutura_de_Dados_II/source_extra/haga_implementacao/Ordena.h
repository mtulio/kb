#ifndef ORDENA_H_
#define ORDENA_H_
/*
#include <iostream>
using namespace std;
class Ordena
{

	
	public:
		static void insertSort(Vetor *vet, int qtd);
		static void mergeSort( int vet, int pi, int pf);
		void merge(int vet, int pi, int m, int n, int pf);

	
};
void Ordena::insertion(int *vetor,int tam)
{
	int aux,j,i;
   for(i=0; i<tam; i++)
   {
   		aux=vetor[i];
   		j=i;
   		while(j > 0 && vetor[j - 1] > aux)
   		{
   			vetor[j] = vetor[j - 1];  
   			 j--;
   		}
   		vetor[j] = aux;
   }
}

void Ordena::insertSort(Vetor *vet,int qtd)
{
	int j,i,elemento;
	Vetor aux(qtd);
	Vetor aux2(qtd);
   for(i=0; i<qtd; i++)
   {
   		aux=vet[i];
   		j=i;
   		//elemento=vet[j-1].obterElemento();
   		while(j > 0 && vet[j - 1] > aux)
   		{
   			vet[j] = vet[j - 1];  
   			 j--;
   		}
   		vet[j] = aux;
   }
}

/*
void Ordena::insertSort (int *vet, int qtd)
{
	int i, j, x;

	for (j = 1; j < qtd; j++) 
	{
		x = vet[j];
		
		for (i = j-1; i >= 0 && vet > x; --i)
		{
			vet[i+1] = vet;
			vet[i+1] = x;
		}
	}
}
*/
/*
void Ordena::mergeSort(int vet, int pi, int pf)
{
	int m;
	m=(pi+pf)/2;
	if(pf<pi)
	{
		mergeSort(vet, pi, m);
		mergeSort(vet, m+1, pf);
		merge(vet, pi, m, m+1, pf);
	
} 

void Ordena::merge(int vet, int pi, int m, int n, int pf)
{
	k=0;
	Vetor vet2;
	int I, J;
	
	for( I=pi, J=n, I<=m && J<= pf; k++)
	{
		if(vet[i] < vet[j])
		{
			vet2[k]=vet[i];
			i++;
		}
		else
		{
			vet2[k]=vet[j];
			j++;
		}
	}
	
	for(; I<=m;I++, k++)
	{
		vet2[k]=vet[i];
	}
	for(; j<=pf; j++, k++)
	{
		vet2[k]=vet[j];
	}
	for(J=0, int I=pi, I<=pf; I++, J++)
	{
		vet[I]=vet2[J];
		
	}
}
*/
#endif /*ORDENA_H_*/

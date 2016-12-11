#ifndef SHELLSORT_H_
#define SHELLSORT_H_

#include<iostream>

class ShellSort
{
public:
	static void ordena(int vet[], int tam);
};//fim da classe ShellSort

void ShellSort::ordena(int vet[], int tam)
{
	int h;
	
	// descobrindo o valor de h
	for(h=1; h<tam; h = 3*h +1);
	//std::cout<<" tam  de h: "<<h<<std::endl;
	
	do{//condicoa para que o h seja maior do que 1
		h /= 3;
		for(int i=h; i<tam; ++i){
			int valor = vet[i];
			int j;
			for(j=i-h; j>=0 && valor<vet[j];j -= h){
				vet[j+h] = vet[j];
			}//fim for 2
			vet[j+h]=valor;
		}//fim for			
	}while(h>1); //fim do		
}//fim ShellSort

// *********** MENU HEAP SORT

#endif /*SHELLSORT_H_*/

#include"Matriz.h"
#include"InterfaceMatriz.h"
#include<iostream>


int main(void)
{
	Matriz<int> teste(2,2);
	
	teste.atribuirElementoMatriz(0,0,-1);
	teste.atribuirElementoMatriz(0,1,-2);
	teste.atribuirElementoMatriz(1,0,-3);
	teste.atribuirElementoMatriz(1,1,-4);
	
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(0,0);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(0,1);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(1,0);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(1,1);
	
	InterfaceMatriz<int>::escreverMatriz(teste);
	
}


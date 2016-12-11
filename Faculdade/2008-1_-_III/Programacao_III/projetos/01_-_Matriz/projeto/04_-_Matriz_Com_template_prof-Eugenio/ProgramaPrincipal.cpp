#include"Matriz.h"
#include"InterfaceMatriz.h"
#include<string>
#include<iostream>

using namespace std;

int main(void)
{
	//Matriz<int> t;
	Matriz<int> teste(4,4);

	teste.atribuirElementoMatriz(0,0,1);
	teste.atribuirElementoMatriz(0,1,2);
	teste.atribuirElementoMatriz(0,2,1);
	teste.atribuirElementoMatriz(0,3,2);
	teste.atribuirElementoMatriz(1,0,1);
	teste.atribuirElementoMatriz(1,1,2);
	teste.atribuirElementoMatriz(1,2,1);
	teste.atribuirElementoMatriz(1,3,2);
	teste.atribuirElementoMatriz(2,2,1);
	teste.atribuirElementoMatriz(2,1,2);
	teste.atribuirElementoMatriz(2,2,1);
	teste.atribuirElementoMatriz(2,1,2);
	teste.atribuirElementoMatriz(3,2,1);
	teste.atribuirElementoMatriz(3,1,2);
	teste.atribuirElementoMatriz(3,2,1);
	teste.atribuirElementoMatriz(3,2,1);
	
	
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(0,0);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(0,1);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(1,0);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(1,1);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(1,1);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(1,1);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(1,1);
	std::cout<<"\nVALOR "<<teste.obterElementoMatriz(1,1);
	std::cout<<std::endl;
	
	
	//Matriz<double> result(2,2);
	
	if(teste.eTriangularSuperior()) cout<<" Eh triang superior"<<endl;
	else cout<<" Nao eh triang superior"<<endl;
	
	if(teste.eTriangularInferior()) cout<<" Eh triang inferior"<<endl;
	else cout<<" Nao eh triang inferior"<<endl;
	
	//copia = new Matriz<int>(2,2);
	//copia = teste2;
	//teste2 = copia;
	
	InterfaceMatriz<int>::escreverMatriz(teste);
	
}//fim principal

//std::cout<<" TESTS - transposta > here!"<<std::endl<<std::endl;

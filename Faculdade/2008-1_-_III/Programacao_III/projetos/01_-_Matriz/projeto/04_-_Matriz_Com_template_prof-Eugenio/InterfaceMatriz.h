#ifndef INTERFACEMATRIZ_H_
#define INTERFACEMATRIZ_H_
#include"Matriz.h"
#include<iostream>
#include <iomanip>

template <class tipo>
class InterfaceMatriz
{
	public:
//		static void lerMatriz(Matriz<class tipo> &matriz);
		static void escreverMatriz(Matriz<tipo> const &matriz);
};
/*
template <class tipo>
void InterfaceMatriz::lerMatriz(Matriz<class tipo> &matriz)
{
	for(unsigned int linha=0; linha<matriz.obterQuantidadeLinhas();linha++){
		for(unsigned int coluna=0; coluna<matriz.obterQuantidadeColunas();coluna++){
			std::cout<<"Elemento["<<linha<<"]["<<coluna<<"]= ";
			std::cin>>	matriz.atribuirElementoMatriz(linha,coluna);
		}
	}
}
*/
template <class tipo>
void InterfaceMatriz<tipo>::escreverMatriz(Matriz<tipo> const &matriz)
{
	unsigned int qLinhas = matriz.obterQuantidadeLinhas();
	unsigned int qColunas = matriz.obterQuantidadeColunas();
	for(unsigned int linha=0; linha<qLinhas;linha++){
		std::cout<<"|";
		for(unsigned int coluna=0; coluna<qColunas;coluna++){
			std::cout<<std::left<<std::setw(3)<<matriz.obterElementoMatriz(linha,coluna)<<" ";
//			std::cout<<matriz.obterElementoMatriz(linha,coluna);
		}
		std::cout<<std::left<<std::setw(3)<<"|"<<std::endl;
	}
		
}



#endif /*INTERFACEMATRIZ_H_*/

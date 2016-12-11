#include<iostream>
#include <iomanip>

#include "InterfaceMatriz.h"

//*****************************************************************************/* 14 */
void InterfaceMatriz::lerMatriz(Matriz &matriz)
{
	for(unsigned int linha=0; linha<matriz.obterQuantidadeLinhas();linha++){
		for(unsigned int coluna=0; coluna<matriz.obterQuantidadeColunas();coluna++){
			std::cout<<"Elemento["<<linha<<"]["<<coluna<<"]= ";
			int elemento=0;
			std::cin>>elemento;
			matriz.atribuirElementoMatriz(linha,coluna,elemento);
		}
	}
}//fim metodo lerMatriz

//*****************************************************************************/* 14 */
void InterfaceMatriz::escreverMatriz(Matriz const &matriz)
{
	for(unsigned int linha=0; linha<matriz.obterQuantidadeLinhas();linha++){
		std::cout<<"|";
		for(unsigned int coluna=0; coluna<matriz.obterQuantidadeColunas();coluna++){
			int elemento=0;
			matriz.obterElementoMatriz(linha,coluna,elemento);
			std::cout<<std::left<<std::setw(3)<<elemento<<" ";
		}//fim for 2
		std::cout<<std::left<<std::setw(3)<<"|"<<std::endl;
	}//fim for 1
}//fim metodo escreverMatriz

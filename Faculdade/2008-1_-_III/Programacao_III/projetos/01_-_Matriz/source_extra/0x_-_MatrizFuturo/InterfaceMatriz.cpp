#include "InterfaceMatriz.h"
#include<iostream>
#include <iomanip>

void InterfaceMatriz::lerMatriz(Matriz &matriz)
{
	try{
	  for(unsigned int linha=0; linha<matriz.obterQuantidadeLinhas();linha++){
		for(unsigned int coluna=0; coluna<matriz.obterQuantidadeColunas();coluna++){
			std::cout<<"Elemento["<<linha<<"]["<<coluna<<"]= ";
			int elemento=0;
			std::cin>>elemento;
			matriz.atribuirElementoMatriz(linha,coluna,elemento);
		}
	  }
	}//fim try
	catch(std::string msg){
		throw (msg);
	}
	catch(int idException){
	   throw idException;
	}
}//fim lerMatriz

void InterfaceMatriz::escreverMatriz(Matriz const &matriz)
{
	try{
	unsigned int qLinhas = matriz.obterQuantidadeLinhas();
	unsigned int qColunas = matriz.obterQuantidadeColunas();
	
	std::cout<<std::endl<<"Interface: "<<qLinhas<<" , "<<qColunas<<" ."<<std::endl;
	for(unsigned int linha=0; linha<qLinhas;linha++){
		std::cout<<"| ";
		for(unsigned int coluna=0; coluna<qColunas;coluna++){
			int elemento=0;
			elemento=matriz.obterElementoMatriz(linha,coluna);
			std::cout<<std::left<<std::setw(3)<<elemento<<" ";
		}
		std::cout<<std::left<<std::setw(3)<<"|"<<std::endl;
	}//fim for
	
	}//fim try
	
	catch(std::string msg){
		throw msg;
	}//fim catch 1
	catch(int idException){
	   throw idException;
	}
}//fim escreverm matriz

void InterfaceMatriz::menuPrincipal()
{
	system("clear");
	int opcao=0;
	for(opcao=0;opcao!=9;){
		system("clear");
		std::cout<<"         MENU PRINCIPAL            "<<std::endl<<std::endl;
		std::cout<<" 1 - MANTER MATRIZES EM ARQUIVO "<<std::endl;
		std::cout<<" 2 - OPERACOES COM MATRIZES "<<std::endl;
		std::cout<<" 9 - SAIR "<<std::endl;
		std::cout<<"OPCAO: ";
		std::cin>>opcao;
		switch(opcao){// inicio switch
			case 1:		std::cout<<"MANTER MATRIZES EM ARQUIVO - EM CONSTRUCAO";
								break;
			case 2: 	std::cout<<"OPERACOES COM MATRIZES - EM CONSTRUCAO";
								break;
			default:	std::cout<<"OPCAO ERRADA";
		}// fim switch
	}
	
}

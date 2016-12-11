#include "Persistencia.h"
#include "Matriz.h"
#include<iostream>

void Persistencia::atribuirMatrizNoArquivo(Matriz const &matriz, std::string const &nomeDoArquivo)
{
	std::ofstream arquivoMatriz(nomeDoArquivo.c_str());
	unsigned int linha  = matriz.obterQuantidadeLinhas();
	unsigned int coluna = matriz.obterQuantidadeColunas();
    
	arquivoMatriz<<linha<<std::endl;
	arquivoMatriz<<coluna<<std::endl;
	
	for(unsigned int i=0; i<linha; i++){//inicio do for_linha
  		int a;
    	for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
  				a=matriz.obterElementoMatriz(i,j);
    			arquivoMatriz<<a<<std::endl;
    	}//fim do for_coluna
  }//fim do for_linha
  
	arquivoMatriz.close();
}

const Matriz * const Persistencia::obterMatrizDoArquivo(std::string const &nomeDoArquivo)
{
	std::ifstream arquivoMatriz(nomeDoArquivo.c_str());
	
	if(!arquivoMatriz.is_open()) throw std::string("Arquivo de Matriz Nao encontrado!");
	
	unsigned int linha=0,coluna=0;
	arquivoMatriz>>linha;
	arquivoMatriz>> coluna;
	Matriz *matriz = new Matriz(linha,coluna);
	
	for(unsigned int i=0; i<linha; i++){//inicio do for_linha
  		int a;
    	for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
  				arquivoMatriz>>a;
  				matriz->atribuirElementoMatriz(i,j,a);
    	}//fim do for_coluna
  }//fim do for_linha
	arquivoMatriz.close();
	return matriz;
}

#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_

#include<fstream>
#include<string>
#include<iostream>

#include"Matriz.h"

template<class tipo>
class Persistencia{
	public:
		static void atribuirMatrizNoArquivo(Matriz<tipo> const &matriz, std::string const &nomeDoArquivo);
		static const Matriz<tipo> * const obterMatrizDoArquivo(std::string const &nomeDoArquivo);
		static bool buscaArquivoExistente(std::string &nome);
		static void removerMatrizDoArquivo(std::string nome);
	
};//fim da classe Persistencia

template<class tipo>
void Persistencia<tipo>::atribuirMatrizNoArquivo(Matriz<tipo> const &matriz, std::string const &nomeDoArquivo)
{
	
	std::string nomeTemp = nomeDoArquivo;
	if(buscaArquivoExistente(nomeTemp)) throw std::string("Matriz jah existe no arquivo");
	//criando o arquivo dentro de uma pasta especifica
	
	std::ofstream arquivoMatriz(nomeDoArquivo.c_str());
	unsigned int linha  = matriz.obterQuantidadeLinhas();
	unsigned int coluna = matriz.obterQuantidadeColunas();
	  
	arquivoMatriz<<linha<<std::endl;
	arquivoMatriz<<coluna<<std::endl;
	
	try{
		for(unsigned int i=0; i<linha; i++){//inicio do for_linha
		   tipo elemento;
		   for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
		      elemento = matriz.obterElementoMatriz(i,j);
		      arquivoMatriz<<elemento<<std::endl;
		   }//fim do for_coluna
		}//fim do for_linha
	arquivoMatriz.close();
	}//fim try
	catch(std::string msg){
		arquivoMatriz.close();
		throw msg;
	}
}//fim atribuir no arquivo

template<class tipo>
const Matriz<tipo> * const Persistencia<tipo>::obterMatrizDoArquivo(std::string const &nomeDoArquivo)
{
	
	
	std::ifstream arquivoMatriz(nomeDoArquivo.c_str());
	Matriz<tipo> *matriz;
	
	try{
		//std::cout<<"  Nome do arquivo: "<<nomeDoArquivo<<std::endl;
		if(!arquivoMatriz.is_open()) throw std::string("Arquivo de Matriz Nao encontrado!");
	   
	   unsigned int linha=0,coluna=0;
	   arquivoMatriz>>linha;
	   arquivoMatriz>> coluna;

	   matriz = new Matriz<tipo>(linha,coluna);
	    
	   for(unsigned int i=0; i<linha; i++){//inicio do for_linha
	      tipo elemento;
	      for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
	         arquivoMatriz>>elemento;
	  	   	 matriz->atribuirElementoMatriz(i,j, elemento);
	      }//fim do for_coluna
	   }//fim do for_linha
	   arquivoMatriz.close();
	   
	   return matriz;
	}//fim try
	catch(std::string msg){
		arquivoMatriz.close();
		throw msg;
	}
}//fim metodo obter

template<class tipo>
bool Persistencia<tipo>::buscaArquivoExistente(std::string &nome)
{
	std::ifstream arquivo(nome.c_str());
	if(!arquivo.is_open()) return false;
	
	arquivo.close();
	return true;	
}

template<class tipo>
void Persistencia<tipo>::removerMatrizDoArquivo(std::string nome)
{
	
	if(!buscaArquivoExistente(nome)) throw std::string("Matriz nao encontrada Arquivo");
	else std::remove(nome.c_str());
}

#endif /*PERSISTENCIA_H_*/

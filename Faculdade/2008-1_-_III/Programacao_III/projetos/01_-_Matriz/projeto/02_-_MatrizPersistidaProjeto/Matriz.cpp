#include "Matriz.h"
#include<iostream>

Matriz::Matriz(unsigned int quantidadeLinhas, unsigned int quantidadeColunas):
	quantidadeLinhas(quantidadeLinhas),
	quantidadeColunas(quantidadeColunas)
{
	if(quantidadeLinhas==0 || quantidadeColunas==0){
		ptMatriz=0; return;
	}
	ptMatriz = new int[quantidadeLinhas*quantidadeColunas];
}

Matriz::Matriz(const Matriz * const matriz)
{
	unsigned int linha=0,coluna=0;
	if(!matriz){
		ptMatriz = 0;
		quantidadeLinhas=quantidadeColunas=0;
		return;
	}
	quantidadeLinhas=linha = matriz->obterQuantidadeLinhas();
	quantidadeColunas=coluna = matriz->obterQuantidadeColunas();
	ptMatriz = new int[linha*coluna];
	for(unsigned int i=0; i<linha; i++){//inicio do for_linha
  		int a;
    	for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
  				matriz->obterElementoMatriz(i,j,a);			
  				atribuirElementoMatriz(i,j,a);
    	}//fim do for_coluna
  }//fim do for_linha*/	
  delete matriz;
}

Matriz::~Matriz()
{
	if(ptMatriz) delete[] ptMatriz;
}

bool Matriz::obterElementoMatriz(unsigned int linha, unsigned int coluna, int &elemento)const
{
	if(linha>=quantidadeLinhas || coluna>=quantidadeColunas) return false;
	elemento= *(ptMatriz+(linha*quantidadeColunas+coluna));
	return true;
}

bool Matriz::atribuirElementoMatriz(unsigned int linha, unsigned int coluna, int elemento)
{
	if(linha>=quantidadeLinhas || coluna>=quantidadeColunas) return false;
	*(ptMatriz+(linha*quantidadeColunas+coluna))=elemento;
	return true;
}

void Matriz::operator=(const Matriz * const matriz)
{
	unsigned int linha=0,coluna=0;
		if(!matriz){
			ptMatriz = 0;
			quantidadeLinhas=quantidadeColunas=0;
			return;
		}
		quantidadeLinhas=linha = matriz->obterQuantidadeLinhas();
		quantidadeColunas=coluna = matriz->obterQuantidadeColunas();
		ptMatriz = new int[linha*coluna];
		for(unsigned int i=0; i<linha; i++){//inicio do for_linha
	  		int a;
	    	for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
	  				matriz->obterElementoMatriz(i,j,a);			
	  				atribuirElementoMatriz(i,j,a);
	    	}//fim do for_coluna
	  }//fim do for_linha*/	
	  delete matriz;
}

const Matriz * const Matriz::operator+(Matriz const &matriz)const
{
	unsigned int linhaMatriz,colunaMatriz;
	
	linhaMatriz=matriz.obterQuantidadeLinhas();
	colunaMatriz=matriz.obterQuantidadeColunas();
	
	Matriz *matrizAux = new Matriz(linhaMatriz,colunaMatriz);
	
	for(unsigned int linha=0;linha<linhaMatriz;linha++)
		for(unsigned int coluna=0;coluna<colunaMatriz;coluna++){
			int elementoA,elementoB,elementoC;
			matriz.obterElementoMatriz(linha,coluna,elementoA);
			obterElementoMatriz(linha,coluna,elementoB);
			elementoC=elementoA+elementoB;
			matrizAux->atribuirElementoMatriz(linha,coluna,elementoC);
		}
	return matrizAux;		
}



//REGRAS
/* cada matriz em um arquivo
 * 
 * formato do arquivo:
 *	linha
 * 	coluna
 * 	e[0,0]
 * 	e[0,1]
 * 	.
 * 	.
 * 	.
 * 	e[n,n]
 * 
 * arquivo texto
 *  
 * 
 * 
 */

#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include<iostream>
#include<string>
#include<fstream>
#include"Matriz.h"

using namespace std;

class Persistencia{

private:
	std::string nomeArquivo;
	
public:
   Persistencia(){};
   Persistencia(std::string nomeArq):nomeArquivo(nomeArq){
      fstream arq;
		arq.open(nomeArquivo.c_str(), std::ios::in);
		if(!arq.is_open()) arq.open(nomeArquivo.c_str(), std::ios::out|std::ios::trunc);
		arq.close();		
	}//fim construtor

   ~Persistencia(){};	

   static void atribuirMatrizArquivo(Matriz const &matriz, std::string const nomeDoArquivo);
   static const Matriz * const obterMatrizDoArquivo(std::string const &nomeDoArquivo);
	
};//fim classe

void Persistencia::atribuirMatrizArquivo(Matriz const &matriz, std::string const nomeDoArquivo)
{
/*
 * criar e abrir arquivo para escrita
 * verificar abertura do aquivo
 * obter matriz quantidade linhas
 * obter matriz quantidade de colunas
 * gravar no arquivo linhas - pular linha
 * gravar no qrquivo colunas, - pular linha
 * for linha
 * for coluna 
 * obter elemento
 * gravar no elemento o arquivo -pular linha
 * fechar o arquivo 
 */

	std::ofstream arquivo;
	arquivo.open(nomeDoArquivo.c_str());
	if(!arquivo.is_open()) return; 
	
	unsigned int linhas=matriz.obterQuantidadeLinhas(),
					colunas=matriz.obterQuantidadeColunas();
	//convertendo a linha(int) em uma string
	
	arquivo<<linhas<<endl;
	arquivo<<colunas<<std::endl;
	
	for(int linha=0; linha<linhas; linha++){
		for(int coluna=0; coluna<colunas; coluna++){
			int elemento;
			matriz.obterElementoMatriz(linha, coluna, elemento);
			arquivo<<elemento<<std::endl;
		}//for 2
	}//for 1
	
	arquivo.close();
	return;	
}


/*
 * abrir arquivo para leitura
 * teste de abertura, return false
 * linha = ler linha do arquivo a linha
 * coluna = ler do arquivo a coluna
 * matriz.atribuirLinhas(-)
 * matriz.atribuirColuna(-)
 * construir um metodo dentro da classe matriz pra realocar ou restruturar a matriz, alternativas:
 * 		1 - criar metodo "Realocar", passar como parametro a linha e a coluna
 * 			dentro de Realocar, linha e atrib qtd linha e colunas atrib qtd colunas.
 * 			e deletar a matriz e criar o metodo novamente
 * 		2 - CRIAR UM PONTEIRO PARA A MATRIZ - "devolve" a matriz pelo nome do metodo, com o metodo sendo um ponteiro
 * 			Criar um CONSTRUTOR DE COPIA:"eh coisa simples"....
 * 			Matriz.cpp	
 * 			Matriz(Matriz *matriz){
 * 				linha matriz->obterQuantidadeLinha
 * 				coluna matriz->obterQtdColuna
 * 				ptMatriz = matriz(linha, coluna)
 * 				for 
 * 					for
 * 						matriz->atribuir(linha, coluna)
 * 				
 * 				delete matriz
 * 				}
 * 				
 * 				progranaPrincipal:
 * 					Matriz MA(Persistencia.obterMatrizDoArquivo)...
 *  
 */
const Matriz * const Persistencia::obterMatrizDoArquivo(std::string const &nomeDoArquivo)
{
	
   ifstream arquivoMatriz(nomeDoArquivo.c_str());
	if(!arquivoMatriz.is_open()) return 0;
	unsigned int linha, coluna;
	arquivoMatriz>>linha;
	arquivoMatriz>>coluna;
	//alocacao dinamica de memoria
	//cria uma nova matriz com qtd de linhas e de colunas
	//cria uma area de memoria
	//retorna um endereço de memoria
	//ponteiro de uma classe Matriz
	//criou uma estrutura do tamanho  q queria e retornou ela
	//new a area de memoria fica reservada para vc... ate q vc digite o delete
	std::cout<<"  obter persistencia, linha"<<linha<<", coluna"<<coluna<<std::endl;
   Matriz *matriz = new Matriz(linha,coluna);
	
	
	//ler linha e coluna com 2 for
	//preencher a matriz eemento por elemento
	//area de monte pra fazer alocacao dinamica de memoria
	for(unsigned int i=0; i<linha; i++){
		int a;
		for(unsigned int j=0; j<coluna; j++){
			arquivoMatriz>>a;
			matriz->atribuirElementoMatriz(i, j, a);
		}
	}
	
	arquivoMatriz.close();
	//fechar o arquivo
	//manda o endereço da matriz pra fora;
	return matriz;
	
	
}


#endif /*PERSISTENCIA_H_*/

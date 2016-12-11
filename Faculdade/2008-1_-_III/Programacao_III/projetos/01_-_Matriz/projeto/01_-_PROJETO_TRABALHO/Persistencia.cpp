#include<iostream>

#include"Persistencia.h"
#include"Matriz.h"

Persistencia::Persistencia(std::string const &nomeArquivo)
{
   std::fstream arq;
   arq.open(nomeArquivo.c_str(), std::ios::in);
	if(!arq.is_open()) arq.open(nomeArquivo.c_str(), std::ios::out|std::ios::trunc);
	arq.close();	
}//fim do construtor 

//*****************************************************************************/* 14 */
void Persistencia::atribuirMatrizArquivo(Matriz const &matriz,
                      std::string const nomeDoArquivo)
{//inicio
   //instanciando um objeto para escrita
   std::ofstream arquivo;
   
   //abrindo um arquivo para escrita   
   arquivo.open(nomeDoArquivo.c_str());                   
   //verificando a abertura
   if(!arquivo.is_open()) return; 
   
   //criando variavel para enviar os dados para dentro do arquivo
   int linhaArq;
   
   //obtendo os dados e escrevendo no arquivo
   linhaArq = matriz.obterQuantidadeLinhas();
   arquivo<<linhaArq<<std::endl;
   
   linhaArq = matriz.obterQuantidadeColunas();
   arquivo<<linhaArq<<std::endl;
   
   //Qual fica mais rapido? declarando variaveis pro obterQtd ou chama-lo diretamente?
   for(unsigned int linha=0; linha<matriz.obterQuantidadeLinhas(); linha++){
      for(unsigned int coluna=0; coluna<matriz.obterQuantidadeColunas(); coluna++){
         matriz.obterElementoMatriz(linha, coluna, linhaArq);
         arquivo<<linhaArq<<std::endl;
      }//fim for 2             
   }//fim for 1
   
   arquivo.close();
   return;                      
}//fim do metodo atribuir

//*****************************************************************************/* 14 */
const Matriz * const Persistencia::obterMatrizDoArquivo(std::string const 
                                       &nomeDoArquivo)
{//inicio
   //instanciando um objeto para leitura e abrindo-o
   std::ifstream arquivoMatriz(nomeDoArquivo.c_str());
	//verificando se foi aberto
   if(!arquivoMatriz.is_open()) return 0;
	
   unsigned int linha, coluna;
	//lendo os valores do arquivo
   arquivoMatriz>>linha;
	arquivoMatriz>>coluna;
	//std::cout<<"  obter persistencia, linha"<<linha<<", coluna"<<coluna<<std::endl;
   //instanciando um objeto para a criacao
   Matriz *matriz = new Matriz(linha,coluna);
	
	
	//ler linha e coluna com 2 for
	//preencher a matriz eemento por elemento
	//area de monte pra fazer alocacao dinamica de memoria
	for(unsigned int i=0; i<linha; i++){
		int a;
		for(unsigned int j=0; j<coluna; j++){
			arquivoMatriz>>a;
			matriz->atribuirElementoMatriz(i, j, a);
		}//fim for 2
	}//fim for 1
	
	arquivoMatriz.close();
	//fechar o arquivo
	//manda o endereço da matriz pra "fora";
	return matriz;	
}//fim metodo obter


//*****************************************************************************/* 14 */
bool Persistencia::apagarArquivo(std::string &nomeArquivo)
{
     
     //verificando se o arquivo existe
     std::ifstream arquivo;
     arquivo.open(nomeArquivo.c_str());
     if(!arquivo.is_open()) return false;
     
     std::remove("nomeArquivo");
     return true; 
     
}

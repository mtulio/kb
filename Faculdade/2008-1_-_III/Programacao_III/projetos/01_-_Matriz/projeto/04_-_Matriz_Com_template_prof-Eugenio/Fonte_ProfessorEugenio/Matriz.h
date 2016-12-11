#ifndef MATRIZ_H_
#define MATRIZ_H_

#include<string>
template <class tipo>
class Matriz
{
	private:
		unsigned int quantidadeLinhas;
		unsigned int quantidadeColunas;
		tipo *ptMatriz;
	public:
		Matriz(unsigned int quantidadeLinhas=0, unsigned int quantidadeColunas=0);
		~Matriz(){if(ptMatriz) delete[] ptMatriz;}
		unsigned int obterQuantidadeLinhas()const {return quantidadeLinhas;};
		unsigned int obterQuantidadeColunas()const{return quantidadeColunas;};
		
		tipo obterElementoMatriz(unsigned int linha, unsigned int coluna)const{
			if(linha>=quantidadeLinhas || coluna>=quantidadeColunas)
					throw (std::string("Indice de linha ou coluna fora do intervalo valido"));
				tipo elemento= *(ptMatriz+(linha*quantidadeColunas+coluna));
				return elemento;
		}
		
		void atribuirElementoMatriz(unsigned int linha, unsigned int coluna, tipo elemento){
			if(linha>=quantidadeLinhas || coluna>=quantidadeColunas)
					throw (std::string("Indice de linha ou coluna fora do intervalo valido"));
				*(ptMatriz+(linha*quantidadeColunas+coluna))=elemento;
		}
		
//		void operator=(const Matriz * const matriz);
//		const Matriz * const operator+(Matriz const &matriz)const;
//		const Matriz * const operator-(Matriz const &matriz)const;
//		const Matriz * const eTransposta()const;
//		Matriz(const Matriz * const matriz);
};

template < class tipo>
Matriz<tipo>::Matriz(unsigned int quantidadeLinhas, unsigned int quantidadeColunas):
	quantidadeLinhas(quantidadeLinhas),
	quantidadeColunas(quantidadeColunas)
{
	if(quantidadeLinhas==0 || quantidadeColunas==0){
		ptMatriz=0; return;
	}
	ptMatriz = new  tipo[quantidadeLinhas*quantidadeColunas];
	if(!ptMatriz) throw (std::string ("Matriz nao pode ser alocada. Falta Memoria Livre"));
}

#endif /*MATRIZ_H_*/

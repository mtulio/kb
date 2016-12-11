#ifndef MATRIZ_H_
#define MATRIZ_H_

class Matriz
{
   private:
		unsigned int quantidadeLinhas;
		unsigned int quantidadeColunas;
		int *ptMatriz;
	public:
        //construtor e destrutor
		Matriz(unsigned int quantidadeLinhas, unsigned int quantidadeColunas);
		//construtor de copia
		Matriz(const Matriz * const matriz);
		~Matriz();
		
		//metodos basicos
		unsigned int obterQuantidadeLinhas()const {return quantidadeLinhas;};
		unsigned int obterQuantidadeColunas()const{return quantidadeColunas;};
		
		bool obterElementoMatriz(unsigned int linha, unsigned int coluna,int &elemento)const;
		bool atribuirElementoMatriz(unsigned int linha, unsigned int coluna,int elemento);
      
		//Calculos
		bool adicao(Matriz const &matA, Matriz const &matB);  /* 01 */
		bool subtracao(Matriz const &matA, Matriz const &matB); /* 02 */
		bool multiplicacao(Matriz const &matA, Matriz const &matB); /* 03 */		
		bool triangularSuperior()const; /* 04 */
		bool triangularInferior()const; /* 05 */
		bool simetrica()const; /* 06 */
		bool antiSimetrica()const; /* 07 */
		bool identidade()const; /* 08 */
		void resultanteDaTransposta(Matriz const &matriz); /* 09 */
		bool resultanteDaPotencia(Matriz const &matriz, int expoente); /* 10 */
		bool multiplicacaoPorK(Matriz const &matA, int k); /* 11 */
		bool igual(Matriz const &matriz)const; /* 12 */
		bool diferente(Matriz const &matriz)const; /* 13 */
		bool ortogonal()const;  /* 14 */
		bool permutacao()const; /* 15 */
      
};//fim classe Matriz

#endif /*MATRIZ_H_*/

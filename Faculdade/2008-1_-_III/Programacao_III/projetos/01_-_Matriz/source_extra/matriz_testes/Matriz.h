#ifndef MATRIZ_H_
#define MATRIZ_H_

class Matriz
{
   private:
		unsigned int quantidadeLinhas;
		unsigned int quantidadeColunas;
		int *ptMatriz;
	public:
		Matriz(unsigned int quantidadeLinhas, unsigned int quantidadeColunas);
		Matriz(const Matriz * const matriz);
		~Matriz();
		//o metodo realocar nao esta funcionando
      void realocar(unsigned int linha, unsigned int coluna);
		
		unsigned int obterQuantidadeLinhas()const {return quantidadeLinhas;};
		unsigned int obterQuantidadeColunas()const{return quantidadeColunas;};
		bool obterElementoMatriz(unsigned int linha, unsigned int coluna, int &elemento)const;
		bool atribuirElementoMatriz(unsigned int linha, unsigned int coluna, int elemento);
		//***********************************************************
		//Apresenta��o dia 04/03
      bool adicao(Matriz &matA, Matriz &matB);  /* 01 */
		bool triangularSuperior(); /* 04 */
      void resultanteDaTransposta(Matriz &matriz); /* 09 */
      bool igual(Matriz &matriz); /* 12 */
        //***********************************************************
        
      bool subtracao(Matriz &matA, Matriz &matB); /* 02 */
		bool multiplicacao(Matriz &matA, Matriz &matB); /* 03 */		
		bool triangularInferior(); /* 05 */
		bool simetrica(); /* 06 */
		bool antiSimetrica(); /* 07 */
		bool identidade(); /* 08 */
		bool resultanteDaPotencia(Matriz &matriz, int expoente); /* 10 */
		bool multiplicacaoPorK(Matriz &matA, int k); /* 11 */
		bool diferente(Matriz &matriz); /* 13 */
		bool ortogonal(); /* 14 */
		bool permutacao(); /* 15 */
};

#endif /*MATRIZ_H_*/

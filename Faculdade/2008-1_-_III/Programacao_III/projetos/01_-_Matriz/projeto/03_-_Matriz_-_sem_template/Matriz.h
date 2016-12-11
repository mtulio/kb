#ifndef MATRIZ_H_
#define MATRIZ_H_
class Matriz
{
	private:
		unsigned int quantidadeLinhas;
		unsigned int quantidadeColunas;
		int *ptMatriz;
	public:
		Matriz(unsigned int quantidadeLinhas=0, unsigned int quantidadeColunas=0);
		Matriz(const Matriz * const matriz);
		~Matriz();
		unsigned int obterQuantidadeLinhas()const {return quantidadeLinhas;};
		unsigned int obterQuantidadeColunas()const{return quantidadeColunas;};
		int obterElementoMatriz(unsigned int linha, unsigned int coluna)const;
		void atribuirElementoMatriz(unsigned int linha, unsigned int coluna, int elemento);
		
		//sobrecarga de operador
		void operator=(const Matriz * const matriz);
		const Matriz * const operator+(Matriz const &matriz)const;
		const Matriz * const operator-(Matriz const &matriz)const;
		const Matriz * const operator*(Matriz const &matriz)const;
		bool operator==(Matriz const &matriz)const;
		bool operator!=(Matriz const &matriz)const;
		
		//metodos que nao usam sobrecarga d operador
		//metodos com procedimentos/verificacao
		bool eTriangularSuperior()const; /* 04 */
		bool eTriangularInferior()const; /* 05 */
		bool eSimetrica()const;
		bool eAntiSimetrica()const;
		bool eIdentidade()const; /* 08 */
		bool eOrtogonal()const;  /* 14 */
		bool eDePermutacao()const; /* 15 */
		
		//metodos com procedimentos/calculos
		const Matriz * eResultanteDaTransposta()const; /* 09 */
		const Matriz * eResultanteDaPotencia(int expoente)const; /* 10 */
		const Matriz * eResultanteMultiplicacaoPorK(int k); /* 11 */		
};

#endif /*MATRIZ_H_*/


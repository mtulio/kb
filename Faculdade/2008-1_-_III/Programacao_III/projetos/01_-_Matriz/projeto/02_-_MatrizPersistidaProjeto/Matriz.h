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
		bool obterElementoMatriz(unsigned int linha, unsigned int coluna, int &elemento)const;
		bool atribuirElementoMatriz(unsigned int linha, unsigned int coluna, int elemento);
		void operator=(const Matriz * const matriz);
		const Matriz * const operator+(Matriz const &matriz)const;
		//static const Matriz * const operator-(Matriz const &matriz)const;
};

#endif /*MATRIZ_H_*/

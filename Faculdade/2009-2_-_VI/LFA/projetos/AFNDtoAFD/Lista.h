/*
 * Lista.h
 *
 *  Created on: 12/10/2009
 *      Author: marco
 */

#ifndef LISTA_H_
#define LISTA_H_

#include<string>

class Lista
{
public:
	unsigned int qtdMaxTransicoes;
	unsigned int contador;//defini em qual posicao ele está, para alocar mais facilmente o objeto no vetor
	//pode ter de 0 a n transicoes
	//onde n é a quantidade de estados
	//ex.: transicoes[0]=q0, transicoes[1]=q1...

	//aqui vai utilizar a quantidade maxima de transicoes
	//e alocar um vetor com a qtd maxima
	string transicoes[];

	Lista();
	~Lista();
};

Lista::Lista(unsigned int qtdMaximaTransicoes):
		contador(0),
		qtdMaximaTransicoes(qtdMaximaTransicoes)
		{
				transicoes = new string[qtdMaximaTransicoes];
		}

Lista::~Lista()
{
	if(transicoes) delete[] transicoes;
}//fim destrutor



#endif /* LISTA_H_ */

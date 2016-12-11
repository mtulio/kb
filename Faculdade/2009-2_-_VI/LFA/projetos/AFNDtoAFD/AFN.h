/*
 * AFN.h
 *
 *  Created on: 12/10/2009
 *      Author: marco
 */

#ifndef AFN_H_
#define AFN_H_

#include"Estado.h"

class AFN
{
private:
	//vetor de estados da afn
	unsigned int qtdEstados;
	Estado automato[];
	unsigned int contador;
	//informacoes sobre os estados
	string alfabeto;
	unsigned int qtdAlfabeto;
public:
	AFN();
	~AFN();

	void atribuirEstado(string nomeEstado);

};

AFN::AFN(unsigned int qtdEstados, string alfabeto):
		qtdEstados(qtdEstados),
		alfabeto(alfabeto),
		contador(0)
{
	automato = new Estado[qtdEstados]();
	//int i;
	//for(i=0; qtdEstados[i] != '0' ;i++);
	//qtdAlfabeto=i;
	qtdAlfabeto = alfabeto.lenght;
}//fim construtor

void atribuirEstado(string nomeEstado)
{
	Estado *temp = new Estado(nomeEstado, alfabeto, qtdEstados);
	automato[contador]=tmep;
	contador++;
}//fim

void atribuirTransicao(string estado, string transicao)
{
	int local=0;
	for(int i=0; i<contador; i++){
		string strtmp=automato[i].obterNome();
		if(strtmp==estado) local=i;
	}//fim for
	if(local==0) return; // n encontrou nenhum objeto com o nome informado
	else
		automato[local].definirTransicao(estado,transicao);
	return;
}//fim

#endif /* AFN_H_ */

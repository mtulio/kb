/*
 * Estado.h
 *
 *  Created on: 12/10/2009
 *      Author: marco
 */

#ifndef ESTADO_H_
#define ESTADO_H_

#include<string>
#include"Lista.h"

//Esta classe abstrai um estado e suas propriedades
class Estado
{
private:
	string nome;
	string alfabeto;
	unsigned int tamanhoALfabeto;
	unsigned int nroEstados;

	//Lista de cada letra disponivel no alfabeto
	//Ex.: transicao[alf1].transicoes[t1]=q1, onde alf1 é a primeira letra
	//do alfabeto e t1 é a primeira transicao
	//transicao[0].transicoes[0]=q1, significa se o objeto atual for q0,
	//e a 1a letra do alfabeto for 1: (q0,0)=q1 p/ alf=0 e t=0
	// (q0,0)=q0 p/alf=0 e t=1 > transicao[alf1].transicoes[t1+1]=q0

	//quantidade maxima de transicao é a qtd de estados * vezes a qtd de alfabetos
	Lista transicao[];
public:
	Estado(){};
	Estado(string nome, string alfabeto,unsigned int nroEstados);

	string obterTransicao(string simbolo);
	void definirTransicao(string simbolo, string nomeProximoEstado);

	string obterNome() {return this->nome; }

};

Estado::Estado(string nome,string alfabeto,unsigned int nroEstados):
		nome(nome),
		alfabeto(alfabeto),
		nroEstados(nroEstados)
		{
			//descobrindo o tamanho percorrendo a palavra
			int i;
			for(i=0;alfabeto[i] != '0' ;i++);
			tamanhoALfabeto=i;

			//definindo a quantidade maxima de transicoes
			//qtd maxima de transicoes por letra do alfabeto é o numero do estado
			//qtdMaxTransicoes=numeroEstados
			transicao = Lista(nroEstados)[tamanhoALfabeto];
			//preenchendo a transicao com a qtd de letras do alfabeto

			for(int temp=0; temp<tamanhoALfabeto; temp++){
				//ex.: p/ alfabeto{abc} e estado atual=q0
				//q0[0]=a, q0[1]=b, q0[2]=c
				transicao[temp]=alfabeto[temp];
			}//fim for
		}//fim construtor

Estado::~Estado()
{
	if(transicao) delete[] transicao;
}//fim destrutor

//##################################################
//definindo para quais transicoes uma certa letra do alfabeto vai 'percorrer'
//ex: (q0,0)=q1 ou seja: transicao[x].transicoes[y]=q1
void Estado::definirTransicao(string simbolo, string nomeProximoEstado)
{
	//descobrindo a posicao do simbolo na palavra
	int i, temp;
	for(temp=0,i; i<tamanhoAlfabeto; i++)
	{
		if(simbolo[0]==alfabeto[i]) temp=i;
	}//fim for

	//alocando o nome do proximo estador no vetor
	transicao[i].transicoes[transicao.contador]=nomeProximoEstado;
	transicao.contador+=1;

}//fim

string Estado::obterTransicao(string simbolo)
{
	int i, temp;
 	for(temp=0,i; i<tamanhoAlfabeto; i++)
 	{
 		if(simbolo[0]==alfabeto[i]) temp=i;
 	}//fim for

 	//retornando o vetor(lista) deposicoes da transicao do estado
	return transicao[i].transicoes;
}//fim obter
#endif /* ESTADO_H_ */

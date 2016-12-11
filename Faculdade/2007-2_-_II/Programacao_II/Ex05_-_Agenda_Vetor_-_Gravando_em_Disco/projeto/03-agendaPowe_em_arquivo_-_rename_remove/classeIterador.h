/*
  Name: MARCO TULIO RODRIGUES BRAGA
  Copyright: UNIVERSIDADE CATOLICA DE GOIAS - PROGRAMACAO II
  Author: BRANCOTULIO & CIA
  Description: PROGRAMA DE AGENDA
*/
#ifndef CLASSEITERADOR_H_
#define CLASSEITERADOR_H_
#include"classePessoa.h"
#include<iostream>
#include<string>
//***************************************************
//  Esta classe tem como responsabilidade armazenar uma "copia" da agenda
// e iteragir com ela atraves de funcoes como proximo, anterior, inicio, estavazio, fim..
//  seria apenas um correio que trasporta informacoes entre as classes
// pode-se perceber esse tal transporte na classe controle...q ele apenas "liga" 
//  a persistencia com a interface
//***************************************************
//tem como objetico "transportar" objetos de uma classe para outra
//Iterador é um vetor de objetos da classe pessoa
class Iterator
{// inicio classe Iterator

	private:
		const unsigned int tamanho;
		const unsigned int indiceUso;
		unsigned int posicao;
		
		Pessoa *conjunto;
		
	public:
		Iterator(Pessoa *conjunto, int tamanho, int indiceUso);
		~Iterator();
		bool estaVazio()const;//
		bool proximo();//
		bool anterior();//
		void inicio(){posicao=0;};//ir para o inicio do vetor
        void fim(){posicao=indiceUso-1;};//
		const Pessoa& obter()const;
		
};// fim classe Iterator

Iterator::Iterator(Pessoa *conjunto, int tamanho, int indiceUso):
				tamanho(tamanho),
				indiceUso(indiceUso),
				posicao(0)
{
	this->conjunto = conjunto;//guardando o objeto de que entrou como para,etro no atributo
}

Iterator::~Iterator()
{
	if(conjunto) delete[] conjunto;
}

bool Iterator::estaVazio()const
{
	return !static_cast<bool>(indiceUso);
}

bool Iterator::proximo()
{
	if(posicao<indiceUso-1){
		posicao++;
		return true;
	}else return false;
}

bool Iterator::anterior()
{
	if(posicao>0){
		posicao--;
		return true;
	}else return false;
}

const Pessoa&  Iterator::obter()const
{   
    //std::cout<<"     Iterador  >> Obter ok ok    tamanho"<<tamanho<<" posicao "<<posicao<<std::endl;//teste
    return(conjunto[posicao]);//retornando um objeto na posição informada
}

#endif /*CLASSEITERADOR_H_*/

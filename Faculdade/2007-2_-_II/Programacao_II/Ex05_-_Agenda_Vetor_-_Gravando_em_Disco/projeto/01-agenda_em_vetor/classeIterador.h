#ifndef CLASSEITERADOR_H_
#define CLASSEITERADOR_H_
#include"classePessoa.h"
#include<iostream>
#include<string>
/*tem como função 
1 - ele apenas sera usado na listagem geral ou por letra
2 - tem como função caminhar, verificar...
tem quaze as mesmas funcoes da persistencia, pois dentro desta 
tem uma copia da agenda q foi entrada como parametro do construtor 
TIPO UMA PERSISTENCIA
VTC

/*/
class Iterator
{// inicio classe Iterator
//atributos " tamanho, inidiceUso, posiçao e um objeto/ponteiro instaciado da classe Pessoa...
	private:
		const unsigned int tamanho;
		const unsigned int indiceUso;
		unsigned int posicao;
		Pessoa *conjunto;
		
	public:
		Iterator(Pessoa *conjunto, int tamanho, int indiceUso); //construtor com parametros...
		~Iterator();//destrutor
		bool estaVazio()const;//
		bool proximo();//
		bool anterior();//
		void inicio(){posicao=0;};//tem como objetivo ir para o inicio do vetor
		void fim(){posicao=indiceUso-1;};// vai para o fim do arquivo 
		const Pessoa  &obter()const;
		
};// fim classe Iterator

//**************************************************************************************

Iterator::Iterator(Pessoa *conjunto, int tamanho, int indiceUso):
				tamanho(tamanho),//inicializara o tamanho com o tamanho da persistencia informado por parametro
				indiceUso(indiceUso),//inicializara o indice uso com o indice de uso informado e usado na classe persistencia
				posicao(0)//
				//conjunto(conjunto); ?????
				
				//dando valores iniciais aos meus atributos...
{//inicio do bloco de comandos do construtor
	this->conjunto = conjunto;// o atributo conjunto esta recebendo o objeto conjunto da classe Pessoa...
}//************************************************************************************
Iterator::~Iterator()//destrutor
{//inicio do bloco de comandos do iterador
	if(conjunto) delete[] conjunto;//verifica se o vetor apontado existe
	// se existir ele deletara librando mais espaço na memoria do computador
}//fim do bloco de comandos do interador
//************************************************************************************


//************************************************************************************
bool Iterator::estaVazio()const
//essa funcao apenas sera verdadeira se o indice de uso for 0
{
	return static_cast<bool>(!indiceUso);
	//static_cast converte de int pra bool xD~
    //apenas qdo o indice de uso for 0 ele converterá para 1 
    //e tornara bool atraves do comando static cas t e retornara 1(V)
    // para o metodo esta vazio
}
//**************************************************************************************

//********************************************************************************************
bool Iterator::proximo()
//tem como funcao "verificar" se n xegou no fim do vetor, se existe uma proxima posiçao
{
	if(posicao<indiceUso-1){//esse if eh mto doente
		posicao++;//incrementa mais uma na posicao, pula pra proxima prosicao
		return true;// se retornar verdadeiro e porque ele pulo pra proxima posiçao
	}else return false;
}
//***********************************************************************************************


bool Iterator::anterior()//tem como funcao voltar para a posicao anterior
{
	if(posicao>0){//duente #$@@#@#
		posicao--;
		return true;
	}else return false;
}
//**************************************************************************************************
const Pessoa&  Iterator::obter()const
{
	return(conjunto[posicao]);
}
//pegar o objeto na posiçao tal da copia da agenda e retornar...
//***************************************************************************************************

#endif /*CLASSEITERADOR_H_*/

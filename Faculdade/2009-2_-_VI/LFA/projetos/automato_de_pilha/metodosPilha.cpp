#include "classe_pilha.h"
using namespace std;
//contrutor
Pilha::Pilha(unsigned int tam):
	tamanho(tam),
	topo(0)
{
	vetor = new string[tamanho];
	for(int i=0;i<tamanho;i++){
		vetor[i] = "-1";
	}
}
//destrutor
Pilha::~Pilha(){
	delete[] vetor;
}

//metodo obter tamanho
 int Pilha::obterTamanho(){
	return tamanho;
};

//retorno de pilha vazia
bool Pilha::pilhaVazia(){
	return topo == 0;
};


//funcao push

bool Pilha::push(string elemento){
	if(topo==tamanho)return false;
	vetor[topo++] = elemento;
	return true;
}

//funcao pop
bool Pilha::pop(string &elemento,bool testaChar){
	if(topo==0)return false;
	if(testaChar){
		if(elemento == vetor[topo-1]){
			elemento = vetor[--topo];
			return true;
		}else{
			return false;
		}
	}else{
		elemento = vetor[--topo];
		return true;
	}
}

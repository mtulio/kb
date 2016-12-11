#include "classe_automato.h"
#include "classe_pilha.h"
#include "classe_fita.h"
using namespace std;
//construtor da classe
Automato::Automato(string tab[][5]):
	qtd_estado(0)
{
	while(tab[qtd_estado][0]!=""){
		qtd_estado++;
	}
	tabela = new string[qtd_estado*5];
	for(int i=0;i<qtd_estado;i++){
		for(int j=0;j<5;j++){
			*(tabela + i*5+j) = tab[i][j];
		}
	}
}

//destrutor da classe
Automato::~Automato(){
	delete[] tabela;
}
bool Automato::validar_sentenca(Fita fita){
	Pilha pilha(fita.tamanho()*2);
	string transicao[5];
	string estado="0",leitura_da_fita="",lerPilha="-1";
	while(!fita.final()){
		leitura_da_fita = fita.leitura_da_fita();
		if(lerPilha!="-1"&&pilha.pop(lerPilha,true)){
			
		}
		this->busca(estado,leitura_da_fita,transicao);
		lerPilha = transicao[2];
		estado   = transicao[3];
		if(transicao[4]!="-1")pilha.push(transicao[4]);		
	}
	return pilha.pilhaVazia();
}

//metodo setar
bool Automato::seta(unsigned int linha,unsigned int coluna,string elemento){
	if(linha>=qtd_estado||coluna>=5)return false;
	*(tabela + linha*5+coluna) = elemento;
	return true;
}

//metodo obter sentenca
bool Automato::obter(unsigned int linha,unsigned int coluna,string &elemento){
	if(linha>=qtd_estado||coluna>=5)return false;
	elemento = *(tabela + linha*5+coluna);
	return true;
}

//metodo buscar sentenca
bool Automato::busca(string estado,string fita,string linha[5]){
	for(int i=0;i<qtd_estado;i++){
		string estadoChave,leituraFita;
		obter(i,0,estadoChave);
		obter(i,1,leituraFita); 
		if(estadoChave==estado&&leituraFita==fita){
			for(int j=0;j<5;j++){
				string str;
				obter(i,j,str);
				linha[j] = str;
			}
			return true;
		}
	}
	return false;
}

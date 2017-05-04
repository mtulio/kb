#include "classe_fita.h"
using namespace std;
//construtor
Fita::Fita(string cadeia):
	vetor(cadeia),
	inicio(0)	
{
}
//destrutor
Fita::~Fita(){}

//metodo ler fita
char Fita::leitura_da_fita(){
	return vetor[inicio++];
}
//metodo pegar tamanho
 int Fita::tamanho(){
	return vetor.size();
}
//final
bool Fita::final(){
	return inicio==vetor.size();
}


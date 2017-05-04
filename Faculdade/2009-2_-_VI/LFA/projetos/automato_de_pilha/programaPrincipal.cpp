#include "classe_pilha.h"
#include "classe_fita.h"
#include "classe_automato.h"
#include <iostream>
using namespace std;

/*
* Linguagen de formais e automatos
* Automato com Pilha	
* Marco Tulio Rodrigues Braga
* Juliane Barbosa Maximo
*/

int main(void)
{
	//valor fixo da tabela
	string matriz[][5] = {{"0","a","-1","0","B"},{"0","b","B","1","-1"},{"1","b","B","1","-1"},{"","","","",""}};
	Automato automato(matriz);
	Fita fita("aabb"); //entrada pre definida
	if(automato.validar_sentenca(fita)) cout<<" Sentenca invalida \n";
	else{ cout<<" Sentenca valida \n";}

	exit(1);	
}//fim do programa principal

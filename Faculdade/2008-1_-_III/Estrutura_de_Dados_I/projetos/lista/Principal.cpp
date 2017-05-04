#include<iostream>
//#include<string>
//#include<iomanip>

#include"Interface.h"
#include"ListaDeDisciplinas.h"


int main (void){
	
	ListaDeDisciplinas *lista = new ListaDeDisciplinas();
	Interface::menuManterListaDeDisciplinas(lista);	
	
	//quando o programa chega na ultima chave do main, sera chamado
	//o destrutor da classe ListaDeDisciplinas
}

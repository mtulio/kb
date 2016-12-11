// PRODUCT BY ANDRE
#include "Cliente.h"
using namespace std;

std::string Cliente::desmaterializar()const { //inicio do metodo desmaterializar
	std::string linha;
	std::string idString;
	int aux;
	for(aux=identificador; aux;) {
		char letra;
		letra = (aux%10)+48;
		idString = letra+idString;
		aux=aux/10;
	}
	linha=idString;
	linha+=";";
	linha+=nome;
	linha+=";";
	
	std::string telefoneString;
	for(unsigned long aux = telefone; aux;) {
		char letra;
		letra = (aux%10)+48;
		telefoneString = letra + telefoneString;
		aux = aux/10;
	}
	linha+=telefoneString;
	linha+=";";
	
	return linha;
}//fim do metodo desmaterializar


void Cliente::materializar(const std::string linha) { //inicio do metodo materialiar
	
	int aux=0;
	int pos=0;
	for(;linha[pos]!=';';pos++) {
		aux=aux*10+(linha[pos]-48);
	}
		identificador=aux;
		
		std::string stringAux="";
		for(pos++; linha[pos]!=';';pos++) {
			stringAux+=linha[pos];
		}
			nome=stringAux;
		
		
		long aux2=0;
		for(pos++;linha[pos]!=';';pos++) {
			aux2=aux*10+(linha[pos]-48);
		}
			telefone=aux2;
		
			
			stringAux="";
			
			for(pos++;linha[pos]!=';';pos++) {
				stringAux+=linha[pos];
			}
				
}// FIM MATERIALIZAR
			
		
	

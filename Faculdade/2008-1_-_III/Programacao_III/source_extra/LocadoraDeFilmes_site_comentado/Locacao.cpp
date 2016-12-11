#include "Locacao.h"
// Classe testada em C++ e modela no Jude
std::string Locacao::desmaterializar()const
{// inicio desmaterializar
	std::string linha;
	std::string idString;
	for(int aux=identificador;aux;){
		char letra= (aux%10)+48;
		idString=letra+idString;
		aux=aux/10;
	}
	linha=idString;
	linha +=";";
	idString="";
	for(int aux=idCliente;aux;){
		char letra= (aux%10)+48;
		idString=letra+idString;
		aux=aux/10;
	}
	linha+=idString;
	linha +=";";
	idString="";
	for(int aux=idFilme;aux;){
		char letra= (aux%10)+48;
		idString=letra+idString;
		aux=aux/10;
	}
	linha+=idString;
	linha +=";";
	idString="";
	for(int aux=valorDeCompra;aux;){
		char letra= (aux%10)+48;
		idString=letra+idString;
		aux=aux/10;
	}
	linha+=idString;	
	linha +=";";
	if(situacao) linha+="1";
			else linha+="0";
	linha+=";";
	return linha;
}// fim desmaterializar

void Locacao::materializar(const std::string cdc)
{// inicio materializar
	int aux=0;
	int pos=0;
	for(;cdc[pos]!=';';pos++) aux=aux*10+(cdc[pos]-48);
	identificador=aux;
	aux=0;
	for(pos++;cdc[pos]!=';';pos++) aux=aux*10+(cdc[pos]-48);
	idCliente=aux;
	aux=0;
	for(pos++;cdc[pos]!=';';pos++) aux=aux*10+(cdc[pos]-48);
	idFilme=aux;
	aux=0;
	for(pos++;cdc[pos]!=';';pos++) aux=aux*10+(cdc[pos]-48);	
	valorDeCompra=aux;
	pos++;
	if((cdc[pos]-48)==0) situacao = false;
		else situacao=true;
}// fim materializar


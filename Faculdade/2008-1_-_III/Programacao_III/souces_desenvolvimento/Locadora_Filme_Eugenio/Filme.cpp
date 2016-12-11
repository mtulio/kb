#include "Filme.h"
#include<string>
// Classe testada em C++ e modela no Jude
std::string Filme::desmaterializar()const
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
	linha+=titulo;
	linha+=";";
	std::string valorString;
	for(long aux=valorDeCompra;aux;){
		char letra= (aux%10)+48;
		valorString=letra+valorString;
		aux=aux/10;
	}
	linha+=valorString;
	linha+=";";
	if(situacao) linha+="1";
		else linha+="0";
	linha+=";";
	return linha;
}// fim desmaterializar


void Filme::materializar(const std::string cdc)
{// inicio materializar
	int aux=0;
	int pos=0;
	for(;cdc[pos]!=';';pos++) aux=aux*10+(cdc[pos]-48);
	identificador=aux;
	std::string strAux="";
	for(pos++;cdc[pos]!=';';pos++) strAux+=cdc[pos];
	titulo=strAux;
	int aux2=0;
	for(pos++;cdc[pos]!=';';pos++) aux2=aux2*10+(cdc[pos]-48);
	valorDeCompra=aux2;
	pos++;
	if((cdc[pos]-48)==0) situacao = false;
		else situacao=true;
}// fim materializar



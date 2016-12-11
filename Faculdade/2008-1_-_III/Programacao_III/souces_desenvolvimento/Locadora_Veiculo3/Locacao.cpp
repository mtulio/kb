#include"Locacao.h"

using namespace std;

void Locacao::materializar(string linha)
{
	try{
		
		int auxInt=0, pos=0;
	
		//mate construtor
		for( ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48);
		identificador = auxInt;
		
		// idCliente
		auxInt=0;
		for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48);
		idCliente = auxInt;
		
		// idVeiculo
		auxInt = 0;
		for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48);
		idVeiculo = auxInt;
		
		// kmInicial
		auxInt = 0;
		for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48);
		kmInicial = auxInt;
		
		// kmFinal
		auxInt=0;
		for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48);
		kmFinal = auxInt;
		
		// valor pago
		auxInt = 0;
		for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48);
		kmFinal = auxInt;
		
		// situacao
		int auxBool;
		for(pos++ ; linha[pos]!=';' ; pos++) auxBool = auxBool*10 + (linha[pos]-48);
		if(auxBool == 1) situacao = true;
		else situacao = false;
	
	}//fim try
	catch(string msg){
		throw msg;		
	}//fim catch
	
}// fim materializar

string Locacao::desmaterializar()const
{
	try{
		string linha, auxString;
		
		// identificador
		for(int aux = identificador; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha = auxString;
		linha+=";";
		
		// idCliente
		for(int aux = idCliente; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		// idVeiculo
		for(int aux = idVeiculo; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		//kmInicial
		for(int aux = kmInicial; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		//kmFinal
		for(int aux = kmFinal; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		//valorPago
		for(int aux = valorPago; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
	
		// situacao
		if(situacao==true) linha += "1";
		else linha += "0";
		
		linha += ";";
		
		return linha;	
	}//fim try
	catch(string msg){
		throw msg;		
	}//fim catch	
}//fim desmaterializar

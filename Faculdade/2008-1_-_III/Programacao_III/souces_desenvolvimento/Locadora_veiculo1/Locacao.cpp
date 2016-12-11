#include"Locacao.h"

using namespace std;

void Locacao::materializar(const string &linha)
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
		
		//valor por km
		auxInt = 0;
		for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48);
		valorPorKm = auxInt;
		
		// valor pago
		auxInt = 0;
		for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48);
		valorPago = auxInt;
		
			
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
		auxString = "";
		for(int aux = idCliente; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		// idVeiculo
		auxString = "";
		for(int aux = idVeiculo; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		//kmInicial
		auxString = "";
		for(int aux = kmInicial; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		//kmFinal
		auxString = "";
		for(int aux = kmFinal; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		//valor Por km
		auxString = "";
		for(int aux = valorPorKm; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
		
		//valorPago
		auxString = "";
		for(int aux = valorPago; aux ; ){
			char letra = (aux%10)+48;
			auxString = letra + auxString;
			aux = aux/10;
		}//fim for
		linha += auxString;
		linha += ";";
	
		return linha;	
	}//fim try
	catch(string msg){
		throw msg;		
	}//fim catch	
}//fim desmaterializar

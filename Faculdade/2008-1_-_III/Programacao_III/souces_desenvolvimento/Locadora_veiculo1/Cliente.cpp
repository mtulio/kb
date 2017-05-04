#include"Cliente.h"
using namespace std;

void Cliente::materializar(const std::string &linha)
{
	std::string auxString="";
	int auxInt=0, pos=0;
	//std::cout<<" aki"<<linha<<" ..."<<std::endl;
	// MATERIALIZANDO O IDENTIFICADOR
	//fazendo o metodo de conversao para a tabela ASCII
	for(;linha[pos]!=';' ; pos++) auxInt = auxInt*10 + (linha[pos]-48) ;
	identificador = auxInt;
	
	//std::string auxStr2="";
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxString += linha[pos];
	nome = auxString;
	
	//string auxStr2="";
	auxString = "";
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxString += linha[pos];
	endereco = auxString;
	
	long auxLong=0;
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxLong = auxLong*10 + (linha[pos]-48);
	telefone = auxLong;
	
	auxLong=0;
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxLong = auxLong*10 + (linha[pos]-48);
	cnh = auxLong;
	
	auxLong=0;
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxLong = auxLong*10 + (linha[pos]-48);
	cpf = auxLong;
	
	//std::cout<<" >> TESTE"<<std::endl;
}//fim do metodo materializar


std::string Cliente::desmaterializar()const
{
	std::string linha, auxString;
	
	// MATERIALIZANDO O IDENTIFICADOR
	// CONVERTENTO O IDENTIFICADOR PAR AUMA STRING
	// METODO DE CONVERSAO: usando os valores da tabela ASCIII
	for(int aux = identificador; aux ; ){ //REPETE ENQUANTO AUX FOR UM VALOR INTEIRO
		// pegando o resto da divisao do aux e incrementando 48, essa add foi
		// devido ao metodo de conversao para a tabela ASCII
		char letra = (aux%10)+48;
		auxString = letra + auxString;
		aux = aux/10;	
	}
	linha = auxString;
	linha += ";";
	
	linha += nome;
	linha += ";";
	
	linha += endereco;
	linha += ";";
	
	
	auxString ="";
	for(long aux = telefone; aux ; ){ 
		char letra = (aux%10)+48;	
		auxString = letra + auxString;
		aux /= 10;	
	}
	linha +=auxString;
	linha += ";";
	
	
	auxString = "";
	for(long aux = cnh; aux ; ){ 
		char letra = (aux%10)+48;	
		auxString = letra + auxString;
		aux /= 10;	
	}
	linha +=auxString;
	linha += ";";
	
	auxString = "";
	for(long aux = cpf; aux ; ){ 
		char letra = (aux%10)+48;	
		auxString = letra + auxString;
		aux /= 10;	
	}
	linha +=auxString;
	linha += ";";
	
	
	return linha;	
}//fim do desmaterializar

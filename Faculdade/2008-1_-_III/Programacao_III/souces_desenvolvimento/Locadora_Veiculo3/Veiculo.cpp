// PRODUCT BY MARCO TULIO
#include<iostream>
#include"Veiculo.h"
using namespace std;

// ARQUIVO PARA A DEFINIÇÃO DOS METODOS DA CLASSE VEICULO
void Veiculo::materializar(string linha)
{
	string auxString="";
	int auxInt=0, pos=0;
	
	// MATERIALIZANDO O IDENTIFICADOR
	//fazendo o metodo de conversao para a tabela ASCII
	for( ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + linha[pos]-48;
	identificador = auxInt;
	
	//std::string auxStr2="";
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxString += linha[pos];
	modelo = auxString;
	
	//string auxStr2="";
	auxString = "";
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxString += linha[pos];
	marca = auxString;
	
	//string auxStr2="";
	auxString = "";
	for(pos++ ; linha[pos]!= ';'; pos++) auxString += linha[pos];
	placa = auxString;
	
	
	auxInt=0;
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxInt = auxInt*10 + (linha[pos]-48);
	valorDeCompra = auxInt;
	
	auxInt=0;
	for(pos++ ; linha[pos]!=';' ; pos++ ) auxInt = auxInt*10 + (linha[pos]-48);
	valorDeVenda = auxInt;
	
	//std::cout<<" >> TESTE"<<std::endl;
}//fim do metodo materializar

string Veiculo::desmaterializar()const
{
	string linha, auxString;
	
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
	// armazendo o valor encontrado do identificador em linha
	linha = auxString;
	// FOI ADOTADO QUE NA LINHA TERA: id;marca;...
	//dados separados por ponto e virgula.. entao:
	linha += ";";
	
	// MATERIALIZANDO O modelo, marca e placa
	linha +=modelo;
	linha += ";";
	
	linha +=marca;
	linha += ";";
	
	linha +=placa;
	linha += ";";
	
	// MATERIALIZANDO O VALOR DE COMPRA
	auxString = "";
	for(int aux = valorDeCompra; aux ; ){ 
		char letra = (aux%10)+48;	
		auxString = letra + auxString;
		aux /= 10;	
	}
	linha += auxString;
	linha += ";";
	// MATERIALIZANDO O VALOR DE VENDA
	auxString = "";
	for(int aux = valorDeVenda; aux ; ){
		char letra = (aux%10) + 48;
		auxString = letra + auxString;
		aux /= 10;		
	}//fim for
	linha += auxString;
	linha += ";";
	return linha;	
}//fim do desmaterializar


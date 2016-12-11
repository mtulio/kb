#include <iostream>
#include <string>
#include "classeData.h"
using namespace std;
int main (void)
{//inicio do programa principal
	Data data1; //criando objeto data1
	unsigned int dia, mes, ano;
	
	cout<<endl<<"Digite o dia: ";
	cin>>dia;
	cout<<endl<<"Digite o mes: ";
	cin>>mes;
	cout<<endl<<"Digite o ano: ";
	cin>>ano;
	if (data1.atribuir(dia, mes, ano)) cout<<endl<<"DATA ATRIBUIDA";//chamando o metodo atribuir e se verdadeiro imprimi uma msg de status
		else cout<<endl<<"DATA ERRADA - NÃO ATRIBUIDA";//Caso o contrario imprimi uma msg de erro
	
	data1.obter(dia, mes, ano); //chamando o metodo obter com apenas inteiros	
	cout<<endl<<endl<<"Dia: "<<dia<<"/Mes: "<<mes<<"/Ano: "<<ano<<endl;
	string mesPal, diaSemana;//criando duas variaveis strings 
	data1.obter(dia, mesPal, ano);
	cout<<endl<<endl<<"Dia: "<<dia<<"Mes: "<<mes<<"Ano: "<<ano<<endl;
	diaSemana = data1.diaDaSemana();
	cout<<endl<<endl<<"Dia da Semana: "<<diaSemana<<endl;	
}//fim do programa principal

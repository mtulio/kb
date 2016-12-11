#include <iostream>
#include <string>
#include "classeData.h"
#include <cstdlib>
using namespace std;
int main (void)
{
	Data data1;
	unsigned int dia, mes, ano;
	system("clear");
	cout<<endl<<"Digite o dia: ";
	cin>>dia;
	cout<<"Digite o mes: ";
	cin>>mes;
	cout<<"Digite o ano: ";
	cin>>ano;
	if (data1.atribuir(dia, mes, ano))
       {
       cout<<endl<<"DATA ATRIBUIDA";
       data1.obter(dia, mes, ano);
       string mesPal, diaSemana;
       data1.obter(dia, mesPal, ano);
       diaSemana = data1.diaDaSemana();
             
       cout<<endl<<dia<<" / "<<mes<<" / "<<ano;
       cout<<endl<<mes<<" / "<<dia<<" / "<<ano;
       cout<<endl<<dia<<" / "<<mes<<" / "<<ano%100;
       cout<<endl<<mes<<" / "<<dia<<" / "<<ano%100;
       cout<<endl<<dia<<" de "<<mesPal<<" de "<<ano;
       cout<<endl<<diaSemana<<", "<<dia<<" / "<<mes<<" / "<<ano;
       cout<<endl<<diaSemana<<" ,"<<dia<<" de "<<mesPal<<" de "<<ano;
       }
		else cout<<endl<<"DATA ERRADA - NÃO ATRIBUIDA";
		cout<<endl<<endl<<"        Programação II - Eugenio"<<endl;
getchar();
getchar();
system("clear");
}

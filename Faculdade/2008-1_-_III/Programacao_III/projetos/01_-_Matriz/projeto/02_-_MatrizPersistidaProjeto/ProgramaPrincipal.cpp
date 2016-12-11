#include"Matriz.h"
#include"InterfaceMatriz.h"
//#include"Persistencia.h"
#include<iostream>
using namespace std;

int main(void)
{
	unsigned int linha,coluna;
	
	system("clear");
	cout<<" S I S T E M A  D E  M A T R I Z E S  MATRIZ A";
	cout<<endl<<endl;
	cout<<"Quantidade de Linhas da matriz: ";
	cin>>linha;
	cout<<"Quantidade de Colunas da matriz: ";
	cin>>coluna;
	
	Matriz MA(linha,coluna);
	InterfaceMatriz::lerMatriz(MA);
	cout<<endl<<endl<<endl<<"Escrita da matriz MATRIZ A"<<endl<<endl;
	InterfaceMatriz::escreverMatriz(MA);

	cout<<" S I S T E M A  D E  M A T R I Z E S  MATRIZ B";
	cout<<endl<<endl;
	cout<<"Quantidade de Linhas da matriz: ";
	cin>>linha;
	cout<<"Quantidade de Colunas da matriz: ";
	cin>>coluna;
	
	Matriz MB(linha,coluna);
	InterfaceMatriz::lerMatriz(MB);
	cout<<endl<<endl<<endl<<"Escrita da matriz MATRIZ B"<<endl<<endl;
	InterfaceMatriz::escreverMatriz(MB);
	
	
	Matriz MC(0,0);
	MC = MA + MB;
	cout<<endl<<endl<<endl<<"Escrita da matriz  MATRIZ C"<<endl<<endl;
	InterfaceMatriz::escreverMatriz(MC);
	





	
	
	return 1;
}

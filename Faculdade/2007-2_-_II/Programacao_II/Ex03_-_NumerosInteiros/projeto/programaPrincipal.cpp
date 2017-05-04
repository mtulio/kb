#include<iostream>
#include<iomanip>
#include<string>
#include"classeNumeros.h"
#include<cmath>
#include <cstdlib>

using namespace std;
int main (void)
{//inicio do programa principal
	
	unsigned int n, b, opcao, nprinc, i;
	numeros n1; //criando objeto n1
   
   
   cout<<endl<<"Digite o primeiro numero inteiro: ";
   cin>>n;
   cout<<endl<<"Digite o segundo numero inteiro: ";
   cin>>b;
   
string tabela[20];
tabela[0]=" __________________________________";
tabela[1]="|__________________________________";
tabela[2]="|----------------------------------|";
	n1.atribuir(n);
	n=n1.obter();
	//cout<<endl<<"|**************************";
	cout<<endl<<tabela[0];
	
	
	
	cout<<endl<<"|__Primeiro_Numero___: "<<setw(12)<<n<<"|";
	cout<<endl<<tabela[2];
	cout<<endl<<"|Fatorial            : "<<setw(12)<<n1.fatorial()<<"|"<<endl;
	cout<<"|Numero Perfeito     : ";
	if (n1.numeroPerfeito()) cout<<"Sim"<<"         |"<<endl;
	else cout<<"Nao"<<"         |"<<endl;
	cout<<"|Capicua             : ";
	if (n1.capicua()) cout<<"Sim"<<"         |"<<endl;
	else cout<<"Nao"<<"         |"<<endl;
	cout<<"|Quad. Perfeito      : ";
	if (n1.quadradoPerfeito()) cout<<"Sim"<<"         |"<<endl;
	else cout<<"Nao"<<"         |"<<endl;
	cout<<"|Numero Primo        : ";
	if (n1.numeroPrimo()) cout<<"Sim"<<"         |"<<endl;
	else cout<<"Nao"<<"         |"<<endl;
	
	cout<<"|Mudança para Base 2 : "<<setw(12)<<n1.mudarBase(2)<<"|"<<endl;
	cout<<"|Mudança para Base 8 : "<<setw(12)<<n1.mudarBase(8)<<"|"<<endl;
	cout<<"|Mudança para Base 16: "<<setw(12)<<n1.mudarBase(16)<<"|"<<endl;
	
	cout<<"|MDC                 : "<<setw(12)<<n1.mdc(b)<<"|"<<endl;	
	cout<<"|MMC                 : "<<setw(12)<<n1.mmc(b)<<"|"<<endl;
	cout<<"|Primos Entre si     : ";
	if (n1.primosEntreSi(b)) cout<<"Sim"<<setw(10)<<"|"<<endl;
	else cout<<"Nao"<<setw(10)<<"|"<<endl;
	cout<<tabela[2];
	
	//calculando os valores do segundo numero
	n1.atribuir(b);
	b=n1.obter();
	//cout<<endl<<"|**************************";
	cout<<endl<<tabela[0];
	cout<<endl<<"|___Segundo_Numero___: "<<setw(12)<<b<<"|";
	cout<<endl<<tabela[2];
	cout<<endl<<"|Fatorial            : "<<setw(12)<<n1.fatorial()<<"|"<<endl;
	cout<<"|Numero Perfeito     : ";
	if (n1.numeroPerfeito()) cout<<"Sim"<<"         |"<<endl;
	else cout<<"Nao"<<"         |"<<endl;
	cout<<"|Capicua             : ";
	if (n1.capicua()) cout<<"Sim"<<"         |"<<endl;
	else cout<<"Nao"<<"         |"<<endl;
	cout<<"|Quad. Perfeito      : ";
	if (n1.quadradoPerfeito()) cout<<"Sim"<<"         |"<<endl;
	else cout<<"Nao"<<"         |"<<endl;
	cout<<"|Numero Primo        : ";
	if (n1.numeroPrimo()) cout<<"Sim"<<"         |"<<endl;
	else cout<<"Nao"<<"         |"<<endl;
	
	cout<<"|Mudança para Base 2 : "<<setw(12)<<n1.mudarBase(2)<<"|"<<endl;
	cout<<"|Mudança para Base 8 : "<<setw(12)<<n1.mudarBase(8)<<"|"<<endl;
	cout<<"|Mudança para Base 16: "<<setw(12)<<n1.mudarBase(16)<<"|"<<endl;
	
	cout<<"|MDC                 : "<<setw(12)<<n1.mdc(n)<<"|"<<endl;
	cout<<"|MMC                 : "<<setw(12)<<n1.mmc(n)<<"|"<<endl;
	cout<<"|Primos Entre si     : ";
	if (n1.primosEntreSi(n)) cout<<"Sim"<<setw(10)<<"|"<<endl;
	else cout<<"Nao"<<setw(10)<<"|"<<endl;
	//cout<<endl<<"**************************";
	cout<<tabela[2];
	
  getchar();
  getchar();
}//fim do programa principal

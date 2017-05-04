#include<iostream>
#include<string>
#include<vector>
#include"classeNumeroNatural.h"
#include<cmath>
#include<iomanip>
using namespace std;
int main (void){//inicio do programa principal
unsigned long b,n,mdc,mmc,nb;
NumeroNatural n1; //criando objeto n1
cout<<endl<<"Informe dois números Naturais: ";
cin>>n>>b;
n1.atribuir(n);
vector <string> tabela(21);

tabela[0]="---------------------------------------------------------------------------------";
tabela[1]="| Metodo | 1º Numero | 2º Numero |";
tabela[2]=" Sim |";
tabela[3]=" Nao |";
tabela[4]= "| Fatorial |";
tabela[5]= "| Numero Perfeito |";
tabela[6]= "| Capicua |";
tabela[7]= "| Quadrado perfeito |";
tabela[8]= "| Numero Primo |";
tabela[9]= "| Numero Primo Entre si |";
tabela[10]= "| MDC |";
tabela[11]= "| MMC |";
tabela[12]= " Sim |"; 
tabela[13]= " Nao |"; 
cout<<tabela[0]<<endl<<tabela[1];
//fatorial
if(n1.fatorial(n)&& n1.fatorial(b)) {

                    cout<<endl<<tabela[0]<<endl<<tabela[4]<<setw(26)<<n<<"|"<<setw(26)<<b<<"|"<<endl;
}

//numero perfeito
cout<<tabela[0]<<endl<<tabela[5];
if(n1.numeroperf(n)) cout<<tabela[2];
else cout<<tabela[3];
if(n1.numeroperf(b)) cout<<tabela[2];
else cout<<tabela[3];

//capicua
cout<<endl<<tabela[0]<<endl<<tabela[6];
if(n1.capicua(n)) cout<<tabela[2];
else cout<<tabela[3];
if(n1.capicua(b)) cout<<tabela[2];
else cout<<tabela[3];

//quadrado perfeito
cout<<endl<<tabela[0]<<endl<<tabela[7];
if(n1.quadradoperf(n)) cout<<tabela[2];
else cout<<tabela[3];
if(n1.quadradoperf(b)) cout<<tabela[2];
else cout<<tabela[3];

//numero primo
cout<<endl<<tabela[0]<<endl<<tabela[8];
if(n1.numeroprimo(n)) cout<<tabela[2];
else cout<<tabela[3];
if(n1.numeroprimo(b)) cout<<tabela[2];
else cout<<tabela[3];

//numero primos entre si
cout<<endl<<tabela[0]<<endl<<tabela[9];
if(n1.numprimosi(n,b)) cout<<tabela[12];
else cout<<setw(52)<<tabela[13];

//maximo divisor comun
cout<<endl<<tabela[0]<<endl<<tabela[10];
if(n1.maxdiv(n,b)) {
                   cout<<setw(53)<<b<<"|";
}

//minimo divisor comun
cout<<endl<<tabela[0]<<endl<<tabela[11];
if(n1.mindiv(n,b)) {
                   cout<<setw(53)<<mmc<<"|"<<endl;
}

//base
//cout<<endl<<tabela[0]<<endl;
//if(n1.binario(n)&& n1.binario(b)) {

//cout<<endl<<tabela[0]<<endl<<tabela[9]<<setw(26)<<nb<<"|"<<setw(26)<<nb<<"|"<<endl;
// }
} //fim do programa principal

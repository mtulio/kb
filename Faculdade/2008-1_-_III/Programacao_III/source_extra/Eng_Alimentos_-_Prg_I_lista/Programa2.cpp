#include<iostream>
using namespace std;
int main(void){
	
	//DECLARANDO AS VARIAVEIS
	int ano;
	
	// LENDO O ANO PARA O CALCULO
	cout<<" Digite o ano: ";
	cin>>ano;
	
	// REALIZANDO O CALCULO
	if((ano%100)!=0){ // SE O ANO NAO FOR UM SECULO
		if((ano%4)==0){ // SEO ANO FOR DIVISIVEL POR 4
			cout<<"O ano "<<ano<<" eh bissexto"<<endl;
		}
		else {// SE O ANO NAO FOR DIVISIVEL POR 4
			cout<<" O ano nao eh bissexto"<<endl;
		}
	} //SE O ANO FOR UM SECULO
	else cout<<" O ano nao eh bissexto"<<endl;	
}

#include <iostream>
#include "classeCPF.h"

using namespace std;

int main (void) { //Inicio do programa Principal
	unsigned long nCPF, n2;
	unsigned int digVer, d2;
	cout << endl << "Digite o seu CPF: ";
	cin >> nCPF;
	cout << endl << "Digite o digito verificador: ";
	cin >> digVer;
	
	CPF CA;
	
	if (CA.atribuir(nCPF, digVer)) cout << endl << "CPF validado!!!";
	else cout << endl << "Erro no CPF";
	
	CA.obter(n2, d2);
	cout << endl << "Seu CPF é " << (n2/1000000) <<"."<< (n2%1000000)/1000 <<"."<< ((n2%1000000)%1000) <<"-"<< d2 <<endl;
 cin.get();
  cin.get();
}

#include<iostream>
#include<string>

#include"NoCliente.h"
#include"Arvore.h"


//using namespace std;

int main (void)
{
	Arvore *arvore;
	arvore = new Arvore();
	
	std::string nome;
	
	nome = "Teste de variavel nome";
	cout<<endl<<"it is > "<<nome<<endl<<endl;	
	
	nome = "Marco";
	arvore->inserirNo(nome);
	
	nome = "Tulio";
	arvore->inserirNo(nome);
	
	arvore->inserirNo(nome);
	nome = "Rodrigues";
	
	arvore->inserirNo(nome);
	nome = "Braga";
	
	arvore->inserirNo(nome);	
	nome = "Altair";
	
	
	exit(1);
}

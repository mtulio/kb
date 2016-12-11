//Arquivo: Interface.h

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<string>
#include<iostream>

#include"Calcular.h"

using namespace std;

class Interface
{
private:
	static void menuCriptografar();
	static void menuDecriptografar();

public:
	static void menuPrincipal();
};//fim classe interface

#endif /*INTERFACE_H_*/

//menu principal
void Interface::menuPrincipal()
{
	int opcao=0;
	bool id=true;

	do{
		cout<<endl<<"1 - Criptografar ";
		cout<<endl<<"2 - Descriptografar ";
		cout<<endl<<"0 - Sair ";
		cin>>opcao;
		
		switch(opcao){
			case 1: { menuCriptografar(); break; }//fim case 1
			case 2: { menuDecriptografar(); break; }//fim case 2
			default: { 
				cout<<"Opcao invalida...tente novamente"; 
				opcao=5; 
				break;
			}//fim default
		}//fim switch
	}while(opcao==0);
}//fim Interface

//Menu Criptografar
void Interface::menuCriptografar()
{
	bool id=true;
	int a, b;

	do{
		cout<<endl<<"Digite o valor de a [1-255]: ";
		cin>>a;
		cout<<endl<<"Digite o valor de b [0-255]: ";
		cin>>b;

		if(Calcular::inverso(a)==-1) {
			cout<<endl<<"O valor de \"a\" nao possui inversa, favor digite novamente!";
			id=true;
		}
		else {//calcula o encript e decript
			Calcular calcularCriptografando(a,b);
			if (calcularCriptografando.criptografar()) 
				cout<<endl<<"Arquivo: "<<calcularCriptografando.obterNomeArqTexto()<<" criptografado para: "<<calcularCriptografando.obterNomeArqCript()<<endl;
			else cout<<" Problemas ao criptografar o arquivo: "<<calcularCriptografando.obterNomeArqTexto()<<endl;
		}//
	}while(id==false);
}//fim Interface

//Menu Decriptografar
void Interface::menuDecriptografar()
{
	bool id=true;
	int a, b;

	do{
		cout<<endl<<"Digite o valor de a [1-255]: ";
		cin>>a;
		cout<<endl<<"Digite o valor de b [0-255]: ";
		cin>>b;

		if(Calcular::inverso(a)==-1) {
			cout<<endl<<"O valor de \"a\" nao possui inversa, favor digite novamente!";
			id=true;
		}
		else {//calcula o encript e decript
			Calcular calcularDecriptografar(a,b);
			if (calcularDecriptografar.decriptografar()) 
				cout<<endl<<"Arquivo: "<<calcularDecriptografar.obterNomeArqTexto()<<" criptografado para: "<<calcularDecriptografar.obterNomeArqCript()<<endl;
			else cout<<" Problemas ao criptografar o arquivo: "<<calcularDecriptografar.obterNomeArqTexto()<<endl;
		}//
	}while(id==false);
}//fim Interface

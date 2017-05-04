#include<iostream>
#include<string>

#include"ControleInt.h"
#include"ControleFloat.h"
#include"ControleDouble.h"
#include"ControleLong.h"
#include"ControleShort.h"

using namespace std;

int main(void){
	try{
		
		//Interface<int>::menuPrincipal();
		
      int opcao=1;
		while(opcao){
         system("cls");
			//system("clear");
         cout<<endl<<"\tMENU PRINCIPAL - TIPOS DE MATRIZES";
			cout<<endl<<" 1 - int";
			cout<<endl<<" 2 - float";
			cout<<endl<<" 3 - double";
			cout<<endl<<" 4 - long";
			cout<<endl<<" 5 - short";
			cout<<endl<<" 0 - Sair do programa";
			cout<<endl<<"Escolha o tipo: ";
			cin>>opcao;
		
			switch(opcao){
			
			case 1:{ ControleInt::setarTipo(); break; }
			case 2:{ ControleFloat::setarTipo(); break; }
			case 3:{ ControleDouble::setarTipo(); break; }
			case 4:{ ControleLong::setarTipo(); break; }
			case 5:{ ControleShort::setarTipo(); break; }
			case 0:{ exit(1); break; }
			default:{ cout<<" Opcao invalida!!!"<<endl;	break; }
			
			}//fim switch		
		}//fim while		
	}//fim do try
	catch(string msg){
		cout<<" Erro PP: "<<msg<<endl<<endl;
	}	
}//fim do main

//#include "carta.h"
#include "baralho.h"
#include <string>

/*
Baralho * criar_baralho() {
	int i, k;
	char naip;
	Carta * aux;
	Baralho * bara = new Baralho("normal");
	// cria os 4 naipes
	for(i=1; i<=4; i++) {
		if(i==1) naip='c';
		if(i==2) naip='o';
		if(i==3) naip='e';
		if(i==4) naip='p';
		for(k=1; k<=13; k++) {
			aux = bara->cria_carta(k, naip);
			bara->adiciona_carta(aux);
		}
	}
	// cria os 2 curingas com naipe 'a' e número 14 e 15.
	aux = bara->cria_carta(14, 'a');
	bara->adiciona_carta(aux);
	aux = bara->cria_carta(15, 'a');
	bara->adiciona_carta(aux);
	return bara;
}
*/

int main() {
	Baralho * bar=0;
	Carta * aux=0;
	int i=0, x=0;
	do {
        system("cls");
		cout << endl << "Escolha uma das seguintes operacoes" << endl;
		cout << "1 --> Criar um baralho." << endl;
		cout << "2 --> Listar o baralho." << endl;
		cout << "3 --> Inverte o baralho." << endl;
		cout << "4 --> Destruir os baralhos." << endl;
		cout << "Digite qualquer outro caracter para encerrar o programa.: ";
		cin >> x ;
		switch (x) {
  			case 1:{
                 //se o baralho n existir ele criara um
                 cout<<"Digite o nome do baralho: ";
                 std::string nome;
                 cin>>nome;
                 
  				if(bar==0)
                            bar->criar_baralho(nome);
                            //cout<<"Baralho criadoo com sucesso"<<endl;
                 
  				
				else cout << endl << "O baralho jah foi criado. Destrua-o para criar outro." << endl;
  				
                cin.get();
                cin.get();
                  break;
             }
  			case 2:
 				
                 if(bar!=0) bar->lista_carta();
				else cout << endl << "O baralho não foi criado. Crie-o primeiro." << endl;
				cin.get();
                cin.get();
  				break;
  			case 3:
 				if(bar!=0) bar->inverte_baralho();
				else cout << endl << "O baralho não foi criado. Crie-o primeiro." << endl;
				break;
 			case 4:
  				if(bar!=0) {bar->~Baralho(); bar=0;}
				else cout << endl << "O baralho não foi criado. Crie-o primeiro." << endl;
  				break;
           case 0:{
                cout<<"Finalizando programa... pressione ENTER!";
                cin.get();
                cin.get();
                break;
                }
  			default:
                
    			cout << endl << "Você digitou um caracter de parada ou um caracter ilegal." << endl;
		}
	}while(x!=0);
	cout << "Programa encerrado pelo usuário." << endl;
	exit(0);	
}

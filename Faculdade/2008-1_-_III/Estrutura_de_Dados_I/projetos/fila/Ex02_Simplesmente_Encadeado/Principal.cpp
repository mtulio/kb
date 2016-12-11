#include<iostream>
#include<iomanip>
#include<string>
#include"NoRequisicao.h"
#include"Fila.h"
#include"ControleFila.h"
#include"Interface.h"

using namespace std;


int main()
{
    Fila *fila=0;
    
    int opcao=1;
    while(opcao){
       system("clear");
       cout<<"\t\tED I - FILA"<<endl;
       cout<<endl<<"1 - Criar Fila Vazia";
       cout<<endl<<"2 - Adicionar Requisicao na Fila";
       cout<<endl<<"3 - Remover requisicao da Fila";
       cout<<endl<<"4 - Consultar requisicao na Fila";
       cout<<endl<<"5 - Listar requisicoes na Fila";
       cout<<endl<<"6 - Destruir Fila";
       cout<<endl<<"0 - SAIR";
       cout<<endl<<"\tEscolha a operacao: ";
       cin>>opcao;
       
       switch(opcao){
                     case 1:{//criar fila vazia
                        system("clear");
                    	cout<<"\tOPCAO 01 - \"Criar Fila Vazia\""<<endl;
                    	if(fila==0){//if 1
                    		fila = new Fila();
                    		if(fila) cout<<"  Fila criada"<<endl;
                    		  else cout<<"Fila n�o criada"<<endl;
                        }//fim if 1
                        else cout<<" Fila ja esta criada"<<endl;
                        
                        cin.get();cin.get();
                        break;
                     }//fim case 1 - criar fila
                     
                     case 2:{//add
                    	system("clear");
                    	cout<<"\tOPCAO 02 - \"Adicionar Requisicao na Fila\""<<endl;
                        //se a fila nao estiver apontando pra ninguem eh impossivela dd
                        //ou se a fila estiver vazia
                        if(fila==0){
                           cout<<" Fila Nao criada"<<endl;
                           cin.get();cin.get(); break;
                        } 
                        
                        NoRequisicao *requisicao = new NoRequisicao();
                        Interface::lerDadosRequisicao(requisicao);
                                              
                        cout<<" Status: ";
                        if(fila->adicionar(requisicao)) cout<<"Requisicao Adicionada"<<endl;
                           else cout<<" Requisicao nao adicionada"<<endl;                        
                        
                        cin.get();cin.get();
                        break;
                     }//fim case 2 - adicionar
                     
                     case 3:{//remover
                    	system("clear");
                    	cout<<"\tOPCAO 03 - \"Remover requisicao da Fila\""<<endl;
                    	if(fila==0){
                           cout<<" Fila Nao criada"<<endl;
                           cin.get();cin.get(); break;
                        } 
                        if(fila->estaVazio()){
                           cout<<" A fila esta vazia"<<endl;
                           cin.get();cin.get(); break;                     
                        }
                        
                       
                        NoRequisicao *requisicao = new NoRequisicao();
                        requisicao = fila->retirar();
                        
                        Interface::escreverRequisicao(requisicao);
                        cout<<" Requisicao Removida com Sucesso"<<endl;
                        cin.get();cin.get();
                        break;
                     }//fim case 3
                     
                     case 4:{// - consultar 
                    	system("clear");
                    	cout<<"\tOPCAO 04 - \"Consultar requisicao na Fila\""<<endl;
                    	if(fila==0){
                           cout<<" Fila Nao criada"<<endl;
                           cin.get();cin.get(); break;
                        } 
                        if(fila->estaVazio()){
                           cout<<" A fila esta vazia"<<endl;
                           cin.get();cin.get(); break;                     
                        }                       
                        
                        cout<<"  Digite o nome do cliente da requisicao: ";
                        string nome;
                        cin>>nome;
                            
                        NoRequisicao *requisicao = new NoRequisicao();
                        if(ControleFila::busca(nome, fila, requisicao )){
                           cout<<" Requisicao Encontrada: "<<endl;
                           Interface::escreverRequisicao(requisicao);
                        }
                        else cout<<" Requisicao nao encontrada!!!"<<endl; 
                        
                        //delete requisicao;
                        cin.get();cin.get();
                        break;
                     }//fim case 4                     
                     
                     case 5:{//listar
                    	system("clear");
                    	cout<<"\tOPCAO 05 - \"Listar requisicoes na Fila\""<<endl;
                    	if(fila==0){
                           cout<<" Fila Nao criada"<<endl;
                           cin.get();cin.get(); break;
                        } 
                        if(fila->estaVazio()){
                           cout<<" A fila esta vazia"<<endl;
                           cin.get();cin.get(); break;                     
                        }
                        
                        Fila *copiaFila = new Fila();
                        ControleFila::copiarFila(fila, copiaFila);
                        //copiaFila=fila;
                        Interface::listarTodos(copiaFila);
                        
                        cin.get();cin.get();
                        break;                     
                     }//fim case 5 - listar
                     
                     case 6:{//destruir fila
                    	 system("clear");
                    	 cout<<"\tOPCAO 06 - \"Destruir Fila\""<<endl;                    	 
                    	 fila->~Fila();
                         fila=0;
                         cout<<"  Fila destruida"<<endl;                          
                         cin.get();cin.get();
                         break;
                         
                     }//fim case 6
                     
                     case 0:{//SAIR
                        cout<<" Finalizando Programa!!!"<<std::endl;
                        fila->~Fila();
                        if(fila) delete fila;
                        cin.get();cin.get();
                        exit(0);
                        break;
                     }//fim case 0
       }//fim switch
    }//fim while
    
    
    cin.get();
    cin.get();
    
    delete fila;
    exit(1);
}//fim main

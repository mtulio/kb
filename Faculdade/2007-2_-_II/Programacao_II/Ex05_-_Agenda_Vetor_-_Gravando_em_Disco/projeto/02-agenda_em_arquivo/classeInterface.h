#ifndef CLASSEINTERFACE_H_
#define CLASSEINTERFACE_H_
#include<iostream>
#include"classeControle.h"
#include<string>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;
//***************************************************************
//Esta classe tem como responsabilidade a "comunicacao" com o usuario 
// comunicacao do tipo usuario/interface
//**********************************************************
class Interface
{
	//Metodos
	public:
		static void menuPrincipal(Controle &ctrl);
		static void lerPessoa(std::string &nome, unsigned long &telefone, std::string &email);
		static void lerPessoaA(const std::string &nome, unsigned long &telefone, std::string &email);
		static void escreverPessoa(const std::string &nome, unsigned long telefone, const std::string &email);
};

void Interface::menuPrincipal(Controle &ctrl)//Metodo q tem como parametro um objeto da classe controle
{// inicio metodo
	unsigned int opcao=1;
	while(opcao){// inicio while
		std::string superior="_________________________",
                    inferior="_________________________",
                    lateral=" | ";
        system("cls");
		cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
		cout<<endl<<"  MENU PRINCIPAL"<<endl;
		cout<<superior;
        cout<<endl<<"| 1 - INCLUIR           |";
		cout<<endl<<"| 2 - EXCLUIR           |";
		cout<<endl<<"| 3 - ALTERAR           |";
		cout<<endl<<"| 4 - CONSULTAR         |";
		cout<<endl<<"| 5 - LISTAGEM GERAL    |";
		cout<<endl<<"| 6 - LISTAGEM POR LETRA|";
		cout<<endl<<"| 0 - SAIR              |";
		cout<<endl<<inferior;
        cout<<endl<<endl;
		cout<<"OPCAO: ";
		cin>>opcao;
		switch(opcao){// inicio switch
			case 1:{// inicio case 1 - INCLUIR
			//chamar o metodo ler, receber os dados, fez a chamada do metodo 
            //incluir da classe controle, que retorna um numero. esse numero é o
            //status da inclusao. de acordo com a resposta eu vou saber o que aconteceu com a
            //inclusao.
					std::string nome,email;
					unsigned long telefone;
					lerPessoa(nome,telefone,email);//chamando o metodo para ler os dados digitados pelo user
					int resposta=ctrl.incluir(nome,telefone,email);//enviando os dados digitados para o metodo incluir da classe Controle 01.1
					if(resposta == 1) cout<<endl<<"INCLUSAO NA AGENDA - SUCESSO";
					if(resposta == 2) cout<<endl<<"-> ERRO"<<endl<<"INCLUSAO NA AGENDA - NOME JA EXISTE";
					if(resposta == 3) cout<<endl<<"-> ERRO"<<endl<<"INCLUSAO NA AGENDA - AGENDA CHEIA";
					cout<<endl<<endl<<"<ENTER> PARA CONTINUAR";
					cin.get();
				break;
			}// fim case 1
			case 2:{//inicio case 2   -  EXCLUIR
					std::string nome,email;
					unsigned long telefone;
					system("cls");
                    cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
                    cout<<endl<<" EXCLUIR";
                    cout<<endl<<"NOME: ";
					cin.get();
					getline(cin,nome);
					if(ctrl.consultar(nome,telefone,email)){
						escreverPessoa(nome,telefone,email);
						cout<<endl<<endl<<"Confirma Exclusao[s/n]:  ";
						char resp;
						resp=cin.get();
						if(resp!='s' && resp!='S' && resp=='n' && resp=='N') resp = 'n';                                  
						if(resp=='s' || resp=='S'){
							ctrl.excluir(nome);
							cout<<endl<<"EXCLUSAO CONCLUIDA";
						}else cout<<"Exclusao Cancelada"<<endl;
					}else cout<<endl<<"PESSOA NAO EXISTE NA AGENDA";
					cout<<endl<<endl<<"<ENTER> PARA CONTINUAR";
					cin.get();
				break;
			}//fim case 2
			case 3:{//inicio case 3    - ALTERAR
					std::string nome,email;
					unsigned long telefone;
					system("cls");
                    cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
                    cout<<endl<<" ALTERAR";
                    cout<<endl<<"NOME: ";
					cin.get();
					getline(cin,nome);
					if(ctrl.consultar(nome,telefone,email)){
						escreverPessoa(nome,telefone,email);
						cout<<endl<<endl<<"Confirma Alteracao[s/n]:  ";
						char resp;
						resp=cin.get();
						if(resp!='s' && resp!='S' && resp!='n' && resp!='N') resp = 'n';
						if(resp=='s' || resp=='S'){
							lerPessoaA(nome,telefone,email);
							ctrl.alterar(nome,telefone,email);
						}
					}else cout<<endl<<"PESSOA NAO EXISTE NA AGENDA";
					cout<<endl<<endl<<"<ENTER> PARA CONTINUAR";
					cin.get();
				break;
			}//fim case 3   
			case 4:{// inicio case 4 - CONSULTAR
					std::string nome,email;
					unsigned long telefone;
					system("cls");
                    cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
                    cout<<endl<<" CONSULTAR";
                    cout<<endl<<"NOME: ";
					cin.get();
					getline(cin,nome);
					if(ctrl.consultar(nome,telefone,email))	escreverPessoa(nome,telefone,email);
						else cout<<endl<<"PESSOA NAO EXISTE NA AGENDA";
					cout<<endl<<endl<<"<ENTER> PARA CONTINUAR";
					cin.get();
				break;
			}//fim case 4  
			case 5:{//inicio case 5  -  LISTAGEM GERAL      
                    Iterator *iterator = ctrl.listagemGeral();//chamando o metodo listagem geral q retorna um objeto da classe persistencia
				//listagemGeral é um método da classe controle.
				//ele retorna o método obter todas as pessoas da classe persistencia
				//e o tipo desse metodo é INTERADOR!!!
                
                	if (iterator->estaVazio()){ //verifica se a agenda que está no iterador
                                                   //está vazia.
                       cin.ignore();// ignora tudo o que foi armazenado no buffer do último cin.                    
                       cout<<" Agenda Vazia" << endl;
                       cin.get();                  
                       break;                                 
                     }               
                    //agora tem todos os nomes do arquivo dentro de um vetor de objetos da classe pessoa
                    std::string superior="__________________________________________________________",
					            inferior="__________________________________________________________",
					            lateral=" | ";
                    system("cls");
					cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
                    cout<<endl<<"  LISTAGEM GERAL"<<endl;
					cout<<superior<<endl;
                    cout<<"______NOME_________TELEFONE______________EMAIL__________"<<lateral<<endl;
                    
                    iterator->inicio();//comando pro interador ir para o inicio.
					bool teste=true;
					while(teste){//vai repetir enquanto a variavel teste for verdadeira
						Pessoa pessoa=iterator->obter();
                        //obter retorna um objeto da classe pessoa
    
						std::string nome;
						pessoa.obterNome(nome);
						cout<<std::setw(15)<<nome<<lateral<<std::setw(10)<<pessoa.obterTelefone()<<lateral<<std::setw(25)<<pessoa.obterEmail()<<lateral<<endl;
						teste=iterator->proximo();
						//pergunta ao "metodo" proximo, se ainda tem posições ocupadas
						//na agenda, se tiver retorna 1. e entra no while novamente.
						//se retornar 0, continua o prog.
					}
					cout<<inferior<<endl;
					cout<<endl<<endl<<"<ENTER> PARA CONTINUAR";
					cin.get();
					cin.get();
					delete iterator; //deletando o ponteiro criado dentro do case.
				break;
			}//fim case 5
			case 6:{//inicio do case 6 - LISTAGEM POR LETRA
			     	char letra;
                    std::string superior="__________________________________________________________",
					            inferior="__________________________________________________________",
					            lateral=" | ";
                    cout<<"Digite a 1ª letra do nome p/listagem: ";
					cin.ignore();//limpando buffer do teclado
					letra=cin.get();//captura a letra digitada na variavel letra   					
					Iterator *iterator = ctrl.listagemNome(letra);
					if (iterator->estaVazio()){//verifica se a agenda dentro do iterador 
					                           //está vazia , neste caso vai ser pq n 
                                               //encontrara nenhum nome com a letra desejada
                       cout<<" NOME DESEJADO NAO ENCONTRADO" << endl;
                       cin.ignore(); //limpando buffer do teclado  
                       cin.get(); //pausa a tela    
                       break;
                    }                    					    
					system("cls");
					cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
					cout<<letra;
                    cout<<endl<<" LISTAGEM POR NOME"<<endl;
					cout<<superior<<endl;
                    cout<<"______NOME_________TELEFONE______________EMAIL__________"<<lateral<<endl;
					iterator->inicio();//função que leva ao inicio da copia da agenda 
					bool teste=true;
					while(teste){
						Pessoa pessoa=iterator->obter();
						std::string nome;
						pessoa.obterNome(nome);
						cout<<std::setw(15)<<nome<<lateral<<std::setw(10)<<pessoa.obterTelefone()<<lateral<<std::setw(25)<<pessoa.obterEmail()<<lateral<<endl;
						teste=iterator->proximo();
					}
					cout<<inferior<<endl;
					cout<<endl<<endl<<"<ENTER> PARA CONTINUAR";
					cin.get();
					cin.get();
					delete iterator;//toda vez q eh criado um ponteiro eh preciso ser deletado			
           }//fim do case 6			     
		}// fim switch
	}// fim while	
}// fim metodo

void Interface::lerPessoa(std::string &nome, unsigned long &telefone, std::string &email)
{//inicio metodo
	system("cls");
	cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
    cout<<endl<<" DADOS DA PESSOA - ENTRADA"<<endl;
	cout<<endl<<"    NOME: ";
	cin.get();
	getline(cin,nome);//lendo o nome e armazenando na var nome
	cout<<"TELEFONE: ";
	cin>>telefone;//lendo o telefone e armazenando na var telefone
	cin.get();
	cout<<"   EMAIL: ";
	getline(cin,email);//lendo o email e armazenando na var email
}// fim metodo

void Interface::lerPessoaA(const std::string &nome, unsigned long &telefone, std::string &email)
//metodo usado para a alteração de nomes
{//inicio metodo
	system("cls");
	cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
    cout<<endl<<" DADOS DA PESSOA - ENTRADA"<<endl;
	cout<<endl<<"    NOME: "<<nome<<endl;
	cout<<"TELEFONE: ";
	cin>>telefone;
	cin.get();
	cout<<"   EMAIL: ";
	getline(cin,email);
}// fim metodo


void Interface::escreverPessoa(const std::string &nome, unsigned long telefone, const std::string &email)
{//este metodo serve apenas para escrever os dados na tela
	system("cls");
	cout<<"\t**_SISTEMA_DA_AGENDA_**"<<endl;
    cout<<endl<<" DADOS DA PESSOA - SAIDA"<<endl;
	cout<<endl<<"    NOME: "<<nome;
	cout<<endl<<"TELEFONE: "<<telefone;
	cout<<endl<<"   EMAIL: "<<email;
}


#endif /*CLASSEINTERFACE_H_*/

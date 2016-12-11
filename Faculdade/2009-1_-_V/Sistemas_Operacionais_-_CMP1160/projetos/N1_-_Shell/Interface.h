#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iostream>
#include<string>
//fim system

#include"Comandos.h"
#include<iomanip>

using namespace std;

class Interface
{//inicio da definicao da classe Interface

public:
	static void menuPrincipal();
	static void menuBin();
	static void menuSbin();
	static void menuProgUser();
	static void menuTaskManager();
};//fim da definicao da classe INterface

//**********************************************************************

void Interface::menuPrincipal()
{//inicio interface
	//inicio das vars globais
	string comando, opcaoS;
	int opcao=100;

	do{//inicio laco do menu principal
		system("clear");
		//cin.ignore();
		cout<<endl<<"   Sistemas Operacionais - N1(Shel) \t Professor Talles"<<endl;
		cout<<endl<<"\tMenu Principal"<<endl;
		cout<<endl<<"ID_-________Lista de Menus________:\"Informações sobre cada menu\"";
		cout<<endl<<"_1_-_Menu de programas da /bin____:\"Exibe uma lista de programas do dir /bin\"";
		cout<<endl<<"_2_-_Menu de programas da /sbin___:\"Exibe uma lista de programas do dir /sbin\"";
		cout<<endl<<"_3_-_Executar programa do usuario_:\"Inicia o menu de execucao do usuario\"";
		cout<<endl<<"_4_-_Gerenciador de Tarefas_______:\"Inicia o menu gerenciador de tarefas\"";
		cout<<endl<<"_0_-_Sair do programa_____________:\"Para a execução do programa\"";
		cout<<endl<<"_____Digite a opção desejada______: ";
		cin>>opcaoS;

		//valida a opcao digitada pelo user
		if(opcaoS[1]=='\0'){
			opcao=(int)opcaoS[0];
			opcao=opcao-48;
		}//fim if
		else opcao=100;
		if(opcao<0||opcao>=5) opcao=100;//condicao para entrar no default

		switch(opcao)
		{//inicio switch
			case 0:{ exit(0); break; }//chamada pra saida do sistema
			case 1:{ menuBin();	 break; }//chamada ao metodo menuBin()
			case 2:{ menuSbin(); break;	}//chamada ao metodo menuSbin()
			case 3:{ menuProgUser(); break;	}//chamada ao metodo menuProgUser()
			case 4:{ menuTaskManager(); break; }//chamada ao metodo menuTaskManager()

			default:{
				cout<<endl<<" Opcao invalida. Tecle <Enter> para tentar novamente!";
				opcao=100;//numero aleatorio para q se possa repetir o menu
				cin.ignore();
				cin.get();
			break;
			}//fim default
		}//fim switch
	}while(opcao!=0);
}//fim interface

//**********************************************************************

//Tem como finalidade executar comandos do diretorio /bin
void Interface::menuBin()
{//inicio menu bin
	string comando, opcaoS;
	int opcao=100;

	do{//inicio laco do-while
		system("clear");
		//cin.ignore();
		cout<<" \"Este menu lista comandos selecionados do diretorio /bin\""<<endl;
		cout<<" \"O diretorio /bin contem contem todos os comandos do S.O.\""<<endl;
		//cout<<endl<<" para que usuario escolha uma opção\""<<endl;
		cout<<endl<<"\t01 - Menu de comandos do dir /bin"<<endl;
		cout<<endl<<"ID_-_________Comandos_____________:\"Informações sobre o comando\"";
		cout<<endl<<"_1_-_ls___________________________:\"Lista os arquivo/diretorios do diretorio atual\"";
		cout<<endl<<"_2_-_date_________________________:\"Exibe o dia da Semana, Mês, Dia, Hora e Ano\"";
		cout<<endl<<"_3_-_df___________________________:\"Exibe espaço usado no Sistema de Arquivos\"";
		cout<<endl<<"_4_-_hostname_____________________:\"Exibe o nome da maquina\"";
		cout<<endl<<"_5_-_uname________________________:\"Exibe informaçõe sobre o Sistema, nome da Sistema utilizado\"";
		cout<<endl<<"_0_-_Voltar_______________________:\"Retorna ao menu Principal\"";
		cout<<endl<<"_____Digite o ID comando__________: ";
		cin>>opcaoS;

		//validando a opcao digitada pelo user
		if(opcaoS[1]=='\0'){
			opcao=(int)opcaoS[0];
			opcao=opcao-48;
		}//fim if
		else opcao=100;
		if(opcao<0||opcao>=6) opcao=100;

		switch(opcao)
		{//inicio switch

			case 0:{ return; break; }//se digitar 0 retorna ao menu anterior/Menu Principal

			case 1:
			{//incio case 1
				comando = "ls";
				//fazendo um chamado do metodo executarComando da classe Comandos
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,1);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim case 1

			case 2:
			{//incio case 2
				comando = "date";
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,1);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim case 2

			case 3:
			{//incio case 3
				comando = "df";
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,1);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim case 3

			case 4:
			{//incio case 4
				comando = "hostname";
				cout<<endl<<"_Saida do programa "<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,1);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim case 4

			case 5:
			{//incio case 5
				comando = "uname";
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,1);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim case 5

			default:
			{//inico default
				cout<<endl<<" Opcao invalida. Tecle <Enter> para tentar novamente!";
				opcao=100;//flag para retornar ao menu
				cin.ignore();
				cin.get();
				break;
			}//fimm default
		}//fimm switch
	}while(opcao!=0);//fim laco do-while
}//fim menu bin

//**********************************************************************

//Menu tem como finalidade imprimir um menu com os comandos da sbin
void Interface::menuSbin()
{//inicio metodo sbin

	string comando, opcaoS;
	int opcao;

	do{//inicio laco do-while
		system("clear");
		//cin.ignore();
		cout<<" \"Este menu lista comandos selecionados do diretorio /sbin\""<<endl;
		cout<<" \"O diretorio /sbin contem ferramentas de conf. do sistema\""<<endl;
		//cout<<endl<<" para que possa ser executado pelo usuario\""<<endl;
		cout<<endl<<"\t02 - Menu de comandos do dir /sbin"<<endl;
		cout<<endl<<"ID_-_______Comando________________:\"Informações sobre o comando\"";
		cout<<endl<<"_1_-_clock________________________:\"Exibe o o relogio do Kernel e/ou o tempo de execução da CPU *\"";
		cout<<endl<<"_2_-_netplugd_____________________:\"Lista os scripts de monitoramento de cada interface de rede.\"";
		cout<<endl<<"_3_-_ifconfig_____________________:\"Lista interfaces de rede. Configura interface de rede";
		cout<<endl<<"_4_-_route________________________:\"Mostra as tabelas de routeamento\"";
		cout<<endl<<"_5_-_runlevel_____________________:\"Exibe o nivel de inicialização do Sistema. Ex: N 5 = Modo Grafico";
		cout<<endl<<"_0_-_Voltar_______________________:\"Retorna ao menu principal\"";
		cout<<endl<<"_____Digite o ID do comando_______: ";
		cin>>opcaoS;

		if(opcaoS[1]=='\0'){
			opcao=(int)opcaoS[0];
			opcao=opcao-48;
		}//fim if
		else opcao=100;
		if(opcao<0||opcao>=6) opcao=100;

		switch(opcao)
		{//inicio switch
			case 0:
			{//inicio case 0
				return;
			break;
			}//fim case 0
			case 1:
			{//incio case 1
				comando = "clock";
				//fazendo um chamado do metodo executarComando da classe Comandos
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,2);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
			break;
			}//fim case 1

			case 2:
			{//incio case 2
				comando = "netplugd";
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,2);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
			break;
			}//fim case 2

			case 3:
			{//incio case 3

				comando = "ifconfig";
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,2);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim case 3

			case 4:
			{//incio case 4
				comando = "route";
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,2);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim case 4

			case 5:
			{//incio case 5
				comando = "runlevel";
				cout<<endl<<"_Saida do programa"<<setw(8)<<comando<<" :"<<endl<<endl;
				Comandos::executaComando(comando,2);
				cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim case 5

			default:
			{//inico default
				cout<<endl<<" Opcao invalida. Tecle <Enter> para tentar novamente!";
				opcao=100;//flag para retornar ao menu
				cin.ignore();
				cin.get();
				break;
			}//fimm default
		}//fimm switch
	}while(opcao!=0);//fim laco do-while
}//fim menu bin

//**********************************************************************

void Interface::menuProgUser()
{//inicio do metodo de digitar comando
	string comando, opcaoS;
	int opcao;

	do{//inicio laco do-while
		system("clear");
		//cin.ignore();
		cout<<"\"Menu de escolha de executar um programa pelo seu nome/Path";
		cout<<endl<<"ou compilar um programa pelos compiladores gcc e g++\""<<endl;
		cout<<endl<<"\t03 - Menu executar comando/programa dos usuarios"<<endl;
		cout<<endl<<"ID_-_____Lista de opções__________:\"Informações sobre o menu\"";
		cout<<endl<<"_1_-_Executar um programa_________:\"Executar um programa pelo nome ou caminho\"";
		cout<<endl<<"_2_-_Compilar um programa_________:\"Exibe opcoes de compilacao\"";
		cout<<endl<<"_0_-_Retornar ao menu anterior____:\"Retorna ao menu principal\"";
		cout<<endl<<"_____Digite o id do comando_______:";
		cin>>opcaoS;

		if(opcaoS[1]=='\0'){
			opcao=(int)opcaoS[0];
			opcao=opcao-48;
		}//fim if
		else opcao=100;
		if(opcao<0||opcao>=5) opcao=100;

		switch(opcao)
		{//inicio switch
			case 0:{ return; break; }

			case 1:
			{//iicio case informar o path
				cout<<endl<<"\"Exemplo executando prog:\n\tPath: $HOME/prog ou /bin/ls "
						"\n\tNome Programa: ./prog ou ls\""<<endl;
				cout<<"Obs.: Não informe arqumentos!"<<endl;
				cout<<" Digite o path ou programa seguindo o exemplo acima: ";
				string comando;
				cin>>comando;
//3 eh o ID do path de exec. nesse caso e executar um prg do user
				cout<<endl;
				Comandos::executaComando(comando,3);
				//if(Comandos::statusComando()) cout<<endl<<" \tPrograma executado com sucesso..Enter para continuar..";
				//else cout<<" FALHA AO EXECUTAR O PROGRAMA"<<endl;
				cout<<endl<<" Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim digitar path

			case 2://inicio case compilar programa
			{
				cout<<endl<<"\t1_-_gcc\n\t2_-_g++"<<endl;
				cout<<" Informe o compilador que será utilizado: ";
				string tipoCompilador;
				cin>>tipoCompilador;
				string codigoFonte, executavel;
				if(tipoCompilador=="1"){
					cout<<" Informe o codigo fonte em C, ou digite sair: ";
					cin>>codigoFonte;
					if(codigoFonte=="sair") break;
					cout<<" Informe o nome do programa: ";
					cin>>executavel;
					//if(codigoFonte=="sair") break;
					Comandos::compilarPrograma(codigoFonte,executavel,1);
				}//fim if 1
				else if(tipoCompilador=="2"){
					cout<<" Informe o codigo fonte em C++, ou digite sair: ";
					cin>>codigoFonte;
					if(codigoFonte=="sair") break;
					cout<<" Informeo nome do programa: ";
					cin>>executavel;
					Comandos::compilarPrograma(codigoFonte,executavel,2);
				}//fim if 2
				else { cout<<" Opcao Invalida!"; }
				//if(Comandos::statusComando()) cout<<" Processo de compilação executado com sucesso"<<endl;
				//else cout<<" Falha ao digitar o comando"<<endl;

				cout<<endl<<" Tecle <Enter> para continuar";
				cin.ignore();
				cin.get();
				break;
			}//fim cas e1

			default:
			{//inico default
				cout<<endl<<" Opcao invalida. Tecle <Enter> para tentar novamente!";
				opcao=100;//flag para retornar ao menu
				cin.ignore();
				cin.get();
				break;
			}//fimm default
		}//fim switch
	}while(opcao!=0);
}//fim do metodo digitar comando

//**************************************************************

void Interface::menuTaskManager()
{//inicio task manager

//variaveis globais
	string comando, opcaoS;
	int opcao;
	string nomeProcesso;

	do{
		system("clear");
		//cin.ignore();
		cout<<"\"Este menu tem a finalidade da iteração do usuario para visualizar processos em execução;"<<endl;
		cout<<"e Finalizar um processo pelo seu nome e/ou PID\""<<endl;
		cout<<endl<<"\t04 - Manu Task Manager - Gerenciador de Tarefas/Processos"<<endl;
		cout<<endl<<"ID_-_Opc. Gerenciador de Tarefas__:\"Informações sobre o menu\"";
		cout<<endl<<"_1_-_Gerenciador de tarefas_______:\"Exibe um relatorio dos proecessos atuais\"";
		cout<<endl<<"_2_-_Finalizar tarefas____________:\"Finaliza um processo pelo seu PID ou nome\"";
//		cout<<endl<<"3 - Pesquisar processos por nome";
		cout<<endl<<"_0_-_Voltar ao menu anterior______:\"Volta ao menu principal\"";
		cout<<endl<<"_____Digite a opção_______________: ";
		cin>>opcaoS;

		if(opcaoS[1]=='\0'){
			opcao=opcaoS[0];//pegando a opcao digitada da string
			opcao=opcao-48;//convertendo segundo a tabela ASCII
		}//fim if
		if(opcao<0||opcao>2) opcao=100;

		switch(opcao)
		{
			case 0: { return; break;}
			case 1:
			{
				Comandos::gerenciadorDeProcessos();
				cout<<" Tecle <Enter> para retornar ao menu...";
				cin.ignore();
				cin.get();
				break;
			}//fim switch

			case 2:
			{//inicio case 2
				cout<<"__Opções:\n_1)_-_PID do processo"<<endl;
				cout<<"_2)_-_Nome do processo"<<endl;
				cout<<"_______Escolha a opcao: ";
				string opcao;
				cin>>opcao;
				int opcaoI = ((int)opcao[0])-48;
				if(opcao=="1")
				{//inifio if
					cout<<" Digite o PID do processo: ";
					//string nomeProc;
					cin>>nomeProcesso;
					Comandos::mataProcesso(nomeProcesso,opcaoI);
					cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				}//fim if
				else if(opcao=="2"){
					cout<<"Digite o nome do processo: ";
					//string nomeProcesso;
					cin>>nomeProcesso;
					Comandos::mataProcesso(nomeProcesso,opcaoI);
					cout<<endl<<" Comando Executado com Sucesso.. Tecle <Enter> para continuar";
				}//fim if
				else{
					cout<<endl<<" Opcao invalida. Tecle <Enter> para tentar novamente!";
				}//fim else
				cin.ignore();
				cin.get();
				break;
			}//fimc ase 2

			default:
			{//inico default
				cout<<endl<<" Opcao invalida. Tecle <Enter> para tentar novamente!";
				opcao=100;//flag para retornar ao menu
				cin.ignore();
				cin.get();
				break;
			}//fimm default
		}//fimm switch
	}while(opcao!=0);//fim laco do-while
}//fim task manager
//**********************************************************************
#endif /*INTERFACE_H_*/

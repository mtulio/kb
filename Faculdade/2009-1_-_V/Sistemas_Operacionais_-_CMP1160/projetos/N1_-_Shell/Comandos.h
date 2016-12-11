#ifndef COMANDOS_H_
#define COMANDOS_H_

//bibliotecas usadas para executar um comando
#include<sys/types.h>
#include<unistd.h>

//bibliotecas extras
#include<iostream>
#include<string>
#include<stdlib.h> //para uso do system
#include<fstream>
#include<sys/wait.h>//uso do metodo wait() em c++

using namespace std;

class Comandos
{//inicio classe comandos
public:
	static void executaComando(string &comando, int idMenu);
	/* id Menu:
		1 - /bin
		2 - /sbin
		3 - informado pelo user
	*/
//	static bool statusComando();

	//Menu 4 metodos do Gerenciador de tarefas
	static void compilarPrograma(string fonte, string executavel, int tipoFonte);
	static void gerenciadorDeProcessos();
	static void mataProcesso(string &idProcesso, int tipoMetodo);
	//static void buscaProcesso(string nomeProc);

};//fim classe comandos
//*******************
//tem a finalidade de verificar se o ultimo comando digitado foi valido ou
//nao usando o retorno de verificação da shell $? se for 0 o comando
//foi executado com exito, caso ocontrario não foi.
/*bool Comandos::statusComando()
{
	system("echo $? >> statusCmd.log");

	ifstream arq;
	string linha;
	arq.open("statusCmd.log",ios::in);//abrindo o arq p escrita
	if(!arq.is_open()) cout<<" FALHA AO ABRIR O ARQUIVO!"<<endl;
	getline(arq,linha);//lendo a linha do arquivo
	if(arq.is_open()) arq.clear();

	cout<<endl<<" IMPRIMI A LINHA DO ARQUIVO: "<<linha<<endl<<endl;

	arq.close();//fechando o arquivo
	remove("statusCmd.log");

	if(linha[0]=='0') return true;
	else return false;

}//fim metodo status comando
*/
//***********************
void Comandos::executaComando(string &comando, int idMenu)
{//inicio do metodo executa comando

	string path = comando; //var q pra receber o path-caminho do prog
	if(idMenu==1) path = "/bin/"+path;	//comando da bin
	if(idMenu==2) path = "/sbin/"+path;	//comando da sbin
	if(idMenu==3) path = comando;		//comando com path informado

	//pega o pid do pai
	pid_t pid;

	//cria um processo filho
	/*
	Processo Pai e Filho
		compartilham o mesmo codigo
		utilizam copia de dados
		compartilham os decritores
	*/
	pid = fork();

	if(pid<0)
	{//inicio if
		fprintf(stderr, " Falha na execucao do Fork");
		exit(-1);
	}//fim if
	else if(pid==0)
	{//fim if
		execlp(path.c_str(), comando.c_str(), NULL);
	}//fim if
	else
	{//inicio else
		//o comando wait espera o processo filho morrer pra que o pai morra
		//o comando sleep substitui o comando wait em c++
		wait(NULL);
		//sleep(0);
		return;
		//exit(0);
	}//fim else
}//fim do metodo executa comando

//**************************
//	MENU 3
//finalidade de compilar um programa durante a execução do mesmo
void Comandos::compilarPrograma(string fonte, string executavel, int tipoFonte)
{
	pid_t pid;
   	pid = fork();//cria um processo filho

     if(pid<0)
	{//inicio if
		fprintf(stderr, " Falha na execucao do Fork");
		exit(-1);
	}//fim if

    else if(pid==0)
	{
	    if(tipoFonte==1) execlp("/usr/bin/g++","g++",fonte.c_str(),"-o",executavel.c_str(), NULL);
	    else if(tipoFonte==2) execlp("/usr/bin/g++","g++",fonte.c_str(),"-o",executavel.c_str(), NULL);
	}//fim if

    else
	{//inicio else
    	wait(NULL);
    	//sleep(0);
		return;
	}//fim else
}//fim metodo de compilar

//*****************************************
//*****************************************
//	METODOS DO GERENCIADOR DE TAREFAS
//o parametro tipo do metodo identifica se ker matar o processo pelo id ou nome
void Comandos::mataProcesso(string &idProcesso, int tipoMetodo)
{//nicio metodo mata rocesso
	pid_t pid;
	pid = fork();
	if(pid<0){//inicio if falha na cricao do processo
		fprintf(stderr," Falha na execucao do fork");
		exit(-1);
	}//fim doif na falha da execucao do processo
	if(pid==0){
			if(tipoMetodo==1) execlp("/bin/kill","-9", idProcesso.c_str(), NULL);
			if(tipoMetodo==2) execlp("/usr/bin/killall","killall", idProcesso.c_str(), NULL);
	}//fim pid==0
	else
	{
		wait(NULL);
		//sleep(0);
		return;
	}//fim else
}//fim metodo mata processo

//*****************************************
void Comandos::gerenciadorDeProcessos()
{//inicio gerenciador de processos
	pid_t pid;
	pid = fork();
	if(pid<0){
		fprintf(stderr, "Falha na execucao do Fork()");
		exit(-1);
	}//fim if < 0
	if(pid==0){ execlp("/bin/ps","-aux","-aux",NULL); }//fim if pid==0
	else
	{//inicio else
		wait(NULL);
		//sleep(0);
		return;
	}//fim else
}//fim menu gerenciado de processos

#endif /*COMANDOS_H_*/

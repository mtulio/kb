#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iomanip>
#include<iostream>
#include"No.h"
#include"Hash.h"

using namespace std;

class Interface
{
public:
	
	static int submenu();
	static void menuPrincipal(Hash *hash);
	static void menuEncadeamentoFechado(Hash *&hash);	
	static void menuLinear(Hash *hash);
	static void menuHashingDuplo(Hash *hash);
	
	static void lerDadosDoAluno(No &obj);
	static void escreverDadosDoAluno(No &obj);
};

void Interface::lerDadosDoAluno(No &obj)
{
	int mat,rg,cpf;
	string nome;
	cout<<endl<<" Digite o nro de Matricula: ";
	cin>>mat;
	cout<<" Digite o nome do Aluno: ";
	cin>>nome;
	cout<<" Digite o CPF: ";
	cin>>cpf;
	cout<<" Digite o RG: ";
	cin>>rg;
	obj.setMatricula(mat);
	obj.setNome(nome);
	obj.setRg(rg);
	obj.setCpf(cpf);
}

void Interface::escreverDadosDoAluno(No &obj)
{
	cout<<endl<<" __________________________________";
	cout<<endl<<"| Matricula: "<<std::setw(15)<<obj.getMatricula()<<" |";
	cout<<endl<<"|      Nome: "<<obj.getNome()<<setw(15)<<" |";
	cout<<endl<<"|        RG: "<<obj.getRg()<<setw(15)<<" |";
	cout<<endl<<"|       CPF: "<<obj.getCpf()<<setw(15)<<" |";
	cout<<" ___________________________________"<<endl;
}//fim escrever

void Interface::menuPrincipal(Hash *hash)
{
int opt=0;

do{
	system("clear");
	cout<<endl<<"\t  ** MENU PRINCIPAL **"<<endl;
	cout<<endl<<" 1 - menu Encadeamento Fechado";
	cout<<endl<<" 2 - menu Encadeamento Aberto/Interno";
	cout<<endl<<" 3 - menu Linear";
	cout<<endl<<" 4 - menu Hashing Duplo";
	cout<<endl<<" 0 - SAIR";
	cout<<endl<<" Escolha uma opcao: ";
	cin>>opt;
	
	switch(opt){
	case 0:{
		exit(0);
		break;
	}
	case 1:{
		menuEncadeamentoFechado(hash);
		break;
	}
	case 2:{
		cout<<" ** NAO IMPLEMENTADO **"<<endl;
		cin.get();cin.get();
		break;
	}
	case 3:{
		menuLinear(hash);
		break;
	}
	case 4:{
		menuHashingDuplo(hash);
		break;
	}//fim case 3
	}//fim switch
	
}while(opt!=0);

}//fim menu principal


//***************
int Interface::submenu()
{
	int opt=0;
	cout<<endl<<" 1 - Adicionar Aluno";
	cout<<endl<<" 2 - Buscar Aluno";
	cout<<endl<<" 3 - Gerar tabela de Alunos - aleatorio 1< matricula <51";
	cout<<endl<<" 4 - Listar Alunos";
	cout<<endl<<" 0 - SAIR";
	cout<<endl<<" Escolha uma opcao: ";
	cin>>opt;
	return opt;
}//fim submenu

//***************
void Interface::menuEncadeamentoFechado(Hash *&hash)
{
	No *noAux;
	int opt=0;
	
do{
	system("clear");
	cout<<endl<<"\t** MENU ENCADEAMENTO FECHADO **"<<endl;
	opt = submenu();
	
	switch(opt)
	{
	case 0:{
		return;
		break;
	}//fim case 0
	case 1:{//add aluno
		cout<<"  EM CONSTRUCAO"<<endl;
		cin.get();cin.get();
		break;
	}//fim case 1
	case 2:{
		cout<<"  EM CONSTRUCAO"<<endl;
		
		/*
		int value=186;
		
		cout<<" Digite a matricula: ";
		cin>>value;
		
		noAux = new No();
		noAux->setMatricula(value);
		int result;
		result = hash->buscaEncadExterno(noAux);
		
		if(result==-2) cout<<" nao encontrado"<<endl;
		else if(result==-1) cout<<" campo vazio"<<endl;
		else cout<<" chave: "<<value<<" VALOR: "<<result<<endl;
		*/
		cin.get();cin.get();
		break;
	}//fim case 2
	case 3:{
		cout<<"  EM CONSTRUCAO"<<endl;
		
		/*		
		for(int i=0; i<hash->n;i++)
		{
			noAux = new No;
			noAux->setMatricula(i);
			noAux->setNome("fulano");
			noAux->setRg(i*100);
			noAux->setCpf(i*100);
			hash->inserirEncadExterno(noAux);
		}//fim for
		
		cout<<" Lista de Alunos Gerada!"<<endl;
		*/
		cin.get();cin.get();
		break;
	}//fim case 3
	
	case 4:{//listar alunos
		cout<<"  EM CONSTRUCAO"<<endl;
		/*
		hash->imprimiLinear();					
		cout<<" Listagem Efetuada!"<<endl;
		
		
		//cout<<" Digite a Matricula: ";
		//cin>>mat;
		
		for(int i=0; i<hash->n;i++)
		{
			noAux = new No();
			noAux->setMatricula(i);
			int result;
			result = hash->buscaEncadExterno(noAux);
			
			if(result==-2) cout<<" nao encontrado"<<endl;
			else if(result==-1) cout<<" campo vazio"<<endl;
			else cout<<" chave: "<<i<<" VALOR: "<<result<<endl;
		}
		
		cout<<" FIM DA LISTAGEM"<<endl;
		*/
		cin.get();cin.get();
		break;
	}//fim case 4
	
	}//fim switch
	
}while(opt!=0);

	//inserindo	
		/*for(int i=0; i<200;i++)
		{
			hash->inserirEncadExterno(i);
		}//fim for
		
		//obtendo
		cout<<" ******** BUSCA********************"<<endl;
		for(int i=0; i<103;i++)
		{
			cout<<" POSICAO: "<<i<<" VALOR: "<<hash.busca(i)<<endl;
		}
		
		int result;
		int value=186;
		result = hash->buscaEncadExterno(value);
		
		if(result==-2) cout<<" nao encontrado"<<endl;
		else if(result==-1) cout<<" campo vazio"<<endl;
		else cout<<" chave: "<<value<<" VALOR: "<<result<<endl;
		*/
}//fim menu encadeamento fechado

void Interface::menuLinear(Hash *hash)
{
	int opt=0;
	No *aux;
	do{
		system("clear");
		cout<<endl<<"\t** MENU LINEAR **"<<endl;
		opt = submenu();
		
		switch(opt)
		{
		case 0:{//
			return;
			break;
		}//fim case 1
		case 1:{//add
			//cout<<"  EM CONSTRUCAO"<<endl;
			
			aux = new No();
			
			lerDadosDoAluno(*aux);
			
			if(hash->inserirLinear(aux)==-1) cout<<" tabela cheia"<<endl;
			
			cout<<endl<<" Aluno Adicionado!!"<<endl;
			
			cin.get();cin.get();
			break;
		}//fim case 2
		case 2:{//buscar
			//cout<<"  EM CONSTRUCAO"<<endl;
			int result, mat;
			
			cout<<endl<<" Digite o nro de matricula: ";
			cin>>mat;
			
			aux = new No();
			aux->setMatricula(mat);
			
			if(hash->buscaLinear(aux)){
				cout<<" Matricula encontrada"<<endl;
			}
			else {
				cout<<" Matricula nao encontrada!"<<endl;
			}
				
			cin.get();cin.get();
			break;
		}//fim case 3
		case 3:{//gerar
			//cout<<"  EM CONSTRUCAO"<<endl;
			
			srand(hash->n);
			int num;
			for(int i=0; i<hash->n;i++)
			{
				num=rand()%(hash->n);
				aux = new No();
				aux->setMatricula(num);
				aux->setNome("fulado");
				aux->setRg(num);
				aux->setCpf(num);
				
				if(hash->inserirLinear(aux)==-1) cout<<" tabela cheia"<<endl;
				//cout<<endl<<"\t alunos gerados"<<endl;
			}//fim for
			
			cout<<endl<<"\t Lista de alunos gerada!"<<endl;
			
			cin.get();cin.get();
			break;
		}//fim case 3
		case 4:{//listar
			//cout<<"  EM CONSTRUCAO"<<endl;
			
			hash->imprimiLinear();
			
			cout<<endl<<" Listagem Efetuada!"<<endl;
			
			cin.get();cin.get();
			break;
		}//fim case 3
		}//fim switch
		
	}while(opt!=0);
	
	/*
	//inserindo	
	
	for(int i=0; i<55;i++)
	{
		if(hash->inserirLinear(i)==-1) cout<<" tabela cheia"<<endl;
	}//fim for
	//hash->imprimiLinear();
	//busca
	int result;
	int i;
	int value=5;
	result = hash->buscaLinear(value);
			
	if(result==-2) cout<<" nao encontrado"<<endl;
	else if(result==-1) cout<<" campo vazio"<<endl;
	else cout<<" chave: "<<value<<" VALOR: "<<result<<endl;
	
	for(i=0; i<110;i++)
	{
		result = hash->buscaLinear(i);
		if(result==-2) cout<<" nao encontrado"<<endl;
		else if(result==-1) cout<<" Tabela cheia"<<endl;
		else cout<<" chave: "<<i<<" VALOR: "<<result<<endl;
		//cout<<" POSICAO: "<<i<<" VALOR: "<<hash.busca(i)<<endl;
	}*/
	
}//fim menu linear

void Interface::menuHashingDuplo(Hash *hash)
{
	No *aux;
	int opt=0;
	do{
		system("clear");
		cout<<endl<<"\t** MENU HASHING DUPLO **"<<endl;
		opt = submenu();
		
		switch(opt)
		{
		case 0:{
			return;
			break;
		}//fim case 1
		case 1:{	
			//cout<<"  EM CONSTRUCAO"<<endl;
			aux = new No();
			
			lerDadosDoAluno(*aux);
			
			if(hash->inserirHashDuplo(aux)==-1) cout<<" tabela cheia"<<endl;
			else cout<<" Adicionado "<<aux->getMatricula()<<" com sucesso"<<endl;
			
			cin.get();cin.get();
			break;
		}//fim case 2
		case 2:{
			//cout<<"  EM CONSTRUCAO"<<endl;
			int mat;
			cout<<" Digite a Matricula: ";
			cin>>mat;
			aux = new No();
			aux->setMatricula(mat);
			
			if(hash->buscaHashDuplo(aux)) cout<<" Matricula: "<<mat<<", Encontrado"<<endl;
			else cout<<" Matricula: "<<mat<<", Não Encontrdo"<<endl;
			
			cin.get();cin.get();;
			break;
		}//fim case 3
		case 3:{//gerar
			//cout<<"  EM CONSTRUCAO"<<endl;
			srand(hash->n);
			int num;
			for(int i=0; i<hash->n;i++)
			{
				num=rand()%(hash->n);
				aux = new No();
				aux->setMatricula(num);
				aux->setNome("fulado");
				aux->setRg(num);
				aux->setCpf(num);
							
				if(hash->inserirLinear(aux)==-1) cout<<" tabela cheia"<<endl;
				//cout<<endl<<"\t alunos gerados"<<endl;
			}//fim for
						
			cout<<endl<<"\t Lista de alunos gerada!"<<endl;
						
			cin.get();cin.get();
			break;
		}//fim case 3
		case 4:{
			//cout<<"  EM CONSTRUCAO"<<endl;
			
			hash->imprimiLinear();
						
			cout<<endl<<" Listagem Efetuada!"<<endl;
						
			cin.get();cin.get();
			
			cin.get();cin.get();
			break;
		}//fim case 3
		}//fim switch
		
	}while(opt!=0);
	
	//inserindo	
	/*for(int i=0; i<hash->n;i++)
	{
		//std::cout<<" i: "<<i<<endl;
		if(hash->inserirHashDuplo(i)==-1) cout<<" tabela cheia"<<endl;
	}//fim for
	
	if(hash->inserirHashDuplo(70)==-1) cout<<" tabela cheia"<<endl;
	else cout<<" Add "<<70<<" com sucesso"<<endl;
	//if(hash->inserirHashDuplo(92)==-1) cout<<" tabela cheia"<<endl;
	//if(hash->inserirHashDuplo(32)==-1) cout<<" tabela cheia"<<endl;
	//if(hash->inserirHashDuplo(70)==-1) cout<<" tabela cheia"<<endl;
	//if(hash->inserirHashDuplo(47)==-1) cout<<" tabela cheia"<<endl;
	//if(hash->inserirHashDuplo(90)==-1) cout<<" tabela cheia"<<endl;
	//hash->imprimiLinear();
	
	//busca
	std::cout<<" busca"<<endl;
	int result;
		int i;
		int value=70;
		
		result = hash->buscaHashDuplo(value);
					
		if(result==-2) cout<<" nao encontrado"<<endl;
		else if(result==-1) cout<<" campo vazio"<<endl;
		else {
			cout<<" ENCONTRADO"<<endl;
			cout<<" chave: "<<value<<" VALOR: "<<result<<endl;
		}
	*/
}//fim menu HashDuplo

#endif /*INTERFACE_H_*/

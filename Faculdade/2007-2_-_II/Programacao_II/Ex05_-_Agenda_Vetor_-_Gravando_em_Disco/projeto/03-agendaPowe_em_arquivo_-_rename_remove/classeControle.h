/*
  Name: MARCO TULIO RODRIGUES BRAGA
  Copyright: UNIVERSIDADE CATOLICA DE GOIAS - PROGRAMACAO II
  Author: BRANCOTULIO & CIA
  Description: PROGRAMA DE AGENDA
*/
#ifndef CLASSECONTROLE_H_
#define CLASSECONTROLE_H_
#include"classePersistencia.h"
//*****************************************************************
//      Esta classe e a "comunicação" entre a interface e a classe Persistencia
//*****************************************************************

class Controle
{
	//Atributos
		private:
			Persistencia agendaDePessoas;
	//Metodos
		public:
			Controle(Persistencia &agendaDePessoas ):agendaDePessoas(agendaDePessoas){};
			int incluir(const std::string &nome, unsigned long telefone, const std::string &email);
			bool consultar(const std::string &nome, unsigned long &telefone, std::string &email)const;
			bool excluir(const std::string &nome);
			bool alterar(const std::string &nome, unsigned long telefone, const std::string &email);
			Iterator *listagemGeral(){return agendaDePessoas.obterTodasAsPessoas();}
			Iterator *listagemLetra(char letra){return agendaDePessoas.obterTodasAsPessoasPorLetra(letra);}
			Iterator *listagemNome(std::string nomeInfo){return agendaDePessoas.obterTodasAsPessoasPorNome(nomeInfo);}
		    Iterator *listagemOrdenarAgenda(){return agendaDePessoas.ordenarAgenda();}
		    bool ordenarEGravar();
};

int Controle::incluir(const std::string &nome, unsigned long telefone, const std::string &email)//01.1 >> recebe os dados digitados pelo usuario

{
	Pessoa pessoa(nome,telefone,email);//criando um objeto da classe pessoa com os dados digitados pelo user
	int resp = agendaDePessoas.atribuir(pessoa);//enviando o objeto criado para o metodo atribuir da classe Persistencia 01.2
	return resp;
}

bool Controle::consultar(const std::string &nome, unsigned long &telefone, std::string &email)const
{
		Pessoa pessoa;
		if(agendaDePessoas.obter(nome,pessoa)){
			telefone = pessoa.obterTelefone();
			email=pessoa.obterEmail();
			return true;
		}else return false;
		
}

bool Controle::excluir(const std::string &nome)
{
	return agendaDePessoas.apagar(nome);
}

bool Controle::alterar(const std::string &nome, unsigned long telefone, const std::string &email)
{
	excluir(nome);
	Pessoa pessoa(nome,telefone,email);
	agendaDePessoas.atribuir(pessoa);
	return true;
}

bool Controle::ordenarEGravar()
{
     return agendaDePessoas.ordenarGravar();
}
			
#endif /*CLASSECONTROLE_H_*/
